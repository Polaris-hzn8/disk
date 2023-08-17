/*************************************************************************
    > File Name: login.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:35:03
************************************************************************/

#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent):QDialog(parent), ui(new Ui::Login) {
    ui->setupUi(this);
}

Login::~Login() {
    delete ui;
}
