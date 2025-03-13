---
title: 抓包 - 简要总结 - Windows和Android抓包
date: 2023-08-25 22:26:42
tags: [其他, 抓包, Fiddler, Windows, Android]
categories: [技术思考]
---

# 抓包 - 简要总结 - Windows和Android抓包

## 前言

小巧且强大的抓包工具“Fiddler”安装可参考我的另一篇博客：[抓包 - 经典抓包工具Fiddler的安装与初使用](https://blog.letmefly.xyz/2023/02/04/Other-PacketCapture-FiddlerInsrallmentAndFirstUse/)

本文主要介绍如何使用Fiddler抓包Windows和安卓。

## Windows

抓包Windows很简单，安装证书，开启HTTPS即可。但是也存在特殊情况：有些软件不走系统代理。

1. 例如QQ音乐客户端，需要手动设置系统代理为```127.0.0.1:8888```
2. UWP应用是运行在沙盒中的，默认不具有访问本地网络的权限，Fiddler的原理是设置一个本地中介服务器，运行时可能会导致UWP应用无法联网
3. python使用requests时需要进行以下设置
   ```python
   response = requests.get(
        url='https://letmefly.xyz/',
        proxies = {
            'http': 'http://127.0.0.1:8888',
            'https': 'http://127.0.0.1:8888'
        }
   )
   ```

## 未root的Android

抓包安卓需要：

1. 在Fiddler的```Tools -> Options -> Connections```中打开```Allow remote computers to connect```
2. 若电脑弹出防火墙提示，请点击允许Fiddler通过防火墙
3. 将手机和电脑连接至同一wifi下（手机连接电脑的热点也可以）
4. 手机中```长按连接的wifi -> 修改网络 -> 代理 -> 手动```，服务器主机名填写电脑在局域网中的IP地址（可以使用```ipconfig```命令获取），端口填````8888```，```保存```
5. 手机访问```127.0.0.1:8888```下载证书，并点击安装。

正常情况下，电脑就能抓到手机的HTTPS包了。

但是Android7开始，系统不再信任用户安装的证书，而非root用户无法安装系统证书。这就导致一些APP（如QQ音乐/抖音）拒绝进行“不安全连接”，从而导致这些应用无法联网。在安卓手机中安装抓包软件，直接在安卓中抓包也是一样的道理，不root的话似乎只有“魔改路由器”在路由器上抓包了。

不得不吐槽一句，QQ音乐中，音乐相关界面会显示“证书不可信”，但是广告缺正常加载。。。。

## root的安卓

在电脑上配置好```openssl```（如果电脑上有git的话，可以直接拿来用へへ），（```Tools -> Options -> HTTPS -> Actions -> Export Root Cerificate to Desktop```）导出Fiddler证书，使用以下命令：

```bash
openssl x509 -inform DER -in C:\Users\LetMeFly\Desktop\FiddlerRoot.cer -out C:\Users\LetMeFly\Desktop\FiddlerRoot.pem
openssl x509 -inform PEM -subject_hash_old -in C:\Users\LetMeFly\Desktop\FiddlerRoot.pem
```

这时候大概率会计算出```e5c3944b```这个哈希值。

```bash
ren C:\Users\LetMeFly\Desktop\FiddlerRoot.pem e5c3944b.0
```

使用ADB将证书添加到root的手机的```/system/etc/security/cacerts```

```bash
adb devices
adb push C:\Users\LetMe\Desktop\e5c3944b.0 /system/etc/security/cacerts
```

注意，可能需要首更改一下该目录的权限为可写

```bash
adb shell
cd /system/etc/security/
chmod 777 cacerts
```

将```cacerts```由原来的```drwxr-xr-x```修改为```drwxrwxrwx```。

操作失败的小伙伴可以参考[这篇博客](https://blog.csdn.net/qq_43278826/article/details/124291040)（这篇博客好像也不行，真遇到啥报错自己搜一下吧X-X）

只需要```设置 -> 安全性与位置信息 -> 加密与凭据 -> 信任的凭据 -> 系统```中有```DO_NOT_TRUST_BC```并处于开启状态，就可以开心的抓包辣！

## 小结

QQ音乐アイドル的“在听”时长有单日2W多分钟的，刚开始我也想抓包冲个榜，但是失败了。。。技术还不够，只抓到了“单日听歌时长”（音响力）的包。还偶然发现QQ音乐首次绑定手机送三天豪华绿钻。花费了几天基本无果，也没有什么冲榜的兴趣了。[遂](https://hanyu.baidu.com/shici/detail?pid=54d154714ab7420c98ee632aee2c8340#:~:text=%E9%81%82)总结并尘封之。

好像，，本来就只手机端有效。（电脑端似乎只记当日时长，手机端记时长也记音响力）

> 文章原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/25/Other-PacketCapture-briefSummary-WindwosAndAndroid/)哦~
> 同步发文于CSDN：[https://letmefly.blog.csdn.net/article/details/132504020](https://letmefly.blog.csdn.net/article/details/132504020)
