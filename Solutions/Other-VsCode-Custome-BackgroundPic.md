---
title: VsCode美化 - VsCode自定义 - VsCode自定义背景图：添加二次元老婆图到VsCode
date: 2023-08-10 18:28:12
tags: [VsCode, 简单, 美化, 二次元]
---

# VsCode美化 - VsCode自定义 - VsCode自定义背景图：添加二次元老婆图到VsCode

## 前言

作为一个二刺螈，VsCode用久了，总觉得少了些什么。是啊，高效的代码生产工具中怎么能没有老婆呢？

那就安装一个VsCode插件把老婆添加到VsCode中吧！

## How

### 安装

#### 方法一

直接在VsCode的插件中搜索```background```（或者```Ctrl + P -> ext install background -> Enter```），点击第一个安装即可。

![background-extention](https://img-blog.csdnimg.cn/1dbd2a8087a949f2b135c22e15066cfa.png#pic_center)

#### 方法二

打开[该插件的marketplace](https://marketplace.visualstudio.com/items?itemName=shalldie.background)，点击Install即可。

![install2](https://img-blog.csdnimg.cn/fff098861c734df49afd6e8908c6e04d.png)

### 配置

安装完毕后，重启VsCode就可以看到右下角的二次元图了。

**什么，不喜欢？想换图？**

打开左下角设置：

![settings](https://img-blog.csdnimg.cn/3d44e736f65f4c7e9623cfa55636a6b0.png)

搜索```background```，点击```拓展```，点击```background```，就可以开始配置了。

可以直接修改```settings.json```来配置（其实该settings.json的路径为```%userprofile%/AppData/Roaming/Code/User/settings.json```）：

![settings.json1](https://img-blog.csdnimg.cn/e2e20f7245204f2ab7018237965609ac.jpeg)

在最外层大括号内添加如下代码即可将图片添加至右下角：

![settings-code](https://img-blog.csdnimg.cn/f3cea492936e4a27886808ac1aa5526f.jpeg)

```json
"background.enabled": true,
"background.customImages": [
    "file:///F:/Pic/八重神子-背-小.png"
],
"background.style": {
    "content": "''",
    "pointer-events": "none",
    "position": "absolute",
    "z-index": "99999",
    "width": "100%",
    "height": "100%",
    "background-position": "100% 100%",
    "background-repeat": "no-repeat",
    "opacity": 0.2
}
```

其中```background.customImages```是图片，```background.style```是图片样式。图片样式中的```opacity```是图片透明度。

如果使用多个图片，且每个图片使用不同的配置，则可以：

```json
"background.enabled": true,
"background.customImages": [
    "图片1",
    "图片2"
],
"background.styles": [
    {配置1},
    {配置2}
]
```

注意，上述配置中是```styles```而不是```style```，其中```配置1```，```配置2```与第一个json配置中```background.style```相同。

## Test

### 效果

![效果](https://img-blog.csdnimg.cn/a212fdbfd4d14b3db08c5e5a03b71233.jpeg)

### 文件分享

我所使用的图：[AliyunDrive](https://www.aliyundrive.com/s/UiJ2yE81Jre)

啊咧，现在阿里云盘“备份盘”中的文件不能分享了，只有“资源库”中的文件才能分享。What?!（2023.8.10）

### 更新

VsCode更新后第一次启动，老婆会不显示。但是不用怕，什么都不需要做，重启一下VsCode就可以了。（```Ctrl + Shift + P -> Reload Window -> Enter```）

### 不爽

不爽之处：每次启动后，VsCode右下角总会提示“Code 安装似乎损坏，请重新安装”。

![不爽](https://img-blog.csdnimg.cn/b8a359be45f2441d822c770ef18b9acb.jpeg)

不过想要屏蔽的话也很简单，点击小齿轮，点击不再显示就好了。

![屏蔽](https://img-blog.csdnimg.cn/cb6bf44ff5134199ad382d217a497d59.jpeg)

## End

中文文档：[github.com/shalldie/vscode-background/blob/HEAD/README.zh-CN.md](https://github.com/shalldie/vscode-background/blob/HEAD/README.zh-CN.md)

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/08/10/Other-VsCode-Custome-BackgroundPic/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132215972](https://letmefly.blog.csdn.net/article/details/132215972)

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>
