'''
Author: LetMeFly
Date: 2023-09-02 09:34:53
LastEditors: LetMeFly
LastEditTime: 2023-09-02 09:42:04
'''
from typing import List

class Solution:
    def captureForts(self, forts: List[int]) -> int:
        ans = 0
        last, cnt = 2, 0
        for fort in forts:
            if fort:
                if fort != last and last != 2:
                    ans = max(ans, cnt)
                cnt = 0
                last = fort
            else:
                cnt += 1
        return ans