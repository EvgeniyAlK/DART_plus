//
// Created by andreysh on 19.10.24.
//

#ifndef GDPROBEWIDGET_H
#define GDPROBEWIDGET_H

#include "../../Dependency.h"


class GDProbeWidget : public QWidget {
    Q_OBJECT

public:
    explicit GDProbeWidget(QWidget *parent = nullptr);

    ~GDProbeWidget() override = default;
};


#endif //GDPROBEWIDGET_H
