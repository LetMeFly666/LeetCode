'''
Author: LetMeFly
Date: 2025-03-03 16:57:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-04 17:07:20
What's more: 这个文件之后也会合并到newSolution.py
'''
from typing import Dict, List
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
        #     'csdn': 'https://letmefly.blog.csdn.net/article/details/129601344',
        #     'leetcode': '',   # 力扣题解地址
        #     'problem': '',    # 比赛/问题地址
        #     'type': 'think',  # 或leetcode或otherplatform
        # }
    }

    """
    Description:
        提取readme中以header为表头（第一行）的表格body的每一行
    
    Input:
        readme按行分割形成的列表
        表头
    
    Output:
        body（一行一个）
    """
    def _getLinesByHeader(readmeSplited: List[str], header: str) -> List[str]:
        pass

    """
    Description:
        将README中信息读到data中
    
    Input:
        data: 空字典
    
    Output:
        data: README->data
    """
    def getdataFromReadme(data: Dict[str, Dict[str, str]]) -> Dict[str, Dict[str, str]]:
        with open('README.md', 'r', encoding='utf-8') as f:
            readme = f.read()
        readSplited = readme.split()

    def getdataFromFile(data: Dict[str, Dict[str, str]]) -> Dict[str, Dict[str, str]]:
        pass

    def rewrite(data: Dict[str, Dict[str, str]]):
        pass

    data = getdataFromReadme(data)
    data = getdataFromFile(data)
    rewrite(data)


if __name__ == '__main__':
    regenerateReadme()
