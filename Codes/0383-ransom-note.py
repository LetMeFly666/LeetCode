'''
Author: LetMeFly
Date: 2024-01-07 12:39:39
LastEditors: LetMeFly
LastEditTime: 2024-01-07 12:41:55
'''
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        cnt = [0] * 26
        for c in magazine:
            cnt[ord(c) - 97] += 1
        for c in ransomNote:
            if not cnt[ord(c) - 97]:
                return False
            cnt[ord(c) - 97] -= 1
        return True