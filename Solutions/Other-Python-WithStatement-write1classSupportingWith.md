---
title: Python - with语句 - 写一个支持with方法调用的类
date: 2024-05-08 16:14:49
tags: [其他, Python, 中等]
---

# Python - with语句 - 写一个支持with方法调用的类

## 前言

使用语句```with open('a.txt', 'r') as f:```可以自动关闭文件句柄，使用语句```with torcu.no_grad()```可以不计算梯度。

我学Py的时候咋好像没学过```open```和```no_grad```是怎么实现的？

于是今日了解了一下。

## 实现一个my_with，计算语句执行用时

其实不难，写一个类，写两个函数```__enter__```（with代码块被调用之前执行）、```__exit__```（结束时候执行）。然后就可以了。

```python
import time


class time_counter:    
    def __enter__(self):
        self.start = time.time()
    
    def __exit__(self, exc_type, exc_value, traceback):
        self.end = time.time()
        print(f"time consume: {self.end - self.start}s")


with time_counter():
    for i in range(int(1e7)):
        i += 1
```

运行结果：

```
time consume: 0.7823185920715332s
```

**那“```as```”语句呢？**

只需要给```__enter__```函数加个返回值：

```python
import time


class time_counter:    
    def __enter__(self) -> int:
        self.start = time.time()
        return 1
    
    def __exit__(self, exc_type, exc_value, traceback):
        self.end = time.time()
        print(f"time consume: {self.end - self.start}s")


with time_counter() as a:
    print(a)
    for i in range(int(1e7)):
        i += 1
```

运行结果：

```
1
time consume: 0.7726781368255615s
```

**关于__exit__函数的三个参数：**

+ exc_type：异常的类型，如果```with```块中没有异常发生，则为```None```。
+ exc_value：异常的值，即```Exception```的实例，如果没有异常发生，则为```None```。
+ traceback：一个```traceback```对象，它封装了异常的调用栈信息，如果没有异常发生，则为```None```。

## End

官方文档：[https://docs.python.org/3/reference/compound_stmts.html#with](https://docs.python.org/3/reference/compound_stmts.html#with)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2024/05/08/Other-Python-WithStatement-write1classSupportingWith/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138576722](https://letmefly.blog.csdn.net/article/details/138576722)
