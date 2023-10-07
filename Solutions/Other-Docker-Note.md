---
title: Docker学习笔记 - 极简极入门级
date: 2023-10-07 10:05:23
tags: [Docker, 简单, Notes]
---

# Docker学习笔记 - 极简极入门级

## 前言

Docker主打一个“极小成本”的虚拟环境的一键部署，使用少量的系统资源占用实现项目在不同宿主机上的无缝迁移。

## 架构

下面两图来自[Bilibili@BV1HP4118797](https://www.bilibili.com/video/BV1HP4118797)

![Docker架构](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/60089d8e00474d35bc1ff9a901d800dc.png)

![Docker命令图](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/d664febdce444dbbae1a0a08d142f023.png)

## 命令

|命令|说明|文档地址|
|:--:|:--:|:--:|
|[docker pull](#Docker-pull)|拉取镜像|[docker pull](https://docs.docker.com/engine/reference/commandline/pull/)|
|docker push|推送镜像到DockerRegistry|docker push|
|docker images|查看本地镜像|docker images|
|docker rmi|删除本地镜像|docker rmi|
|docker run|创建并运行容器（不能重复创建）|docker run|
|docker stop|停止指定容器|docker stop|
|docker start|启动指定容器|docker start|
|docker restart|重新启动容器|docker restart|
|docker rm|删除指定容器|docs.docker.com|
|docker ps|查看容器|docker ps|
|docker logs|查看容器运行日志|docker logs|
|docker exec|进入容器|docker exec|
|docker save|保存镜像到本地压缩文件|docker save|
|docker load|加载本地压缩文件到镜像|docker load|
|docker inspect|查看容器详细信息|docker inspect|

### Docker pull



## 个人的话

文章到这里可以说是已经结束了。以下是我个人在使用过程中的一些想说的话：

docker环境的底层似乎是Linux系统，因此感觉在Windows上的适配/体验并不算特别好。

在Windows上运行Docker时官方推荐的方法是使用WSL(Windows Subsystem for Linux)，结果就是Docker在安装过程中完全不给选择安装路径，并且默认开机自启xxx。

还有就是docker-windows的内存回收做得不够到位。我的主机是32G内存的，日常使用一般占用20%~30%，但开个Docker再运行个nginx的容器能飙到70%多。

后台运行Docker-Desktop时进程```Vmmem```大约会占据1-2G内存，再运行一个nginx能占据4~6G。总觉得虚拟机的内存占用是不会完全显示在任务管理器中的，常常在运行虚拟机时任务管理器中所有进程的内存占用加起来 要比 真正的内存总占用小（未细算）。

退出Docker-Desktop后```Vmmem```占据的内存并不会被主动释放，使用命令```wsl --shutdown```后可以看到任务管理器中```Vmmem```消失了，但是总的内存占用并没有明显下降。（也就是说日常二十多的内存占用，开启Docker并运行一个容器后，只要不关机，我就没找到让内存占用低于70%的方法）

退出docker并且关闭了wsl后，再次运行Docker，似乎并未使用之前分配的内存，会多出一个1G多的```Vmmem```进程，总内存占用就飙到85%~90%了，其他应用使用起来能感到较为明显的小卡。这可是32G内存的主机欸。```任务管理器 -> 用户```看到```xxx@hotmail.com```的内存总占用是1.7G，而```任务管理器 -> 用户```看到的实际占用是27.4G。

![用户内存占用](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/c0c5ea88673e49c597b81915c3d00bd6.png)

![总占用](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/92f2409eb64e49b686d003c8959304e1.png)

所以，求一个有效的Windows上使用Docker后释放内存的好办法（重启除外）[Doge]

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/10/07/Other-Docker-Note/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133633479](https://letmefly.blog.csdn.net/article/details/133633479)