//
// Created by andreysh on 19.10.24.
//
#include "GDProbeWidget.h"

#include "../GDMainForm.h"
#include "../../GDPlatform/GDUtils.h"

GDProbeWidget::GDProbeWidget(QWidget *parent) {
    const auto layout = new QHBoxLayout(this);
    const auto button = new QPushButton(tr("Замер"), this);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(button);

    setLayout(layout);

    basicPrepareOfWidget(this, layout);

}
