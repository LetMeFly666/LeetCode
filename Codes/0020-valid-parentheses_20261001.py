'''
Author: LetMeFly
Date: 2026-10-01 09:22:01
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-01 09:29:56
'''
class Solution:
    def isValid(self, s: str) -> bool:
        st = ['']
        pair = {
            '{': '}',
            '(': ')',
            '[': ']'
        }
        for c in s:
            if c in pair: st.append(c)
            elif pair.get(st.pop(), '') != c: return False
        return len(st) == 1
