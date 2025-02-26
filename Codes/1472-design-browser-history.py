'''
Author: LetMeFly
Date: 2025-02-26 13:38:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-26 13:41:11
'''
class BrowserHistory:
    def __init__(self, homepage: str):
        self.history = [homepage]
        self.now = self.right = 0

    def visit(self, url: str) -> None:
        self.now += 1
        if self.now == len(self.history):
            self.history.append(url)
        else:
            self.history[self.now] = url
        self.right = self.now

    def back(self, steps: int) -> str:
        self.now = max(0, self.now - steps)
        return self.history[self.now]

    def forward(self, steps: int) -> str:
        self.now = min(self.right, self.now + steps)
        return self.history[self.now]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)