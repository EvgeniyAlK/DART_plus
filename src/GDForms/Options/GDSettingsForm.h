//
// Created by andreysh on 19.10.24.
//

#ifndef GDSETTINGSFORM_H
#define GDSETTINGSFORM_H

#include "../../Dependency.h"


class GDSettingsForm : public QWidget {
    Q_OBJECT

public:
    explicit GDSettingsForm(QWidget *parent = nullptr);

    ~GDSettingsForm() override = default;
};


#endif //GDSETTINGSFORM_H
