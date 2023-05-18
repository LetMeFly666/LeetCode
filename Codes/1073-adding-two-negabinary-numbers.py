'''
Author: LetMeFly
Date: 2023-05-18 09:36:41
LastEditors: LetMeFly
LastEditTime: 2023-05-18 09:50:11
'''
from typing import List

class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        i, j, c = len(arr1) - 1, len(arr2) - 1, 0
        ans = []
        while i >= 0 or j >= 0 or c:
            a = arr1[i] if i >= 0 else 0
            b = arr2[j] if j >= 0 else 0
            x = a + b + c
            if x >= 2:
                x -= 2
                c = -1
            elif x == -1:
                x = 1
                c = 1
            else:
                c = 0
            ans.append(x)
            i, j = i - 1, j - 1
        while len(ans) > 1 and not ans[-1]:
            ans.pop()
        ans.reverse()
        return ans
