#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = new QTcpSocket; // 创建socket对象
    // 回车
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_close_button_clicked()
{
    this->close();
}

void Widget::on_connect_buttun_clicked()
{
    // 获取ip和端口号
    QString ip = ui->ip_edit->text();
    QString post = ui->post_edit->text();

    // 连接
    socket->connectToHost(QHostAddress(ip), post.toShort());

    // 成功信号
    connect(socket, &QTcpSocket::connected, [this](){
        QMessageBox::information(this, "连接提示", "连接成功");

        // 隐藏
        this->hide();
        chat *c = new chat(socket);
        c->show();
    });
    // 断开信号
    connect(socket, &QTcpSocket::disconnected, [this](){
        QMessageBox::information(this, "断开提示", "网络断开");
    });
}



