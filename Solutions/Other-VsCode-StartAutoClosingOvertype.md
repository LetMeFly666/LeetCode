---
title: VsCode启用右括号自动跳过(自动重写) - 自录制gif演示
date: 2025-03-25 23:37:17
tags: [其他, VsCode]
categories: [技术思考]
index_img: https://cdn.letmefly.xyz/img/blog/VsCode_StartAutoClosingOvertype/skipped_failed.gif
---

# VsCode启用右括号自动跳过(自动重写) - 自录制gif演示

## 前言

不知道大家在编程时候的按键习惯是怎样的。输入完左括号后编辑器一般会自动补全右括号，输入完左括号的内容后，是按`→`跳过右括号还是按`)`跳过右括号呢？

```cpp
for (int i = 0; i < a.si)
                       ↑
                       光标在这里的时候
```

我的习惯是按`)`。这样编辑器(VsCode)不会再输出一个`)`出来变成两个`)`，而是会字节跳过右边的`)`并把光标移动到`)`的后面。

<!-- ![skipped](https://i-blog.csdnimg.cn/direct/34e4163eabf34d8aae206169fcec376f.gif) -->

![skipped](https://cdn.letmefly.xyz/img/blog/VsCode_StartAutoClosingOvertype/skipped.gif)

暂且把不会出现两个`)`的现象称为“右括号自动跳过”，其实它的官方名是`autoClosingOvertype`。

## 让人“火大”的事情出现了

正常情况下行云流水，for循环丝毫不犹豫一气呵成，输入一个`)`完美！

但要是括号里的内容没有一气呵成呢？括号里内容写了一半，去括号外修改了点东西，回来继续写括号里的内容，写完再输入一个`)`，就会发现变成了两个`)`！！！原有的`)`没有被跳过(或重写)！

然后我还需要按delete键把原有的`)`删掉。是可忍，孰不可忍！优化之！

<!-- ![skipped-failed](https://i-blog.csdnimg.cn/direct/4fa2c348425843c3a3f037cc21308366.gif) -->

![skipped-failed](https://cdn.letmefly.xyz/img/blog/VsCode_StartAutoClosingOvertype/skipped_failed.gif)

## 如何解决

`Ctrl + Shift + P`，输入`settings.json`回车，添加一个`"editor.autoClosingOvertype": "always"`就可以了。

或者直接左下角齿轮-设置-搜索`autoClosingOvertype`-修改为`always`也是一样的。

这样，不论鼠标中途到过哪些地方，只要按`)`的时候光标下一个字符是`)`，就会自动跳过之。

<!-- ![skipped-okAgain](https://i-blog.csdnimg.cn/direct/d23ac5841c994ad3add1e709cb4d3b38.gif) -->

![skipped-okAgain](https://cdn.letmefly.xyz/img/blog/VsCode_StartAutoClosingOvertype/skipped_okAgain.gif)

这样，就能任意切光标位置啦：

<!-- ![skipped-always](https://i-blog.csdnimg.cn/direct/58a738569a9f48f496af647142dfbc83.gif) -->

![skipped-always](https://cdn.letmefly.xyz/img/blog/VsCode_StartAutoClosingOvertype/skipped_always.gif)

## 如何选择

假设你有很多的左右括号不匹配的需求，可能出现很多的`()))))`之类的，可以选择将`editor.autoClosingOvertype`设置为`auto`或`never`；

如果像我一样编程较多，几乎`()`都会配对出现，建议修改为`always`。

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146515937)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/25/Other-VsCode-StartAutoClosingOvertype/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
