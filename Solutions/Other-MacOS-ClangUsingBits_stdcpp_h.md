---
title: MacOS - Clang使用bits/stdc++.h - 非官方(竞赛用) - 通用方法
date: 2025-09-27 12:54:53
tags: [其他, MacOS, C++]
categories: [技术思考]
---

# MacOS - Clang使用bits/stdc++.h - 非官方(竞赛用) - 通用方法

## 前言

Windows和MacOS双用户，Windows上cpp**打竞赛/刷题**时使用`bits/stdc++.h`确实方便，毕竟不是实际项目的开发。

但MacOS的默认clang不包含`bits/stdc++.h`头文件，检索、github多星仓库的方法都**不通用**，故写此文已记之。

并且每次mac更新了developer kit之后，之前手动添加的`bits/stdc++.h`头文件都会失效，需要重新添加。

## 原理

不论是编译过程中还是在IDE的语法检测过程中，(若无指定特殊参数)都是会去默认库文件路径下查找目标头文件。

而clang默认没有`bits/stdc++.h`这个头文件，所以没办法`#include <bits/stdc++.h>`。

所以直接新建个这个文件，放到库文件目录下就好了。

## 方法

网上clang库文件的位置都是一个固定路径，不同版本的MacOS(如最近新出的MacOS26)路径也不同。

如何确定clang默认库文件的位置？两个方法吧

### 方法一：IDE中获取

如果你使用IDE(大概率)，如VsCode，直接随便创建个cpp文件，如：

```cpp
#include <iostream>
```

然后鼠标在`iostream`上`Command+单击鼠标左键`就好。

这样VsCode就会打开`iostream`这个文件，这个文件所在路径就是clang库文件的默认路径。（如：`/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/`）

### 方法二：使用clang命令

MacOS上打开`终端`，输入命令`clang -E -x c++ - -v < /dev/null`，可以看到输出中包含如下内容：

```
#include "..." search starts here:
#include <...> search starts here:
 /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1
 /Library/Developer/CommandLineTools/usr/lib/clang/17/include
 /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
 /Library/Developer/CommandLineTools/usr/include
 /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks (framework directory)
 /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/SubFrameworks (framework directory)
End of search list.
```

看到没，`#include <...> search starts here:`，也就是说`#include <xxx>`的时候是从这些路径下开始搜索头文件的。

随便选一个（如第一个的`/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/`即可）。

### 最后的头文件添加

在上一步找到的库文件默认路径下新建文件夹`bits`，并将`stdc++.h`放入这个文件夹下就好了。

至于`stdc++.h`这个文件怎么来？可以在Windows上复制(maybe)，也可以使用Github上的[这个](https://raw.githubusercontent.com/khaveesh/macOS-stdc.h/refs/heads/master/stdc%2B%2B.h)。

## End

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/152164818)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/27/Other-MacOS-ClangUsingBits_stdcpp_h/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)