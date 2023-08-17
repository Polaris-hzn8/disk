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
class TitleWedget;
}

class TitleWedget : public QWidget {
    Q_OBJECT
public:
    explicit TitleWedget(QWidget *parent = nullptr);
    ~TitleWedget();
private:
    Ui::TitleWedget *ui;
};

#endif // TITLEWEDGET_H

