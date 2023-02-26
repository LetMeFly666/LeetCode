'''
Author: LetMeFly
Date: 2023-02-26 20:47:36
LastEditors: LetMeFly
LastEditTime: 2023-02-26 21:11:33
'''
from typing import List


class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        ans = 0
        letter = [0] * 26
        for l in letters:
            letter[ord(l) - ord('a')] += 1
        
        n = len(words)
        for mask in range(1 << n):
            letterLefted = letter.copy()
            thisScore = 0
            ok = True
            for i in range(n):
                if mask & (1 << i):
                    for thisChar in words[i]:
                        thisScore += score[ord(thisChar) - ord('a')]
                        if not letterLefted[ord(thisChar) - ord('a')]:
                            ok = False
                            break
                        letterLefted[ord(thisChar) - ord('a')] -= 1
            if ok:
                ans = max(ans, thisScore)
        return ans