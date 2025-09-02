<!--
 * @Author: LetMeFly
 * @Date: 2025-09-02 10:48:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 17:40:22
-->
---
title: MacOS - 记录MacOS发烫的好几天 - 幕后黑手竟然是
date: 2025-09-01 23:52:47
tags: [其他, Mac]
categories: [技术思考]
---

# MacOS - 记录MacOS发烫的好几天 - 幕后黑手竟然是

> Mac是不可能出bug的，一定是世界出bug了。

## 前言

几天前Mac突然开始烫烫的，就这么一烫烫了好几天。这可不行，所以看了下“活动监视器”，发现了一个Code Helper(Plugin)占据200%上下的CPU近4天了。

![高进程占用](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/24ab1584d8b24ca19884863c75501d9f.png)

详细信息中只能看到是`/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)`，可以确认是VsCode某个插件抽风了，但是看不到是具体哪个插件。看起来像是Colpolit或Trae这种编程辅助插件，但是这些插件在我刷题时都关掉了。

没办法，看pid时18900，于是命令行中执行了下`ps aux | grep 18900`，得到了：

```
letmefly        18900 186.4  0.0 1626974576   5904   ??  R    二03下午 5706:17.83 /Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin) /Users/letmefly/.vscode/extensions/marscode.marscode-extension-1.2.34/resource/aiserver/server.js --logFile false --isExternal true --authV2 false --pluginHomePathName .marscode
```

原来是`marscode.marscode-extension-1.2.34`，确实是trae插件抽风了。

并且不知道是什么原因导致的，这个Code Helper的父进程是launched而不是VsCode。所以即使我关闭VsCode重新打开(不是重启)这个进程也仍然存在，结束进程后CPU利用率反倒由200%上升到了259%，最后强制退出了这个进程。

过了一会儿，过了几天，Mac都凉凉的，这才是一个成熟Mac日常办公所应该具有的温度。

## End

今天Windows的`Microsoft Office SDX Helper`（`C:\Program Files\Microsoft Office\root\Office16`）又开始发了下疯，同样是狂吃CPU导致电脑发烫，直接在任务管理器中终止了就没事儿了。

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>


> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151087541)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/01/Other-MacOS-Logging_several_days_of_macOS_overheating/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)