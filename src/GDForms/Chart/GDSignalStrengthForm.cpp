//
// Created by andreysh on 19.10.24.
//

#include "GDSignalStrengthForm.h"

#include "../../GDPlatform/GDUtils.h"

GDSignalStrengthForm::GDSignalStrengthForm(QWidget *parent) {
    const auto layout = new QHBoxLayout(this);

    layout->addWidget(new QLabel("GDSignalStrengthForm"));

    setLayout(layout);

    basicPrepareOfWidget(this, layout, "#D4FFC0");
}
