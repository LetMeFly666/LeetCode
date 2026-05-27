# CLI 工具使用总结

## ✅ 新增功能

添加了两个强大的 CLI 工具，允许你通过命令行查找日历事件，**无需修改任何源代码**！

## 🚀 快速使用

### 最简单的方式 - find_task.py

```bash
# 列出所有日历
python3 find_task.py --list

# 查看某个日历的所有事件
python3 find_task.py Tasks

# 在日历中搜索
python3 find_task.py Tasks review

# 按 UUID 查找
python3 find_task.py --uid DA640753-2A56-4DB0-91BD-094374BDBAD6

# 检查重复事件
python3 find_task.py Practice --repeat-check
```

### 完整功能 - task_finder.py

```bash
# 显示帮助
python3 task_finder.py --help

# 列出日历
python3 task_finder.py --list-calendars

# 按 UID 查找
python3 task_finder.py --uid <UUID>

# 按标题查找
python3 task_finder.py --calendar Tasks --title "Project Documentation"

# 在日历中搜索
python3 task_finder.py --calendar Tasks --search review

# 检查重复事件
python3 task_finder.py --calendar Practice --check-repeat
```

## 📋 文件清单

| 文件 | 用途 |
|------|------|
| **find_task.py** | ⭐ 简化版 CLI 工具（推荐使用） |
| **task_finder.py** | 完整版 CLI 工具（更多选项） |
| **CLI_GUIDE.md** | 详细的 CLI 使用指南 |
| calendar_manager.py | 核心库（被 CLI 工具调用） |
| QUICK_REFERENCE.md | API 快速参考 |
| CALENDAR_MANAGER_USAGE.md | API 详细文档 |

## 📝 常见用法

### 场景 1: 查看某个日历中的任务

```bash
python3 find_task.py Tasks
```

输出：
```
✓ 找到 7 个事件

----------------------------------------------------------------------
[1] 🔄    Project Documentation
[2] 🔄    Script Development
[3]       Team Discussion
[4]       Review Code
[5] 🔄    Final Presentation
[6] 🔄    Interview
[7] 🔄    ppt
----------------------------------------------------------------------
```

### 场景 2: 搜索特定任务

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

### 场景 3: 查看任务详情

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
URL:         https://[your-server]/remote.php/dav/calendars/.../... 或 `~/.zshrc` 中添加：

```bash
alias find='cd ~/Projects/LeetCode/tryGoPy/caldav && source venv/bin/activate && python3 find_task.py'
```

然后可以直接使用：
```bash
find --list
find 工作
find Tasks review
find --uid DA640753-2A56-4DB0-91BD-094374BDBAD6
```

### 获取帮助

```bash
# find_task.py 的帮助
python3 find_task.py --help

# task_finder.py 的帮助
python3 task_finder.py --help

# 详细指南
cat CLI_GUIDE.md
```

## 🛠️ 技术细节

### 依赖关系
- `find_task.py` 依赖 `task_finder.py` 的函数
- `task_finder.py` 依赖 `calendar_manager.py` 的核心功能
- `calendar_manager.py` 使用 `caldav` 库

### 运行流程
```
用户输入 (CLI)
    ↓
find_task.py 或 task_finder.py (参数解析)
    ↓
calendar_manager.py (核心逻辑)
    ↓
caldav (CalDAV 协议)
    ↓
Nextcloud CalDAV 服务器
```

### 错误处理
- 所有错误都有清晰的提示
- 日志记录到 `logs/` 文件夹
- 不会因为找不到结果而崩溃

## 📖 更多信息

详细文档请参考：
- **CLI_GUIDE.md** - 完整的 CLI 使用指南
- **QUICK_REFERENCE.md** - API 快速参考
- **CALENDAR_MANAGER_USAGE.md** - 库函数详细文档
- **IMPLEMENTATION_SUMMARY.md** - 实现细节

## ✨ 总结

现在你可以：
- ✅ 不修改代码地查询任务
- ✅ 快速搜索任何日历中的事件
- ✅ 查看事件的详细信息（重复规则等）
- ✅ 检查事件是否"永不截止"
- ✅ 在命令行中完成所有操作

**推荐使用**: `python3 find_task.py` 用于日常查询
