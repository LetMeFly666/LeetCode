'''
Author: LetMeFly
Date: 2023-01-19 22:36:44
LastEditors: LetMeFly
LastEditTime: 2023-01-19 22:49:04
'''


# 参考了官方题解的简洁的判断大小写数字的方法，其他全部是自己的思路，竟然和官方题解的命名都一样。
# 不同的是特殊字符的判断方法，题目中说过了只包含字母数字和特殊字符，因此不少字母数字就是特殊字符
# 不同的还有是否两个连续字符相同的判断方法，我个人觉得我的更简洁一些
class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        lastChar = ''
        hasLower, hasUpper, hasDigit, hasSpecial = False, False, False, False
        for c in password:
            if c == lastChar:
                return False
            lastChar = c
            if c.islower():
                hasLower = True
            elif c.isupper():
                hasUpper = True
            elif c.isdigit():
                hasDigit = True
            else:
                hasSpecial = True
        return hasLower and hasUpper and hasDigit and hasSpecial