'''
Author: LetMeFly
Date: 2025-08-16 10:17:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-16 10:24:13
'''
class Solution:
    def maximum69Number (self, num: int) -> int:
        s = list(str(num))
        for i, c in enumerate(s):
            if c == '6':
                s[i] = '9'
                break
        return int(''.join(s))  # 记得转回int