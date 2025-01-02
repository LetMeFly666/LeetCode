'''
Author: LetMeFly
Date: 2025-01-02 15:14:04
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-02 15:20:24
'''
from bs4 import BeautifulSoup

html_code = open('C:/Users/LetMeFly/Desktop/d.html', 'r', encoding='utf-8').read()

soup = BeautifulSoup(html_code, 'lxml')
# 移除所有属性
for tag in soup.find_all(True):  # True 表示匹配所有标签
    tag.attrs = {}  # 清空所有属性

# 移除所有的 <svg> 标签
for svg_tag in soup.find_all('svg'):
    svg_tag.decompose()  # 彻底移除标签及其内容

data = str(soup.contents[0])
print(data)
open('C:/Users/LetMeFly/Desktop/d-2.html', 'w', encoding='utf-8').write(data)