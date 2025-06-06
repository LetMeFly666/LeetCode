'''
Author: LetMeFly
Date: 2025-06-06 21:49:43
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-06 22:27:47
'''
class Solution:
    def robotWithString(self, s: str) -> str:
        mini = ['z' * (len(s) + 1)]
        for i in range(len(s) - 1, -1, -1):
            mini[i] = min(mini[i + 1], s[i])
        ans = []
        st = []
        for i, c in enumerate(s):
            st.append(c)
            while st and st[-1] <= mini[i + 1]:
                ans.append(st.pop())
        return ''.join(ans)