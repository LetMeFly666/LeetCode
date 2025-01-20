'''
Author: LetMeFly
Date: 2025-01-19 22:36:01
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-19 22:54:58
'''
import requests

response = requests.get(
    url='https://onlinelibrary.wiley.com/action/doSearch?SeriesKey=14678667&sortBy=Earliest',
    headers={
        'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7',
        'accept-language': 'zh-CN,zh;q=0.9',
        'cache-control': 'no-cache',
        'pragma': 'no-cache',
        'priority': 'u=0, i',
        'sec-ch-ua': '"Not A(Brand";v="8", "Chromium";v="132", "Google Chrome";v="132"',
        'sec-ch-ua-mobile': '?0',
        'sec-ch-ua-platform': '"Windows"',
        'sec-fetch-dest': 'document',
        'sec-fetch-mode': 'navigate',
        'sec-fetch-site': 'none',
        'sec-fetch-user': '?1',
        'upgrade-insecure-requests': '1',
        'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/132.0.0.0 Safari/537.3',
    },

)
print(response)
# print(response.text)

"""
这就是大名鼎鼎的Cloudfalre?
YuPeng把请求头替换地和浏览器完全一致还是能被检测出来，返回403而不是200
"""
