'''
Author: LetMeFly
Date: 2023-12-10 20:24:51
LastEditors: LetMeFly
LastEditTime: 2023-12-10 20:25:28
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        _0, _1 = 1, 1
        for i in range(n - 1):
            _0, _1 = _1, _0 + _1
        return _1