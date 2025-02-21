---
title: Windows - URL Scheme - 在Windows上无管理员权限为你的程序添加URL Scheme
date: 2024-02-08 22:15:06
tags: [其他, Windows, URL Scheme]
---

# Windows - URL Scheme - 在Windows上无管理员权限为你的程序添加URL Scheme

## What

想不想在浏览器打开/控制你的电脑应用？

比如我在浏览器地址栏输入```wegame://```后回车会提示```是否打开URL:wegame Portocol```。

![wegame:/](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/blog_migrate/b0189f1d64fe75ded0f955a2473a6c40.png)

若出现了```始终允许```选项，你甚至可以写一个Web界面，在```始终允许```后通过Web控制你的本地程序。

这是怎么实现的呢？<span title="覆雪之下喜欢说的一句话">很简单，我教你啊！</span>

## 要张脑子了

想要了解这种协议，可以Google```URL Scheme```。

+ 在Windows和MacOS上，你可以使用这种协议打开或控制本地应用（也许[Linux](https://github.com/youssef-attai/linux-custom-url-scheme)也行？）
+ 在Android和iOS上，你可以使用这种协议在应用之间跳转（并传参）

比如<span title="LX Music">某开源音乐播放器</span>就支持通过[Scheme URL](https://lxmusic.toside.cn/desktop/scheme-url)来控制音乐的播放。

有了这种协议，你也可以在用户访问你的某个软件的官网时，实现“在xx软件中打开并查看”的功能。

本篇<b title="主要是安卓苹果我暂时不会">只以</b>Windows为例，演示如何在不需要用户的管理员权限的情况下，为你的应用创建URL Scheme。

## How

只需要向注册表```HKEY_LOCAL_MACHINE\Software\Classes```或```HKEY_CURRENT_USER\Software\Classes```中添加一些子键。其中```HKEY_LOCAL_MACHINE```对所有用户生效，但需要管理员权限。现在以只对当前用户生效的不需要管理员权限的```HKEY_CURRENT_USER```为例：<span title="这两个位置叫“HKEY_CLASSES_ROOT”" style="color: black; background-color: black">(这两个位置叫“HKEY_CLASSES_ROOT”)</span>

首先```Win+R```，```regedit```并```回车```打开注册表，进入到```HKEY_CURRENT_USER\Software\Classes```的位置:

![进入HKEY_CLASSES_ROOT](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/blog_migrate/24ec011191d7ab68954f3b133ee6de52.png)

在```Classes```下```右键→新建项```并```重命名```新建的项（文件夹）。这里的名字就是你待会儿在浏览器中输入的scheme。这里以```LetTest```为例。

在```LetTest```文件夹空白处双击```默认```并修改默认值，这里的值就是浏览器中显示的内容（就像WeGame显示的```URL:wegame Portocol```）。这里以```URL Scheme测试```为例。（其实这里的值写成```URL:<myapp> Protocol```比较规范）

在```LetTest```文件夹上或空白处```右键→新建→字符串值```，名字为```URL Protocol```（不能更改），值一般为你的可执行程序的位置。这里以```F:\OtherApps\Program\Python\Python\python.exe```为例。（其实这里写什么都能正常执行，但建议这么写）

![next step](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/blog_migrate/b7fa1b6d7ebddbd1d41e418bd2240306.png)

在```LetTest```文件夹上依次建立```shell→open→command```文件夹，其中```shell```和```open```的默认值都为空，```command```的值为你要执行的命令。

这里的命令一般为```"可执行程序" "%1"```（其中```"%1"```为浏览器等传递的参数）。一般为```"C:\LetMeFly.exe" "%1"```，但是这里以一个简单的Python脚本为例，写为```"F:\OtherApps\Program\Python\Python\python.exe" "F:\OtherApps\Program\VsCode\Code\TrySchemeURL\test.py" "%1"```。（其中Python.exe的位置和```test.py```的位置都需要根据实际需求来调整）

![next step 2](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/blog_migrate/774ea2172aa37ab4b34e5ecfbb925ac2.png)

在```F:\OtherApps\Program\VsCode\Code\TrySchemeURL```目录下（或其他位置）新建```test.py```，写入以下内容：

```python
import sys
import os

print(sys.argv)
os.system('pause')
```

在浏览器中输入```LetTest://hello/world/?a=1```回车，大功告成！

![原神启动！](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/blog_migrate/c40c43e466fabe2756a8820082da496b.png)

![按任意键进入异世界](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/blog_migrate/97ada65d40aef067d2fba406513cff5b.png)

关于这里为什么显示的是```Python```而不是```URL Scheme测试```，我发现```command```为一个文件的位置时会显示文件名，否则会显示你起的名字。

你还可以为这个Scheme设置一个图标（虽然在浏览器中也不会显示）：

在```LetTest```下新建```DefaultIcon```项，默认值为图标路径。

![icon?](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/blog_migrate/ea8041ee6f34bd7cfe9725bb4fa0dc1b.png)

## 这描述太详细（太长）了，能否可视化一点

没问题，结构如下：

```
HKEY_CURRENT_USER\Software\Classes
    LetTest
        (Default) = URL Scheme测试
        URL Protocol = 
        DefaultIcon
            (Default) = "C:\favicon.ico"
        Shell
            Open
                Command
                    (Default) = "F:\OtherApps\Program\Python\Python\python.exe" "F:\OtherApps\Program\VsCode\Code\TrySchemeURL\test.py" "%1"
```

导出的.reg文件为：（双击即可食用）

```regedit
Windows Registry Editor Version 5.00

[HKEY_CURRENT_USER\SOFTWARE\Classes\LetTest]
@="URL Scheme测试"
"URL Protocol"="F:\\OtherApps\\Program\\Python\\Python\\python.exe"

[HKEY_CURRENT_USER\SOFTWARE\Classes\LetTest\DefaultIcon]
@="F:\\OtherApps\\Program\\Python\\Python\\python.exe"

[HKEY_CURRENT_USER\SOFTWARE\Classes\LetTest\shell]

[HKEY_CURRENT_USER\SOFTWARE\Classes\LetTest\shell\open]

[HKEY_CURRENT_USER\SOFTWARE\Classes\LetTest\shell\open\command]
@="\"F:\\OtherApps\\Program\\Python\\Python\\python.exe\" \"F:\\OtherApps\\Program\\VsCode\\Code\\TrySchemeURL\\test.py\" \"%1\""
```

## 参考

+ [吕毅的博客](https://blog.walterlv.com/post/windows-uri-scheme-association.htm)写得不错。

似乎对，，自家的`microsoft-edge`无效。。。

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/08/Other-Windows-URLScheme-Define1URLSchemeForYourApplicationWithoutUACOnWindows/)哦~
>
> [https://letmefly.blog.csdn.net/article/details/136083203](https://letmefly.blog.csdn.net/article/details/136083203)

