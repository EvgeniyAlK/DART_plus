//
// Created by andreysh on 19.10.24.
//

#ifndef GDDIAGNOSTICSFORM_H
#define GDDIAGNOSTICSFORM_H

#include "../../Dependency.h"


class GDDiagnosticsForm : public QWidget {
    Q_OBJECT

public:
    explicit GDDiagnosticsForm(QWidget *parent = nullptr);

    ~GDDiagnosticsForm() override = default;
};


#endif //GDDIAGNOSTICSFORM_H
