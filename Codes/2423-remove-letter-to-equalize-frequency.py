'''
Author: LetMeFly
Date: 2023-04-29 13:57:01
LastEditors: LetMeFly
LastEditTime: 2023-04-29 14:11:18
'''
class Solution:
    def isSame(self, a: list) -> bool:
        val = 0
        for v in a:
            if v:
                if val:
                    if val != v:
                        return False
                else:
                    val = v
        return True
    
    def equalFrequency(self, word: str) -> bool:
        bin = [0] * 26
        for c in word:
            bin[ord(c) - ord('a')] += 1
        for i in range(26):
            if bin[i]:
                bin[i] -= 1
                if self.isSame(bin):
                    return True
                bin[i] += 1
        return False