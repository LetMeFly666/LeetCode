<!--
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:10:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-15 18:29:01
-->
# 目的

像Mac日历一样，可以标记每天几点到几点都干了什么，可以加Tag，可以进行统计。

# 使用方法



# 使用示例

```

```

# 结果

# End

## Chat with GPT

<details><summary>点我展开每次的询问</summary>

你了解Mac日历吗

<hr/>

如果我想让ChatGPT帮我使用cloudflare workers创建一个类似Mac日历的应用，我应该怎么告诉它，以使得它能一步一步完成整个项目？

<br/>

"我需要帮助使用Cloudflare Workers构建一个日历应用（类似Mac日历），支持以下功能：

+ 后端通过Cloudflare Workers实现事件的创建、获取、删除功能，并使用Cloudflare KV存储数据。
+ 前端使用HTML、CSS和JavaScript来显示日历，并支持用户创建、查看、编辑事件。这些前端的文件也是由同一个Cloudflare workers项目返回的。
+ 支持设置事件提醒，并通过浏览器通知提醒用户。
+ 提供API接口：POST /events（创建事件），GET /events（获取事件列表），DELETE /events/{id}（删除事件）。"
+ 支持对事件加Tag，支持分类汇总功能。

完成这个项目需要较大的工作量，请你分步骤逐步完成。

<br/>

现在我创建好了cloudflare应用，并成功显示了Hello, Cloudflare Workers!

下一步我想编写代码，使得cloudflare返回html页面。

<br/>

这个页面能够由js读取HTML来实现吗？我不知道cloudflare workers是否允许这么做

<br/>

我希望将HTML和JavaScript分开，我应该如何部署静态文件？可以在一个项目中实现吗

<br/>

对于前端页面进行如下修改：

+ 设置默认语言为中文
+ 在head部分引入js：https://letmefly.xyz/Links/Common.js
+ 缩进为4个空格（js文件也是如此）

<br/>

前端显示成功！请继续

<br/>

介绍http delete，说明其传参方式

能否像post和get一样传参，而不是通过url的子路径传参

<br/>

现在我决定不使用KV来存储数据，而是使用D1数据库存储数据。

<br/>

我在绑定D1数据库的时候，出现了以下报错：

D1 bindings require module-format workers. https://developers.cloudflare.com/workers/reference/migrate-to-module-workers/

<br/>

TOML写注释

<br/>

```
name = "api"
type = "module"  # 绑定D1数据库的Workers要求必须为模块格式而不能是脚本格式
compatibility_date = "2024-12-09"
main = "main.js"

d1_databases = [
  { binding = "api", database_id = "40bf17b1-b598-4ad2-aad0-860f2b282cee" }
]
```

报错：

```

 ⛅️ wrangler 3.93.0 (update available 3.95.0)
-------------------------------------------------------

▲ [WARNING] Processing wrangler.toml configuration:

    - 😶 Ignored: "type":
      Most common features now work out of the box with wrangler, including modules, jsx,
  typescript, etc. If you need anything more, use a custom build.


▲ [WARNING] You are about to publish a Workers Service that was last published via the Cloudflare Dashboard.

  Edits that have been made via the dashboard will be overridden by your local code and config.


√ Would you like to continue? ... yes
Total Upload: 5.56 KiB / gzip: 1.92 KiB
Your worker has access to the following bindings:
- D1 Databases:
  - api: 40bf17b1-b598-4ad2-aad0-860f2b282cee

X [ERROR] A request to the Cloudflare API (/accounts/870d2550dd021f035ec8dd56e29f7472/workers/scripts/api) failed.

  D1 bindings require module-format workers.
  https://developers.cloudflare.com/workers/reference/migrate-to-module-workers/ [code: 10021]

  If you think this is a bug, please open an issue at:
  https://github.com/cloudflare/workers-sdk/issues/new/choose
```

<br/>

<br/>

<br/>

<br/>

<br/>

<br/>

<br/>

<br/>

<br/>

<br/>

<br/>

<br/>

</details>