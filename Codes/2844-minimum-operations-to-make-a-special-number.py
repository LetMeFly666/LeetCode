'''
Author: LetMeFly
Date: 2024-07-25 16:37:00
LastEditors: LetMeFly
LastEditTime: 2024-07-25 16:43:13
'''
class Solution:
    def thisEnd(self, num: str, n: int) -> int:
        finding = chr(ord('0') + n % 10)
        i = num.rfind(finding)
        if i == -1:
            return len(num)
        finding = chr(ord('0') + n // 10 % 10)
        i = num.rfind(finding, 0, i)
        return len(num) - i - 2 if i != -1 else len(num)
    
    def minimumOperations(self, num: str) -> int:
        ans = len(num) if '0' not in num else len(num) - 1
        for end in [0, 25, 50, 75]:
            ans = min(ans, self.thisEnd(num, end))
        return ans
