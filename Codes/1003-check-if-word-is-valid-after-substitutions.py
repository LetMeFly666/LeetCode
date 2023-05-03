'''
Author: LetMeFly
Date: 2023-05-03 09:37:20
LastEditors: LetMeFly
LastEditTime: 2023-05-03 09:46:14
'''
class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for c in s:
            if c == 'a':
                st.append('a')
            elif c == 'b':
                if not len(st) or st[-1] != 'a':
                    return False
                else:
                    st[-1] = 'b'
            else:
                if not len(st) or st[-1] != 'b':
                    return False
                else:
                    st.pop()
        return not len(st)