---
title: FFmpeg（强大的音视频处理工具） - 一些基本实用方法
date: 2023-07-03 15:30:06
tags: [其他, 中等, FFmpeg, 音频, 视频]
---

# FFmpeg（强大的音视频处理工具） - 一些基本实用方法

## 下载安装

官网：[ffmpeg.org](https://ffmpeg.org/)

[下载页面](https://ffmpeg.org/download.html) -> Windows -> [Windows builds from gyan.dev](https://www.gyan.dev/ffmpeg/builds/)  或 [Windows builds by BtbN](https://github.com/BtbN/FFmpeg-Builds/releases)

推荐使用第二个[Github@BtbN/FFmpeg-Builds](https://github.com/BtbN/FFmpeg-Builds/releases)，在最新的一个```release```中，搜索```win```，下载```ffmpeg-master-latest-win64-gpl.zip```或```ffmpeg-master-latest-win64-gpl-shared.zip```。

解压```.zip```压缩包，将```bin```目录添加到```环境变量```，重启```cmd终端```，输入```ffmpeg -version```，看到```ffmpeg version n5.1-5-gaba74d7843-20220803 Copyright (c) 2000-2022 the FFmpeg developers```即说明安装配置成功。

## 使用

最简单的使用方式为：

### 格式转换

```bash
ffmpeg -i input.mp4 output.flv
```

### 音视频裁剪

```bash
ffmpeg -i input.mp4 -ss 20 -t 10 output.mp4
```

其中，```-ss```是开始时间，```-t```是持续时间。

```bash
ffmpeg -i input.mp4 -ss 20 -to 30 output.mp4
```

其中，```-ss```是开始时间，```-t0```是结束时间。

```bash
ffmpeg -i input.mp4 -ss 0:0:20 -to 0:0:30 output.mp4
```

其中，```20```代表20秒，```0:0:20```代表0时0分20秒。

另外的，若```-to```和```-t```同时设置，则以```-t```为准。

### 等长分割（批量分割）

```bash
ffmpeg -i input.mp3 -vn -f segment -segment_time 7 output%03d.mp3
```

将input.mp3分割为数个7秒的小片段，并命名为output001.mp3、output002.mp3、...。

其中：

+ ```-acodec copy``` instructs FFmpeg to copy the audio codec from the input file without re-encoding it, which means the output files will have the same audio quality.
+ ```-vn``` tells FFmpeg to extract only the audio stream from the input file and ignore the video stream, as this command does not produce any video output.
+ ```-f segment``` sets the output format to segmented files.
+ ```-segment_time 7``` 每段7秒

🤫

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/07/03/Other-FFmpeg-SomeCommonUsage/)哦~
> [https://blog.tisfy.eu.org/2023/07/03/Other-FFmpeg-SomeCommonUsage/](https://blog.tisfy.eu.org/2023/07/03/Other-FFmpeg-SomeCommonUsage/)
