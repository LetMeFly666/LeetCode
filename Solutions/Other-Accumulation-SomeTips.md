---
title: 日积月累 - 一些小知识
date: 2023-02-21 21:33:49
tags: [其他, 小杂, 知识, 中等, Github, HTML, Windows, Phone, Python, Website, 安全]
---

# 日积月累 - 一些小知识

这里准备放一些日积月累的小知识，排版等也可能会在后期不断调整归类。

## About Github

### CHANGELOG.md

更新日志文件，格式可参考：[https://www.bestyii.com/topic/75](https://www.bestyii.com/topic/75)

## About HTML

### 空白字符

这是一个空白字符：“ㅤ”

### WebView2

（实为Edge内核？）编写的程序可以借助webview2实现网页的访问与浏览。相当于是浏览器。若电脑上安装有WebView2，则程序可以直接借助WebView2实现网页的浏览。

见到一个B站UP主打包WebView2的[视频](https://www.bilibili.com/video/BV1Aa411j7XV/)。

## About Windows

### Windows应用商店安装的应用

Windows应用商店安装的应用似乎不一定能找到.exe文件。那么这些应用到底安装到了哪里呢？

```
C:\Program Files\WindowsApps
```

例如[胡桃工具箱](https://hut.ao/)1.4.1.0_x64_Test的安装位置是：```C:\Program Files\WindowsApps\7f0db578-026f-4e0b-a75b-d5d06bb0a74d_1.4.1.0_x64__7jfyf5536hdrr```

### Windows沙盒复制文件时发生错误的原因

有时候在Windows Sandbox中下载了一个4G的学习资料，将其复制到主机时，可能会遇到复制了一半突然

```
复制文件或文件夹时出错
     未指定的错误
        确定
```

然后如果文件复制时不干其他事情，只让系统进行复制操作，基本上每次都能复制完成且不出错（我没遇到过这样还报错的）

某天（应该是2023.2.24），突然就发现了这“未知错误”的原因

如果我们在主机和沙盒间通过复制粘贴的方式传输文件时，在文件传输过程中，我们又复制了其他东西，那么这时候文件传输就会出现上述错误！只要我们不更新剪贴板，随意操作其他东西，我是没见过复制错误发生未知错误的情况。

我想，也许其原理是通过剪贴板的看不见的“文件链路”进行传输的？

### autohotkey

记录一下autohotkey，它是一款是一款免费的、Windows平台下开放源代码的热键脚本语言

官网：[https://www.autohotkey.com/](www.autohotkey.com)

## About Phone

### Phone APP 如视VR

记录一款软件，使用智能手机拍摄就能三维建模。智能手机拍摄将信息传到服务器上，云计算后返回，可在线浏览。免费，但不可下载模型。

其视频讲解可见：[科技宅小明](https://space.bilibili.com/5626102)的视频[科技还是魔法？！2分钟重建我的家！](https://www.bilibili.com/video/BV1mV4y1A7PP)

早点有的话就能多建模两个地方喽~

## About Python

### Python chain

连接两个iterable的东西为一个iterable的东西

```python
from itertools import chain
a = [1, 2, 6]
b = [2, 5, 7]
for i in chain(a, b):
    print(i, end=', ')
```

执行结果：

```
1, 2, 6, 2, 5, 7,
```

### Python bisect

二分查找用。

```bisect.bisect_right(list, val)```类似于C++的```upper_bound(list.begin(), lise.end(), val) - list.begin()```

同理，```bisect_left```类似于```lower_bound```

### Python json.dumps

格式化输出json（实质是将python字典转化为格式化后的字符串）

```python
import json
data = {"name": "你好", "list": [1, 2]}
print("data:", data)
formatted = json.dumps(data, indent=4, ensure_ascii=False)
print("json.dumps:", formatted)
```

运行结果：

```
data: {'name': '你好', 'list': [1, 2]}
json.dumps: {
    "name": "你好",
    "list": [
        1,
        2
    ]
}
```

其中```ensure_ascii```默认为```True```，这时会以ASCII码的形式输出（中文你好就变成了"\u4f60\u597d"）

More：json.dumps是将字典转为字符串，json.loads是将字符串转为字典。假如从爬虫得到的返回值是json格式的字符串，想将其格式化后输出，那么就可以：

```python
import json
responsedData = '{"name": "\\u4f60\\u597d", "list": [1, 2]}'  # 假设responsedData由爬虫获得
print("不好看的原版responsedData:", responsedData)
formatted = json.dumps(json.loads(responsedData), indent=4, ensure_ascii=False)
print("json.dumps(json.loads):", formatted)
```

运行结果：

```
不好看的原版responsedData: {"name": "\u4f60\u597d", "list": [1, 2]}
json.dumps(json.loads): {
    "name": "你好",
    "list": [
        1,
        2
    ]
}
```

### Python sortedcontainers.SortedSet

Python有序集合，类似C++的set

但缺点是需要手动安装，非Python自带

```bash
pip install sortedcontainers
```

```python
from sortedcontainers import SortedSet
se = SortedSet()
# 增删改查未完待续
```

## About Website

### ip扫描工具censys

很多网站为了防止DDos等都使用CDN等将自己的真实ip隐藏起来。但是如果直接访问真实ip的话，还是有可能会返回SSL证书（例如浏览器提示的“证书无效/不匹配”

censys扫描全球所有IP并记录ip于域名直接的关系，并且扫描速度快得惊人```(>_<)```

网址：censys.io

### 域名收集工具/SSL证书查询工具crt.sh

网址：crt.sh，传说所有的SSL证书都能在上面查到（好像是）

并且，输入一个域名，它的所有子域名甚至都能被查到（似乎前提是开了https）。

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/02/21/Other-Accumulation-SomeTips)哦~
> [https://leetcode.letmefly.xyz/2023/02/21/Other-Accumulation-SomeTips](https://leetcode.letmefly.xyz/2023/02/21/Other-Accumulation-SomeTips)