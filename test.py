'''
Author: LetMeFly
Date: 2025-10-12 23:21:07
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-12 23:22:55
'''
import requests
import json

result = requests.post(
    url = 'https://fuwu.rsj.beijing.gov.cn/dxxdgwyquery/publicQuery/gzwbkrsssquery',
    # data = json.dumps({
    #     'yhid': '',
    #     'pxdm': 0,
    #     'zwdm': '',
    #     'page': 1,
    #     'pageSize': 50
    # })
    data = {
        'yhid': '',
        'pxdm': 0,
        'zwdm': '',
        'page': 1,
        'pageSize': 50
    }
)

print(result)
print(result.text)