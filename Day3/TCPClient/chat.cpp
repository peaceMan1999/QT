#include "chat.h"
#include "ui_chat.h"

chat::chat(QTcpSocket *s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);

    socket = s;
}

chat::~chat()
{
    delete ui;
}

void chat::on_clear_Button_clicked()
{
    ui->lineEdit->clear();
}

void chat::on_send_Button_clicked()
{
    QString str = ui->lineEdit->text();
    QByteArray arr;
    arr.append(str);

    socket->write(arr);
}


void chat::keyPressEvent(QKeyEvent *k)
{
    // 重写了回车，代表回车发送
    if (k->key() == Qt::Key_Return){
        on_send_Button_clicked();
    }
}
