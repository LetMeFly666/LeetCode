---
title: 密码管理 - 使用Bitwarden/Vaultwarden自托管密码服务 - 折腾记录
date: 2025-02-15 12:42:16
tags: [其他, 密码, 服务器]
categories: [技术思考]
---

# 密码管理 - 使用Bitwarden/Vaultwarden自托管密码服务 - 折腾记录

## 前言

某天(大约两周前了至少 一直没找到机会记录)逛Github发现了开源的密码管理服务[Bitwarden](http://github.com/bitwarden)，能自托管、能加密、多端适配。

这，，不是让人如获至宝吗。于是就开始折腾了。

## 折腾Bitwarden

### 镜像无法拉取

在服务器上按照[bitwarden/server](https://github.com/bitwarden/server)提示进行操作，拉取脚本并执行，然后无法拉取指定镜像。

解决办法有3：

1. 在服务器上配置特殊网络环境
2. 寻找可用镜像
3. 本地魔法拉取并上传镜像到服务器，并修改脚本源码

于是我修改了脚本源码，分析环境变量并提前下载好指定的镜像版本，并注释掉了`docker pull`命令。

这个脚本还会下载其他脚本，我还修改了脚本为不下载其他脚本而是直接执行本地下载好的脚本文件。

每次尝试都需要重新输入所有内容。

### 无法认证

使用bitwarden的自托管服务也需要在bitwarden[官网](https://bitwarden.com/host/)提交邮箱并获得ID和KEY，只有服务器上认证通过了这个ID和KEY，才能继续执行，否则会直接报错。

不知为何，无论如何尝试都始终无法验证成功。因此docker会启动失败。

再次运行安装脚本时，脚本检测本地文件认为已经安装成功，就会拒绝安装。想要`uninstall`又提示卸载失败。

每次尝试都需要手动删除执行到一般的缓存文件、新建文件夹并上传“魔改版”子脚本、重新输入所有内容。

### 资源占用

官方要求内存至少2G，有[博客](https://blog.hentioe.dev/posts/deploy-bitwarden-server.html#:~:text=%E6%B2%A1%E6%9C%89%E4%BB%BB%E4%BD%95%E8%AE%BF%E9%97%AE%E5%AE%83%E7%9A%84%E5%8D%A0%E7%94%A8%E5%B0%B1%E8%BE%BE%E5%88%B0%201GB%20%E4%BB%A5%E4%B8%8A)说部署成功后未进行任何操作内存占用就达到1G以上。对于我那小学生机，还是放弃了吧。

### 改进建议

1. 输入内容保存到本地，下次运行时可以直接询问是否修改（或者像cuda安装时那样可以手动选择并修改一些配置），要不然每次重新尝试需要输入的内容有点多（域名、数据库配置信息等）。也许是因为在良好的互联网环境下几乎可以一次完成，所以不会存在这个问题吧。
2. “安装过”检测。启动失败了不代表安装成功，下次执行安装命令不应该拒绝安装。
3. 有无“ID和KEY验证失败”的原因说明。
4. 能占据资源小一些的话就更好了。

## 折腾Vaultwarden

好在有大佬用rust重写了bitwarden的[服务端](https://github.com/dani-garcia/vaultwarden)，可以完美兼容所有bitwarden客户端所需服务端api。资源占用小且易部署。

似乎之前这个项目叫bitwarden_rs，后面为了防止商标侵权之类的改名为了vaultwarden。我使用的部署方式是docker-compose。

### 客户端表示不支持

一切“顺利”，诶，不是说vaultwarden完美覆盖了所有bitwarden服务端的api吗，为啥我这bitwarden的客户端（浏览器插件）就不认我这服务器呢？

登录时候选择自托管服务器，总是说登录失败。在服务器上看log是访问了一个不存在的url。

我甚至想过魔改docker镜像，修改一下服务的路径。结果发现除了我没有人遇到过这个问题。

后面我突然发现，执行`docker images`的时候，`vaultwarden/server:latest`的`CREATED`是`3 years ago`！

好家伙，原来是因为使用的阿里云“阿里服务器专属docker镜像服务”，这个服务似乎很久不更新了。

在搜镜像源的时候，发现很多镜像提供者陆陆续续关闭了，包括很多互联网大厂和顶尖高校，这些大厂/高校还在正常提供其他镜像服务，但是说“由于ZhengCe原因关停”。

也许在不久的将来，其他镜像服务也会陆续下架[？](https://linux.do/t/topic/106872/40)吾不敢言。

最后找了个镜像源并指定tag为`1.31.0`成功了。这里对镜像提供者表示感谢。

### 证书链不受信任

网页版、浏览器插件、安卓APP使用都十分顺利，完美！准备试一段时间然看看是否要完全替代Chrome的密码管理了，毕竟连Edge都能~~不经你询问~~直接导入所有Chrome密码。

突然，手机APP同步时提示“同步失败”，重新登录时提示“证书链不受信任”。诶，手机上访问网页版也正常啊，是安卓APK证书链信任机制的锅吗？还是之前抓包导入自定义证书导致的？不应该啊。

之后的几天里，这种现象时不时出现，有时发生，有时又一切正常。有时流量会这样，有时连上wifi也不行。我甚至怀疑过是不是因为Cloudflare CDN导致每次访问到的节点不一样，我也甚至想过导入一些证书到手机上（但安卓从7.0开始就不信任用户自己导入的证书了）。

直到有一天，What The Fantastic，我访问我自己的网站访问不了了。。。我的服务器上搭建了很多服务，为了保护主机ip，全部使用了互联网界清流CF的CDN。那天，任何子域名，一概无法正常访问。那段时间，正常访问Github没有一秒可以成功过[。](https://github.com/LetMeFly666/LeetCode/blob/1df877f2de19c6c7b25f85407587c7d370e6e798/Solutions/LeetCode%200680.%E9%AA%8C%E8%AF%81%E5%9B%9E%E6%96%87%E4%B8%B2II.md?plain=1#L183-L189)

我甚至怀疑过是不是北邮V-P.N的BUG，也怀疑过xxx，还在Termux上进行了一堆的debug。可能是笔者计网知识薄弱导致的错误推断，结论是并非安卓机配置问题，而是遭到了神秘力量的强有力封锁。

不过过了那十来天后现象有所缓和，又不想关掉CDN暴露主机真实IP，就先这样吧。。。大多时候一切正常，偶尔网络链路会受到一些魔改。

### 更新

Linux上暂未配置docker直连网络，若通过MacOS或Windows拉取镜像：

```bash
# on macos
# export NO_PROXY=registry-1.docker.io,docker.io
docker pull --platform=linux/amd64 vaultwarden/server:alpine
# docker pull vaultwarden/server@sha256:f8b5ccb9cb7f1a156321c398e64f49e4fea681e2172281415e4fd5e23b6b89f1
docker save vaultwarden/server:alpine -o ~/Downloads/vaultwarden-alpine.tar
# docker save vaultwarden/server@sha256:f8b5ccb9cb7f1a156321c398e64f49e4fea681e2172281415e4fd5e23b6b89f1 -o ~/Downloads/vaultwarden-alpine.tar
rsync -avz ~/Downloads/vaultwarden-alpine.tar Let:~/
rm -r ~/Downloads/vaultwarden-alpine.tar
docker rmi vaultwarden/server:alpine
# docker rmi vaultwarden/server@sha256:f8b5ccb9cb7f1a156321c398e64f49e4fea681e2172281415e4fd5e23b6b89f1

# on linux
docker load -i vaultwarden-alpine.tar
# docker tag b4016fd0738a vaultwarden/server:1.35.3-alpine
rm -f vaultwarden-alpine.tar
cd ~/django/vaultwarden
docker compose down
sed -i 's|image: vaultwarden/server:1.33.2-alpine|image: vaultwarden/server1.35.3:-alpine|' docker-compose.yml
# sed -i 's|image: vaultwarden/server:1.35.3-alpine|image: vaultwarden/server:1.33.2-alpine|' docker-compose.yml
docker compose up -d
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145649203)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/15/Other-Password-SelfHostPasswordToolUsingBitwardenVaultwarden)哦~
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/15/Other-Password-SelfHostPasswordToolUsingBitwardenVaultwarden](https://blog.letmefly.xyz/2025/02/15/Other-Password-SelfHostPasswordToolUsingBitwardenVaultwarden)
