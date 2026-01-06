'''
Author: LetMeFly
Date: 2026-01-01 22:48:31
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-03 23:48:53
'''

"""
CSDN:
1. 新建草稿 - 得到id 156545186
    - 发现实际内容与`content`无关，只与`markdowncontent`有关
    - 不能只转义\n，latex的\times的\也要转义，否则会被认为是\t；"也要转义
2. 修改草稿内容
3. 发布文章 （最具不确定性的一步）
4. 点赞
5. 收藏
"""

"""
LeetCode:
    - 使用postman已实现发文全流程(除文章点赞)
"""

"""
chat:
写一个python脚本，读取一个markdown文件，并作为body的一个字段content向一个api发送请求。
这时候换行、反斜杠需要进行特殊的转义处理吗？
"""

import json
with open('Solutions/LeetCode 1411.给Nx3网格图涂色的方案数.md', 'r', encoding='utf-8') as f:
    content = f.read()
data = json.dumps({
    'content': content
}, ensure_ascii=False)
print(data)
