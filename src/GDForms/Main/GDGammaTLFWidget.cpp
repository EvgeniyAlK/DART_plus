//
// Created by andreysh on 19.10.24.
//
#include "GDGammaTLFWidget.h"

#include "../../GDPlatform/GDUtils.h"
#include "../../GDPlatform/Widget/GDAzimuthWidget.h"

GDGammaTLFWidget::GDGammaTLFWidget(QWidget *parent) {
    const auto layout = new QVBoxLayout(this);
    const auto azimuth = new GDAzimuthWidget(this);
    const auto slider = new QSlider;
    const auto gammaOne = new QPushButton(tr("Гамма 1"), this);
    const auto gammaTwo = new QPushButton(tr("Гамма 2"), this);
    const auto gammaLayout = new QHBoxLayout();
    const auto azimuthLabel = new QLabel();

    gammaLayout->setSpacing(5);
    gammaLayout->addWidget(gammaOne);
    gammaLayout->addWidget(gammaTwo);

    azimuth->setColor(QColor::fromRgb(0xB3, 0x60, 0x8A));

    azimuthLabel->setMaximumHeight(32);

    slider->setMinimum(-180);
    slider->setMaximum(180);
    slider->setValue(0);
    slider->setOrientation(Qt::Horizontal);

    layout->addWidget(azimuth);
    layout->addWidget(azimuthLabel);
    layout->addLayout(gammaLayout);
    layout->addWidget(slider);

    setLayout(layout);

    connect(slider, &QSlider::valueChanged, azimuth, &GDAzimuthWidget::setAzimuth);
    connect(azimuth, &GDAzimuthWidget::azimuthChanged, azimuthLabel, [azimuthLabel](const int it) {
        azimuthLabel->setText(QString("Гамма TLF: %1 градусов").arg(it));
    });

    azimuth->setAzimuth(0);

    basicPrepareOfWidget(this, layout);
}
