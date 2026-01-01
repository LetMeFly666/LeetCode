'''
Author: LetMeFly
Date: 2026-01-01 15:54:45
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-01 16:03:01
'''
from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return list(map(int, str(int(''.join(map(str, digits))) + 1)))

if __name__ == '__main__':
    sol = Solution()
    print(sol.plusOne([1,2,3]))