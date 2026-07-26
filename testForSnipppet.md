<!--
 * @Author: LetMeFly
 * @Date: 2026-07-26 16:31:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-07-26 17:00:18
-->


我新增了

```json
    "[markdown]": {  // 不然markdown没有补全
        "editor.quickSuggestions": {
            "other": true,
            "comments": true,
            "strings": true,
        },
    },
```

可以了，但是问题是这东西不在$$中间补全

一旦我开始输入了 `$`，似乎就进入了公示模式，然后这些代码段补全就失效了，正好我想在这里面自动补全。。

\lfloor\frac{1}{2}\rfloor

\lfloor\frac{}{2\rfloor

$fenshu fenshu $

\lfloor\frac{}{2}\rfloor    

$ \lfloor\frac{}{2}\rfloor  $

nihao

fenshu

$ fenshu $

\lfloor\frac{}{}\rfloor

1. first
2. second
3. third
\lfloor\frac{}{}\rfloor
$ fenshu   lfloor \lfloor  $

# 

## 思路 # \lfloor\frac{}{}\rfloor

## 思路


## 代码
```cpp

```


## 代码
```cpp

```