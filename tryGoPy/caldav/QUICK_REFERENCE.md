# Quick Reference - Calendar Manager

## 快速开始

### 1. 查找事件是否"永远重复"

```python
from calendar_manager import find_event_by_uid

result = find_event_by_uid("6A3AD2E1-C742-4158-9C0D-1D8BA5BB41C0")
if result:
    cal, event_info = result
    if event_info['repeat_never_ends']:
        print("✓ 这个事件永远重复")
    else:
        print("✗ 这个事件有截止时间或固定次数")
```

### 2. 检查日历中哪些事件永远重复

```python
from calendar_manager import check_calendar_repeat_status

has_forever, repeat_events = check_calendar_repeat_status("背单词")

for event in repeat_events:
    print(f"{event['summary']}: 永远重复 = {event['never_ends']}")
```

### 3. 修改事件

```python
from calendar_manager import modify_calendar_event

# 改为永远重复
modify_calendar_event(
    calendar_id="背单词",
    event_summary="Daily Practice",
    new_rrule="FREQ=DAILY"
)

# 改为重复 30 次
modify_calendar_event(
    calendar_id="背单词",
    event_summary="Daily Practice",
    new_rrule="FREQ=DAILY;COUNT=30"
)

# 改为重复到某个日期
modify_calendar_event(
    calendar_id="背单词",
    event_summary="Daily Practice",
    new_rrule="FREQ=DAILY;UNTIL=20261231"
)
```

## 常用 RRULE

| 功能 | RRULE | 永远重复? |
|------|-------|---------|
| 每天 | `FREQ=DAILY` | ✓ 是 |
| 每周一 | `FREQ=WEEKLY;BYDAY=MO` | ✓ 是 |
| 每月1号 | `FREQ=MONTHLY;BYMONTHDAY=1` | ✓ 是 |
| 每年1月1日 | `FREQ=YEARLY;BYMONTH=1;BYMONTHDAY=1` | ✓ 是 |
| 每天，30次 | `FREQ=DAILY;COUNT=30` | ✗ 否 |
| 每天，到2026年12月 | `FREQ=DAILY;UNTIL=20261231` | ✗ 否 |
| 每周一、三、五 | `FREQ=WEEKLY;BYDAY=MO,WE,FR` | ✓ 是 |
| 每周一、三、五，10次 | `FREQ=WEEKLY;BYDAY=MO,WE,FR;COUNT=10` | ✗ 否 |

## 判断规则

一个 RRULE 是否永远重复取决于：

```
永远重复 = 没有 COUNT 参数 AND 没有 UNTIL 参数
```

**例子：**
- `FREQ=DAILY` → 没有 COUNT、没有 UNTIL → ✓ 永远重复
- `FREQ=DAILY;COUNT=30` → 有 COUNT → ✗ 不永远重复
- `FREQ=DAILY;UNTIL=20261231` → 有 UNTIL → ✗ 不永远重复
- `FREQ=DAILY;COUNT=30;UNTIL=20261231` → 都有 → ✗ 不永远重复

## 命令行快速测试

```bash
# 运行示例
python3 example_usage.py

# 主程序（会自动检查指定的 UID）
python3 calendar_manager.py

# 原始脚本（读取"Practice"日历）
python3 read_tasks.py
```

## 常见场景

### 场景 1: 找到一个事件并检查它是否永远重复

```python
from calendar_manager import find_event_by_uid

result = find_event_by_uid("DA640753-2A56-4DB0-91BD-094374BDBAD6")
if result and result[1]['repeat_never_ends']:
    print("找到了永远重复的事件!")
```

### 场景 2: 修改事件为永远重复

```python
from calendar_manager import modify_calendar_event

success = modify_calendar_event(
    calendar_id="背单词",
    event_summary="要修改的事件名",
    new_rrule="FREQ=DAILY"  # 永远每天重复
)

if success:
    print("✓ 已修改为永远重复")
else:
    print("✗ 修改失败，请检查日历和事件名")
```

### 场景 3: 找出某个日历中所有永远重复的事件

```python
from calendar_manager import check_calendar_repeat_status

has_forever, events = check_calendar_repeat_status("背单词")

if has_forever:
    print("这个日历有永远重复的事件:")
    for e in events:
        if e['never_ends']:
            print(f"  - {e['summary']}")
```

## 返回值类型

### find_event_by_uid()
```python
(Calendar, {
    'uid': str,                      # 事件 UUID
    'summary': str,                  # 事件标题
    'rrule': str | None,            # 重复规则
    'repeat_never_ends': bool,      # 是否永远重复
    'calendar_name': str,           # 所在日历名称
    ...
})
```

### check_calendar_repeat_status()
```python
(
    has_never_ending: bool,         # 是否有永远重复的事件
    [
        {
            'summary': str,         # 事件标题
            'rrule': str,          # 重复规则
            'never_ends': bool     # 是否永远重复
        },
        ...
    ]
)
```

### modify_calendar_event()
```python
True   # 修改成功
False  # 修改失败（事件未找到或错误）
```

## 日志位置

所有操作都会生成日志文件：
```
logs/calendar_manager_YYYYMMDD_HHMMSS.log
logs/example_usage_YYYYMMDD_HHMMSS.log
```

检查日志文件查看详细的操作记录。

## 错误处理

所有函数都会：
1. 返回 None/False 表示失败
2. 将详细错误写入日志文件
3. 输出到控制台

在生产环境中，始终检查返回值并查看日志文件。
