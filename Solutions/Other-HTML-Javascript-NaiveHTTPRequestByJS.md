---
title: HTML - Javascript - 原生的JS HTTP请求：实用主义的一篇文章
date: 2023-08-06 18:58:51
tags: [其他, HTML, Javascript, JS, HTTPRequest]
---

# HTML - Javascript - 原生的JS HTTP请求：实用主义的一篇文章

## 前言

虽然现在使用JQuery等可以做到很方便的HTTP请求，但是这样做毕竟要引入一些JS文件。

如果想使用原生的JS进行HTTP网络请求应该怎样呢？可以使用XMLHttpRequest。

## 使用方法

**GET请求**

```javascript
var httpRequest = new XMLHttpRequest();
httpRequest.open('GET', 'https://hanyu.baidu.com/static/asset/css/main.css', false);  // false是指不同步（异步）
httpRequest.send();
console.log(httpRequest.response);
```

这样就能得到```string```格式的response了。

**POST请求**

POST请求和GET请求基本相同：

```javascript
var httpRequest = new XMLHttpRequest();
httpRequest.open('POST', '/api/login/', false);
httpRequest.send(JSON.stringify(warrant));
console.log(httpRequest.response);
```

## What's More

返回的结果可能是字符串类型的，可以使用```JSON.parse()```将其转为object类型

```javascript
data = JSON.parse(httpRequest.response);
console.log(data);
console.log(typeof(data));
```

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/08/06/Other-HTML-Javascript-NaiveHTTPRequestByJS/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132134252](https://letmefly.blog.csdn.net/article/details/132134252)
