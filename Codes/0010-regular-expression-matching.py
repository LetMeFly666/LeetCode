'''
Author: LetMeFly
Date: 2022-05-08 09:51:07
LastEditors: LetMeFly
LastEditTime: 2022-05-08 09:53:08
'''
#  Error!
import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return re.match(p, s) != None
