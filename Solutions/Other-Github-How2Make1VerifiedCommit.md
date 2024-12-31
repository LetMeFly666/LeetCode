---
title: Github - 如何提交一个带有“verified”标识的commit
date: 2024-12-28 22:09:55
tags: [其他, Github]
---

# Github - 如何提交一个带有“verified”标识的commit

## 前言(Why)

今天在Github上浏览某项目的commit记录的时候发现，有的commit记录带有<font color="#1a7f7c">verified</font>绿色标识，有的带有橘色的<font color="#9a6700">Unverified</font>标识，还有的什么都不显示。

![verified & Unverified](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/3837fcd7967946978991bd06d7315762.png)

既然我是根正苗红的作者(bushi)，为何不想要一个verified标呢？相关探究随之而来。

## What

这是Github的[“提交签名验证”机制](https://docs.github.com/zh/authentication/managing-commit-signature-verification/about-commit-signature-verification)，可以确保改提交未本人所为。

> 当提交签名在被推送到 GitHub 时经过验证，一个验证记录会与该提交一并存储。 该记录无法编辑且会一直存在，这样一来，即便签名密钥被轮换、撤销，或者参与者离开了组织，签名也能始终保持已验证状态。
> 
> 验证记录包含一个时间戳，用于标记验证完成的时间。 此持久记录可确保已验证状态的一致性，为存储库内的参与提供稳定的历史记录。 可以通过将鼠标悬停在 GitHub 上的“Verified”徽章上，或者通过[REST API](https://docs.github.com/zh/rest/commits/commits)访问提交（其中包含一个 verified_at 字段）来查看此时间戳。

## How

因为SSH密钥对还可以当<span title="验证身份用">Authentication Key</span>，所以这里介绍如何使用SSH密钥对对一次commit签名（~~其实是因为我**暂时**不太了解GPG Key~~）。

假设你已经在默认位置生成过ssh密钥对，则只需在你想提交时签名的仓库执行以下命令（如果你想对所有未进行过相关配置的仓库生效，只需要在`git config`后面加一个`--global`）：

```bash
git config commit.gpgsign true           # 设置commit时使用gpg签名
git config gpg.format ssh                # 设置使用ssh密钥进行签名
git config user.signingkey <ssh公钥路径>  # 配置ssh公钥路径
```

然后将ssh公钥上传到github上。

[Github - SSH and GPG keys](https://github.com/settings/keys) -> `New SSH Key` -> `Key type`选择`Signing Key` -> 输入SSH公钥并保存。

在本地进行一次commit并push到Github，顺利的话，在Commit历史记录中就能看到Verified标了。

## End

但是注意，git版本大于等于2.41才支持上述配置。

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/28/Other-Github-How2Make1VerifiedCommit/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144796175](https://letmefly.blog.csdn.net/article/details/144796175)