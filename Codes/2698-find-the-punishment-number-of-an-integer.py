'''
Author: LetMeFly
Date: 2023-10-25 20:26:33
LastEditors: LetMeFly
LastEditTime: 2023-10-25 20:36:58
'''
class Solution:
    def check(self, n: int) -> int:
        to = str(n * n)
        l = len(to)
        for mask in range(1 << l):
            cnt = 0
            thisNum = 0
            for i in range(l):
                thisNum = thisNum * 10 + ord(to[i]) - ord('0')
                if (mask >> i) & 1:
                    cnt += thisNum
                    thisNum = 0
            if cnt + thisNum == n:
                return n * n
        return 0


    def punishmentNumber(self, n: int) -> int:
        return sum(self.check(i) for i in range(1, n + 1))