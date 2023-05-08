#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    server = new QTcpServer;

    server->listen(QHostAddress::AnyIPv4, 8081);

    // 客户端发来连接信号处理
    connect(server, &QTcpServer::newConnection, this, &Widget::newConnect);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::newConnect()
{
    // 创建套接字
    QTcpSocket *socket = server->nextPendingConnection();
    // 怎么获取信息呢？
    QString ip = socket->peerAddress().toString(); // 获取地址
    QString post = QString::number(socket->peerPort()); // 获取端口号

    ui->ip_Edit->setText(ip);
    ui->post_Edit->setText(post);

//    // 收到信号接收信息
//    connect(socket, &QTcpSocket::readyRead, this, &Widget::getSocketMsg);

    // 多线程下
    myThread *mtd = new myThread(socket);
    mtd->run();

    connect(mtd, &myThread::sendToWidget, this, &Widget::threadSlot);
}

void Widget::threadSlot(QByteArray ba)
{
    ui->lineEdit->setText(QString(ba));
}

//void Widget::getSocketMsg()
//{
//    // 获取信号对象
//    QTcpSocket *s = (QTcpSocket *)sender();
//    ui->lineEdit->setText(QString(s->readAll()));
//}
