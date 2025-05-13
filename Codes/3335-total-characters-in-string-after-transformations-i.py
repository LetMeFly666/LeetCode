'''
Author: LetMeFly
Date: 2025-05-13 09:02:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-13 09:18:14
'''
MOD = 1000000007

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - 97] += 1
        ans = len(s)
        for _ in range(t):
            z = cnt[-1]
            for i in range(24, -1, -1):
                cnt[i + 1] = cnt[i]
            cnt[0] = z
            cnt[1] = (cnt[1] + z) % MOD
            ans = (ans + z) % MOD
        return ans