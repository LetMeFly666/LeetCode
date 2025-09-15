'''
Author: LetMeFly
Date: 2025-09-15 21:58:43
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-15 21:58:57
'''
class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        cannot = set(brokenLetters)
        return sum(all(c not in cannot for c in word) for word in text.split())