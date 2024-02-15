---
title: QT - 实例 - 可点击的进度条、无窗口应用
date: 2023-08-02 09:50:11
tags: [其他, QT, 实例, QT实例]
descriptions: QT无窗口应用  QT可点击的进度条
---

# QT - 实例 - 可点击的进度条、无窗口应用

## QT无窗口应用

如果窗口类的```RestReminder```，则在其构造函数中添加以下两行代码即可：

```cpp
setAttribute(Qt::WA_TranslucentBackground);
setWindowFlags(Qt::FramelessWindowHint);  // 此行windows下需
```

更多操作推荐参考博客：[博客园：Qt界面外观之一：Qt风格与特殊效果窗体](https://www.cnblogs.com/linuxAndMcu/p/10133983.html#5197834)

## QT可点击的进度条

QT的```QPushButton```是有```click()```方法的，直接如下就可以：

```cpp
connect(pushbutton, SIGNAL(clicked()), this, SLOT(on_pushbutton_clicked()));
```

但是QT的```QProgressBar```没有```click()```方法，需要我们手动处理```鼠标事件```。

可以写一个```ClickableProgressBar```类，继承```QProgressBar```：

```cpp
class ClickableProgressBar : public QProgressBar {
public:
    ClickableProgressBar(QWidget* parent = nullptr) : QProgressBar(parent) {}

protected:
    void mousePressEvent(QMouseEvent* event) override {
        qDebug() << "clickableProgressBar clicked" << endl;
        for (int i = 0; i <= 100; i++) {
            setValue(i);
            Sleep(10);
        }
    }
};
```

这样，在点击进度条时，就会从0到100逐渐填充完毕了。

## 完整代码

main.cpp

```cpp
#include "RestReminder.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RestReminder w;
    w.show();
    return a.exec();
}
```

RestReminder.h

```cpp
#pragma once

#include <QtWidgets/QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>
#include <Windows.h>
#include "ui_RestReminder.h"

class ClickableProgressBar : public QProgressBar {
public:
    ClickableProgressBar(QWidget* parent = nullptr) : QProgressBar(parent) {}

protected:
    void mousePressEvent(QMouseEvent* event) override {
        qDebug() << "clickableProgressBar clicked" << endl;
        for (int i = 0; i <= 100; i++) {
            setValue(i);
            Sleep(10);
        }
    }
};

class RestReminder : public QWidget {
    Q_OBJECT

public:
    RestReminder(QWidget *parent = nullptr);
    ~RestReminder();

    ClickableProgressBar * clickableProgressBar;
    QPushButton* pushbutton;

private slots:
    // void on_clickableProgressBar_clicked();
    void on_pushbutton_clicked();

private:
    Ui::RestReminderClass ui;

    void initUI();
};
```

RestReminder.cpp

```cpp
#include "RestReminder.h"

RestReminder::RestReminder(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    // 取消窗口
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);

    initUI();
}

RestReminder::~RestReminder()
{}

void RestReminder::initUI() {
    // progressBar
    clickableProgressBar = new ClickableProgressBar(this);
    clickableProgressBar->setOrientation(Qt::Vertical);
    clickableProgressBar->setMinimum(0);
    clickableProgressBar->setMaximum(100);
    // connect(pushbutton, &QProgressBar::mousePressEvent, this, &RestReminder::on_pushbutton_clicked);
    // connect(progressBar, SIGNAL(clicked()), this, SLOT(on_progressBar_clicked()));

    // pushbutton
    pushbutton = new QPushButton(this);
    pushbutton->setText("66666");
    connect(pushbutton, SIGNAL(clicked()), this, SLOT(on_pushbutton_clicked()));
}

//void RestReminder::on_progressBar_clicked() {
//    qDebug() << "progressBar clicked" << endl;
//    for (int i = 0; i <= 100; i++) {
//        progressBar->setValue(i);
//    }
//}

void RestReminder::on_pushbutton_clicked() {
    qDebug() << "pushbutton clicked" << endl;
    clickableProgressBar->setValue(50);
}

//void RestReminder::on_clickableProgressBar_clicked() {
//    qDebug() << "clickableProgressBar clicked" << endl;
//    clickableProgressBar->setValue(100);
//}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/08/02/Other-QT-Example-ClickableProgressBar-noWindow/)哦~
> Tisfy：[https://blog.letmefly.xyz/2023/08/02/Other-QT-Example-ClickableProgressBar-noWindow/](https://blog.letmefly.xyz/2023/08/02/Other-QT-Example-ClickableProgressBar-noWindow/)
