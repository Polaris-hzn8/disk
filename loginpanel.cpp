/*************************************************************************
    > File Name: login.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:35:03
************************************************************************/

#include "loginpanel.h"
#include "config.h"
#include <QGraphicsDropShadowEffect>
#include <QIcon>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPainter>
#include <ui_loginpanel.h>

LoginPanel::LoginPanel(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LoginPanel)
{
    ui->setupUi(this);
    //初始化窗口样式
    _background = QPixmap(LOGIN_BG_PATH);
    ui->stackedWidget->setCurrentIndex(0);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags()); //去掉边框
    setWindowTitle("YunDisk");
    setFixedSize(800, 500);
    setWindowIcon(QIcon(APP_ICON_PATH));
    QFont font;
    font.setFamily("Microsoft YaHei");
    setFont(font);
    //1.titleBar
    connect(ui->titleBar, &TitleBar::showSettingPanel, [=]() {
        // 0 login_page 1 regis_page 2 setting_page
        _background = QPixmap(SETTING_BG_PATH);
        update();
        ui->stackedWidget->setCurrentIndex(2);
    });

    //2.setting_page
    connect(ui->configBtn, &QToolButton::clicked, this, [=]() {
        //保存并设置remote配置
        _background = QPixmap(LOGIN_BG_PATH);
        update();
    });
    connect(ui->returnBtn_s, &QToolButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
        _background = QPixmap(LOGIN_BG_PATH);
        update();
    });

    //4.regis_page
    connect(ui->returnBtn_r, &QToolButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
        _background = QPixmap(LOGIN_BG_PATH);
        update();
    });

    //5.login_page
    connect(ui->regisBtn, &QToolButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
        _background = QPixmap(REGIS_BG_PATH);
        update();
    });
}

void LoginPanel::paintEvent(QPaintEvent* e)
{
    //绘制登录窗口的背景图
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), _background);
}

void LoginPanel::on_submitBtn_clicked()
{
    //1.从控件中取出用户输入的数据
    QString yunid = ui->yunid_inp->text();
    QString username = ui->username_inp->text();
    QString passwd1 = ui->pwd_inp1->text();
    QString passwd2 = ui->pwd_inp2->text();
    QString phoneNumber = ui->phone_inp->text();
    QString email = ui->email_inp->text();

    //2.数据校验
    QRegExp regexp;
    bool res = true;
    //yunid
    regexp.setPattern(YUNID_REG);
    bool flag1 = regexp.exactMatch(yunid);
    if (!flag1) {
        QMessageBox::warning(this, "ERROR", "用户名格式不正确");
    }
    //username
    regexp.setPattern(USERNAME_REG);
    bool flag2 = regexp.exactMatch(username);
    if (!flag2) {
        QMessageBox::warning(this, "ERROR", "用户名格式不正确");
    }
    //passwd1
    regexp.setPattern(PASSWD_REG);
    bool flag3 = regexp.exactMatch(passwd1);
    if (!flag3) {
        QMessageBox::warning(this, "ERROR", "用户名格式不正确");
    }
    //passwd2
    bool flag4 = true;
    if (passwd1 != passwd2) {
        flag4 = false;
        QMessageBox::warning(this, "ERROR", "用户名格式不正确");
    }
    //phoneNumber
    regexp.setPattern(PHONE_REG);
    bool flag5 = regexp.exactMatch(phoneNumber);
    if (!flag5) {
        QMessageBox::warning(this, "ERROR", "用户名格式不正确");
    }
    //email
    regexp.setPattern(EMAIL_REG);
    bool flag6 = regexp.exactMatch(email);
    if (!flag6) {
        QMessageBox::warning(this, "ERROR", "用户名格式不正确");
    }
    res = flag1 & flag2 & flag3 & flag4 & flag5 & flag6;
    if (!res) {
        return; //数据有误
    }

    //3.将数据发送给服务器 采用http协议的post方式 数据以json格式
    QNetworkAccessManager* pManager = new QNetworkAccessManager(this);
    //（1）组装request请求
    QNetworkRequest request;
    QString url = QString("http://%1:%2/reg").arg(ui->ip->text()).arg(ui->port->text());
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json"); //post数据格式
    //（2）将用户数据组装成json格式

    //（3）发送数据
    QNetworkReply* reply = pManager->post(request, data);

    //4.接受服务器发送的响应
    connect(reply, &QNetworkReply::readyRead, this, [=]() {
        //（1）接受数据
        QByteArray response = reply->readAll();
        //（2）解析数据

        //（3）判断是否成功
    });

    //5.对响应进行分析处理
}

LoginPanel::~LoginPanel()
{
    delete ui;
}
