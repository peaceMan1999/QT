#include "mythread.h"

myThread::myThread(QTcpSocket *s)
{
    socket = s;
}

void myThread::run(){
    connect(socket, &QTcpSocket::readyRead, this, &myThread::connect_socket);
}

void myThread::connect_socket(){
    // 怎么从mythread传到widget上？通过自定义信号！！！
    QByteArray arr = socket->readAll();
//    qDebug() << QString(arr);
    emit sendToWidget(arr);
}
