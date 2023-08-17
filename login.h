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
class Login;
}

class Login : public QDialog {
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
private:
    Ui::Login *ui;
};

#endif // LOGIN_H
