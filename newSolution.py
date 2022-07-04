'''
Author: LetMeFly
Date: 2022-07-03 11:21:14
LastEditors: LetMeFly
LastEditTime: 2022-07-04 23:15:53
Command: python newSolution.py 102. 二叉树的层序遍历
What's more: 当前仅支持数字开头的题目
'''
import sys
import time
from urllib.parse import quote

from numpy import linspace

argv = sys.argv
print(argv)

num = int(argv[1][:-1])
title = ""
for i in range(2, len(argv)):
    # if i != 2:
    #     title += " "
    title += argv[i]
nameProblem = "AllProblems/{0}.{1}.md".format(num, title)
print(nameProblem)

solutionURLll = "https://leetcode.letmefly.xyz/{0}/LeetCode%20{1:04d}.{2}/".format(time.strftime("%Y/%m/%d", time.localtime()), num, quote(title, "utf-8"))
print(solutionURLll)

with open(nameProblem, "r", encoding="utf-8") as f:
    problem = f.read()

solution = problem + """
## 方法一：xx

11111

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp

```

> 同步发文于CSDN，原创不易，转载请附上[原文链接]({0})哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/--------------------------](https://letmefly.blog.csdn.net/article/details/--------------------------)
""".format(solutionURLll)

def refreshPublistTime(solution: str) -> solution:
    splited = solution.split("\n")
    splited[2] = "date: " + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    return "\n".join(splited)

solution = refreshPublistTime(solution)
print(solution)

solutionName = "Solutions/LeetCode {0:04d}.{1}.md".format(num, title)
with open(solutionName, "w", encoding="utf-8") as f:
    f.write(solution)
print("请编辑题解: “{0}”，注意不要更改文件前5行".format(solutionName))

print("请去掉可能的由其他插件自动生成的头部注释信息")
csdnid = input("请输入CSDN题解文章的id(11022152)：")
solutionURLcs = "https://letmefly.blog.csdn.net/article/details/{0}".format(csdnid)

with open(solutionName, "r", encoding="utf-8") as f:
    solution = f.read()

solution = solution.replace("--------------------------", csdnid)
solution = solution.replace("--------------------------", csdnid)

with open(solutionName, "w", encoding="utf-8") as f:
    f.write(solution)

print("请重新复制所有的题解内容，并粘贴到CSDN中发布")
print("请在LeetCode中新建、编辑并发布题解")

solutionURLlc = input("LeetCode题解的url: ")

with open("README.md", "r", encoding="utf-8") as f:
    readme = f.read()

def readmeNewLine(readme: str) -> str:
    splited = readme.split("\n")
    def getTiJieBeginEnd(splited: list) -> tuple:
        begin, end = 0, 0
        for i in range(len(splited)):
            if splited[i] == "|题目名称|困难程度|题目地址|题解地址|CSDN题解|LeetCode题解|":
                begin = i + 2
            lineSplited = splited[i].split("|")
            if begin and i >= begin:
                if not ord('0') <= ord(lineSplited[1][0]) <= ord('9'):
                    end = i
                    break
        return (begin, end)
    beginLine, endLine = getTiJieBeginEnd(splited)
    print(beginLine, endLine)
    haveBigger = False
    for i in range(beginLine, endLine):
        thisNum = int(splited[i].split("|")[1].split(".")[0])
        if thisNum > num:
            haveBigger = True
            break
    if not haveBigger:
        i = endLine
    def generateNewLine():
        def getHard():
            solutionSplited = solution.split("\n")
            tags = solutionSplited[3]
            realTags = tags.split("tags: [")[1][:-1].split(", ")
            if "简单" in realTags:
                return "简单"
            elif "中等" in realTags:
                return "中等"
            elif "困难" in realTags:
                return "困难"
            else:
                return input("自动获取难易程度失败！请手动输入[简单/中等/困难]并检查代码: ")
        def getProblemUrl():
            tempUrl = solutionURLlc
            if tempUrl[len(tempUrl) - 1] != '/':
                tempUrl += "/"
            splitedUrl = tempUrl.split("/")
            del splitedUrl[len(splitedUrl) - 3]
            del splitedUrl[len(splitedUrl) - 2]
            return "/".join(splitedUrl)
        return """|{0:04d}.{1}|{2}|<a href="{3}" target="_blank">地址点我</a>|<a href="{4}" target="_blank">地址点我</a>|<a href="https://letmefly.blog.csdn.net/article/details/{5}" target="_blank">地址点我</a>|<a href="{6}" target="_blank">地址点我</a>|""".format(num, title, getHard(), getProblemUrl(), solutionURLll, csdnid, solutionURLlc)
    splited.insert(i, generateNewLine())
    return "\n".join(splited)

readme = readmeNewLine(readme)
print(readme)
with open("README.md", "w", encoding="utf-8") as f:
    f.write(readme)
