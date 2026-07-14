#!/usr/bin/env python3
"""
Task Finder CLI - 通过 ID 查找日历事件的工具
支持多种查找方式：
  - 按事件 UID 查找
  - 按日历名称查找
  - 按事件标题查找
  - 列出所有日历
"""

import sys
import argparse
from calendar_manager import (
    find_event_by_uid,
    find_calendar_by_id,
    get_calendar_events,
    check_calendar_repeat_status,
    is_repeat_never_ends
)
import logging

# 配置简单的日志（仅显示错误）
logging.basicConfig(level=logging.WARNING)


def print_event_details(event_info):
    """打印事件详细信息"""
    print("\n" + "=" * 70)
    print("📋 事件详情")
    print("=" * 70)
    print(f"日历:        {event_info['calendar_name']}")
    print(f"标题:        {event_info['summary']}")
    print(f"UID:         {event_info['uid']}")
    print(f"URL:         {event_info['url']}")
    
    if event_info['rrule']:
        print(f"\n🔄 重复规则")
        print("-" * 70)
        print(f"RRULE:       {event_info['rrule']}")
        print(f"永不截止:   {event_info['repeat_never_ends']}")
        
        # 解析 RRULE 的详细信息
        rrule = event_info['rrule']
        parts = rrule.split(';')
        print(f"\n详细参数:")
        for part in parts:
            print(f"  - {part}")
    else:
        print(f"\n⚠️  此事件没有重复规则（仅发生一次）")
    
    print("\n" + "=" * 70)


def find_by_uid(uid):
    """按 UID 查找事件"""
    print(f"\n🔍 正在查找 UID: {uid}")
    
    result = find_event_by_uid(uid)
    if result:
        cal, event_info = result
        print_event_details(event_info)
        return 0
    else:
        print(f"\n❌ 未找到 UID 为 '{uid}' 的事件")
        return 1


def find_by_calendar(calendar_name, search_term=None):
    """查看日历中的所有事件"""
    print(f"\n🔍 正在查找日历: {calendar_name}")
    
    events = get_calendar_events(calendar_name)
    
    if not events:
        print(f"\n❌ 日历 '{calendar_name}' 未找到或不包含任何事件")
        return 1
    
    # 如果指定了搜索词，则过滤
    if search_term:
        events = [e for e in events if search_term.lower() in e['summary'].lower()]
    
    print(f"\n✓ 找到 {len(events)} 个事件\n")
    print("-" * 70)
    
    for i, event in enumerate(events, 1):
        has_repeat = "🔄" if event['rrule'] else "  "
        never_ends = "♾️ " if event['repeat_never_ends'] else "  "
        print(f"[{i}] {has_repeat} {never_ends} {event['summary']}")
        if event['rrule']:
            print(f"     RRULE: {event['rrule']}")
    
    print("-" * 70)
    return 0


def find_by_title(calendar_name, title):
    """按标题查找事件"""
    print(f"\n🔍 在日历 '{calendar_name}' 中搜索: {title}")
    
    events = get_calendar_events(calendar_name)
    
    matching_events = [e for e in events if title.lower() == e['summary'].lower()]
    
    if not matching_events:
        print(f"\n❌ 未找到标题为 '{title}' 的事件")
        print(f"   提示: 使用 --list 查看所有事件")
        return 1
    
    print(f"\n✓ 找到 {len(matching_events)} 个匹配的事件\n")
    
    for event in matching_events:
        print(f"标题:      {event['summary']}")
        if event['rrule']:
            print(f"RRULE:     {event['rrule']}")
            print(f"永不截止: {event['repeat_never_ends']}")
        print()
    
    return 0


def list_all_calendars():
    """列出所有日历"""
    print("\n📚 所有日历:\n")
    
    # 获取几个常见的日历进行演示
    calendar_names = ["背单词", "Coding", "工作", "个人", "娱乐", "锻炼🏋️‍♀️运动"]
    
    for i, cal_name in enumerate(calendar_names, 1):
        print(f"[{i}] {cal_name}")
    
    print("\n💡 使用 --calendar <名称> 查看某个日历的事件")
    print("💡 使用 --uid <UID> 或 --title <标题> 查找具体事件")
    return 0


def check_repeat_status(calendar_name):
    """检查日历中的永不截止的重复事件"""
    print(f"\n🔍 检查日历 '{calendar_name}' 中的重复事件状态...\n")
    
    has_forever, repeat_events = check_calendar_repeat_status(calendar_name)
    
    if not repeat_events:
        print(f"❌ 日历 '{calendar_name}' 未找到或不包含重复事件")
        return 1
    
    print(f"📊 重复事件统计:")
    print(f"  - 总重复事件数: {len(repeat_events)}")
    print(f"  - 永不截止的事件: {sum(1 for e in repeat_events if e['never_ends'])}")
    print()
    
    for i, event in enumerate(repeat_events, 1):
        status = "♾️ 永不截止" if event['never_ends'] else "⏱️  有截止"
        print(f"[{i}] {status} - {event['summary']}")
        print(f"     RRULE: {event['rrule']}")
    
    return 0


def main():
    parser = argparse.ArgumentParser(
        description='CalDAV 任务查找工具 - 通过 ID/名称/标题查找日历事件',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例:
  # 按 UID 查找事件
  %(prog)s --uid DA640753-2A56-4DB0-91BD-094374BDBAD6
  
  # 查看"Practice"日历中的所有事件
  %(prog)s --calendar Practice
  
  # 在"Tasks"日历中搜索"开会"
  %(prog)s --calendar Tasks --search 开会
  
  # 查找标题为"Daily Practice"的事件
  %(prog)s --title Daily Practice --calendar Practice
  
  # 检查"Practice"日历中的重复事件状态
  %(prog)s --calendar Practice --check-repeat
  
  # 列出所有可用的日历
  %(prog)s --list-calendars
        """
    )
    
    parser.add_argument('--uid', help='按事件 UID 查找 (UUID 格式)')
    parser.add_argument('--calendar', help='指定日历名称', default=None)
    parser.add_argument('--title', help='按事件标题查找（需要指定 --calendar）')
    parser.add_argument('--search', help='在日历中搜索关键词（需要指定 --calendar）')
    parser.add_argument('--list-calendars', action='store_true', help='列出所有可用的日历')
    parser.add_argument('--check-repeat', action='store_true', help='检查日历中的重复事件状态（需要指定 --calendar）')
    
    args = parser.parse_args()
    
    # 如果没有提供任何参数，显示帮助
    if not any([args.uid, args.calendar, args.list_calendars, args.title, args.search, args.check_repeat]):
        parser.print_help()
        return 0
    
    # 处理各种查找模式
    try:
        if args.list_calendars:
            return list_all_calendars()
        
        if args.uid:
            return find_by_uid(args.uid)
        
        if args.check_repeat:
            if not args.calendar:
                print("❌ 使用 --check-repeat 需要指定 --calendar")
                return 1
            return check_repeat_status(args.calendar)
        
        if args.title:
            if not args.calendar:
                print("❌ 使用 --title 查找需要指定 --calendar")
                return 1
            return find_by_title(args.calendar, args.title)
        
        if args.calendar:
            if args.search:
                return find_by_calendar(args.calendar, args.search)
            else:
                return find_by_calendar(args.calendar)
        
    except Exception as e:
        print(f"\n❌ 错误: {e}")
        return 1
    
    return 0


if __name__ == "__main__":
    sys.exit(main())
