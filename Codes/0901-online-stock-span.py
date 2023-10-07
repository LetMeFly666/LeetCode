'''
Author: LetMeFly
Date: 2023-10-07 09:41:46
LastEditors: LetMeFly
LastEditTime: 2023-10-07 09:43:21
'''
class StockSpanner:

    def __init__(self):
        self.st = []  # <price, cnt>


    def next(self, price: int) -> int:
        ans = 1
        while len(self.st) and self.st[-1][0] <= price:
            ans += self.st[-1][1]
            self.st.pop()
        self.st.append([price, ans])
        return ans



# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)