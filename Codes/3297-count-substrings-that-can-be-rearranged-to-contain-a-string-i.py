'''
Author: LetMeFly
Date: 2025-01-09 12:39:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-09 12:44:30
'''
from collections import Counter, defaultdict


class Solution:
    def ok(self, cnt1: defaultdict) -> bool:
        for k, v in self.cnt2.items():
            if cnt1[k] < v:
                return False
        return True
    
    def validSubstringCount(self, word1: str, word2: str) -> int:
        self.cnt2 = Counter(word2)
        cnt1 = defaultdict(int)
        ans = l = r = 0
        while l < len(word1):
            if l:
                cnt1[word1[l - 1]] -= 1
            while not self.ok(cnt1):
                if r == len(word1):
                    return ans
                cnt1[word1[r]] += 1
                r += 1
            ans += len(word1) - r + 1
            l += 1
        return ans
