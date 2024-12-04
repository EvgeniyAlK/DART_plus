//
// Created by andreysh on 19.10.24.
//
#include "GDSettingsForm.h"

#include "../../GDPlatform/GDUtils.h"

GDSettingsForm::GDSettingsForm(QWidget *parent) {
    const auto layout = new QHBoxLayout(this);

    layout->addWidget(new QLabel("GDSettingsForm"));

    setLayout(layout);

    basicPrepareOfWidget(this, layout, "#D4FFC0");
}
