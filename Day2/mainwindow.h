#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    // 单击事件--重写
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent* event);
    ~MainWindow();

private slots:
    void newActionSlot();
    void openActionSlot();
    void saveActionSlot();


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
