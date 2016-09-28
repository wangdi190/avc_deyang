#include "mainwindow.h"
#include <QApplication>

#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

 //   a.setWindowIcon(QIcon("./wd.ico"));

//    QTextCodec *codec = QTextCodec::codecForName("System");

//    QTextCodec::setCodecForLocale(codec);
 //   QTextCodec::setCodecForCStrings(codec);
//    QTextCodec::setCodecForTr(codec);



    MainWindow w;
    w.show();

    return a.exec();
}
