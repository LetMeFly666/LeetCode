'''
Author: LetMeFly
Date: 2024-07-03 19:25:02
LastEditors: LetMeFly
LastEditTime: 2024-07-03 19:26:12
'''
class Solution:
    def getSum(self, n: int) -> int:
        ans = 0
        while n:
            ans += n % 10
            n //= 10
        return ans
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        sum = self.getSum(x)
        return sum if x % sum == 0 else -1