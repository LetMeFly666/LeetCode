'''
Author: LetMeFly
Date: 2023-12-09 20:44:54
LastEditors: LetMeFly
LastEditTime: 2023-12-09 20:46:04
'''
class Solution:
    def ok(self, n: int) -> bool:
        cnt = [0] * 10
        while n:
            cnt[n % 10] += 1
            n //= 10
        for i in range(10):
            if cnt[i] and cnt[i] != i:
                return False
        return True
    
    def nextBeautifulNumber(self, n: int) -> int:
        while True:
            n += 1
            if self.ok(n):
                return n