'''
Author: LetMeFly
Date: 2025-01-05 19:08:35
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-05 19:25:43
'''
from typing import List

class ATM:

    def __init__(self):
        self.money = [0] * 5
        # self.per = [10, 20, 100, 200, 500]  # 我说咋一直不对，原来面值写错了
        self.per = [20, 50, 100, 200, 500]

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(5):
            self.money[i] += banknotesCount[i]

    def withdraw(self, amount: int) -> List[int]:
        # if amount == 550:
        #     print('debug')
        ans = [0] * 5
        for i in range(4, -1, -1):
            ans[i] = min(self.money[i], amount // self.per[i])
            amount -= ans[i] * self.per[i]
        if amount:
            return [-1]
        for i in range(5):
            self.money[i] -= ans[i]
        return ans


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)

# op = ["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
# val = [[], [[0, 0, 1, 2, 1]], [600], [[0, 1, 0, 1, 1]], [600], [550]]

# atm = ATM()
# for i in range(1, len(op)):
#     if op[i] == "deposit":
#         atm.deposit(val[i][0])
#     else:
#         print(atm.withdraw(val[i][0]))
