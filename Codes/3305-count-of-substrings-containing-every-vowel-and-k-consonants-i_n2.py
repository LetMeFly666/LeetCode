'''
Author: LetMeFly
Date: 2025-03-12 09:41:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-12 09:44:21
'''
AEIOU = 'aeiou'
class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        ans = 0
        for i in range(len(word)):
            cnt5 = [0] * 5
            cntk = 0
            for j in range(i, len(word)):
                for n in range(5):
                    if word[j] == AEIOU[n]:
                        cnt5[n] += 1
                        break
                cntk += word[j] not in AEIOU
                ans += all(cnt5) and cntk == k
        return ans