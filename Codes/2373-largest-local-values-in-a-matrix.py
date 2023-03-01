'''
Author: LetMeFly
Date: 2023-03-01 09:14:56
LastEditors: LetMeFly
LastEditTime: 2023-03-01 09:36:58
'''
from typing import List


if False:  # AC，方法一，正常
    class Solution:
        def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
            n = len(grid)
            ans = [[0 for _ in range(n - 2)] for __ in range(n - 2)]
            for i in range(1, n - 1):
                for j in range(1, n - 1):
                    M = 1
                    for k in range(-1, 2):
                        for l in range(-1, 2):
                            M = max(M, grid[i + k][j + l])
                    ans[i - 1][j - 1] = M        
            return ans


# AC，方法二，语法糖简化
class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = [[0 for _ in range(n - 2)] for __ in range(n - 2)]
        for i in range(1, n - 1):
            for j in range(1, n - 1):
                ans[i - 1][j - 1] = max(grid[x][y] for x in range(i - 1, i + 2) for y in range(j - 1, j + 2))
        return ans

# a = Solution()
# a.largestLocal([1, 2, 3, 4])