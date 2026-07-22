---
title: Git：自定义merge规则——为追加型 Markdown 单词表实现基于 commit 时间的自动合并规则（AI文）
date: 2026-07-21 18:20:00
tags: [Git]
categories: [技术思考]
description: 对某些特殊文件自定义Git的merge规则
---

# Git：自定义merge规则——为追加型 Markdown 单词表实现基于 commit 时间的自动合并规则（AI文）

> 本文总结[自](https://chatgpt.com/c/6a5f8435-2988-83ea-a577-bf2dc843e881)ChatGPT！ [某分支的ChatLink](https://chatgpt.com/share/6a60c2de-7a4c-83ea-9e07-147aed3d92e3)


## 背景


> Git
> 默认的三方合并适合处理普通文本修改，但对于追加型日志文件（例如单词学习记录），更适合使用基于
> commit history 的自定义 merge driver。

要解决的问题：

仓库中有一个 Markdown 文件：

    Solutions/Other-English-LearningNotes-SomeWords.md

该文件包含：

-   Markdown 元信息
-   一个长期追加的单词表
-   后续其他笔记内容

单词表类似：

    |corrosion|n. 腐蚀；锈蚀|
    |fragrant|adj. 香的|
    |||
    |magnetism|n. 磁性，吸引力/魅力|

其中：

    |||

表示一次新的背单词记录。

由于该文件只追加，不应该使用普通文本 merge。

例如：

分支 A：

    |||
    |1||

分支 B：

    |||
    ||2|

正确结果应该按照 commit 时间：

    |||
    |1||
    |||
    ||2|

而不是依赖 Git 默认 diff merge。

------------------------------------------------------------------------

## 技术原理

### Git merge driver

Git 支持针对特定文件指定 merge driver。

`.gitattributes`：

    Solutions/Other-English-LearningNotes-SomeWords.md merge=words

`.git/config`：

``` ini
[merge "words"]
    name = English words timestamp merge
    driver = python3 merge_words.py %O %A %B
```

参数：

  参数   含义
  ------ ---------------------
  %O     共同祖先文件
  %A     当前 merge 结果文件
  %B     另一个分支文件

------------------------------------------------------------------------

## merge driver 执行流程

``` mermaid
flowchart TD
A[git merge branch] --> B[发现 merge 属性]
B --> C[调用 merge driver]
C --> D[%O ancestor]
C --> E[%A ours]
C --> F[%B theirs]
D --> G[Python脚本]
E --> G
F --> G
G --> H[读取 Git commit history]
H --> I[提取新增记录]
I --> J[按照 commit 时间排序]
J --> K[生成最终文件]
K --> L[写回 %A]
L --> M[完成 merge]
```

------------------------------------------------------------------------

## 为什么不能直接比较三个文件

普通 merge 只能看到：

    ancestor
    ours
    theirs

但是追加日志需要知道：

    commit1
    commit2
    commit3

例如：

    ours:

    1
    3

    theirs:

    2

文件内容无法知道：

    1 < 2 < 3

所以需要：

    git merge-base
    git rev-list
    git show --format=%ct

读取真实提交历史。

------------------------------------------------------------------------

## 核心算法

1.  找共同祖先：

```{=html}
<!-- -->
```
    git merge-base ours theirs

2.  获取两个分支新增 commit：

```{=html}
<!-- -->
```
    git rev-list --reverse base..head

3.  对每个 commit：

```{=html}
<!-- -->
```
    git show --unified=0 commit -- file

提取新增行。

4.  获取时间：

```{=html}
<!-- -->
```
    git show -s --format=%ct commit

5.  排序：

``` python
changes.sort(
    key=lambda x:
        (
            x.timestamp,
            x.commit
        )
)
```

6.  按顺序重新生成单词表。

------------------------------------------------------------------------

## 踩坑记录

### 1. %A 不是原始 ours 文件

错误思路：

    读取 %A
    追加 ours/theirs diff

因为 `%A` 是 Git merge 过程中的目标文件，不一定等于 merge 前的 ours。

正确：

使用 ancestor + commit history 重建。

------------------------------------------------------------------------

### 2. 文件内容不能决定提交顺序

错误：

    比较 ancestor/ours/theirs

无法恢复：

    commit1 -> commit2 -> commit3

必须读取 Git history。

------------------------------------------------------------------------

### 3. Markdown 表格空列

原正则：

``` python
r"^\|[^|]+\|[^|]+\|$"
```

不能匹配：

    |1||
    ||2|

因为存在空 cell。

修改为：

``` python
r"^\|.*\|.*\|$"
```

并特殊处理：

    |||

它是分隔符，不是单词。

------------------------------------------------------------------------

### 4. 不应该删除重复 \|\|\|

两个分支同时新增：

    |||
    |1|

和：

    |||
    |2|

结果应该：

    |||
    |1|
    |||
    |2|

两个 session 都有意义。

------------------------------------------------------------------------

### 5. 插入位置和空行

表格后：

    |magnetism|...|

    其他内容

空行属于表格后的分隔。

新增内容应该插入：

    |magnetism|...|
    |||
    |new|

    其他内容

而不是：

    |magnetism|...|

    |||
    |new|

------------------------------------------------------------------------

## 最终效果

配置：

`.gitattributes`

    Solutions/Other-English-LearningNotes-SomeWords.md merge=words

Git config：

``` ini
[merge "words"]
    name = English words timestamp merge
    driver = python3 merge_words.py %O %A %B
```

之后：

``` bash
git merge other_branch
```

Git 会自动调用脚本。

------------------------------------------------------------------------

## 源码

最终版本 merge_words.py 可放置于：

    merge_words.py

并由 merge driver 调用。

------------------------------------------------------------------------

## 总结

这个方案不是普通文本 merge。

它实际上是：

    Git merge driver
    +
    Git commit history
    +
    append-only log replay

适合：

-   单词学习记录
-   日志文件
-   changelog
-   自动生成 Markdown 列表

核心思想：

> 对追加型数据，不要 merge 最终文本，而应该重新播放两个分支产生的事件。

## The End

<center><font size="6px" face="Ink Free">The End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163084329)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/21/Other-Git-CustomMergingScript/)哦~
> 
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
