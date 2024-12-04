//
// Created by andreysh on 19.10.24.
//

#ifndef GDMAINFORM_H
#define GDMAINFORM_H

#include "../Dependency.h"
#include "../GDPlatform/GDSerialPort.h"

class GDMainForm : public QMainWindow {
    Q_OBJECT

public:
    explicit GDMainForm(QWidget *parent = nullptr);

    ~GDMainForm() override = default;

    GDSerialPort *gdSerialPort;

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    // main menu
    QMenu *file, *chart, *tools, *options;

    // file actions
    QAction *createNewHole, *sendToUSB, *saveToCSV, *openFile;

    // chart actions
    QAction *signalStrength, *batteryCharge, *temperature;

    // tools actions
    QAction *diagnostics;

    // options actions
    QAction *settings;

public slots:
    void serialResponseReady(QByteArray response);
};


#endif // GDMAINFORM_H
