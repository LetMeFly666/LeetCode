---
title: Python爬虫下载雨课堂视频资源 到本地后自主可控地倍速观看
date: 2023-07-01 18:06:40
tags: [其他, Python, 中等, 爬虫, 雨课堂, RainClassroom]
categories: [技术思考]
---

[我](https://letmefly.xyz)写了一个项目，在此分享一下。

+ 项目介绍：下载雨课堂的视频到本地以便任意倍速观看
+ 项目地址：[Github@LetMeFly666/RainClassroomVideoDownload](https://github.com/LetMeFly666/RainClassroomVideoDownload)

## 起因

+ 雨课堂视频首次播放无法拖动
+ 点击网页外的其他位置视频会自动暂停
+ 最多支持2倍速

总之就是很不爽。

本项目的目的不是逃避视频观看（下载到本地观看是不会计入成绩的），而是在本地以任意节奏地观看 更有助于自己的学习。

## 使用方法

**首先更改main.py中的配置**

打开main.py，修改其中的Config字典

```python
Config = {
    'Cookie': 'sessionid=498e8384w849q948q121x884ffe78ett',
    'CourseId': '16809342',  # cid https://grsbupt.yuketang.cn/pro/lms/84eubUaed9T/16809342/studycontent
    'Sign': '84eubUaed9T',  # https://grsbupt.yuketang.cn/pro/lms/84eubUaed9T/16809342/studycontent
    'Domain': 'grsbupt.yuketang.cn',  # https://grsbupt.yuketang.cn/pro/lms/84eubUaed9T/16809342/studycontent
    'uv_id': '3090',  # 意义暂不明确
    'SaveDirName': 'LetYuOutput',  # 视频要保存到的文件夹，存在则直接保存，不存在则创建
}
```

其中的```Cookie```需要自己获取，```F12 -> 控制台```输入```document.cookie```并回车即可得到。

```CourseId```、```Sign```、```Domain```都可用从当前课程的url中获取。

![coursePage.jpg](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/6b8faea060684253b35a5cfd4f0231c6.png)

```uv_id```和```SaveDirName```一般情况下无需更改。

确保自己的Python环境中安装好了requests包，

**之后使用命令 python main.py即可开始下载**

所有视频及字幕（如果有）将会被保存到工作目录的Config.SaveDirName文件夹下。

![keepResult.jpg](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/966531a5efeb450685b58e1c4a63bf53.png)

之后就可用任意倍速、快进等学习自己感兴趣的部分了。

## 播放器推荐

视频播放器有很多，这里推荐一个自动识别字幕且支持倍速的视频播放器：[PotPlayer](https://potplayer.daum.net/)

## TODO

+ [ ] 多线程的支持
+ [ ] 保存方式的支持（例如以原本的章节目录结构进行保存）
+ [ ] 会不会有除了courseChapter.sectionLeafList.leafList的第4层
+ [ ] 多字幕处理（当前有多个字幕的话，只会保存第一个字幕）

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/01/Other-Python-Spider-YuketangRainClassroomVideoDownload/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131493348](https://letmefly.blog.csdn.net/article/details/131493348)
