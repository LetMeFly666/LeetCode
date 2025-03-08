'''
Author: LetMeFly
Date: 2025-03-08 11:05:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-08 11:06:30
'''
while True:
    data = input('想隐蔽传输的信息：')
    with open('letsender', 'w', encoding='utf-8') as f:
        f.write(data)