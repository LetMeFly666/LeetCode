---
title: Cloudflare workers - 如何使用（起步篇）
date: 2024-12-09 13:45:04
tags: [其他, Cloudflare]
categories: [技术思考]
---

# Cloudflare workers - 如何使用（起步篇）

Cloudflare Workers 是一种基于 JavaScript 的无服务器计算平台，允许你在 Cloudflare 的边缘网络上运行代码，而无需管理传统的服务器基础设施。它能在全球范围内的 Cloudflare 数据中心上执行代码，以提供快速、低延迟的服务。

## 安装wrangler并登录

1. 安装`wrangler`

    1. 确保机器上安装了[Node.js](https://nodejs.org/zh-cn)
    2. 使用`npm`安装`wrangler`：
      
        ```bash
        npm install -g wrangler
        ```

        或者使用`yarn`安装：

        ```bash
        yarn global add wrangler
        ```

2. 登录Cloudflare账号

    1. 执行命令：

        ```bash
        wrangler login
        ```
    
    2. 在弹出的浏览器窗口中登录Cloudflare账户（这里可能需要一下特殊网络环境）

    3. 如果你使用`powershell`运行且提示：

        ```
        wrangler : 无法加载文件 F:\OtherApps\Program\Node\node-v16.13.1-win-x64\wrangler.ps1，因为在此系统上禁止运行脚本。有关详细信息，请参阅 https:/go.microsoft.com/fwlink/?LinkID=135170 中的 about_Execution_Policies。
        所在位置 行:1 字符: 1
        + wrangler
        + ~~~~~~~~
            + CategoryInfo          : SecurityError: (:) []，PSSecurityException
            + FullyQualifiedErrorId : UnauthorizedAccess
        ```

        那么可以使用如下命令允许本地脚本运行，并要求从互联网下载的脚本必须有有效的签名：

        ```powershell
        Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
        ```

        如果希望恢复禁止所有脚本运行，可以使用如下命令恢复：

        ```powershell
        Set-ExecutionPolicy Restricted -Scope CurrentUser
        ```


## 创建Cloudflare workers应用

### 方式一 - 创建（v3及之前可用）

1. 创建Worker项目

    创建一个名为`api`的项目：

    ```bash
    wrangler generate api
    ```

    这将会在当前目录下生成一个`api`文件夹，文件中中包含一个`wrangler.toml`文件：

    ```toml
    name = "api"
    compatibility_date = "2024-12-09"
    ```

2. 编写Worker代码

    在生成的`api`文件夹下，创建`index.js`文件并写入以下内容：

    ```javascript
    addEventListener('fetch', event => {
        event.respondWith(handleRequest(event.request))
    })

    async function handleRequest(request) {
        return new Response('Hello, world!', {
            headers: { 'content-type': 'text/plain' },
        })
    }
    ```

    编辑`wrangler.toml`，添加如下一行（设置入口点为`index.js`）

    ```toml
    main = "index.js"
    ```

### 方式二

## 测试开发部署

3. 开发和测试

    使用以下命令在本地开发和测试：

    ```bash
    cd api
    wrangler dev
    ```

    如果出现以下报错，请安装[vc_redist](https://learn.microsoft.com/zh-cn/cpp/windows/latest-supported-vc-redist)最新版

    ```
    X [ERROR] There was an access violation in the runtime.

    On Windows, this may be caused by an outdated Microsoft Visual C++ Redistributable library.
    Check that you have the latest version installed.
    See https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist.



    X [ERROR] The Workers runtime failed to start. There is likely additional logging output above.
    ```

    如果想在本地开发时直接使用生产环境中的D1数据库(Cloudflare D1)，则需要`wrangler dev --remote`

6. 部署到Cloudflare

    ```bash
    wrangler deploy
    ```

7. 拉取代码到本地

    如果在Cloudflare dashboard（网页端）对内容进行了修改，可执行以下命令将内容拉取到本地：

    ```
    emm，似乎只能手动复制文件的到本地。。
    ```

<!-- 参考django设计一个简单的worker框架，要求：

1. 每个模块是一个子文件夹，子文件夹中可以实现相关的各种功能
2. main.js中可以导入不同的模块，每个模块对应一个子URL
3. 每个模块中有一个url.js，对应这个子模块中的各种功能。

例如：

其中一个模块是`img`，main.js中导入`img`模块，并设置子URL`img`对应模块`img`。
`img`模块中，有两个`url`：

1. `a.png`显示`svg hello world`
2. `svg`显示`svg nihao`

最终效果：

1. 访问`/img/a.png`显示`a.png`
2. 访问`/img/svg`显示`svg` -->


<!-- 进行如下修改：

1. 我想要设计的是一个框架，在`main.js`中或`img/url.js`中如果使用过多的`if-else`则将会不便于开发，最好参考django写一个列表 -->

<!-- 很棒，进行如下修复：

`const routeHandler = moduleRoutes[path.replace(modulePath, '')]`这段代码中，如果url地址中还有下一级子路径，则会匹配失败。修改为path.replace().第一级url -->

<!-- 不是的。`const nowPath = path.replace(modulePath, '');`，我想获取nowPath的第一级路径 -->

<!-- 介绍js的URL -->

<!-- event.request 中都有哪些内容 -->

<!-- event.request.url可以修改吗？ -->

  <!-- const newRequest = new Request(newUrl, {
    method: event.request.method,
    headers: event.request.headers,
    body: event.request.body,
  });
  这样的话会不会有一些参数/内容没有被复制 -->

<!-- 我不知道都有哪些属性在后续可能被用到，我想复制除了Url之外的所有属性 -->

<!-- 手机通过Wifi连接到校园网，电脑A通过数据线连接手机共享的网络，电脑B也连接到校园网。
已知校园网是一个大局域网，直接连接到其中的设备可以相互访问。
那么，电脑A和电脑B之间在同一个局域网中吗？可以相互访问吗？ -->

<!-- 如果电脑B通过手机的无线热点接入网络， -->

<!-- /github/public?user=LetMeFly666&repo=LeetCode  从event.request中提取参数user和repo -->

<!-- const user = url.searchParams.get('user');
const repo = url.searchParams.get('repo');
这两行有没有语法糖之类的更简单的写法 -->

<!-- 简单的SVG代码，返回文字Hello World，不需要任何格式 -->

<!-- 不指定画布大小，不指定文字大小 -->

<!-- 这样在浏览器中看到的是xml，而不是svg -->

<!-- <svg xmlns="http://www.w3.org/2000/svg">
    <text x="50%" y="50%" fill="black">${text}</text>
</svg>
这样就能被正确解析为svg，不需要额外的HTML代码 -->

<!-- 我需要你返回一个不带有任何格式的svg源码，显示文字Hello World。
我给你的svg中带有x=50%和y=50%样式，这不是我想要的。 -->

<!-- 这样文字就看不到了 -->

<!-- 这个y=20是如何确定的 -->

<!-- 限制一下svg高度，正好为文字大小 -->

<!-- 设置svg的宽度为文字总宽度。使用js完成计算 -->

<!-- 我使用的是node环境，可能无法使用document对象 -->

<!-- X [ERROR] Build failed with 1 error:

  X [ERROR] Could not resolve "canvas"

      github/public/utils/calculateWidth.js:7:33:
        7 │ const { createCanvas } = require('canvas');
          ╵                                  ~~~~~~~~

    You can mark the path "canvas" as external to exclude it from the bundle, which will remove this
  error. You can also surround this "require" call with a try/catch block to handle this failure at
  run-time instead of bundle-time. -->

<!-- 能否不使用第三方库 -->

<!-- 你还是粗略估计吧。
放心，所有文字都是英文 -->

# End

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2024/12/09/Other-CloudflareWorkers-How2use/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144488128](https://letmefly.blog.csdn.net/article/details/144488128)
