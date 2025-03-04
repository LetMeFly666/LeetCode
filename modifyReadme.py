'''
Author: LetMeFly
Date: 2025-03-03 16:57:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-03 17:29:10
What's more: 这个文件之后也会合并到newSolution.py
'''
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
    originalData


if __name__ == '__main__':
    regenerateReadme()
