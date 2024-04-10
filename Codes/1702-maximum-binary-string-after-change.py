'''
Author: LetMeFly
Date: 2024-04-10 12:58:15
LastEditors: LetMeFly
LastEditTime: 2024-04-10 12:58:26
'''
class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        cnt0 = binary.count('0')
        if not cnt0:
            return binary
        first0 = binary.find('0')
        pos0 = first0 + (cnt0 - 1)
        return '1' * pos0 + '0' + '1' * (len(binary) - pos0 - 1)