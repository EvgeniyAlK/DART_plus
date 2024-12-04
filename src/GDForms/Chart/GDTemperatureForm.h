//
// Created by andreysh on 19.10.24.
//

#ifndef GDTEMPERATUREFORM_H
#define GDTEMPERATUREFORM_H

#include "../../Dependency.h"


class GDTemperatureForm : QWidget {
    Q_OBJECT

public:
    explicit GDTemperatureForm(QWidget *parent = nullptr);

    ~GDTemperatureForm() override = default;
};


#endif //GDTEMPERATUREFORM_H
