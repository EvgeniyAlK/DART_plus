//
// Created by andreysh on 19.10.24.
//
#include "GDDiagnosticsForm.h"

#include "../../GDPlatform/GDUtils.h"

GDDiagnosticsForm::GDDiagnosticsForm(QWidget *parent) {
    const auto layout = new QHBoxLayout(this);

    layout->addWidget(new QLabel("GDDiagnosticsForm"));
    layout->setSpacing(0);

    setLayout(layout);

    basicPrepareOfWidget(this, layout, "#D4FFC0");
}
