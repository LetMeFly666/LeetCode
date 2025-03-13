---
title: HTML - 使用Python快速生成HTML的UI
date: 2023-04-04 19:43:13
tags: [其他, HTML, Python, 前端]
categories: [技术思考]
---

# HTML - 使用Python快速生成HTML的UI

## 前言

今日HJL给我分享了一个项目：[https://github.com/gradio-app/gradio](https://github.com/gradio-app/gradio)（中文文档点[这里](https://github.com/gradio-app/gradio/blob/main/readme_files/zh-cn#readme)）

这个项目使用起来很简单，只需要安装一下```gradio```：

```bash
pip install gradio
```

就可以使用了。

## 样例

```python
import gradio as gr

def greet(name):
    return "Hello " + name + "!"

demo = gr.Interface(fn=greet, inputs="text", outputs="text")
    
demo.launch()
```

之后运行这个Py文件，打开```http://localhost:7860/```，就能看到页面了！

页面中主要有两个框，左边是输入框，可以输入一个名字。输入完成点击```Submit```后可以在右边看到输出的：```Hello {name}!```，并且还能自适应手机端和电脑端。

更高级的操作可以查看Readme。

> 原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/04/Other-HTML-AutoGenerateHTMLByPython/)哦~
> 原文链接：[https://blog.letmefly.xyz/2023/04/04/Other-HTML-AutoGenerateHTMLByPython/](https://blog.letmefly.xyz/2023/04/04/Other-HTML-AutoGenerateHTMLByPython/)