---
title: Github - 记录一次向字节跳动CloudWeGo文档贡献的commit
date: 2025-02-14 17:52:28
tags: [其他, Github, Git, 开源项目贡献, PR]
categories: [技术思考]
---

# Github - 记录一次向字节跳动CloudWeGo文档贡献的commit

## 前言

和好朋友们做[项目](https://github.com/LetMeFly666/douyinec)时学习`Kitex`看`cloudwego`文档，发现文档中有注释未对齐：

![文档中有注释未对齐.png](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/f2aa89233fa54acc972217149887b82f.png)

~~有点强迫症(bushi)~~ 于是想着给文档项目提个PR。

## 过程

按正常流程：提[issue](https://github.com/cloudwego/cloudwego.github.io/issues/1241)，Fork了该项目，clone到本地，新建[分支](https://github.com/LetMeFly666/cloudwego.github.io/tree/ltf/docs.fix)，修改并[commit](https://github.com/LetMeFly666/cloudwego.github.io/commit/55c457b6de2877aab71f3e2fa87c77a04f606a67)，提[PR](https://github.com/cloudwego/cloudwego.github.io/pull/1242)，签署`CLA`协议，等待Approve和merge。

其实两周前(2025.1.30 8:34)就想提了，今天终于实行了[当时想干的](https://github.com/LetMeFly666/LeetCode/blob/bbc0d6f781085acc1a9acf7c490834f18179164b/tryGoPy/Go/douyinec/README.md?plain=1#L37)。

## ToSay

虽然提的是一个小更改，但是：

字节Cloudwego文档项目反馈真的好及时！提了一个issue，十几分钟就收到了回复，几十分钟就`CR`通过，并且merge了！点赞👍

现在中英文这里的注释都对齐了：

![对齐了.png](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/f389bbdb17b64b0387824a57f97929b4.png)

![成功[贡献](https://web.archive.org/web/20250214102955/https://github.com/cloudwego/cloudwego.github.io)了](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/d6a2cb573acd4deca58a7ffc6dba1fec.png)

## 附一些Github的谜之缩写（黑话）

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

我的一些其他贡献（记录在册）：

|类型|时间|备注|结果|
|:--:|:--:|:--:|:--:|
|[PowerShell/PSReadLine#2655(issue)](https://github.com/PowerShell/PSReadLine/issues/2655)|2021.7.7|Powershell bug report|Duplicated|
|[yanhaijing/linklink#1(issue)](https://github.com/yanhaijing/linklink/issues/1)|2021.8.10|demo链接无法正常访问|Completed(after 2 years)|
|[spln13/DatabasesForTrainin#3(pr)](https://github.com/spln13/DatabasesForTrainin/pull/3)<br/>[spln13/DatabasesForTrainin#4(pr)](https://github.com/spln13/DatabasesForTrainin/pull/4)<br/>[spln13/DatabasesForTrainin#5(pr)](https://github.com/spln13/DatabasesForTrainin/pull/5)|2021.11.5|修改课程配套数据库|Merged|
|[youngyangyang04/leetcode-master#1134(pr)](https://github.com/youngyangyang04/leetcode-master/pull/1134)<br/>[youngyangyang04/leetcode-master#1135(pr)](https://github.com/youngyangyang04/leetcode-master/pull/1135)|2022.3.3|添加0564题C++版本的题解|Closed(不接受新题解)|
|[pcottle/learnGitBranching#942(pr)](https://github.com/pcottle/learnGitBranching/pull/942)<br/>[pcottle/learnGitBranching#945(pr)](https://github.com/pcottle/learnGitBranching/pull/945)|2022.3.3|中文版url中添加参数|Closed但意见采纳了|
|[youngyangyang04/leetcode-master#1145(pr)](https://github.com/youngyangyang04/leetcode-master/pull/1145)|2022.3.6|添加2100题C++版本的题解|Closed(不接受新题解)|
|[youngyangyang04/leetcode-master#1228(pr)](https://github.com/youngyangyang04/leetcode-master/pull/1228)|2022.4.10|删除代码随想录的.DS_Store|Merged|
|[LeetCode-Feedback/LeetCode-Feedback#7143(pr)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/pull/7143)|2022.4.29|中文版Readme+中文力扣站域名更新|Merged|
|[justinmeister/Mario-Level-1#45(pr)](https://github.com/justinmeister/Mario-Level-1/pull/45)|2022.4.30|马里奥单文件版|Opening|
|[LeetCode-Feedback/LeetCode-Feedback#7420(issue)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/7420)|2022.5.25|中文版题目歧义+多一个句号|Completed|
|[LeetCode-Feedback/LeetCode-Feedback#7434(issue)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/7434)|2022.5.26|中文版题目添加“何为不能相互攻击”的描述|Completed|
|[LeetCode-Feedback/LeetCode-Feedback#7827(issue)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/7827)|2022.6.19|中文版题目描述有歧义|Completed|
|[LeetCode-Feedback/LeetCode-Feedback#8217(issue)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/8217)|2022.7.16|力扣中文版题目带大陆无法访问的`wiki`|Completed|
|[Balashov1337/edf2ascii#1(pr)](https://github.com/Balashov1337/edf2ascii/pull/1)|2022.7.26|fix: c++`%d`写成了`%c`|Opening|
|[LeetCode-Feedback/LeetCode-Feedback#8816(issue)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/8816)|2022.8.27|存在错误测试用例|Closed|
|[LeetCode-Feedback/LeetCode-Feedback#9736(issue)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/9736)|2022.10.4|新版UI无法渲染`sqrt`|Completed|
|[LeetCode-Feedback/LeetCode-Feedback#9820(issue)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/9820)|2022.10.10|题目英译中错误|Completed|
|[LeetCode-Feedback/LeetCode-Feedback#12523(issue)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/12523)|2023.3.23|缺少特殊测试用例|Self-closed|
|[LeetCode-Feedback/LeetCode-Feedback#41001(issue)](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/41001)|2026.10.27|数据范围描述存在多余空格|Opening|
|[liuyong0076/ACMER#1(pr)](https://github.com/liuyong0076/ACMER/pull/1)|2023.7.5|fix: django导入app的数据库|Opening|
|[kahakaha/bupt-kb-helper#3(pr)](https://github.com/kahakaha/bupt-kb-helper/pull/3)|2023.9.13|fix: 课程名为汉字时无法匹配|Merged|
|[lin594/code-contributing-practice#142(issue)](https://github.com/lin594/code-contributing-practice/issues/142)<br/>[lin594/code-contributing-practice#143(pr)](https://github.com/lin594/code-contributing-practice/pr/143)|2023.10.9|代码仓库正常练习|Merged|
|[lin594/code-contributing-practice#144(issue)](https://github.com/lin594/code-contributing-practice/issues/144)<br/>[lin594/code-contributing-practice#145(pr)](https://github.com/lin594/code-contributing-practice/pr/145)|2023.10.9|代码仓库正常练习|Merged|
|[BUCT-Alumni/BUCT-Alumni#3(pr)](https://github.com/BUCT-Alumni/BUCT-Alumni/pull/3)|2023.10.12|校友群添加信息|Merged|
|[BUCT-Alumni/BUCT-Alumni#5(issue)](https://github.com/BUCT-Alumni/BUCT-Alumni/issues/5)<br/>[BUCT-Alumni/BUCT-Alumni#6(pr)](https://github.com/BUCT-Alumni/BUCT-Alumni/pull/6)|2023.10.12|删除个人链接中无用参数|Merged|
|[BUCT-Alumni/BUCT-Alumni#10(issue)](https://github.com/BUCT-Alumni/BUCT-Alumni/issues/10)<br/>[BUCT-Alumni/BUCT-Alumni#11(pr)](https://github.com/BUCT-Alumni/BUCT-Alumni/pull/11)|2023.10.19|新增贡献项目墙|Merged|
|[Afool4U/xingchenjiaoyu#1(issue)](https://github.com/Afool4U/xingchenjiaoyu/issues/1)|2023.11.15|双引号写反了|Completed|
|[phohenecker/switch-cuda#3(issue)](https://github.com/phohenecker/switch-cuda/issues/3)|2024.5.7|Bug-zsh环境下无法运行（带解决方案）|Opening|
|[cloudwego/cloudwego.github.io#1241(issue)](https://github.com/cloudwego/cloudwego.github.io/issues/1241)<br/>[cloudwego/cloudwego.github.io#1242(pr)](https://github.com/cloudwego/cloudwego.github.io/pull/1242)|2025.2.14|文档格式小改|Merged|
|[cloudwego/cloudwego.github.io#1244(issue)](https://github.com/cloudwego/cloudwego.github.io/issues/1244)<br/>[cloudwego/cloudwego.github.io#1245(pr)](https://github.com/cloudwego/cloudwego.github.io/pull/1245)|2025.2.17|文档格式小改|Merged|

Github贡献👆

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145639175)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/14/Other-Github-Record1Contribution2BytedanceCloudwegoDocs/)哦~
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/14/Other-Github-Record1Contribution2BytedanceCloudwegoDocs/](https://blog.letmefly.xyz/2025/02/14/Other-Github-Record1Contribution2BytedanceCloudwegoDocs/)
