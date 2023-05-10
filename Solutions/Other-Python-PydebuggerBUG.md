---
title: Python - 记录一下pydebugger的BUG
date: 2023-04-05 20:33:43
tags: [其他, Python, BUG]
---

# Python - 记录一下pydebugger的BUG

我的Python版本：

```
Python 3.9.4 (tags/v3.9.4:1f2e308, Apr  6 2021, 13:40:21) [MSC v.1928 64 bit (AMD64)] on win32
```

只需要下面一段代码：

```python
def f():
    a = 1
    breakpoint()
    print(a)

f()
```

运行。这时候就会进入pydebugger模式：

```
> f:\otherapps\program\git\store\store20_leetcode\solutions\other-python-pydebuggerbug.py(10)f()
-> print(a)
(Pdb)
```

首先介绍几个pydebugger的命令：

+ ```p {变量名}```：打印变量。例如```p a```是打印变量a
+ ```!{变量名} = {新值}```：设置变量的值为新值。例如```!a = 2```是设置a的值为2
+ ```ll```：（long list）List the whole source code for the current function or frame.
+ ```s```：(step)单步执行

好了，现在我们在终端中进行debug

1. 首先在终端中输入```p a```输出变量```a```的值，可以得到结果：```1```。这很正常，```a```的值为```1```
2. 接着在终端中输入```!a = 2```，将```a```的值修改为```2```
3. 然后在终端中输入```p a```再次打印```a```的值，可以得到结果：```2```。可见```a```的值已经被修改为了```2```
4. 接着在终端中输入```ll```打印当前函数```f```的源码，可以得到结果：```1  def f():\n2    a = 1\n...```
5. 最后在终端中输入```p a```再次打印```a```的值，可以发现BUG出现了，我们得到了结果```1```。```a```的值再次变成了```1```
6. 进一步验证，在终端中输入```s```单步执行，执行```breakpoint()```函数的下一行```print(a)```，可以得到结果：```1```

这说明pydebugger中的打印函数的```longlist```将修改的```a```变回了原值。

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/04/05/Other-Python-PydebuggerBUG)哦~
> 原文链接：[https://blog.tisfy.eu.org/2023/04/05/Other-Python-PydebuggerBUG](https://blog.tisfy.eu.org/2023/04/05/Other-Python-PydebuggerBUG)