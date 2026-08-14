---
title: Codex：通过编辑配置文件添加带Bearer的自定义MCP
date: 2026-08-14 22:06:39
tags: [Agent, MCP, LLM, AI, Codex, 逆向]
categories: [技术思考]
---

# Codex：通过编辑配置文件添加带Bearer的自定义MCP

## 背景

> MCP像大模型的USB协议一样可以让Agent借此与万物交互。

笔者服务器上有一个Vibe Coding的24h运行的MCP(由于是公网服务器所以带鉴权)，研究了下怎么通过配置文件给Codex添加上这个MCP。

## 图形化界面配置

先讲讲通过图形化界面配置，理解之后讲解通过配置文件配置会容易些。

![Codex添加自定义MCP服务器-通过图形界面](https://files.letmefly.xyz/d/n/Codex%E6%B7%BB%E5%8A%A0%E8%87%AA%E5%AE%9A%E4%B9%89MCP%E6%9C%8D%E5%8A%A1%E5%99%A8-%E9%80%9A%E8%BF%87%E5%9B%BE%E5%BD%A2%E7%95%8C%E9%9D%A2.jpg)

1. `⌘+,`/`Ctrl+,`打开设置
1. 选择`插件`
1. 点击`MCP`
1. 点击`添加/添加MCP服务器`
1. 输入`MCP服务器地址`
1. 输入`Bearer令牌环境变量`
1. 如果你的MCP服务还需要一些header，则可在此输入
1. 和7. 的不同之处在于8. 这里类似6. ，不是直接输入值，而是输入的环境变量名

所谓环境变量名是什么呢？就是Bearer令牌或者一些敏感的header值不应该直接写在配置文件里，而是通过环境变量的方式传入，这样可以一定程度上避免敏感信息泄露。

那么`环境变量`是怎么设置的呢？在`~/.codex/.env`里面输入就可以了。（如果没有这个文件则新建一个就好）：

```
LETMEFLY_MCP_TOKEN="your_bearer_token_here_123456abc"
```

## 全部通过配置文件配置

了解如何配置文件而非图形化界面配置的好处在于，知道了如何通过配置文件配置，就能通过其他脚本来自定义管理MCP工具了。

其实也很简单，修改`~/.codex/config.toml`，新增如下内容即可：

```toml
[mcp_servers.demo]
enabled = true
url = "https://mcp-demo.letmefly.xyz/mcp"
bearer_token_env_var = "LETEFLY_MCP_TOKEN"

[mcp_servers.demo.http_headers]
de = "o"

[mcp_servers.demo.env_http_headers]
demo = "DEO_HEADER"
```

## 永久允许Agent访问MCP的工具`tool1`

修改`~/.codex/config.toml`，新增：

```toml
[mcp_servers.demo.tools.tool1]
approval_mode = "approve"
```

## The End

<center><font size="6px" face="Ink Free">The End, Thanks!</font></center>


> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163763014)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/14/Other-AI-Agent-Codex-Adding1CustomMCPWithBearerByEditingConfigFiles/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
