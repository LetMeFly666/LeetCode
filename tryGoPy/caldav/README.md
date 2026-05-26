<!--
 * @Author: LetMeFly
 * @Date: 2026-05-21 12:01:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-05-21 12:27:18
-->
# caldav

## tasks

- [x] read repeat tasks in "背单词"
- [x] add methods to read and modify calendars
- [x] check if event repeat never ends (no COUNT/UNTIL)

## files

|name|function|
|:--:|:--|
|README.md|Project overview|
|read_tasks.py|Original script to read repeat tasks from "背单词"|
|calendar_manager.py|New module with methods to read/modify calendars|
|example_usage.py|Examples of using calendar_manager|
|CALENDAR_MANAGER_USAGE.md|Detailed usage guide|
|secrets/|<ol><li>caldav.url</li><li>caldav.username</li><li>caldav.password</li></ol>|
|agent/|store agent files|
|logs/|Generated log files

## Agent

+ use python language.
+ list files in secrets/ is ok, but reading content in secrets/* is strictly forbidden.
+ generate more memory or try log files

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
