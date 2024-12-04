//
// Created by andreysh on 19.10.24.
//
#include "GDTLFWidget.h"

#include "../../GDPlatform/GDUtils.h"
#include "../../GDPlatform/Widget/GDAzimuthWidget.h"

GDTLFWidget::GDTLFWidget(QWidget *parent) {
    const auto layout = new QVBoxLayout(this);
    const auto azimuth = new GDAzimuthWidget(this);
    const auto slider = new QSlider;

    azimuth->setColor(QColor::fromRgb(0x62, 0x87, 0xFF));

    slider->setMinimum(-360);
    slider->setMaximum(360);
    slider->setValue(0);
    slider->setOrientation(Qt::Horizontal);

    layout->addWidget(azimuth);
    layout->addWidget(slider);

    setLayout(layout);

    connect(slider, &QSlider::valueChanged, azimuth, &GDAzimuthWidget::setAzimuth);

    basicPrepareOfWidget(this, layout);
}
