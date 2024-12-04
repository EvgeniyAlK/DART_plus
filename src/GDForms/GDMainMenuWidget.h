//
// Created by andreysh on 22.10.24.
//

#ifndef GDMAINMENUWIDGET_H
#define GDMAINMENUWIDGET_H

#include "../Dependency.h"

class GDMainMenuWidget : public QScrollArea {
    Q_OBJECT

public:
    // class MenuFile final {
    // public:
    //     const QString Title = QString(QObject::tr("Файл"));
    //     const QAction
    //             *CreateNewHole = new QAction(QObject::tr("Создать новую скважину")),
    //             *SendToUSB = new QAction(QObject::tr("Отправить на USB")),
    //             *SaveToCSV = new QAction(QObject::tr("Сохранить в CSV")),
    //             *OpenFile = new QAction(QObject::tr("Открыть файл"));
    // };

    class MenuChart final {
    public:
        const QString Title = QString(QObject::tr("Диаграмма"));
        const QAction
            *SignalStrength = new QAction(QObject::tr("Сила сигнала")),
            *BatteryCharge = new QAction(QObject::tr("Заряд батареи")),
            *Temperature = new QAction(QObject::tr("Температура"));
    };

    class MenuTools final {
    public:
        const QString Title = QString(QObject::tr("Диагностика"));
        const QAction *Diagnostics = new QAction(QObject::tr("Инструменты"));

    };

    class MenuOptions final {
    public:
        const QString Title = QString("Настройки");
        const QAction *Settings = new QAction(QObject::tr("Параметры"));
    };

    // const MenuFile* file = new MenuFile();
    const MenuChart* chart = new MenuChart();
    const MenuTools* tools = new MenuTools();
    const MenuOptions* options = new MenuOptions();

    explicit GDMainMenuWidget(QWidget *parent);
    ~GDMainMenuWidget() override = default;
};

#endif //GDMAINMENUWIDGET_H
