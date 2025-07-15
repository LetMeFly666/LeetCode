'''
Author: LetMeFly
Date: 2025-07-15 23:15:03
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-15 23:30:52
'''
class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        ok = [False, False]
        for c in word:
            if c.isalpha():
                ok[c.lower() in 'aeiou'] = True
            elif not c.isdigit():
                return False
        return all(ok)