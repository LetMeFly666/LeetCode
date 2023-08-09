'''
Author: LetMeFly
Date: 2023-08-09 08:08:20
LastEditors: LetMeFly
LastEditTime: 2023-08-09 08:10:29
'''
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        mul, cnt = 1, 0
        while n:
            mul *= n % 10
            cnt += n % 10
            n //= 10
        return mul - cnt