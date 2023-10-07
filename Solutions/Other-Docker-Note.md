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
|[docker pull](#docker-pull)|拉取镜像|[docker pull](https://docs.docker.com/engine/reference/commandline/pull/)|
|[docker push](#docker-push)|推送镜像到DockerRegistry|[docker push](https://docs.docker.com/engine/reference/commandline/push/)|
|[docker images](#docker-images)|查看本地镜像|[docker images](https://docs.docker.com/engine/reference/commandline/images/)|
|[docker rmi](#docker-rmi)|删除本地镜像|[docker rmi](https://docs.docker.com/engine/reference/commandline/rmi/)|
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

可以在几乎任何时候使用```--help```来查看帮助。例如```docker --help```、```docker pull --help```

### docker pull

拉取镜像。

```bash
docker pull [OPTIONS] NAME[:TAG|@DIGEST]
```

OPTIONS说明：

+ -a :拉取所有 tagged 镜像
+ --disable-content-trust :忽略镜像的校验,默认开启

实例（以nginx为例）：

```bash
docker pull nginx
```

这样的话docker会默认拉取最新(latest)的nginx镜像到本地。

其实不拉取镜像也可以，在```docker run```时若还未拉取过镜像，则docker会自动拉取。

### docker push

将本地的镜像上传到镜像仓库,要先登陆到镜像仓库。

```bash
docker push [OPTIONS] NAME[:TAG]
```

OPTIONS说明：

+ --disable-content-trust :忽略镜像的校验,默认开启

实例：

```bash
docker push mynginx
```

### docker images

列出本地镜像。执行过```docker pull```或```docker run```后镜像可能会被保存。

```bash
docker images [OPTIONS] [REPOSITORY[:TAG]]
```

OPTIONS说明：

+ -a :列出本地所有的镜像（含中间映像层，默认情况下，过滤掉中间映像层）

实例：

```bash
docker images
```

```bash
docker images ubuntu
```

将会得到本地所有版本的ubuntu镜像。

### docker rmi

删除本地一个或多个镜像。

```bash
docker rmi [OPTIONS] IMAGE [IMAGE...]
```

OPTIONS说明：

+ -f :强制删除

实例：

```bash
docker rmi -f nginx
```

有容器正在使用nginx镜像，但还是会被强制删除。

## 其他设置

编辑```deamon.json```或者直接在Docker Desktop的settings中修改配置文件即可更改docker的一些设置。

### 镜像加速

阿里云为个人提供了免费的Docker镜像加速服务。位置：[控制台 -> 容器镜像服务 -> 镜像加速器](https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors)。

复制```加速器地址```（xxx.mirror.aliyuncs.com）并在```deamon.json```中新增一项即可：

```json
"registry-mirrors": ["xxx.mirror.aliyuncs.com"]
```

阿里云明确说明只给个人使用，因此不要分享这个私有地址。

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

## 参考链接

+ [Bilibili@BV1HP4118797: 黑马程序员Docker快速入门到项目部署](https://www.bilibili.com/video/BV1HP4118797)
+ [飞书文档：day02-Docker（和上述视频配套）](https://b11et3un53m.feishu.cn/wiki/MWQIw4Zvhil0I5ktPHwcoqZdnec)
+ [菜鸟教程：docker 命令大全](https://www.runoob.com/docker/docker-command-manual.html)

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/10/07/Other-Docker-Note/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133633479](https://letmefly.blog.csdn.net/article/details/133633479)