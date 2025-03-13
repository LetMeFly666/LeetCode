---
title: HTML - Hexo - 取消Hexo下划线转义：因为公式中可能会用到大量下划线（Hexo公式）
date: 2023-07-27 17:19:21
tags: [其他, HTML, MathJax, Latex, Hexo, sed]
categories: [技术思考]
---

# HTML - Hexo - 取消Hexo下划线转义：因为公式中可能会用到大量下划线（Hexo公式）

## 为什么取消下划线的转义

公式中可能会用到很多下划线，然而下划线在Markdown中有特殊含义，例如```_a_```代表斜体的```a```。

基于Hexo的渲染原理，Markdown源码首先会被Markdown引擎渲染，之后才会被公式引擎渲染。

因此```$a_i + b_i$```本应被渲染成$a_i + b_i$，但会被Hexo的Markdown引擎渲染成```$a<em>i + b</em>i$```，之后渲染成公式的时候就会很离谱。

所以要取消下划线的转义。

这里不得不吐槽一句，其他支持公式的Markdown编辑器哪个都没有这种错误！

## 如何取消转义

取消转义只需要将```../hexoWorkspace/node_modules/marked/lib/```下的所有文件中的```"<em>" + text + "</em>"```替换为```"_" + text + "_"```即可。

因此在Linux系统上只需要使用```sed```命令（有关sed命令推荐[菜鸟教程-sed](https://www.runoob.com/linux/linux-comm-sed.html)）：

```bash
sed -i 's/"<em>" + text + "<\/em>"/"_" + text + "_"/g' ../hexoWorkspace/node_modules/marked/lib/*
```

## 为什么不使用其他的渲染引擎

为了解决Hexo的公式问题，我尝试了很多渲染引擎。但每个引擎都有其不尽人意的地方。有的不支持行内公式，有的不支持公式中出现中文字符，有的...。

想要渲染公式，一个很不错的思路是[使用强大的MathJax渲染](https://blog.letmefly.xyz/2023/06/29/Other-HTML-RenderLatexByMathJaxJS/)。

正当我以为终于解决了公式问题的时候，我发现Hexo的Markdown渲染引擎会转义很多东西，```$ $```之间的内容也会转义！！！

因此经过多次尝试，终于取消了Hexo对下划线的转义。但是对于公式中的自减运算符```a--```的转义，至今还未能解决！

<center><font size="6px" face="楷体">想让Hexo完美支持公式咋就这么难呢(:cry:)</font></center>

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/27/Other-HTML-Hexo-RemoveTheEscapeOfUnderline/)哦~
> Tisfy：[https://blog.letmefly.xyz/2023/07/27/Other-HTML-Hexo-RemoveTheEscapeOfUnderline/](https://blog.letmefly.xyz/2023/07/27/Other-HTML-Hexo-RemoveTheEscapeOfUnderline/)
