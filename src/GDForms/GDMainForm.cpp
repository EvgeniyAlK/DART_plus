//
// Created by andreysh on 19.10.24.
//


#include "GDMainForm.h"

#include "GDMainMenuWidget.h"
#include "SurveyData.h"
#include "../GDPlatform/GDSerialPort.h"
#include "../GDPlatform/GDUtils.h"
#include "Main/GDDrillingChartWidget.h"
#include "Main/GDDrillingTableWidget.h"
#include "Main/GDGammaTLFWidget.h"
#include "Main/GDProbeWidget.h"
#include "Main/GDTLFWidget.h"
#include "Main/GDTopPanelWidget.h"

// create menu
static QMenu *cm(const QString &text) {
    return new QMenu(text);
}

// create action
static QAction *ca(const QString &text) {
    return new QAction(text);
}


GDMainForm::GDMainForm(QWidget *parent):
    // main menu
    file(cm(tr("Файл"))),
    chart(cm(tr("Графики"))),
    tools(cm(tr("Инструменты"))),
    options(cm(tr("Параметры"))),

    // file actions
    createNewHole(ca(tr("Создать новую скважину"))),
    sendToUSB(ca(tr("Отправить на USB"))),
    saveToCSV(ca(tr("Сохранить в CSV"))),
    openFile(ca(tr("Открыть файл"))),
    // chart actions
    signalStrength(ca(tr("Сила сигнала"))),
    batteryCharge(ca(tr("Заряд батареи"))),
    temperature(ca(tr("Температура"))),

    // tools actions
    diagnostics(ca(tr("Диагностика"))),

    // options actions
    settings(ca(tr("Настройки"))) {
    file->addAction(createNewHole);
    file->addAction(sendToUSB);
    file->addAction(saveToCSV);
    file->addAction(openFile);

    chart->addAction(signalStrength);
    chart->addAction(batteryCharge);
    chart->addAction(temperature);

    tools->addAction(diagnostics);

    options->addAction(settings);

    menuBar()->addMenu(file);
    menuBar()->addMenu(chart);
    menuBar()->addMenu(tools);
    menuBar()->addMenu(options);

    resize(1024, 768);

    const auto widget = new QWidget;
    const auto layout = new QVBoxLayout;
    const auto additionalLayout = new QHBoxLayout;
    const auto leftLayout = new QVBoxLayout;
    const auto rightLayout = new QVBoxLayout;

    const auto tlfWidget = new GDTLFWidget;
    const auto gammaTlfWidget = new GDGammaTLFWidget;
    const auto probeWidget = new GDProbeWidget;
    const auto topPanelWidget = new GDTopPanelWidget;

    setCentralWidget(widget);

    const auto drillingTableWidget = new GDDrillingTableWidget();

    leftLayout->addWidget(new GDDrillingTableWidget);
    leftLayout->addWidget(new GDDrillingChartWidget);

    rightLayout->addWidget(tlfWidget);
    rightLayout->addWidget(gammaTlfWidget);
    rightLayout->addWidget(probeWidget);
    rightLayout->setStretchFactor(tlfWidget, 4);
    rightLayout->setStretchFactor(gammaTlfWidget, 4);
    rightLayout->setStretchFactor(probeWidget, 1);

    additionalLayout->addLayout(leftLayout);
    additionalLayout->addLayout(rightLayout);
    additionalLayout->setStretchFactor(leftLayout, 4);
    additionalLayout->setStretchFactor(rightLayout, 1);

    layout->addWidget(topPanelWidget);
    layout->addLayout(additionalLayout);

    widget->setLayout(layout);

    resetSpacing(layout);
    resetSpacing(additionalLayout);
    resetSpacing(leftLayout);
    resetSpacing(rightLayout);
    resetSpacing(widget);
    resetSpacing(this);

    const auto menu = new GDMainMenuWidget(widget);

    connect(topPanelWidget, &GDTopPanelWidget::logoClick, this, [this, menu] {
        menu->setGeometry(15, 15, this->width() - 30, this->height() - 100);
        menu->show();
    });

    gdSerialPort = new GDSerialPort();

    connect(gdSerialPort, &GDSerialPort::responseReady, this, [](QByteArray response) {
        qDebug() << "Signal";
        qDebug() << response;
        Package0x80 package0x80 = Package0x80(&response);
        qDebug() << "Package0x08" << "GX:" << package0x80.gx << "GY:" << package0x80.gy << "GZ:" << package0x80.gz << "Temp:" << package0x80.temp << "Voltage:" << package0x80.volt;
        SurveyShot* survey_shot = new SurveyShot(&package0x80);
        qDebug() << "GV len" << survey_shot->gv << "HV len" << survey_shot->hv << "SurveyShot" << "AZ:" << survey_shot->az << "PITCH:" << survey_shot->dip << "ROLL:" << survey_shot->tlf;
        SurveyData* survey_data = new SurveyData(survey_shot, 0, 0, 0);
        qDebug() << "Размер списка SurveyData:" << survey_data->SurveyList.size();
    }, Qt::QueuedConnection);

    gdSerialPort->start();


    // connect(topPanelWidget, &GDTopPanelWidget::logoClick, this, [this, widget]() {
    //     qDebug() << tr("Главная форма создана");
    //
    //
    //     QDialog splash(widget, Qt::Widget);
    //     auto laySplash = new QVBoxLayout(&splash);
    //     auto lblText = new QLabel;
    //     laySplash->addWidget(lblText);
    //     lblText->setText("hello world! hello world! hello world! hello world! hello world! ");
    //     splash.adjustSize();
    //
    //     // splash.setGeometry(
    //     //     QStyle::alignedRect(
    //     //         Qt::LeftToRight,
    //     //         Qt::AlignCenter,
    //     //         splash.size(),
    //     //         widget->rect()
    //     //     )
    //     // );
    //
    //     splash.setGeometry(this->x() + this->width() / 2 - 150, this->y() + this->height() / 2 - 150, 300, 300);
    //
    //     splash.exec();
    // });
}

void GDMainForm::mousePressEvent(QMouseEvent *event) {
    QMainWindow::mousePressEvent(event);

    qDebug() << "Mouse Press Event";
}

void GDMainForm::serialResponseReady(QByteArray response) {
    qDebug() << "Данные";
    qDebug() << response;
    qDebug() << response.length();
}
