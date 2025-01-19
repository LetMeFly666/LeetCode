'''
Author: LetMeFly
Date: 2025-01-17 15:38:40
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-17 15:42:31
'''
class A:
    def __init__(self) -> None:
        print('A')

class B(A):
    def __init__(self) -> None:
        super().__init__()
        print('B')
        super().__init__()

B()