---
title: 日积月累 - 一些小知识 - 杂乱 - 啥都有
date: 2023-10-19 20:13:39
tags: [其他, 小杂, 知识, 中等, Github]
---

# 日积月累 - 一些小知识 - 杂乱 - 啥都有

这里准备放一些日积月累的小知识，但是相比于[日积月累 - 一些小知识](https://blog.letmefly.xyz/2023/02/21/Other-Accumulation-SomeTips/)而言，本文更加随意（杂乱）。

## Github 在issue中引用代码的代码段

方法：在Github的[代码页](https://github.com/LetMeFly666/LeetCode/blob/master/newSolution.py)，点击其中一行的数字，按住shift，再点击零一行的数字，会发现这几行有了背景色。点一下上面那行左边的“三个点的按钮”，点击```Reference in new issue```，即可在新的issue页面获取所引用代码的[链接](https://github.com/LetMeFly666/LeetCode/blob/9c603112d33f885842b37bd368267063d7a5fe3b/newSolution.py#L132-L139)。

效果：[Github@LetMeFly666/LeetCode/issue#32](https://github.com/LetMeFly666/LeetCode/issues/32)

## 轻量级Flask搭建小Web服务

```python
from flask import send_file, Flask

app = Flask('1')

@app.route('/file/')
def download_file():
    return send_file(r'C:\Users\LetMeFly\Desktop\image.png', 'a.png', as_attachment=True)


@app.route('/')
def hello_world():
    return 'Hello World!'

print(app.url_map)
app.run(host='0.0.0.0', port='80', debug=True)
```

这样，访问```ip/file/```时就会开始下载文件，访问```ip/```时会看到```Hello World!```

## C++ auto&&

```cpp
queue<pair<int, int>> q;
auto&& [x, y] = q.front();
q.pop();
```

其中```q.pop()```将会导致```x```和```y```的值失效！ 详情可见一个De了1个多小时的BUG：[7d4f27d](https://github.com/LetMeFly666/LeetCode/commit/7d4f27da29d30e4d7a38fd91b34dbff9af52d154)

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/19/Other-Accumulation-Messy)哦~
> [https://blog.letmefly.xyz/2023/10/19/Other-Accumulation-Messy](https://blog.letmefly.xyz/2023/10/19/Other-Accumulation-Messy)