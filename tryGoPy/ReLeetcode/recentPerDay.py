'''
Author: LetMeFly
Date: 2025-12-08 13:22:59
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-08 13:28:37
'''
from bs4 import BeautifulSoup
import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))


# def get1



with open('recentPerDay.html', 'r') as f:
    html = f.read()

soup = BeautifulSoup(html, 'lxml')
div = soup.find('div', {'class': 'grid'})
a_s = div.find_all('a')
hrefs = [a['href'] for a in a_s if a['href']]
print(hrefs)
print(len(hrefs))