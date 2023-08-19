/*************************************************************************
    > File Name: titlewedget.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:55:51
************************************************************************/

#include "config.h"
#include "titlebar.h"
#include "ui_titlebar.h"

TitleBar::TitleBar(QWidget *parent):QWidget(parent), ui(new Ui::TitleBar) {
    //logo
    ui->setupUi(this);
    QPixmap logo = QPixmap(APP_LOGO_PATH).scaledToWidth(40);
    ui->logo->setPixmap(logo);
    ui->logo->setFixedSize(logo.width(), logo.height());
    //text
    QFont font;
    font.setFamily("JetBrains Mono");
    font.setPixelSize(14);
    ui->text->setFont(font);
    ui->text->setText("YunDisk");
    ui->text->setFixedSize(100, logo.height());
    ui->text->setAlignment(Qt::AlignLeft|Qt::AlignCenter);
}

TitleBar::~TitleBar() {
    delete ui;
}
