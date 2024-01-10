'''
Author: LetMeFly
Date: 2024-01-10 19:16:06
LastEditors: LetMeFly
LastEditTime: 2024-01-10 19:20:27
'''
class Solution:
    def minLength(self, s: str) -> int:
        st = []
        for c in s:
            if (c == 'B' and st and st[-1] == 'A') or (c == 'D' and st and st[-1] == 'C'):
                st.pop()
            else:
                st.append(c)
        return len(st)
