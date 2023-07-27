---
title: HTML - 在网页上显示Latex公式（使用纯js在网页上显示Latex公式）
date: 2023-06-29 19:39:42
tags: [其他, HTML, MathJax, Latex, Hexo]
---

# HTML - 在网页上显示Latex公式（使用纯js在网页上显示Latex公式）

本文讲解如何使用纯JS在HTML中渲染latex公式。

## 前言

Hexo对公式的支持有点小小的<sub>一言难尽</sub>，尤其是对带有中文的公式的支持程度不是很高。并且很多人（包括我）尝试了很多次都没能完美适配。最终，决定不使用hexo渲染，而是直接将公式源码返回到前端，在前端使用JS进行渲染。

## 官方使用方法（大陆无法访问）

MathJax的官网是[mathjax.org](https://www.mathjax.org/)，在Github的地址为[mathjax/MathJax](https://github.com/mathjax/MathJax)。

使用起来很简单，只需要在HTML页面中加入如下代码

```html
<script>
    window.MathJax = { tex: { inlineMath: [['$', '$'], ['\\(', '\\)']], }, chtml: { scale: 0.8 }};
</script>
<script src='https://cdn.jsdelivr.net/npm/mathjax@3.0.1/es5/tex-mml-chtml.js'></script>
```

即可。当网页加载好后，```$```之间以及```\(```之间的内容将被作为公式渲染。

## 大陆可用的使用方法

由于某些滥用的原因，jsdelivr在大陆无法访问。

因此必须借助其他js源，或者将mathjax所需代码字体等下载至本地。

[笔者](https://letmefly.xyz)为此提供了一个大陆的不完全服务，使用笔者提供的```https://letmefly.xyz/Links/JS/MathJax/tex-mml-chtml.js```能够正常使用mathjax的大部分功能。

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/06/29/Other-HTML-RenderLatexByMathJaxJS)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131464796](https://letmefly.blog.csdn.net/article/details/131464796)
