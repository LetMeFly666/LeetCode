---
title: VsCode自定义单词分隔符 - 还在为“中文不论多长都会被识别为一句话”而发愁吗？
date: 2024-05-14 21:32:09
tags: [VsCode, 简单]
categories: [技术思考]
---

# VsCode自定义单词分隔符 - 还在为“中文不论多长都会被识别为一句话”而发愁吗？

## 前言

**在VsCode眼中，中文不论多长都是一个单词！**

例如在VsCode中编辑下面两段话：

```
这是一段话(括号是英文括号)
```

```
这是一段话（括号是中文括号）
```

然后分别在上述两段话的括号内部分双击鼠标左键（这样VsCode会自动选中它眼中的一个word），会得到如下结果：

![中英文符号的不同](https://cdn.letmefly.xyz/img/blog/VsCodeCustomeWordSeparators/DifferenceIn_EngAndCN_Character.gif)

<!-- ![中英文符号的不同](https://img-blog.csdnimg.cn/img_convert/616da6f47774ede03149f2934fc8fda2.gif) -->

甚至，我们可以写一段很长的，不包含英文字符的中文：

```
这是一个非常长的句子，没有换行和空格：中文标点在此处被用来区分不同的词组和句子，虽然缺乏空格可能会使阅读变得有些困难，但通过这种方式，我们可以测试对连续文本的解析能力。例如，“这是一个测试句子，它旨在展示如何在没有空格的情况下使用中文标点来组织语言。虽然这看起来有些不同寻常，但它确实是一种挑战，要求我们更加专注于每个字符和它们之间的关系。通过这种方式，我们可以锻炼自己的阅读能力和理解能力，以便更好地适应各种文本格式和排版方式。”这段话通过连续的字符流展示了中文标点的独特作用，尽管没有空格，但读者仍可以通过对中文语境的理解来解读其中的意义。
```

在这段中文的任一位置双击鼠标左键，得到的结果都会是一样的。

![很长的中文也是一个单词](https://cdn.letmefly.xyz/img/blog/VsCodeCustomeWordSeparators/LongLongPureChinese_Is_1word.gif)

<!-- ![很长的中文也是一个单词](https://img-blog.csdnimg.cn/img_convert/b1252f0b0bcb9e9243d68a88960acf59.gif) -->

**有没有办法让VsCode更智能一点呢？比如认识中文符号**

当然有。

## 自定义单词分隔符

打开VsCode，使用快捷键```Ctrl+Shift+P```，在弹出的输入框中```Open User Settings (JSON)```然后```回车```。这样就打开了VsCode的配置文件。

![打开VsCode配置文件](https://cdn.letmefly.xyz/img/blog/VsCodeCustomeWordSeparators/OpenVsCode_Settings.gif)

<!-- ![打开VsCode配置文件](https://img-blog.csdnimg.cn/img_convert/8bfd3726ed0f05783fc3a4cf03eef497.gif) -->

添加如下一行，并保存：

```json
"editor.wordSeparators": "`~!@#$%^&*()-=+[{]}\\|;:'\",.<>/?“”（），。？、：—；",
```

![在Settings.json中添加一行代码.jpg](https://cdn.letmefly.xyz/img/blog/VsCodeCustomeWordSeparators/Add1LineInSettings.json.jpg)

<!-- ![在Settings.json中添加一行代码.jpg](https://img-blog.csdnimg.cn/img_convert/74f422ee6f67153ece5e8f7dc6c64f94.jpeg) -->

任务完成！

这段代码的意思是，单词的分隔符为：````~!@#$%^&*()-=+[{]}\\|;:'\",.<>/?“”（），。？、：—；```。如果你遇到了其他的中文字符，也可以写到这里面。

除了常见的英文分隔符外，后面的```“”（），。？、```是一些中文常见的符号。这样，VsCode在遇到中文括号```（```等时，就会视为单词的分隔符了。这样，刚才那长长的一段话就会变为“看起来不那么笨的样子了”：

![很长的中文不再是一个单词了](https://cdn.letmefly.xyz/img/blog/VsCodeCustomeWordSeparators/LongLongPureChinese_Is_NOT_1word.gif)

<!-- ![很长的中文不再是一个单词了](https://img-blog.csdnimg.cn/img_convert/cc370551a2429a8183638ffa1446e917.gif) -->

## End

+ 参考链接：[stackoverflow：Visual Studio Code—Customizing word separators](https://stackoverflow.com/questions/31632351/visual-studio-code-customizing-word-separators)

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2024/05/14/Other-VsCode-CustomeWordSeparators/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138871269](https://letmefly.blog.csdn.net/article/details/138871269)

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>
