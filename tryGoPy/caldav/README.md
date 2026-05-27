<!--
 * @Author: [Author Name]
 * @Date: 2026-05-21 12:01:08
 * @LastEditors: [Last Editor]
 * @LastEditTime: 2026-05-21 12:27:18
-->
# caldav

## tasks

- [x] read repeat tasks in "背单词"
- [x] add methods to read and modify calendars
- [x] check if event repeat never ends (no COUNT/UNTIL)
- [x] add CLI tool to search tasks without modifying source code

## files

|name|function|
|:--:|:--|
|README.md|Project overview|
|read_tasks.py|Original script to read repeat tasks from "背单词"|
|calendar_manager.py|Core module with methods to read/modify calendars|
|find_task.py|CLI tool - simplified task finder (recommended for quick queries)|
|task_finder.py|CLI tool - full-featured task finder with advanced options|
|example_usage.py|Examples of using calendar_manager library|
|CALENDAR_MANAGER_USAGE.md|Detailed API documentation|
|QUICK_REFERENCE.md|Quick reference for API|
|CLI_GUIDE.md|Guide for using CLI tools (find_task.py and task_finder.py)|
|IMPLEMENTATION_SUMMARY.md|Implementation details|
|secrets/|<ol><li>caldav.url</li><li>caldav.username</li><li>caldav.password</li></ol>|
|agent/|store agent files|
|logs/|Generated log files

## Agent

+ use python language.
+ list files in secrets/ is ok, but reading content in secrets/* is strictly forbidden.
+ generate more memory or try log files

## New CLI Tools: find_task.py and task_finder.py

No more need to modify source code! Use CLI tools to search tasks:

### Quick Start

```bash
# List all calendars
python3 find_task.py --list

# View all events in a calendar
python3 find_task.py Tasks

# Search for specific event in a calendar
python3 find_task.py Tasks review

# Find event by UUID
python3 find_task.py --uid DA640753-2A56-4DB0-91BD-094374BDBAD6

# Check repeat events status
python3 find_task.py Practice --repeat-check
```

### Two CLI Tools Available

1. **find_task.py** - Simplified interface, quick queries
   - Easiest to use for common tasks
   - Recommended for most users

2. **task_finder.py** - Full-featured with more options
   - Advanced filtering
   - More detailed output
   - Use: `python3 task_finder.py --help`

For detailed CLI guide, see `CLI_GUIDE.md`

## New Module: calendar_manager.py

Added a comprehensive module for reading and modifying CalDAV calendars with the following capabilities:

### Key Functions

1. **find_calendar_by_id(calendar_id)** - Find calendar by ID or name
2. **find_event_by_uid(event_uid)** - Find event by UUID across all calendars
3. **is_repeat_never_ends(rrule_str)** - Check if RRULE has no end date/count
4. **get_calendar_events(calendar_id, include_repeat_only=False)** - Get events from a calendar
5. **check_calendar_repeat_status(calendar_id)** - Check if calendar has infinite repeat events
6. **modify_calendar_event(calendar_id, event_summary, new_rrule, new_summary)** - Modify event properties

### Usage

```python
from calendar_manager import find_event_by_uid, is_repeat_never_ends

# Find an event by UID
result = find_event_by_uid("DA640753-2A56-4DB0-91BD-094374BDBAD6")
if result:
    cal, event_info = result
    print(f"Event: {event_info['summary']}")
    print(f"Repeat never ends: {event_info['repeat_never_ends']}")

# Check if RRULE means repeat forever
never_ends = is_repeat_never_ends("FREQ=DAILY")  # True - repeat forever
never_ends = is_repeat_never_ends("FREQ=DAILY;COUNT=10")  # False - repeat 10 times
```

### What "Never Ends" Means

A recurrence rule (RRULE) means "repeat forever" (never ends) if it contains:
- NO COUNT parameter (which limits occurrences)
- NO UNTIL parameter (which limits by date)

Example:
- ✓ `FREQ=DAILY` - repeat forever
- ✗ `FREQ=DAILY;COUNT=30` - repeat 30 times (not forever)
- ✗ `FREQ=DAILY;UNTIL=20261231` - repeat until date (not forever)

### Running Examples

```bash
source venv/bin/activate
python3 example_usage.py
```

For detailed documentation, see `CALENDAR_MANAGER_USAGE.md`
