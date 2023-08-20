/*************************************************************************
    > File Name: login.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:35:03
************************************************************************/

#include "loginpanel.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <ui_loginpanel.h>

LoginPanel::LoginPanel(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LoginPanel)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags()); //去掉边框
    setWindowTitle("YunDisk");
    setFixedSize(800, 500);
    setWindowIcon(QIcon(APP_ICON_PATH));
    QFont font;
    font.setFamily("Microsoft YaHei");
    setFont(font);
}

void LoginPanel::paintEvent(QPaintEvent* e)
{
    //绘制登录窗口的背景图
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(BASIC_BG_PATH));
}

LoginPanel::~LoginPanel()
{
    delete ui;
}
