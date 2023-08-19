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
    explicit TitleBar(QWidget *parent = nullptr);
    ~TitleBar();
private:
    Ui::TitleBar *ui;
};

#endif // TITLEWEDGET_H

