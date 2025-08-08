'''
Author: LetMeFly
Date: 2025-08-05 10:28:59
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-05 10:40:16
'''
from typing import List
from collections import defaultdict

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        ans = l = 0
        window = defaultdict(int)
        for r, v in enumerate(fruits):
            window[v] += 1
            while len(window) > 2:
                window[fruits[l]] -= 1
                if not window[fruits[l]]:
                    del window[fruits[l]]
                l += 1
            ans = max(ans, r - l + 1)
        return ans