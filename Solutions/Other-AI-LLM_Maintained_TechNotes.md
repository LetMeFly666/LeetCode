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

## 数据格式

### JSONL（JSON Lines）

JSONL（也叫 NDJSON）是一种文本格式：每一行是一个独立的合法 JSON 对象，行与行之间用 `\n` 分隔。
## 大模型

### MoE（Mixture of Experts，混合专家）

一句话理解：一个大模型里塞了好多个"专家"小网络，每次来一个 token，只挑其中几个专家上场干活，剩下的专家全都摸鱼。所以**总参数可以很大，但每次推理只用其中一小部分**——又大又快，鱼和熊掌都想要。

**它长什么样**

在标准 Transformer 里，每层的 FFN（前馈网络）是一整块稠密的大矩阵。MoE 做的事就是把这一块 FFN 拆成 N 个并列的小 FFN（叫 Experts），前面加一个叫 Router（路由器 / 门控）的小网络来决定"这个 token 该交给谁处理"。

```
         ┌──────── Expert 1 ────────┐
 token → Router  ──► (选 Top-K)  ──►│ Expert 2（被选中，参与计算）
         └──────── Expert 3 ────────┘
                   ...
                   Expert N（未被选中，不激活）
```

常见做法是 **Top-2 路由**：每个 token 走得分最高的 2 个专家，输出按门控权重加权求和。

**几个关键概念**

| 概念 | 说明 |
|---|---|
| 总参数量 | 所有专家加起来的参数，模型"有多大" |
| 激活参数量 | 实际参与本次前向计算的参数，决定"跑多快" |
| Top-K | 每个 token 选几个专家，常见 K=1 或 K=2 |
| 负载均衡损失 | 额外加的 loss，防止所有 token 都挤到同一个专家那里（专家坍缩） |
| 共享专家 | DeepSeek 等模型的设计：留一两个"总是激活"的专家学通用知识 |

举个直观的数字：Mixtral 8x7B 有 8 个专家、每次选 2 个，总参数约 47B，但每个 token 实际只激活约 13B——推理成本接近一个 13B 的稠密模型，效果却能打到 70B 级别。

**为什么它香**

- **Scaling 更划算**：同样算力预算下，MoE 能塞进更多参数容量，学到更多知识
- **推理更便宜**：参数多但激活少，显存够的前提下速度接近小模型
- **专家分工**：不同专家会自发专精不同领域（代码 / 数学 / 自然语言 ...），有点像一个团队

**为什么它也难搞**

- **显存吃紧**：虽然激活少，但所有专家都得加载进显存，部署门槛并不低
- **通信开销大**：分布式训练时 token 要被路由到不同 GPU 上的专家，All-to-All 通信很贵
- **训练不稳定**：Router 容易学偏，专家负载不均，得靠 balance loss 小心调教
- **小 batch 表现差**：batch 太小时，专家利用率低，优势发挥不出来

**代表玩家**

- **GShard / Switch Transformer**（Google）：MoE 在大模型里的早期代表作
- **Mixtral 8x7B / 8x22B**（Mistral）：第一个让大家都能本地跑的开源 MoE
- **DeepSeek-V2 / V3**：细粒度专家 + 共享专家的创新设计，激活比例压得很低
- **Qwen MoE 系列、Llama 4（Scout / Maverick）**：国内外大厂纷纷跟进

一句话总结：Dense 模型是"全员加班"，MoE 是"按需派单"——在同等效果下，后者更省电；在同等算力下，后者能学更多。未来相当长一段时间，大模型往更大规模扩展时，MoE 几乎是绕不开的一条路。


```jsonl
*本文由AI大模型维护，持续更新中。最近更新时间：2026-04-24*
{"name": "Bob", "age": 25}
{"name": "Charlie", "age": 35}
```

文件扩展名通常为 `.jsonl` 或 `.ndjson`。

**与标准 JSON 的核心区别**：

| 维度 | JSON | JSONL |
|---|---|---|
| 结构 | 单个 JSON 值（通常是数组/对象） | 每行一个独立 JSON 对象 |
| 解析 | 需整体解析 | 可逐行解析 |
| 追加写入 | 困难（需维护闭合括号） | 直接 append 一行 |
| 内存占用 | 与文件大小成正比 | 可流式处理，常数级内存 |

**典型使用场景**：

- **机器学习训练数据**：OpenAI fine-tuning 数据集要求 JSONL 格式（每行一个 `{"messages": [...]}` 对象）
- **日志收集**：每条日志一行 JSON，方便 `grep`、`jq`、`tail -f` 实时处理
- **数据管道 / ETL**：Spark、BigQuery 等都原生支持 JSONL 导入导出
- **流式传输**：生产者不断 append 行，消费者逐行读取，天然适合管道和消息队列场景

用 `jq` 处理 JSONL 非常方便：

```bash
# 提取所有 name 字段
cat data.jsonl | jq -r '.name'
# 过滤 age > 28 的记录
cat data.jsonl | jq 'select(.age > 28)'
```

---

*本文由AI大模型维护，持续更新中。最近更新时间：2026-04-23*

> 同步发文于我的[个人博客](https://blog.letmefly.xyz/)，(AI)创作不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/16/Other-AI-LLM_Maintained_TechNotes/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
