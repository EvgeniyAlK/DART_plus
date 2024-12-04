//
// Created by andreysh on 14.11.24.
//

#include "GDSerialPort.h"

/***
 * Надо придумать некую стейт машину.
 * 
 ***/


void GDSerialPort::scanStateHandler() {
    if (_state == Unknown) {
        makeTransition(Scan);
    }

    if (_state == Scan) {
        for (const auto it: _portInfo->availablePorts()) {
            if (it.description().contains(MARKER_FOR_SEARCHING_REQUIRED_PORT)) {
                qDebug() << "Удалось найти порт по маркеру " << MARKER_FOR_SEARCHING_REQUIRED_PORT;
                qDebug() << "portName: " << it.portName();
                qDebug() << "systemLocation: " << it.systemLocation();
                qDebug() << "description: " << it.description();
                qDebug() << "manufacturer: " << it.manufacturer();
                qDebug() << "serialNumber: " << it.serialNumber();
                qDebug() << "----------------";
                qDebug() << "current: " << QDateTime::currentMSecsSinceEpoch();

                _nameOfPortFound = it.portName();

                makeTransition(DeviceFound);
            }
        }
    }
}

void GDSerialPort::connectToDeviceStateHandler() {
    qDebug() << "Connect To Device " << _nameOfPortFound;

    _port.setPortName(_nameOfPortFound);

    if (_port.isOpen()) {
        _port.close();
    }

    if (!_port.isOpen() && !_port.open(QIODevice::ReadWrite)) {
        qDebug() << "Error after open " << _port.errorString();
    }

    if (!_port.setBaudRate(QSerialPort::Baud115200)) {
        qDebug() << "Error after setBaudRate " << _port.errorString();
    }


    if (!_port.setDataBits(QSerialPort::Data8)) {
        qDebug() << "Error after setDataBits " << _port.errorString();
    }

    if (!_port.setParity(QSerialPort::NoParity)) {
        qDebug() << "Error after setParity " << _port.errorString();
    }

    if (!_port.setStopBits(QSerialPort::OneStop)) {
        qDebug() << "Error after setStopBits " << _port.errorString();
    }

    if (!_port.setFlowControl(QSerialPort::NoFlowControl)) {
        qDebug() << "Error after setFlowControl " << _port.errorString();
    }

    makeTransition(Connected);
}

void GDSerialPort::deviceFoundStateHandler() {
}

void GDSerialPort::connectingStateHandler() {
}

void GDSerialPort::connectedStateHandler() {
    makeTransition(SendingCommand);
}

void GDSerialPort::sendingCommandStateHandler() {
    const auto data = QByteArray::fromHex("80");

    qDebug() << "Write Data Len: " << _port.write(data);
    qDebug() << "Data: " << data;

    _port.waitForBytesWritten(-1);
    _port.flush();

    makeTransition(CommandSent);
}

void GDSerialPort::commandSentStateHandler() {
    makeTransition(ReadingData);
}

void GDSerialPort::readingDataStateHandler() {
    _response.clear();

    qDebug() << "readingDataStateHandler";

    auto delta = QDateTime::currentMSecsSinceEpoch();

    while (true) {
        if (_port.waitForReadyRead(-1) && _port.bytesAvailable() > 0) {
            auto const readData = _port.readAll();
            _response.append(readData);

            delta = QDateTime::currentMSecsSinceEpoch();
        }

        if (_response.length() == 63) {
            qDebug() << "!!!!!!!!BREAK " << " <=> BREAK!!!!!!!";
            break;
        }

        if (QDateTime::currentMSecsSinceEpoch() - delta > READ_DATA_TIMEOUT) {
            qDebug() << "****** Timeout =(( ******";
            
            makeTransition(Scan);
            break;
        }
    }

    makeTransition(DataRead);
}

void GDSerialPort::dataReadStateHandler() {
    emit responseReady(_response);

    makeTransition(Scan);
}

void GDSerialPort::makeTransition(const State state) {
    qDebug() << "Transition from: " << _state << " to: " << state;
    _state = state;
}

GDSerialPort::GDSerialPort(QObject *parent): _portInfo(new QSerialPortInfo), _port(QSerialPort()) {
    _state = Unknown;
}

void GDSerialPort::run() {
    auto deltaTime = QDateTime::currentMSecsSinceEpoch();
    auto response = QByteArray();

    for (;;) {
        if (_state == Unknown || _state == Scan) {
            if (const auto current = QDateTime::currentMSecsSinceEpoch();
                current - deltaTime > SCAN_POLLING_PAUSE_MSECS) {

                scanStateHandler();

                deltaTime = QDateTime::currentMSecsSinceEpoch();
            }
        } else if (_state == DeviceFound) {
            connectToDeviceStateHandler();
        } else if (_state == Connected) {
            connectedStateHandler();
        } else if (_state == SendingCommand) {
            sendingCommandStateHandler();
        } else if (_state == CommandSent) {
            commandSentStateHandler();
        } else if (_state == ReadingData) {
            readingDataStateHandler();
        } else if (_state == DataRead) {
            dataReadStateHandler();
        }
    }
}

void GDSerialPort::sendingCommand(const QByteArray &command) {
    _commandSend.clear();
    _commandSend.append(command);
    
    _state = SendingCommand;
}
