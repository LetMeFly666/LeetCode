'''
Author: LetMeFly
Date: 2024-03-03 12:04:53
LastEditors: LetMeFly
LastEditTime: 2024-03-03 12:07:12
'''
from collections import deque

class MyStack:

    def __init__(self):
        self.q = deque()

    def push(self, x: int) -> None:
        temp = deque()
        temp.append(x)
        while self.q:
            temp.append(self.q.popleft())
        self.q = temp

    def pop(self) -> int:
        return self.q.popleft()

    def top(self) -> int:
        return self.q[0]


    def empty(self) -> bool:
        return not self.q



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()