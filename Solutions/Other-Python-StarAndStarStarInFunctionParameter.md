---
title: Python - 函数参数中的*和**
date: 2023-02-22 15:34:14
tags: [其他, Python, 简单, Notes]
---

# Python - 函数参数中的*和**

有时会见到python函数参数中的*，怕忘记，特做此笔记。

```python
def f(*a, **b):
    print(a)
    print(b)

f(1, 2, 3, hshf="0sfsfsf", a="sf")
```

运行结果：

```
(1, 2, 3)
{'hshf': '0sfsfsf', 'a': 'sf'}
```

**What's more:**

```python
def func(a, b):
    print(a, b)

func(1, 2)
func(*(1, 2))
```

运行结果：

```
1 2
1 2
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/02/22/Other-Python-StarAndStarStarInFunctionParameter/)哦~
> Tisfy：[https://blog.tisfy.eu.org/2023/02/22/Other-Python-StarAndStarStarInFunctionParameter/](https://blog.tisfy.eu.org/2023/02/22/Other-Python-StarAndStarStarInFunctionParameter/)
