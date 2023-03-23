'''
Author: LetMeFly
Date: 2023-03-23 21:27:39
LastEditors: LetMeFly
LastEditTime: 2023-03-23 21:29:00
'''
from typing import overload

@overload
def MyAdd(first: int) -> int:
    ...

@overload
def MyAdd(first: int, second: int) -> int:
    ...

@overload
def MyAdd(first: int, second: int, third: int) -> int:
    ...

@overload
def MyAdd(first: int, second: int, third: int, *more) -> int:
    ...

def MyAdd(*args):
    ans = 0
    for i in args:
        ans += i
    return ans

print(MyAdd(1))
print(MyAdd(1, 2))
print(MyAdd(1, 2, 3))
print(MyAdd(1, 2, 3, 4))
print(MyAdd(1, 2, 3, 4, 5))