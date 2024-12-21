<!--
 * @Author: LetMeFly
 * @Date: 2024-12-20 22:12:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 23:01:23
-->
# calendar后端

## 文件描述

+ `temp`文件夹：存放一些临时的东西（以后可能很少再用到的东西），例如创建数据表的sql语句等。
+ `test`文件夹：后端测试文件夹。用来发包测试后端工作是否符合预期。
+ `cookie.js`：`中间件`，解析cookie用。
+ `event.js`：事件函数，添加、查看、删除事件。
+ `README.md`：此文件，用于描述项目后端。
+ `user.js`：`中间件`，依据请求获取用户id。

## 接口文档

### 创建事件 POST {BASE_URL}/events

**请求头**

+ Cookie: passKey=用户登录凭证

**请求体**

```json
{
    'title': '开发',
    'description': 'LetCalendar开发',
    'startTime': '2024-12-20T10:00:00',
    'during': 60,  # 任务持续时长，单位为分钟
    'tags': [1, 2]
}
```

**返回值**

创建成功(200)：

```json
{
    success: 'ok',
    taskId: 1
}
```

用户身份不合法(401)：

```
Invalid passKey
```

创建失败(500)：

```
Failed to create task
```

**请求示例**

[代码段1](https://github.com/LetMeFly666/LeetCode/blob/13f2ff1c5d0cc82e198fcd175a1e8cc6c8fceea6/api/calendar/back/test/testBackEvent.py#L7-L33) + [代码段2](https://github.com/LetMeFly666/LeetCode/blob/13f2ff1c5d0cc82e198fcd175a1e8cc6c8fceea6/api/calendar/back/test/testBackEvent.py#L52)

### 查询事件 GET {BASE_URL}/events

**请求头**

+ Cookie: passKey=用户登录凭证

**请求体**

None。 TODO: 起止时间

**返回值**

查询成功(200)：

```json
[{"taskId":1,"title":"开发","description":"Let Calendar开发","startTime":"2024-12-17T10:00:00","during":60,"userid":1},{"taskId":13,"title":"开发","description":"LetCalendar开发","startTime":"2024-12-20T10:00:00","during":60,"userid":1}]
```

用户身份不合法(401)：

```
Invalid passKey
```

**请求示例**

[代码段1](https://github.com/LetMeFly666/LeetCode/blob/13f2ff1c5d0cc82e198fcd175a1e8cc6c8fceea6/api/calendar/back/test/testBackEvent.py#L7-L19) + [代码段2](https://github.com/LetMeFly666/LeetCode/blob/13f2ff1c5d0cc82e198fcd175a1e8cc6c8fceea6/api/calendar/back/test/testBackEvent.py#L36-L39) + [代码段3](https://github.com/LetMeFly666/LeetCode/blob/13f2ff1c5d0cc82e198fcd175a1e8cc6c8fceea6/api/calendar/back/test/testBackEvent.py#L55)

### 删除事件 DELETE  {BASE_URL}/events

**请求头**

+ Cookie: passKey=用户登录凭证

**请求体**

虽然这么写似乎有点不太标准，但为了后端的统一性还是先这样写了。

```json
{
    'taskId': 12
}
```

**返回值**

删除成功(200)：

```
Task ${taskId} deleted successfully.
```

用户身份不合法(401)：

```
Invalid passKey
```

删除失败(404) - taskId不存在或该task非操作者所有会导致：

```
Access Denied!
```

**请求示例**

[代码段1](https://github.com/LetMeFly666/LeetCode/blob/13f2ff1c5d0cc82e198fcd175a1e8cc6c8fceea6/api/calendar/back/test/testBackEvent.py#L7-L19) + [代码段2](https://github.com/LetMeFly666/LeetCode/blob/13f2ff1c5d0cc82e198fcd175a1e8cc6c8fceea6/api/calendar/back/test/testBackEvent.py#L42-L49) + [代码段3](https://github.com/LetMeFly666/LeetCode/blob/13f2ff1c5d0cc82e198fcd175a1e8cc6c8fceea6/api/calendar/back/test/testBackEvent.py#L58-L59)