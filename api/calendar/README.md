<!--
 * @Author: LetMeFly
 * @Date: 2024-12-15 16:10:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-18 12:34:14
-->
# 目的

像Mac日历一样，可以标记每天几点到几点都干了什么，可以加Tag，可以进行统计。

# 使用方法



# 使用示例

```

```

# 结果

# TODO

+ [ ] 删除标签时，前端提醒“所有任务的xx标签将会被移除”

# End

## Chat with GPT

<details><summary>点我展开每次的询问</summary>

你了解Mac日历吗

<hr/>

如果我想让ChatGPT帮我使用cloudflare workers创建一个类似Mac日历的应用，我应该怎么告诉它，以使得它能一步一步完成整个项目？

<hr/>

"我需要帮助使用Cloudflare Workers构建一个日历应用（类似Mac日历），支持以下功能：

+ 后端通过Cloudflare Workers实现事件的创建、获取、删除功能，并使用Cloudflare KV存储数据。
+ 前端使用HTML、CSS和JavaScript来显示日历，并支持用户创建、查看、编辑事件。这些前端的文件也是由同一个Cloudflare workers项目返回的。
+ 支持设置事件提醒，并通过浏览器通知提醒用户。
+ 提供API接口：POST /events（创建事件），GET /events（获取事件列表），DELETE /events/{id}（删除事件）。"
+ 支持对事件加Tag，支持分类汇总功能。

完成这个项目需要较大的工作量，请你分步骤逐步完成。

<hr/>

现在我创建好了cloudflare应用，并成功显示了Hello, Cloudflare Workers!

下一步我想编写代码，使得cloudflare返回html页面。

<hr/>

这个页面能够由js读取HTML来实现吗？我不知道cloudflare workers是否允许这么做

<hr/>

我希望将HTML和JavaScript分开，我应该如何部署静态文件？可以在一个项目中实现吗

<hr/>

对于前端页面进行如下修改：

+ 设置默认语言为中文
+ 在head部分引入js：https://letmefly.xyz/Links/Common.js
+ 缩进为4个空格（js文件也是如此）

<hr/>

前端显示成功！请继续

<hr/>

介绍http delete，说明其传参方式

能否像post和get一样传参，而不是通过url的子路径传参

<hr/>

现在我决定不使用KV来存储数据，而是使用D1数据库存储数据。

<hr/>

我在绑定D1数据库的时候，出现了以下报错：

D1 bindings require module-format workers. https://developers.cloudflare.com/workers/reference/migrate-to-module-workers/

<hr/>

TOML写注释

<hr/>

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

<hr/>

我有一个D1数据库：

```sql
CREATE TABLE Users (
    userid INTEGER PRIMARY KEY AUTOINCREMENT, 
    username VARCHAR(255) UNIQUE NOT NULL, 
    password VARCHAR(255) NOT NULL
);

CREATE TABLE User_LoginInfo (
    login_id INTEGER PRIMARY KEY AUTOINCREMENT,
    userid INTEGER NOT NULL,
    loginTime DATETIME NOT NULL,
    loginIp VARCHAR(50),
    passKey VARCHAR(255) NOT NULL,
    FOREIGN KEY (userid) REFERENCES Users(userid)
);
```

我要依据cookie中的passKey去User_LoginInfo中获取userid以便得知是哪个用户创建的任务。

用户只能操作自己创建的任务。

请你对其进行修改。

<hr/>

使用JS往当前域名下创建一个永不过期的cookie，名为passKey，值为123

<hr/>

我想要的主要是日历效果，主要是想记录今天已经完成的一件事情。

<hr/>

我想要的主要是日历效果，主要是想记录今天已经完成的一件事情。

请你不要着急，记住我所提出的所有要求，一步一步来完成。

下面首先设计并创建数据库。

<hr/>

我想要的主要是日历效果，主要是想记录今天已经完成的一件事情。例如我今天学了20分钟Java，我就可以在网页上记录一下，以便后续统计。

请你不要着急，记住我所提出的所有要求，一步一步来完成。

下面首先设计并创建数据库。

我已经创建了Users表、User_LoginInfo表，接下来准备创建Calendar_Tasks表和Calendar_Tags表。

Calendar_Tags表中包含：tagId、tagName、tagColor(十六进制的RGB值)

Calendar_Tasks表中包含：taskId、title、description、startTime(任务开始时间)、during(任务持续时长)、tagId、userid等。

<hr/>

很棒，接下来开始写后端的事件创建、新增、删除函数。

<hr/>

我有一个TagId数据表，现在要设计一个Tasks数据表。

一个Task可以对应多个TagId，Task中还会包含其他信息如taskId、description等。

我应该怎么设计Task表格？

<hr/>

解释这段sql代码

<hr/>

还有一种办法是在Task表中添加一个tags键。

两种解决方案哪个更合适？

<hr/>

我决定使用TaskTag表这种方式。

我有没有必要创建一个taskTag_Id这个键？

<hr/>

我想要的主要是日历效果，主要是想记录今天已经完成的一件事情。例如我今天学了20分钟Java，我就可以在网页上记录一下，以便后续统计。

请你不要着急，记住我所提出的所有要求，一步一步来完成。

下面首先设计并创建数据库。

我已经创建了Users表、User_LoginInfo表，接下来准备创建Calendar_Tasks表、Calendar_Tags表和Calendar_TaskTag表。

Calendar_Tags表中包含：tagId、tagName、tagColor(十六进制的RGB值)

Calendar_Tasks表中包含：taskId、title、description、startTime(任务开始时间)、during(任务持续时长)、userid等。

Calendar_TaskTag表中包含：taskId、TagId。一个任务可能对应着多个标签。

<hr/>

很棒，接下来开始写后端的事件创建、新增、删除函数。

<hr/>

重写一下添加标签的这段代码，每个标签插入一次是不是太低效了？

<hr/>

删除任务的时候，能否直接`DELETE FROM Calendar_Tasks WHERE taskId = ? AND userid = ?;`？

这样在userid和taskid不匹配的时候就会删除失败。

如果是这样，我又应该如何判断是否删除失败了？

<hr/>

现在我写完了后端的 查询、修改、删除 任务的函数，我想先写一个Python脚本模拟发包分别测试一下。

<hr/>

介绍HTTP DELETE

<hr/>

它可以将数据保留在请求体当中吗

<hr/>

```
...
```

现在我写完了后端的 查询、修改、删除 任务的函数，我想先写一个Python脚本模拟发包分别测试一下。

你不需要修改我写的函数，你只需要写一个使用python requests库的脚本，以便我可以运行测试。

<hr/>

```
...
```

现在我写完了后端的 查询、修改、删除 任务的函数，我想先写一个Python脚本模拟发包分别测试一下。

虽然deleteEvent函数可能不是很合适，但是你暂时不需要修改或继续完善它。

你的任务是：写一个python脚本，以便我可以用来测试这三个后端api。

<hr/>

不，现在你不需要修改我的代码

我需要修改代码的时候我会告诉你的。

你只需要完成一件事情，明白吗？

就是写一个python脚本，向后端发送模拟数据包，以便能测试这三个api是否可以正常工作。

<hr/>

```
...
```

现在我写完了后端的 查询、修改、删除 任务的函数，我想先写一个Python脚本模拟发包分别测试一下。

虽然deleteEvent函数可能不是很合适，但是你暂时不需要修改或继续完善它。

你的任务是：写一个python脚本，以便我可以用来测试这三个后端api。

请注意，现在你不需要修改我的代码

我需要修改代码的时候我会告诉你的。

你只需要完成一件事情，明白吗？

就是写一个python脚本，向后端发送模拟数据包，以便能测试这三个api是否可以正常工作。

我不希望继续处理事件删除的功能，你可以理解我这个功能已经完成了。

现在你不要帮我完善其中的删除任务功能，你要做的是写python代码。

<hr/>

我不希望在URL中确定DELETE函数的taskID，我就要不规范地在请求体中传递taskID这个参数。

本次回复中，你只能返回python代码，用python的requests库发送模拟请求，测试后端的三个api

<hr/>

<hr/>

<hr/>

<hr/>

</details>