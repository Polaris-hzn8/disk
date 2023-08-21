/*************************************************************************
    > File Name: titlewedget.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:55:51
************************************************************************/

#include "titlebar.h"
#include "config.h"
#include "ui_titlebar.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>

TitleBar::TitleBar(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TitleBar)
{
    _parent = parent;
    setFixedSize(800, 54);
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
    ui->text->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
    //settingBtn
    connect(ui->settingBtn, &QPushButton::clicked, this, [=]() {
        emit showSettingPanel();
    });
    //minimalBtn
    connect(ui->minimalBtn, &QPushButton::clicked, this, [=]() {
        parentWidget()->showMinimized();
    });
    //closeBtn
    connect(ui->closeBtn, &QPushButton::clicked, this, [=]() {
        this->parentWidget()->close();
    });
}

void TitleBar::mouseMoveEvent(QMouseEvent* e)
{
    //只允许左键拖动窗口（持续操作）
    if (e->buttons() & Qt::LeftButton) {
        //窗口跟随鼠标移动
        //窗口左上角位置 = 鼠标当前位置 - 求差值
        _parent->move(e->globalPos() - _dist);
    }
}

void TitleBar::mousePressEvent(QMouseEvent* e)
{
    //只允许左键操作（瞬间操作）
    if (e->button() == Qt::LeftButton) {
        //求差值 = 鼠标当前位置 - 窗口左上角位置
        _dist = e->globalPos() - _parent->geometry().topLeft();
    }
}

void TitleBar::paintEvent(QPaintEvent* e)
{
    //绘制titleBar的背景图
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(TITLE_BAR_PATH));
}

TitleBar::~TitleBar()
{
    delete ui;
}
