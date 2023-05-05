#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 连接
    connect(ui->newAction, &QAction::triggered, this, &MainWindow::newActionSlot);
    connect(ui->openAction, &QAction::triggered, this, &MainWindow::openActionSlot);
    connect(ui->saveAction, &QAction::triggered, this, &MainWindow::saveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newActionSlot(){
    ui->textEdit->clear();
    this->setWindowTitle("创建文档");
}

void MainWindow::openActionSlot(){
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("打开"),
        QCoreApplication::applicationDirPath(),
        tr("Images (*.cpp)"));
    if (fileName.isEmpty()){
        QMessageBox::warning(this, "警告", "请选择一个文件");
    }else{
//        qDebug() << fileName;
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QByteArray arr = file.readAll();
        ui->textEdit->setText(QString(arr));
        file.close();
    }
}

void MainWindow::saveActionSlot(){
    QString fileName = QFileDialog::getSaveFileName(
                this,
                tr("另存为"),
                QCoreApplication::applicationDirPath());
    if (fileName.isEmpty()){
        QMessageBox::warning(this, "警告", "请选择一个文件");
    }else{
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QByteArray arr;
        arr.append(ui->textEdit->toPlainText());
        file.write(arr);
        file.close();
    }
}

// 点击事件
void MainWindow::keyPressEvent(QKeyEvent *k){
    if (k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_S){
        saveActionSlot();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *m){
    QPoint pt = m->pos();
    qDebug() << pt;
    // 事件
    if (m->button() == Qt::LeftButton){
        qDebug() << "左点击";
    }else if (m->button() == Qt::RightButton){
        qDebug() << "右点击";
    }
}

