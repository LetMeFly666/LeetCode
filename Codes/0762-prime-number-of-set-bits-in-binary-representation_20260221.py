'''
Author: LetMeFly
Date: 2026-02-21 12:13:32
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-21 12:22:44
'''
max_length = 0
while 1 << max_length < 1000000:
    max_length += 1
print(f'max_length: {max_length}, 1 << {max_length} = {1 << max_length}')

primes = []
for i in range(2, max_length + 1):
    isnot = False
    for j in range(2, i):
        if i % j == 0:
            isnot = True
            break
    if not isnot:
        primes.append(i)
print(f'primes: {primes}')

mask = 0
for p in primes:
    mask |= 1 << p
print(f'mask: {mask}')

"""
max_length: 20, 1 << 20 = 1048576
primes: [2, 3, 5, 7, 11, 13, 17, 19]
mask: 665772
"""
