/*************************************************************************
    > File Name: mypushbutton.h
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 20:11:31
************************************************************************/

#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPropertyAnimation>
#include <QPushButton>

class MyPushButton : public QPushButton {
    Q_OBJECT
    //Q_PROPERTY(int rotation READ rotation WRITE setRotation)
public:
    MyPushButton(QWidget *parent = nullptr);
signals:
public slots:
};

#endif // MYPUSHBUTTON_H
