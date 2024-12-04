//
// Created by andreysh on 19.10.24.
//

#include "GDAzimuthWidget.h"
#include "../../GDPlatform/GDUtils.h"


GDAzimuthWidget::GDAzimuthWidget(QWidget *parent) {
    resize(200, 200);
}

QColor GDAzimuthWidget::color() const {
    return _color;
}

void GDAzimuthWidget::setColor(const QColor &color) {
    _color = color;

    update();
}

int GDAzimuthWidget::azimuth() const {
    return _azimuth;
}

void GDAzimuthWidget::paintEvent(QPaintEvent *event) {
    static const QPoint hourHand[7] = {
        QPoint(0, 0),
        QPoint(-10, 0),
        QPoint(5, -15),
        QPoint(20, 0),
        QPoint(10, 0),
        QPoint(10, 50),
        QPoint(0, 50)
    };

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width() / 2., height() / 2.);

    painter.setPen(Qt::NoPen);
    painter.setBrush(color());

    painter.save();
    painter.rotate(_azimuth);
    painter.translate(-5, -25);
    painter.drawConvexPolygon(hourHand, 7);
    painter.restore();

    painter.save();
    painter.setPen(color());
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(-75, -75, 150, 150);
    painter.restore();
}

void GDAzimuthWidget::setAzimuth(const int azimuth) {
    _azimuth = azimuth;

    azimuthChanged(azimuth);

    update();
}
