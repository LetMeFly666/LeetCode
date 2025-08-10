'''
Author: LetMeFly
Date: 2025-08-10 17:20:07
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-10 20:12:28
'''
can = set(''.join(sorted(str(1 << i))) for i in range(31))

class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        return ''.join(sorted(str(n))) in can