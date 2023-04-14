#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include<QTimer>
#include"CurrencyParsing.h"
#include <QMouseEvent>
#include <QDateTime>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void Data_update_now();


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint m_dragPosition;

    QTimer* timer_now;



Currency_parsing currency_now;
Currency_parsing currensy_1h_1d_7d;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
