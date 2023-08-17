/*************************************************************************
    > File Name: titlewedget.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:55:51
************************************************************************/

#include "titlewedget.h"
#include "ui_titlewedget.h"

TitleWedget::TitleWedget(QWidget *parent):QWidget(parent), ui(new Ui::TitleWedget) {
    ui->setupUi(this);
}

TitleWedget::~TitleWedget() {
    delete ui;
}
