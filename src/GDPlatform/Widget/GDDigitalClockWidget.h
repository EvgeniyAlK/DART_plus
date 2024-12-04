//
// Created by andreysh on 19.10.24.
//

#ifndef GDDIGITALCLOCKWIDGET_H
#define GDDIGITALCLOCKWIDGET_H

#include "../../Dependency.h"


class GDDigitalClockWidget : public QWidget {
    Q_OBJECT

public:
    explicit GDDigitalClockWidget(QWidget *parent = nullptr);

    ~GDDigitalClockWidget() override = default;

private:
    enum State { Tick, Tac };

    inline static const QString TimeFormat = "hh:mm:ss";
    inline static const QString DateFormat = "dd.MM.yyyy";

    inline static QString _getCurrentTime();
    inline static QString _getCurrentDate();

    State _currentState = Tick;

    QLCDNumber* _clock;
    QLabel* _calendar;


private slots:
    void tick();
};


#endif //GDDIGITALCLOCKWIDGET_H
