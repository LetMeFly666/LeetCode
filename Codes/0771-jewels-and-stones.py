'''
Author: LetMeFly
Date: 2023-07-24 08:45:46
LastEditors: LetMeFly
LastEditTime: 2023-07-24 08:46:53
'''
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(stone in jewels for stone in stones)