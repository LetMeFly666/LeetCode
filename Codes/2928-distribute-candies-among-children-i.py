'''
Author: LetMeFly
Date: 2024-06-01 11:44:10
LastEditors: LetMeFly
LastEditTime: 2024-06-01 11:45:32
'''
class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        ans = 0
        for x in range(min(limit, n) + 1):
            for y in range(min(n - x, limit) + 1):
                if n - x - y <= limit:
                    ans += 1
        return ans