---
title: 有了域名想绑定域名邮箱？拥有域名后，如何免费绑定邮箱呢？如何使用【昵称@你的.域名】收发邮件
date: 2022-09-27 19:30:16
tags: [其他, 域名, 邮箱]
---

# 有了域名想绑定域名邮箱？拥有域名后，如何免费绑定邮箱呢？如何使用【昵称@你的.域名】收发邮件

**前提**： 如文章标题，此篇文章的前提是“已经拥有了自己的域名”

有了自己的域名后，采用本篇文章的方式，就可以**免费**地将自己的域名绑定至邮箱。

**说人话**就是：假如你拥有域名“[letmefly.xyz](https://letmefly.xyz)”，那么根据这篇文章，你可以实现“使用[admin@letmefly.xyz](mailto:admin@letmefly.xyz)”收发邮件。

## 申请免费邮箱

本篇教程使用的是阿里云企业邮箱的免费版：[https://www.iplaysoft.com/go/alimailfree](https://www.iplaysoft.com/go/alimailfree?userCode=s6usmdta)

因此，如果你的域名正好是[阿里云购买的域名](https://wanwang.aliyun.com/?userCode=s6usmdta)，那么实现起来就会更容易一些（其他域名也能实现）

点击进入[https://www.iplaysoft.com/go/alimailfree](https://www.iplaysoft.com/go/alimailfree?userCode=s6usmdta)，可以发现产品是免费的。

![购买免费产品](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/572de567d2c0497eae93f638c52eefe7.png)

输入已有域名，点击“立即购买”

之后进入控制台：[alimail.console.aliyun.com](https://alimail.console.aliyun.com/?userCode=s6usmdta)，可以看到邮箱列表中，有自己的域名。

![邮箱域名列表](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/2a9552d8f7e54d7b863031e748f09c85.png)

如果域名不是购买自[阿里云](https://wanwang.aliyun.com/?userCode=s6usmdta)，那么需要前往所购买域名的管理平台，设置以下三个值：

|主机记录值|解析类型|优先级|解析记录值|
|:--:|:--:|:--:|:--:|
|@|MX|5|mxn.mxhichina.com|
|@|MX|10|mxw.mxhichina.com|
|@|TXT|-|v=spf1 include:spf.mxhichina.com -all|

如果域名是购买自[阿里云](https://wanwang.aliyun.com/?userCode=s6usmdta)的，那么可以一键快捷设置。

之后等待域名解析生效：

![检查是否已生效](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/5fcd958f97b84b02bb0880bd77efe4a4.png)

生效后需要重置管理账号密码（默认管理账号为：postmaster@你的.域名）

![重置管理账号密码](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/5e238ce294b54002b371f5b81ea9ba8f.png)

然后就可以通过[https://qiye.aliyun.com](https://qiye.aliyun.com)登陆后台管理自己的企业邮箱了。

![登录管理后台](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/4632b98d2c7244a08a48f4abe25b66e5.png)

你可以在这里新建邮箱账号（比如[admin@letmefly.xyz](mailto:admin@letmefly.xyz)）

![创建邮箱地址](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/8dfadb3158e84e89b7f612c26861b500.png)

你可以直接使用刚刚创建好的邮箱地址再次登录，并收发邮件。（需要先退出登录管理号）

![退出管理号](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/7fd7e9d40e5b4d018d1d68dc2046253e.png)

登录地址仍然为[https://qiye.aliyun.com](https://qiye.aliyun.com)

![登录刚刚创建好的邮箱账号](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/803971d1e2214a80b4b5d2fed0d9ef31.png)

然后就可以愉快地收发邮件啦

![可以愉快地收发邮件啦](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/f65256d4d8a0458bb4f373a2beb90358.png)

你也可以设置自动转发等，以转发到自己的常用邮箱

![自动转发](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/3aa96392c429430c8b5a66d685ece237.png)

心动不如行动，赶快收藏一波然后去试试吧！

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/27/Other-BandDomain2mail/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127077055](https://letmefly.blog.csdn.net/article/details/127077055)
