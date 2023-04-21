'''
Author: LetMeFly
Date: 2023-04-21 12:42:41
LastEditors: LetMeFly
LastEditTime: 2023-04-21 12:42:43
'''
class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        return n * 2 if n % 2 else n