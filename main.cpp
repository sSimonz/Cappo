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
    // app路径
    QFileInfo appInfo(qApp->applicationFilePath());
    QDir appDir = appInfo.absoluteDir();  //绝对路径
    InitXmlLanguage(appDir.absolutePath() + xmlLanguage);

//    PlayWidget w;
    MainWindow w;
    w.show();

    return a.exec();
}
