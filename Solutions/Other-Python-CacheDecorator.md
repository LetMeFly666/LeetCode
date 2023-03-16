---
title: Python - cache修饰器：将已经计算过的结果保留下来，可用于记忆化搜索
date: 2022-11-07 09:23:13
tags: [其他, Python, 中等, Notes, 修饰器, 记忆化]
---

# Python - cache修饰器：将已经计算过的结果保留下来，可用于记忆化搜索

今日在看力扣题解时发现了大佬的“@cache”，发现很方便，就小研究了一番。

## 实验和结论

### 先说下结论

cache是functools中的一个用于缓存计算结果的修饰器

```python
from functools import cache
```

可用于修饰函数

```python
@cache
def myAdd(a, b):
    return a + b
```

<!-- 这样做的好处是，在第二次计算某个已经计算过的值的时候，会直接返回之前计算过的结果。 -->

这样做的好处是，对于被修饰的函数，相同的参数只会被真正计算一次。后续再使用相同的参数调用这个函数的话，会直接返回先前已经计算过的结果。

若在程序中第一次调用```myAdd(1, 2)```，则真的会在```myAdd```函数中计算```1 + 2 = 3```

但是在程序中再次调用```myAdd(1, 2)```时，由于之前已经计算过参数为```(1, 2)```时结果为```3```，所以这次实际上不会再次计算```1 + 2 = ?```，而是直接返回```3```

### 实验

下面进行验证：

编写两个简单的“加法运算”函数

```python
from functools import cache


def withoutCache(a, b):
    print(a, b)
    c = a + b
    return c


@cache
def withCache(a, b):
    print(a, b)
    c = a + b
    return c
```

在计算```a + b```之前，会先进行打印操作，意思是“我要开始计算a+b了”

接着调用这两个函数：

```python
print(withoutCache(1, 2))
print('-' * 10)
print(withoutCache(1, 2))
print('-' * 10)
print(withCache(2, 3))
print('-' * 10)
print(withCache(2, 3))
```

相当于是用相同的参数对每个函数各调用两次。

我们得到运行结果：

```
1 2
3
----------
1 2
3
----------
2 3
5
----------
5
```

可以看到，在第二次调用```withCache(2, 3)```时，实际上没有真正地计算```2 + 3 = ?```，而是直接返回了先前已经计算过的```5```。

### 实现

那么这个修饰器是怎么实现的呢？接下来我们实现一个低配版的cache修饰器

可以参考文章[Python - 函数参数中的*和**](https://leetcode.letmefly.xyz/2023/02/22/Other-Python-StarAndStarStarInFunctionParameter/)获取函数中的参数

```python
dic = {}

def myCache(func):
    def main(*a):
        if a in dic:
            return dic[a]
        dic[a] = func(*a)
        return dic[a]
    return main


@myCache
def myAdd(a, b):
    print(a, b)
    c = a + b
    return c

print(myAdd(1, 2))
print('-' * 10)
print(myAdd(1, 2))
```

运行结果：

```
1 2
3
----------
3
```

上述只是一个简单的延时，未经优化，且未记录调用函数，多个函数调用时可能会产生冲突。

## lru_cache

阅读源码可发现，其实cache修饰器是调用了lru_cache修饰器。

lru（Least Recently Used），即最近最少使用。下面简单介绍一下lru_cache

```python
@lru_cache(maxsize=2, typed=False)
def f(a, b):
    pass
```

其中maxsize代表最大缓存数量，typed代表是否区分数据类型（typed为True的话将会分别缓存不同类型的数据，例如3和3.0）

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/02/22/Other-Python-CacheDecorator/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129164772](https://letmefly.blog.csdn.net/article/details/129164772)
