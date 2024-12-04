//
// Created by andreysh on 19.10.24.
//

#include "GDDrillingTableWidget.h"

#include "../../Dependency.h"
#include "../../GDPlatform/GDUtils.h"

class LeftRightWidget final : public QWidget {
public:
    explicit LeftRightWidget(QWidget *parent) : QWidget(parent) {

    }

    ~LeftRightWidget() override = default;
};


GDDrillingTableWidget::GDDrillingTableWidget(QWidget *parent) {
    const auto layout = new QHBoxLayout(this);
    const auto table = new QTableWidget(this);
    auto headers = QStringList();

    headers << "A" << "B" << "C" << "D";

    table->setColumnCount(4);
    table->setRowCount(0);

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setHorizontalHeaderLabels(headers);

    layout->addWidget(table);

    setLayout(layout);

    basicPrepareOfWidget(this, layout);
}
