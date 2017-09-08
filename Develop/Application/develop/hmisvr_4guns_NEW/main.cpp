#include <QtGui/QApplication>
#include "main_dialog.h"
#include "qtextcodec.h"
#include <QtGui>
#include <QWSServer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    //QWSServer::setCursorVisible(false);
    main_dialog w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}


