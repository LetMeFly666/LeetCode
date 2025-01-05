---
title: Git - 记录一次由于少输入了一个参数导致的更改丢失
date: 2025-01-04 14:48:11
tags: [其他, Git]
---

# Git - 记录一次由于少输入了一个参数导致的更改丢失

## 前言

某晚我激情开发了几个小时，中途没有进行commit存档。准备睡觉时，我想创建一个新的分支并将今晚所有更改提交到新分支上（似乎应该开发时候就创建？）。

然后因为少输入了一个参数，导致被跟踪过的文件的更改全部消失了。

## 成因

我想创建并切换到`api`分支：

```bash
git checkout -b api
```

结果一困少输了个`-b`，变成了：

```bash
git checkout api
```

结果我那晚开发的所有内容恰好都在`api`这个文件夹下，于是所有的更改都没了。

## 分析

在执行`git checkout`命令时，如果想要将文件还原到

## End

另：我的git版本为`2.42.0.windows.2`。

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/04/Other-Git-record1gitFileLost/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144929924](https://letmefly.blog.csdn.net/article/details/144929924)
