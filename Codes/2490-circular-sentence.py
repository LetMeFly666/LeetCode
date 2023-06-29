'''
Author: LetMeFly
Date: 2023-06-30 07:27:22
LastEditors: LetMeFly
LastEditTime: 2023-06-30 07:27:24
'''
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        for i in range(len(sentence)):
            if sentence[i] == ' ':
                if sentence[i - 1] != sentence[i + 1]:
                    return False
        return sentence[-1] == sentence[0]