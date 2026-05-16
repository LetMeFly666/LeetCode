---
title: VSCode Docker(Code Server)首次调试C++长时间下载debuginfo问题
date: 2026-05-16 20:58:46
tags: [VsCode, 简单, Docker]
categories: [技术思考]
description: VsCode Docker(Code Server)每次重启docker首次dbg C++都要花费很久去下载一个15.5M的debuginfo的解决方案
---

# VSCode Docker(Code Server)首次调试C++长时间下载debuginfo问题

## 背景

最近在小服务器上部署了vscode docker([code server](https://github.com/coder/code-server))以便多处Continue一些项目，结果每次docker重启后首次调试C++时都会下载很久的debug info。

虽然文件只有15.5M，但无魔法的话可能会下载个十来分钟甚至直接下载失败。主要是还没找到这东西下在了哪里没办法持久化。

经过不断尝试，终于让docker重启后编译C++也不去下载这么个东西了。

```
Stopped due to shared library event (no libraries added or removed)
Loaded '/lib64/ld-linux-x86-64.so.2'. Symbols loaded.
Downloading 15.52 M separate debug info for /lib64/libstdc++.so.6...
```

## 解决办法

在VsCode默认shell配置环境变量：

```bash
export DEBUGINFOD_URLS=""
```

---

> FBI WARNING
> 
> 以下内容让ChatGPT总结自我与ChatGPT的对话，有明显不合理之处但未改动。
> 
> 不合理之处如：

1. “自动下载巨大的 debuginfo”，其实15.52M不算巨大，主要是没有魔法的话巨慢。
2. “尝试 ~/.gdbinit”部分并非“有时仍会：”，而是一定会“Downloading ...”。
3. “开始怀疑 Docker 持久化”我没怀疑过这个，因为我直到`~`目录都持久化了，是GPT忘了才怀疑的。

---

# GDB / debuginfod / Docker / VSCode C++ Debugging 踩坑复盘（Fedora + code-server）

## 背景

环境：

- Docker 容器
- Fedora 39
- `code-server`
- VSCode C/C++ 扩展 (`cppdbg`)
- GDB 15.1
- C++ (`g++ -g`)

目标：

- 在 Docker 中稳定调试 C++
- 避免每次首次 debug 时自动下载巨大的 debuginfo
- 避免 2h 卡死等待下载
- 理解 debuginfod 到底在干什么
- 理解为什么设置 seemingly 无效

---

# 第一阶段：发现问题

最初现象：

启动 VSCode Debug 后：

```text
Stopped due to shared library event (no libraries added or removed)
Loaded '/lib64/ld-linux-x86-64.so.2'. Symbols loaded.
Downloading 15.52 M separate debug info for /lib64/libstdc++.so.6...
```

而且：

- 下载非常慢
- 经常卡住
- Docker 重启后还会再次下载
- 只有第一次 debug C++ 会触发
- 其他普通程序不会

于是开始怀疑：

- GDB 配置错误？
- VSCode 插件问题？
- Docker 没持久化？
- debuginfo 装错？
- cache 丢失？

---

# 第二阶段：尝试通过 launch.json 禁用 debuginfod

最初配置：

```json
{
    "name": "g++ (code-server / Linux gdb)",
    "type": "cppdbg",
    "request": "launch",
    "program": "${fileDirname}/${fileBasenameNoExtension}",
    "args": [],
    "stopAtEntry": false,
    "cwd": "${fileDirname}",
    "externalConsole": false,
    "MIMode": "gdb",
    "miDebuggerPath": "/usr/bin/gdb",
    "preLaunchTask": "C/C++: g++ (code-server build)",
    "setupCommands": [
        {
            "description": "enable pretty printing",
            "text": "-enable-pretty-printing",
            "ignoreFailures": true
        }
    ],
    "environment": [
        {
            "name": "DEBUGINFOD_URLS",
            "value": ""
        }
    ]
}
```

期间踩坑：

## 1. `environment` 必须是 array

错误尝试：

```json
"environment": {
    "DEBUGINFOD_URLS": ""
}
```

报错：

```text
Incorrect type. Expected "array"
```

后来确认：

VSCode cppdbg 的 schema 要求：

```json
"environment": [
  {
    "name": "XXX",
    "value": "YYY"
  }
]
```

---

## 2. `env` 不支持

尝试：

```json
"env": {
  "DEBUGINFOD_URLS": ""
}
```

结果：

```text
Property env is not allowed
```

---

## 3. 即使配置正确，也没用

即使 launch.json 配置完全正确：

```json
"environment": [
  {
    "name": "DEBUGINFOD_URLS",
    "value": ""
  }
]
```

仍然会：

```text
Downloading 15.52 M separate debug info...
```

说明：

- VSCode 确实接受了配置
- 但 debuginfod 仍然生效

后来才发现：

> GDB 很可能在 VSCode 注入 environment 前，就已经初始化 debuginfod 了。

---

# 第三阶段：尝试通过 GDB 命令关闭

尝试：

```json
"setupCommands": [
    {
        "description": "disable debuginfod",
        "text": "set debuginfod enabled off",
        "ignoreFailures": true
    }
]
```

结果仍然无效。

原因后来才明白：

```text
Loaded '/lib64/ld-linux-x86-64.so.2'
Downloading 15MB...
```

这些行为：

> 发生在 setupCommands 执行之前。

因此：

```gdb
set debuginfod enabled off
```

只是：

> 从现在开始关闭。

而不是：

> 阻止启动阶段请求。

---

# 第四阶段：尝试 ~/.gdbinit

尝试：

```gdb
set debuginfod enabled off
```

写入：

```text
~/.gdbinit
```

结果：

依然不稳定。

有时仍会：

```text
Downloading 15.52 M...
```

后来分析：

GDB 初始化顺序中：

- system gdbinit
- auto-load
- shared library scan
- debuginfod init
- user ~/.gdbinit

顺序可能因 Fedora patch 不同而变化。

因此：

> 用户 gdbinit 并不一定足够早。

---

# 第五阶段：开始怀疑 Docker 持久化

因为观察到：

- 同一个 Docker session 内不会再次下载
- 只有 Docker 重启后才会再次下载

于是怀疑：

```text
~/.cache/debuginfod_client
```

没有持久化。

---

# 第六阶段：定位 debuginfod cache

发现：

```bash
~/.cache/debuginfod_client
```

目录存在。

而且：

```bash
du -h ~/.cache/debuginfod_client
```

能看到：

```text
15M /home/coder/.cache/debuginfod_client/289d812be7557bb66c6cfdd6e429614136188789
```

里面还有：

```text
debuginfo
debuginfo.GWLJYE
debuginfo.HvmaJg
debuginfo.N8U00F
```

于是开始推测：

- 这就是下载的 15MB
- Docker 重启后没有复用

---

# 第七阶段：错误推理（后来证明）

当时错误地认为：

```text
Downloading 15MB
==
一定下载成功
```

并进一步认为：

```text
既然 ~/.cache 没变
说明下载到别处了
```

后来通过实验推翻。

---

# 第八阶段：关键实验

做了一个非常重要的实验：

## 1. 删除 cache

```bash
rm -rf ~/.cache/debuginfod_client/289d812be7557bb66c6cfdd6e429614136188789/
```

## 2. 再次 debug

结果：

```text
Downloading 15.52 M separate debug info for /lib64/libstdc++.so.6...
Download failed: Timer expired.
Continuing without separate debug info for /lib64/libstdc++.so.6.
```

## 3. 检查 cache

结果：

```bash
du -h ~/.cache/debuginfod_client
```

大小并没有增加。

---

# 第九阶段：终于定位真相

这个实验最终证明：

> `Downloading 15.52 M` 并不意味着下载成功。

真正发生的是：

```text
GDB
 ↓
连接 Fedora debuginfod server
 ↓
server 返回：文件大小 15.52MB
 ↓
开始下载
 ↓
下载极慢
 ↓
超时
 ↓
GDB fallback
 ↓
继续调试（无 debuginfo）
```

因此：

- cache 变大：只是临时文件
- cache 变小：失败后清理
- 并没有真正下载完成

---

# 第十阶段：理解 debuginfo 到底是什么

发现：

```text
/lib64/libstdc++.so.6
```

只有：

```text
2.4MB
```

而下载提示却是：

```text
15.52MB
```

于是意识到：

> debuginfo 不是运行库本体。

而是：

- DWARF debug symbols
- 行号
- 类型信息
- STL 内部结构
- ABI metadata

本质上类似：

```text
编译后二进制 + 源码映射
```

---

# 第十一阶段：尝试安装本地 debuginfo rpm

尝试：

```bash
sudo dnf install libstdc++-debuginfo
```

结果：

```text
No match for argument
```

原因：

Fedora 默认没有开启 debuginfo repo。

---

# 第十二阶段：手动添加 debuginfo repo

因为使用的是阿里云 Fedora 源：

```ini
[fedora]
baseurl=https://mirrors.aliyun.com/fedora/releases/$releasever/Everything/$basearch/os/
```

没有 debug repo。

于是手动添加：

```ini
[fedora-debuginfo]
name=Fedora $releasever - $basearch - Debug
baseurl=https://mirrors.aliyun.com/fedora/releases/$releasever/Everything/$basearch/debug/tree/
enabled=1
gpgcheck=0
```

以及：

```ini
[updates-debuginfo]
name=Fedora $releasever - $basearch - Updates Debug
baseurl=https://mirrors.aliyun.com/fedora/updates/$releasever/Everything/$basearch/debug/tree/
enabled=1
gpgcheck=0
```

期间还遇到：

```text
404 repomd.xml
```

因为阿里云 updates debuginfo 不完整。

---

# 第十三阶段：发现本地 debuginfo 巨大

执行：

```bash
sudo dnf install libstdc++-debuginfo glibc-debuginfo
```

结果：

```text
Installing dependencies:
 gcc-debuginfo 102M
```

总大小：

```text
112M download
490M installed size
```

于是发现：

> 为了一个 15MB runtime symbol
> Fedora debuginfo rpm 会拉整个 gcc debuginfo dependency tree。

完全不可接受。

---

# 第十四阶段：理解“其实不用 debuginfo”

后来发现：

即使：

```text
Download failed: Timer expired.
Continuing without separate debug info.
```

之后：

- 断点正常
- 单步正常
- 用户变量正常
- 自己代码行号正常

因此终于意识到：

> 对日常 LeetCode / 普通 C++ debug 来说，libstdc++ debuginfo 根本不是必须。

缺少的只是：

- STL 深层内部解析
- libc 行号
- GCC runtime 深层调试

---

# 第十五阶段：最终正确解决方案

最终真正有效的方法：

```bash
export DEBUGINFOD_URLS=""
```

写入：

```text
~/.zshrc
```

之后：

```text
Downloading 15MB...
```

彻底消失。

---

# 为什么这个方法 finally 有效？

因为：

```bash
export DEBUGINFOD_URLS=""
```

发生在：

> GDB 进程启动之前。

因此：

```text
GDB process env:
DEBUGINFOD_URLS=""
```

于是：

> debuginfod subsystem 从一开始就被禁用了。

而之前的方法：

- launch.json
- setupCommands
- ~/.gdbinit

都发生得太晚。

---

# 最终状态

现在系统行为：

```text
GDB
 ├── debuginfod disabled at startup
 ├── no network requests
 ├── no 2h wait
 ├── no repeated attempts
 ├── normal C++ debug works
 └── STL deep symbols unavailable（通常无所谓）
```

---

# 最终结论（重要）

## 真正的问题不是：

- Docker
- cache
- HOME
- volume
- VSCode
- GDB bug

而是：

> Fedora debuginfod 下载极慢 + 初始化时机早于 VSCode 注入环境变量。

---

# 最终推荐配置

## ~/.zshrc

```bash
export DEBUGINFOD_URLS=""
export DEBUGINFOD_PROGRESS=0
```

---

# 经验总结

## 1. `Downloading xxx MB` 不等于下载成功

只是 server 告诉你：

```text
这个文件大小是 xxx MB
```

---

## 2. debuginfo 不是运行库

```text
libstdc++.so
```

只是 runtime。

真正大的：

```text
DWARF debug symbols
```

---

## 3. debuginfod 是增强功能，不是必须

没有它：

普通 C++ debug 仍然完全可用。

---

## 4. GDB 初始化非常早

很多“关闭 debuginfod”的方法实际上已经晚了。

---

## 5. shell environment 才是最稳定层级

```bash
export DEBUGINFOD_URLS=""
```

比：

- launch.json
- gdbinit
- setupCommands

都更底层、更可靠。

---

# 最终一句话总结

这次踩坑的本质是：

> GDB 在启动早期自动尝试通过 Fedora debuginfod 下载 libstdc++ 的 DWARF 调试符号；由于网络极慢导致长期卡顿，而 VSCode/GDB 层面的关闭方法时机太晚，最终只有在 shell 启动阶段通过 `export DEBUGINFOD_URLS=""` 才真正彻底禁用 debuginfod。

---

# The End

忽然发现Linux上文件排序顺序和Windows上不同，所以Readme文章顺序，，。。。

<center><font size="6px" face="Ink Free">The End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161147475)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/16/Other-VsCode-CodeServerDocker-StopDownloading15MgdbDebuginfod-gdb_debuginfod_docker_vscode_cpp_debugging_postmortem_2026/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
