'''
Author: LetMeFly
Date: 2025-04-11 21:07:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-11 21:09:06
'''
class Solution:
    def isOk(self, n: int) -> bool:
        s = str(n)
        if len(s) % 2:
            return False
        cnt = 0
        for i in range(len(s) // 2):
            cnt += ord(s[i]) - ord(s[-i - 1])
        return cnt == 0
    
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        return sum(self.isOk(i) for i in range(low, high + 1))