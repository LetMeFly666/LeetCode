'''
Author: LetMeFly
Date: 2024-05-20 23:39:45
LastEditors: LetMeFly
LastEditTime: 2024-05-20 23:41:58
'''
class Solution:
    def longestAwesome(self, s: str) -> int:
        mask, ans = 0, 1
        ma = {0: -1}
        for i in range(len(s)):
            mask ^= 1 << (ord(s[i]) - ord('0'))
            if mask in ma:
                ans = max(ans, i - ma[mask])
            else:
                ma[mask] = i
            for j in range(10):
                mask2 = mask ^ (1 << j)
                if mask2 in ma:
                    ans = max(ans, i - ma[mask2])
        return ans