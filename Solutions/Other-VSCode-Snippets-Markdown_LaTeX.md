---
title: 在VsCode markdown的公式中快速插入⌊分数⌋等代码段
title_en: Insert Floor Fractions Quickly in LaTeX Formulas with Markdown Snippets
date: 2026-07-26 18:05:08
tags: [VsCode]
categories: [技术思考]
index_img: https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/589548de8ba9436390bb8d524b14068b.gif
---

# 在VsCode markdown的公式中快速插入⌊分数⌋等代码段

## 背景

在markdown中写题解的时候经常会需要在LaTeX公式中输入类似`$\lfloor\frac{x}{2}\rfloor$`这样的代码，但是(对于坚持手写题解的*大佬*来说)这一长串手打起来还挺慢的。好在VsCode支持*代码片段*，在特定文件输入特定前缀可以插入指定代码，并且还能自定义光标位置、按tab切到下一个光标位置。

**分享这种操作的文章不是很多么？这篇文章的意义是什么？**

笔者在N年前就在VsCode上配置了一些cpp的代码段，这两天突然想起了配置markdown的代码段，结果发现需要解决以下问题才能配置成功：

+ markdown默认没有补全提示
+ markdown中即使配置了代码段，也无法在输入了`$`后的公式中补全
+ 大模型也无法直接给出这个问题的准确答案

先来个最终效果：

![向下取整：$x=\lfloor\frac{n\times n(n+1)}{2}\rfloor$](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/589548de8ba9436390bb8d524b14068b.gif)

VsCode中输入`分数`的拼音`fenshu`可以插入`\lfloor\frac{}{2}\rfloor`代码段，光标默认定位到分子，按tab键定位到分母，分母默认是$2$，再按Tab键定位到向下取整分数的结尾。

## 设置

### 新增代码段

`Cmd/Ctrl + Shift + P -> Snippets: Configure Snippets -> 新建全局代码片段文件`

注意(01)，一定要新建**全局**代码片段文件，不可以只选中markdown文件类型。因为输入 `⌊分数⌋` 的时候都是在markdown的公式中输入的，如果你新建一个关于markdown文件的代码段，很抱歉，你输入了`$`并开始输入`fenshu`的时候，诶，VsCode认为你在输入LaTeX，不给你弹代码段哈哈。

如果你想限制代码段的生效范围是`markdown`和`LaTeX`，可以在全局代码段文件中新增`"scope": "markdown,latex"`配置（如果你选中markdown代码段的话，是不支持scope字段的）。

删掉默认的字符，把下面的字符粘贴进去（并保存）：

```json
{
	"LaTeX Floor Fraction": {
		"scope": "markdown,latex",
        "prefix": "fenshu",
        "body": [
            "\\\\lfloor\\\\frac{$1}{${2:2}}\\\\rfloor"
        ],
        "description": "LaTeX中分数并向下取整"
    },
}
```

注意(02)这里面`\`的转义，`\frac`要写成`\\\\frac`，因为：

+ JSON 解析一次：`\\\\` → `\\`
+ snippet 插入时：`\\` → `\`

### 开启markdown文件的自动补全

不知道你的VsCode默认配置是怎样的，设置好上面的代码段后，你可能迫不及待地在markdown中尝试，但是发现怎么都触发不了自动补全提示。

#### 插件

这可能是因为你的VsCode对于markdown文件的补全建议默认是关闭的。这可能是插件所致(03)，测试方式是`Cmd/Ctrl + Shift + P -> Developer: Reload with Extensions Disabled`，看下是否会自动补全。(大概率会)如果还不能自动补全，说明不是插件所致。

置于关闭*不含插件的重新启动*的方式不用担心，你关闭插件并重启后，右下角会有一个很明显的提示，说这次启动禁用了所有插件，点击按钮正常重新加载VsCode。

#### 配置

你可以通过在`settings.json`中新增如下配置来实现VS Code针对markdown的补全建议(04)：

```json
    "[markdown]": {  // 不然markdown没有补全
        "editor.quickSuggestions": {
            // 官方文档中只找到了这三个控制粒度，其中other必须设置为true
            "other": true,
            // "comments": true,
            // "strings": true,
        },
    },
```

这个`settings.json`打开方式是`Cmd/Ctrl + Shift + P -> Preferences: Open User Settings (JSON)`。

至此，你就可以愉快地使用了。

> 其他公式(原理类似)，以后再来探索吧。

# End

+ 本文中一共出现了01、02、03、04这4个注意事项：

    + 01: 要使用全局代码段而非指定语言代码段
    + 02: 代码段中`\frac`要写成`\\\\frac`
    + 03: 可以在临时禁用拓展的情况下看看效果
    + 04: 在设置中打开对markdown的补全建议

+ [VsCode Snippets 文档](https://code.visualstudio.com/docs/editing/userdefinedsnippets)
+ [VsCode 中 `editor.quickSuggestions` 配置相关文档](https://code.visualstudio.com/docs/editing/intellisense#_settings)

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163218874)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/26/Other-Git-CustomMergingScriptOther-VSCode-Snippets-Markdown_LaTeX/)哦~
> 
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
