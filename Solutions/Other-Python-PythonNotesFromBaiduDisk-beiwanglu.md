---
title: python - 下载自百度网盘的远古の - 知识点备忘录
date: 2023-09-25 22:03:00
tags: [其他, Python, Notes]
---

###    多值参数的传递

```python
def sum_nums_3(a, *args, b=22, c=33, **kwargs):
    print(a)
    print(b)
    print(c)
    print(args)
    print(kwargs)

sum_nums_3(100, 200, 300, 400, 500, 600, 700, b=1, c=2, mm=800, nn=900)

#说明:如果很多个值都是不定长参数，那么这种情况下，可以将缺省参数放到 *args的后面， 但如果有**kwargs的话，**kwargs必须是最后的(python3环境下)
```

### **python私有方法和私有属性理解,子类继承**

```
私有的属性，不能通过对象直接访问，但是可以通过方法访问
私有的方法，不能通过对象直接访问
私有的属性、方法，不会被子类继承，也不能被访问
一般情况下，私有的属性、方法都是不对外公布的，往往用来做内部的事情，起到安全的作用
可以通过调用继承的父类的公有方法，间接的访问父类的私有方法、属性
```

### 静态方法、实例方法、类方法

|  项目  |     操作对象      |  调用方式  |
| :--: | :-----------: | :----: |
| 静态方法 | 既不操作类也不操作实例对象 | 类或实例对象 |
| 实例方法 |    操作实例属性     |  实例对象  |
| 类方法  |     操作类属性     | 类或实例对象 |



### 关于子类继承父类__init__方法

```
子类不重写__init__ ， 实例化子类时，会自动调用父类定义的__init__
但重写了__init__时，实例化子类，就不会调用父类已经定义的__init__	
为了能使用或扩展父类的行为，最好使用super().__init__()调用父类的__init__方法
```

### 单例对象

```
在初始化中使用__new__重写基类(object)返回的引用地址(返回给__init__)将类设置为单例类,当第二次创建对象后,只会将第一个对象的地址赋值给第二个对象(即对象的引用),并不会销毁 操作首个创建对象所产生的数据
```

### 

### 列表(可遍历对象)不能同时遍历与增删元素

```python
list1 = [10, 20, 30, 40, 50]
for num in list1:
    print(num)
    if num == 30 or num == 40:
        list1.remove(num)
print(list1)
# 执行结果:
10
20
30
50
[10, 20, 40, 50]
# 结论:删除列表内一个元素,后面元素会自动补位;所以在列表内不能操作遍历与删除
```

### 全局变量(区别于其他语言)

```python
x = 1
def change(a):
    x += 1
    print(x)
change(x)
 执行结果:
        UnboundLocalError:在赋值之前引用的局部变量x。<程序运行报错>
 结论:
    不能在函数体内直接修改全局变量,只能访问全局变量(可直接访问);
    要修改全局变量需使用global后再进行修改操作;
    如果在函数体内修改与全局变量同名的局部变量,需先赋值后再修改
```

### python2与python3数据类型的差异

```python
python3对文本和进制有了明确的区分,文本用Unicode编码,为str类型;二进制数据则为bytes类型
Python有两种类型转换的函数encode()、decode()
encode()  str-->bytes
decode()  bytes-->str
```



### 函数格式

```python
apply_async(func[, args[, kwds]]) 

Process([group [, target [, name [, args [, kwargs]]]]])

"("表示是必传参数,

"["表示可选参数,即已配置缺省参数值

"[,参数名称" 表示非第一参数,使用该参数需从第一个依次填写参数,或者使用参数名称赋值(常用)  args=(1,)
```



### GIL(全局解释器锁)计算密集型与IO密集型

```
在python语言中官方推荐使用c语言解释器,在使用c语言解释器解释python语句时,多线程因为GIL<只针对多线程>的原因(GIL同一时刻只允许一个线程执行),只能并发不能并行;
考虑到执行速度,根据运算类型使用不同方式:
计算密集型:多进程
IO密集型: 多线程、协程
    
问题一:IO密集型中多线程与协程的执行速度
    IO密集型执行时间主要在IO读写,python中由于GIL锁的原因,多线程其实还是使用的单核在进行cpu计算,如果计算任务加锁了，cpu时间片调度机制会在一个cpu时间片（python默认是处理完1000个字节码）结束后，去释放GIL锁，并查看其他线程是否可以执行，由于任务被加锁，会在第二个cpu时间片继续把时间片分给第一个线程，这会让cpu调度时间白白浪费，反而导致多线程比协程(遇到耗时操作自动切换任务)耗时更久
问题二:计算密集型中多线程与单线程的执行速度
    计算量小的情况下单线程快,因为多线程切换需要时间
    计算量大的情况下多线程快,多线程会获得更多的CPU执行时间
```

### 多进程多线程图文理解

- [http://www.ruanyifeng.com/blog/2013/04/processes_and_threads.html](http://www.ruanyifeng.com/blog/2013/04/processes_and_threads.html)

### 协程的耗时操作说明

```
python中文件的读写(read/write)是磁盘在处理,并不占用CPU,在对大文件读写时,操作系统会识别为耗时操作(多长时间判定为耗时操作系统决定),对于协程会进行任务切换
```



### 函数/类方法 形式参数为缺省参数的情况

```python
背景: 函数/类方法 的形式参数已设置缺省参数,且每次调用函数未对形式参数的缺省值进行重新赋值
 

情形: 形式参数的缺省参数为可变参数   
    在每次调用该函数时,该形式参数不会被重新赋予函数定义时设置的缺省值,而是延续该函数上次被调用结束后的值,即该形式参数每次被调用后不会释放内存.
    eg:
       def sum(a, b, c=[1]):
         print("c的初始值:%s" %c)
         print("c的初始地址:",id(c))
         c += [1]
         print("c加一后的地址:",id(c))
         print("求和值为:%s"% ([a]+[b]+[c]))
         print("求和结束后C的值%s\n"%c)

         sum(2,3)
         sum(4,5)
        
       执行结果:
          c的初始值:[1]
          c的初始地址: 2308199479560
          c加一后的地址: 2308199479560
          求和值为:[2, 3, [1, 1]]
          求和结束后C的值[1, 1]

          c的初始值:[1, 1]
          c的初始地址: 2308199479560
          c加一后的地址: 2308199479560
          求和值为:[4, 5, [1, 1, 1]]
          求和结束后C的值[1, 1, 1]
   
总结:
    函数的调用可以理解为 将函数对象浅拷贝一份到内存空间,当函数执行完成后cpu将浅拷贝的数据销毁,如果函数体内有可变类型数据变量,直接修改该可变数据变量(即内存级修改,非重新赋值)会导致下次调用该函数时,此变量的值是前一次调用后的值.<以上属个人理解>
```

### python的内存销毁机制

```
在python中一切皆对象;函数、类在定义是会分配内存空间即创建函数和类的对象,而python中数据的销毁时通过引用计数来完成的,当一个对象的引用计数为0时,这个对象才会被销毁; 所以在python语句中函数被调用结束后(函数对象并未被销毁)其内存空间 包含在函数内定义的变量并不会被销毁.
```





### 浅拷贝与深拷贝

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



### 面向对象`__class__`与dict方法的使用

```python
通过__class__方法可以找到创建该对象的类
> 类名.类属性 <=> 实例对象.__class__.类属性

实例对象在调用实例方法是通过__class__方法找到(实例对象.实例方法格式会自动调用__class__方法)类里面的实例方法; 
> 实例对象.实例方法 <=> 实例对象.__class__.实例方法(实例对象)

实例属性是以键值对的形式保存在字典中,通过__dict__方法以字典形式{"实例属性名1": "实例属性1","实例属性名2": "实例属性2"...}存储实例属性,访问实例属性本质上是通过__dict__方法找到实例属性的字典引用,以属性名为"键"获取"值"作为实例属性的值

eg:
  class A(object):
    nn = 20

    def __init__(self, name):
        self.name = name
        self.__age = 26

    def show_name(self):
        print("name :", self.name)
       
    def __show_age(self):
        print("name :", self.__age)


  a = A("wang")
1>  print(a.name)
2>  print(A.nn)
3>  print(a.__class__.nn)    <=>print(a.nn)
4>  print("调试<< 实例.__class__ :", a.__class__)
5>  a.show_name()
6>  a.__class__.show_name(a)
7>  A.show_name(a)
8>  print(a._A__age)
9>  A._A__show_age(a)
10>  a.__class__._A__show_age(a)
11>  print(a.__dict__)
12>  print(A.__dict__)
    
 执行结果:
1>    wang
    #  访问公有属性
2>	20
3>	20
    #  以上两行访问类属性
4>	调试<< 实例.__class__ : <class '__main__.A'>
    #  以上说明 实例对象名.__class__可以找到创建该对象的类的引用
5>	name : wang
6>	name : wang
7>	name : wang
    #  以上两行再次证明__class__的作用
8>    26
    #  访问私有属性
9>    name : 26
10>    name : 26
    # 利用__class__在外部访问私有方法
11>	{'name': 'wang', '_A__age': 26}    
    #  以上说明 实例对象名._类名__私有属性名 访问实例对象的私有属性
12>    {'__module__': '__main__', 'nn': 20, '__init__': <function A.__init__ at 0x00000200DAA70A60>, 'show_name': <function A.show_name at 0x00000200DAA70AE8>, '_A__show_age': <function A.__show_age at 0x00000200DAA70B70>, '__dict__': <attribute '__dict__' of 'A' objects>, '__weakref__': <attribute '__weakref__' of 'A' objects>, '__doc__': None}
    #  以上说明 方法
```

### `__dict__`与dir()的区别

```python
Python下万物皆对象，每个对象都有多个属性(attribute)，Python对属性有一套统一的管理方案。
1. dir(对象名)是一个函数，返回的是list；
2. __dict__是一个属性，返回的是dictionary,键为属性名(这里的属性包含方法)，值为属性值；
3. dir()用来寻找一个对象的所有属性，包括__dict__中的属性，__dict__是dir()的子集；
4. __dir__是魔法方法, 实例.__dir__() 与 dir(实例)  等效

* 并不是所有对象都拥有__dict__属性。许多内建类型就没有__dict__属性，如list，此时就需要用dir()来列出对象的所有属性。
* 实例的__dict__仅存储与该实例相关的实例属性(不含实例方法,因为实例方法是保存在类里面的)，正是因为实例的__dict__属性，每个实例的实例属性才会互不影响。	
*类的__dict__存储所有实例共享的变量和函数(类属性，方法等)，类的__dict__并不包含其父类的属性。

*dir(对象名)函数会自动寻找一个对象的所有属性和方法(包含私有方法)，包括__dict__中的属性。
*__dict__是dir()的子集，dir()包含__dict__中的属性。
```

### 环境变量

```python
__name__、sys.path 均为环境变量

__name__
模块是对象，并且每个模块都有一个内置属性__name__。
当一个模块被直接运行的时候，该模块__name__的值就等于缺省的'__main__'。
如果一个模块被import ，那么这个被引入模块__name__的值就等于该模块名，也就是文件名去掉py扩展名的部分。
也就是说__name__的值表明了当前py文件调用的方式，因此可以用if __name__ == '__main__'来判断是否是在直接运行该.py文件。 
示例：test.py

sys.path
当我们导入一个模块时：import  xxx，默认情况下python解析器会搜索当前目录、已安装的内置模块和第三方模块，搜索路径存放在sys模块的path中(sys.path 返回的是一个列表！ )：
当我们要添加自己的搜索目录时，可以通过列表的append()方法；
对于模块和自己写的脚本不在同一个目录下，在脚本开头加sys.path.append('模块地址')或sys.path.insert(0,'模块地址')
```

### getattr()与setattr()

```python
> getarrt()

描述
getattr() 函数用于返回一个对象属性值。

语法
getattr 语法：

getattr(object, name[, default])
参数
object -- 对象。# 可以是类也可以是实例对象
name -- 字符串，对象属性。
default -- 默认返回值，如果不提供该参数，在没有对应属性时，将触发 AttributeError。

返回值
返回对象属性值。

实例
以下实例展示了 getattr 的使用方法：
getattr/eg01
>>>class A(object):
...     bar = 1
... 
>>> a = A()
>>> getattr(a, 'bar')        # 获取属性 bar 值
1
>>> getattr(a, 'bar2')       # 属性 bar2 不存在，触发异常
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'A' object has no attribute 'bar2'
>>> getattr(a, 'bar2', 3)    # 属性 bar2 不存在，但设置了默认值
3

getattr/eg02
class A():
    def smile(self,aa):
        print(self)
        print("%s"%aa)
a = A()
m = getattr(a,'smile')
m(1)
>>> <__main__.A object at 0x00000237046F14E0>
>>> 1
a
>>> <__main__.A at 0x237046f14e0>
结论:通过getattr函数在一个实例对象中得到实例方法的引用,在调用该函数时,不需要再传递self,函数会自动将这个实例对象作为第一个实参传递
*******************************************************


> setattr()
描述
setattr 函数对应函数 getatt()，用于设置属性值，该属性必须存在。

语法
setattr 语法：

setattr(object, name, value)
参数
object -- 对象。
name -- 字符串，对象属性。  如果对象属性已经存在,会覆盖原属性值
value -- 属性值。  

返回值
无。

实例
以下实例展示了 setattr 的使用方法：

>>>class A(object):
...     bar = 1
... 
>>> a = A()
>>> getattr(a, 'bar')          # 获取属性 bar 值
1
>>> setattr(a, 'bar', 5)       # 设置属性 bar 值
>>> a.bar
5**
```

### **方法**

```python
endswith()方法
    语法：
        str.endswith(suffix[, start[, end]])
    参数:
        suffix -- 该参数可以是一个字符串或者是一个元素。
        start -- 字符串中的开始位置。
        end -- 字符中结束位置。
    返回值:
        如果字符串含有指定的后缀返回True，否则返回False。
    实例:
        str = "this is string example....wow!!!";
        suffix = "wow!!!";
        print str.endswith(suffix);
        print str.endswith(suffix,20);

        suffix = "is";
        print str.endswith(suffix, 2, 4);
        print str.endswith(suffix, 2, 6);
    实例输出:
        True
        True
        True
        False
    startswith()方法同endswith()
```

### **其他内建函数**

```python
all() 函数
	描述:
        all() 函数用于判断给定的可迭代参数 iterable 中的所有元素是否都为 TRUE，如果是返回 True，否则返回 False。 (元素除了是 0、空、FALSE 外都算 TRUE。)
    语法：
        all(iterable)
    参数:
        iterable -- 元组或列表。
    返回值:
        如果iterable的所有元素不为0、''、False或者iterable为空，all(iterable)返回True，否则返回False；(空元组、空列表返回值为True，这里要特别注意。)
    实例:
       >>>all(['a', 'b', 'c', 'd'])  # 列表list，元素都不为空或0
      True
      >>> all(['a', 'b', '', 'd'])   # 列表list，存在一个为空的元素
      False
      >>> all([0, 1，2, 3])          # 列表list，存在一个为0的元素
      False

      >>> all(('a', 'b', 'c', 'd'))  # 元组tuple，元素都不为空或0
      True
      >>> all(('a', 'b', '', 'd'))   # 元组tuple，存在一个为空的元素
      False
      >>> all((0, 1, 2, 3))          # 元组tuple，存在一个为0的元素
      False

      >>> all([])             # 空列表
      True
      >>> all(())             # 空元组
      True
        
  map() 函数
	描述:
       map() 会根据提供的函数对指定序列做映射。
	  第一个参数 function 以参数序列中的每一个元素调用 function 函数，返回包含每次 function 函数返回值的新列表。
    语法:
       map(function, iterable, ...)
    参数:
       function -- 函数，有两个参数
	   iterable -- 一个或多个序列
    返回值:
        Python 2.x 返回列表。
	    Python 3.x 返回迭代器。
    实例:
        >>>def square(x) :            # 计算平方数
        ...     return x ** 2
        ... 
        >>> map(square, [1,2,3,4,5])   # 计算列表各个元素的平方
        [1, 4, 9, 16, 25]
        >>> map(lambda x: x ** 2, [1, 2, 3, 4, 5])  # 使用 lambda 匿名函数
        [1, 4, 9, 16, 25]

        # 提供了两个列表，对相同位置的列表数据进行相加
        >>> map(lambda x, y: x + y, [1, 3, 5, 7, 9], [2, 4, 6, 8, 10])
        [3, 7, 11, 15, 19]
```

### **import与 \_\_import\_\_导入**

```
from info import redis_store
# 相当于在本地定义一个变量redis_store 指向info模块中redis_store的值，对本地的redis_stone直接进行赋值,只会修改本地变量redis_store的指向,并不会修改info模块中redis_store的值;这里如果info模块中redis_store是可变类型数据(如list()),在本地中通过from info import redis_store导入后直接对其指向的值进行修改(如redis_store.append()),才会修改info模块中redis_store的值
import info
info.redis_store
# 使用 import info，相当于在本地定义一个变量info 指向模块info，但是它保持着自已的名字空间，这就是为什么你需要使用模块名来访问它的函数或属性: module.function 的原因
# 导包或者导入包内变量，python解释器会将整个文件运行一次

module = __import__("info")
返回模块名叫info的模块
* 模块也是对象
```

### 文件读取

```python
file.read([size])
read() 方法用于从文件读取指定的字节数，如果未给定或为负则读取所有。

file.readline([size])
readline() 方法用于从文件读取整行，包括 "\n" 字符。如果指定了一个非负数的参数，则返回指定大小的字节数,如果读取完一行会退出，包括 "\n" 字符。
*file.xreadline([size])返回的是生成了一个生成器，遍历的时候才真正生成具体的内容

file.readlines([sizeint])
读取所有行并返回列表，若给定sizeint>0，返回总和大约为sizeint字节的行, 实际读取值可能比 sizeint 较大, 因为需要填充缓冲区,每次读取的基本单位为一行,如果一行数据大于sizeint,按一行输出。

文件对象是可迭代的，那么可以直接在for循环中使用它们。
f=open(filename)
for line in f:    
	print line
f.close()    
	

*这里的文件对象f是一个迭代器,拥有next方法,在进行for迭代时,会调用next方法,返回值是文件的下一行数据```
```

### 文件搜索路径

```python
系统进行文件搜索是以当前所在文件为基础进行搜索的,而不是以启动文件为基础进行搜索的
```

### **xxxitem**:使用 [] 的方式操作属性时被调用

```python
__setitem__(self,name,value): 使用instance[name] = value操作实例对象时被调用
__getitem__(self,name): 使用instance[name]操作实例对象时被调用
__delitem__(self,name): 使用del instance[]操作实例对象时被调用
作用:类似访问字典模式访问对象
注意:
    不能在__setitem__中进行instance[] = var操作,会形成死循环
使用场景:
    在__setitem__(self,name,value)方法内将name、value以字典形式保存在私有实例属性中(影藏)
    class Item(object):
        
        def __init__(self, *args, **kwargs):
            self.__item = dict()
        
        def  __setitem__(self,name,value):
            self.__item[name] = value
        
        def __getitem__(self,name):
            value =  self.__item.get(name, None)
            if value:
                return value
            else:
                print('属性{}不存在'.format(name))
        def __delitem__(self,name):
            del self.__item[name]
            
```



### json、base64、pickle

```python
pickle
    pickle模块是python的标准模块，提供了对于python数据的序列化操作，可以将数据转换为bytes类型，其序列化速度比json模块要高
   
pickle.dumps() 将python数据序列化为bytes类型
pickle.loads() 将bytes类型数据反序列化为python的数据类型


base64
	Base64是一种基于64个可打印字符来表示二进制数据的表示方法。由于2^6=64，所以每6个比特为一个单元，对应某个可打印字符。3个字节有24个比特，对应于4个Base64单元，即3个字节可由4个可打印字符来表示。在Base64中的可打印字符包括字母A-Z、a-z、数字0-9，这样共有62个字符，此外两个可打印符号在不同的系统中而不同
    
base64.b64encode() 将bytes类型数据进行base64编码，返回编码后的bytes类型
base64.b64deocde() 将base64编码的bytes类型进行解码，返回解码后的bytes类型

json
json.dumps() 将python数据序列化为json字符串
json.loads() 将json字符串反序列化为python的数据类型
```


> 于2020.2.11日下载自百度网盘（个人笔记.rar），共包含三个md文件，这是其一。
>
> 无法追述到作者及来源，但所总结的内容确实较为优质，不忍心删除之，不想令其石沉大海。
>
> 若原作者发现了此文，请与[我](https://github.com/LetMeFly666)联系🌹
>
> [本文地址](https://blog.tisfy.eu.org/2023/09/25/Other-Python-PythonNotesFromBaiduDisk-beiwanglu/)
