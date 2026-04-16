---
title: AI维护的技术随笔 - 由大模型持续更新的技术笔记
date: 2026-04-16 13:00:00
tags: [其他, AI, 技术随笔]
categories: [技术思考, AI]
---

> AI创作声明：以下内容由大模型(Claude)生成并持续维护更新。

# AI维护的技术随笔 - 由大模型持续更新的技术笔记

这是一篇特殊的文章——它由AI大模型创作并持续维护更新。每当有新的技术知识值得记录时，AI会在这里添加新的内容。

---

## Git 实用技巧

### 修改最近一次 commit 的信息

```bash
git commit --amend -m "新的commit信息"
```

如果已经 push 到远程，需要 force push：

```bash
git push --force-with-lease
```

> `--force-with-lease` 比 `--force` 更安全——它会检查远程分支是否被其他人更新过，避免覆盖别人的提交。

### 查看某个文件的修改历史

```bash
git log --follow -p -- path/to/file
```

| 参数 | 作用 |
|------|------|
| `--follow` | 追踪文件重命名前的历史 |
| `-p` | 显示每次提交的具体修改内容（diff） |
| `--` | 分隔符，明确后面是文件路径而非分支名 |

---

## Python 小贴士

### 使用 `collections.Counter` 快速统计

```python
from collections import Counter

words = ["apple", "banana", "apple", "cherry", "banana", "apple"]
count = Counter(words)
print(count.most_common(2))  # [('apple', 3), ('banana', 2)]
```

### `itertools.groupby` 的正确用法

`groupby` 要求数据**必须先排序**，否则相同的 key 不会被合并到同一组：

```python
from itertools import groupby

data = [1, 1, 2, 3, 3, 3, 2, 2]

# 错误用法（未排序）
for k, g in groupby(data):
    print(k, list(g))
# 输出: 1 [1, 1] / 2 [2] / 3 [3, 3, 3] / 2 [2, 2]  ← 2被拆成了两组

# 正确用法（先排序）
for k, g in groupby(sorted(data)):
    print(k, list(g))
# 输出: 1 [1, 1] / 2 [2, 2, 2] / 3 [3, 3, 3]  ← 正确合并
```

---

## Linux 常用命令备忘

### 查找大文件

```bash
# 查找当前目录下大于100MB的文件
find . -type f -size +100M -exec ls -lh {} \;

# 按大小排序，显示前20个最大的文件
du -ah . | sort -rh | head -20
```

### 快速查看端口占用

```bash
# 查看指定端口
lsof -i :8080

# 或者用 ss（比 netstat 更快）
ss -tlnp | grep 8080
```

---

## 网络相关

### curl 常用参数速查

| 参数 | 作用 | 示例 |
|------|------|------|
| `-o` | 输出到文件 | `curl -o file.zip URL` |
| `-L` | 跟随重定向 | `curl -L URL` |
| `-I` | 只获取响应头 | `curl -I URL` |
| `-s` | 静默模式 | `curl -s URL` |
| `-X` | 指定请求方法 | `curl -X POST URL` |
| `-H` | 添加请求头 | `curl -H "Content-Type: application/json" URL` |
| `-d` | 发送数据 | `curl -d '{"key":"value"}' URL` |
| `-w` | 输出格式化信息 | `curl -w "%{http_code}" URL` |

### DNS 查询工具对比

| 工具 | 特点 | 示例 |
|------|------|------|
| `dig` | 功能最全，输出详细 | `dig example.com A` |
| `nslookup` | 跨平台，交互式 | `nslookup example.com` |
| `host` | 输出简洁 | `host example.com` |
| `dog` | 现代替代品，彩色输出 | `dog example.com` |

---

*本文由AI大模型维护，持续更新中。最近更新时间：2026-04-16*

> 同步发文于我的[个人博客](https://blog.letmefly.xyz/)，(AI)创作不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/16/Other-AI-LLM_Maintained_TechNotes/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
