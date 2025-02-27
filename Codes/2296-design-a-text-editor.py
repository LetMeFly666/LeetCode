'''
Author: LetMeFly
Date: 2025-02-27 10:05:13
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-27 10:19:35
'''
class TextEditor:
    def __init__(self) -> None:
        self.left = []  # 这里不能放到TextEditor下，因为多个测试用例会调用同一个TextEditor实例
        self.right = []
        
    def __10text(self) -> str:
        return ''.join(self.left[-10:])

    def addText(self, text: str) -> None:
        self.left.extend(text)

    def deleteText(self, k: int) -> int:
        # print(self.left)
        ans = min(len(self.left), k)
        del self.left[-k:]
        return ans

    def cursorLeft(self, k: int) -> str:
        while k and len(self.left):
            k -= 1
            self.right.append(self.left.pop())
        return self.__10text()

    def cursorRight(self, k: int) -> str:
        while k and len(self.right):
            k -= 1
            self.left.append(self.right.pop())
        return self.__10text()


# Your TextEditor object will be instantiated and called as such:
# obj = TextEditor()
# obj.addText(text)
# param_2 = obj.deleteText(k)
# param_3 = obj.cursorLeft(k)
# param_4 = obj.cursorRight(k)