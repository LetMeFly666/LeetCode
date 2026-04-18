---
title: AI维护的技术随笔 - 由大模型持续更新的技术笔记
date: 2026-04-16 13:00:00
tags: [其他, AI, 技术随笔]
categories: [技术思考, AI]
---

> AI创作声明：以下内容由大模型(Claude)生成并持续维护更新。

# AI维护的技术随笔 - 由大模型持续更新的技术笔记

这是一篇特殊的文章——它由AI大模型创作并持续维护更新。每当有新的技术知识值得记录时，AI会在这里添加新的内容。

## Skill

### 微信支付 AI Skill：给 IDE 中的 LLM 用的结构化知识包

微信支付官方推出了 [wechatpay-skills](https://github.com/wechatpay-apiv3/wechatpay-skills) 仓库，将支付接入的领域知识以 **Cursor Custom Skills** 格式打包（`SKILL.md` + `references/` 目录），放到 AI IDE 的 Skill 配置目录下即可使用。

> 一句话总结：这个 Skill 不是让 AI 替你付款，而是教 AI 怎么写出正确的支付接入代码。

核心思路：不让 LLM 自由发挥写支付代码，而是让它从预先编写验证过的知识库中检索正确答案。代码示例（Java/Go）由微信支付团队预先编写并验证，LLM 只负责根据用户场景选对代码片段返回。

提供 5 个能力：

| 能力 | 说明 |
|---|---|
| 支付方式选型 | 根据业务场景（App/微信内/浏览器/PC）匹配 JSAPI、APP、H5、Native、小程序、付款码、合单支付 |
| 示例代码检索 | 检索仓库中预写的代码示例，非 AI 实时生成 |
| 业务知识速查 | APPID 绑定、订单状态流转、退款规则等 |
| 接入质量评估 | 上线前检查签名验签、回调处理、必接接口 |
| 接口排障 | 提供 Request-Id 自动匹配错误码和排查方案 |

接入方式（以 Cursor 为例）：

```bash
npx skills add https://github.com/wechatpay-apiv3/wechatpay-skills --yes
```

或手动将 Skill 目录复制到 `.cursor/skills/` 下。这种「结构化知识包 > 纯 prompt」的模式值得关注——本质上是 API 提供方主动为 AI 编程场景适配知识格式，比开发者自己写 system prompt 靠谱得多。

## Mac

### 命令行设置定时睡眠（pmset）

Mac 可以通过命令行设置定时睡眠，核心工具是 `pmset`。

**方式一：指定绝对时刻**

```bash
sudo pmset schedule sleep "MM/DD/YYYY HH:MM:SS"
```

例如设置 2026 年 4 月 19 日凌晨 1:00 睡眠：

```bash
sudo pmset schedule sleep "04/19/2026 01:00:00"
```

查看已设置的定时计划：

```bash
pmset -g sched
```

取消所有定时计划：

```bash
sudo pmset schedule cancelall
```

**方式二：指定相对时间（N 分钟后）**

macOS 的 `shutdown` 命令没有 `-s`（sleep）选项，只能关机/重启。要用相对时间触发睡眠，可以让 `date` 算出绝对时刻再传给 `pmset`：

```bash
sudo pmset schedule sleep "$(date -v+60M '+%m/%d/%Y %H:%M:%S')"
```

`-v+60M` 表示当前时间加 60 分钟，改数字即可调整。

或者更直接——后台延时后执行 `sleepnow`：

```bash
(sleep 3600 && sudo pmset sleepnow) &
```

`3600` 是秒数（60 分钟 = 3600 秒）。

**对比**：

| 方式 | 优点 | 缺点 |
|---|---|---|
| `pmset schedule sleep "日期"` | 精确到时刻，系统级调度 | 日期格式需手动拼 |
| `pmset schedule sleep "$(date ...)"` | 支持相对时间，自动算时刻 | 命令稍长 |
| `sleep N && pmset sleepnow` | 最简单直接 | 依赖终端进程存活 |

**立即睡眠**：`sudo pmset sleepnow`

---

*本文由AI大模型维护，持续更新中。最近更新时间：2026-04-19*

> 同步发文于我的[个人博客](https://blog.letmefly.xyz/)，(AI)创作不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/16/Other-AI-LLM_Maintained_TechNotes/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
