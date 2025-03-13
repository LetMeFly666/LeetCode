---
title: Python的__pycache__到底缓存什么？能缓存历史运行结果吗？—— 对PyCache的一点研究
date: 2022-11-07 09:23:13
tags: [其他, Python, 中等, __pycache__, Research]
categories: [技术思考]
---

为了研究__pycache__的作用，特做实验如下：

大致思路是先“使用版本控制工具git监控文件变动”，再“查阅官方文档进行深入了解”

**新建空白测试用文件夹TestForPyCache并进入**

![新建文件夹TestForPyCache](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/4169ac9af5ba48abbddc7974741472f2.png)![进入测试用文件夹](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/3a997d70d29948a79e2f0086108c707f.png)

**初始化Git仓库**
![初始化Git仓库](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/dcced958c5fc4f2c80fa9d615919c85d.png)
**新建空白Py文件**
![新建空白Py文件](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/99482b978a784ace980b051538887ea5.png)

```bash
fsutil file createnew main.py 0
```

意思为创建大小为0的```main.py```文件

**创建一个最简单的模块**

新建MyModel文件夹

![新建MyModel文件夹](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/b7e0ef89d40e4c5dbea8f626cdbbc295.png)
并在新建的文件夹中新建两个空白文件```__init__.py```和```GetSum.py```

![新建类中文件](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/81f5acb778964ebda2da52d442d43928.png)

```bash
fsutil file createnew .\MyModel\__init__.py 0
fsutil file createnew .\MyModel\GetSum.py 0
```

**编辑新建的Py文件**

MyModel/GetSum.py：

![GetSum.py](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/2e97c7230b0f41989ed1c8e31412b2ff.png)
这里使用一段非常简单的代码进行测试

```python
# 求1 + 2 + 3 + ... + n
def getSumN(n: int) -> int:
    s = 0
    for i in range(n + 1):
        s += i
    return s
```

main.py：
![main.py](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/89e44579e76e4d45ab67e1744601b26b.png)
```python
from MyModel import GetSum

n = int(input("Input the n: "))
result = GetSum.getSumN(n)
print(result)
```

记得保存文件

**提交到版本库**

![提交到版本库](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/d63fe54698254eb5a5a51c0ecf8629a3.png)

可以看到有一次提交记录

并且当前工作区无改动
![当前工作区无改动](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/132df6921de64b45b3118b8d1896fab7.png)

**运行一次main.py**


![运行一次](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/c490775fdfec48afb0403a2e4a2759f9.png)

这次输入```100000000```

可以看到工作区有文件变动，新增了```MyModel/__pycache__/```文件夹

![文件变动，MyModel/__pycache__/](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/d97a5af15dd44ef69d5a7be1e5c197c3.png)
**同样添加到版本库**

![将Cache添加到版本库](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/5c52fb641dd44fbf902d298753b92cd0.png)

可以看到一共有两条提交记录，且工作区无改动

**那么，运行其他输入，PyCache会随之改变吗？**

再次运行```main.py```
![再次运行main.py](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/690a97083a964a82802ef96cb2abd3c0.png)
这次输入值```50000000```

**查看工作区文件状态**

![发现工作区无改动](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/6dc111f054224ed5b0bec9edf1ce1aac.png)
发现工作区无改动

**这就说明每次运行不同输入可能不会导致__pycache__随之进行多次改变**

我电脑上Python的版本为3.9.4

![Python版本](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/f51862280523486683f13791133f8260.png)
查看官方文档：[https://docs.python.org/zh-cn/3.9/tutorial/modules.html?highlight=__pycache__](https://docs.python.org/zh-cn/3.9/tutorial/modules.html?highlight=__pycache__)

![官方文档](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/22923d72a1a94e57b53ab51661da0bc3.png)
点击蓝色链接```PEP 3147```：[https://peps.python.org/pep-3147/](https://peps.python.org/pep-3147/)

即可看到pycache创建流程图

![pycache创建流程图](https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/25737ed5801d4ce696519775e4f3587e.png)
（图源：[https://peps.python.org/_images/pep-3147-1.png](https://peps.python.org/_images/pep-3147-1.png)）

只有当“pycache/xx.pyc与源文件不符”时，才会重新编译生成```pycache```

**pycache并不是为了存储“历史某次的执行结果”，而只是“为了快速加载模块的速度，把模块的编译版缓存在 __pycache__ 目录”**

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/07/Other-Python-ResearchForPycache/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127724471](https://letmefly.blog.csdn.net/article/details/127724471)
