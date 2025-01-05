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

在执行`git checkout`命令时，可以将整个仓库还原到一个`分支/commit_hash/tag`，可以用于恢复一个文件(夹)。

当切换到`分支/commit_hash/tag`时，正确的命令是`git checkout 分支/commit_hash/tag`。

+ 例如我有一个分支名为`dev`，那么我可以使用`git checkout dev`命令切换到`dev`分支；
+ 例如我有一个commit的hash为`9259d713a40e97f97af61a422631b723f5666aa5`，那么我可以使用`git checkout 9259d713`命令切换到这次commit；
+ 例如我有一个tag名为`v0.1`，那么我可以使用`git checkout v0.1`命令切换到这个tag；
+ 例如我想创建并切换到`dev`分支，那么我可以使用`git checkout -b dev`命令。

若重名，则优先级`分支 > 标签 > commit_hash`。

当恢复一个文件(夹)时，正确的命令是`git checkout -- 文件(夹)名`。

+ 例如我有一个文件夹是`Solution`，那么我可以通过命令`git checkout -- Solution`将文件夹`Solution`恢复到暂存区或版本库。

**但是**，如果我没有加`--`，`git checkout`命令仍然会恢复这个文件夹！

## 误操

我本来想创建并切换到一个分支`api`：

```bash
git checkout -b api
```

结果因为困倦忘记输入`-b`了：

```bash
git checkout api
```

结果此时我还没有`api`分支，但正好有`api`文件夹。

`git`一看，心想，你这命令不规范，想还原一个文件夹但是没有`--`啊，你应该输成`git chcekout -- api`，太菜了吧，`--`都不知道输。还好我`git`比较聪明，知道你的意思，虽然你没有加`--`，但我还是帮你把文件夹`api`给还原了吧。

然后我一个晚上的更改就几乎全被还原了。。。没被还原的，只剩下一些未被跟踪过的文件（新创建的文件）。然后我就在VsCode的`时间线`里把文件一个一个恢复了一下。。。

竟然，，一丁点提示都没有。

## 亡羊补牢

早就有人吐槽创建并切换到新分支也是checkout命令，因此从git 2.23开始引入了`switch`命令。

以后再切换分支时，就使用`git switch 分支名`；创建并切换到新分支时，就使用`git switch -c 分支名`好了。

## End

另：我的git版本为`2.42.0.windows.2`。

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/04/Other-Git-record1gitFileLost/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144929924](https://letmefly.blog.csdn.net/article/details/144929924)
