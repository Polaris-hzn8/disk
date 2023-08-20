/*************************************************************************
    > File Name: mainwindow.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:35:19
************************************************************************/

#include "mainpanel.h"
#include "ui_mainpanel.h"

MainPanel::MainPanel(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPanel)
{
    ui->setupUi(this);
}

MainPanel::~MainPanel()
{
    delete ui;
}
