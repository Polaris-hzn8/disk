/*************************************************************************
    > File Name: login.h
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:34:42
************************************************************************/

#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class LoginPanel;
}

class LoginPanel : public QDialog {
    Q_OBJECT
public:
    explicit LoginPanel(QWidget* parent = nullptr);
    ~LoginPanel();

protected:
    void paintEvent(QPaintEvent* e); //绘制窗口图像
private:
    Ui::LoginPanel* ui;
};

#endif // LOGIN_H
