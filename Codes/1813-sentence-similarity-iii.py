'''
Author: LetMeFly
Date: 2023-01-16 23:05:59
LastEditors: LetMeFly
LastEditTime: 2023-01-16 23:08:17
'''
class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        words1 = sentence1.split()
        words2 = sentence2.split()
        front1, front2, back1, back2 = -1, -1, len(words1), len(words2)
        while front1 + 1 < len(words1) and front2 + 1 < len(words2) and words1[front1 + 1] == words2[front2 + 1]:
            front1 += 1
            front2 += 1
        while back1 - 1 > front1 and back2 - 1 > front2 and words1[back1 - 1] == words2[back2 - 1]:
            back1 -= 1
            back2 -= 1
        return front1 + 1 == back1 or front2 + 1 == back2