#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_TranslucentBackground, true);
     setWindowFlag(Qt::FramelessWindowHint);
     setWindowOpacity(0.85);
     setWindowFlag(Qt::WindowStaysOnTopHint);

     ui->Changed1H->setText("Changed 1H");
     ui->Changed1D->setText("Changed 1D");
     ui->Changed7D->setText("Changed 7D");

     QPixmap pixmap(":/images/images/bitcoin.png");
     ui->bitcoin_pic->setPixmap(pixmap.scaled(135,175,Qt::KeepAspectRatio));
     ui->bitcoin_currency->setText("$");
}

MainWindow::~MainWindow()
{
    delete ui;
}


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

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_clicked()
{
  this->showMinimized();
}



