# 🚀 如何使用 CLI 工具查找任务

## 问题
你问："我想通过 ID 来寻找一个 task 的具体信息，怎么找？总不能让我修改源码来寻找吧？至少应该支持 cli？"

## 解决方案
✅ **已解决！** 现在可以通过命令行工具查找任务，无需修改源代码！

## 快速开始（3 秒上手）

```bash
# 1. 列出所有日历
python3 find_task.py --list

# 2. 查看某个日历的事件
python3 find_task.py Tasks

# 3. 在日历中搜索
python3 find_task.py Tasks review

# 4. 按 UUID 查找
python3 find_task.py --uid DA640753-2A56-4DB0-91BD-094374BDBAD6

# 5. 检查重复事件
python3 find_task.py Practice --repeat-check
```

## 详细用法

### 选项 1: find_task.py (推荐 ⭐)

简化版本，命令最少：

```bash
# 列出所有日历
python3 find_task.py --list

# 查看某个日历的所有事件
python3 find_task.py Practice

# 在日历中搜索关键词
python3 find_task.py Tasks 开会

# 按 UUID 精确查找
python3 find_task.py --uid DA640753-2A56-4DB0-91BD-094374BDBAD6

# 检查某个日历中的重复事件
python3 find_task.py Practice --repeat-check

# 显示帮助
python3 find_task.py --help
```

### 选项 2: task_finder.py (完整功能)

功能更全面，选项更多：

```bash
# 列出所有日历
python3 task_finder.py --list-calendars

# 查看日历
python3 task_finder.py --calendar Tasks

# 在日历中搜索
python3 task_finder.py --calendar Tasks --search 开会

# 按标题精确查找
python3 task_finder.py --calendar Tasks --title "Project Documentation"

# 按 UUID 查找
python3 task_finder.py --uid DA640753-2A56-4DB0-91BD-094374BDBAD6

# 检查重复事件
python3 task_finder.py --calendar Practice --check-repeat

# 显示帮助
python3 task_finder.py --help
```

## 实际示例

### 示例 1: 查看工作日历的所有任务

```bash
$ python3 find_task.py Tasks

🔍 正在查找日历: 工作

✓ 找到 7 个事件

----------------------------------------------------------------------
[1] 🔄    Project Documentation
     RRULE: FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
[2] 🔄    Script Development
     RRULE: FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
[3]       Team Discussion
[4]       Review Code
[5] 🔄    Final Presentation
     RRULE: FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
[6] 🔄    Interview
     RRULE: FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
[7] 🔄    ppt
     RRULE: FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
----------------------------------------------------------------------
```

### 示例 2: 搜索关键词

```bash
$ python3 find_task.py Tasks review

🔍 正在查找日历: 工作

✓ 找到 2 个事件

----------------------------------------------------------------------
[1] 🔄    Project Documentation
     RRULE: FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
[2]       Team Discussion
----------------------------------------------------------------------
```

### 示例 3: 查看任务详情

```bash
$ python3 find_task.py --uid DA640753-2A56-4DB0-91BD-094374BDBAD6

🔍 正在查找 UID: DA640753-2A56-4DB0-91BD-094374BDBAD6

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
```

### Q2: 搜索找不到结果怎么办？

1. 检查日历名称是否正确：`python3 find_task.py --list`
2. 检查搜索词是否存在：`python3 find_task.py 日历名`
3. 尝试用完整的 UUID：`python3 find_task.py --uid <完整UUID>`

### Q3: 如何查看完整的帮助？

```bash
# find_task.py 帮助
python3 find_task.py --help

# task_finder.py 帮助
python3 task_finder.py --help

# 详细文档
cat CLI_GUIDE.md
cat CLI_SUMMARY.md
```

### Q4: 什么是"永不截止"？

在重复规则中：
- **永不截止**：没有 COUNT 或 UNTIL 参数，事件永远重复
  - 例如：`FREQ=DAILY` 
- **有截止**：有 COUNT（固定次数）或 UNTIL（截止日期）
  - 例如：`FREQ=DAILY;COUNT=10` 或 `FREQ=DAILY;UNTIL=20261231`

## 底层原理

```
用户输入 (CLI)
    ↓
find_task.py (参数解析)
    ↓
task_finder.py (功能实现)
    ↓
calendar_manager.py (核心逻辑)
    ↓
caldav 库 (CalDAV 协议)
    ↓
Nextcloud (CalDAV 服务器)
```

## 相关文件

- 📄 `CLI_GUIDE.md` - 完整的 CLI 指南
- 📄 `CLI_SUMMARY.md` - CLI 工具总结
- 📄 `QUICK_REFERENCE.md` - 快速参考
- 📄 `CALENDAR_MANAGER_USAGE.md` - API 文档
- 📄 `README.md` - 项目说明

## 总结

✅ 现在你可以：
- 不修改代码地查询任务
- 快速搜索日历中的事件
- 查看事件的详细信息
- 检查重复规则
- 完全在命令行中操作

**推荐**: 使用 `python3 find_task.py` 进行日常查询
