# Linux Swap 文件完全指南：从创建到调优

> 作为一名后端开发工程师，你迟早会遇到服务器内存不够用的窘境。本文将带你深入理解 Linux Swap 的工作原理，并手把手教你如何正确地创建、启用和调优 Swap 文件。

---

## 目录

1. [什么是 Swap？](#什么是-swap)
2. [Swap 分区 vs Swap 文件](#swap-分区-vs-swap-文件)
3. [什么时候需要 Swap？](#什么时候需要-swap)
4. [实战：6 步创建并启用 Swap 文件](#实战6-步创建并启用-swap-文件)
5. [进阶：Swappiness 调优](#进阶swappiness-调优)
6. [常见问题排查](#常见问题排查)
7. [总结](#总结)

---

## 什么是 Swap？

Swap（交换空间）是 Linux 内存管理机制的重要组成部分。简单来说，它是磁盘上的一块区域，充当物理内存（RAM）的"溢出缓冲区"。

当系统的物理内存即将耗尽时，Linux 内核会将一些**不活跃的内存页**（inactive pages）从 RAM 移动到 Swap 空间中，从而释放 RAM 给更急需的进程使用。当这些被换出的内存页再次被访问时，内核会将它们从 Swap 读回到 RAM——这个过程叫做 **swap in**（换入）。

```
┌─────────────────────────────────────────────┐
│                   RAM (物理内存)              │
│                                             │
│  ┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐       │
│  │ 进程A │ │ 进程B │ │ 进程C │ │ 进程D │       │
│  │(活跃) │ │(活跃) │ │(不活跃)│ │(活跃) │       │
│  └──────┘ └──────┘ └──┬───┘ └──────┘       │
│                        │                     │
│                  内存不足时                    │
│                   swap out                   │
│                        │                     │
└────────────────────────┼────────────────────┘
                         ▼
┌─────────────────────────────────────────────┐
│              Swap 空间 (磁盘)                │
│                                             │
│  ┌──────────────────────────┐               │
│  │  进程C 的不活跃内存页      │               │
│  │  (等待被再次访问时 swap in) │               │
│  └──────────────────────────┘               │
└─────────────────────────────────────────────┘
```

### 关键概念

| 术语 | 含义 |
|------|------|
| **Swap Out** | 内核将不活跃内存页从 RAM 写入 Swap 空间 |
| **Swap In** | 内核将之前换出的页从 Swap 空间读回 RAM |
| **Page** | 内存管理的最小单位，通常为 4KB |
| **Swappiness** | 内核使用 Swap 的积极程度（0-200，默认60） |

---

## Swap 分区 vs Swap 文件

Linux 支持两种 Swap 实现方式：

| 特性 | Swap 分区 | Swap 文件 |
|------|-----------|-----------|
| **创建方式** | 需要独立磁盘分区 | 普通文件即可 |
| **灵活性** | 创建后难以调整大小 | 可随时创建、删除、调整 |
| **性能** | 理论上略好（无文件系统开销） | 现代内核下差异极小 |
| **适用场景** | 安装时规划好的服务器 | 云服务器、VPS、临时扩展 |
| **推荐度** | ★★★☆☆ | ★★★★★（现代主流方案） |

> **结论**：除非你有非常特殊的性能需求，否则 **Swap 文件是更好的选择**——灵活、简单、易管理。自 Linux 内核 2.6 以来，Swap 文件的性能已经与 Swap 分区几乎没有差别。

---

## 什么时候需要 Swap？

### 推荐的 Swap 大小

| 物理内存 (RAM) | 推荐 Swap 大小 | 需要休眠时 |
|----------------|----------------|-----------|
| ≤ 2 GB | 2× RAM | 3× RAM |
| 2 – 8 GB | 等于 RAM | 2× RAM |
| 8 – 64 GB | 至少 4 GB | 1.5× RAM |
| > 64 GB | 至少 4 GB | 不建议休眠 |

### 必须配置 Swap 的场景

- **小内存 VPS/云服务器**（1-2GB RAM）：编译代码、运行数据库时容易 OOM
- **运行 Java 应用**：JVM 的内存占用往往超出预期
- **需要休眠（Hibernate）**：休眠时整个 RAM 内容会写入 Swap
- **数据库服务器**：MySQL/PostgreSQL 等在高并发时可能突发内存需求

### 不太需要 Swap 的场景

- 内存充足（>64GB）且负载可预测的专用服务器
- 对延迟极其敏感的实时系统（Swap I/O 会引入不可预测的延迟）

---

## 实战：6 步创建并启用 Swap 文件

以下是在 Ubuntu/Debian 系统上创建 2GB Swap 文件的完整步骤。每一步都有详细解释。

### Step 1：分配磁盘空间

```bash
sudo fallocate -l 2G /swapfile
```

| 参数 | 说明 |
|------|------|
| `sudo` | 以 root 权限执行（在根目录创建文件需要） |
| `fallocate` | 快速分配磁盘空间，不实际写入数据，几乎瞬间完成 |
| `-l 2G` | `--length` 的缩写，指定文件大小为 2 GiB |
| `/swapfile` | 文件路径，惯例放在根目录下 |

> **为什么用 `fallocate` 而不是 `dd`？**
>
> 传统方式是 `dd if=/dev/zero of=/swapfile bs=1M count=2048`，它会逐块写入零数据，2GB 可能需要几十秒。而 `fallocate` 直接在文件系统层面预留空间，速度快几个数量级。
>
> **注意**：`fallocate` 在某些文件系统（如 `btrfs`、`ZFS`）上可能不支持，此时需回退到 `dd` 方式。

### Step 2：锁定文件权限

```bash
sudo chmod 600 /swapfile
```

权限 `600` 的含义：

```
6   0   0
│   │   └── 其他用户（others）：无任何权限
│   └────── 所属组（group）：无任何权限
└────────── 文件所有者（root）：读(4) + 写(2) = 6
```

**为什么这一步至关重要？** Swap 文件中存储的是从内存换出的数据，可能包含密码、密钥、数据库记录等敏感信息。如果其他用户可以读取 swap 文件，就等于可以窥探其他进程的内存内容——这是严重的安全漏洞。

如果跳过这一步，`swapon` 会发出警告：

```
swapon: /swapfile: insecure permissions 0644, 0600 suggested.
```

### Step 3：格式化为 Swap 格式

```bash
sudo mkswap /swapfile
```

`mkswap`（**m**a**k**e **swap**）在文件头部写入 swap 签名和元数据：

- **Magic number**：标识这是一个合法的 swap 空间
- **UUID**：唯一标识符
- **页大小信息**：通常为 4096 bytes
- **可用页数**：总空间除以页大小

典型输出：

```
Setting up swapspace version 1, size = 2 GiB (2147479552 bytes)
no label, UUID=a1b2c3d4-e5f6-7890-abcd-ef1234567890
```

> 这一步类似于用 `mkfs.ext4` 格式化磁盘分区——都是在存储介质上建立特定格式的数据结构，只不过这里的格式是 swap。

### Step 4：立即激活 Swap

```bash
sudo swapon /swapfile
```

执行后，Linux 内核**立即开始使用**该文件作为交换空间。这是即时生效的，无需重启。

但有一个问题：**这只是临时生效**——系统重启后，这个 swap 就不会自动挂载了。所以我们需要下一步。

### Step 5：持久化配置（开机自动挂载）

```bash
echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab
```

**命令拆解**：

| 部分 | 说明 |
|------|------|
| `echo '...'` | 输出配置字符串 |
| `\|` | 管道符，传递给下一个命令 |
| `sudo tee -a` | 以 root 权限**追加**写入文件（`-a` = append） |
| `/etc/fstab` | **F**ile **S**ystem **Tab**le，系统启动时读取的挂载配置表 |

> **为什么不用 `sudo echo '...' >> /etc/fstab`？**
>
> 因为 `>>` 重定向是由**当前 shell** 执行的，而当前 shell 是普通用户权限。`sudo` 只提升了 `echo` 的权限，`>>` 操作仍然会因权限不足而失败。`tee` 命令本身被 `sudo` 提权，所以可以成功写入。这是 Linux 中一个经典的权限"坑"。

**fstab 条目解析**：

```
/swapfile   none   swap   sw   0   0
    │         │      │     │   │   │
    │         │      │     │   │   └── fsck 顺序：0 = 启动时不检查
    │         │      │     │   └────── dump 备份：0 = 不需要备份
    │         │      │     └────────── 挂载选项：sw = swap 默认选项
    │         │      └──────────────── 文件系统类型：swap
    │         └─────────────────────── 挂载点：none（swap 不挂载到目录树）
    └───────────────────────────────── 设备/文件路径
```

### Step 6：验证

```bash
swapon --show
```

预期输出：

```
NAME      TYPE  SIZE  USED  PRIO
/swapfile file    2G    0B    -2
```

| 列 | 含义 |
|----|------|
| **NAME** | swap 设备/文件路径 |
| **TYPE** | `file`（文件）或 `partition`（分区） |
| **SIZE** | 总大小 |
| **USED** | 已使用量 |
| **PRIO** | 优先级，数值越大越优先使用 |

其他验证方式：

```bash
# 查看内存和 swap 概况
free -h

# 查看 /proc 虚拟文件系统中的 swap 信息
cat /proc/swaps

# 查看内存详细信息
cat /proc/meminfo | grep -i swap
```

---

## 进阶：Swappiness 调优

### 什么是 Swappiness？

`swappiness` 是一个内核参数，控制内核将内存页换出到 Swap 的积极程度：

| 值 | 行为 |
|----|------|
| `0` | 尽可能不使用 swap（仅在内存极度不足时使用） |
| `10` | 推荐的服务器设置，减少 swap 使用 |
| `60` | 默认值，平衡策略 |
| `100` | 积极使用 swap |

### 查看当前值

```bash
cat /proc/sys/vm/swappiness
```

### 临时修改（立即生效，重启失效）

```bash
sudo sysctl vm.swappiness=10
```

### 永久修改

```bash
echo 'vm.swappiness=10' | sudo tee -a /etc/sysctl.conf
sudo sysctl -p  # 重新加载配置
```

### 调优建议

| 场景 | 推荐 swappiness | 原因 |
|------|-----------------|------|
| 数据库服务器 | 1 - 10 | 数据库有自己的缓存管理，频繁 swap 会严重影响查询性能 |
| Web 服务器 | 10 - 30 | 减少不必要的 swap，保持响应速度 |
| 桌面系统 | 40 - 60 | 平衡内存使用和应用响应性 |
| 内存紧张的 VPS | 60 - 80 | 更积极地使用 swap，避免 OOM |

---

## 常见问题排查

### 1. `fallocate` 报错 "fallocate: fallocate failed: Operation not supported"

**原因**：文件系统不支持 `fallocate`（如 `btrfs`、某些网络文件系统）。

**解决**：改用 `dd`：

```bash
sudo dd if=/dev/zero of=/swapfile bs=1M count=2048 status=progress
```

### 2. `swapon` 报错 "swapon: /swapfile: read swap header failed"

**原因**：忘记执行 `mkswap` 格式化步骤。

**解决**：

```bash
sudo mkswap /swapfile
sudo swapon /swapfile
```

### 3. 重启后 Swap 消失

**原因**：没有将配置写入 `/etc/fstab`。

**验证**：

```bash
cat /etc/fstab | grep swap
```

如果没有输出，执行 Step 5 添加配置。

### 4. 如何关闭并删除 Swap 文件？

```bash
# 1. 关闭 swap
sudo swapoff /swapfile

# 2. 从 fstab 中移除对应行
sudo sed -i '/\/swapfile/d' /etc/fstab

# 3. 删除文件
sudo rm /swapfile
```

### 5. 如何调整 Swap 大小？

无法直接调整，需要先关闭旧的，再创建新的：

```bash
sudo swapoff /swapfile
sudo fallocate -l 4G /swapfile   # 改为 4GB
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
```

---

## 总结

### 完整命令速查

```bash
# === 创建并启用 2G Swap ===
sudo fallocate -l 2G /swapfile       # 1. 分配空间
sudo chmod 600 /swapfile             # 2. 设置权限
sudo mkswap /swapfile                # 3. 格式化
sudo swapon /swapfile                # 4. 激活

# === 持久化 ===
echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab

# === 验证 ===
swapon --show
free -h

# === 调优 (可选) ===
echo 'vm.swappiness=10' | sudo tee -a /etc/sysctl.conf
sudo sysctl -p
```

### 流程图

```
创建文件 ──→ 锁定权限 ──→ 格式化 ──→ 激活 ──→ 持久化 ──→ 验证
fallocate    chmod 600    mkswap     swapon    fstab      swapon --show
  (快速)      (安全)     (初始化)   (即时生效)  (永久生效)   (确认状态)
```

Swap 是 Linux 内存管理中不可或缺的一环。即使你的服务器有充足的内存，配置一个合理大小的 Swap 也是一种良好的实践——它为你的系统提供了一个安全网，在内存使用突增时避免 OOM Killer 直接杀死进程。

希望这篇文章对你有帮助！如果有任何疑问，欢迎在评论区讨论。

---

*作者：一个曾经因为没配 Swap 而在凌晨被 OOM 告警吵醒的程序员 🙃*
