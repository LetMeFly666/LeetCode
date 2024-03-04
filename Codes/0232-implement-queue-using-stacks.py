'''
Author: LetMeFly
Date: 2024-03-04 09:14:40
LastEditors: LetMeFly
LastEditTime: 2024-03-04 09:17:56
'''
class MyQueue:

    def __init__(self):
        self.input = []
        self.output = []
    
    def __preTreatment(self):
        if self.output:
            return
        while self.input:
            self.output.append(self.input.pop())

    def push(self, x: int) -> None:
        self.input.append(x)

    def pop(self) -> int:
        self.__preTreatment()
        return self.output.pop()

    def peek(self) -> int:
        self.__preTreatment()
        return self.output[-1]

    def empty(self) -> bool:
        self.__preTreatment()
        return not self.output


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()