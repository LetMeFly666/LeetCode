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

`pmset` 不支持按索引取消单条计划，只能 `cancelall` 全部清除。要“取消某一条”，思路是先 cancelall，再把想保留的重新添加：

```bash
sudo pmset schedule cancelall
sudo pmset schedule sleep "04/20/2026 02:00:00"   # 重新添加想保留的
sudo pmset schedule wake "04/20/2026 08:00:00"
```

**方式二：指定相对时间（N 分钟后）**

macOS 的 `shutdown` 命令没有 `-s`（sleep）选项，只能关机/重启。要用相对时间触发睡眠，可以让 `date` 算出绝对时刻再传给 `pmset`：

```bash
sudo pmset schedule sleep "$(date -v+60M '+%m/%d/%Y %H:%M:%S')"
```

`-v+60M` 表示当前时间加 60 分钟，改数字即可调整。

> **注意**：网上常见的 `(sleep 3600 && sudo pmset sleepnow) &` 方案有坑——`sudo` 凭据默认 5 分钟过期，后台进程又没有 tty 交互输入密码，等 sleep 结束后 `sudo` 会直接报错，根本不会睡眠。所以**相对时间睡眠推荐用 `date` + `pmset schedule` 方式**。

**对比**：

| 方式 | 优点 | 缺点 |
|---|---|---|
| `pmset schedule sleep "日期"` | 精确到时刻，系统级调度 | 日期格式需手动拼 |
| `pmset schedule sleep "$(date ...)"` | 支持相对时间，自动算时刻 | 命令稍长 |

**立即睡眠**：`sudo pmset sleepnow`

## AI 工程实践

### AI Bot 稳定 Diff 修改方案：单 Hunk + 预读 + 单 Commit

让 AI bot 从零生成一个完整文件很容易，但让它对已有文件做增量修改就很容易翻车——乱改、截断、重复、错位，各种幺蛾子。经过 9 轮实验（详见 [PR #1523](https://github.com/LetMeFly666/LeetCode/pull/1523) 和[完整博文](https://blog.letmefly.xyz/2026/04/19/Other-AI-BotDiffStrategies/)），找到了一个 100% 稳定的方案。

**核心结论**：每次只改一处，改完确认再改下一处。

```
流程：
1. 通过 api.github.com 获取最新文件内容（不走 CDN）
2. 确定修改位置（行号 + 上下文）
3. 生成单 hunk 的 unified diff
4. 提交 commit
5. 需要多处修改？重复 1-4
```

**实验数据**：

| 策略 | 成功率 | 问题 |
|---|---|---|
| Multi-hunk / 1 commit | 0/3 ❌ | 第一个 hunk 改了行数，后面 hunk 行号全错 |
| Multi-hunk + 预读 / 1 commit | 1/3 ⚠️ | patch 按序应用，后续 hunk 仍然受偏移影响 |
| **单 hunk / 单 commit** | **11/11 ✅** | **无失败**（含函数移动、批量替换、值交换、回退） |

**三个关键踩坑点**：

1. **Multi-hunk 不可靠**：unified diff 里放多个 `@@` hunk 时，第一个 hunk 如果插入/删除了行，后面 hunk 的行号就废了。即使你基于最新文件计算行号也没用——因为 patch 工具是按序应用的，第一个 hunk apply 后文件行数已经变了。

2. **`raw.githubusercontent.com` 有 CDN 缓存**：commit 后立刻读 raw URL 可能拿到旧版本。必须用 `api.github.com/repos/{owner}/{repo}/contents/{path}?ref={branch}` 获取最新内容。

3. **上下文行必须从 API 逐字复制**：diff 里的上下文行（不带 `+`/`-` 的行）必须和文件内容一字不差，不能凭记忆写。一个空格、一个标点的偏差都可能导致 patch 定位失败或应用到错误位置。

**为什么不直接用全量输出（Mode 2）？**

小文件可以，但大文件（>100行）有三个致命问题：
- Token 消耗大：500 行文件每次改都要输出 500 行
- 截断风险：超过模型输出窗口直接丢内容
- 模糊截断：LLM 生成长文本时可能无意识省略重复段落

**方案的本质**：消除不确定性。
- 单 hunk = 不算 hunk 间行偏移
- 预读文件 = 不靠"记忆"靠实际数据
- 每次 commit 后重读 = 下一次修改基于最新状态

多几次 API 调用和 commit，换来 100% 成功率，完全值得。

---

*本文由AI大模型维护，持续更新中。最近更新时间：2026-04-19*

> 同步发文于我的[个人博客](https://blog.letmefly.xyz/)，(AI)创作不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/16/Other-AI-LLM_Maintained_TechNotes/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
