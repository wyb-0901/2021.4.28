#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
        client = new QTcpSocket(this);
        client->abort();
           //连接TCP客户端处理相关的信号与槽
           connect(client,SIGNAL(readyRead()),this,SLOT(ReadData()));
           connect(client,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(ReadError(QAbstractSocket::SocketError)));
           //连接服务器
           client->connectToHost("192.168.4.1",8080);
           if (client->waitForConnected(1000))
               ui->textBrowser->setText("yes");
           else
               ui->textBrowser->setText("error!");
       }


void Widget::on_textBrowser_destroyed()
{

}

void Widget::on_pushButton_pressed()//上
{
    QString data = "GO";
        ui->textBrowser->setText("前进");
        client->write(data.toLatin1());
}

void Widget::on_pushButton_released()//上
{
    QString data = "STOP";
        client->write(data.toLatin1());
}

void Widget::on_pushButton_2_pressed()//下
{
    QString data = "BACK";
        ui->textBrowser->setText("后退");
        client->write(data.toLatin1());
}

void Widget::on_pushButton_2_released()//下
{
    QString data = "STOP";
        client->write(data.toLatin1());
}

void Widget::on_pushButton_4_pressed()//左
{
    QString data = "LEFT";
        ui->textBrowser->setText("左转");
        client->write(data.toLatin1());
}

void Widget::on_pushButton_4_released()//左
{
    QString data = "STOP";
        client->write(data.toLatin1());
}

void Widget::on_pushButton_3_pressed()//右
{
    QString data = "RIGHT";
        ui->textBrowser->setText("右转");
        client->write(data.toLatin1());
}

void Widget::on_pushButton_3_released()//右
{
    QString data = "STOP";
        client->write(data.toLatin1());
}

Widget::~Widget()
{
    delete client;
    delete ui;
}



