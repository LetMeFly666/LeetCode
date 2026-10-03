---
title: 两台旧电脑修复 —— 绕过WinXP密码登录、备份和恢复Win7数据、安装Win10
date: 2026-10-03 17:28:33
tags: [其他, Windows, 重装, 系统恢复]
categories: [技术思考]
---

# 两台旧电脑修复 —— 绕过WinXP密码登录、备份和恢复Win7数据、安装Win10

## 前言

国庆回家邻居有两台旧电脑，一台是WinXP系统的台式机忘记了密码，一台是Win7系统的笔记本电脑完全无法进入系统。故寻求我来帮忙修复这两台电脑。

## PE盘制作

恰逢手中PE盘被某位格外讨人喜欢的同事征用，故重做一枚。

### U盘数据备份

临时找了一个U盘，借助手中Mac制作一个镜像到Mac上，待U盘重装的使命完成后再恢复。

第一次使用了`dd`命令：

```bash
sudo dd if=/dev/rdisk4 of=~/Downloads/usb-backup.img bs=4m
```

结果发现U盘里面只有几十M的文件，而这个命令需要制作U盘总容量等大的DMG。故改用了`hdiutil`命令只保存已使用内容并带上一部分的压缩算法：

```bash
hdiutil create -srcdevice /dev/rdisk4 -format UDZO -o /Users/tisfy/Downloads/usb-backup.dmg
```

### 启动盘制作



### U盘数据还原

```bash
diskutil list external
diskutil info /dev/disk4  
diskutil info /dev/disk4 | grep Protocol  # 确认USB是/dev/disk4
diskutil unmountDisk /dev/disk4
sudo asr restore --source /Users/tisfy/Downloads/usb-backup.dmg --target /dev/disk4 --erase
```

## 绕过WinXP密码登录

WinXP系统的古早台式机，

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/167038314)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/03/Other-Windows-ReInstall_bypassWinXPPassword_BackupRecoryWin7Data_Win10Install/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
