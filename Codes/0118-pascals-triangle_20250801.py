'''
Author: LetMeFly
Date: 2025-08-01 23:51:32
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-02 00:01:53
'''
from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1] for _ in range(numRows)]
        for i in range(1, numRows):
            for j in range(1, i):
                ans[i].append(ans[i - 1][j - 1] + ans[i - 1][j])
            ans[i].append(1)
        return ans