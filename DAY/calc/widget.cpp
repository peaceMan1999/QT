#include "widget.h"
#include "ui_widget.h"
#include <string.h>
#include <iostream>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMaximumSize(300,350);
    this->setMinimumSize(300,350);

    this->setWindowTitle("计算器");

    QFont qf("仿宋", 14); // 字体对象
    ui->Msg_Edit->setFont(qf);

    QIcon con("D:\\QT\\Project\\calc\\back.png"); // 图片对象
    ui->Erase_Button->setIcon(con);

    ui->GetNum_Button->setStyleSheet( "background: yellow" );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_1_clicked()
{
    exp += "1";
    ui->Msg_Edit->setText(exp);
}


void Widget::on_pushButton_2_clicked()
{
    exp += "2";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_pushButton_3_clicked()
{
    exp += "3";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_pushButton_4_clicked()
{
    exp += "4";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_pushButton_5_clicked()
{
    exp += "5";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_pushButton_6_clicked()
{
    exp += "6";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_pushButton_7_clicked()
{
    exp += "7";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_pushButton_8_clicked()
{
    exp += "8";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_pushButton_9_clicked()
{
    exp += "9";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_pushButton_0_clicked()
{
    exp += "0";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_Clear_Button_clicked()
{
    exp.clear();
    ui->Msg_Edit->setText(exp);
}

void Widget::on_Erase_Button_clicked()
{
    exp.chop(1);
    ui->Msg_Edit->setText(exp);
}

void Widget::on_GetNum_Button_clicked()
{
    QByteArray arr;
    arr.append(exp); // 把 QString 转换为 QByteArray;
    char ch[128] = {0};
    strcpy(ch, arr.data()); // 把 QByteArray 转为 char*

    char a = ch[0];
    char b = ch[2];
    int first_num = a - '0';

    char sign = ch[1];
    int second_num = b - '0';
    int ans = 0;
    std::cout << first_num << " " << sign << " " << second_num << std::endl;
    switch(sign){
        case '+':
            ans = first_num + second_num;
            std::cout << ans << std::endl;
            break;
        case '*':
            ans = first_num * second_num;
            std::cout << ans << std::endl;
            break;
    }
    std::cout << ans << std::endl;
    exp.clear();
    exp = QString::number(ans);
    ui->Msg_Edit->setText(exp);
}

void Widget::on_Mult_Button_clicked()
{
    exp += "*";
    ui->Msg_Edit->setText(exp);
}

void Widget::on_Add_Button_clicked()
{
    exp += "+";
    ui->Msg_Edit->setText(exp);
}
