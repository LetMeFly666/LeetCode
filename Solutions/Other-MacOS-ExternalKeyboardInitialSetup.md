---
title: MacOS：首次外接键盘初始化设置（Option/Command互换、左上角·～而非§±）
date: 2026-07-03 15:25:21
tags: [VsCode, 简单, Mac, MacOS]
categories: [技术思考]
---

# MacOS：首次外接键盘初始化设置（Option/Command互换、左上角·～而非§±）

## 背景

Mac连接外接键盘可能会遇到以下情况：

+ Mac首次连接外接键盘可能会弹出“键盘设置助理”初始化设置，怎么设置？设置错了怎么办？（Esc下面的键按出来是`§±`而不是``` ~` ```）
+ 一些键盘不支持Mac模式（导致从左到右是`Ctrl、Command/Win、Alt/Option`而非`Ctrl、Option、Command`）

![键盘设置助理](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/c8164caea1764061869d758085ab3e24.png)

## 把`§±`设置成``` ~` ```

这个需要了解ANSI键和ISO键。如图红色部分是二者的区别：

![ANSI和ISO键盘对比图，图源：https://www.typing-fingers.com/zh-TW/keyboard-layout-standards-ansi-vs-iso/](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/dbacdb6f15a447c1a9f0b2d0d9f55c8f.png)
<!-- ![ANSI和ISO键盘对比图，图源：https://www.typing-fingers.com/zh-TW/keyboard-layout-standards-ansi-vs-iso/](https://www.typing-fingers.com/wp-content/uploads/2023/11/iso_ansi.webp) -->

可以发现ISO键盘左边shift键的右边不是z，这也就是为什么刚连接键盘时候Mac让你按下左边shift右边的那个按键。

以及，Tab键上面（1的左边）在ISO键盘中含义是`§±`，而不是现在常用的``` ~` ```。

如果你把你的键盘错选成了ISO，那么你想打``` ~` ```则会得到`§±`。解决方案是重新运行一次“键盘设置助理”，把键盘设置为ANSI键盘。

以MacOS26.5.2为例，“键盘设置助理”的位置是`左上角 -> 系统设置 -> 键盘 -> 更改键盘类型`：

![“键盘设置助理”的位置是`左上角 -> 系统设置 -> 键盘 -> 更改键盘类型`](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/b7dd7744ca994519bbd568e23ee3d3eb.png)

弹出“键盘设置助理”后点击`继续`、`Z`、`/`，选择`ANSI（美国）`、`完成`，可能需要重新拔插一下键盘，再次按下`1`左边打按钮就可以打出``` ~` ```了。

## 把`Ctrl、Command/Win、Alt/Option`设置为`Ctrl、Option、Command`

这个需要在Mac里面更改一下`修饰键`，位置是`左上角 -> 系统设置 -> 键盘 -> 键盘快捷键 -> 修饰键`

![左上角 -> 系统设置 -> 键盘 -> 键盘快捷键](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/943c56e5aba84aad8220c48a5a19b5d9.png)

选择你的外接键盘，替换Command和Option两个修饰键即可。

![更换Command和Option修饰键](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/6b32e8591e824515839e9cbbe803fd8f.png)

这样你按下键盘上的`Alt`就会得到`Command`一样的效果了。

## The End

> 看到ISO这样的Enter突然想起来小时候的键盘了。

<center><font size="6px" face="Ink Free">The End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162551319)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/03/Other-MacOS-ExternalKeyboardInitialSetup/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
