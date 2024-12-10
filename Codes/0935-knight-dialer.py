'''
Author: LetMeFly
Date: 2024-12-10 15:14:37
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-10 15:17:05
'''
# AC,57.50%,56.76%
CAN_FROM = [
    [4, 6],
    [6, 8],
    [7, 9],
    [4, 8],
    [3, 9, 0],
    [], 
    [1, 7, 0],
    [2, 6],
    [1, 3],
    [2, 4]
]
MOD = 1_000_000_007

class Solution:
    def knightDialer(self, n: int) -> int:
        last = [1] * 10
        for _ in range(n - 1):
            now = [0] * 10
            for i in range(10):
                for j in CAN_FROM[i]:
                    now[i] = (now[i] + last[j]) % MOD
            last = now
        return sum(last) % MOD