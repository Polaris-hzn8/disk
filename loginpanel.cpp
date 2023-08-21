/*************************************************************************
    > File Name: login.cpp
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-17 17:35:03
************************************************************************/

#include "loginpanel.h"
#include "config.h"
#include <QDir>
#include <QFile>
#include <QGraphicsDropShadowEffect>
#include <QIcon>
#include <QJsonDocument>
#include <QJsonObject>
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
    // 1.初始化窗口样式
    _background = QPixmap(LOGIN_BG_PATH);
    ui->stackedWidget->setCurrentIndex(0);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags()); //去掉边框
    setWindowTitle("YunDisk");
    setFixedSize(800, 500);
    setWindowIcon(QIcon(APP_ICON_PATH));
    QFont font;
    font.setFamily("Microsoft YaHei");
    setFont(font);
    // 2.页面间的跳转
    //setting_page
    connect(ui->returnBtn_s, &QToolButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
        _background = QPixmap(LOGIN_BG_PATH);
        update();
    });

    //regis_page
    connect(ui->returnBtn_r, &QToolButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
        _background = QPixmap(LOGIN_BG_PATH);
        update();
    });
    //login_page
    connect(ui->regisBtn, &QToolButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
        _background = QPixmap(REGIS_BG_PATH);
        update();
    });
}

void LoginPanel::on_submitBtn_clicked()
{
    //1.从控件中取出用户输入的数据
    QString yunid = ui->yunid_inp->text();
    QString username = ui->username_inp->text();
    QString passwd1 = ui->pwd_inp1->text();
    QString passwd2 = ui->pwd_inp2->text();
    QString phone = ui->phone_inp->text();
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
    bool flag5 = regexp.exactMatch(phone);
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
    /*
        {
            yunid:xxx,
            username:xxxx,
            passwd:xxx,
            phone:xxx,
            email:xxx
        }
    */
    QJsonObject obj1;
    obj1.insert("yunid", yunid);
    obj1.insert("username", username); //QJsonValue(username)
    obj1.insert("passwd", passwd1);
    obj1.insert("phone", phone);
    obj1.insert("email", email);
    //obj -> doc -> qbytearray
    QJsonDocument doc1(obj1);
    QByteArray json = doc1.toJson();
    //（3）发送数据
    QNetworkReply* reply = pManager->post(request, json);

    //4.接受服务器发送的响应 并对响应进行分析处理
    connect(reply, &QNetworkReply::readyRead, this, [=]() {
        //（1）接受数据
        QByteArray all = reply->readAll();
        //（2）解析数据
        //qbytearray -> doc -> obj
        QJsonDocument doc2 = QJsonDocument::fromJson(all);
        QJsonObject obj2 = doc2.object();
        QString status = obj2.value("code").toString();
        //（3）判断是否成功
        if (status == "002") {
            //注册成功

        } else if (status == "003") {
            //用户已经存在

        } else {
            //其他错误
        }
    });
}

void LoginPanel::on_loginBtn_clicked()
{
}

void LoginPanel::on_confsaveBtn_clicked()
{
    //校验remote配置
    QString ip = ui->ip->text();
    QString port = ui->port->text();
    QRegExp regexp;
    regexp.setPattern(IP_REG); //校验ip地址
    if (!regexp.exactMatch(ip)) {
        QMessageBox::warning(this, "incorrect", "Please enter a valid format IP address.");
        return;
    }
    regexp.setPattern(PORT_REG); //校验port端口
    if (!regexp.exactMatch(port)) {
        QMessageBox::warning(this, "incorrect", "The port is out of range.");
        return;
    }

    //将remote配置信息转为json格式
    QJsonObject obj;
    obj.insert("ip", ip);
    obj.insert("port", port);
    QJsonDocument doc(obj);
    QByteArray json = doc.toJson();

    //创建文件目录
    QDir dir;
    QString dirpath = QFileInfo(CONFFILE).absolutePath();
    if (!dir.exists(dirpath)) {
        qDebug() << QString("debug: create dir: %1").arg(dirpath);
        dir.mkpath(dirpath);
    }

    //打开or创建文件
    QFile file(CONFFILE);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        file.write(json);
        file.close();
        qDebug() << "config save successfully in " << CONFFILE;
        qDebug() << "ip = " << ip << " port = " << port;
        QMessageBox::information(this, "sucess", "config success!");
        //设置成功后切换到首页
        ui->stackedWidget->setCurrentIndex(0);
        _background = QPixmap(LOGIN_BG_PATH);
        update();
    } else {
        QString errorInfo = QString("Error: Unable to open %1 for writing.").arg(CONFFILE);
        QMessageBox::critical(this, "Error", errorInfo);
    }
}

void LoginPanel::on_settingBtn_clicked()
{
    //1.切换stackpage页面
    // 0 login_page 1 regis_page 2 setting_page
    ui->stackedWidget->setCurrentIndex(2);
    //2.切换背景图片
    _background = QPixmap(SETTING_BG_PATH);
    update();
    //3.读取已有配置信息
    QString ip = "";
    QString port = "";
    QFile file(CONFFILE);
    if (file.open(QFile::ReadOnly)) {
        QByteArray all = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(all);
        QJsonObject obj = doc.object();
        ip = obj.value("ip").toString(); //ip
        port = obj.value("port").toString(); //port
        qDebug() << "read config file sccuess.";
        qDebug() << "ip = " << ip << " port = " << port;
    }
    file.close();
    //4.将配置填充到lineEdit中
    ui->ip->setText(ip);
    ui->port->setText(port);
}

void LoginPanel::paintEvent(QPaintEvent* e)
{
    //绘制登录窗口的背景图
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), _background);
}

LoginPanel::~LoginPanel()
{
    delete ui;
}
