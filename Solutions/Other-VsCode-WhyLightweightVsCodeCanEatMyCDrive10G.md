---
title: VsCode缓存清理 - 轻量级的VsCode为何越用越大？为什么吃了我C盘10G？如何无痛清理VsCode缓存？手把手教你为C盘瘦身
date: 2022-07-30 15:23:21
tags: [其他, VsCode, Windows, 磁盘清理]
categories: [技术思考]
---

VsCode是一款**轻量级**代码编辑器

可用一段就会很快发现，“轻量级”的VsCode并不轻量

不统计不知道，一统计吓一跳，使用了一段时间后，VsCode占用了我C盘10G+的空间！

好家伙，于是我决定治理一下VsCode，让VsCode变得真正的轻量级。

### VsCode的空间占用分析

VsCode所占用的空间，主要包括四大部分（下面是我写此博客时统计的结果）：

1. ```程序的安装目录```：大约会占用350M
2. ```%userprofile%\.vscode```：可达800M。主要为：各个拓展。VsCode卸载拓展似乎不会删除硬盘上的文件，因此这个里面很大，并且混有很多不用的
3. ```%userprofile%\AppData\Local\Microsoft\vscode-cpptools\ipch  ```：用一段时间能达到4G  与C(++)语言有关，关闭程序后可以直接删。不使用VsCode编辑C/C++的用户可能无此痛苦
4. ```%userprofile%\AppData\Roaming\Code```：2G+  存放用户数据、配置等。  （可以通过启动时添加--user-data-dir NewDir  来使其他目录作为配置）


可以定期删除的地方，有```3. ipch```（可完全删除） 和 ```4. Romaing```（不可完全删除）

#### 4. Romaing中，到底哪些可以定期删除

对```%userprofile%\AppData\Roaming\Code```中的文件进行更进一步地分析，我得到了如下结论：

```
%userprofile%\AppData\Roaming\Code\CachedExtensionVSIXs   用一段时间可以达到500M   可以直接删
%userprofile%\AppData\Roaming\Code\Cache       很快几十M
%userprofile%\AppData\Roaming\Code\CachedData  很快几十M
%userprofile%\AppData\Roaming\Code\CachedExtensions  安装新插件时，似乎默认不会自动删除，安装插件一多能达到800M
%userprofile%\AppData\Roaming\Code\CachedExtensionVSIXs 反正也是与插件有关的，也能达到几百M
%userprofile%\AppData\Roaming\Code\Code Cache    十几M
%userprofile%\AppData\Roaming\Code\Crashpad      十几M  用来存放崩溃信息
%userprofile%\AppData\Roaming\Code\logs          几十M  这个可以直接删，用来存放日志记录
%userprofile%\AppData\Roaming\Code\Service Worker 1G    
    %userprofile%\AppData\Roaming\Code\Service Worker\CacheStorage   1G  主要位于这里
    %userprofile%\AppData\Roaming\Code\Service Worker\ScriptCache    10M
%userprofile%\AppData\Roaming\Code\User          600M
    %userprofile%\AppData\Roaming\Code\User\workspaceStorage  500M  每打开一个工作目录就会在这个目录下生成一个文件夹
    %userprofile%\AppData\Roaming\Code\User\History           100M
            每Ctrl+S(仅限有修改的成功的重新保存)一次就会生成一个副本。
            这个不是按git的思路只存放更改，而是整个文件全部Copy一份。
            一个100多k的源码保存十次就是1M，对于习惯随手Ctrl+S的用户会占用较大的空间
            但是，删除之后将会影响历史版本的还原。
            其中，文件名采用了代码混淆技术，每个文件会生成一个文件夹，真正的文件名、各个文件对应文件保存时间都在每个文件夹下的entries.json中
    %userprofile%\AppData\Roaming\Code\User\snippets    这个不能删，并且重装还得记得备份（如果没有自动还原的话）这个是用户自定义的代码片段
```

### 能定时删除的目录

1. ```%userprofile%\AppData\Local\Microsoft\vscode-cpptools\ipch```
2. ```%userprofile%\AppData\Roaming\Code\CachedExtensionVSIXs```
3. ```%userprofile%\AppData\Roaming\Code\Cache```
4. ```%userprofile%\AppData\Roaming\Code\CachedData```
5. ```%userprofile%\AppData\Roaming\Code\CachedExtensions```
6. ```%userprofile%\AppData\Roaming\Code\CachedExtensionVSIXs```
7. ```%userprofile%\AppData\Roaming\Code\Code Cache```
8. ```%userprofile%\AppData\Roaming\Code\Crashpad```
9. ```%userprofile%\AppData\Roaming\Code\logs```
10. ```%userprofile%\AppData\Roaming\Code\Service Worker\CacheStorage```
11. ```%userprofile%\AppData\Roaming\Code\Service Worker\ScriptCache```
12. ```%userprofile%\AppData\Roaming\Code\User\workspaceStorage```
13. ```%userprofile%\AppData\Roaming\Code\User\History```


这么多文件夹总不可能手动地一个一个地删除，因此我写了一个脚本：

```bash
@REM example:
@REM del "%userprofile%/AppData/Local/Microsoft/vscode-cpptools/ipch/" /s /q /f
@REM rd "%userprofile%/AppData/Local/Microsoft/vscode-cpptools/ipch/" /s /q
@REM md "%userprofile%/AppData/Local/Microsoft/vscode-cpptools/ipch/"

@echo off

call:EmptyOneDir "%userprofile%\AppData\Local\Microsoft\vscode-cpptools\ipch"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\CachedExtensionVSIXs"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\Cache"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\CachedData"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\CachedExtensions"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\CachedExtensionVSIXs"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\Code Cache"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\Crashpad"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\logs"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\Service Worker\CacheStorage"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\Service Worker\ScriptCache"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\User\workspaceStorage"
call:EmptyOneDir "%userprofile%\AppData\Roaming\Code\User\History"

goto end

:EmptyOneDir  rem same as Let empty [path] /q
    echo empty %1
    echo del %1 /s /q /f
    del %1 /s /q /f
    echo rd %1 /s /q
    rd %1 /s /q
    echo md %1
    md %1
:end
```

**只需要将这个脚本另存为CleanVsCode.bat，并定期双击运行一次，就能定期释放大量空间**

当然，释放的空间直接取决于你的VsCode所产生的缓存大小，间接取决于你的VsCode的使用次数。

最好关闭VsCode后再运行脚本。

### ⚠️Warning

运行脚本后再次运行VsCode基本上看不出什么不同，只是当前工作路径下所打开的文件需要重新手动点击打开。

毕竟是一个能删除很多东西的脚本，因此请谨慎使用。

我作为本篇博客的原创博主，只是为大家提供了一个便捷的方法，但是其可能造成的后果，博主并不承担责任。

但是大家可以放心的是，我自己也在定期运行这个脚本。

准备有空的时候将其加入Windows计划，以实现定期地自动释放空间。

视频版演示：

[video(video-4523Dsfl-1662295789207)(type-bilibili)(url-https://player.bilibili.com/player.html?aid=430147071)(image-https://i-blog.csdnimg.cn/blog_migrate/36191ca6fcf0df7e7a315f4b3efe8254.jpeg)(title-轻量级的VsCode为何越用越大？为什么吃了我C盘10G？如何无痛清理VsCode缓存？手把手教你为C盘瘦身)]

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/30/Other-VsCode-WhyLightweightVsCodeCanEatMyCDrive10G/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126082324](https://letmefly.blog.csdn.net/article/details/126082324)