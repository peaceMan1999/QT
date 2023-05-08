#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>
#include <QByteArray>
#include <QKeyEvent>
#include <QDebug>

namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT

public:
    explicit chat(QTcpSocket *s, QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *k);
    ~chat();

private slots:
    void on_clear_Button_clicked();
    void on_send_Button_clicked();


private:
    Ui::chat *ui;
    QTcpSocket *socket;
};

#endif // CHAT_H
