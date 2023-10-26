'''
Author: LetMeFly
Date: 2023-10-26 10:26:10
LastEditors: LetMeFly
LastEditTime: 2023-10-26 10:26:11
'''
class Solution:
    def countDigits(self, num: int) -> int:
        n = num
        ans = 0
        while n:
            ans += (num % (n % 10)) == 0
            n //= 10
        return ans