'''
Author: LetMeFly
Date: 2025-03-13 11:16:41
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-13 11:20:08
'''
from collections import defaultdict

class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        cnt11 = defaultdict(int)
        cnt21 = left1 = 0
        cnt12 = defaultdict(int)
        cnt22 = left2 = 0
        ans = 0
        for c in word:
            if c in 'aeiou':
                cnt11[c] += 1
                cnt12[c] += 1
            else:
                cnt21 += 1
                cnt22 += 1
            
            while len(cnt11) == 5 and cnt21 >= k:
                if word[left1] in 'aeiou':
                    cnt11[c] -= 1
                    if not cnt11[c]:
                        del cnt11[c]
                else:
                    cnt21 -= 1
                left1 += 1
            while len(cnt12) == 5 and cnt21 > k:
                if word[left2] in 'aeiou':
                    cnt12[c] -= 1
                    if not cnt12[c]:
                        del cnt12[c]
                else:
                    cnt22 -= 1
                left2 += 1
            ans += left1 - left2
        return ans