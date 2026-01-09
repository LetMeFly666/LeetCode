'''
Author: LetMeFly
Date: 2026-01-01 22:48:31
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-09 21:48:51
'''

"""
算了！！放弃了，CSDN不愿这样，不好逆向，且有一定封号风险。算了。
这个脚本不能正常使用。

编辑一半还给我来了个“您已退出登录，请重新登陆！”，还有错别字。。。
"""

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

import requests
import json

with open('Solutions/LeetCode 0865.具有所有最深节点的最小子树.md', 'r', encoding='utf-8') as f:
    content = f.read()
# data = json.dumps({
#     'content': content
# }, ensure_ascii=False)
# print(data)

payload={
    'title': 'LeetCode 865.具有所有最深节点的最小子树：深度优先搜索（一次DFS + Python5行）',  # read + modify
    'markdowncontent': content,
    'content': '',
    'readType': 'public',
    'level': 0,
    'tags': '',
    'status': 2,
    'categories': '',
    'type': 'original',
    'original_link': '',
    'authorized_status': False,
    'not_auto_saved': '1',
    'source': 'pc_mdeditor',
    'cover_images': [],
    'cover_type': 1,
    'is_new': 1,
    'vote_id': 0,
    'resource_id': '',
    'pubStatus': 'draft',
    'creator_activity_id': '',
}
print(payload)

# exit(0)
with open('del-session', 'r') as f:
    session = f.read()
with open('del-user_token', 'r') as f:
    user_token = f.read()

cookies = {
    'SESSION': session,
    'UserToken': user_token,
}

headers = headers = {
    "Origin": "https://editor.csdn.net",
    "Pragma": "no-cache",
    "Cache-Control": "no-cache",

    "Sec-CH-UA": '"Google Chrome";v="143", "Chromium";v="143", "Not A(Brand";v="24"',
    "Sec-CH-UA-Mobile": "?0",
    "Sec-CH-UA-Platform": '"Windows"',

    "Sec-Fetch-Dest": "document",
    "Sec-Fetch-Mode": "navigate",
    "Sec-Fetch-Site": "none",
    "Sec-Fetch-User": "?1",

    "Upgrade-Insecure-Requests": "1",

    "User-Agent": (
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
        "AppleWebKit/537.36 (KHTML, like Gecko) "
        "Chrome/143.0.0.0 Safari/537.36"
    ),
}

session = requests.Session()
session.trust_env = False  # 忽略系统代理

response = session.post(
    url='https://bizapi.csdn.net/blog-console-api/v3/mdeditor/saveArticle',
    json=payload,
    cookies=cookies,
    headers=headers
)
print(response)
print(response.text)

