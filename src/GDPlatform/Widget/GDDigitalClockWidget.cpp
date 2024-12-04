//
// Created by andreysh on 19.10.24.
//

#include "GDDigitalClockWidget.h"
#include "../../GDPlatform/GDUtils.h"

GDDigitalClockWidget::GDDigitalClockWidget(QWidget *parent): QWidget(parent),
                                                             _clock(new QLCDNumber(this)),
                                                             _calendar(new QLabel(this)) {
    const auto timer = new QTimer(this);
    const auto layout = new QVBoxLayout(this);

    _clock->setSegmentStyle(QLCDNumber::Flat);
    _clock->setDigitCount(8);
    _clock->setStyleSheet(
        "border: none;"
    );
    _clock->display(_getCurrentTime());

    _calendar->setAlignment(Qt::AlignCenter);
    _calendar->setStyleSheet(
        "border: none;"
        "font-size: 18px;"
        "font-weight: bold;"
        "font-family: monospace;"
    );
    _calendar->setText(_getCurrentDate());

    layout->addWidget(_clock);
    layout->addWidget(_calendar);

    basicPrepareOfWidget(this, layout);

    connect(timer, &QTimer::timeout, this, &GDDigitalClockWidget::tick);

    timer->start(500);
}

QString GDDigitalClockWidget::_getCurrentTime() {
    return QTime::currentTime().toString(TimeFormat);
}

QString GDDigitalClockWidget::_getCurrentDate() {
    return QDate::currentDate().toString(DateFormat);
}

void GDDigitalClockWidget::tick() {
    const auto date = _getCurrentDate();
    auto text = _getCurrentTime();

    if (_currentState == Tick) {
        text[2] = ':';
        text[5] = ':';

        _currentState = Tac;
    } else {
        text[2] = ' ';
        text[5] = ' ';

        _currentState = Tick;
    }

    _clock->display(text);
    _calendar->setText(date);
}
