'''
Author: LetMeFly
Date: 2025-09-28 19:01:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-28 19:06:41
'''
a = input()
if len(a) != 9:
    print('Invalid')
    exit(0)
for i in range(2):
    if not 'A' <= a[i] <= 'Z':
        print('Invalid')
        exit(0)
for i in range(2, 8):
    if not a[i].isdigit():
        print('Invalid')
        exit(0)
should = 0
for i in range(8):
    should += ord(a[i])
should %= 26
should = chr(should + ord('A'))
a = a[:-1] + should
print(a)
