//
// Created by andreysh on 19.10.24.
//


#include "GDTopPanelWidget.h"
#include "../../GDPlatform/GDUtils.h"
#include "../../GDPlatform/Widget/GDDigitalClockWidget.h"


// create label
static QLabel *cl(const char *text) {
    return new QLabel(QObject::tr(text));
}

GDTopPanelWidget::GDTopPanelWidget(QWidget *parent) {
    const auto layout = new QHBoxLayout(this);
    const auto logo = new QPushButton(this);

    const auto file = cl(
        "<h3 style='text-align: center;'>Файл</h3>"
        "<div style='text-align: center;'>Label_er.dat</div>"
    );

    const auto magneticDeclination = cl(
        "<h3 style='text-align: center;'>Магнитное склонение</h3>"
        "<div style='text-align: center;'>-5.45</div>"
    );

    const auto projectAzimuth = cl(
        "<h3 style='text-align: center;'>Проектный азимут</h3>"
        "<div style='text-align: center;'>128.4</div>"
    );

    const auto offsetOfTLF = cl(
        "<h3 style='text-align: center;'>Смещение TLF</h3>"
        "<div style='text-align: center;'>13.2</div>"
    );

    const auto backgroundColor = palette().color(backgroundRole());


    logo->setFlat(true);
    logo->setAutoFillBackground(true);
    logo->setIcon(QIcon(":/images/DartLogo-4.png"));
    logo->setIconSize(QSize(128, 64));
    logo->setStyleSheet(
        "QPushButton{ background-color: gray; }"
        "QPushButton:disabled{ background-color: gray; }"
        "QPushButton:pressed{ background-color: gray; }"
        "QPushButton:focus:pressed{ background-color: ; }"
        "QPushButton:focus{ background-color: gray; }"
        "QPushButton:hover{ background-color: gray; }"
        "QPushButton:checked{ background-color: gray; }"
    );

    qDebug() << backgroundColor.name();


    layout->addWidget(logo);
    layout->addWidget(file);
    layout->addWidget(magneticDeclination);
    layout->addWidget(projectAzimuth);
    layout->addWidget(offsetOfTLF);
    layout->addWidget(new GDDigitalClockWidget(this));

    setLayout(layout);
    setFixedHeight(64);

    connect(logo, &QPushButton::clicked, this, [this] { logoClick(); });

    basicPrepareOfWidget(this, layout);
}
