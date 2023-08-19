/*************************************************************************
    > File Name: main.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:35:11
************************************************************************/

#include <QApplication>
#include "mainwindow.h"
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
//    MainWindow w;
//    w.show();
    Login login;
    login.show();
    return app.exec();
}

