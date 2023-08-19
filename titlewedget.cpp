/*************************************************************************
    > File Name: titlewedget.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:55:51
************************************************************************/

#include "titlewedget.h"
#include "ui_titlewedget.h"

TitleWedget::TitleWedget(QWidget *parent):QWidget(parent), ui(new Ui::TitleWedget) {
    //logo
    ui->setupUi(this);
    QPixmap logo = QPixmap(":/res/img/YunDisk.png").scaled(40, 30);
    ui->logo->setPixmap(logo);
    ui->logo->setFixedSize(logo.width()+8, logo.height());
    //text
    QFont font;
    font.setFamily("JetBrains Mono");
    font.setPixelSize(14);
    ui->text->setFont(font);
    ui->text->setText("YunDisk");
    ui->text->setFixedSize(100, logo.height());
    ui->text->setAlignment(Qt::AlignLeft|Qt::AlignBottom);

}

TitleWedget::~TitleWedget() {
    delete ui;
}
