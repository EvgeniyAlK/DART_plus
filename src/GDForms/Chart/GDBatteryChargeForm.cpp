//
// Created by andreysh on 19.10.24.
//

#include "GDBatteryChargeForm.h"

#include "../../GDPlatform/GDUtils.h"

GDBatteryChargeForm::GDBatteryChargeForm(QWidget *parent) {
    const auto layout = new QHBoxLayout(this);

    layout->addWidget(new QLabel("GDSignalStrengthForm"));

    setLayout(layout);

    basicPrepareOfWidget(this, layout, "#D4FFC0");
}
