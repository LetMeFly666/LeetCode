---
title: PWA(Progressive web apps)：Web技术实现类似原生应用 - 入门
date: 2023-03-17 21:38:06
tags: [其他, PWA, Notes, Web, Web App]
---

# PWA(Progressive web apps)：Web技术实现类似原生应用 - 入门简介

## 前言

在（使用Google浏览器）访问一些网站时，有时右上角会弹出“安装应用”的按钮。

![安装应用](https://img-blog.csdnimg.cn/4e3c5c2f99c34fd8813e3d6bbbf73736.png)

例如[谷歌V8官网](https://v8.dev/)

![V8官网](https://img-blog.csdnimg.cn/c8d4c53fdd81461c9bc167dabf58d73c.png)

如果我们点击“安装”，则会在桌面生成一个“快捷方式”，并且当前页面也会弹出为独立的窗口。

![独立窗口](https://img-blog.csdnimg.cn/b559cb43b62344e7b9ba67200f598278.png)

我们双击桌面的快捷方式也能达到同样的效果。

![快捷方式](https://img-blog.csdnimg.cn/d294e60bacdb4cc8b48893005d6f0328.png)

**这就像是我们打开了一个安装在本地的程序一样**，并且能在“设置->应用和功能”中找到（Win10下可以```Win + R```，```ms-settings:appsfeatures```，```回车```）

![应用和功能](https://img-blog.csdnimg.cn/4265e108066443cd8166e9e83768193c.png)

查看快捷方式的属性，可以发现其实质上是指向了```chrome_proxy.exe```，其目标为```"C:\Program Files\Google\Chrome\Application\chrome_proxy.exe"  --profile-directory=Default --app-id=omahloekemgldcjjnolkgifggmedapio```

实质上只是在具有专属边框的独立窗口中打开了这个网页而已。

这样做有什么**好处**呢？

首先相比于单独的程序而言，这个方法不需要真正地安装程序，其实质上可以理解为一个快捷方式。

其次，相比于普通的网页而言，安装为“应用”的网页可以离线打开、方便缓存很多内容等。

假如我做了一个纯前端的在线图片生成工具箱，那么我就可以将其打包成PWA应用，这样用户在“安装到本地后”，可以在几乎不占用额外硬盘空间的情况下（当然缓存当前前端页面及其资源还是要占用一丢丢的空间的），**离线**使用这个工具箱。

有点介绍完了，怎么卸载呢？

两种方法，一个是直接在Windows设置中卸载

![卸载1](https://img-blog.csdnimg.cn/ea9f07d95adf490d9e91a991588922ce.png)

另一个是在打开应用后，点击右上方三个点，并选择卸载

![卸载2](https://img-blog.csdnimg.cn/756313c98c1d4ab287c04c6349df7348.png)

记得清除数据

![清除数据](https://img-blog.csdnimg.cn/1c98b0b090fb41b1b182d89f26f33888.png)

前言讲完了，接下来是其简介，以及如何编写PWA应用：

## 简介（Answered by ChatGPT）

PWA指的是Progressive Web App，是一种通过Web技术实现类似原生应用的用户体验的应用程序。

与传统的Web应用程序不同，PWA可以离线访问，有着更快的加载速度、更流畅的交互体验，并且可以在桌面上以应用程序的形式运行。PWA利用了现代浏览器提供的一些API和技术，如Service Workers和Web App Manifests，实现了离线缓存、推送通知、添加到主屏幕等功能，使得用户可以像使用原生应用程序一样使用它们。

PWA的优点包括：

1. 不需要下载安装：PWA不需要用户下载和安装，可以通过浏览器直接使用。
1. 快速加载：PWA可以利用Service Workers等技术，实现本地缓存和离线访问，使得加载速度更快。
1. 可以离线访问：PWA可以离线使用，用户不必依赖网络连接。
1. 可以添加到主屏幕：用户可以将PWA添加到主屏幕，以应用程序的形式进行访问。
1. 推送通知：PWA可以通过推送通知的方式向用户发送信息，增强用户体验。

总的来说，PWA是一种融合了Web和原生应用程序的优点的新型应用程序，为用户提供了更好的体验，也为开发者提供了更便捷的开发方式。

## 如何编写PWA应用

当然还是看官方文档为妙：

+ [谷歌官方文档](https://developers.google.com/web/progressive-web-apps)（点击后会跳转到[这里](https://web.dev/progressive-web-apps/)大陆可直接访问）
+ [Mozilla文档](https://developer.mozilla.org/en-US/docs/Web/Progressive_web_apps)

最后贴上ChatGPT对“如何编写PWA应用”的总结：

PWA（Progressive Web Apps）是一种使用 Web 技术编写的应用程序，可以像原生应用程序一样运行，并提供离线缓存、推送通知等功能。下面是编写 PWA 应用的一般步骤：

1. 确定应用程序的功能和设计，以及响应式布局、离线缓存等功能。
1. 使用 HTML、CSS 和 JavaScript 编写应用程序代码。建议使用模块化的代码结构和框架（如 React、Vue.js 等）。
1. 在代码中添加必要的 Web App Manifest 和 Service Worker。Web App Manifest 是一个 JSON 文件，包含应用程序的元数据，如名称、图标、颜色、起始页 URL 等。Service Worker 是一个 JavaScript 文件，用于缓存应用程序的静态资源并提供离线访问功能。
1. 部署应用程序到 Web 服务器上，并确保它是通过 HTTPS 协议访问的，以确保应用程序的安全性和信任度。
1. 在浏览器中访问应用程序，添加到主屏幕，并测试其功能和性能。

总之，编写 PWA 应用需要了解 Web 技术和 PWA 的相关规范，同时使用现代的开发工具和框架可以帮助开发人员更加高效地开发 PWA 应用。

## Sample

附上修改简化后的“W3开放网”的PWA的manifest.json

```json
{
    "name": "W3开放网",
    "short_name": "W3开放网",
    "start_url": "/?source=pwa",
    "display": "standalone",
    "scope": "/",
    "background_color": "#fff",
    "homepage": "http://127.0.0.1:5500/",
    "icons": [
        {
          "src": "https://www.w3dev.cn/images/48x48.png",
          "type": "image/png",
          "sizes": "48x48"
        },
        {
          "src": "https://www.w3dev.cn/images/96x96.png",
          "type": "image/png",
          "sizes": "96x96"
        },
        {
          "src": "https://www.w3dev.cn/images/144x144.png",
          "type": "image/png",
          "sizes": "144x144"
        },
        {
          "src": "https://www.w3dev.cn//images/192x192.png",
          "type": "image/png",
          "sizes": "192x192"
        }
    ]
}
```

> 原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/03/17/Other-PWA-ProgressiveWebApp-Introduction/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129629012](https://letmefly.blog.csdn.net/article/details/129629012)
