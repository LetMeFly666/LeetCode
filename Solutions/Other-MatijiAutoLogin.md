---
title: 码蹄集需要频繁登录？如何做到“一劳永逸”——码蹄集只登录一次久久不掉线的教程
date: 2022-08-30 18:27:57
tags: [其他, 码蹄集, 简单, 免登录, 前端]
categories: [技术思考]
---

# 码蹄集需要频繁登录？如何做到“一劳永逸”——码蹄集只登录一次久久不掉线的教程

这个方法至少到我发文之时（20220830）仍然有效。如果后续失效了，可能是码蹄集后端进行了优化（估计不是因为看了我这篇文章才改的后端）

## 背景

电脑上码蹄集每次打开浏览器都需要重新登录，并且要么扫码要么短信验证，不能输入密码登录。

以上两种方法都需要手机配合才能进行，清华社称这是为了安全。

虽然不是很麻烦，但**用手机配合才能登录**不像是程序员的风格。

某日忽然发现手机夸克很久之前的登录没有掉线！

这说明码蹄集后端服务器不会定期删除Cookie（至少个把月）。

那为什么浏览器一关就得重新登录了呢？很简单，前端让浏览器把Cookie给删了呗。

因此，整活开始：手动告诉浏览器，这个Cookie的有效期是1000天。

## 具体方法

前端设置和获得Cookie可以参考[菜鸟教程](https://www.runoob.com/js/js-cookies.html)提供的方法（需稍加修改）：

**获取Cookie：**

```javascript
function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i].trim();
        if (c.indexOf(name)==0) return c.substring(name.length,c.length);
    }
    return "";
}
```

**设置Cookie：**

```javascript
function setCookie(cname,cvalue,exdays) {
    var d = new Date();
    d.setTime(d.getTime()+(exdays*24*60*60*1000));
    var expires = "expires="+d.toGMTString();
    document.cookie = cname + "=" + cvalue + "; " + expires + "; path=/";
}
```

经过分析，码蹄集储存用户身份信息的Cookie叫```token```，因此我们可以获取到这个Cookie并将其设置为1000天。

```javascript
// 只需要在码蹄集首页打开控制台，复制这段代码粘贴并回车即可
function getCookie(cname) {
    var name = cname + "=";
    var ca = document.cookie.split(';');
    for(var i=0; i<ca.length; i++) {
        var c = ca[i].trim();
        if (c.indexOf(name)==0) return c.substring(name.length,c.length);
    }
    return "";
}

function setCookie(cname,cvalue,exdays) {
    var d = new Date();
    d.setTime(d.getTime()+(exdays*24*60*60*1000));
    var expires = "expires="+d.toGMTString();
    document.cookie = cname + "=" + cvalue + "; " + expires + "; path=/";
}

let token = getCookie("token");
setCookie("token", token, 100);  // 100天内不用重新登录
```

## 具体方法

登录码蹄集，在码蹄集[首页](https://matiji.net/exam/)打开控制台（打开控制台的手把手教程可以参考：[https://letmefly.blog.csdn.net/article/details/106959306](https://letmefly.blog.csdn.net/article/details/106959306)），然后复制上面一段代码，粘贴并回车即可。

<small>本来想着实现免频繁登录是为了节省登录时间，但是写博客、做视频用了一个多小时</small>  :snowflake:

<small>不过我想发明洗衣机的耗时应该也比洗衣服时间长，希望能方便到各位看官吧</small>

<iframe src="//player.bilibili.com/player.html?aid=857601399&bvid=BV1DV4y1H75q&cid=819266825&page=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true" width="100%" height="500px"> </iframe>

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/30/Other-MatijiAutoLogin/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126610331](https://letmefly.blog.csdn.net/article/details/126610331)
