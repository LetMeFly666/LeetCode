'''
Author: LetMeFly
Date: 2024-05-22 20:21:27
LastEditors: LetMeFly
LastEditTime: 2024-05-22 20:23:50
'''
from typing import List
from collections import defaultdict

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        ans = [[], []]
        cnt = defaultdict(int)
        for winner, loser in matches:
            cnt[winner] += 0
            cnt[loser] += 1
        for id_, times in cnt.items():
            if times == 0:
                ans[0].append(id_)
            elif times == 1:
                ans[1].append(id_)
        ans[0].sort()
        ans[1].sort()
        return ans