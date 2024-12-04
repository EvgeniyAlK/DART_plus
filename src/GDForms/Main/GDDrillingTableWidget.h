//
// Created by andreysh on 19.10.24.
//

#ifndef GDDRILLINGTABLEWIDGET_H
#define GDDRILLINGTABLEWIDGET_H

#include "../../Dependency.h"


class GDDrillingTableWidget : public QWidget {
    Q_OBJECT

public:
    explicit GDDrillingTableWidget(QWidget *parent = nullptr);

    ~GDDrillingTableWidget() override = default;
};


#endif //GDDRILLINGTABLEWIDGET_H
