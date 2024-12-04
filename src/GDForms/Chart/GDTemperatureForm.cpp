//
// Created by andreysh on 19.10.24.
//

#include "GDTemperatureForm.h"

#include "../../GDPlatform/GDUtils.h"

GDTemperatureForm::GDTemperatureForm(QWidget *parent) {
    const auto layout = new QHBoxLayout(this);

    layout->addWidget(new QLabel("GDTemperatureForm"));
    layout->setSpacing(0);

    setLayout(layout);

    basicPrepareOfWidget(this, layout, "#D4FFC0");
}
