'''
Author: LetMeFly
Date: 2023-03-18 13:09:27
LastEditors: LetMeFly
LastEditTime: 2023-03-18 13:13:26
'''
class Solution:
    def ifSelfPalindrome(self, s: str, l: int, r: int) -> bool:  # s[l, r]
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

    def ifOk(self, a: str, b: str) -> bool:
        la = 0
        lb = len(b) - 1
        while la < lb:
            if a[la] != b[lb]:
                if self.ifSelfPalindrome(a, la, lb) or self.ifSelfPalindrome(b, la, lb):
                    return True
                else:
                    return False
            la += 1
            lb -= 1
        return True

    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        return self.ifOk(a, b) or self.ifOk(b, a)