---
title: Github - 记录一次对“不小心包含了密码的PR”的修复
date: 2025-02-06 11:09:47
tags: [其他, Git, Github]
---

# Github - 记录一次对“不小心包含了密码的PR”的修复

## 前言

和好朋友一起开发一个字节跳动青训营[抖音电商后端(now ![仓库是否公开图](https://api.letmefly.xyz/github/public/?user=LetMeFly666&repo=douyinec))](https://github.com/LetMeFly666/douyinec)的项目，某大佬不小心把本地一密码commit上去并提了PR。


PR一旦发出则无法被删除，且其包含的commit也能被所有能看到这个仓库的人看到。虽然是本地一密码，泄露了也不是很严重，但最好还是隐藏一下这个信息。

## 思路

思路为：

1. [强制重写本次PR的commits](#强制重写本次pr的commits)
2. [删除评论、Action等所有可能带有“密码泄露sha”的记录](#删除密码泄露sha的出现位置)
3. [加强安全防范](#加强安全防范)

其他人无法得知密码泄露的那次commit的sha，也就无法找到泄露的密码。

## 实操

### 强制重写本次PR的commits

其实PR中包含“密码commit”不用惊慌，重写包含密码commit的源分支，与协作者沟通并强制push即可。

但是由于误操等原因，PR被close并且源分支被删除了。于是思路变成了：`恢复源分支` -> `重新打开PR` -> `强制重写源分支`。

这里需要补充一丢丢Github PR的知识：

> Pull Request(PR)通常是开发者想将一个分支(源分支)合并到另一个分支(目标分支)从而提交的更改请求。
> 
> `a`分支对`b`分支的PR在同一时间只能存在一个(关闭的PR除外)，提出PR后合并之前任何对`a`分支的更改都将同步反映到PR上，直到PR被合并或关闭为止。
> 
> 一个PR被强制关闭后，想要重新打开的前提是`a`分支依然存在并且还是提PR时候的`a`分支（另创分支并起名为`a`、被关闭PR中的commit强制重写过的`a`分支不算）。

问题是远端(Github)`a`分支被删除了，还没拉取到本地过，还能恢复这个`a`分支到`PR`关闭时的状态（或在此状态上新增了commit的状态）吗？当然可以，这就是Git：

```bash
git fetch origin pull/<PR编号>/head:<分支名>
git switch <分支名>
```

之后就可以push到远端，重新开启PR，本地回滚，隐匿密码，重新commit，强制push到远端，关闭PR并删除远端分支(可选)了。

```bash
git push --set-upstream origin <分支名>
gh pr reopen 30
git reset HEAD^
vim config.toml
git add xxx
git commit -s -m "xxx"
git push --force
gh pr close 30 -c "历史已重写"
git push origin --delete <分支名>
```

### 删除“密码泄露sha”的出现位置

虽然带有密码的commit被删除了，不会被合并到各个分支中了，变成了“游离”的commit。

但是其他人知道这个commit的sha的话，还是能够[访问](https://github.com/LetMeFly666/douyinec/commit/xxxxxx_commitHash_sha)。

也许Github服务器上什么时候会在`git gc`的时候清除这个commit，但暂未寻找相关文档，是否会发生以及发生具体时间不详。

但是所幸，commit的message以及action的记录都是可以强制删除的，注意GitGuardian等即使修改了历史评论，但github上仍然可以看到历史评论，记得删除历史评论。

### 加强安全防范

最好的办法就是在本地仓库创建一个预提交的[钩子](https://github.com/pre-commit/pre-commit)，但是需要每个Collaborator自己在本地分别安装，最少也要执行一下`git config --local core.hooksPath xxx钩子文件`命令。

然后提交的时候最好不要`git add .`或`git add *`之类的，最好一个一个看看。

其次就是使用一些密码泄露检测工具，放在[文章结尾](#end)部分了。

好用的密码泄露检测工具可以一旦密码泄露立即报警，若不慎泄露则需要**和其他成员沟通并**强制push，必要的话可能需要更改密码。

## End

推荐一个第三方秘密检测工具[GitGuardian](https://github.com/apps/gitguardian)，检测功能强大，能根据代码语境检测。

自荐一个简单的密码检测Bot[Let Secret Monitor](https://github.com/marketplace/actions/let-secret-monitor)，支持自定义密钥信息，普通的commit在push后也会触发检测。

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/06/Other-Github-PrCredentialLeakFix/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145469338](https://letmefly.blog.csdn.net/article/details/145469338)
