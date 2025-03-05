'''
Author: LetMeFly
Date: 2022-07-03 11:21:14
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-05 22:09:22
Command: python newSolution.py 102. 二叉树的层序遍历
What's more: 当前仅支持数字开头的题目
What's more: 代码结构写的很混乱 - 想单文件实现所有操作
'''
import os
import re
import sys
import time
import datetime
import subprocess
from urllib.parse import quote


argv = sys.argv
print(argv)

num = int(argv[1][:-1])
title = ""
for i in range(2, len(argv)):
    if i != 2:
        title += " "
    title += argv[i]
nameProblem = "AllProblems/{0}.{1}.md".format(num, title)
print(nameProblem)

title = ""
for i in range(2, len(argv)):
    title += argv[i]

timeURL = time.strftime("%Y/%m/%d", time.localtime())
solutionURLll = "https://blog.letmefly.xyz/{0}/LeetCode%20{1:04d}.{2}/".format(timeURL, num, quote(title, "utf-8"))
solutionURLll_humanable = "https://blog.letmefly.xyz/{0}/LeetCode {1:04d}.{2}/".format(timeURL, num, title)
print(solutionURLll)

with open(nameProblem, "r", encoding="utf-8") as f:
    problem = f.read()


def genSolutionPart(num):
    suffix2markdowncode = {
        'cpp': ('cpp', 'C++'),  # markdown、汉语名
        'py': ('python', 'Python'),
        'c': ('c', 'C语言'),
        'java': ('java', 'Java'),
        'go': ('go', 'Go')
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
    for thisFileType in suffix2markdowncode:  # 修改题解中的展示顺序为suffix2markdowncode中出现的顺序而不是后缀字典序(复杂度可优化但没必要)
        for file in today4code:
            fileType = os.path.splitext(file)[-1]
            if fileType.startswith('.'):
                fileType = fileType[1:]
            if fileType != thisFileType:
                continue
            markdowncode = suffix2markdowncode[fileType]
            with open(file, 'r', encoding='utf-8') as f:
                data = f.read()
            # data = removePrefix(data, fileType)  # TODO: 移除前面注释以及其他头部文件
            result += f'\n#### {markdowncode[1]}\n\n```{markdowncode[0]}\n{data}\n```\n'
    return result


solution = problem + genSolutionPart(num) +"""
> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接]({0})哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
""".format(solutionURLll)  # .format(solutionURLll, solutionURLll_humanable)

def refreshPublistTime(solution: str) -> str:
    splited = solution.split("\n")
    splited[2] = "date: " + time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    return "\n".join(splited)

solution = refreshPublistTime(solution)
print(solution)

solutionName = "Solutions/LeetCode {0:04d}.{1}.md".format(num, title)
with open(solutionName, "x", encoding="utf-8") as f:
    f.write(solution)

# 认领issue
os.system(f'git checkout -b {num}')
issueCreateResult = os.popen(f'gh issue create -t "Who can add 1 more problem of {num}" -b "By newSolution.py using GH" -l "题解" -a "@me"').read()
print(issueCreateResult)
issueNum = int(issueCreateResult.split('\n')[0].split('/')[-1])

print("请编辑题解: “{0}”，注意不要更改文件前5行".format(solutionName))

print("请去掉可能的由其他插件自动生成的头部注释信息，并保存你所编辑的题解")
csdnid = input("请输入CSDN题解文章的id(11022152)：")
solutionURLcs = "https://letmefly.blog.csdn.net/article/details/{0}".format(csdnid)

with open(solutionName, "r", encoding="utf-8") as f:
    solution = f.read()

solution = solution.replace("--------------------------", csdnid)
# solution = solution.replace("--------------------------", csdnid)

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
        return """|{0:04d}.{1}|{2}|<a href="{3}" target="_blank">题目地址</a>|<a href="{4}" target="_blank">题解地址</a>|<a href="https://letmefly.blog.csdn.net/article/details/{5}" target="_blank">CSDN题解</a>|<a href="{6}" target="_blank">LeetCode题解</a>|""".format(num, title, getHard(), getProblemUrl(), solutionURLll, csdnid, solutionURLlc)
    splited.insert(i, generateNewLine())
    return "\n".join(splited)

readme = readmeNewLine(readme)
print(readme)
with open("README.md", "w", encoding="utf-8") as f:
    f.write(readme)

# commit push pr merge delete-branch
os.system('git add .')
os.system(f'git commit -s -m "update: 添加问题“{num}.{title}”的代码和题解"')
os.system(f'git push --set-upstream origin {num}')
cmd = f'gh pr create -t "添加问题“{num}.{title}”的代码和题解" -b "By newSolution.py using GH | close: #{issueNum}" -l "题解" -a "@me"'
prResult = os.popen(cmd).read()
print(prResult)
prNumber = int(prResult.split('/')[-1])
input('enter when ready to merge:')  # 万一给带密码的东西merge了就无法恢复了(虽然这个仓库一次都没有过)
# os.system(f'gh pr merge {prNumber} -r -d')  # rebase没有verified的标，且sha也不一样
def get_commit_diff():
    # 获取题解分支比master多出的提交次数
    try:
        count = int(subprocess.check_output(
            ['git', 'rev-list', '--count', f'master..{num}'],
            stderr=subprocess.DEVNULL  # 屏蔽错误输出
        ).decode().strip())
    except subprocess.CalledProcessError:
        print("无法获取提交差异，请确认分支存在")
        return 1
    return count
commitCount = get_commit_diff()
if commitCount < 2:  # 直接本地merge，即不是rebase又减少一次merge记录 | 这个merge大概不会产生冲突
    os.system(f'git switch master')
    os.system(f'git merge {num}')
    os.system(f'git push')
    os.system(f'git branch -d {num}')
    os.system(f'git push --delete origin {num}')
else:  # 使用gh在github上通过squash的方式merge | 在本地squash merge并push的话github无法自动识别并关闭pr
    os.system(f'gh pr merge -s -d  -t "update: 添加问题“{num}.{title}”的代码和题解" -b "Signed-off-by: LetMeFly666 <814114971@qq.com>"')
# https://github.com/LetMeFly666/LeetCode/blob/3435204860a8a85aa666618d90f40916dc70a1f1/reassign.py
def syncGitcodeCSDN():
    nowCWD = os.getcwd()
    os.chdir('OtherSource/gitcode_knowledge')
    os.system('git pull --force')
    # 判断一个commit是否按配置签名
    def verify_commit(commit_hash: str) -> bool:
        result = subprocess.run(
            ['git', 'verify-commit', commit_hash],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        return not result.returncode
    # 获取一个commit的上一个commit
    def get_parent_commit(commit_hash: str) -> str:
        result = subprocess.run(
            ['git', 'log', commit_hash, '--pretty=%H', '-n', '2'],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        return result.stdout.decode('utf-8').strip().split()[-1]
    # 将从某次commit开始至HEAD的所有commit重新签名
    def re_assign(commit_hash: str) -> None:
        # cmd = f'git filter-branch -f --commit-filter \'git commit-tree -S "$@";\' {commit_hash}..HEAD'
        # print(cmd)
        # os.system(cmd)
        env = os.environ.copy()
        env['FILTER_BRANCH_SQUELCH_WARNING'] = "1"
        result = subprocess.run(
            ["git", "filter-branch", "-f", "--commit-filter", 'git commit-tree -S "$@";', f"{commit_hash}..HEAD"],
            env=env,
        )
        print(result.returncode)
        # subprocess.Popen(cmd)
    def re_assign_main():
        # re_assign('HEAD~2')
        # return
        if verify_commit('HEAD'):  # HEAD的签名也能被验证
            return
        notVerified = 'HEAD'
        while True:
            next = get_parent_commit(notVerified)
            if next == notVerified:
                break
            notVerified = next
            if verify_commit(next):
                break
        print(notVerified)
        re_assign(notVerified)
    re_assign_main()
    os.system('git push --force')  # resign gitcode
    os.system('git push Let main:From_GitCode_CSDN')
    os.chdir(nowCWD)
syncGitcodeCSDN()
