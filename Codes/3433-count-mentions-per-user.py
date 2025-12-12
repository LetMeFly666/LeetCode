'''
Author: LetMeFly
Date: 2025-12-12 13:29:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-12 13:42:16
'''
from typing import List

class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        ans: List[int] = [0] * numberOfUsers
        for action, time, who in events:
            if action == "OFFLINE":
                continue
            if who == "ALL":
                ans = [x + 1 for x in ans]
            elif who == "HERE":
                ans = [x + 1 for x in ans]
                for a, t, w in events:
                    if a == "OFFLINE" and int(time) - 60 < int(t) <= int(time):
                        ans[int(w)] -= 1
            else:
                for i in (int(w[2:]) for w in who.split(" ")):
                    ans[i] += 1
        return ans  # 差点忘了return