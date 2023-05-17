'''
Author: LetMeFly
Date: 2023-05-17 09:04:08
LastEditors: LetMeFly
LastEditTime: 2023-05-17 09:15:52
'''
from typing import List

if False:  # FirstTry # 让第一个开始时间不晚于第二个 + 字符串转整数
    def convertTime(s: str) -> int:
        _0 = ord('0')
        return (ord(s[0]) - _0) * 600 + (ord(s[1]) - _0) * 60 + (ord(s[3]) - _0) * 10 + (ord(s[4]) - _0)

    class Solution:
        def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
            t1s, t1e = convertTime(event1[0]), convertTime(event1[1])
            t2s, t2e = convertTime(event2[0]), convertTime(event2[1])
            if t1s > t2s:
                t1s, t2s = t2s, t1s
                t1e, t2e = t2e, t1e
            return t2s <= t1e

# SecondTry # 直接开始比较
class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        return not(event1[1] < event2[0] or event2[1] < event1[0])