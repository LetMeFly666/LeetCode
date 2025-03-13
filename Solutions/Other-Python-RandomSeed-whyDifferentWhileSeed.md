---
title: Python - random.seed初探 - 为什么固定随机种子了每次结果还不一样
date: 2024-07-23 11:06:47
tags: [其他, Python, 中等, Notes]
categories: [技术思考]
---

# Python - random.seed初探 - 为什么固定随机种子了每次结果还不一样

## 前言

和很多语言一样，python的random也能设置随机种子，设置随机种子后相同的rand调用会产生相同的结果。例如下面代码在同一版本的python下，理论上不论何时运行多少次都将得到相同的结果：

```python
import random
random.seed(83)
a = [random.randint(0, random.randint(1, 100)) for _ in range(20)]
random.shuffle(a)
print(a)
```

但昨晚我固定随机种子后，每次运行还是得到了不同的结果。探究其原因，竟是因为——set。

## random.seed的正常使用示例

依据目前调研和观测，设置初始随机种子后，不论怎么调用random库的函数，只要调用顺序一致，调用结果都一致。

```python
# a.py
import random
import b
random.seed(5)
import c
print(b.seedBeforeImport() * c.seedThenImport())

# b.py
import random
def seedBeforeImport():
    return random.random()

# c.py
import random
def seedThenImport():
    return random.random()
```

之后运行`python a.py`，就我的Python版本而言，每次运行结果都是`0.46206037285763746`。

## 诶，随机结果突然不一样了？

多执行几次下面代码，结果发现打印的结果有时是`a`有时是`b`有时是`c`，固定随机种子失效了？

```python
import random
random.seed(64)
a = list(set(['a', 'b', 'c']))
print(random.choice(a))
```

其实不然，咱们将代码修改成下面的样子，结果发现，不论随机选取的是`a`是`b`还是`c`，就我的python版本而言所选取的下标都是`1`。

```python
import random
random.seed(64)
a = list(set(['a', 'a', 'b', 'c']))
choiced = random.choice(a)
choicedIndex = a.index(choiced)
print(f'choiced: {choiced}, index: {choicedIndex}')
```

也就是说，这种每次不同的随机是由set导致的。运行以下代码可以看到每次结果是不一样的。

```python
a = list(set(['a', 'a', 'b', 'c']))
print(a)
```

Python 的集合（set）和字典（dict）的底层实现依赖于哈希表，为了防止哈希冲突攻击，Python 3.3 及以后的版本引入了哈希随机化。这意味着在不同的运行中，相同的字符串可能会有不同的哈希值，从而导致集合和字典中的元素顺序不同。（可以试试，`print(list(set([1, 2, 4, 3, 4, 5])))`每次运行的结果是一样的）

例如运行下面代码，可以看到单次运行每次hash结果相同，不同次运行每次结果不同，且这个结果不依赖于`random.seed`所设定的随机种子。

```python
import random
random.seed(5)
print(hash("Hello World"))
print(hash("Hello World"))
print(hash("Hello World"))
```

## 怎样使用set的同时保持每次运行结果一致

只需要设置一个环境变量`PYTHONHASHSEED`，这样python的哈希函数的随机种子就也固定了。例如：

```python
import random
random.seed(64)
print(hash("Hello World"))
a = list(set(['a', 'a', 'b', 'c']))
print(a)
print(random.choice(a))
```

在Linux shell中执行命令`PYTHONHASHSEED=123 python a.py`，可以看到每次的结果都是：

```
6827962425479379018
['a', 'b', 'c']
b
```

## End

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2024/07/23/Other-Python-RandomSeed-whyDifferentWhileSeed/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140630443](https://letmefly.blog.csdn.net/article/details/140630443)
