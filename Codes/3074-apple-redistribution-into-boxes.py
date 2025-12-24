'''
Author: LetMeFly
Date: 2025-12-24 13:30:54
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-24 13:40:50
'''
from typing import List

class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        cnt = sum(apple)
        ans = 0
        for t in sorted(capacity, reverse=True):
            cnt -= t
            ans += 1
            if cnt <= 0:
                return ans


# if __name__ == "__main__":
#     sol = Solution()
#     print(sol.minimumBoxes([1,3,2], [4,3,1,5,2]))