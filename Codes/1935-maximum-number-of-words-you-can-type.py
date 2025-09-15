'''
Author: LetMeFly
Date: 2025-09-15 21:48:47
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-15 21:56:54
'''
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        ans = 0
        cannot = set(brokenLetters)
        for word in text.split():
            ans += all(c not in cannot for c in word)
        return ans