//
// Created by andreysh on 19.10.24.
//

#ifndef GDGAMMATLFWIDGET_H
#define GDGAMMATLFWIDGET_H

#include "../../Dependency.h"


class GDGammaTLFWidget: public QWidget {
    Q_OBJECT

public:
    explicit GDGammaTLFWidget(QWidget *parent = nullptr);

    ~GDGammaTLFWidget() override = default;
};



#endif //GDGAMMATLFWIDGET_H
