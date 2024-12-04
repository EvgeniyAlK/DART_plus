//
// Created by andreysh on 19.10.24.
//

#include "GDCreateNewHoleForm.h"

#include "../../GDPlatform/GDUtils.h"

GDCreateNewHoleForm::GDCreateNewHoleForm(QWidget *parent) {
    const auto layout = new QHBoxLayout(this);

    layout->addWidget(new QLabel("GDCreateNewHoleForm"));

    setLayout(layout);

    basicPrepareOfWidget(this, layout, "#D4FFC0");
}
