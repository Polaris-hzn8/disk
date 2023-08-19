/*************************************************************************
    > File Name: main.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:35:11
************************************************************************/

#include <QApplication>
#include "loginPanel.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    LoginPanel loginpanel;
    loginpanel.show();
    return app.exec();
}

