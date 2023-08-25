---
title: Cloudflare Warp+，1.1.1.1，如何使用，如何获取免费流量，如何优选IP
date: 2023-08-25 21:17:27
tags: [其他, VPN]
LetMeFly_SelfUse: true
---

# Cloudflare Warp+，1.1.1.1，如何使用，如何获取免费流量，如何优选IP

## 前言

本篇纯自用，用作防止忘记的备份。他人请勿看。

说实话，**这只是个隐匿真实IP从而保护用户隐私是软件**。

**这只是个隐匿真实IP从而保护用户隐私是软件**。

**这只是个隐匿真实IP从而保护用户隐私是软件**。

## 下载

下载地址为最牛ip：[1.1.1.1](https://1.1.1.1/)，目前还能正常访问。支持多种系统，选择对应的进行安装即可。

## 使用

安装完成后首页有个未打开的开关。首次连接比较看脸，首次打开开关之前最好确保有科學のNet，安卓可以尝试电脑热点辅助（因为不能同时有两个```🔑```图标）。实在不行重装一两次也许就可以了。

之后每次使用只需要“连接”就可以了。

## 升级到Warp+

默认的warp可无限流量免费使用，若想<del>使用</del>（白嫖）warp+，可以使用以下三种方法：

### 方法一：分享（脚本）

每分享给一个用户注册，可以获得1G的Warp+流量。

当然有大佬写好了[脚本](https://huggingface.co/spaces/Aristore/Warp/tree/main)，我也下载到了本地修改成了无UI版本。（不要直接二次分享，里面包含了ID、密钥等）

但是使用次数多后，会显示“402 Bad request: too frequent”，等上一天也可能仍是这样。

### 方法二：使用Cloudflare Zero Trust

登录Cloudflare，选择Zero Trust，选择“0美元”套餐，绑卡界面退出，重进Zero Trust，选择首次添加设备，设置邮箱域名如@qq.com（若出现BUG可以先选择ZeroTrust下的其他子目录，再选择第一个子目录就可以了）。

在CF Warp中登录Zero Trust。

注意，退出Zero Trust后Warp+的流量似乎会清零。

### 方法三：电报机器人

Telegram中搜索[@generatewarpplusbot](https://t.me/generatewarpplusbot)，按照提示订阅两个“服务号”并回答一个加减乘除运算题即可获得24.9P的私钥，在CF Warp中更新私钥即可。

## 优选IP

优选IP与否似乎关系不大。并且好像要安装WireGuard才能做到IP优选。

使用**我已经下载好**的脚本（在Warp备份文件夹中），运行手动优选的bat，在result.csv中选择一个靠前的，运行手动设置bat，输入ip即可。

```
emm，都说了本文自用。
```

# End

<script>alert('一个保护互联网隐私的软件<br />本文仅自用');</script>

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/08/25/Other-VPN-CloudflareWarp+1.1.1.1)哦~
> [https://blog.tisfy.eu.org/2023/08/25/Other-VPN-CloudflareWarp+1.1.1.1](https://blog.tisfy.eu.org/2023/08/25/Other-VPN-CloudflareWarp+1.1.1.1)
