'''
Author: LetMeFly
Date: 2024-12-29 14:58:42
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-29 15:06:46
'''
from typing import List

class Solution:
    def sort(self, a: str, b: str) -> bool:
        for i in range(len(self.counts[0])):
            if self.counts[ord(a) - ord('A')][i] != self.counts[ord(b) - ord('A')][i]:
                return self.counts[ord(a) - ord('A')][i] > self.counts[ord(b) - ord('A')][i]
        return a > b
    
    def rankTeams(self, votes: List[str]) -> str:
        n = len(votes[0])
        self.counts = [[0] * n for _ in range(26)]
        for vote in votes:
            for i in range(n):
                self.counts[ord(vote[i]) - ord('A')][i] += 1
        return sorted(votes[0], key=self.sort())
