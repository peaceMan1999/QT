#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <chat.h>

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
    void on_close_button_clicked();
    void on_connect_buttun_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
};

#endif // WIDGET_H
