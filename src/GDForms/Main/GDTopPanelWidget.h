//
// Created by andreysh on 19.10.24.
//

#ifndef GDTOPPANELWIDGET_H
#define GDTOPPANELWIDGET_H

#include "../../Dependency.h"


#endif //GDTOPPANELWIDGET_H
class GDTopPanelWidget : public QWidget {
    Q_OBJECT

signals:
    void logoClick();

public:
    explicit GDTopPanelWidget(QWidget *parent = nullptr);

    ~GDTopPanelWidget() override = default;
};
