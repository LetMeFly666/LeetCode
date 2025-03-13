---
title: Python - Django - 合并两个django项目，将一个项目作为另一个项目的子项目
date: 2023-04-19 16:52:59
tags: [其他, Python, Django]
categories: [技术思考]
---

# Python - Django - 合并两个django项目，将一个项目作为另一个项目的子项目

## 前言

我开发了一个小项目，是BUCT的学生访客申请的后端，叫LetVisit；我校有一个已有的项目，是平安校园管理系统，叫ZJSystem。

LetVisit已经基本开发好且测试好了，但是突然要把LetVisit整合到ZJSystem中。怎么办？重构？太麻烦了。

于是我就想有没有一个较好的合并两个django项目的方法，发现基本上没有。跟着为数不多的文章尝试也失败了。

最后，借助ChatGPT的帮助，成功合并了两个项目，特将方法记录如下。

## How

平安校园的目录结构为：

```
ZJSystem
    ZJSystem
        urls.py
        settings.py
        ...
    manage.py
```

访客申请后端的目录结构为：

```
LetVisit
    LetVisit
        urls.py
        settings.py
        ...
    manage.py
```

现在将**LetVisit作为ZJSystem的一个APP并合并到ZJSystem中**。

首先，将```LetVisit```整个文件夹移动到```ZJsystem/ZJSystem```下：

```
ZJSystem
    ZJSystem
        LetVisit
            LetVisit
                urls.py
                settings.py
                ...
            manage.py
        urls.py
        settings.py
        ...
    manage.py
```

然后，将```LetVisit```修改为一个APP。怎么做呢？只需要在```ZJSystem/ZJSystem/LetVisit/LetVisit/urls.py```中添加一段代码：

```python
app_name = 'LetVisit'
```

然后在```ZJSystem```中使用这个APP。怎么做呢？需要在```ZJSystem/ZJSystem/settings.py```的```INSTALLED_APPS```中，加上```LetVisit```

```python
INSTALLED_APPS = [
    ...
    'LetVisit'
]
```

最后，我们需要做的就是：将访问```LetVisit```的请求转发给```LetVisit```这个APP处理。这里，我们可以选择**将所有以LetVisit开头的请求转交给LetVisit这个APP**。怎么做呢？我们只需要在```ZJSystem/ZJSystem/urls.py```中添加一行```path('LetVisit/', include('LetVisit.urls', namespace='LetVisit'))```

```python
urlpatterns = [
    ...
    path('LetVisit/', include('LetVisit.urls', namespace='LetVisit'))
]
```

这样，所有的以```LetVisit/```开头的请求都会转交给```LetVisit```这个APP来处理啦！

先别着急，运行一下试试：

```bash
cd ZJSystem
python manage.py runserver
```

咦？发现```LetVisit```这个APP报错了：

```
    from LetVisit import a
ModuleNotFoundError: No module named 'LetVisit'
```

这是因为，在单独的LetVisit项目中，```LetVisit/manage.py```和```LetVisit/LetVisit```是同级的，因此自然能找到LetVisit这个“包”。但是LetVisit作为ZJSystem的子项目后，运行的是```ZJSystem/manage.py```，找不到```ZJSystem/ZJSystem/LetVisit/LetVisit```。

怎么办呢？也不难，把LetVisit添加到Python执行路径的环境中就好了。在```ZJSystem/ZJSystem/settings.py```中，添加：

```python
import sys
PROJECT_ROOT = os.path.dirname(os.path.abspath(__file__))
PathToAdd = os.path.join(PROJECT_ROOT, 'LetVisit/')
sys.path.insert(0, PathToAdd)
```

这样执行```ZJSystem```时，就能找到```LetVisit```了。

大功告成。

## More

注意，这时候所有对LetVisit的请求的URL都要以```LetVisit```开头，可能会与原始的地址不匹配，注意修改一下。

相当于对于整个项目ZJSystem来说，```127.0.0.1:8000/LetVisit/HelloWord```会被转发给LetVisit，但是对于LetVisit来说，它所匹配的URL是```HelloWorld```，而不是```LetVisit/HelloWorld```。

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/19/Other-Python-Django-Merge2DjangoProject/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130248202](https://letmefly.blog.csdn.net/article/details/130248202)
