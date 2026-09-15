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

解压后你可能会得到一个压缩包，再解压一次可得到一些文件（夹）：

```
zsh-5.9.2-1-x86_64.pkg
├─etc
│  └─zsh
└─usr
│   ├─bin
│   ├─lib
│   │  └─zsh
│   │      └─5.9.2
│   │          └─zsh
│   │              ├─net
│   │              └─param
│   └─share
│       ├─licenses
│       │  └─zsh
│       ├─man
│       │  └─man1
│       └─zsh
│           ├─5.9.2
│           │  └─help
│           ├─functions
│           │  ├─Calendar
│           │  ├─Chpwd
│           │  ├─Completion
│           │  │  ├─Base
│           │  │  ├─Linux
│           │  │  ├─Unix
│           │  │  ├─X
│           │  │  └─Zsh
│           │  ├─Exceptions
│           │  ├─Math
│           │  ├─MIME
│           │  ├─Misc
│           │  ├─Newuser
│           │  ├─Prompts
│           │  ├─TCP
│           │  ├─VCS_Info
│           │  │  └─Backends
│           │  ├─Zftp
│           │  └─Zle
│           ├─scripts
│           └─site-functions
├─.BUILDINFO
├─.INSTALL
├─.MTREE
└─.PKGINFO
```

其中`.`开头的4个文件不用管，只需要把`etc`和`usr`文件夹放到Git Bash的安装目录下就好了。

`Git Bash`的安装目录在哪里？可以这样找到：`Win + R`，输入`cmd`，在弹出的窗口中输入`where bash`，得到类似`C:\Program Files\Git\bin\bash.exe`的路径，那么`Git Bash`的安装目录就是`C:\Program Files\Git`。

你看`C:\Program Files\Git`目录也有`etc`和`usr`文件夹，直接把解压后的`etc`和`usr`文件夹拖拽到这个目录下就可以了，会自动合并子文件夹（如果你不放心也可以手动递归复制文件(夹)到对应的目录）。

现在你在`Git Bash`中输入`zsh`，应该会有如下提示，直接按`0`跳过就行：

```
This is the Z Shell configuration function for new users,
zsh-newuser-install.
You are seeing this message because you have no zsh startup files
(the files .zshenv, .zprofile, .zshrc, .zlogin in the directory
~). This function can help you with a few settings that should
make your use of the shell easier.

You can:

(q) Quit and do nothing. The function will be run again next time.

(0) Exit, creating the file ~/.zshrc containing just a comment.
That will prevent this function being run again.

(1) Continue to the main menu.

--- Type one of the keys in parentheses ---
```

关于怎么打开`Git bash`，如果你是下载的Git安装包一路安装的话，应该可以在任意目录下右键，选择“在Git Bash中打开”；如果没有类似选项，也可以`Win + R`输入`bash`并回车即可。

## ZSH的简单配置

### git bash默认使用zsh

先把你的输入法调成英文，然后在`Git Bash`中输入：

```bash
vim ~/.bashrc
```

按`i`进入编辑模式，粘贴如下内容：

```bash
if [ -t 1 ]; then
  exec zsh
fi
```

按`Esc`退出编辑模式，输入`:wq`保存并退出。

这段命令的意思如下：`[ -t 1 ]`表示判断“文件描述符 1（stdout 标准输出）是不是终端”，如果是在交互式终端中运行则条件成立，启动zsh并使用zsh替换当前shell进程，否则（例如重定向到文件等场景）条件不成立就不切到zsh了。

也可以写成：

```bash
if [[ $- == *i* ]]; then
  exec zsh
fi
```

`$-` 是 Bash 的一个特殊变量，里面放着当前 Shell 的各种运行选项。如果这个字符串里面有`i`（代表interactive）就说明是交互式终端。

### 后续自定义配置

后面怎么配置就可以跟Linux和Mac上一样了，比如安装个`oh-my-zsh`和`zsh-autosuggestions`之类的。

## VsCode设置默认使用git bash(zsh)

如果你的Git和我一样不是正常安装的，那么VsCode可能识别不到你的git bash。需要在`settings.json`（Preferences: Open User Settings (JSON)）中添加以下内容：

```json

"terminal.integrated.profiles.windows": {
    "Lets ZSH": {
        "path": "C:\\MyApps\\Git\\App\\bin\\bash.exe"
    }
},
"terminal.integrated.defaultProfile.windows": "Lets ZSH",
```

注意，你可以起名为`Lets ZSH`，但你不能起名为`Git Bash`。

## End

参考文献：

+ 《[知乎：Windows安装Zsh终端](https://zhuanlan.zhihu.com/p/625583037)》

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/165002226)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/11/Other-Windows-Shell-UseZSHByGitBashAndMsys2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
