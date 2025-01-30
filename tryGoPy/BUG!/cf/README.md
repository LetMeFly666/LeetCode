<!--
 * @Author: LetMeFly
 * @Date: 2025-01-09 16:21:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-09 16:43:42
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

bug初次提交：[`63679be9996e5b13b9b7d7d88396b95646019e2f`](https://github.com/LetMeFly666/LeetCode/commit/63679be9996e5b13b9b7d7d88396b95646019e2f)；[files](https://github.com/LetMeFly666/LeetCode/commit/63679be9996e5b13b9b7d7d88396b95646019e2f)；[Github@cloudflare/workers-sdk](https://github.com/cloudflare/workers-sdk/)。

---

现在，我将wrangler版本升级为了` ⛅️ wrangler 3.100.0`，该BUG仍然存在。另，我的node版本为`v16.13.1`。

准备先简化一下POC再专门创建一个cf workers项目试试。至于项目，就先缝补一下让他能运行吧。
