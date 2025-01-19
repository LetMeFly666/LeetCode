'''
Author: LetMeFly
Date: 2025-01-19 14:06:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-19 14:16:32
'''
MOD = 1000000007
dp3 = [1, 1, 2, 4] + [0] * 100000
dp4 = [1, 1, 2, 4] + [0] * 100000
for i in range(4, 100001):
    dp3[i] = (dp3[i - 1] + dp3[i - 2] + dp3[i - 3]) % MOD
    dp4[i] = (dp4[i - 1] + dp4[i - 2] + dp4[i - 3] + dp4[i - 4]) % MOD

class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        ans = 1
        cnt = 0
        for i in range(len(pressedKeys)):
            cnt += 1
            if i == len(pressedKeys) - 1 or pressedKeys[i] != pressedKeys[i + 1]:
                ans = ans * (dp4[cnt] if pressedKeys[i] == '7' or pressedKeys[i] == '9' else dp3[cnt]) % MOD
                cnt = 0
        return ans