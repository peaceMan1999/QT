#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <mythread.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void newConnect();
    void threadSlot(QByteArray ba);
//    void getSocketMsg();

private:
    Ui::Widget *ui;
    QTcpServer *server;
};

#endif // WIDGET_H
