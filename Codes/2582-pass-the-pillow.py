'''
Author: LetMeFly
Date: 2023-09-26 08:47:48
LastEditors: LetMeFly
LastEditTime: 2023-09-26 08:47:49
'''
class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        time %= (n - 1) * 2
        return time + 1 if time <= n - 1 else 2 * n - time - 1