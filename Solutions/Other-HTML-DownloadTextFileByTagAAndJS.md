---
title: HTML - HTML中使用JS下载文本文件
date: 2023-07-06 11:07:29
tags: [其他, HTML, Javascript, JS, 文件, 文件下载]
categories: [技术思考]
---

# HTML - HTML中使用JS下载文本文件

如果只希望将一些文本以文件形式保存到本地，则可以使用```a```标签

## 方法一：使用href属性

```html
<a href="data:text/plain;charset=utf-8,要保存文件的文本" download="文本.txt">点我下载</a>
```

<a href="data:text/plain;charset=utf-8,要保存文件的文本" download="文本.txt">点我下载</a>

拓展：字符串形式的DOM：

```javascript
div = document.querySelector("div");
str = div.innerHTML
```

## 方法二：使用Blog文件流

方法一中若要下载的文本中有引号，则转义起来比较麻烦。因此可以使用文件流来进行下载：

```html
<a id="ToDownload">点我下载</a>
<script>
    function set1download(a, fileName, fileStream) {
        const blob = new Blob([fileStream], {type: 'application/text'});
        const href = window.URL.createObjectURL(blob);
        a.href = href;
        a.download = decodeURI(fileName);
        // window.URL.revokeObjectURL(href);
    }
    set1download(
        document.querySelector("#ToDownload"),
        '文本文件下载测试.txt',
        '要下载的内容，引号测试"6"666'
    );
</script>
```

<a id="ToDownload20230706">点我下载</a>
<script>
    function set1download(a, fileName, fileStream) {
        const blob = new Blob([fileStream], {type: 'application/text'});
        const href = window.URL.createObjectURL(blob);
        a.href = href;
        a.download = decodeURI(fileName);
        // window.URL.revokeObjectURL(href);
    }
    set1download(
        document.querySelector("#ToDownload20230706"),
        '文本文件下载测试.txt',
        '要下载的内容，引号测试"6"666'
    );
</script>

在CSDN中可能因为无法执行JS等原因看不到效果，具体效果可以前往[我的Blog](https://blog.letmefly.xyz/2023/07/06/Other-HTML-DownloadTextFileByTagAAndJS/)查看。

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/06/Other-HTML-DownloadTextFileByTagAAndJS/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131572006](https://letmefly.blog.csdn.net/article/details/131572006)
