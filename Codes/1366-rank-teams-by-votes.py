'''
Author: LetMeFly
Date: 2024-12-29 14:58:42
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-29 21:08:46
'''
"""
# WA
from typing import List

class Solution:
    def sort(self, a: str) -> bool:
        ans = 0
        for i in range(len(self.counts[0])):
            ans = ans * len(self.counts[0]) - self.counts[ord(a) - ord('A')][i]
        ans *= 100
        ans += ord(a)
        return ans
    
    def rankTeams(self, votes: List[str]) -> str:
        n = len(votes[0])
        self.counts = [[0] * n for _ in range(26)]
        for vote in votes:
            for i in range(n):
                self.counts[ord(vote[i]) - ord('A')][i] += 1
        return ''.join(sorted(votes[0], key=self.sort))
"""
from typing import List

class Solution:    
    def rankTeams(self, votes: List[str]) -> str:
        n = len(votes[0])
        counts = [[0] * n for _ in range(26)]
        for vote in votes:
            for i in range(n):
                counts[ord(vote[i]) - ord('A')][i] -= 1
        return ''.join(sorted(votes[0], key=lambda a: (counts[ord(a) - ord('A')], a)))