---
title: HTML - 在网页上显示mermaid流程图（使用纯js在网页上显示mermaid流程图）
date: 2023-06-29 21:31:14
tags: [其他, HTML, mermaid]
---

# HTML - 在网页上显示mermaid流程图（使用纯js在网页上显示mermaid流程图）

本文讲解如何使用纯JS在HTML中渲染mermaid流程图。

## 前言

首次使用纯JS渲染mermaid公式是在编译原理课的程序设计正则表达式转DFA的可视化上。（[Re2DFA](https://re2dfs.letmefly.xyz)）

由于美化博客时想要能支持mermaid，故特地再次使用了mermaidjs，并记录了使用方法，以供下次使用。

## 官方使用方法（大陆无法访问）

mermaid的官网是[mermaid.js.org](https://mermaid.js.org/)，其Github项目地址为[mermaid-js/mermaid](https://github.com/mermaid-js/mermaid)。

其使用方法很简单，不需要预备的js代码，只需要单独地调用一个mermaid-js库即可。

调用完成后，mermaid-js将会默认将HTML页面中```class```为```mermaid```的标签渲染为mermaid流程图。

```html
<span class='mermaid'>
graph LR
Box1["Hi"] --> BoxHaha["Haha"]
</span>
<script src="https://cdn.jsdelivr.net/npm/mermaid@10.2.3/dist/mermaid.min.js"></script>
```

怎么获取最新版的mermaidjs地址呢？最新版的mermaidjs地址可以在```https://www.jsdelivr.com/package/npm/mermaid```获取。

使用效果：

```mermaid
graph LR
Box1["中文"] --> BoxHaha["Haha"]
```

## 大陆可用的使用方法

由于某些滥用的原因，jsdelivr在大陆无法访问。

因此必须借助其他js源，或者将mermaid所需代码等下载至本地。

[笔者](https://letmefly.xyz)为此提供了一个大陆的可用服务，使用笔者提供的```https://letmefly.xyz/Links/mermaid.min.js```能够正常使用mermaid。

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/06/29/Other-HTML-RenderMermaidByMermaidJS/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131464925](https://letmefly.blog.csdn.net/article/details/131464925)
