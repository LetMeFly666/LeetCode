'''
Author: LetMeFly
Date: 2023-06-19 15:57:00
LastEditors: LetMeFly
LastEditTime: 2023-06-19 16:31:55
'''
from typing import List


class Min2:
    min1 = 0
    min2 = 0
    num = 0

    def update(self, n: int) -> None:
        if not self.num:
            self.min1 = n
            self.num = 1
        elif self.num == 1:
            self.min2 = n
            self.num = 2
            if self.min1 > self.min2:
                self.min1, self.min2 = self.min2, self.min1
        else:
            if n < self.min1:
                self.min2 = self.min1
                self.min1 = n
            elif n < self.min2:
                self.min2 = n
    
    def getMin1(self) -> int:
        return self.min1
    
    def getMin2(self) -> int:
        return self.min2
    
    def getMinNum(self) -> int:
        return self.num


class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        mod1, mod2 = Min2(), Min2()
        cnt = 0
        for t in nums:
            cnt += t
            if t % 3 == 1:
                mod1.update(t)
            elif t % 3 == 2:
                mod2.update(t)
        if cnt % 3 == 0:
            return cnt
        elif cnt % 3 == 1:
            ans = 0
            if mod1.getMinNum():
                ans = max(ans, cnt - mod1.getMin1())
            if mod2.getMinNum() >= 2:
                ans = max(ans, cnt - mod2.getMin1() - mod2.getMin2())
            return ans
        else:
            ans = 0
            if mod2.getMinNum():
                ans = max(ans, cnt - mod2.getMin1())
            if mod1.getMinNum() >= 2:
                ans = max(ans, cnt - mod1.getMin1() - mod1.getMin2())
            return ans