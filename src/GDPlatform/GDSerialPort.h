//
// Created by andreysh on 12.11.24.
//

#ifndef GDSERIALPORT_H
#define GDSERIALPORT_H

#include "../Dependency.h"


class GDSerialPort : public QThread {
    Q_OBJECT

    QSerialPort _port;
    QSerialPortInfo *_portInfo;

    static constexpr qint64 SCAN_POLLING_PAUSE_MSECS = 1 * 1000;
    static constexpr qint64 CONNECTING_TIMEOUT_MSECS = 10 * 1000;
    static constexpr qint64 READ_DATA_TIMEOUT = 5 * 1000;
    inline static const QString MARKER_FOR_SEARCHING_REQUIRED_PORT = "DART";

    QByteArray _commandSend, _response;

public:
    enum State {
        Unknown, Scan, DeviceFound, Connecting, Connected,
        SendingCommand, CommandSent, ReadingData, DataRead
    };

    Q_ENUM(State)

private:
    State _state = Unknown;
    
    QString _nameOfPortFound;

    void scanStateHandler();

    void connectToDeviceStateHandler();

    void deviceFoundStateHandler();

    void connectingStateHandler();

    void connectedStateHandler();

    void sendingCommandStateHandler();

    void commandSentStateHandler();

    void readingDataStateHandler();

    void dataReadStateHandler();

    void makeTransition(State state);

public:
    explicit GDSerialPort(QObject *parent = nullptr);

    ~GDSerialPort() override = default;

protected:
    void run() override;

public slots:
    void sendingCommand(const QByteArray &command);

signals:
    void responseReady(const QByteArray &response);
};

#endif //GDSERIALPORT_H
