'''
Author: LetMeFly
Date: 2025-02-03 08:57:31
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-03 08:59:26
'''
class Solution:
    def isOk(self, s: str, l: int, r: int) -> bool:
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True
    
    def validPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] != s[r]:
                return self.isOk(s, l, r - 1) or self.isOk(s, l + 1, r)
            l += 1
            r -= 1
        return True