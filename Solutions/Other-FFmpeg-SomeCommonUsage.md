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
ffmpeg -ss 20 -t 10 -i input.mp4 output.mp4
```

其中，```-ss```是开始时间，```-t```是持续时间。

```bash
ffmpeg -ss 20 -to 30 -i input.mp4 output.mp4
```

其中，```-ss```是开始时间，```-to```是结束时间。

```bash
ffmpeg -ss 0:0:20 -to 0:0:30 -i input.mp4 output.mp4
```

其中，```20```代表20秒，```0:0:20```代表0时0分20秒。

另外的，若```-to```和```-t```同时设置，则以```-t```为准。

**特别提醒：**

使用ffmpeg进行视频裁剪时，请务必将```-ss```参数放在```-i```前面！

虽然先```-i```和先```-ss```都能正常裁剪，但是先```-i```的话，可能会比先```-ss```慢很多。

```bash
# 十来秒后才开始裁剪
ffmpeg -i "[DMG&LoliHouse] BOCCHI THE ROCK! - 05 [WebRip 1080p HEVC-10bit AAC ASSx2].mkv" -ss 200 -t 5 output.mp4 -y
# 几乎立刻开始裁剪
ffmpeg -ss 200 -t 5 -i "[DMG&LoliHouse] BOCCHI THE ROCK! - 05 [WebRip 1080p HEVC-10bit AAC ASSx2].mkv" output.mp4 -y
```

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

### 给视频添加图片文字

所用到素材及结果详见：[阿里云盘分享](https://www.aliyundrive.com/s/EQKti4XkgB3)

#### 给视频添加图片

如果想要往某个视频上的某个位置添加一个图片（比如二维码），则可以使用以下命令将```0.png```添加到```0.mp4```的左上角```(10, 10)```的位置：

```bash
ffmpeg -i 0.mp4 -i 0.png -filter_complex "overlay=10:10" output.mp4
```

如果想要0.png仅在第5到10秒出现，则可以：

```bash
ffmpeg -i 0.mp4 -i 0.png -filter_complex "overlay=10:10:enable='between(t,5,10)" output.mp4
```

#### 给视频添加文字

如果想在```0.mp4```的```(130, 320)```处添加大小为```70```的```黑```色```华文行楷```的```欢迎来到我的空间```，则可以：

```bash
ffmpeg -i 0.mp4 -i 0.png -vf "drawtext=text='欢迎来到我的空间':fontsize=70:fontcolor=black:x=130:y=320:fontfile=C\\:/Windows/Fonts/STXINGKA.TTF" output.mp4
```

#### 同时给视频添加图片和文字

ffmpeg中```-vf```和```-filter_complex```不能同时用于同一个输出流。想要同时往视频中添加图片和文字，可以使用```-filter_complex```选项来指定所有过滤器：

```bash
ffmpeg -i 0.mp4 -i 0.png -filter_complex "[0:v][1:v]overlay=180:450,drawtext=text='欢迎来到我的空间':fontsize=70:fontcolor=black:x=130:y=320:fontfile=C\\:/Windows/Fonts/STXINGKA.TTF[outv]" -map "[outv]" output.mp4
```

### 合并视频和字幕

假设当前目录下有```0.mp4```和```0.ass```，则可以：

```bash
ffmpeg -i 0.mp4 -vf "ass=0.ass" -c:a copy output.mp4
```

假设提示“找不到字体”，则可以

```bash
ffmpeg -i 0.mp4 -vf "ass=0.ass:fontsdir=/path/to/fonts/" -c:a copy  output.mp4
```

### 使用硬件加速（GPU）

首先确定可用硬件列表：

```bash
ffmpeg -hwaccels
```

得到结果：

```
ffmpeg versioxxx
xxx

Hardware acceleration methods:
cuda
qsv
d3d11va
opencl
vulkan
```

则说明可以使用```cuda```、```qsv```等进行硬件加速。

接着只需要：

```bash
# ffmpeg -hwaccel <加速器> -i 输入视频文件 输出视频文件
ffmpeg -hwaccel cuda -i 0.mp4 1.flv
```

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/07/03/Other-FFmpeg-SomeCommonUsage/)哦~
> [https://blog.tisfy.eu.org/2023/07/03/Other-FFmpeg-SomeCommonUsage/](https://blog.tisfy.eu.org/2023/07/03/Other-FFmpeg-SomeCommonUsage/)
