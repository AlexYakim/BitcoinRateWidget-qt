#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Getting the screen size for the start position of the widget on the screen

    w.setStyleSheet("background-color:#f0f0f0;  border-radius: 10px");
    QRect  screenGeometry = QApplication::primaryScreen()->geometry();
    int x = screenGeometry.width() - w.width();
    double controlPanelHeight = screenGeometry.height() -QApplication::primaryScreen()->availableGeometry().height();
    int y = (screenGeometry.height()-controlPanelHeight) - w.height();
    w.move(x,y);

    w.show();
    return a.exec();
}
