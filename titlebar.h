/*************************************************************************
    > File Name: titlewedget.h
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:55:59
************************************************************************/

#ifndef TITLEWEDGET_H
#define TITLEWEDGET_H

#include <QWidget>

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget {
    Q_OBJECT
public:
    explicit TitleBar(QWidget* parent = nullptr);
    ~TitleBar();
    void paintEvent(QPaintEvent* e); //绘制窗口图像

protected:
    void mouseMoveEvent(QMouseEvent* e);
    void mousePressEvent(QMouseEvent* e);

private:
    Ui::TitleBar* ui;
    QPoint _dist; //差值 鼠标当前位置 - 窗口左上角点
    QWidget* _parent; //TitleBar的窗口类
};

#endif // TITLEWEDGET_H
