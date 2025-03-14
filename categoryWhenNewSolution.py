'''
Author: LetMeFly
Date: 2025-03-14 09:49:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-14 09:51:50
Command: python categoryWhenNewSolution.py 3340. 检查平衡字符串
'''
import sys
import time


argv = sys.argv
num = int(argv[1][:-1])
title = ""
for i in range(2, len(argv)):
    if i != 2:
        title += " "
    title += argv[i]
nameProblem = "AllProblems/{0}.{1}.md".format(num, title)

with open(nameProblem, "r", encoding="utf-8") as f:
    problem = f.read()

solution = problem
def refreshPublistTime(solution: str) -> str:
    splited = solution.split("\n")
    splited[2] = "date: " + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    splited.insert(4, 'categories: [题解, LeetCode]')
    return "\n".join(splited)

solution = refreshPublistTime(solution)
print(solution)
