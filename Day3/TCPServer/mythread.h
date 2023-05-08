#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QTcpSocket *s);
    // 重写run函数
    void run();

signals:
    void sendToWidget(QByteArray ba);

public slots:
    void connect_socket();
private:
    QTcpSocket *socket;
};

#endif // MYTHREAD_H
