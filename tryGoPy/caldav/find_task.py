#!/usr/bin/env python3
"""
快速任务查找脚本 - 简化的命令行界面

快捷用法:
  find 工作                          # 列出"Tasks" calendar的所有事件
  find Tasks review                      # 在"Tasks"日历中搜索"review"
  find --uid DA640753-2A56...       # 按 UUID 查找
  find --list                        # 列出所有日历
"""

import sys
from task_finder import (
    find_by_uid, find_by_calendar, find_by_title, 
    list_all_calendars, check_repeat_status
)


def print_usage():
    """打印使用说明"""
    print("""
🔍 任务查找工具 - 快速查询指南

基本用法:
  python3 find_task.py <日历> [搜索词]     - 在日历中查找事件
  python3 find_task.py --uid <UID>        - 按 UUID 查找
  python3 find_task.py --list             - 列出所有日历
  python3 find_task.py --help             - 显示详细帮助

示例:
  1. 列出所有日历
     python3 find_task.py --list
  
  2. 查看"Practice"日历中的所有事件
     python3 find_task.py Practice
  
  3. 在"Tasks"日历中搜索"review"
     python3 find_task.py Tasks review
  
  4. 按 UUID 查找具体事件
     python3 find_task.py --uid DA640753-2A56-4DB0-91BD-094374BDBAD6
  
  5. 检查"Practice"日历中的重复事件
     python3 find_task.py Practice --repeat-check

💡 更多选项，运行: python3 task_finder.py --help
    """)


def main():
    if len(sys.argv) < 2:
        print_usage()
        return 0
    
    # 处理特殊标志
    if sys.argv[1] in ['--help', '-h', 'help']:
        print_usage()
        return 0
    
    if sys.argv[1] in ['--list', '-l', 'list']:
        return list_all_calendars()
    
    if sys.argv[1] == '--uid':
        if len(sys.argv) < 3:
            print("❌ 需要提供 UID 参数")
            print("用法: python3 find_task.py --uid <UID>")
            return 1
        return find_by_uid(sys.argv[2])
    
    # 解析日历名称和搜索词
    calendar_name = sys.argv[1]
    search_term = None
    check_repeat = False
    
    if len(sys.argv) > 2:
        if sys.argv[2] == '--repeat-check':
            check_repeat = True
        else:
            search_term = sys.argv[2]
    
    # 检查重复状态
    if check_repeat:
        return check_repeat_status(calendar_name)
    
    # 搜索
    return find_by_calendar(calendar_name, search_term)


if __name__ == "__main__":
    sys.exit(main())
