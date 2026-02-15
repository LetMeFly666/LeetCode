'''
Author: LetMeFly
Date: 2022-07-03 11:21:14
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-15 17:41:48
Command: python newSolution.py 102. 二叉树的层序遍历
What's more: 当前仅支持数字开头的题目
What's more: 代码结构写的很混乱 - 想单文件实现所有操作
'''
import os
import re
import ast
import sys
import json
import time
import shutil
import datetime
import subprocess
from enum import Enum
from urllib.parse import quote

argv = sys.argv
print(argv)
CODES_TO_GEN = ['cpp', 'python3', 'golang', 'java', 'rust']  # 参考“AllProblems/_mappingData.json”

num = int(argv[1][:-1])
title = ""
for i in range(2, len(argv)):
    if i != 2:
        title += " "
    title += argv[i]
nameProblem = "AllProblems/{0}.{1}/{0}.{1}.md".format(num, title)
print(nameProblem)

# ===================== 生成代码模板 =====================
def normalizePyCode(code: str) -> str:
    """给不完整的class/def补上 pass"""
    lines = code.splitlines()
    new_lines = []
    for i, line in enumerate(lines):
        new_lines.append(line)
        if re.match(r'^\s*def\s+\w+\(.*\)\s*(->\s*.*)?:\s*$', line):
            new_lines.append(" " * (len(line) - len(line.lstrip()) + 4) + "pass")
    if lines and re.match(r'^\s*class\s+\w+\s*.*:\s*$', lines[-1]):
        new_lines.append("    pass")
    return "\n".join(new_lines)
def needsImportTyping(code: str, toImport: str = 'List') -> bool:
    code = normalizePyCode(code)  # 先补全
    tree = ast.parse(code)
    class ListChecker(ast.NodeVisitor):
        def __init__(self):
            self.uses_list = False
        def visit_Name(self, node):
            if node.id == toImport:
                self.uses_list = True
            self.generic_visit(node)
        def visit_Attribute(self, node):
            if isinstance(node.value, ast.Name) and node.value.id == "typing" and node.attr == toImport:
                self.uses_list = True
            self.generic_visit(node)
    checker = ListChecker()
    checker.visit(tree)
    return checker.uses_list
alreadyExists = False
with open(f'AllProblems/{num}.{title}/titleSlug.txt', 'r', encoding='utf-8') as f:
    titleSlug = f.read()
with open(f'AllProblems/_mappingData.json', 'r', encoding='utf-8') as f:
    mappingData = json.loads(f.read())
mappingSuffix: dict = mappingData["templateSlug2sourceCodeFilePrefix"]["data"]
alreadyCodes = os.listdir('Codes')
for code2gen in CODES_TO_GEN:
    toName = f'{num:04}-{titleSlug}.{mappingSuffix[code2gen]}'
    if toName in alreadyCodes:
        alreadyExists = True
        break
dateSuffix = '_' + datetime.datetime.now().strftime("%Y%m%d") if alreadyExists else ''
for code2gen in CODES_TO_GEN:
    toName = f'Codes/{num:04}-{titleSlug}{dateSuffix}.{mappingSuffix[code2gen]}'
    fromName = f'AllProblems/{num}.{title}/code.{mappingSuffix[code2gen]}'
    print(toName)
    if not os.path.exists(toName):
        shutil.copy(fromName, toName)
    # rust - 更新lib.rs （若同时多个pr改代码则这里很容易冲突）
    if code2gen == 'rust':
        with open("Codes/lib.rs", "r+", encoding="utf-8") as f:
            content = f.read()
            relativePath = toName.removeprefix('Codes/')
            content = re.sub(r'include!\(".*?"\);', f'include!("{relativePath}");', content, count=1)
            f.seek(0)
            f.write(content)
            f.truncate()
    elif code2gen == 'cpp':
        with open(toName, 'r+', encoding='utf-8') as f:
            content = f.read()
            f.seek(0)
            header = '#if defined(_WIN32) || defined(__APPLE__)\n' +\
                     '#include "_[1,2]toVector.h"\n' +\
                     '#endif\n\n'
            f.write(header + content)
    elif code2gen == 'python3':
        with open(toName, 'r+', encoding='utf-8') as f:
            content = f.read()
            if needsImportTyping(content, 'Optional'):  # 这样得ast两次，算了无所谓了暂时
                f.seek(0)
                header = 'from typing import Optional\n\n'
                f.write(header + content)
            if needsImportTyping(content):
                f.seek(0)
                header = 'from typing import List\n\n'
                f.write(header + content)
    elif code2gen == 'golang':
        with open(toName, 'r+', encoding='utf-8') as f:
            content = f.read()
            f.seek(0)
            header = 'package main\n\n'
            f.write(header + content)

title = ""
for i in range(2, len(argv)):
    title += argv[i]

timeURL = time.strftime("%Y/%m/%d", time.localtime())
solutionURLll = "https://blog.letmefly.xyz/{0}/LeetCode%20{1:04d}.{2}/".format(timeURL, num, quote(title, "utf-8"))
solutionURLll_humanable = "https://blog.letmefly.xyz/{0}/LeetCode {1:04d}.{2}/".format(timeURL, num, title)
print(solutionURLll)

# 获取最后一次commit的sha
def get_latest_commit_sha() -> str:
    try:
        # 执行 git log 命令获取最后一次提交的 SHA
        sha = subprocess.check_output(['git', 'log', '-1', '--pretty=format:%H']).decode('utf-8').strip()
        return sha
    except subprocess.CalledProcessError as e:
        print(f"Error: {e}")
        return None
lastSHA = get_latest_commit_sha()

# whoami
class User(Enum):
    Tisfy = "Tisfy"
    LetMeFly = "LetMeFly666"

    @property
    def remote(self) -> str:
        return {
            User.Tisfy: 'tisfy',
            User.LetMeFly: 'origin',
        }[self]

def get_whoami() -> User:
    name = subprocess.check_output(
        ["git", "config", "user.name"],
        stderr=subprocess.DEVNULL
    ).decode().strip()
    return User(name)
WHOAMI = get_whoami()
print(f'now {WHOAMI} working.')
REMOTE = WHOAMI.remote

# 认领issue
os.system(f'git checkout -b {num}')
os.system(f'git push --set-upstream {REMOTE} {num}')  # (#832)
def getPlatform():
    platform = sys.platform
    if platform == 'win32':
        return 'Windows'
    elif platform == 'darwin':
        return 'MacOS'
    else:
        return 'Linux(or others)'
issueTitle = f'[newSolution]Who can add 1 more problem of LeetCode {num}'  # (#872)
# alreadyRelatedIssueLists = os.popen(f'gh issue list --search "{issueTitle}"').read()
tmp_issueGetResult = subprocess.run(
    ['gh', 'issue', 'list', '--search', issueTitle],
    stdout=subprocess.PIPE,
    text=True,
    encoding='utf-8'
)
alreadyRelatedIssueLists = tmp_issueGetResult.stdout
alreadyRelatedIssueListsSplited = alreadyRelatedIssueLists.split('\n')
print(alreadyRelatedIssueLists)
print(alreadyRelatedIssueListsSplited)
issueNum = 0
for line in alreadyRelatedIssueListsSplited:
    if issueTitle in line:
        issueNum = int(line.split()[0])
print(issueNum)
if not issueNum:
    issueCreateResult = os.popen(f'gh issue create -t "{issueTitle}" -b "By [newSolution.py](https://github.com/LetMeFly666/LeetCode/blob/{lastSHA}/newSolution.py) using GH on {getPlatform()} | [{num}.{title}](https://leetcode.cn/problems/{titleSlug}) " -l "题解" -l "solving" -a "@me"').read()
    print(issueCreateResult)
    issueNum = int(issueCreateResult.split('\n')[0].split('/')[-1])
else:
    os.popen(f'gh issue edit {issueNum} --add-label "solving"')  # 这里暂不read等待popen执行完毕，这里的小异步是被允许的
    os.popen(f'gh issue comment {issueNum} -b "hello #{issueNum} you are not alone now(/again)."')

input('代码写完后按回车生成题解模板：')

with open(nameProblem, "r", encoding="utf-8") as f:
    problem = f.read()

def genSolutionPart(num):
    suffix2markdowncode = {
        'cpp': ('cpp', 'C++'),  # markdown、汉语名
        'py': ('python', 'Python'),
        'c': ('c', 'C语言'),
        'java': ('java', 'Java'),
        'go': ('go', 'Go'),
        'rs': ('rust', 'Rust')
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
        if not os.path.isfile(os.path.join('Codes', file)): # 1075
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
        fileDay = f'{year:04d}-{month:02d}-{day:02d}'  # What 之前咋写的year-day-month
        fileDay = datetime.datetime.strptime(fileDay, '%Y-%m-%d').date()
        today = datetime.date.today()
        deltaDays = (today - fileDay).days
        if deltaDays > 5 or deltaDays < -1:  # 最多接受5天前的或“明天的”(暂且视为时差)
            if deltaDays > 5:
                print(f'{fileDay} ~ {today} = {deltaDays} days > 5 days')
            else:
                print(f'{today} ~ {fileDay}: future {-deltaDays} days?')
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
    splited.insert(4, 'categories: [题解, LeetCode]')
    return "\n".join(splited)

solution = refreshPublistTime(solution)
print(solution)

solutionName = "Solutions/LeetCode {0:04d}.{1}.md".format(num, title)
solutionExists = os.path.exists(solutionName)
if not solutionExists:
    with open(solutionName, "w", encoding="utf-8") as f:
        f.write(solution)

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
else:
    input(f'手动更新完 {solutionName} 了吗？: ')
    # TODO: 有空时候可以写个手动更新题解中代码的函数 - 最简单的办法是代码追加到(最后一种方法的)后面然后手动删

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
            del splitedUrl[len(splitedUrl) - 2]
            del splitedUrl[len(splitedUrl) - 2]
            del splitedUrl[len(splitedUrl) - 2]  # solutions
            return "/".join(splitedUrl)
        return """|{0:04d}.{1}|{2}|<a href="{3}" target="_blank">题目地址</a>|<a href="{4}" target="_blank">题解地址</a>|<a href="https://letmefly.blog.csdn.net/article/details/{5}" target="_blank">CSDN题解</a>|<a href="{6}" target="_blank">LeetCode题解</a>|""".format(num, title, getHard(), getProblemUrl(), solutionURLll, csdnid, solutionURLlc)
    splited.insert(i, generateNewLine())
    return "\n".join(splited)

if not solutionExists:
    readme = readmeNewLine(readme)
    print(readme)
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(readme)

if solutionExists:
    gitCommitMsgPrefix = f'update: 添加问题“{num}.{title}”的代码(并更新其题解)'
else:
    gitCommitMsgPrefix = f'update: 添加问题“{num}.{title}”的代码和题解'
if os.path.exists('.commitTitleExtra'):
    with open('.commitTitleExtra', 'r', encoding='utf-8') as f:
        gitCommitMsgPrefix += f.read().replace("\n", " ")

# commit push pr merge delete-branch
os.system('git add .')
def getPrOrIssueMaxNum(prOrIssue: str) -> int:  # (#811)
    print(f'max {prOrIssue} number:', end=' ')
    sys.stdout.flush()
    cmd = ['gh', prOrIssue, 'list', '--state', 'all', '--limit', '1', '--json', 'number']
    result = subprocess.run(cmd, capture_output=True, text=True, check=True)
    data = json.loads(result.stdout)
    print(data)
    return data[0]['number']
lastNum = max(getPrOrIssueMaxNum('pr'), getPrOrIssueMaxNum('issue'))
print(lastNum)
commitMsg = f'{gitCommitMsgPrefix} (#{lastNum + 1})'
if os.path.exists('.commitmsg') and os.path.isfile('.commitmsg'):  # (#795)
    with open('.commitmsg', 'r', encoding='utf-8') as f:
        commitMsgFromfile = f.read()
    if not commitMsgFromfile.startswith('\n'):
        commitMsgFromfile = '\n' + commitMsgFromfile
    commitMsg += commitMsgFromfile
subprocess.run(['git', 'commit', '-s', '-m', commitMsg])  # os.system('git commit -s -m "{msg}"')的话没法评论多行
os.system(f'git push --set-upstream {REMOTE} {num}')
cmd = [
    'gh', 'pr', 'create',
    '-R', 'LetMeFly666/LeetCode',
    '-H', f'{REMOTE}:{num}' if WHOAMI == User.Tisfy else f'{num}',  # -H branch可能是 新版/旧版/Mac 所需的属性，并没有默认使用当前分支诶
    '-t', gitCommitMsgPrefix,
    '-b', f'By [newSolution.py](https://github.com/LetMeFly666/LeetCode/blob/{lastSHA}/newSolution.py) using GH on {getPlatform()} | close: #{issueNum}',
    "-l", "题解",
    "-a", "@me",
]
print(cmd)
prResult = subprocess.run(
    cmd,
    capture_output=True,
    text=True
)
if prResult.returncode:
    prAlreadyExists = True
    prResult = prResult.stderr
else:
    prAlreadyExists = False
    prResult = prResult.stdout
print(prResult)
try:
    prNumber = int(prResult.split('/')[-1])
except:
    opening_pr_json = subprocess.run([
        'gh', 'pr', 'list',
        '--state', 'open',
        '--json', 'number,url,headRefName,headRepository'
    ], capture_output=True, text=True).stdout.strip()
    opening_pr_json = json.loads(opening_pr_json)
    for pr in opening_pr_json:
        print(f"pr['headRefName']: {pr['headRefName']}")
        if pr['headRefName'] == str(num):
            prNumber = int(pr['number'])
        break
print(prNumber)
if prAlreadyExists:
    cmd = ['gh', 'pr', 'comment', str(prNumber), '-b', 'Hello, we meet again.']
    subprocess.run(cmd)
os.system('gh pr edit --add-label "under merge"')
input('enter when ready to merge: ')  # 万一给带密码的东西merge了就无法恢复了(虽然这个仓库一次都没有过)
os.system('gh pr edit --remove-label "under merge"')
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
    push_to_which = 'origin'
    if WHOAMI == User.Tisfy:
        push_to_which = 'tisfy_letslt'
        # 因为直接push到origin的话，依据~/.ssh/config，会使用LetMeFly666的id_rsa进行push
        # 会变成LetMeFly666 merged the pull result，贡献者变成LetMeFly666了
    os.system(f'git push {push_to_which}')
    os.system(f'git branch -d {num}')
    os.system(f'git push --delete {REMOTE} {num}')
else:  # 使用gh在github上通过squash的方式merge | 在本地squash merge并push的话github无法自动识别并关闭pr
    try:
        result = subprocess.run(
            ["gh", "pr", "view", str(prNumber), "--json", "title"],
            capture_output=True,
            text=True,
            check=True,
            encoding="utf-8",
        )
        mergeTitle = json.loads(result.stdout)["title"]
    except:
        mergeTitle = gitCommitMsgPrefix
    os.system(f'gh pr merge -s -d -t "{mergeTitle} (#{prNumber})"')
os.system(f'gh issue edit {issueNum} --remove-label "solving"')

# https://github.com/LetMeFly666/LeetCode/blob/3435204860a8a85aa666618d90f40916dc70a1f1/reassign.py
def syncGitcodeCSDN():
    nowCWD = os.getcwd()
    nextCWD = 'OtherSource/gitcode_knowledge'
    if not os.path.exists(nextCWD):
        return
    os.chdir(nextCWD)
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
