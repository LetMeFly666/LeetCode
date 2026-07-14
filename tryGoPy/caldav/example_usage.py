#!/usr/bin/env python3
"""
Example script: Analyze and modify a specific calendar
Demonstrates using calendar_manager methods
"""

from calendar_manager import (
    find_event_by_uid,
    find_calendar_by_id,
    check_calendar_repeat_status,
    get_calendar_events,
    modify_calendar_event,
    is_repeat_never_ends
)
import logging

logger = logging.getLogger(__name__)

def example_find_event_by_uid():
    """Example 1: Find an event by UID"""
    print("\n" + "=" * 70)
    print("Example 1: Find event by UID")
    print("=" * 70)
    
    # 使用实际存在的 UID (从之前的测试得到)
    event_uid = "DA640753-2A56-4DB0-91BD-094374BDBAD6"
    
    result = find_event_by_uid(event_uid)
    if result:
        cal, event_info = result
        print(f"\n✓ Found event!")
        print(f"  Calendar: {event_info['calendar_name']}")
        print(f"  Title: {event_info['summary']}")
        print(f"  UID: {event_info['uid']}")
        print(f"  Has repeat: {event_info['has_repeat']}")
        if event_info['rrule']:
            print(f"  RRULE: {event_info['rrule']}")
            print(f"  Repeat never ends: {event_info['repeat_never_ends']}")
    else:
        print(f"\n✗ Event '{event_uid}' not found")


def example_check_calendar_repeats():
    """Example 2: Check which events in a calendar have infinite repeats"""
    print("\n" + "=" * 70)
    print("Example 2: Check calendar repeat status")
    print("=" * 70)
    
    calendar_name = "背单词"
    has_forever, repeat_events = check_calendar_repeat_status(calendar_name)
    
    print(f"\nCalendar: {calendar_name}")
    print(f"  Has events that repeat forever: {has_forever}")
    print(f"  Total repeat events: {len(repeat_events)}")
    
    if repeat_events:
        print("\n  Repeat events:")
        for i, event in enumerate(repeat_events, 1):
            print(f"\n    [{i}] {event['summary']}")
            print(f"        RRULE: {event['rrule']}")
            print(f"        Never ends: {event['never_ends']}")


def example_list_all_events_in_calendar():
    """Example 3: List all events in a calendar"""
    print("\n" + "=" * 70)
    print("Example 3: List all events in a calendar")
    print("=" * 70)
    
    calendar_name = "背单词"
    events = get_calendar_events(calendar_name)
    
    print(f"\nCalendar: {calendar_name}")
    print(f"Total events: {len(events)}")
    
    print("\nEvent details:")
    for i, event in enumerate(events, 1):
        print(f"\n  [{i}] {event['summary']}")
        if event['rrule']:
            print(f"      RRULE: {event['rrule']}")
            print(f"      Never ends: {event['repeat_never_ends']}")
        else:
            print(f"      (No repeat rule)")


def example_find_all_infinite_repeat_events():
    """Example 4: Find all events across all calendars that repeat forever"""
    print("\n" + "=" * 70)
    print("Example 4: Find all events that repeat forever")
    print("=" * 70)
    
    # Common calendar names
    calendar_names = ["背单词", "Coding", "工作", "个人", "娱乐"]
    
    infinite_events = []
    
    for cal_name in calendar_names:
        has_forever, repeat_events = check_calendar_repeat_status(cal_name)
        
        for event in repeat_events:
            if event['never_ends']:
                infinite_events.append({
                    'calendar': cal_name,
                    'summary': event['summary'],
                    'rrule': event['rrule']
                })
    
    print(f"\nFound {len(infinite_events)} events that repeat forever:")
    
    if infinite_events:
        for i, event in enumerate(infinite_events, 1):
            print(f"\n  [{i}] {event['summary']}")
            print(f"      Calendar: {event['calendar']}")
            print(f"      RRULE: {event['rrule']}")
    else:
        print("\n  (None found)")


def example_analyze_rrule():
    """Example 5: Analyze different RRULE patterns"""
    print("\n" + "=" * 70)
    print("Example 5: Analyze RRULE patterns")
    print("=" * 70)
    
    test_rrules = [
        ("FREQ=DAILY", "每天，永远"),
        ("FREQ=WEEKLY;BYDAY=MO,WE,FR", "每周一、三、五，永远"),
        ("FREQ=DAILY;COUNT=30", "每天，30次"),
        ("FREQ=DAILY;UNTIL=20261231", "每天，直到2026年12月31日"),
        ("FREQ=MONTHLY;BYMONTHDAY=1", "每月1号，永远"),
        ("FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU", "每年9月第3个周日，直到1991年")
    ]
    
    print("\nRRULE analysis:")
    for rrule, description in test_rrules:
        never_ends = is_repeat_never_ends(rrule)
        print(f"\n  {description}")
        print(f"    RRULE: {rrule}")
        print(f"    Never ends: {never_ends}")


def main():
    """Run all examples"""
    print("\n" + "=" * 70)
    print("CalDAV Calendar Manager - Examples")
    print("=" * 70)
    
    # Run examples
    example_find_event_by_uid()
    example_check_calendar_repeats()
    example_list_all_events_in_calendar()
    example_find_all_infinite_repeat_events()
    example_analyze_rrule()
    
    print("\n" + "=" * 70)
    print("Examples completed!")
    print("=" * 70 + "\n")


if __name__ == "__main__":
    main()
