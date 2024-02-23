'''
Author: LetMeFly
Date: 2024-02-23 11:22:26
LastEditors: LetMeFly
LastEditTime: 2024-02-23 11:25:03
'''
import time

# pop(last element)
start = time.time()
a = [0 for _ in range(100000)]
while a:
    a.pop()
end = time.time()
print(f'pop consume: {end - start}s')

# slice(first element)
start = time.time()
a = [0 for _ in range(100000)]
while a:
    a = a[1:]
end = time.time()
print(f'slice consume: {end - start}s')
