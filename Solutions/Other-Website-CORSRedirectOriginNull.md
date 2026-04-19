---
title: CORS 跨域重定向后 Origin 变 null —— 一次 Nginx 字体加载失败的排查记录
title_en: "CORS Cross-Origin Redirect Makes Origin Null - An Nginx Font Loading Debug Story"
date: 2026-04-19 15:24:00
tags: [其他, Nginx, CORS, Web]
categories: [技术思考, AI]
---

> AI创作声明：以下内容由大模型总结自我与大模型的对话。

# CORS 跨域重定向后 Origin 变 null —— 一次 Nginx 字体加载失败的排查记录

## 现象

博客 `blog.letmefly.xyz` 页面加载 MathJax 数学公式字体，前端引用地址是 `https://letmefly.xyz/Links/JS/MathJax/.../MathJax_Zero.woff`。Nginx 会将 `letmefly.xyz` 的请求 302 重定向到 `web.letmefly.xyz`。浏览器控制台报出 CORS 错误：

```
Access to font at 'https://web.letmefly.xyz/...' (redirected from 'https://letmefly.xyz/...')
from origin 'https://blog.letmefly.xyz' has been blocked by CORS policy:
No 'Access-Control-Allow-Origin' header is present on the requested resource.
```

## 排查过程

### 第一步：确认 Nginx CORS 配置

Nginx 使用全局 `map` 变量做 CORS 白名单：

```nginx
map $http_origin $corsHost {
    default "";
    "~https://blog.letmefly.xyz" https://blog.letmefly.xyz;
    # ...其他域名
}
```

各 server 块通过 `add_header Access-Control-Allow-Origin $corsHost;` 输出 CORS 头。看起来没问题。

### 第二步：curl 验证最终目标

直接带 Origin 请求 `web.letmefly.xyz`：

```bash
curl -I -H "Origin: https://blog.letmefly.xyz" \
  https://web.letmefly.xyz/Links/JS/MathJax/output/chtml/fonts/woff-v2/MathJax_Zero.woff
```

返回了 `access-control-allow-origin: https://blog.letmefly.xyz`，完全正确。

### 第三步：curl 验证重定向源

```bash
curl -I -H "Origin: https://blog.letmefly.xyz" \
  https://letmefly.xyz/Links/JS/MathJax/output/chtml/fonts/woff-v2/MathJax_Zero.woff
```

302 响应也带了正确的 `access-control-allow-origin: https://blog.letmefly.xyz`。

两端 curl 都正确，但浏览器就是报错。这说明**浏览器实际发出的请求和 curl 模拟的不一样**。

### 第四步：根因定位——Origin 变成了 null

综合以上线索：curl 手动带 Origin 请求没问题，但浏览器报错。说明浏览器跟随 302 重定向后，发到 `web.letmefly.xyz` 的请求里 **Origin 不是 `https://blog.letmefly.xyz`**。那它变成了什么？答案是字符串 `"null"`。

## 根因：WHATWG Fetch 规范的 tainted origin flag

这不是浏览器 bug，而是 **WHATWG Fetch 规范**明确要求的行为。

规范定义了 **tainted origin flag**（被污染的源标记）机制：

- [Fetch 规范 Section 4.5 HTTP-redirect fetch](https://fetch.spec.whatwg.org/#http-redirect-fetch) 第 10 步：如果重定向目标 URL 的 origin 与请求当前 URL 的 origin **不同**，且请求的 origin 与当前 URL 的 origin 也**不同**，则设置请求的 tainted origin flag。
- [Serializing a request origin](https://fetch.spec.whatwg.org/#serializing-a-request-origin) 算法：如果请求的 tainted origin flag 已设置，则返回字符串 `"null"`。

翻译成人话：**当一个 CORS 请求经历了跨域重定向（重定向前后的 origin 不同），浏览器会把后续请求的 `Origin` 头设为字符串 `"null"`。**

在这个案例中，请求链是：

```
blog.letmefly.xyz  →(fetch)→  letmefly.xyz  →(302)→  web.letmefly.xyz
     origin                    host A                    host B
```

`letmefly.xyz` → `web.letmefly.xyz` 是跨域重定向，触发 tainted origin flag。浏览器向 `web.letmefly.xyz` 发送的请求中 `Origin: null`。Nginx 的 `map $http_origin` 匹配不到 `null`，走了 default `""`，不输出 CORS 头，浏览器拦截。

**为什么规范要这样设计？** 出于隐私和安全保护。举个例子：假设你在 `trusted-bank.com` 的页面上，页面向 `api.trusted-bank.com` 发了一个带 Cookie 的请求。如果 `api.trusted-bank.com` 被攻击者控制（或攻击者通过 DNS 劫持把请求引到了 `evil.com`），而浏览器仍然把 `Origin: https://trusted-bank.com` 原封不动地传过去，那么 `evil.com` 收到这个请求后就能冒充来自 `trusted-bank.com` 的合法请求——这就是[混淆代理攻击（confused deputy attack）](https://en.wikipedia.org/wiki/Confused_deputy_problem)。浏览器把跨域重定向后的 Origin 设为 `null`，就是为了切断这条信任链：重定向目标不应该自动继承原始请求的可信身份。

## 各浏览器实现情况

| 浏览器 | 行为 | 参考 |
|---|---|---|
| Chrome | 跨域重定向后 `Origin: null` | Chromium Issue 154967 |
| Firefox | 跨域重定向后 `Origin: null` | [Bug 1444278](https://bugzilla.mozilla.org/show_bug.cgi?id=1444278)（2018 年修复对齐规范） |
| Safari | 跨域重定向后 `Origin: null` | 同规范行为 |

所有现代浏览器都遵循这一规范行为。Firefox 的 Bug 1444278 记录了完整的修复过程：之前 Firefox 在跨域重定向后仍然发送原始 Origin（与 Chrome/Safari 不一致），后来修复为发送 `"null"` 以对齐 WHATWG Fetch 规范。规范维护者 annevk 在该 bug 中确认：「Once we cross origin boundaries the request's origin is supposed to become a unique opaque identifier (which serializes to null).」

## 解决方案

**最佳方案（推荐）**：在前端直接引用最终地址 `https://web.letmefly.xyz/...`，避免经过 `letmefly.xyz` 的重定向，根本不触发 tainted origin flag。

**备选方案一**：在 `web.letmefly.xyz` 的 Nginx 配置中，对字体文件用 `*` 通配符：

```nginx
location ~* \.(woff|woff2|ttf|eot|otf)$ {
    add_header Access-Control-Allow-Origin "*" always;
}
```

字体文件本身不涉及敏感数据，用 `*` 通配是安全的。

**备选方案二**：在 map 中加一条匹配 `null` 的规则：

```nginx
map $http_origin $corsHost {
    default "";
    "null" "https://blog.letmefly.xyz";
    "~https://blog.letmefly.xyz" https://blog.letmefly.xyz;
    # ...
}
```

但这样做安全性稍差——任何 Origin 为 null 的请求都会被放行为 `blog.letmefly.xyz`。

## 排查过程中踩的另一个坑：Nginx add_header 继承陷阱

排查过程中还踩了一个坑：在 `web.letmefly.xyz` 的 server 块级别加了 `add_header Access-Control-Allow-Origin $corsHost;`，但不生效。

原因涉及 Nginx `add_header` 的继承机制。根据[官方文档](https://nginx.org/en/docs/http/ngx_http_headers_module.html#add_header)的描述：

> These directives are inherited from the previous configuration level **if and only if** there are no `add_header` directives defined on the current level.

也就是说，`add_header` **默认是会继承上层的**，但一旦当前层级（如 `location`）里出现了**任何一条** `add_header`，上层（`server`/`http`）的 `add_header` 就**全部失效**——不是合并，而是完全替换。

以 `web.letmefly.xyz` 的配置为例，假设原本有这样的结构：

```nginx
server {
    server_name web.letmefly.xyz;
    add_header Access-Control-Allow-Origin $corsHost always;  # ← server 级别

    location / {
        # 这个 location 里没有任何 add_header → 会继承 server 级别的 CORS 头 ✓
        try_files $uri $uri/ =404;
    }

    location /api {
        add_header X-Frame-Options SAMEORIGIN;  # ← 一旦出现这条
        # server 级别的 add_header 全部失效，CORS 头丢失 ✗
    }
}
```

解决办法是把 CORS 头直接加到每个含有 `add_header` 的 location 块里。可以用 `include` 抽成公共片段避免重复：

```nginx
# /etc/nginx/snippets/cors.conf
add_header Access-Control-Allow-Origin $corsHost always;
```

然后在每个需要 CORS 头的 location 中引入：

```nginx
server {
    server_name web.letmefly.xyz;
> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160310109)和我的[个人博客](https://blog.letmefly.xyz/)，(AI)创作不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/19/Other-Website-CORSRedirectOriginNull/)哦~
    root /srv/web/website;

    location / {
        include /etc/nginx/snippets/cors.conf;
        try_files $uri $uri/ =404;
    }

    location /api {
        include /etc/nginx/snippets/cors.conf;
        add_header X-Frame-Options SAMEORIGIN;
        proxy_pass http://backend;
    }

    location ~* \.(woff|woff2|ttf|eot|otf)$ {
        include /etc/nginx/snippets/cors.conf;
        expires 30d;
    }
}
```

这样即使某个 location 有自己的 `add_header`，CORS 头也不会丢失。

> **补充**：Nginx 1.29.3 新增了 `add_header_inherit merge;` 指令，可以让子级别在保留自己 `add_header` 的同时继承上层的 `add_header`，但目前大多数生产环境的 Nginx 版本尚未支持。

---

*写完这篇文章后才发现，最好的排查方式是一开始就在浏览器 DevTools 的 Network 面板里查看重定向后实际发出的请求头……不过绕了一圈学到的东西更多（大概吧）。*

> 同步发文于我的[个人博客](https://blog.letmefly.xyz/)，(AI)创作不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/19/Other-Website-CORSRedirectOriginNull/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
