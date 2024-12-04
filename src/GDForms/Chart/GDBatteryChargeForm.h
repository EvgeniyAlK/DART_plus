//
// Created by andreysh on 19.10.24.
//

#ifndef GDBATTERYCHARGEFORM_H
#define GDBATTERYCHARGEFORM_H

#include "../../Dependency.h"


class GDBatteryChargeForm : QWidget {
    Q_OBJECT

public:
    explicit GDBatteryChargeForm(QWidget *parent = nullptr);

    ~GDBatteryChargeForm() override = default;
};


#endif //GDBATTERYCHARGEFORM_H
