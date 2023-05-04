'''
Author: LetMeFly
Date: 2023-05-04 10:10:24
LastEditors: LetMeFly
LastEditTime: 2023-05-04 10:30:32
'''
from typing import List

class Solution:
    def minStep(self, fruits: List[List[int]], startPos: int, l: int, r: int) -> int:
        if fruits[r][0] <= startPos:
            return startPos - fruits[l][0]
        elif fruits[l][0] >= startPos:
            return fruits[r][0] - startPos
        else:
            leftDistance = startPos - fruits[l][0]
            rightDistance = fruits[r][0] - startPos
            return min(2 * leftDistance + rightDistance, leftDistance + 2 * rightDistance)
    
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        ans = 0
        cnt = 0
        l = 0
        r = 0
        while r < len(fruits):
            cnt += fruits[r][1]
            while l <= r and self.minStep(fruits, startPos, l, r) > k:
                cnt -= fruits[l][1]
                l += 1
            ans = max(ans, cnt)
            r += 1
        return ans