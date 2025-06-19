'''
Author: LetMeFly
Date: 2025-06-19 10:16:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-19 10:35:59
'''
# M: !9 -> 9
# m: first == 1 ? (!01 -> 0) : (first->1)
class Solution:
    def firstN9(self, s: str) -> int:
        for i, c in enumerate(s):
            if c != '9':
                return i
        return -1
    
    def firstN01(self, s: str) -> int:
        for i, c in enumerate(s):
            if c != '0' and c != '1':
                return i
        return -1
    
    def change(self, s: str, a: str, b: str) -> int:
        li = list(s)
        for i, c in enumerate(li):
            if c == a:
                li[i] = b
        return int(''.join(li))
    
    def maxDiff(self, num: int) -> int:
        M = m = 0
        s = str(num)
        index = self.firstN9(s)
        M = num if index < 0 else self.change(s, s[index], '9')
        if s[0] == '1':
            index = self.firstN01(s)
            m = num if index < 0 else self.change(s, s[index], '0')
        else:
            m = self.change(s, s[0], '1')
        return M - m