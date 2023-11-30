'''
Author: LetMeFly
Date: 2023-11-30 20:41:59
LastEditors: LetMeFly
LastEditTime: 2023-11-30 20:44:54
'''
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        bin1 = [0] * 26
        bin2 = [0] * 26
        for c in word1:
            bin1[ord(c) - ord('a')] += 1
        for c in word2:
            bin2[ord(c) - ord('a')] += 1
        for i in range(26):
            if (bin1[i] == 0) != (bin2[i] == 0):
                return False
        bin1.sort()
        bin2.sort()
        return bin1 == bin2