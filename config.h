/*************************************************************************
    > File Name: config.h
    > Author: Polaris-hzn8
    > Mail: 3453851623@qq.com
    > Created Time: 2023-08-19 18:50:58
************************************************************************/

#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

/**************** 应用图标配置 *************/
#define APP_LOGO_PATH ":/res/img/YunDisk.png"
#define APP_ICON_PATH ":/res/img/YunDisk32.png"

/**************** 应用背景图片配置 *************/
#define TITLE_BAR_PATH ":/res/img/titleBar.png"
#define LOGIN_BG_PATH ":/res/img/loginbg.png"
#define REGIS_BG_PATH ":/res/img/registerbg.png"
#define SETTING_BG_PATH ":/res/img/settingbg.png"

// 文件路径
const QString CONFFILE = "conf/conf.json"; // 配置文件
const QString RECORDDIR = "conf/record/"; // 用户文件上传下载记录
const QString FILETYPEDIR = "conf/fileType"; // 存放文件类型图片目录

// 正则表达式
const QString YUNID_REG = "^[a-zA-Z0-9]\\{12\\}$";
const QString USERNAME_REG = "^[a-zA-Z\\d_@#-\\*]\\{3,16\\}$";
const QString PASSWD_REG = "^[a-zA-Z\\d_@#-\\*]\\{6,18\\}$";
const QString PHONE_REG = "1\\d\\{10\\}";
const QString EMAIL_REG = "^[a-zA-Z\\d\\._-]\\+@[a-zA-Z\\d_\\.-]\\+(\\.[a-zA-Z0-9_-]\\+)+$";
const QString IP_REG = "((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)";
const QString PORT_REG = "^[1-9]$|(^[1-9][0-9]$)|(^[1-9][0-9][0-9]$)|(^[1-9][0-9][0-9][0-9]$)|(^[1-6][0-5][0-5][0-3][0-5]$)";

#endif // CONFIG_H
