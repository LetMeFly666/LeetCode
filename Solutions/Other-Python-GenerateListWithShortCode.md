---
title: Python生成列表的简洁代码
date: 2022-11-19 15:38:49
tags: [其他, Python, 中等, List, Research]
categories: [技术思考]
---

[CSDN@Afool4U](https://blog.csdn.net/ik666) 前天发布了文章“（可能是最方便的方法）如何在Python中定义一个多维列表”，地址：[https://blog.csdn.net/ik666/article/details/127912220](https://blog.csdn.net/ik666/article/details/127912220)

觉得不错，加以修改以记之（存档）

```python
def array(*a):
    print(a)  # Show log
    return [array(*a[1:]) for _ in range(a[0])] if a else None 

a = array(2, 2, 3)
print("a:", a)

b = array()
print("b:", b)

c = array(1, 1, 1, 1, 1)
print("c:", c)
```

运行结果：

```python
(2, 2, 3)
(2, 3)
(3,)
()
()
()
(3,)
()
()
()
(2, 3)
(3,)
()
()
()
(3,)
()
()
()
a: [[[None, None, None], [None, None, None]], [[None, None, None], [None, None, None]]]
()
b: None
(1, 1, 1, 1, 1)
(1, 1, 1, 1)
(1, 1, 1)
(1, 1)
(1,)
()
c: [[[[[None]]]]]
```

函数会重复递归，小数据量完全没问题。大数据量可以考虑“记忆化”，可写成一个“修饰器”（应该能这么叫吧）。

```python
def array(*a):
    already = {}
    def main(*a):
        if a in already:
            return already[a]
        print(a)
        ans = [main(*a[1:]) for _ in range(a[0])] if a else None
        already[a] = ans
        return ans 
    return main(*a)

a = array(2, 2, 3)
print("a:", a)

b = array()
print("b:", b)

c = array(1, 1, 1, 1, 1)
print("c:", c)
```

运行结果：

```python
(2, 2, 3)
(2, 3)
(3,)
()
a: [[[None, None, None], [None, None, None]], [[None, None, None], [None, None, None]]]
()
b: None
(1, 1, 1, 1, 1)
(1, 1, 1, 1)
(1, 1, 1)
(1, 1)
(1,)
()
c: [[[[[None]]]]]
```

可以看到计算过的不会再重复递归计算了。

但是**代码一点也不简洁了！！！😱**

这就还不如

```python
def array(*a):
    ans = None
    for d in reversed(a):
        ans = [ans for _ in range(d)]
    return ans


a = array(2, 2, 3)
print("a:", a)

b = array()
print("b:", b)

c = array(1, 1, 1, 1, 1)
print("c:", c)
```

运行结果：

```python
a: [[[None, None, None], [None, None, None]], [[None, None, None], [None, None, None]]]
b: None
c: [[[[[None]]]]]
```

总之：

|方案|简洁程度|效率|
|:--:|:--:|:--:|
|方案一|⭐⭐⭐|⭐|
|方案二|⭐|⭐⭐|
|方案三|⭐⭐|⭐⭐⭐|

对于数据量小的数组，基本上不需要考虑效率问题

甚至直接```a = [[[None for _ in range(3)] for _ in range(2)] for _ in range(2)]```就行。
