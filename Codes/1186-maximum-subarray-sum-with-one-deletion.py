'''
Author: LetMeFly
Date: 2024-07-21 19:13:48
LastEditors: LetMeFly
LastEditTime: 2024-07-21 19:15:07
'''
from typing import List

class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        del0, del1, ans = arr[0], 0, arr[0]
        for i in range(1, len(arr)):
            del1 = max(del1 + arr[i], del0)
            del0 = max(del0 + arr[i], arr[i])
            ans = max(ans, del0, del1)
        return ans