---
title: Linux - SSH - SSH免密登录（假设已生成过rsa key pair）
date: 2023-04-22 11:03:11
tags: [其他, Linux, SSH, SSH免密登录]
---

# Linux - SSH - SSH免密登录（假设已生成过rsa key pair）

## 前言

如果使用过Github的git clone、push等功能，应该已经配置过```ssh-keygen```命令生成了密钥对。

本篇文章就在```能通过密码SSH登录远程服务器``` 且 ```已有上述密钥对```的前提下，尽可能简单地描述如何**SSH免密登录到Linux服务器**

## How

我想使用自己的电脑（电脑A）免密登录到Linux服务器（电脑B）。在进行以下配置之前，想要SSH登录服务器B，必须要输入密码。

```bash
ssh user@B.ip
```

接下来会提示```user@B.ip's passwords:```，输入密码后才能正常登录。

怎么做到使用电脑A登录电脑B时，不需要输入密码就能直接登录呢？

首先找到自己电脑上的SSH密钥和公钥。（Windows电脑一般在```%userprofile%/.ssh```目录下有```id_rsa```和```id_rsa.pub```两个文件），其中带```.pub```的是公钥，是可以传送到电脑B上的。

接下来，我们只需要将电脑A```id_rsa.pub```中的内容，添加到服务器B的```/home/user/.ssh/authorized_keys```中。其中```user```是你的用户名。或者添加到```~/.ssh/authorized_keys```中是一模一样的。

如果不存在这个文件，创建这个文件即可；如果这个文件已经存在（不管其中是否已有内容），将A电脑的```.pub```中的内容添加到这个文件的末尾即可（注意单独占据一行）

这样，我们直接使用A电脑，去SSH登录B电脑，就可以发现不用输入密码啦！

> 原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/04/22/Other-Linux-SSHLoginWithoutPassword/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130302379](https://letmefly.blog.csdn.net/article/details/130302379)