<!--
 * @Author: LetMeFly
 * @Date: 2024-12-10 23:34:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-15 16:13:43
-->
# 目的

判断一个Github是否公开，并返回svg。

# 使用方法

/github/public/?user={Github用户名}&repo={仓库名}

# 使用示例

```
https://api.letmefly.xyz/github/public/?user=LetMeFly666&repo=LeetCode
```

## 实际使用列表

+ [SecFFT论文彩蛋](https://web.letmefly.xyz/%E8%AE%A1%E7%AE%97%E6%9C%BACode/paperChocolate/)

# 结果

返回该仓库是否公开的文字SVG。

+ 若为公开，则返回`Public`
+ 若为私有，则返回`Private`
+ 若不存在，也返回`Private`
