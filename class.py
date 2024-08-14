'''
Author: LetMeFly
Date: 2024-08-14 11:46:48
LastEditors: LetMeFly
LastEditTime: 2024-08-14 11:48:16
'''
class F:
    def __init__(self, a: str) -> None:
        self.a = a

    @property
    def name(self) -> str:
        return self.a


f = F('h')
print(f.name)