---
title: FFmpeg（强大的音视频处理工具） - 一些基本实用方法
date: 2023-07-03 15:30:06
tags: [其他, 中等, FFmpeg, 音频, 视频]
categories: [技术思考]
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

### 提取视频中的一段音频并输出为mp3

```bash
ffmpeg -ss 5 -t 5 -i input.mkv -vn -acodec mp3 output.mp3
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

关于如何在```Linux```上编译安装支持```CUDA```的```FFmpeg```请查看[FFmpeg - 如何在Linux(Ubuntu)上安装支持CUDA的FFmpeg](https://blog.letmefly.xyz/2023/04/07/Other-FFmpeg-howToInstallCudableFFmpegOnLinux/)。

### 使用一个视频的格式信息压制另一个视频

首先获取已有视频的格式信息：

```bash
ffprobe -v error -select_streams v:0 -show_entries stream=codec_name,bit_rate,width,height,avg_frame_rate -of default=noprint_wrappers=1 perfect.mkv
```

得到：

```
codec_name=h264
width=1920
height=1080
avg_frame_rate=24000/1001
bit_rate=2183643
```

接着按照此格式开始压制即可：

```bash
ffmpeg -i input.mkv -c:v libx264 -b:v 2M -s 1920x1080 -r 24 output.mkv
```

### 格式转换时保留内挂字幕

```bash
ffmpeg -i input.mkv -c:s copy output.mkv
```

其中```-c:s```是值字幕，```copy```是指复制，也可以修改成```-c:s ass```等。

### 视频倍速

```bash
ffmpeg -i input.mp4 -filter_complex "[0:v]setpts=PTS/1.5[v];[0:a]atempo=1.5[a]" -map "[v]" -map "[a]" -c:v libx264 -c:a aac -b:a 192k output.mp4
```

<details><summary><span title="ByChatGPT:https://chatgpt.com/share/c056ce83-9103-4968-8e5d-8c981309bff9">参数详解</span></summary><ul><li><p><code>ffmpeg</code>：调用FFmpeg程序。</p></li><li><p><code>-i WeChat_20240521100857.mp4</code>：指定输入文件名为 <code>WeChat_20240521100857.mp4</code>。</p></li><li><p><code>-filter_complex "[0:v]setpts=PTS/1.5[v];[0:a]atempo=1.5[a]"</code>：应用复杂滤镜处理：</p><ul><li><code>-filter_complex</code>：使用复杂滤镜功能。</li><li><code>[0:v]setpts=PTS/1.5[v]</code>：将视频流的时间戳(PTS)按1.5倍速调整。具体含义如下：<ul><li><code>[0:v]</code>：表示第一个输入文件的视频流。</li><li><code>setpts=PTS/1.5</code>：PTS（Presentation Time Stamp，显示时间戳）是FFmpeg用来同步音视频的标记。将时间戳缩短为原来的1/1.5，从而实现1.5倍速播放。</li><li><code>[v]</code>：给处理后的视频流命名为<code>[v]</code>，供后续使用。</li></ul></li><li><code>[0:a]atempo=1.5[a]</code>：将音频流的速度调整为1.5倍。具体含义如下：<ul><li><code>[0:a]</code>：表示第一个输入文件的音频流。</li><li><code>atempo=1.5</code>：将音频速度调整为1.5倍。FFmpeg中<code>atempo</code>滤镜用于调整音频速度，允许的值范围是[0.5, 2.0]，超过范围需要链式使用多个<code>atempo</code>。</li><li><code>[a]</code>：给处理后的音频流命名为<code>[a]</code>，供后续使用。</li></ul></li></ul></li><li><p><code>-map "[v]"</code>：指定输出文件使用处理后的视频流<code>[v]</code>。</p></li><li><p><code>-map "[a]"</code>：指定输出文件使用处理后的音频流<code>[a]</code>。</p></li><li><p><code>-c:v libx264</code>：指定视频编码器为<code>libx264</code>，这是一个常用的高质量H.264编码器。</p></li><li><p><code>-c:a aac</code>：指定音频编码器为<code>aac</code>，这是一个常用的高质量音频编码器。</p></li><li><p><code>-b:a 192k</code>：指定音频比特率为192 kbps，确保音频质量。</p></li><li><p><code>output.mp4</code>：指定输出文件名为 <code>output.mp4</code>。</p></li></ul></details>

## Mac版

> 这个小节针对Mac的ffmpeg做一些特殊说明。

安装：

```bash
brew install ffmpeg
```

Macbook Air M5 gpu加速：

```bash
ffmpeg -hwaccel videotoolbox -i 微信视频2026-06-29_135147_974.mp4 -c:v h264_videotoolbox -crf 25 -b:v 5M -c:a copy output.mp4
# 主要是 -hwaccel videotoolbox 和 -c:v h264_videotoolbox
```

GPU加速前转码速率1.4左右，CPU利用率90%+；GPU加速后转码速率4.5左右，CPU利用率10%，GPU利用率50%。

## End

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/03/Other-FFmpeg-SomeCommonUsage/)哦~
> [https://blog.letmefly.xyz/2023/07/03/Other-FFmpeg-SomeCommonUsage/](https://blog.letmefly.xyz/2023/07/03/Other-FFmpeg-SomeCommonUsage/)
