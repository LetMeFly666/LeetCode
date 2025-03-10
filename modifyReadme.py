'''
Author: LetMeFly
Date: 2025-03-03 16:57:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-09 18:56:40
What's more: 这个文件之后也会合并到newSolution.py
'''
from typing import Dict, List, Tuple
import re
"""
Descriptions:
    读README.md，读Solutions文件夹，依据Solutions文件夹中的文章更新README.md中的对应位置

要求：
    1. README中【技术思考】文章列表表头是：|名称|博客|CSDN博客地址|
    2. README中【力扣题解】列表表头是：|题目名称|困难程度|题目地址|题解地址|CSDN题解|LeetCode题解|
    3. README中【其他题解】列表表头是：|题目|题解|CSDN题解|
    4. 博客源码文件名中【技术思考】以[Other-]开头
    5. 博客源码文件名中【力扣题解】以[LeetCode ]开头
    6. 博客源码文件名中【其他题解】以"其他"开头
    7. 1-3表头不能完全相同

功能：
    1. 更新【技术思考】文章列表，文章顺序是博客源码文件名字母序升序
    2. 更新【力扣题解】文章列表，文章顺序是数字开头的题目优先、剑指Offer(None比II优先)开头的其次、面试题开头的其次、LCP开头的最后。对于开头相同的题目编号小的优先
    3. 更新【其他题解】文章列表，若文章列表中原有
    4. 文章列表中原有的数据会保留(如题目地址/比赛地址)，文章列表中不存在的数据可能会尝试在博客源码头部字段读取(优先级大于列表原有)，都不存在的数据将会为空
        博客源码头部字段：
            1. CSDN博客地址：csdn_url
"""
def regenerateReadme():
    data: Dict[str, Dict[str, str]] = {
        # 'Other-Windows-UWP-launchSttingsApp': {
        #     'title': 'Windows - UWP - 通过链接启动Windows设置中的应用：ms-settings',
        #     'csdn': '129601344',  # https://letmefly.blog.csdn.net/article/details/129601344
        #     'leetcode': 'https://leetcode.cn/problems/add-two-numbers/solutions/2327003/letmefly-2liang-shu-xiang-jia-by-tisfy-55xq/',  # 力扣题解地址
        #     'problem': 'https://leetcode.cn/problems/add-two-numbers/',  # 比赛/问题地址
        #     'type': 'thinking',      # 或leetcode或othersol
        #     'date': '20250308',
        #     'hard': '中等',
        # }
    }
    THINKING_HEADER = '|名称|博客|CSDN博客地址|'
    LEETCODE_HEADER = '|题目名称|困难程度|题目地址|题解地址|CSDN题解|LeetCode题解|'
    OTHERSOL_HEADER = '|题目|题解|CSDN题解|'
    THINKING_afterHeader = ''  # thinking header的下一行
    LEETCODE_afterHeader = ''
    OTHERSOL_afterHeader = ''

    """
    Description:
        提取readme中以header为表头（第一行）的表格body的每一行
    
    Input:
        readme按行分割形成的列表
        表头
    
    Output:
        body（一行一个）
        表头的下一行
    """
    def _getLinesByHeader(readmeSplited: List[str], header: str) -> Tuple[List[str], str]:
        ans = []
        isnow = False
        for line in readmeSplited:
            line = line.strip()
            if isnow and not line:
                break
            if isnow:
                ans.append(line)
            if line == header:
                isnow = True
        return ans[1:], ans[0]

    """
    Description:
        依据技术思考的博客信息设置data内容
    """
    def _setThinkingData(dataThinking: List[str], data: Dict[str, Dict[str, str]]) -> None:
        for line in dataThinking:
            lineSplited = line.split('|')
            dateArticlePattern = r'(\d{4}/\d{2}/\d{2})/([^/]+)/'
            match = re.search(dateArticlePattern, lineSplited[2])
            date = match.group(1)
            date = ''.join(date.split('/'))
            articleId = match.group(2)
            title = lineSplited[1]
            csdndata = lineSplited[3]
            csdnId = csdndata.split('details/')[1].split('"')[0] if 'details/' in csdndata else ''
            # print(lineSplited)
            # print(articleId)
            # print(title)
            # print(csdnId)
            # print(date)
            data[articleId] = {
                'title': title,
                'csdn': csdnId,
                'type': 'thinking',
            }
    
    """
    Description:
        依据力扣题解的博客信息设置data内容
    """
    def _setLeetcodeData(dataLeetcode: List[str], data: Dict[str, Dict[str, str]]) -> None:
        for line in dataLeetcode:
            lineSplited = line.split('|')
            dateArticlePattern = r'(\d{4}/\d{2}/\d{2})/([^/]+)/'
            match = re.search(dateArticlePattern, lineSplited[4])
            date = match.group(1)
            date = ''.join(date.split('/'))
            articleId = match.group(2)
            title = lineSplited[1]
            hard = lineSplited[2]
            csdndata = lineSplited[5]
            csdnId = csdndata.split('details/')[1].split('"')[0] if 'details/' in csdndata else ''
            leetcodeData = lineSplited[6]
            leetcode = leetcodeData.split('<a href="')[1].split('"')[0]
            problemData = lineSplited[3]
            problem = 'https://leetcode.cn/problems/' + problemData.split('/problems/')[1].split('/')[0] + '/'
            # print(articleId)
            # print(title)
            # print(csdnId)
            # print(leetcode)
            # print(problem)
            # print(date)
            # print(hard)
            data[articleId] = {
                'title': title,
                'csdn': csdnId,
                'leetcode': leetcode,
                'problem': problem,
                'type': 'leetcode',
                'date': date,
                'hard': hard,
            }
    
    """
    Description:
        依据其他题解的博客信息设置data内容
    """
    def _setOthersolData(dataOthersol: List[str], data: Dict[str, Dict[str, str]]) -> None:
        for line in dataOthersol:
            lineSplited = line.split('|')
            if lineSplited[1] == '———':  # 注意是“———”而不是“---”
                continue
            dateArticlePattern = r'(\d{4}/\d{2}/\d{2})/([^/]+)/'
            match = re.search(dateArticlePattern, lineSplited[2])
            date = match.group(1)
            date = ''.join(date.split('/'))
            articleId = match.group(2)
            title = lineSplited[1].split('>')[1].split('<')[0]
            csdndata = lineSplited[3]
            csdnId = csdndata.split('details/')[1].split('"')[0] if 'details/' in csdndata else ''
            problem = lineSplited[1].split('href="')[1].split('"')[0]
            # print(title)
            # print(csdnId)
            # print(problem)
            # print(articleId)
            # print(date)
            data[articleId] = {
                'title': title,
                'csdn': csdnId,
                'problem': problem,
                'type': 'othersol',
                'date': date,
            }
    
    """
    Description:
        根据data中的一条“thinking”文章信息(article)生成这一行的str
    """
    def __generateArticleLine_Thinking(articleId: str, article: Dict[str, str]) -> str:
        pass

    """
    Description:
        根据data中的一条“leetcode”文章信息(article)生成这一行的str
    """
    def __generateArticleLine_Leetcode(articleId: str, article: Dict[str, str]) -> str:
        pass

    """
    Description:
        根据data中的一条“othersol”文章信息(article)生成这一行的str
    """
    def __generateArticleLine_Othersol(articleId: str, article: Dict[str, str]) -> str:
        pass
    
    """
    Description:
        生成三个文章列表
    
    Input:
        data
    
    Output:
        List[str], List[str], List[str]，分别代表thinking、leetcode、othersol三种文章的新文章列表
    """
    def _genNewArticleList(data: Dict[str, Dict[str, str]]) -> Tuple[List[str], List[str], List[str]]:
        thinkingSplited: List[str] = [THINKING_HEADER, THINKING_afterHeader]
        leetcodeSplited: List[str] = [LEETCODE_HEADER, LEETCODE_afterHeader]
        othersolSplited: List[str] = [OTHERSOL_HEADER, OTHERSOL_afterHeader]
        for articleId, article in data.items():
            if article['type'] == 'thinking':
                thinkingSplited.append(__generateArticleLine_Thinking(articleId, article))
            elif article['type'] == 'leetcode':
                leetcodeSplited.append(__generateArticleLine_Leetcode(articleId, article))
            else:
                othersolSplited.append(__generateArticleLine_Othersol(articleId, article))
        thinkingSplited[2:].sort()
        return thinkingSplited, leetcodeSplited, othersolSplited

    """
    Description:
        依据表头那一行，使用更新后的文章列表替换掉原有README中的更新列表
    
    Input:
        readmeSplited
        newList - 例如新生成的leetcode题解文章列表
    
    Modified:
        原地修改readmeSplited数组
    """
    def _replaceArticleList(readmeSplited: List[str], newList: List[str]):
        pass

    """
    Description:
        将README中信息读到data中
    
    Input:
        data: 空字典
    
    Output:
        data: README->data
        readmeSplited
    """
    def getdataFromReadme(data: Dict[str, Dict[str, str]]) -> Tuple[Dict[str, Dict[str, str]], List[str]]:
        with open('README.md', 'r', encoding='utf-8') as f:
            readmeSplited = f.readlines()
        nonlocal THINKING_afterHeader
        nonlocal LEETCODE_afterHeader
        nonlocal OTHERSOL_afterHeader
        dataThinking, THINKING_afterHeader = _getLinesByHeader(readmeSplited, THINKING_HEADER)
        _setThinkingData(dataThinking, data)
        dataLeetcode, LEETCODE_afterHeader = _getLinesByHeader(readmeSplited, LEETCODE_HEADER)
        _setLeetcodeData(dataLeetcode, data)
        dataOthersol, OTHERSOL_afterHeader = _getLinesByHeader(readmeSplited, OTHERSOL_HEADER)
        _setOthersolData(dataOthersol, data)
        # print(data)
        return data, readmeSplited

    """
    Description:
        从博客文件中读取信息并更新data
    """
    def getdataFromFile(data: Dict[str, Dict[str, str]]) -> Dict[str, Dict[str, str]]:
        return data
        pass

    """
    Description:
        依据data更新readme文章列表并写入文件
    """
    def rewrite(data: Dict[str, Dict[str, str]], readmeSplited: List[str]) -> None:
        thinkingSplited, leetcodeSplited, othersolSplited = _genNewArticleList(data)
        _replaceArticleList(readmeSplited, thinkingSplited)
        _replaceArticleList(readmeSplited, leetcodeSplited)
        _replaceArticleList(readmeSplited, othersolSplited)
        with open('README.md', 'w', encoding='utf-8') as f:
            f.writelines(readmeSplited)

    data, readmeSplited = getdataFromReadme(data)
    data = getdataFromFile(data)
    rewrite(data, readmeSplited)


if __name__ == '__main__':
    regenerateReadme()
