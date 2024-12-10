# 目的

判断一个Github是否公开。

# 使用方法

/github/public/?user={Github用户名}&repo={仓库名}

# 使用示例

```
https://api.letmefly.xyz/github/public/?user=LetMeFly666&repo=LeetCode
```

# 结果

返回该仓库是否公开的文字SVG。

+ 若为公开，则返回`Public`
+ 若为私有，则返回`Private`
+ 若不存在，也返回`Private`
