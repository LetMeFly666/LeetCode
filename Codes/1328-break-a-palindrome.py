'''
Author: LetMeFly
Date: 2025-03-05 15:57:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-05 15:59:07
'''
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1:
            return ''
        
        s = list(palindrome)
        for i in range(len(palindrome) // 2):
            if palindrome[i] != 'a':
                s[i] = 'a'
                return ''.join(s)
        
        s[-1] = 'b'
        return ''.join(s)
