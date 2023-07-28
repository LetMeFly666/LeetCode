'''
Author: LetMeFly
Date: 2023-07-28 08:39:33
LastEditors: LetMeFly
LastEditTime: 2023-07-28 09:22:43
'''
from typing import List
from functools import cache

class Solution:
    @cache
    def dfs(self, n):
        if self.dp[n]:
            return self.dp[n]
        # self.dp[n] = max([0, self.dfs(thisPre) for thisPre in self.pre[n]]) + self.time[n]  # ValueError: max() arg is an empty sequence
        for thisPre in self.pre[n]:
            self.dp[n] = max(self.dp[n], self.dfs(thisPre))
        self.dp[n] += self.time[n]
        return self.dp[n]

    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        self.time = time
        self.dp = [0] * n
        self.pre = [[] for _ in range(n)]  # 这里不能写成[[]] * n！！！
        for thisPre, thisNext in relations:
            self.pre[thisNext - 1].append(thisPre - 1)
        return max(self.dfs(i) for i in range(n))


if __name__ == '__main__':
    n = 3
    relations = [[1, 3], [2, 3]]
    time = [3, 2, 5]
    sol = Solution()
    print(sol.minimumTime(n, relations, time))
