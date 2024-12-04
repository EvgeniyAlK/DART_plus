//
// Created by andreysh on 19.10.24.
//

#ifndef UTILS_H
#define UTILS_H

#include "../Dependency.h"


inline void setBackgroundColor(QWidget* _this, const QString &color) {
    QString style = "background-color: " + color + ";";
    _this->setStyleSheet(style);
}

inline void resetSpacing(QWidget* _this) {
    _this->setContentsMargins(0, 0, 0, 0);
}

inline void resetSpacing(QLayout* _this) {
    _this->setContentsMargins(0, 0, 0, 0);
    _this->setSpacing(0);
}

inline void basicPrepareOfWidget(QWidget* widget, QLayout* layout, const QString &backgroundColor) {
    resetSpacing(widget);
    resetSpacing(layout);
    setBackgroundColor(widget, backgroundColor);
}

inline void basicPrepareOfWidget(QWidget* widget, QLayout* layout) {
    resetSpacing(widget);
    resetSpacing(layout);
}

#endif //UTILS_H
