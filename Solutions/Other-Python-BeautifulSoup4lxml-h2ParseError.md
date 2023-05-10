---
title: Python BeautifulSoup4或lxml 无法解析嵌套了p标签的h2
date: 2022-12-04 15:20:28
tags: [其他, Python, 中等, BeautifulSoup, lxml, HTML]
---

今天在使用python的beautiful进行Web分析时发现，BeautifulSoup无法解析嵌套了p标签的h2

```python
content = """
<h2>
    <p>5</p>
</h2>
"""

from bs4 import BeautifulSoup
soup = BeautifulSoup(content, "lxml")
print(soup)
```

运行结果：

```
<html><body><h2>
</h2><p>5</p>
</body></html>
```

这在浏览器上是能正常显示的

但是如果把```p```标签换成```b```标签，则可以发现显示成功

```python
content = """
<h2>
    <b>5</b>
</h2>
"""

from bs4 import BeautifulSoup
soup = BeautifulSoup(content, "lxml")
print(soup)
```

运行结果：

```
<html><body><h2>
<b>5</b>
</h2>
</body></html>
```

我的Python版本：Python 3.9.4
bs4: 0.0.1
lxml: 4.7.1

大概率和lxml无关，因为将```soup = BeautifulSoup(content, "lxml")```更换为```soup = BeautifulSoup(content)```后解析结果相同。

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/04/Other-Python-BeautifulSoup4lxml-h2ParseError/)哦~
