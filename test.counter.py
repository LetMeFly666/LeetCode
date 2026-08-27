'''
Author: LetMeFly
Date: 2026-08-27 16:32:09
LastEditors: LetMeFly.xyz
LastEditTime: 2026-08-27 16:35:59
'''
from collections import Counter, defaultdict

a = "12"
b = Counter(a)
print(type(b))
print(b['3'])
print(b[1])

"""
python Counter和defaultdict(int)很像，只不过Counter访问不存在的键不会给默认加进去，而defaultdict会
"""
print(len(b))  # 2

c = defaultdict(int)
c['1'] = 1
c['2'] = 1
print(c['3'])
print(c[1])
print(len(c))  # 4
