'''
Author: LetMeFly
Date: 2023-06-17 09:46:10
LastEditors: LetMeFly
LastEditTime: 2023-06-17 09:56:46
'''
class Solution:
    def numberOfCuts(self, n: int) -> int:
        if n == 1:
            return 0
        return n if n % 2 else n // 2