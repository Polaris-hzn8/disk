/*************************************************************************
    > File Name: login.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:35:03
************************************************************************/

#include <QGraphicsDropShadowEffect>
#include <QIcon>
#include <QPainter>
#include "config.h"
#include "loginpanel.h"
#include "ui_loginpanel.h"

LoginPanel::LoginPanel(QWidget *parent):QDialog(parent), ui(new Ui::LoginPanel) {
    ui->setupUi(this);
    setWindowTitle("YunDisk");
    setFixedSize(800, 500);
    setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    setWindowIcon(QIcon(APP_ICON_PATH));
    QFont font;
    font.setFamily("Microsoft YaHei");
    setFont(font);
}

void LoginPanel::paintEvent(QPaintEvent *e) {
    //绘制登录窗口的背景图
    QPainter painter(this);
    QPixmap loginBg = QPixmap(BG_LOGIN_PATH);
    painter.drawPixmap(0, 0, width(), height(), loginBg);
}

LoginPanel::~LoginPanel() {
    delete ui;
}
