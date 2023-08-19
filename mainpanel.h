/*************************************************************************
    > File Name: mainwindow.h
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:34:55
************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainPanel; }
QT_END_NAMESPACE

class MainPanel : public QMainWindow {
    Q_OBJECT
public:
    MainPanel(QWidget *parent = nullptr);
    ~MainPanel();
private:
    Ui::MainPanel *ui;
};

#endif // MAINWINDOW_H
