#include "GDForms/GDMainForm.h"

// QScopedPointer<QFile>   _logFile;
//
// void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    // const auto pathLogFile = QDir(QDir::current()).filePath("application.log");

    // _logFile.reset(new QFile(pathLogFile));
    // _logFile.data()->open(QFile::Append | QFile::Text);

    // qInstallMessageHandler(messageHandler);

    qDebug() << "Qt Version: " << qVersion();

    const auto mainForm = new GDMainForm();
    mainForm->show();

    return QApplication::exec();
}

// void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
// {
//     // Open stream file writes
//     QTextStream out(_logFile.data());
//     // Write the date of recording
//     out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
//     // By type determine to what level belongs message
//     switch (type)
//     {
//         case QtInfoMsg:     out << "INF "; break;
//         case QtDebugMsg:    out << "DBG "; break;
//         case QtWarningMsg:  out << "WRN "; break;
//         case QtCriticalMsg: out << "CRT "; break;
//         case QtFatalMsg:    out << "FTL "; break;
//     }
//     // Write to the output category of the message and the message itself
//     out << context.category << ": "<< msg << Qt::endl;
//     out.flush();    // Clear the buffered data
// }
