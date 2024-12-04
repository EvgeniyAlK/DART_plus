//
// Created by andreysh on 19.10.24.
//

#ifndef GDTLFWIDGET_H
#define GDTLFWIDGET_H

#include "../../Dependency.h"


class GDTLFWidget: public QWidget {
    Q_OBJECT

public:
    explicit GDTLFWidget(QWidget *parent = nullptr);

    ~GDTLFWidget() override = default;

};



#endif //GDTLFWIDGET_H
