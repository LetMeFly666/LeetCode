'''
Author: LetMeFly
Date: 2024-04-14 10:15:21
LastEditors: LetMeFly
LastEditTime: 2024-04-14 11:25:32
Description: 统计1000天内（及总）文件信息
Description: 依据：文件中是否包含1000天的日期时间字符串
Description: 仅依据第一个时间字符串，仅捕获%Y-%m-%d %H-%M-%s的时间格式
'''
import re
from datetime import datetime, timedelta
import os


# t = '5452024-04-14 10:15:21454\n2024-04-14 10:35:34'
# time_pattern = re.compile(r"(\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2}):(\d{2})")
# match = time_pattern.search(t)
# print(match)


# t = 'epit: [hello, world]\ntags: [其他, 知识, 日语, Notes]\nsf: [hello, world]'
# matches = re.search(r"tags: \[(.*?)\]", t)
# if matches:
#     tags = matches.group(1).split(", ")
#     print(tags)
# exit(0)
    

tiJieIn1000, notTiJieIn1000 = 0, 0


def ifin1000file(filename):
    global tiJieIn1000, notTiJieIn1000
    with open(filename, 'r', encoding='utf-8') as f:
        time_str = f.read()
    time_pattern = re.compile(r"(\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2}):(\d{2})")
    match = time_pattern.search(time_str)
    if not match:
        return False
    year, month, day, hour, miunte, second = map(int, match.groups())
    file_time = datetime(year, month, day)
    current_time = datetime(2024, 4, 14)
    delta = current_time - file_time
    if delta <= timedelta(days=1000):
        # print(f'1000天内：{filename} - {match}')
        matches = re.search(r"tags: \[(.*?)\]", time_str)
        if matches:
            tags = matches.group(1).split(", ")
            if '题解' in tags:
                tiJieIn1000 += 1
            else:
                notTiJieIn1000 += 1
    else:
        print(f'1000天外：{filename} - {match}')
    return delta <= timedelta(days=1000)


"""统计一个文件夹下的所有文件，并返回：文件总数、1000天内的文件总数、文件总大小、1000天内的文件总大小"""
def statistic1(baseDir):
    print(baseDir)
    cnt, cntIn100, size, sizeIn1000 = 0, 0, 0, 0
    for file in os.listdir(baseDir):
        file = os.path.join(baseDir, file)
        if not os.path.isfile(file):
            continue
        fileSize = os.stat(file).st_size
        cnt += 1
        size += fileSize
        if ifin1000file(file):
            cntIn100 += 1
            sizeIn1000 += fileSize
    return cnt, cntIn100, size, sizeIn1000


codesCnt, codesCntIn1000, codesSize, codesSizeIn1000 = statistic1(os.path.abspath(os.path.join(os.getcwd(), 'Codes')))
solutionCnt, solutionCntIn1000, solutionSize, solutionSizeIn1000 = statistic1(os.path.abspath(os.path.join(os.getcwd(), 'Solutions')))
print(codesCnt, codesCntIn1000, codesSize, codesSizeIn1000)
print(solutionCnt, solutionCntIn1000, solutionSize, solutionSizeIn1000)
print(tiJieIn1000, notTiJieIn1000)


"""
1000天外：F:\OtherApps\Program\Git\Store\Store20_LeetCode\Codes\0274-h-index.cpp - <re.Match object; span=(34, 53), match='2021-07-11 13:31:02'>
1000天外：F:\OtherApps\Program\Git\Store\Store20_LeetCode\Codes\0374-guess-number-higher-or-lower.cpp - <re.Match object; span=(34, 53), match='2021-06-14 09:24:03'>
1000天外：F:\OtherApps\Program\Git\Store\Store20_LeetCode\Codes\1049-last-stone-weight-ii.cpp - <re.Match object; span=(34, 53), match='2021-06-08 11:08:49'>
1000天外：F:\OtherApps\Program\Git\Store\Store20_LeetCode\Codes\1711-count-good-meals.cpp - <re.Match object; span=(34, 53), match='2021-07-07 08:22:47'>
1000天外：F:\OtherApps\Program\Git\Store\Store20_LeetCode\Codes\1846-maximum-element-after-decreasing-and-rearranging.cpp - <re.Match object; span=(34, 53), match='2021-07-15 10:32:58'>
1000天外：F:\OtherApps\Program\Git\Store\Store20_LeetCode\Codes\Offer0051-zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof.cpp - <re.Match object; span=(34, 53), match='2021-07-16 20:38:30'>
F:\OtherApps\Program\Git\Store\Store20_LeetCode\Solutions
1329 1289 1426499 1399801
676 676 3494704 3494704
596 80
"""

"""我的友圈文案
力扣每日一题打卡1000天~
1k天里共写了1.33M(1399801字节)的算法题代码，596篇题解和80篇技术博客(3.33M=3494704字节)。
每天10-30分钟，为的是保持身为“程序猿”的手感[发抖]期待未来的每一天
http://blog.letmefly.xyz/
"""

"""GPT生成的可参考的文案：
今天是我坚持力扣每日一题的第1000天。这不仅仅是关于编程，更是关于毅力和成长的旅程。每天的挑战都让我更接近于成为更好的自己。感谢这段旅程，也期待未来的每一天。#力扣1000天# #每日一题# #编程之路#
"""