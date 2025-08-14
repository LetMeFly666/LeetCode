'''
Author: LetMeFly
Date: 2025-08-14 10:28:59
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-14 18:43:00
'''
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n:
            if n % 3 == 2:
                return False
            n //= 3
        return True