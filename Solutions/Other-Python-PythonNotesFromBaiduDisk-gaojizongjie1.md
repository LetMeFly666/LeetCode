---
title: python - 下载自百度网盘的远古の - 高级知识总结1
date: 2023-09-25 22:03:00
tags: [其他, Python, Notes]
---

# UDP通信

## 一、注意

1. 在使用网络调试助手进行网络数据传输时,需要将VMware虚拟的网络连接模式设置为桥接模式;如果设置为NAT模式,会出现跨平台通信时,代码内的bind绑定端口操作实际是无效的(端口号依旧在变化),具体是什么原因还不得而知!

   ​

   桥接模式: 直接连接物理网络,相当于两台电脑,如果没有在一个局域网内,则只能通过外网地址进行通信

   NAT模式: 共享主机的IP地址, 只能通过局域网地址访问

   ​

## 二、知识点

1.   关闭linux网卡:  

     **ifconfig ens33 down**

2.   开启linux网卡:

      **ifconfig ens33 up**



## 三、通讯过程分析

1. 创建套接字对象
2. 使用套接字发送/接收数据
3. 关闭套接字



## 四、案例分析

```python
import socket

def send_data(udp_socket):
    msg = input("请输入发送的数据： ").encode("utf-8")
    dest_ip = input("接受方ip地址： ")
    dest_port = int(input("接收方端口号："))
    udp_socket.sendto(msg, (dest_ip, dest_port))

def recv_data(udp_socket):
    recv_msg = udp_socket.recvfrom(1024)
    print(recv_msg[0].decode("utf-8"))
    print(recv_msg[1])


def main():
    udp_client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_client.bind(("", 65500))
    print("*" * 30)
    print("1: 发送数据！")
    print("2: 接收数据！")
    print("*" * 30)
    while True:
        op_num = input("please enter a function no: ")
        if op_num == "1":
            send_data(udp_client)
        elif op_num == "2":
            recv_data(udp_client)
        else:
            print("指令错误，请重新输入！")

if __name__ == "__main__":
    main()

```

# TCP通信

## 一、tcp特点

1. **面向连接**
   - 发送应答机制
   - 超时重传
   - 错误校验
   - 流量控制和阻塞管理
2. **可靠传输**   



## 二、TCP与UDP的不同

- 面向连接（确认有创建三方交握，连接已创建才作传输。）
- 有序数据传输
- 重发丢失的数据包
- 舍弃重复的数据包
- 无差错的数据传输
- 阻塞/流量控制



## 三、TCP通讯过程分析

1. **作为客户端**
   - 创建套接字对象
   - 连接服务器
   - 使用套接字发送/接收数据
   - 关闭套接字
2. **作为服务器**
   - 创建套接字对象
   - bind绑定ip和端口
   - 设置套接字为监听套接字
   - 等待客户端连接(连接成功得到服务套接字和客户端地址)
   - 使用服务套接字接收/发送数据
   - 关闭监听套接字和服务套接字

## 四、注意

1. tcp服务器一般情况下都需要绑定，否则客户端找不到这个服务器
2. tcp客户端一般不绑定，因为是主动链接服务器，所以只要确定好服务器的ip、port等信息就好，本地客户端可以随机
3. tcp服务器中通过listen可以将socket创建出来的主动套接字变为被动的，这是做tcp服务器时必须要做的
4. 当客户端需要链接服务器时，就需要使用connect进行链接，udp是不需要链接的而是直接发送，但是tcp必须先链接，只有链接成功才能通信
5. 当一个tcp客户端连接服务器时，服务器端会有1个新的套接字，这个套接字用来标记这个客户端，单独为这个客户端服务
6. listen后的套接字是被动套接字，用来接收新的客户端的链接请求的，而accept返回的新套接字是标记这个新客户端的
7. 关闭listen后的套接字意味着被动套接字关闭了，会导致新的客户端不能够链接服务器，但是之前已经链接成功的客户端正常通信。
8. 关闭accept返回的套接字意味着这个客户端已经服务完毕
9. 当客户端的套接字调用close后，服务器端会recv解堵塞，并且返回的长度为0，因此服务器可以通过返回数据的长度来区别客户端是否已经下线

# 多任务-进程

## 一、注意

1. 多进程执行过程-在创建进程后,操作系统会给新创建的这个进程**启动后(调用start)**拷贝一份运行代码(实际上是写时拷贝,只有运行过程中修改了运行代码才会真正的进行拷贝,没有修改运行代码实际是公用一份运行代码),之后每个进程(包括主进程)内数据都是独立的,即进程间数据是不共享的.

2. 拷贝的代码只是在进程创建的时候,由主进程分配给子进程的任务代码和传递的参数,而主进程所拥有的资源子进程并不是全部拥有

3. **进程内出现异常会报错,但进程池中的进程异常不会产生异常**

   ```python
   from multiprocessing import Process, Queue
   import time
   import random

   def write():
       for value in ['A', 'B', 'C']:
           print('Put %s to queue...' % value)
           q.put(value)
           time.sleep(random.random())
    
              
           
   def read():
        while True:
          if not q.empty():
              data = q.get()
              print("get {} from queue".format(data))
              time.sleep(random.randint(0, 5))
          else:
              continue
               
   if __name__ == "__main__":
      q = Queue()
      pw = Process(target=write)
      pr = Process(target=read)

      pw.start()
      pr.start()

      pw.join()
      pr.join()

   """
   运行结果:

      Process Process-2:

      NameError: name 'q' is not defined

      Process Process-1:

      NameError: name 'q' is not defined

      结果分析:

      队列是主进程资源,子进程无法访问
      队列必须在进程函数定义之前定义，函数只能访问定义前或则传递过来的参数
      通过传参的方式接收的参数是变量的引用，而全局参数在进程内部无法修改变量值，在进程内部修改的是一个新的变量

   """
   ```


## 二、案例分析

```python
from multiprocessing import Process
import os
import time

num = [11, 22]

def worker1(name, age, *args, **kwargs):
    print("in worker1 process_id = {}, num = {}".format(os.getpid(), num))
    print("name = {}, age = {}".format(name, age))
    print(args)
    print(kwargs)
    for i in range(3):
        time.sleep(1)
        num.append(i)
        print("in worker1 process_id = {}, num = {}".format(os.getpid(), num))


def worker2(name, age, *args, **kwargs):
    print("in worker2 process_id = {}, num = {}".format(os.getpid(), num))
    print("name = {}, age = {}".format(name, age))
    print(args)
    print(kwargs)
    for i in range(111,113):
        time.sleep(1)
        num.append(i)
        print("in worker2 process_id = {}, num = {}".format(os.getpid(), num))


p1 = Process(target=worker1, args=("work1", 18), kwargs=({"m":20}))
p2 = Process(target=worker2, args=("work2", 19), kwargs=({"m":21}))
p1.start()
num.append(999)
p1.join()
print("<num = {}>".format(num))
p2.start()

"""
运行结果:
  in worker1 process_id = 98304, num = [11, 22]
  name = work1, age = 18
  ()
  {'m': 20}
  in worker1 process_id = 98304, num = [11, 22, 0]
  in worker1 process_id = 98304, num = [11, 22, 0, 1]
  in worker1 process_id = 98304, num = [11, 22, 0, 1, 2]
  <num = [11, 22, 9999]>
  in worker2 process_id = 98305, num = [11, 22, 9999]
  name = work2, age = 19
  ()
  {'m': 21}
  in worker2 process_id = 98305, num = [11, 22, 9999, 111]
  in worker2 process_id = 98305, num = [11, 22, 9999, 111, 112]
"""
```



## 三、进程与线程区别

### 定义 : 

- 进程是系统进行**资源分配和调度的一个独立单位**.     		- - 比如 在一台电脑上能够同时运行多个QQ
- 线程是进程的一个实体,是**CPU调度和分派的基本单位**           - - 比如 一个QQ中的多个聊天窗口

### 区别 : 

- 一个程序至少有一个进程,一个进程至少有一个线程.
- 线程的划分尺度小于进程(资源比进程少)，使得多线程程序的并发性高。
- 进程在执行过程中拥有独立的内存单元，而多个线程共享内存，从而极大地提高了程序的运行效率
- 线线程不能够独立执行，必须依存在进程中
- 主进程默认等待子进程执行完毕才会结束,如果主进程被意外终止,子进程可以继续运行;这样的子进程被称作孤儿进程, 主线程默认也会等待子线程执行完毕才会结束,但是如果主线程结束,子线程不管有没有完成任务都会结束

### 优缺点 : 

- 线程和进程在使用上各有优缺点：线程执行开销小，但不利于资源的管理和保护；而进程正相反。




## 四、进程间通信 - Queue

### 作用 :

- 实现多进程之间的数据传递，Queue本身是一个消息列队程序

### 应用说明 :

from multiprocessing import Queue

- q = Queue()/Queue(-x) 		- - 定义一个进程间通信队列, 可接受的消息无上限(直达内存的尽头)

  - q = Queue(x)			- - 定义一个进程间通信,最大可接受x条消息

- Queue.qsize()：返回当前队列包含的消息数量；

- Queue.empty()：如果队列为空，返回True，反之False ；

- Queue.full()：如果队列满了，返回True,反之False；

- Queue.get([block[, timeout]])：获取队列中的一条消息，然后将其从列队中移除，block默认值为True；

  说明:

  | block | timeout | 描述                                       |
  | :---: | :-----: | :--------------------------------------- |
  | True  |    X    | 消息列队如果为空,程序被阻塞; 等待timeout秒 若还没读取到消息, 则抛出"Queue.Empty"异常 |
  | False |    /    | 消息列队如果为空，则会立刻抛出"Queue.Empty"异常           |

- Queue.get_nowait()：相当Queue.get(False)；

- Queue.put(item,[block[, timeout]])：将item消息写入队列，block默认值为True；

  说明 :

  | block | timeout | 描述                                       |
  | :---: | :-----: | ---------------------------------------- |
  | True  |    X    | 消息列队已满,程序将被阻塞;等待timeout秒, 若还没空间，则抛出"Queue.Full"异常 |
  | False |    /    | 消息列队如果没有空间可写入，则会立刻抛出"Queue.Full"异常；      |

  ​

  ## 进程池

  ### 作用 :

  ​	批量创建进程,进程任务的分配和空闲资源进程的回收,充分利用进程资源和资源的管理

  ### 运行 :

  ​	初始化Pool时，可以指定一个最大进程数，当有新的请求提交到Pool中时，如果池还没有满，那么就会创建一个新的进程用来执行该请求；但如果池中的进程数已经达到指定的最大值，那么该请求就会等待，直到池中有进程结束，才会用之前的进程来执行新的任务

  案例分析:

  ```python
  from multiprocessing import Pool
  import time
  import random
  import os

  def work(msg):
      start_time = time.time()
      print("{}开始执行,进程号 {}".format(msg, os.getpid()))
      time.sleep(random.random() * 2)
      end_time = time.time()
      print("{}结束执行,运行时间{}".format(msg, end_time-start_time))
      
  if __name__ == "__main__":
    p = Pool(3)
    for i in range(10):
        p.apply_async(work,args=(i,))

    time.sleep(1)
    print("------start--------")
  	# 关闭Pool，使其不再接受新的任务；  
    p.close()
    p.join()
    # 主进程阻塞，等待子进程的退出， 必须在close或terminate之后使用；
    print("--------end--------")
    
    # 说明:
     	"""
     	    这里主进程不会主动等待进程池任务执行,如果主进程执行完毕,进程池任务立即结束
     	    进程池在定义的时候没有指定最大进程数,系统会按当前运行计算机的cpu核心数决定进程池内运行的最大进程数,如计算机为双核,则进程池内最大进程数为2
     	""""
  ```


# 多任务-协程

## 可迭代对象与迭代器

## 一、可迭代对象 :

​	迭代是访问集合元素的一种方式。迭代器是一个可以记住遍历的位置的对象。迭代器对象从集合的第一个元素开始访问，直到所有的元素被访问完结束。迭代器只能往前不会后退。

### 定义 :

​	**我们把可以通过for...in...这类语句迭代读取一条数据供我们使用的对象称之为可迭代对象（Iterable）**

### 可迭代对象的本质 :

​	向我们提供一个这样的中间“人”即迭代器帮助我们对其进行迭代遍历使用。

可迭代对象通过`__iter__`方法向我们提供一个迭代器，我们在迭代一个可迭代对象的时候，实际上就是先获取该对象提供的一个迭代器，然后通过这个迭代器来依次获取对象中的每一个数据, 也就是说，一个具备了`__iter__`方法的对象，就是一个可迭代对象。

```python
class Mylist():

	def __iter__(self):
		pass
    
from collections import Iterable
isinstance(Mylist(), Iterable)
>>> True
```

## 二、迭代器 :

​	迭代器是用来帮助我们记录每次迭代访问到的位置，当我们对迭代器使用next()函数的时候，迭代器会向我们返回它所记录位置的下一个位置的数据。实际上，在使用next()函数的时候，调用的就是迭代器对象的`__next__`方法

### 定义 :

​	**一个实现了\_\_iter\_\_方法和\_\_next\_\_方法的对象，就是迭代器。**

### for  *  in  *  循环本质

​	for **item** in **Iterable** 循环的本质就是先通过iter()函数获取可迭代对象Iterable的迭代器，然后对获取到的迭代器不断调用next()方法来获取下一个值并将其赋值给item，当遇到StopIteration的异常后循环结束。

### 迭代器实现

```python
class MyList(object):

    def __init__(self):
        self.items = []

    def add(self, value):
        self.items.append(value)

    def __iter__(self):
        return MyIterator(self)

class MyIterator(object):

    def __init__(self, obj):
        self.data = obj
        self.current = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.current < len(self.data.items):
            item = self.data.items[self.current]
            self.current += 1
            return item
        else:
            raise StopIteration

m = MyList()
m.add(1)
m.add(22)
m.add(333)
m.add(444)

for i in m:
    print(i)
```

### 注意 :

​	并不是只有for循环能接收可迭代对象

```python
li = list(FibIterator(15))
print(li)
tp = tuple(FibIterator(6))
print(tp)
```



## 三、生成器

### 定义

​	只要在def中有yield关键字的 就称为 生成器, **生成器是一类特殊的迭代器**

### 生成器定义方式

```python
# 方式一
G = ( x*2 for x in range(5))
>>>  <generator object <genexpr> at 0x7f626c132db0>

# 方式二
def fib(n):
    current = 0
    num1, num2 = 0, 1
    while current < n:
        num = num1
        num1, num2 = num2, num1+num2
        current += 1
        yield num
    return 'done'
```



### 总结

- 使用了yield关键字的函数不再是函数，而是生成器。（使用了yield的函数就是生成器）
- yield关键字有两点作用：
  1. 保存当前运行状态（断点），然后暂停执行，即将生成器（函数）挂起
  2. 将yield关键字后面表达式的值作为返回值返回，此时可以理解为起到了return的作用
- 可以使用next()函数让生成器从断点处继续执行，即唤醒生成器（函数）
- Python3中的生成器可以使用return返回最终运行的返回值，而Python2中的生成器不允许使用return返回一个返回值（即可以使用return从生成器中退出，但return后不能有任何表达式）。

## 四、协程

### 定义

​	协程(微线程、纤程)是python个中另外一种实现多任务的方式，只不过比线程更小占用更小执行单元（理解为需要的资源）

### 协程与线程区别

​	在实现多任务时, 线程切换从系统层面远不止保存和恢复 CPU上下文这么简单。 操作系统为了程序运行的高效性每个线程都有自己缓存Cache等等数据，操作系统还会帮你做这些数据的恢复操作。 所以线程的切换非常耗性能。但是协程的切换只是单纯的操作CPU的上下文，所以一秒钟切换个上百万次系统都抗的住。

### yield协程简单实现

```python
import time

def work1():
    while True:
        print("----work1---")
        yield
        time.sleep(0.5)

def work2():
    while True:
        print("----work2---")
        yield
        time.sleep(0.5)

def main():
    w1 = work1()
    w2 = work2()
    while True:
        next(w1)
        next(w2)

if __name__ == "__main__":
    main()
```



### greenlet协程简单实现

```python
# pip3 install greenlet

from greenlet import greenlet
import time

def test1():
    while True:
        print "---A--"
        gr2.switch()
        time.sleep(0.5)

def test2():
    while True:
        print "---B--"
        gr1.switch()
        time.sleep(0.5)

gr1 = greenlet(test1)
gr2 = greenlet(test2)

#切换到gr1中运行
gr1.switch()
```



### greenlet协程简单实现

执行过程

​	当一个greenlet遇到IO(指的是input output 输入输出，比如网络、文件操作等)操作时，比如访问网络，就自动切换到其他的greenlet，等到IO操作完成，再在适当的时候切换回来继续执行。由于IO操作非常耗时，经常使程序处于等待状态，有了gevent为我们自动切换协程，就保证总有greenlet在运行，而不是等待IO

###  gevent的使用

```python
# pip3 install gevent

import gevent

def f(n):
    for i in range(n):
        print(gevent.getcurrent(), i)

g1 = gevent.spawn(f, 5)
g2 = gevent.spawn(f, 5)
g3 = gevent.spawn(f, 5)
g1.join()
g2.join()
g3.join()

# 运行结果
<Greenlet at 0x10e49f550: f(5)> 0
<Greenlet at 0x10e49f550: f(5)> 1
<Greenlet at 0x10e49f550: f(5)> 2
<Greenlet at 0x10e49f550: f(5)> 3
<Greenlet at 0x10e49f550: f(5)> 4
<Greenlet at 0x10e49f910: f(5)> 0
<Greenlet at 0x10e49f910: f(5)> 1
<Greenlet at 0x10e49f910: f(5)> 2
<Greenlet at 0x10e49f910: f(5)> 3
<Greenlet at 0x10e49f910: f(5)> 4
<Greenlet at 0x10e49f4b0: f(5)> 0
<Greenlet at 0x10e49f4b0: f(5)> 1
<Greenlet at 0x10e49f4b0: f(5)> 2
<Greenlet at 0x10e49f4b0: f(5)> 3
<Greenlet at 0x10e49f4b0: f(5)> 4
# 可以看到，3个greenlet是依次运行而不是交替运行
```

### gevent切换执行

```python
import gevent

def f(n):
    for i in range(n):
        print(gevent.getcurrent(), i)
        #用来模拟一个耗时操作，注意不是time模块中的sleep
        gevent.sleep(1)

g1 = gevent.spawn(f, 5)
g2 = gevent.spawn(f, 5)
g3 = gevent.spawn(f, 5)
g1.join()
g2.join()
g3.join()

# 运行结果
<Greenlet at 0x7fa70ffa1c30: f(5)> 0
<Greenlet at 0x7fa70ffa1870: f(5)> 0
<Greenlet at 0x7fa70ffa1eb0: f(5)> 0
<Greenlet at 0x7fa70ffa1c30: f(5)> 1
<Greenlet at 0x7fa70ffa1870: f(5)> 1
<Greenlet at 0x7fa70ffa1eb0: f(5)> 1
<Greenlet at 0x7fa70ffa1c30: f(5)> 2
<Greenlet at 0x7fa70ffa1870: f(5)> 2
<Greenlet at 0x7fa70ffa1eb0: f(5)> 2
<Greenlet at 0x7fa70ffa1c30: f(5)> 3
<Greenlet at 0x7fa70ffa1870: f(5)> 3
<Greenlet at 0x7fa70ffa1eb0: f(5)> 3
<Greenlet at 0x7fa70ffa1c30: f(5)> 4
<Greenlet at 0x7fa70ffa1870: f(5)> 4
<Greenlet at 0x7fa70ffa1eb0: f(5)> 4
```

### gevent打补丁

```python
from gevent import monkey
import gevent
import random
import time

# 有耗时操作时需要
monkey.patch_all()  # 将程序中用到的耗时操作的代码，换为gevent中自己实现的模块

def coroutine_work(coroutine_name):
    for i in range(10):
        print(coroutine_name, i)
        time.sleep(random.random())

gevent.joinall([
        gevent.spawn(coroutine_work, "work1"),
        gevent.spawn(coroutine_work, "work2")
])
```

### gevent 执行过程解析

```python
import gevent
import time

from gevent import monkey
monkey.patch_all()


def fun(n):
    for i in range(n):
        print(gevent.getcurrent(), i)
        time.sleep(0.5)
    else:
        print("%s执行完毕" %gevent.getcurrent())


def main():
    # 这里可以认为添加了3个协程任务(一个整体)
    g1 = gevent.spawn(fun, 1)
    print("g1 start")
    g2 = gevent.spawn(fun, 3)
    print("g2 start")
    g3 = gevent.spawn(fun, 5)
    print("g3 start")

    # join为耗时操作,启动协程任务;在进行第二轮(一轮表示执行完一次所有待执行的协程任务)任务执行时,首先执行g1,而g1
    # 任务已完成,依次(按添加顺序)执行g2,g3;则第二轮协程任务完成,g1.join()结束等待,继续执行主线任务
    g1.join()
    print("g1 任务完成")
    g2.join()
    print("g2 任务完成")
    g3.join()
    print("g3 任务完成")


if __name__ == '__main__':
    main()
    
# 运行结果
g1 start
g2 start
g3 start
<Greenlet "Greenlet-0" at 0x1df556ca148: fun(1)> 0
<Greenlet "Greenlet-1" at 0x1df556ca248: fun(3)> 0
<Greenlet "Greenlet-2" at 0x1df556ca348: fun(5)> 0
<Greenlet "Greenlet-0" at 0x1df556ca148: fun(1)>执行完毕
<Greenlet "Greenlet-1" at 0x1df556ca248: fun(3)> 1
<Greenlet "Greenlet-2" at 0x1df556ca348: fun(5)> 1
g1 任务完成
<Greenlet "Greenlet-1" at 0x1df556ca248: fun(3)> 2
<Greenlet "Greenlet-2" at 0x1df556ca348: fun(5)> 2
<Greenlet "Greenlet-1" at 0x1df556ca248: fun(3)>执行完毕
<Greenlet "Greenlet-2" at 0x1df556ca348: fun(5)> 3
g2 任务完成
<Greenlet "Greenlet-2" at 0x1df556ca348: fun(5)> 4
<Greenlet "Greenlet-2" at 0x1df556ca348: fun(5)>执行完毕
g3 任务完成
```

# 进程、线程、协程区别

- 进程是资源分配的单位
- 线程是操作系统调度的单位
- 进程切换需要的资源很最大，效率很低
- 线程切换需要的资源一般，效率一般（当然了在不考虑GIL的情况下）
- 协程切换任务资源很小，效率高
- 多进程、多线程根据cpu核数不一样可能是并行的，但是协程是在一个线程中 所以是并发


## 进程线程综合演练

```python
#  *_* coding:utf8 *_*
"""
案例功能:
	使用多进程多线程完成妹子图下载
	进程1: 完成页面图片链接
	进程2: 完成多线程图片下载
"""
import random
import requests
import os
import re
from threading import Thread
from multiprocessing import Queue, Process

import time
import socket

socket.setdefaulttimeout(20)

q = Queue()


class GetImage(object):
    def __init__(self, url, header):
        self.current_page_url = url
        self.header = header
        self.resource_urls = []
        self.GET_NULL_LIMIT = 3
        self.current_null_times = 0
        self.is_dormancy = False
        self.dormancy_time = 30

    def get_image_url(self, q):
        print(">>>>>>>>> 开始获取图片网址 <<<<<<<<<")
        while True:
            response = self.get_current_page_data()
            resource_urls = re.findall(r"data-original='(.*?)'", response)
            if resource_urls:
                q.put(resource_urls)
                self.resource_urls.extend(resource_urls)
            else:
                q.put(None)
                break

    def get_current_page_data(self):
        if self.current_page_url:
            print("\n请求网页 {}  数据".format(self.current_page_url))
            response = requests.get(self.current_page_url, headers=self.header)
            response.close()
            response_content = response.text
            time.sleep(random.random())
            ret = re.search(r"""<a class="next page-numbers" href="(.*?)">下一页&raquo;</a>""", response_content)
            if ret:
                self.current_page_url = ret.group(1)
            else:
                self.current_page_url = None

            return response_content
        else:
            return ""

    def download_image(self, save_dir):
        Process(target=self.get_image_url, args=(q,)).start()
        Process(target=self.start_download_image, args=(save_dir, q)).start()

    def start_download_image(self, save_dir, q):
        print("************ 开始下载图片 *************")
        while True:
            image_urls = q.get()
            if not image_urls:
                break

            if self.is_dormancy:
                print("[WARRING]: 获取数据错误次数超阈值次!")
                print("[WARRING]: 被服务器发现了,图片下载休眠 {} 秒钟.....".format(self.dormancy_time))
                time.sleep(self.dormancy_time)
                if self.current_null_times > self.GET_NULL_LIMIT * 3:
                    print("[ERROR]: 程序退出!")
                    os.kill(os.getppid(), 9)
                    os.kill(os.getpid(), 9)
                    exit()

            for image_url in image_urls:
                Thread(target=self.execute_download, args=(image_url, save_dir)).start()

    def execute_download(self, image_url, save_dir):
        response = requests.get(image_url, headers=self.header)
        response.close()
        time.sleep(random.random())
        image_name = image_url.split('/')[-1]
        save_path = os.path.join(save_dir, image_name)
        image_data = response.content

        if image_data:
            self.save_resource(image_data, save_path)
            print("{} 完成下载".format(image_name))
            self.is_dormancy = False
            self.current_null_times = 0
        elif self.current_null_times < self.GET_NULL_LIMIT:
            self.current_null_times += 1
            print("[INFO]: 图片 {} 获取失败! 数据请求网址 {} ".format(image_name, image_url))
        else:
            self.current_null_times += 1
            print("[INFO]: 图片 {} 获取失败! 数据请求网址 {} ".format(image_name, image_url))
            self.is_dormancy = True

    @staticmethod
    def save_resource(content, save_path):
        with open(save_path, "wb") as f:
            f.write(content)


mz_url = "https://www.mzitu.com/"
mz_header = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
                  "(KHTML, like Gecko) Chrome/73.0.3683.103 Safari/537.36",
    "Referer": "https://www.mzitu.com/",
}

if __name__ == '__main__':
    mz_image = GetImage(mz_url, mz_header)
    mz_image.download_image("images")
```



# 正则表达式

## 一、定义

​	正则表达式是对字符串操作的一种逻辑公式，就是用事先定义好的一些特定字符、及这些特定字符的组合，组成一个“规则字符串”，这个“规则字符串”用来表达对字符串的一种过滤逻辑

## 二、字符匹配

- ### 单字符匹配

|  字符  | 功能                    |
| :--: | :-------------------- |
|  .   | 匹配任意1个字符（除了\n）        |
| [ ]  | 匹配[ ]中列举的字符           |
|  \d  | 匹配数字，即0-9             |
|  \D  | 匹配非数字，即不是数字           |
|  \s  | 匹配空白，即 空格，tab键        |
|  \S  | 匹配非空白                 |
|  \w  | 匹配单词字符，即a-z、A-Z、0-9、_ |
|  \W  | 匹配非单词字符               |

- ### 多字符匹配

|  字符   | 功能                          |
| :---: | --------------------------- |
|   *   | 匹配前一个字符出现0次或者无限次，即可有可无      |
|   +   | 匹配前一个字符出现1次或者无限次，即至少有1次     |
|   ?   | 匹配前一个字符出现1次或者0次，即要么有1次，要么没有 |
|  {m}  | 匹配前一个字符出现m次                 |
| {m,n} | 匹配前一个字符出现从m到n次              |

- ### 匹配开头结尾

|  字符  | 功能      |
| :--: | ------- |
|  ^   | 匹配字符串开头 |
|  $   | 匹配字符串结尾 |

- ### 匹配分组

|    字符     | 功能                 |
| :-------: | ------------------ |
|    \|     | 匹配左右任意一个表达式        |
|   (ab)    | 将括号中字符作为一个分组       |
|  `\num`   | 引用分组num匹配到的字符串     |
|  `(?P)`   | 分组起别名              |
| (?P=name) | 引用别名为name分组匹配到的字符串 |

实例演示

```python
>>> ret = re.match("([^-]*)-(\d+)","010-12345678")
>>> ret.group()
'010-12345678'
>>> ret.group(1)
'010'
>>> ret.group(2)
'12345678'

import re

labels = ["<html><h1>www.itcast.cn</h1></html>", "<html><h1>www.itcast.cn</h2></html>"]

for label in labels:
    ret = re.match(r"<(\w*)><(\w*)>.*</\2></\1>", label)
    if ret:
        print("%s 是符合要求的标签" % ret.group())
    else:
        print("%s 不符合要求" % label)
    
# 运行结果：
<html><h1>www.itcast.cn</h1></html> 是符合要求的标签
<html><h1>www.itcast.cn</h2></html> 不符合要求


import re

ret = re.match(r"<(?P<name1>\w*)><(?P<name2>\w*)>.*</(?P=name2)></(?P=name1)>", "<html><h1>www.itcast.cn</h1></html>")
ret.group()
```



## 三、re 高级用法

1. ### **search**

```python
#coding=utf-8
import re

ret = re.search(r"\d+", "阅读次数为 9999")
ret.group()

运行结果：
'9999'
```

2. ### **findall**

```python
#coding=utf-8
import re

ret = re.findall(r"\d+", "python = 9999, c = 7890, c++ = 12345")
print(ret)

运行结果：
['9999', '7890', '12345']
```

3. ### **sub**

```python
#coding=utf-8
eg1:
import re

ret = re.sub(r"\d+", '998', "python = 997")
print(ret)

运行结果：
python = 998


eg2:
#coding=utf-8
import re

def add(temp):
    strNum = temp.group()
    num = int(strNum) + 1
    return str(num)

ret = re.sub(r"\d+", add, "python = 997")
print(ret)

ret = re.sub(r"\d+", add, "python = 99")
print(ret)

运行结果：
python = 998
python = 100
```

## 四、贪婪与非贪婪

### 概念 :

​	Python里数量词默认是贪婪的（在少数语言里也可能是默认非贪婪），总是尝试匹配尽可能多的字符；

非贪婪则相反，总是尝试匹配尽可能少的字符。在"*","?","+","{m,n}"后面加上？，使贪婪变成非贪婪。

```python
>>> re.match(r"aa(\d+)","aa2343ddd").group(1)
'2343'
>>> re.match(r"aa(\d+?)","aa2343ddd").group(1)
'2'
>>> re.match(r"aa(\d+)ddd","aa2343ddd").group(1) 
'2343'
>>> re.match(r"aa(\d+?)ddd","aa2343ddd").group(1)
'2343'
```

# Http协议、Web服务器

## 一、定义

在Web应用中，服务器把网页传给浏览器，实际上就是把网页的HTML代码发送给浏览器，让浏览器显示出来。而浏览器和服务器之间的传输协议是HTTP

- HTML是一种用来定义网页的文本，会HTML，就可以编写网页；
- HTTP是在网络上传输HTML的协议，用于浏览器和服务器的通信。

## 二、协议分析

1. ### HTTP格式

   一个HTTP包含Header和Body两部分，其中Body是可选的。

2. ### HTTP  GET请求格式

   ```
   GET /path HTTP/1.1
   Header1: Value1
   Header2: Value2
   Header3: Value3
   ```

3. ### HTTP  POST响应格式

   ```
   200 OK
   Header1: Value1
   Header2: Value2
   Header3: Value3

   body data goes here...

   Body的数据类型由Content-Type头来确定，如果是网页，Body就是文本，如果是图片，Body就是图片的二进制数据
   ```

## 三、web静态服务器-epool (单进程单线程)

```python
import socket
import sys
import re
import select

class WSGIServer(object):

    def __init__(self, port, root_path):
        self.socket_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket_server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.socket_server.bind(("", port))
        self.socket_server.listen(128)
        self.root_path = root_path

    def run_forever(self):
        socket_fileno_dict = dict()
        epl = select.epoll()
        epl.register(self.socket_server.fileno(), select.EPOLLIN)
        while True:
            socket_list = epl.poll()
            for socket_fileno, event in socket_list:
                if socket_fileno == self.socket_server.fileno():
                    client_info = self.socket_server.accept()
                    socket_fileno_dict[client_info[0].fileno()] = client_info[0]
                    epl.register(client_info[0].fileno(), select.EPOLLIN)
                    print("接入新客户", client_info[1])
                elif event == select.EPOLLIN:
                    client_socket = socket_fileno_dict[socket_fileno]
                    recv_data = client_socket.recv(1024)
                    if not recv_data:
                       print("结束服务", )
                       client_socket.close()
                       epl.unregister(socket_fileno)
                       del socket_fileno_dict[socket_fileno]
                    else:
                       data_lines = recv_data.decode().splitlines()
                       for line in data_lines:
                           print(line)
                       request_path = re.match(r"[^/]+(/[^ ]*)", data_lines[0]).group(1)
                       self.request_headle(client_socket, request_path)


    def request_headle(self, client_server, path):
        if path == "/":
            response_path = self.root_path + "/index.html"
        else:
            response_path = self.root_path + path

        try:
            with open(response_path, "rb") as f:
                response_body = f.read()
        except:
            response_body = "you brower page web not found".encode("utf-8")
            response_header = "http/1.1 404 not found page \r\n"
            response_header += "Content-Length: %d\r\n"%len(response_body)
            response_header += "\r\n"
        else:
            response_header = "http/1.1 200 ok \r\n"
            response_header += "Content-Length: %d\r\n"%len(response_body)
            response_header += "\r\n"
        finally:
            client_server.send(response_header.encode("utf-8") + response_body)


def main():
    if len(sys.argv) == 2:
        port = int(sys.argv[1])
    else:
        print("please input format run 'python3 xx.py 8888'")
        return

    root_dir = "./html"
    print("WSGIServer run in port ", port)
    wsgi_server = WSGIServer(port, root_dir)
    wsgi_server.run_forever()


if __name__ == "__main__":
    main()
```

* 这里的epoll只能运行在linux,在其他系统上有改版的工具包
* epoll工作过程图解

![epoll](images\epoll.jpg)

- epoll能够高效运行的原因
  1. 事件监听工作方式
  2. 与操作系统共享内存,减少文件拷贝耗时

I/O 多路复用的特点：

​	通过一种机制使一个进程能同时等待多个文件描述符，而这些文件描述符（套接字描述符）其中的任意一个进入读就绪状态，epoll()函数就可以返回。 所以, IO多路复用，本质上不会有并发的功能，因为任何时候还是只有一个进程或线程进行工作，它之所以能提高效率是因为select\epoll 把进来的socket放到他们的 '监视' 列表里面，当任何socket有可读可写数据立马处理，那如果select\epoll 手里同时检测着很多socket， 一有动静马上返回给进程处理，总比一个一个socket过来,阻塞等待,处理高效率。

​	当然也可以多线程/多进程方式，一个连接过来开一个进程/线程处理，这样消耗的内存和进程切换页会耗掉更多的系统资源。 所以我们可以结合IO多路复用和多进程/多线程 来高性能并发，IO复用负责提高接受socket的通知效率，收到请求后，交给进程池/线程池来处理逻辑。

epoll在linux中的实现过程可参考

[http://blog.csdn.net/xiajun07061225/article/details/9250579](http://blog.csdn.net/xiajun07061225/article/details/9250579)



> 于2020.2.11日下载自百度网盘（个人笔记.rar），共包含三个md文件，这是其一。
>
> 无法追述到作者及来源，但所总结的内容确实较为优质，不忍心删除之，不想令其石沉大海。
>
> 若原作者发现了此文，请与[我](https://github.com/LetMeFly666)联系🌹
>
> [本文地址](https://blog.tisfy.eu.org/2023/09/25/Other-Python-PythonNotesFromBaiduDisk-gaojizongjie1/)
