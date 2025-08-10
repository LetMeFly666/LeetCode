'''
Author: LetMeFly
Date: 2025-08-10 17:20:07
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-10 20:11:21
'''
can = set(sorted(str(1 << i)) for i in range(31))

class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        return sorted(str(n)) in can