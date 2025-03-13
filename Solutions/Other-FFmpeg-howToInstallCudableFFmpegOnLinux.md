---
title: FFmpeg - 如何在Linux(Ubuntu)上安装支持CUDA的FFmpeg
date: 2024-04-07 09:20:14
tags: [其他, 中等, FFmpeg, 音频, 视频]
categories: [技术思考]
---

# FFmpeg - 如何在Linux(Ubuntu)上安装支持CUDA的FFmpeg

> 笔者认为现在的很多“xx教程”只讲干什么不讲为什么，这样即使报错了看官也不知道如何解决。

在[安装过程的探索](#安装过程的探索)部分会记录我的整个安装过程以及报错和报错的解决办法。

在[省流之一步到位的方法](#省流之一步到位的方法)部分会省去安装过程中磕磕绊绊的哪些坑，提供一种避坑的方法。

## 安装过程的探索

**确保机器上安装好了NVIDIA驱动和CUDA Toolkit**

可以通过```nvidia-smi```命令检查NVIDIA驱动程序是否已正确安装，通过```nvcc --version```命令来验证```CUDA Toolkit```是否安装完成。

**安装带有NVIDIA硬件加速支持的FFmpeg**

```bash
git clone https://git.ffmpeg.org/ffmpeg.git ffmpeg  
cd ffmpeg
./configure --enable-cuda-nvcc --enable-cuda-sdk --enable-libnpp --enable-nvenc --extra-cflags="-I/usr/local/cuda/include" --extra-ldflags="-L/usr/local/cuda/lib64"
make
sudo make install
```

**非自由软件的启用**

上一步执行时候会报错：

```
cuda_nvcc is nonfree and --enable-nonfree is not specified.

If you think configure made a mistake, make sure you are using the latest
version from Git.  If the latest version fails, report the problem to the
ffmpeg-user@ffmpeg.org mailing list or IRC #ffmpeg on irc.libera.chat.
Include the log file "ffbuild/config.log" produced by configure as this will help
solve the problem.
```

大概意思是说```cuda_nvcc```是非自由软件，需要在FFmpeg的配置选项中加入```--enable-nonfree```。

这样生成的二进制文件将会包含非自由代码，可能会限制FFmpeg版本的分发。

```bash
./configure --enable-cuda-nvcc --enable-cuda-sdk --enable-libnpp --enable-nvenc --enable-nonfree --extra-cflags="-I/usr/local/cuda/include" --extra-ldflags="-L/usr/local/cuda/lib64"
make
sudo make install
```

**安装ffnvcodec**

上一步执行时候会报错：

```
ERROR: nvenc requested, but not all dependencies are satisfied: ffnvcodec

If you think configure made a mistake, make sure you are using the latest
version from Git.  If the latest version fails, report the problem to the
ffmpeg-user@ffmpeg.org mailing list or IRC #ffmpeg on irc.libera.chat.
Include the log file "ffbuild/config.log" produced by configure as this will help
solve the problem.
```

ffnvcodec是FFmpeg对NVIDIA编解码SDK的封装，必须在系统中安装此库才能启用NVENC编码器。

```bash
sudo apt-get update
sudo apt-get install libnvidia-encode-<version> ffmpeg
sudo apt-get install nv-codec-headers
```

如何确定```libnvidia-encode```的```version```呢？需要将```<version>```替换为NVIDIA驱动版本号。

```bash
nvidia-smi | grep "Driver Version"
```

可以看到```| NVIDIA-SMI 470.239.06   Driver Version: 470.239.06   CUDA Version: 11.4 |```，即驱动版本```Driver Version```为```470.239.06```。

尝试```sudo apt-get install libnvidia-encode-470.239.06 ffmpeg```报错找不到```libnvidia-encode-470.239.06```。

尝试不加版本号```sudo apt-get install libnvidia-encode```得到：

```
正在读取软件包列表... 完成
正在分析软件包的依赖关系树       
正在读取状态信息... 完成       
虚拟软件包 libnvidia-encode 由下面的软件包提供：
  nvidia-340 340.108-0ubuntu5.20.04.2
  libnvidia-encode-390 390.157-0ubuntu0.20.04.1
  libnvidia-encode-525-server 525.105.17-0ubuntu0.18.04.1
  libnvidia-encode-515-server 515.105.01-0ubuntu0.18.04.1
  libnvidia-encode-470-server 470.182.03-0ubuntu0.18.04.1
  libnvidia-encode-450-server 450.236.01-0ubuntu0.18.04.1
  libnvidia-encode-418-server 418.226.00-0ubuntu0.18.04.2
  libnvidia-encode-550 550.54.15-0ubuntu1
  libnvidia-encode-535 535.161.08-0ubuntu1
  libnvidia-encode-470 470.239.06-0ubuntu1
  libnvidia-encode-545 545.23.08-0ubuntu1
  libnvidia-encode-525 525.147.05-0ubuntu1
  libnvidia-encode-450 450.248.02-0ubuntu1
  libnvidia-encode-515 515.105.01-0ubuntu1
  libnvidia-encode-510 510.108.03-0ubuntu1
  libnvidia-encode-520 520.61.05-0ubuntu1
  libnvidia-encode-495 495.29.05-0ubuntu1
  libnvidia-encode-465 465.19.01-0ubuntu1
  libnvidia-encode-460 460.106.00-0ubuntu1
  libnvidia-encode-455 455.45.01-0ubuntu1
请您明确地选择安装其中一个。

E: 软件包 libnvidia-encode 没有可安装候选
```

其中```libnvidia-encode-470```对应的```470.239.06-0ubuntu1```不正是我显卡驱动的版本吗。

因此```sudo apt-get install libnvidia-encode-470 ffmpeg```解决。

在执行命令```sudo apt-get install nv-codec-headers```时报错```无法定位软件包 nv-codec-headers```，因此需要手动下载其源码并编译安装：

```bash
git clone https://git.videolan.org/git/ffmpeg/nv-codec-headers.git
cd nv-codec-headers
sudo make install
```

**最后一步之编译FFmpeg**

准备工作做完了，直接

```bash
./configure --enable-cuda-nvcc --enable-cuda-sdk --enable-libnpp --enable-nvenc --enable-nonfree --extra-cflags="-I/usr/local/cuda/include" --extra-ldflags="-L/usr/local/cuda/lib64"
make
sudo make install
```

等待*一会儿*，就安装好了。

```bash
ffmpeg -hwaccels
```

可以看到：

```
Hardware acceleration methods:
vdpau
cuda
```

说明ffmpeg现在已经支持CUDA加速了。

（```./configure```的时候抛出了警告```WARNING: Option --enable-cuda-sdk is deprecated. Use --enable-cuda-nvcc instead.```，已经有```--enable-cuda-nvcc```了，因此我们也可以删掉```--enable-cuda-sdk```。）

**启用libx264**

```bash
sudo apt-get install libx264-dev
```

然后在```./configure```的时候添加两个参数```--enable-libx264```和```--enable-gpl```（```--enable-gpl```是添加```--enable-libx264```的时候它让加的）

## 省流之一步到位的方法

若安装过程遇到任何报错可以尝试在在[安装过程的探索](#安装过程的探索)中寻找可能的解决方法。

```bash
# 安装libnvidia-encode和ffmpeg开发包
sudo apt-get update
sudo apt-get install libnvidia-encode-<version> ffmpeg  # 将<version>替换为你显卡驱动的版本
git clone https://git.videolan.org/git/ffmpeg/nv-codec-headers.git
cd nv-codec-headers
sudo make install
cd ..
# 编译安装FFmpeg
./configure --enable-cuda-nvcc --enable-libnpp --enable-nvenc --enable-nonfree --extra-cflags="-I/usr/local/cuda/include" --extra-ldflags="-L/usr/local/cuda/lib64"  # 也可以加上--enable-libx264 --enable-gpl以便支持libx264
make
sudo make install
```

## 如何加速？加速命令是什么

```bash
ffmpeg -hwaccel cuda -i input.mp4 output.mp4
```

命令中```-hwaccel cuda```选项告诉FFmpeg使用CUDA进行硬件加速。

```bash
ffmpeg -hwaccel cuda -hwaccel_output_format cuda -i input.mp4 -c:v h264_nvenc output.mp4
```

命令中```-c:v h264_nvenc```选项指定使用NVIDIA的NVENC进行视频编码，而```-hwaccel_output_format cuda```选项指定了使用CUDA格式的硬件加速输出。

## End

有关FFmpeg的一些常用命令可以查看[FFmpeg（强大的音视频处理工具） - 一些基本实用方法](https://blog.letmefly.xyz/2023/07/03/Other-FFmpeg-SomeCommonUsage/)。

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/04/07/Other-FFmpeg-howToInstallCudableFFmpegOnLinux/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137449955](https://letmefly.blog.csdn.net/article/details/137449955)