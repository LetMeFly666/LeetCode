'''
Author: LetMeFly
Date: 2024-01-22 12:46:31
LastEditors: LetMeFly
LastEditTime: 2024-01-22 12:49:11
'''
class Solution:
    def maximumSwap(self, num: int) -> int:
        ans = num
        s = str(num)
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                temp = list(s)
                temp[i], temp[j] = temp[j], temp[i]
                ans = max(ans, int(''.join(temp)))
        return ans