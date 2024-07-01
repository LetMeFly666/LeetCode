---
title: 不能函数重载的Python如何实现“伪重载”
date: 2023-03-23 20:19:21
tags: [其他, Python, 中等, overload, 函数重载, 重载]
---

# 能函数重载的Python如何实现“伪重载”

## 认清现实吧！函数重载在Python中不存在

首先，Python是一门解释型语言，其解释和执行都是动态的，一个名字可以随时代表其他任何意义，根本不存在重载机制。

例如：

```python
def f(a):         # line1
    return a      # line2
                  # line3
def f(a, b):      # line4
    return a + b  # line5
                  # line6
f(1)  # Error     # line7
f(1, 2)           # line8
```

Python解释器执行完line1和line2，得知```f```是一个函数，其功能是返回传入的唯一一个参数。

然而，line4和line5会把前两行的```f```的意义覆盖掉，执行完line5，Python解释器认为```f```是一个**只接受两个参数**的函数，因为这个函数已经将之前对```f```的定义覆盖掉了。

因此运行此代码并不会得到想要的```1```和```3```，而是会得到报错：```TypeError: f() missing 1 required positional argument: 'b'```

## 我好像在写代码的时候见到过Python的重载函数？

有没有一种错觉，觉得好像见到过Python的重载函数呢？

先给大家看一段代码及其运行效果（之后再讲其原理）：

```python
from typing import overload     #line1
                                #line2
@overload                       #line3
def f(a: int) -> int:           #line4
    ...                         #line5
                                #line6
@overload                       #line7
def f(a: int, b: int) -> int:   #line8
    ...                         #line9
                                #line10
def f(a: int, *args) -> int:    #line11
    for i in args:              #line12
        a += i                  #line13
    return a                    #line14
                                #line15
print(f(1))                     #line16
print(f(1, 2))                  #line17
```

推荐将上述代码的line1到line15复制到VsCode中，line16和line17手动打上去

![运行效果](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/8c81362e197948928a92c249d710130b.gif)

可以发现，当我们在函数```f```中输入一个参数```1```时，编译器提示：```(a: int) -> int```

![一个参数](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/6e5fc3dd49634b629b17d61c8da70ae4.png)

在函数```f```中输入两个参数```1```和```2```时，编译器提示：```(a: int, b: int) -> int```

![两个参数](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/cc7098e6ac6a4f01891727fe4973e033.png)

执行上述代码，发现```f(1)```返回值为```1```，```f(1, 2)```返回值为```1 + 2```的值```3```，似乎实现了```加法函数```的重载

## 真实原理解析

Python ```typing```中的```overload```修饰器只接收函数的函数名、参数类型及函数的返回类型，并不管函数中具体是什么。

这也就是为什么上述代码的line5和line9都是```...```。这里写什么都是不会实际执行的（来自我的观测，未经科学考证）

实际上，真正的函数```f```只有line11这一个，这个函数接受可变数量的参数，并将所有接受的到的参数累加后返回。

删掉line1到line10，从line11开始写，执行结果是一模一样的。```@overload```修饰器实际上只是对Python的**注解**的一种扩展

至于VsCode等编辑器为什么会认可这种拓展，是约定俗成还是@overload修饰器有着更深层的秘密？我暂未探究。

好了，懂得了上述原理，我们就可以实现一个“重载之加法器”：

```python
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
```

+ 当输入```MyAdd(1)```时编辑器会提示```(first: int) -> int```
+ 当输入```MyAdd(1, 2)```时编辑器会提示```(first: int, second: int) -> int```
+ 当输入```MyAdd(1, 2, 3)```时编辑器会提示```(first: int, second: int, third: int) -> int```
+ 当输入```MyAdd(1, 2, 3, 4)```或```MyAdd(更多参数)```时编辑器会提示```(first: int, second: int, third: int, *more: Any) -> int```

运行结果：

```
1
3
6
10
15
```

是不是很像重载了```MyAdd```函数？

## 弦外音

当然，也可以使用```typing```的```singledispatch```等实现类似的操作：

```python
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
```

运行结果：

```
Argument is an integer
Argument is a string
```

但是在输入参数的过程中，编译器给的提示都是```(*args: Any, **kwargs: Any) -> None```

具体原理暂未深究。

总之，使用```typing```中的```overload```修饰器，可以做到效果不错的“伪重载”。

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/23/Other-Python-Overload/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129738983](https://letmefly.blog.csdn.net/article/details/129738983)
