---
title: 建站 - 如何访问Cloudflare的workers.dev
date: 2023-04-29 14:40:30
tags: [其他, Website, 建站, Cloudflare, Workers, DNS, DNS污染]
---

# 建站 - 如何访问Cloudflare的workers.dev

## 前言

Cloudflare提供了workers服务，类似于“云函数”，提供每日10万次的免费调用次数以及一共1G的免费存储空间。

但是调用workers服务的地址是xx.xx.workers.dev，这个地址在国内访问不到！因为workers.dev这个域名在国内已经被DNS污染了。

可能是由于很多人滥用workers.dev，但是这有点滥杀了诶！良民的服务也一概屏蔽掉了。

## How

既然是*.workers.dev被DNS污染了，那么我们只需要使用一个没有被DNS污染的域名代替这个域名就可以了。

首先将一个域名托管到cloudflare上，例如：letmefly.eu.org

接着点进去这个域名，添加一条DNS记录

```
url.letmefly.eu.org    A    8.8.8.8
```

将```url.letmefly.eu.org```设置为了指向```8.8.8.8```的```A```记录，并**打开代理**（就是那个小云朵）

虽说指向的是谷歌的DNS服务器，但其实基本上指向哪个ip都可以（暂未验证），因为打开了代理，所以实际上```url.letmefly.eu.org```并没有指向```8.8.8.8```，而是指向了距离你较近的Cloudflare服务器（我的结论）。

当你访问```url.letmefly.eu.org```时，实际上是访问了Cloudflare服务器，Cloudflare服务器再访问你配置的地址（8.8.8.8），并将结果返回给你。这样做好处一个是保护了服务器的真实ip（别人不知道你的真实服务器地址是8.8.8.8），另一个是Cloudflare会提供缓存服务（Github部署的网站经常访问速度很慢，这就可以使用Cloudflare代理访问）

之后，再**在letmefly.eu.org这个域名下**，点击“Workers路由”，在“HTTP 路由”中点击“添加路由”

在弹出的输入框中，“路由”填写```url.letmefly.eu.org/*```（记得一定带上```/*```，代表匹配所有的以```url.letmefly.eu.org/```开头的url），“服务”选中你的Workers服务，“环境”选择唯一可选的“production”，点击“保存”即可。

这样，当访问```url.letmefly.eu.org```时，就会访问Cloudflare服务器，服务器看到```url.letmefly.eu.org```和配置的Workers路由规则匹配，就转发给Workers服务了。

```url.letmefly.eu.org```没有被污染（良民的域名，别乱用），它所指向的Cloudflare服务在中国也有很大的市场（也不会被无缘无故地一下墙掉），因此就能访问原本访问不到的```xx.xx.workers.dev```了

> 原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/04/29/Other-Website-HowToAccessWordersDotDev/)哦~
> Tisfy：[https://leetcode.letmefly.xyz/2023/04/29/Other-Website-HowToAccessWordersDotDev/](https://leetcode.letmefly.xyz/2023/04/29/Other-Website-HowToAccessWordersDotDev/)
