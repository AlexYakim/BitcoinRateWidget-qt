#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Set Windows widget`s property

   setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowOpacity(0.85);
    setWindowFlag(Qt::WindowStaysOnTopHint);

    ui->setupUi(this);

// Settings of request to API

    currency_now.SetUrl("https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=usd&include_24hr_change=true&include_24hr_vol=true&include_last_updated_at=true");
    currency_now.Request_now();
    currensy_1h_1d_7d.SetUrl("https://api.coingecko.com/api/v3/coins/bitcoin");
    currensy_1h_1d_7d.Request_1h_1d_7d();

    ui->Changed1H->setText("Changed 1H");
    ui->Changed1D->setText("Changed 1D");
    ui->Changed7D->setText("Changed 7D");

    QPixmap pixmap(":/images/images/bitcoin.png");


    ui->bitcoin_pic->setPixmap(pixmap.scaled(135,175,Qt::KeepAspectRatio));
    ui->bitcoin_currency->setText("$");


    timer_now=new QTimer();
    timer_now->start(6000);
    connect(timer_now,&QTimer::timeout,this,&MainWindow::Data_update_now);

}

MainWindow::~MainWindow()
{
    delete ui;

}

// Bitcoin data display
void MainWindow:: Data_update_now(){

currency_now.Request_now();
ui->bitcoin_currency->setText(QString("$ ")+QString::number(currency_now.price_now,'f',2));
currensy_1h_1d_7d.Request_1h_1d_7d();
currensy_1h_1d_7d.price_1h>0?ui->percent1H->setStyleSheet("color:green"):ui->percent1H->setStyleSheet("color:red");
ui->percent1H->setText(QString::number(currensy_1h_1d_7d.price_1h,'f',2)+QString(" %"));
currensy_1h_1d_7d.price_1d>0?ui->percent1D->setStyleSheet("color:green"):ui->percent1D->setStyleSheet("color:red");
ui->percent1D->setText(QString::number(currensy_1h_1d_7d.price_1d,'f',2)+QString(" %"));
currensy_1h_1d_7d.price_7d>0?ui->percent7D->setStyleSheet("color:green"):ui->percent7D->setStyleSheet("color:red");
ui->percent7D->setText(QString::number(currensy_1h_1d_7d.price_7d,'f',2)+QString(" %"));
QDateTime currentDateTime = QDateTime::currentDateTime();
ui->Last_updating->setText(QString("Останнє обновлення: ")+currentDateTime.toString("dd/MM/yyyy hh:mm:ss"));
}

//Controlling widget repositioning with the mouse
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}


// Open and close button

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_clicked()
{
  this->showMinimized();
}


