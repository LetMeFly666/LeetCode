# CalDAV Calendar Manager - Usage Guide

## Overview
`calendar_manager.py` 提供了一套方法来读取、查询和修改 CalDAV 日历中的事件。

## Features

### 1. 按 ID 或名称查找日历
```python
from calendar_manager import find_calendar_by_id

# 按日历名称查找
cal = find_calendar_by_id("背单词")

# 按日历 ID 查找
cal = find_calendar_by_id("1-3")
```

### 2. 按 UID 查找事件
```python
from calendar_manager import find_event_by_uid

# 查找事件
result = find_event_by_uid("DA640753-2A56-4DB0-91BD-094374BDBAD6")

if result:
    cal, event_info = result
    print(f"事件名称: {event_info['summary']}")
    print(f"重复规则: {event_info['rrule']}")
    print(f"永远重复: {event_info['repeat_never_ends']}")
```

### 3. 检查重复规则是否"永不截止"
```python
from calendar_manager import is_repeat_never_ends

# 检查 RRULE 是否永不结束
rrule = "FREQ=DAILY"  # 永远重复
result = is_repeat_never_ends(rrule)  # True

rrule = "FREQ=DAILY;COUNT=10"  # 重复 10 次
result = is_repeat_never_ends(rrule)  # False

rrule = "FREQ=DAILY;UNTIL=20260601"  # 重复到某个日期
result = is_repeat_never_ends(rrule)  # False
```

### 4. 获取日历中的所有事件
```python
from calendar_manager import get_calendar_events

# 获取所有事件
events = get_calendar_events("背单词")

# 仅获取有重复规则的事件
repeat_events = get_calendar_events("背单词", include_repeat_only=True)

for event in repeat_events:
    print(f"{event['summary']}")
    print(f"  RRULE: {event['rrule']}")
    print(f"  永远重复: {event['repeat_never_ends']}")
```

### 5. 检查日历的重复事件状态
```python
from calendar_manager import check_calendar_repeat_status

# 检查日历中是否有"永不截止"的重复事件
has_never_ending, repeat_events = check_calendar_repeat_status("背单词")

print(f"有永远重复的事件: {has_never_ending}")
print(f"总共 {len(repeat_events)} 个重复事件")

for event in repeat_events:
    print(f"  {event['summary']}: 永远重复 = {event['never_ends']}")
```

### 6. 修改事件
```python
from calendar_manager import modify_calendar_event

# 修改事件的重复规则
success = modify_calendar_event(
    calendar_id="背单词",
    event_summary="背单词+英语小听力",
    new_rrule="FREQ=DAILY"  # 改为每天重复，永不截止
)

# 修改事件的标题
success = modify_calendar_event(
    calendar_id="背单词",
    event_summary="背单词+英语小听力",
    new_summary="新的事件名称"
)

# 删除重复规则
success = modify_calendar_event(
    calendar_id="背单词",
    event_summary="背单词+英语小听力",
    new_rrule=None
)
```

## RRULE 格式说明

### 什么是"永不截止"的重复？
- **包含 COUNT 参数**：`FREQ=DAILY;COUNT=10` - 重复固定次数
- **包含 UNTIL 参数**：`FREQ=DAILY;UNTIL=20260601` - 重复到某个日期
- **都不包含**：`FREQ=DAILY` - 永远重复，永不截止

### 常见 RRULE 例子

```
# 每天重复，永不截止
FREQ=DAILY

# 每周一、三、五重复，永不截止
FREQ=WEEKLY;BYDAY=MO,WE,FR

# 每天重复，总共 30 次
FREQ=DAILY;COUNT=30

# 每天重复，直到 2026-12-31
FREQ=DAILY;UNTIL=20261231

# 每月的第一天，永不截止
FREQ=MONTHLY;BYMONTHDAY=1

# 每年 9 月的第三个周日，直到 1991 年 9 月 14 日
FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
```

## 命令行用法

### 运行主程序
```bash
source venv/bin/activate
python3 calendar_manager.py
```

这将执行示例查询，并将结果保存到 `logs/` 文件夹。

## 日志

所有操作都会被记录到 `logs/calendar_manager_YYYYMMDD_HHMMSS.log` 文件中。

例如：查找事件、检查重复规则、修改事件的所有细节都会被记录。

## 返回值说明

### `find_event_by_uid()` 返回
```python
(cal, event_info)
# event_info = {
#     'uid': 'DA640753-2A56-4DB0-91BD-094374BDBAD6',
#     'summary': '背单词+英语小听力',
#     'rrule': 'FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU',
#     'url': 'https://...',
#     'has_repeat': True,
#     'repeat_never_ends': False,
#     'calendar_name': '背单词',
#     'event_obj': <Event object>
# }
```

### `get_calendar_events()` 返回
```python
[
    {
        'summary': '事件名称',
        'rrule': 'FREQ=DAILY',
        'url': 'https://...',
        'has_repeat': True,
        'repeat_never_ends': True
    },
    ...
]
```

### `check_calendar_repeat_status()` 返回
```python
(
    has_never_ending,  # bool: 是否有永不截止的重复事件
    [
        {
            'summary': '事件名称',
            'rrule': 'FREQ=DAILY',
            'never_ends': True
        },
        ...
    ]
)
```

## 错误处理

所有函数都包含异常处理和日志记录：

```python
try:
    result = find_calendar_by_id("some_id")
except Exception as e:
    # 错误会被记录到 logs/ 文件夹
    logger.error(f"Error: {e}", exc_info=True)
    return None
```

## 示例脚本

创建自己的脚本来使用这些方法：

```python
from calendar_manager import (
    find_event_by_uid,
    check_calendar_repeat_status,
    get_calendar_events,
    modify_calendar_event
)

# 1. 查找特定事件
result = find_event_by_uid("DA640753-2A56-4DB0-91BD-094374BDBAD6")
if result:
    cal, event_info = result
    print(f"找到事件: {event_info['summary']}")
    if event_info['repeat_never_ends']:
        print("这个事件永远重复!")

# 2. 检查日历状态
has_forever, repeat_events = check_calendar_repeat_status("背单词")
if has_forever:
    print("背单词日历有永远重复的事件")

# 3. 获取所有重复事件
events = get_calendar_events("Coding", include_repeat_only=True)
for event in events:
    print(f"{event['summary']}: {event['rrule']}")

# 4. 修改事件
if modify_calendar_event("背单词", "背单词+英语小听力", new_rrule="FREQ=DAILY"):
    print("事件已成功修改!")
```
