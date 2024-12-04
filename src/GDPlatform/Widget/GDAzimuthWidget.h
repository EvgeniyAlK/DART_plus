//
// Created by andreysh on 19.10.24.
//

#ifndef GDAZIMUTHWIDGET_H
#define GDAZIMUTHWIDGET_H
#include "GDDigitalClockWidget.h"


class GDAzimuthWidget : public QWidget {
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(int azimuth READ azimuth WRITE setAzimuth NOTIFY azimuthChanged)

    QColor _color = QColor::fromRgb(0, 0, 0);
    int _azimuth = 0;

public:
    explicit GDAzimuthWidget(QWidget *parent = nullptr);

    ~GDAzimuthWidget() override = default;

    [[nodiscard]] QColor color() const;

    void setColor(const QColor &color);

    [[nodiscard]] int azimuth() const;

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void setAzimuth(int azimuth);

signals:
    void azimuthChanged(int azimuth);
};


#endif //GDAZIMUTHWIDGET_H
