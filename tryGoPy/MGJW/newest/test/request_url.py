'''
Author: LetMeFly
Date: 2025-07-26 15:58:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-26 16:09:09
'''
import requests

FILE_NAME = 'urls.txt'

with open(FILE_NAME, 'r', encoding='utf-8') as f:
    urls = f.readlines()

for url in urls:
    response = requests.get(url.strip())
    print(response)
    print(response.text)
