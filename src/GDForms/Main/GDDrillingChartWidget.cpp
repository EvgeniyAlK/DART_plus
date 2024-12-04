//
// Created by andreysh on 19.10.24.
//

#include "GDDrillingChartWidget.h"

#include "../../GDPlatform/GDUtils.h"

class LeftRightWidget final : public QWidget {
public:
    explicit LeftRightWidget(QWidget *parent) : QWidget(parent) {
        const auto series = new QtCharts::QLineSeries();
        const auto chart = new QtCharts::QChart();
        const auto chartView = new QtCharts::QChartView(chart);

        series->append(0, 6);
        series->append(2, 4);
        series->append(3, 8);
        series->append(7, 4);
        series->append(10, 5);
        *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);


        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle(tr("Лево/Право"));

        chartView->setRenderHint(QPainter::Antialiasing);

        const auto layout = new QVBoxLayout(this);

        layout->addWidget(chartView);

        basicPrepareOfWidget(this, layout);
        basicPrepareOfWidget(chartView, layout);

        setLayout(layout);
    }

    ~LeftRightWidget() override = default;
};

class TopBottomWidget final : public QWidget {
public:
    explicit TopBottomWidget(QWidget *parent) : QWidget(parent) {
        const auto series = new QtCharts::QLineSeries();
        const auto chart = new QtCharts::QChart();
        const auto chartView = new QtCharts::QChartView(chart);

        series->append(0, 6);
        series->append(2, 4);
        series->append(3, 8);
        series->append(7, 4);
        series->append(10, 5);
        *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);


        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle(tr("Верх/Низ"));

        chartView->setRenderHint(QPainter::Antialiasing);

        const auto layout = new QVBoxLayout(this);

        layout->addWidget(chartView);

        basicPrepareOfWidget(this, layout);
        basicPrepareOfWidget(chartView, layout);

        setLayout(layout);
    }

    ~TopBottomWidget() override = default;
};

GDDrillingChartWidget::GDDrillingChartWidget(QWidget *parent) {
    const auto layout = new QVBoxLayout(this);
    const auto tab = new QTabWidget(this);
    const auto left = new LeftRightWidget(this);
    const auto top = new TopBottomWidget(this);

    tab->addTab(left, tr("Лево/Право"));
    tab->addTab(top, tr("Верх/низ"));

    layout->addWidget(tab);

    basicPrepareOfWidget(this, layout);

    setLayout(layout);
}
