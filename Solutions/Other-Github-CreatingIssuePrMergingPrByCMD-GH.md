---
title: 使用GH（命令行）在本地提出Github上的issue、PR，合并PR
date: 2023-10-19 21:55:44
tags: [其他, Github, Git]
categories: [技术思考]
---

# 使用GH（命令行）在本地提出Github上的issue、PR，合并PR

## 前言

Github上的一些操作使用Git命令是无法完成的，因此正常流程就是在网页端进行。等一下，你让程序员用网页操作？果然，有命令行工具可以完成以上任务：[GH](https://cli.github.com)。并且，该工具还支持以ssh的方式操作，这样就基本上杜绝了```https://github.com```间歇性无法访问的尴尬。

## 首次下载、配置登录

进入[官网](https://cli.github.com)点击[Download for Windows](https://github.com/cli/cli/releases/download/v2.32.1/gh_2.32.1_windows_amd64.msi)，安装后会得到```gh.exe```（在虚拟机中安装后将```gh.exe```拷贝到环境变量中效果是一样的）。

首次需要使用命令```gh auth login```进行登录。这是应该是不可避免地要访问一下网页，但之后应该就不用了。之后依次选择（上下选择后回车选中）或输入（输入后回车）：

1. Github.com
2. **SSH**
3. C:\xx\.ssh\id_rsa.pub
4. GH SSH Key
5. Login with a web browser
6. 复制 ```one-time code```
7. 在网页端根据提示完成后续操作

最终所有配置会缓存在```%userprofile%\AppData\Roaming\GitHub CLI```下。

## 创建issue

在本地**git仓库**目录中使用以下命令即可在Github上创建issue：

```bash
gh issue create -t "标题title" -b "body"
```

## 创建PR

在本地git仓库目录的想发起PR的分支中，使用以下命令即可在Github上创建PR：

```bash
gh pr create -t "标题title" -b "body"
gh pr create -t "GH 使用小笔记" -b "close: #37"
```

## 合并PR并删除 本地和远程 的分支

```bash
gh pr merge GHNote -m -d
```

其中```38```是pr的编号，还可以换成```url```或```branch```。

其中```-m```是以```merge```的方式合并。还可以换成```-r```（```rebase```）或```-s```（```squash```）。

其中```-d```代表合并后删除本地和远端的分支。

## More

在几乎任何使用，使用```gh xx --help```以获得帮助。

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/19/Other-Github-CreatingIssuePrMergingPrByCMD-GH/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133935823](https://letmefly.blog.csdn.net/article/details/133935823)
