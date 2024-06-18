'''
Author: LetMeFly
Date: 2024-06-18 19:10:26
LastEditors: LetMeFly
LastEditTime: 2024-06-18 19:16:37
'''
class Solution:
    def isPrice(self, s: str) -> bool:
        if s[0] != '$':
            return False
        if len(s) == 1:
            return False
        for c in s[1:]:
            if not c.isdigit():
                return False
        return True
    
    def newPrice(self, s: str, discount: int) -> str:
        val = int(s) * (100 - discount)
        return f'${val // 100}.{val % 100:02d}'
    
    def discountPrices(self, sentence: str, discount: int) -> str:
        splited = sentence.split(' ')
        for i in range(len(splited)):
            if self.isPrice(splited[i]):
                splited[i] = self.newPrice(splited[i][1:], discount)
        return ' '.join(splited)