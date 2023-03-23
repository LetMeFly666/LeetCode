'''
Author: LetMeFly
Date: 2023-03-23 21:35:11
LastEditors: LetMeFly
LastEditTime: 2023-03-23 21:36:25
'''
from functools import singledispatch, wraps

@singledispatch
def f(arg):
    print("Unsupported type")

@f.register
def _(arg: int):
    print("Argument is an integer")

@f.register
def _(arg: str):
    print("Argument is a string")

f(1)
f("1")