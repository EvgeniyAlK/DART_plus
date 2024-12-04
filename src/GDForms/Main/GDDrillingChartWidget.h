//
// Created by andreysh on 19.10.24.
//

#ifndef GDPROBECHARTWIDGET_H
#define GDPROBECHARTWIDGET_H

#include "../../Dependency.h"


class GDDrillingChartWidget : public QWidget {
    Q_OBJECT

public:
    explicit GDDrillingChartWidget(QWidget *parent = nullptr);

    ~GDDrillingChartWidget() override = default;
};


#endif //GDPROBECHARTWIDGET_H
