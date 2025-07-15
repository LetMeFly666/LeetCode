'''
Author: LetMeFly
Date: 2025-07-15 23:15:03
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-15 23:28:33
'''
class Solution:
    def isYuan(self, c: str) -> bool:
        return c in 'aeiou'
    
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        ok = [False, False]
        for c in word:
            if c.isalpha():
                ok[self.isYuan(c)] = True
            elif not c.isdigit():
                return False
        print(ok)
        return all(ok)