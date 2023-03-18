'''
Author: LetMeFly
Date: 2023-03-18 14:31:19
LastEditors: LetMeFly
LastEditTime: 2023-03-18 14:42:54
'''
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        cnt1 = [0 for _ in range(26)]
        cnt2 = [0 for _ in range(26)]
        for c in s1:
            cnt1[ord(c) - ord('a')] += 1
        for i in range(len(s1)):
            cnt2[ord(s2[i]) - ord('a')] += 1
        if cnt1 == cnt2:
            return True
        for i in range(len(s1), len(s2)):
            cnt2[ord(s2[i]) - ord('a')] += 1
            cnt2[ord(s2[i - len(s1)]) - ord('a')] -= 1
            if cnt1 == cnt2:
                return True
        return False