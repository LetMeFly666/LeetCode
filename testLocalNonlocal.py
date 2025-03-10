'''
Author: LetMeFly
Date: 2025-03-09 18:44:59
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-09 18:49:32
'''
def f():
    a = '0'
    def changeA():
        # print(a)  # 这样会报错：local variable 'a' referenced before assignment
        a = '1'
        # print(a)
    def getA():
        print(a)
    
    changeA()
    getA()

f()

"""
这段代码的执行结果是0，实际上changeA函数并没能修改到a的值
请以此为案例详细介绍python局部和全局值
"""