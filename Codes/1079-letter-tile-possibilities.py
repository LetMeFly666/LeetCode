'''
Author: LetMeFly
Date: 2023-05-19 19:35:07
LastEditors: LetMeFly
LastEditTime: 2023-05-19 19:40:00
'''
from collections import Counter


class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        dic = Counter(tiles)
        def dfs() -> int:
            ans = 0
            for c, times in dic.items():
                if times > 0:
                    ans += 1
                    dic[c] -= 1
                    ans += dfs()
                    dic[c] += 1
            return ans

        return dfs()