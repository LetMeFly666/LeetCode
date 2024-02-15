---
title: Python - Jupyter - 远程连接Jupyter内核
date: 2023-04-22 12:55:06
tags: [其他, Python, Jupyter, Linux, 远程连接, 端口]
---

# Python - Jupyter - 远程连接Jupyter内核

## 前言

假设你有一台高性能服务器（电脑B），并且在上面安装好了Jupyter

现在你想使用你自己常用的电脑（电脑A）编码，但使用电脑B的计算资源。

怎么办呢？以VsCode为例（首先需要安装[Jupyter插件](https://marketplace.visualstudio.com/items?itemName=ms-toolsai.jupyter)），接着创建```.ipynb```为后缀的Jupyter记事本文件

打开这个文件，如果系统环境变量中配置好了Python等的话，应该可以看到当前正在使用本地的内核

![系统内核](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/f13e405e0e214f30a09f8cc88fad12a8.png)

现在登录电脑B，在终端中进入你想要进入的目录，打开jupyter服务（若未安装jupyter可以使用命令```pip install jupyter```），设置端口、token：

```bash
cd ~/JupyterDir
jupyter notebook --port 8888 --ip 0.0.0.0 --NotebookApp.token=47a90a1933b28b74903c8b436c7f12d3f8aafe35db85f8f1
```

如果Linux服务器的8888端口是开着的话，就可以通过访问Linux服务器的8888端口来访问其jupyter服务了。

先在浏览器中尝试，打开网址：

```
http://linuxB.ip:8888/?token=47a90a1933b28b74903c8b436c7f12d3f8aafe35db85f8f1
```

可以看到Jupyter服务连接成功

![Jupyter服务连接成功](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/2ea41cb2ab1147c9af68014aeba3723d.png)

这时，如果已经配置好了机器A登录机器B时的免密登录（没有配置也没关系，请参考[SSH免密登录](https://blog.letmefly.xyz/2023/04/22/Other-Linux-SSHLoginWithoutPassword/)），那么我们就可以打开机器A的VsCode，使用机器B的Jupyter内核了：

在刚刚新建的demo.ipynb中，点击“内核”

连接新的内核：

![连接新的内核](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/10c6b35e23d84000993df874a2bb07c1.png)

输入刚刚和浏览器中相同的URL并回车：

![输入刚刚和浏览器中相同的URL](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/f84fa43e967a4db4a8c85731be007b22.png)

可以看到内核发生了改变：

![内核发生了改变](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/6c2bc5ed8f604e098e12ea2713582d4d.png)

在记事本中输入一些命令进行尝试：

```bash
!free -g
```

运行结果

```
              total        used        free      shared  buff/cache   available
Mem:             62          12          26           0          23          49
Swap:            18           0          18
```

![free -g](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/77f6f8ee3e314a15b9d0bc0c5006b4fd.png)

```bash
!dir
```

运行结果

```
D2LFiles
```

![D2lFiles](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/ad48e29993574e39bbfbfbe2733585cd.png)

正是我们刚刚在Linux服务器上选择的文件夹。

这样，就实现了，虽然我是在机器A上编写的Jupyter记事本，但其实质上是在机器B上执行的。

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/22/Other-Python-Jupyter-RemoteKoreConnection/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130303588](https://letmefly.blog.csdn.net/article/details/130303588)
