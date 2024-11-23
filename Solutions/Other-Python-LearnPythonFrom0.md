---
title: Python - 从0开始学Python(Python3)
date: 2024-11-22 23:03:48
tags: [其他, Python]
---

# Python - 从0开始学Python(Python3)

Python作为一门“胶水语言”，(很多领域的人都)值得一学。

<p class="LetMeFly_ToCute">仅以此篇，献给某可爱的人。</p>

<!-- HTML写一个JS函数：我有一个`<p class="LetMeFly_ToCute">仅以此篇，献给某可爱的人。</p>`，使用JS将其变成可爱的色彩（颜色随时间变化，整体偏浅粉） -->
<!-- 颜色过于突兀了，设置渐变，彩虹色，后面文字到前面文字过渡 -->
<!-- 需要会动的粉色渐变，颜色从后往前移动 -->
<!-- 这个颜色挺好看的，但是不会动 -->

<!-- 我有这么一段HTML`<p class="LetMeFly_ToCute">仅以此篇，献给某可爱的人。</p>`，请写一个JS函数，2秒内点击这个p标签8次及以上的话，打开一个新页面。 -->
<!-- 写到一个文件里 -->

## Day1 - Python安装、Python原理、Python一些基础概念、Python基础数据类型、Python函数的简单调用

<span id="day1"></span>

### Python安装

这里说的很不详细（因为不是重点(bushi)），若失败也可以网上搜搜。

+ Windows: [官网](https://www.python.org/downloads/windows/)下载安装包`xx Windows installer xx`，一路安装。
+ MacOS: [下载地址](https://www.python.org/downloads/macos/)
+ Linux: 自带？（但是可能需要输入`Python3`命令）命令是什么？[下一部分](#python原理)就会介绍。

### Python原理

经常有人问我：

> 我用的VsCode的Python；我用的PyCharm的Python；...

这里先不说conda那些，不管用的啥`编辑器(IDE)`都无所谓，本质上都是`python 文件 参数`。

不信我们新建一个文件`a.py`并输入`print('Hello World!')`保存，打开终端：

> + Windows: `Win + R` - `cmd` - `回车`
> + MacOS: `command + space`打开搜索 - `terminal` - `回车`
> + Linux: 都Linux了还问我终端是啥

然后输入**命令**并回车：

```bash
python a.py的路径C:\Desktop\a.py
```

就能看到`Hello World!`了。和在`VsCode`或`PyCharm`等等之类的里面运行完全没有区别。

本质上就是Python解释器接收一个参数，参数是文件路径，然后Python就去一行一行地解释(运行)这个文件。

如果你编写的Python文件能够处理参数，那么就可以在`python a.py`后面加上任意的参数了。

### Python一些基础概念

很多编程语言都是这样，有“常量”、“变量”、“函数”、“参数”等等很多名称。这些还是记一记吧，方便和其他程序员交流。但是不用怕，很容易记住的。

对于如下代码：

```python
a = 1      # Line 1
b = 2      # Line 2
a = a + b  # Line 3
print(a)   # Line 4
```

其中`a`和`b`就是变量，`print`是函数，第4行的`a`是函数`print`的参数。

### Python基础数据类型

## Dayn - 操作符重载

# End

<style name="LetMeFly_ToCute">
    .LetMeFly_ToCute {
        font-size: 24px;
        font-weight: bold;
        background: linear-gradient(to left, #FFB6C1, #FFC0CB, #FFD1DC, #FFE4E1); /* 粉色渐变 */
        -webkit-background-clip: text;
        background-clip: text;   /* 还定义标准属性“background-clip”以实现兼容性css(vendorPrefix) */
        color: transparent;
        display: inline-block; /* 确保渐变效果应用于整个元素 */
        animation: pinkGradientMove 5s linear infinite;
    }

    @keyframes pinkGradientMove {
        0% {
            background-position: 100% 50%;
        }
        100% {
            background-position: 0% 50%;
        }
    }
</style>

<script name="LetMeFly_ToCute">
    document.addEventListener('DOMContentLoaded', function() {
        const pElement = document.querySelector('.LetMeFly_ToCute');
        let clickCount = 0;
        const targetClicks = 5;
        const timeLimit = 1000; // 1秒
        let startTime = Date.now();

        // 添加点击事件监听器
        function handleClick() {
            const currentTime = Date.now();
            if (currentTime - startTime <= timeLimit) {
                clickCount++;
                if (clickCount == targetClicks) {
                    openNewPage();
                    clickCount = 0;
                }
            } else {
                // 如果时间超过限制，重置计数器和开始时间
                clickCount = 1; // 重置计数器
                startTime = currentTime; // 重置开始时间
            }
        }

        pElement.addEventListener('click', handleClick);

        function openNewPage() {
            window.open('https://letmefly.xyz/He0/shykeke/WeCan/', '_blank');
        }
    });
</script>

<center><font size="6px" face="Ink Free">The End, thanks!</font></center>

> 原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/22/Other-Python-LearnPythonFrom0/)哦~
> [https://blog.letmefly.xyz/2024/11/22/Other-Python-LearnPythonFrom0/](https://blog.letmefly.xyz/2024/11/22/Other-Python-LearnPythonFrom0/)
