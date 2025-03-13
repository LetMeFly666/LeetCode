---
title: python - 下载自百度网盘的远古の - 高级知识总结2
date: 2023-09-25 22:03:00
tags: [其他, Python, Notes]
categories: [技术思考]
---

# Python提高

## 一、动态库加载

1. 编译C语言代码(会生成xx.out 二进制可执行文件)
   - gcc xx.c

2. 运行编译后的文件
   - ./xx.out

3. 把一个C语言文件编译成一个动态库的命令(平台下)
   - gcc xx.c -shared -o -fPIC libxx.so

4. 加载动态库
   - lib = ctypes.cdll.LoadLibrary("./libxx.so")

5. 多线程执行任务
   - Thread(target=lib.文件封装的函数名).start()

6. 代码示例

   ​

   1> C 代码 文件名: loop.c

   ```c
   void Dead_Loop()
   {
       while(1)
       {
           ;
       }
   }
   ```

   2> 将loop.c编译成动态库 libloop.so

   3> 文件名:thread_dynamic_load.py

   ```python
   from threading import Thread
   from ctypes import cdll

   lib = cdll.LoadLibrary("./libloop.so")
   Thread(target=lib.Dead_Loop).start()

   while True:
       pass
   ```

7. 结论

- python是一门胶水语言,可以通过加载动态库的方式在一个项目中运行不同语言的程序
- 通过动态库加载其他语言的方式可以解决多线程GIL使用C解释器运行无法并发的问题



## 二、拷贝

```
copy.copy() — 浅拷贝
1、对可变类型对象进行浅拷贝, 只做顶层拷贝
2、对不可变类型对象进行浅拷贝, 那么不拷贝

copy.deepcopy() — 深拷贝
1、对可变类型对象进行深拷贝, 除了顶层拷贝,还会对该对象的子元素进行深拷贝
2、对不可变类型对象进行深拷贝(递归思维,以递归出口为最终 是否执行拷贝操作的依据)
	 (1)如果该对象存在可变类型数据的子元素, 那么会顶层拷贝, 并且对其子元素进行深拷贝
     (2)如果该对象不存在可变数据对象, 那么不拷贝
```



## 三、私有化

- xx:	    公有变量

- _x:       单前置下划线,私有化属性或方法，from somemodule import *禁止导入,类对象和子类可以访问

  说明: 使用from somemodule import *的方式从一个包导入所有资源, _x不会被导入 但通过 from somemodule import _x的方式是可以导入的

- \__xx:     双前置下划线,避免与子类中的属性命名冲突，无法在外部直接访问(名字重整<\_类名__xx>所以访问不到)

- \__xx__: 双前后下划线,用户名字空间的魔法对象或属性

- xx__:  单后置下划线,用于避免与Python关键词的冲突

  ​

## 四、模块导入

- 模块被导入后，`import module/from xx import yy`不能重新导入模块，重新导入需用`reload`

  说明: python解释器在运行时,会将导入的包编译为.pyc的二进制文件;提升代码运行速度, 所以`程序在运行的过程中`如果包的内容有修改,即便再次导入,解释器发现对应的.pyc文件已经存在,并不会重新编译加载资源

  文件名 test1

  ```python
  _a = "_a"
  ```

  文件名 test2

  ```python
  # import test1
  from test1 import _a
  import time

  # print(test1._a)
  print(_a)

  while True:
      time.sleep(1)
      from test1 import _a
      print(_a)
      # import test1
      # print(test1._a)
  ```

  **结论: 修改test1 中_a的值, 打印结果不会改变**

  ​

  修改test2代码

  ```python
  # from imp import reload -- Python3.4版本以上源代码中的引用由imp自动变为importlib
  from importlib import reload
  import test1
  import time

  print(test1._a)

  while True:
      time.sleep(1)
      reload(test1)
      print(test1._a)
  ```

  **结论: 使用reload重新加载, 修改test1 中_a的值, 打印结果发生改变**

## 五、property属性

1. 定义

   一种用起来像是使用的实例属性一样的特殊属性，可以对应于某个方法

2. property属性的两种方式

   - 装饰器    => 在方法上应用装饰器
   - 类属性    => 在类中定义值为property对象的类属性

3. 装饰器方式

```python
class Goods(object):

    def __init__(self):
        # 原价
        self.original_price = 100
        # 折扣
        self.discount = 0.8

    @property
    def price(self):
        # 实际价格 = 原价 * 折扣
        new_price = self.original_price * self.discount
        return new_price

    # 新式类独有
    @price.setter
    def price(self, value):
        self.original_price = value

    # 新式类独有
    @price.deleter
    def price(self):
        del self.original_price

obj = Goods()
obj.price         # 获取商品价格
obj.price = 200   # 修改商品原价
del obj.price     # 删除商品原价
```

- 定义时，在实例方法的基础上添加 @property 装饰器；并且仅有一个self参数
- 调用时，无需括号
- 经典类中的属性只有一种访问方式，其对应被 @property 修饰的方法
- 新式类中的属性有三种访问方式，并分别对应了三个被@property、@方法名.setter、@方法名.deleter修饰的方法
- 新式类中具有三种访问方式，我们可以根据它们几个属性的访问特点，分别将三个方法定义为对同一个属性：获取、修改、删除
- 简单实例

```python
class Pager:
    def __init__(self, current_page):
        # 用户当前请求的页码（第一页、第二页...）
        self.current_page = current_page
        # 每页默认显示10条数据
        self.per_items = 10 

    @property
    def start(self):
        val = (self.current_page - 1) * self.per_items
        return val

    @property
    def end(self):
        val = self.current_page * self.per_items
        return val

# ############### 调用 ###############
p = Pager(1)
p.start  # 就是起始值，即：m
p.end  # 就是结束值，即：n

# Python的property属性的功能是：property属性内部进行一系列的逻辑计算，最终将计算结果返回。
```

4. 类属性方式

- 当使用类属性的方式创建property属性时，`经典类`和`新式类`无区别
- 简单实例

```python
class Goods(object):

    def __init__(self):
        # 原价
        self.original_price = 100
        # 折扣
        self.discount = 0.8

    def get_price(self):
        # 实际价格 = 原价 * 折扣
        new_price = self.original_price * self.discount
        return new_price

    def set_price(self, value):
        self.original_price = value

    def del_price(self):
        del self.original_price

    PRICE = property(get_price, set_price, del_price, '价格属性描述...')

obj = Goods()
obj.PRICE         # 获取商品价格
obj.PRICE = 200   # 修改商品原价
del obj.PRICE     # 删除商品原价
```

- property方法中有个四个参数
  - 第一个参数是方法名，调用 对象.属性 时自动触发执行方法
  - 第二个参数是方法名，调用 对象.属性 ＝ XXX 时自动触发执行方法
  - 第三个参数是方法名，调用 del 对象.属性 时自动触发执行方法
  - 第四个参数是字符串，调用 对象.属性.__doc__ ，此参数是该属性的描述信息
- 由于`类属性方式`创建property属性具有3种访问方式，我们可以根据它们几个属性的访问特点，分别将三个方法定义为对同一个属性：获取、修改、删除



## 六、魔法属性

1.   _\_doc\_\_   类的描述信息

```python
   class Foo:
       """ 描述类信息，这是用于看片的神奇 """
       def func(self):
           pass

   print(Foo.__doc__)
   #输出：类的描述信息
```

   ​

2.   _\_module\_\_    当前操作的对象在那个模块

3.   _\_class\_\_        当前操作的对象的类是什么

     ```python
                   from test import Person

                   obj = Person()
                   print(obj.__module__)  # 输出 test 即：输出模块
                   print(obj.__class__)  # 输出 test.Person 即：输出类
     ```

4.   _\_del\_\_            当对象在内存中被释放时，自动触发执行。

     ```python
                   class Foo:
                       def __del__(self):
                           pass
     ```

5.   _\_call\_\_    对象后面加括号，触发执行。

     ```python
                   class Foo:
                       def __init__(self):
                           pass

                       def __call__(self, *args, **kwargs):
                           print('__call__')
     ```


​       obj = Foo()  # 执行\_\_init\_\_
​       obj()  # 执行 \_\_call\_\_

​    6._\_dict\_\_  	  类或对象中的所有属性	

7. _\_str\_\_  	         如果一个类中定义了__str__方法，那么在打印 对象 时，默认输出该方法的返回值。

```python
class Foo:
	def __str__(self):
		return 'laowang'

obj = Foo()
print(obj)
# 输出：laowang
```

   ​

8. _\_getitem\_\_  	 _\_setitem\_\_  	_\_delitem\_\_  	   用于索引操作，如字典。以上分别表示获取、设置、删除数据

   ```python
   class Foo(object):

       def __getitem__(self, key):
           print('__getitem__', key)

       def __setitem__(self, key, value):
           print('__setitem__', key, value)

       def __delitem__(self, key):
           print('__delitem__', key)
   ```


   obj = Foo()

   result = obj['k1']      # 自动触发执行 \_\_getitem\_\_
   obj['k2'] = 'laowang'   # 自动触发执行 \_\_setitem\_\_
   del obj['k1']           # 自动触发执行 \_\_delitem\_\_

9. _\_getslice\_\_  	 _\_setslice_\_  	_\_delslice\_\_  	   该三个方法用于切片操作，如：列表

```python
	class Foo(object):

       def __getslice__(self, i, j):
           print('__getslice__', i, j)

       def __setslice__(self, i, j, sequence):
           print('__setslice__', i, j)

       def __delslice__(self, i, j):
           print('__delslice__', i, j)

   obj = Foo()

   obj[-1:1]                   # 自动触发执行 __getslice__
   obj[0:1] = [11,22,33,44]    # 自动触发执行 __setslice__
   del obj[0:2]                # 自动触发执行 __delslice__
```

   


> 于2020.2.11日下载自百度网盘（个人笔记.rar），共包含三个md文件，这是其一。
>
> 无法追述到作者及来源，但所总结的内容确实较为优质，不忍心删除之，不想令其石沉大海。
>
> 若原作者发现了此文，请与[我](https://github.com/LetMeFly666)联系🌹
>
> [本文地址](https://blog.letmefly.xyz/2023/09/25/Other-Python-PythonNotesFromBaiduDisk-gaojizongjie2/)
