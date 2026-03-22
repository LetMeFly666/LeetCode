'''
Author: LetMeFly
Date: 2026-03-22 10:58:41
LastEditors: LetMeFly.xyz
LastEditTime: 2026-03-22 11:01:33
'''
data = '0' * 5000
data = '<!-- ' + data + '-->'
with open('testSlow.html', 'w', encoding='utf-8') as f:
    f.write(data)
