---
title: 如何将网站某页面全部修改为黑白色
date: 2022-12-01 15:42:43
tags: [其他, HTML, 简单]
---

昨日，缅怀🕯️

很多国内网站都将主页全部修改为了黑白色

参考CSDN的文章：[https://blog.csdn.net/qq_40482342/article/details/123898474](https://blog.csdn.net/qq_40482342/article/details/123898474)

只需要在网页```<head></head>```标签下添加如下格式即可

```html
<style> 
    html { 
        -webkit-filter: grayscale(100%); 
        -moz-filter: grayscale(100%); 
        -ms-filter: grayscale(100%); 
        -o-filter: grayscale(100%); 
        filter:progid:DXImageTransform.Microsoft.BasicImage(grayscale=1);  
        _filter:none; 
    } 
</style>
```

通过JS将**主页**修改为黑白

```javascript
const THEGRAYSTYLE = document.createElement("style");
THEGRAYSTYLE.innerHTML = "html { \n-webkit-filter: grayscale(100%); \n-moz-filter: grayscale(100%); \n-ms-filter: grayscale(100%); \n-o-filter: grayscale(100%); \nfilter:progid:DXImageTransform.Microsoft.BasicImage(grayscale=1);  \n_filter:none; \n}"
function ifChange() {
    const href = location.href;
    const mainHref = href.indexOf("://") ? href.substring(href.indexOf("://") + 3) : href;
    for (var i = 0; i + 1 < mainHref.length; i++) {
        if (mainHref[i] == '/' && mainHref[i + 1] != '?')
            return false;
    }
    return true;
}
if (ifChange()) {
    document.querySelector("head").append(THEGRAYSTYLE);
}
```

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/01/Other-HTML-ChangeWeb2Gray/)哦~
> [https://blog.letmefly.xyz/2022/12/01/Other-HTML-ChangeWeb2Gray/](https://blog.letmefly.xyz/2022/12/01/Other-HTML-ChangeWeb2Gray/)
