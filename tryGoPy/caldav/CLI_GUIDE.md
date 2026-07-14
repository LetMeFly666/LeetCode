# CLI 任务查找指南

## 概述

现在你可以通过命令行查找日历中的任务，**无需修改源代码**！

有两个工具可用：
1. **find_task.py** - 简化版，快速查询
2. **task_finder.py** - 完整版，高级功能

## 快速开始

### 1. 列出所有日历

```bash
python3 find_task.py --list
```

输出：
```
📚 所有日历:

[1] 背单词
[2] Coding
[3] 工作
[4] 个人
[5] 娱乐
[6] 锻炼🏋️‍♀️运动
```

### 2. 查看某个日历的所有事件

```bash
python3 find_task.py Practice
```

输出：
```
✓ 找到 1 个事件

----------------------------------------------------------------------
[1] 🔄    Daily Practice
     RRULE: FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
----------------------------------------------------------------------
```

### 3. 在日历中搜索关键词

```bash
python3 find_task.py Tasks review
```

输出：
```
✓ 找到 2 个事件

----------------------------------------------------------------------
[1] 🔄    Project Documentation
     RRULE: FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
[2]       Team Discussion
----------------------------------------------------------------------
```

### 4. 按 UUID 查找特定事件

```bash
python3 find_task.py --uid DA640753-2A56-4DB0-91BD-094374BDBAD6
```

输出：
```
======================================================================
📋 事件详情
======================================================================
日历:        背单词
标题:        Daily Practice
UID:         DA640753-2A56-4DB0-91BD-094374BDBAD6
URL:         https://[your-server]/remote.php/dav/calendars/.../... 或 ~/.zshrc
alias find='cd ~/Projects/LeetCode/tryGoPy/caldav && source venv/bin/activate && python3 find_task.py'

# 然后就可以这样使用：
find --list
find 工作
find Tasks review
find --uid DA640753-2A56-4DB0-91BD-094374BDBAD6
```

### 或创建一个 shell 脚本

创建 `~/bin/find-task`：
```bash
#!/bin/bash
cd ~/Projects/LeetCode/tryGoPy/caldav
source venv/bin/activate
python3 find_task.py "$@"
```

然后就可以：
```bash
find-task --list
find-task 工作
```

## 故障排除

### "日历未找到"错误

确保日历名称拼写正确。使用 `--list` 查看确切的日历名称：
```bash
python3 find_task.py --list
```

### 搜索结果为空

搜索是区分大小写的。试试其他关键词或使用 `--list` 查看所有事件。

### 需要更详细的信息

使用 `task_finder.py` 而不是 `find_task.py`：
```bash
python3 task_finder.py --calendar Practice --check-repeat
```

## 相关文件

- `find_task.py` - 简化的 CLI 工具
- `task_finder.py` - 完整的 CLI 工具，更多选项
- `calendar_manager.py` - 核心库
- `QUICK_REFERENCE.md` - API 快速参考
- `CALENDAR_MANAGER_USAGE.md` - 详细 API 文档
