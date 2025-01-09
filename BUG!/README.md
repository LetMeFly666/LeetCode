<!--
 * @Author: LetMeFly
 * @Date: 2025-01-09 16:21:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-09 16:24:16
-->
使用`wrangler deploy`时，发现其把

```js
a = `1'\n'2`
```

渲染为了：

```js
a = `1'
'2`
```

我的wrangler版本为` ⛅️ wrangler 3.99.0 (update available 3.100.0)`

准备待会儿更新一下最新版本试试。