---
title: Windows程序互斥锁 - 一个程序同时仅允许运行一个实例
date: 2024-02-17 16:52:12
tags: [Windows, 简单, 互斥, 锁, 并发]
---

# Windows程序互斥锁 - 一个程序同时仅允许运行一个实例

## 前言

鉴于应用逻辑需要，有些Windows应用同时只能运行一个实例。例如：一个电脑只能同时运行一个微信（手速快了当我没说，不信你去试试）。

怎么实现呢？大致有两种办法：系统自带的互斥锁 或 （手动实现或系统自带）文件锁。

想要使用系统提供的锁（不论是程序锁还是文件锁），不同系统调用的API不同（需要适配系统）；想要手写文件锁，则十分麻烦（甚至很难做到完美）。

接下来以Windows系统为例，创建一个“同时只能运行一个实例”的程序。**若第二次打开这个程序，则向正在运行的程序发送消息并退出**。

## How

### 推荐的方法：系统自带的锁功能

Windows中程序锁函数为```CreateMutex```函数。例如：

```c
HANDLE mutexHandle = CreateMutex(NULL, TRUE, MUTEX_NAME);
```

所有程序中，系统只允许同时存在一个名为```MUTEX_NAME```的锁。程序借此可判断自己是否为第一个实例，若是（得到了锁）则继续运行，否则找到正在运行的程序并向起发送消息。

```c
#include <windows.h>
#include <stdio.h>

#define MUTEX_NAME "Local\\MySingleInstanceMutex"
#define WINDOW_CLASS_NAME "MySingleInstanceAppWindowClass"
#define WINDOW_TITLE "MySingleInstanceApp"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_COPYDATA: {
        PCOPYDATASTRUCT pCDS = (PCOPYDATASTRUCT)lParam;
        if (pCDS->cbData > 0) {
            char* messageText = (char*)pCDS->lpData;
            MessageBox(hWnd, messageText, "Message Received", MB_OK);
        }
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    HANDLE mutexHandle = CreateMutex(NULL, TRUE, MUTEX_NAME);
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        // 实例已运行，找到窗口并发送消息
        HWND hWnd = FindWindow(WINDOW_CLASS_NAME, WINDOW_TITLE);
        if (hWnd) {
            COPYDATASTRUCT cds;
            cds.dwData = 1; // 可以使用不同的值来表示不同类型的消息
            cds.cbData = strlen(lpCmdLine) + 1;
            cds.lpData = lpCmdLine;
            SendMessage(hWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&cds);
        }
        return 0; // 退出程序
    }

    // 注册窗口类
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = WINDOW_CLASS_NAME;

    if (!RegisterClass(&wc)) return 0;

    // 创建窗口
    HWND hWnd = CreateWindow(WINDOW_CLASS_NAME, WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    if (!hWnd) return 0;

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ReleaseMutex(mutexHandle);
    CloseHandle(mutexHandle);
    return (int) msg.wParam;
}
```

编译：

```bash
gcc tryLock.c -o tryLock
```

运行：双击或使用命令行（可传参）

```bash
./tryLock.exe -t stop
```

首次运行可以看到一个简单的窗口：

![首次运行](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/78a2d16548894d419d77e855ce90e207.png)

再次运行时，可以看到第二个程序并没有启动，反而是第一个程序接受到了第二个程序传来的参数（消息）并弹出了弹窗：

![接收到了消息](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/fe4333f8a1414a78b045142af443c3ba.png)

这样，同时只运行一个实例的功能就实现了。结合上URL Scheme（详情可见[这篇博客](https://blog.letmefly.xyz/2024/02/08/Other-Windows-URLScheme-Define1URLSchemeForYourApplicationWithoutUACOnWindows/)），便可以实现通过浏览器控制本地的程序了。

<small>向下载下来玩玩也可以<a href="https://www.alipan.com/s/UrvvSK4dMYb">点击这里</a>下载。</small>

### 通过文件（锁）实现 —— 完美的程序中不推荐

这种方法的思路是：程序启动时创建一个文件，程序结束时删除这个文件。若程序启动时发现这个文件已经存在，则认为有实例正在运行，自己退出。

若是使用系统提供的文件锁，和方法一中直接使用互斥锁没有过多区别，不如直接使用系统提供的互斥锁；

若是手动创建文件，则很难实现原子操作。（一个程序以写文件的方式打开一个文件，这个文件没有正在进行写操作时，另一个文件也是可以写的）。并且意外产生的程序退出可能导致文件没被删除（用户强制关闭、系统断电关机等）。

为了**防止程序意外退出造成的文件未被删除**，可以：

> 程序启动时写文件并在文件中写入自己的pid，第二个程序读到这个文件时监测这个pid是否还在运行，若没在运行则认为是意外退出并写入自己的pid，否则向这个正在运行的实例传参。

但是```判断锁文件是否存在```、```打开写文件的句柄```和```实际写入内容```不是原子的，快速启动两个程序可能会导致：

> 两个程序判断锁文件是否存在时，还未存在；
>
> 两个程序依次写入内容；
>
> 两个程序同时运行。

## End

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2024/02/17/Other-Windows-ProgramMutex-onlyRun1instanceMeanwhile/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136139822](https://letmefly.blog.csdn.net/article/details/136139822)

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>
