---
title: Windows(Shell) —— 通过Git Bash和Msys2在Windows上使用ZSH
date: 2026-09-09 10:51:42
tags: [其他, VsCode, Windows, bash, shell, zsh, git]
categories: [技术思考]
---

# Windows(Shell) —— 通过Git Bash和Msys2在Windows上使用ZSH

> 天下人苦cmd久矣(bushi)

Windows自带的cmd和PowerShell在使用上都不如Linux下的shell方便，安装了Git后默认会带有Git Bash（运行时基于msys2-runtime修改而来），只需要再安装一个MSYS2的zsh就能在Windows上通过Git Bash使用zsh了。

## Git 安装（简述）

折腾Windows上ZSH的大概都安装过git。如果没，那就在[官网](https://git-scm.com/install/windows)[下载](https://github.com/git-for-windows/git/releases/download/v2.55.0.windows.5/Git-2.55.0.5-64-bit.exe)并安装即可。

安装完成后如果你能正常使用`git`命令那么你大概率也可以直接使用`bash`命令来使用Git Bash了。

## MSYS2简介

MSYS2是一个在Windows上运行的类Unix环境，如果你想要省事儿的话，也可以直接安装一个MSYS2。MSYS2使用`pacman`作为包管理器，可以直接使用`pacman -S zsh`来安装zsh。

但这不是本文的目的。由于Git Bash本身就是基于msys2-runtime修改而来，所以我们可以直接在Git Bash中使用MSYS2的zsh。

## ZSH下载“安装”

访问[msys2官网的zsh包](https://packages.msys2.org/packages/zsh?repo=msys&variant=x86_64)，找到`File:`后面的下载链接：[https://mirror.msys2.org/msys/x86_64/zsh-5.9.2-1-x86_64.pkg.tar.zst](https://mirror.msys2.org/msys/x86_64/zsh-5.9.2-1-x86_64.pkg.tar.zst)，这是一个压缩包，可以使用Bandizip或者7-Zip等工具解压。

解压后你可能会得到一个压缩包，再解压一次可得到一些文件：

```
zsh-5.9.2-1-x86_64.pkg
├─etc
│  └─zsh
└─usr
    ├─bin
    ├─lib
    │  └─zsh
    │      └─5.9.2
    │          └─zsh
    │              ├─net
    │              └─param
    └─share
        ├─licenses
        │  └─zsh
        ├─man
        │  └─man1
        └─zsh
            ├─5.9.2
            │  └─help
            ├─functions
            │  ├─Calendar
            │  ├─Chpwd
            │  ├─Completion
            │  │  ├─Base
            │  │  ├─Linux
            │  │  ├─Unix
            │  │  ├─X
            │  │  └─Zsh
            │  ├─Exceptions
            │  ├─Math
            │  ├─MIME
            │  ├─Misc
            │  ├─Newuser
            │  ├─Prompts
            │  ├─TCP
            │  ├─VCS_Info
            │  │  └─Backends
            │  ├─Zftp
            │  └─Zle
            ├─scripts
            └─site-functions
```


## End

参考文献：

+ 《[知乎：Windows安装Zsh终端](https://zhuanlan.zhihu.com/p/625583037)》

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/165002226)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/11/Other-Windows-Shell-UseZSHByGitBashAndMsys2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
