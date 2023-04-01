'''
Author: LetMeFly
Date: 2023-04-01 09:32:38
LastEditors: LetMeFly
LastEditTime: 2023-04-01 09:47:54
'''
class Solution:
    def maskPII(self, s: str) -> str:
        if '@' in s:  # email
            locAt = s.find('@')
            return s[0].lower() + '*****' + s[locAt - 1].lower() + s[locAt:].lower()
        else:
            cntNum = sum(c.isdigit() for c in s)
            ans = ["***-***-", "+*-***-***-", "+**-***-***-", "+***-***-***-"][cntNum - 10]
            allDigital = "".join(c if c.isdigit() else "" for c in s)
            for i in range(len(allDigital) - 4, len(allDigital)):
                ans += allDigital[i]
            return ans