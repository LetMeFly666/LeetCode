---
title: Github - 记录一次向字节跳动CloudWeGo文档贡献的commit
date: 2025-02-14 17:52:28
tags: [其他, Github, Git, 开源项目贡献, PR]
---

# Github - 记录一次向字节跳动CloudWeGo文档贡献的commit

## 前言

和好朋友们做[项目](https://github.com/LetMeFly666/douyinec)时学习`Kitex`看`cloudwego`文档，发现文档中有注释未对齐：

![文档中有注释未对齐.png](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/f2aa89233fa54acc972217149887b82f.png)

~~有点强迫症(bushi)~~于是想着给文档项目提个PR。

## 过程

按正常流程：提[issue](https://github.com/cloudwego/cloudwego.github.io/issues/1241)，Fork了该项目，clone到本地，新建[分支](https://github.com/LetMeFly666/cloudwego.github.io/tree/ltf/docs.fix)，修改并[commit](https://github.com/LetMeFly666/cloudwego.github.io/commit/55c457b6de2877aab71f3e2fa87c77a04f606a67)，提[PR](https://github.com/cloudwego/cloudwego.github.io/pull/1242)，签署`CLA`协议，等待Approve和merge。

其实两周前(2025.1.30 8:34)就想提了，今天终于实行了[当时想干的](https://github.com/LetMeFly666/LeetCode/blob/bbc0d6f781085acc1a9acf7c490834f18179164b/tryGoPy/Go/douyinec/README.md?plain=1#L37)。

## ToSay

虽然提的是一个小更改，但是：

字节Cloudwego文档项目反馈真的好及时！提了一个issue，十几分钟就收到了回复，几十分钟就`CR`通过，并且merge了！点赞👍

现在中英文这里的注释都对齐了：

[对齐了.png](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/f2aa89233fa54acc972217149887b82f.png)

## 附一些Github的谜之缩写

本次PR和issue全程参考其他已merge的PR或issue进行，其间看到了Approve时留下的message`LGTM`，搜了一下后发现了一些Github的谜之缩写。

| 缩写 | 全称 | 含义 |
|------|------|------|
| PR   | Pull Request | 拉取请求，给其他项目提交代码 |
| LGTM | Looks Good To Me | 朕知道了，代码已经过 review，可以合并 |
| SGTM | Sounds Good To Me | 和 LGTM 意思差不多，也是已经通过了 review 的意思 |
| WIP  | Work In Progress | 传说中提 PR 的最佳实践是，如果你有个改动很大的 PR，可以在写了一部分的情况下先提交，但是在标题里写上 WIP，以告诉项目维护者这个功能还未完成，方便维护者提前 review 部分提交的代码 |
| PTAL | Please Take A Look | 你来瞅瞅？用来提示别人来看一下 |
| TBR  | To Be Reviewed | 提示维护者进行 review |
| TL;DR | Too Long; Didn't Read | 太长懒得看。也有很多文档在做简略描述之前会写这么一句 |
| TBD  | To Be Done (or Defined/Discussed/Decided/Determined) | 根据语境不同意义有所区别，但一般都是还没搞定的意思 |

缩写来源：[CSDN@misayaaaaa](https://blog.csdn.net/misayaaaaa/article/details/102684348)

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145639175)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/14/Other-Github-Record1Contribution2BytedanceCloudwegoDocs/)哦~
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/14/Other-Github-Record1Contribution2BytedanceCloudwegoDocs/](https://blog.letmefly.xyz/2025/02/14/Other-Github-Record1Contribution2BytedanceCloudwegoDocs/)
