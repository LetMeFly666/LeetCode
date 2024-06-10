'''
Author: LetMeFly
Date: 2024-06-10 15:18:38
LastEditors: LetMeFly
LastEditTime: 2024-06-10 15:19:51
'''
from typing import List

class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        ans = 0
        l, r = 0, len(people) - 1
        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1
            r -= 1
            ans += 1
        return ans