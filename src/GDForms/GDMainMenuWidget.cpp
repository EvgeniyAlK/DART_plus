//
// Created by andreysh on 22.10.24.
//

#include "GDMainMenuWidget.h"

#include "../GDPlatform/GDUtils.h"

class File final {
public:
    QLabel* title = new QLabel(QObject::tr("Файл"));
    const QAction *createNewHole = new QAction(QObject::tr("Создать новую скважину"));
    const QAction *sendToUSB = new QAction(QObject::tr("Отправить на USB"));
    const QAction *saveToCSV = new QAction(QObject::tr("Сохранить в CSV"));
    const QAction *openFile = new QAction(QObject::tr("Открыть файл"));
};

GDMainMenuWidget::GDMainMenuWidget(QWidget *parent): QScrollArea(parent) {
    const auto file = new File();
    const auto layout = new QHBoxLayout(this);
    const auto leftLayout = new QVBoxLayout(this);

    leftLayout->setAlignment(Qt::AlignCenter);

    layout->addLayout(leftLayout);

    setAutoFillBackground(true);
    setGeometry(0, 0, 0, 0);

    leftLayout->setSpacing(5);

    auto bt = new QPushButton(file->createNewHole->text());
    bt->setBaseSize(300, 30);


    leftLayout->addWidget(file->title);
    leftLayout->addWidget(bt);
    leftLayout->addWidget(new QPushButton(file->sendToUSB->text()));
    leftLayout->addWidget(new QPushButton(file->saveToCSV->text()));
    leftLayout->addWidget(new QPushButton(file->openFile->text()));

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    const auto widget = new QWidget(this);
    widget->setLayout(layout);

    setWidget(widget);
}
