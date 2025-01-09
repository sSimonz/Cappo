#include "PlayWidget.h"
#include <QApplication>
#include <QFileInfo>
#include <QTranslator>
#include <QDir>
#include "mainwindow.h"
#include "comm/CXmlLanguage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 读取xml文件
    QTranslator appTranslator;
    QString xmlLanguage = "/Language/CHS.xml";
#ifdef Q_OS_WIN
    // app路径
    QFileInfo appInfo(qApp->applicationFilePath());
    QDir appDir = appInfo.absoluteDir();  //绝对路径
    InitXmlLanguage(appDir.absolutePath() + xmlLanguage);
#else
    // app路径
    QString appDirPath = QCoreApplication::applicationDirPath();
    QDir dir(appDirPath);
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    appDirPath = dir.absolutePath();
    InitXmlLanguage(appDirPath + xmlLanguage);
#endif

//    PlayWidget w;
    MainWindow w;
    w.show();

    return a.exec();
}
