---
title: HTML - Javascript - JS可变参数函数
date: 2023-04-05 21:00:13
tags: [其他, HTML, Javascript, JS]
categories: [技术思考]
---

# HTML - Javascript - JS可变参数函数

Javascript作为一个非常灵活的语言，肯定能有办法让函数接受不同数量的参数。

但是怎么接受呢？像Python那样```def f(**args)```？

当然不是。Javascript（后文简称JS）采用的方法更为奇特，直接无需在参数列表中定义，直接向函数中传递你想要传递的参数即可。

那么在函数中怎么获取呢？函数中有一个变量叫```arguments```，可以把它当作一个数组，里面存放了传入这个函数的所有参数。

举个例子：

```javascript
function MySum() {
    var ans = 0;
    for (var i = 0; i < arguments.length; i++) {
        ans += arguments[i];
    }
    return ans;
}

const SUM = MySum(1, 2, 3, 4);
console.log(SUM);
```

运行结果：

```
10
```

**题外话：**

有没有很好奇arguments到底长啥样呢？

不如我们在函数中输出一下：

```javascript
function f() {
    console.log(arguments);
}

f();
f(1, 2, "Hello");
```

在谷歌浏览器控制台执行，可以得到结果：

```
Arguments [callee: ƒ, Symbol(Symbol.iterator): ƒ]
Arguments(3) [1, 2, 'Hello', callee: ƒ, Symbol(Symbol.iterator): ƒ]
```

完全可以将其理解为一个有着特殊属性的列表/数组。

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/05/Other-HTML-Javascript-variableParamaterFunction)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129977062](https://letmefly.blog.csdn.net/article/details/129977062)
