'''
Author: LetMeFly
Date: 2025-05-25 23:39:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-25 23:47:11
'''
from typing import List

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        cnt = [[0] * 26 for _ in range(26)]
        for word in words:
            cnt[ord(word[0]) - ord('a')][ord(word[1]) - ord('a')] += 1
        ans = middle = 0
        for i in range(26):
            ans += cnt[i][i] // 2 * 2
            middle |= cnt[i][i] % 2
            for j in range(i + 1, 26):
                ans += min(cnt[i][j], cnt[j][i]) * 2
        return (ans + middle) * 2