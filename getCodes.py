import os
import re
import time
import datetime


def genSolutionPart(num):
    suffix2markdowncode = {
        'cpp': ('cpp', 'C++'),
        'py': ('python', 'Python'),
        'c': ('c', 'C语言'),
    }
    today4code = []
    for file in os.listdir('Codes'):
        first = file.split('-')[0]
        try:
            first = int(first)
        except:
            pass
        if first != num:
            continue
        print(file)
        with open(os.path.join('Codes', file), 'r', encoding='utf-8') as f:
            data = f.read()
        time_pattern = re.compile(r"(\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2}):(\d{2})")
        match = time_pattern.search(data)
        if not match:
            print('time not found')
            continue
        year, month, day, hour, miunte, second = map(int, match.groups())
        fileDay = f'{year:04d}-{day:02d}-{month:02d}'
        today = datetime.date.today().strftime('%Y-%d-%m')
        if fileDay != today:
            print(f'{fileDay} != {today}')
            continue
        today4code.append(os.path.join('Codes', file))
    # TODO: 一题两解的支持
    result = """
## 解题方法：xx

11111

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码
"""
    for file in today4code:
        fileType = os.path.splitext(file)[-1]
        if fileType.startswith('.'):
            fileType = fileType[1:]
        markdowncode = suffix2markdowncode[fileType]
        with open(file, 'r', encoding='utf-8') as f:
            data = f.read()
        # data = removePrefix(data, fileType)  # TODO: 移除前面注释以及其他头部文件
        result += f'\n#### {markdowncode[1]}\n\n```{markdowncode[0]}\n{data}\n```\n'
    return result


result = genSolutionPart(994)  # 今日是2024.5.13
print(result)
