'''
Author: LetMeFly
Date: 2025-01-11 22:29:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-11 22:31:40
'''
class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        ans = 0
        p = 1
        while num1 and num2 and num3:
            ans += p * min(num1 % 10, num2 % 10, num3 % 10)
            num1 //= 10
            num2 //= 10
            num3 //= 10
            p *= 10
        return ans