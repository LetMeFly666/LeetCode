---
title: 2209.用地毯覆盖后的最少白色砖块：记忆化搜索之——深度优先搜索(DFS)
date: 2025-02-21 14:41:47
tags: [题解, LeetCode, 困难, 字符串, 深度优先搜索, DFS]
---

# 【LetMeFly】2209.用地毯覆盖后的最少白色砖块：记忆化搜索之——深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets/](https://leetcode.cn/problems/minimum-white-tiles-after-covering-with-carpets/)

<p>给你一个下标从<strong>&nbsp;0</strong>&nbsp;开始的 <strong>二进制</strong>&nbsp;字符串&nbsp;<code>floor</code>&nbsp;，它表示地板上砖块的颜色。</p>

<ul>
	<li><code>floor[i] = '0'</code>&nbsp;表示地板上第&nbsp;<code>i</code>&nbsp;块砖块的颜色是 <strong>黑色</strong>&nbsp;。</li>
	<li><code>floor[i] = '1'</code>&nbsp;表示地板上第&nbsp;<code>i</code>&nbsp;块砖块的颜色是 <strong>白色</strong>&nbsp;。</li>
</ul>

<p>同时给你&nbsp;<code>numCarpets</code> 和&nbsp;<code>carpetLen</code>&nbsp;。你有&nbsp;<code>numCarpets</code>&nbsp;条&nbsp;<strong>黑色</strong>&nbsp;的地毯，每一条&nbsp;<strong>黑色</strong>&nbsp;的地毯长度都为&nbsp;<code>carpetLen</code>&nbsp;块砖块。请你使用这些地毯去覆盖砖块，使得未被覆盖的剩余 <strong>白色</strong>&nbsp;砖块的数目 <strong>最小</strong>&nbsp;。地毯相互之间可以覆盖。</p>

<p>请你返回没被覆盖的白色砖块的 <strong>最少</strong>&nbsp;数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/02/10/ex1-1.png" style="width: 400px; height: 73px;"></p>

<pre><b>输入：</b>floor = "10110101", numCarpets = 2, carpetLen = 2
<b>输出：</b>2
<b>解释：</b>
上图展示了剩余 2 块白色砖块的方案。
没有其他方案可以使未被覆盖的白色砖块少于 2 块。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/02/10/ex2.png" style="width: 353px; height: 123px;"></p>

<pre><b>输入：</b>floor = "11111", numCarpets = 2, carpetLen = 3
<b>输出：</b>0
<b>解释：</b>
上图展示了所有白色砖块都被覆盖的一种方案。
注意，地毯相互之间可以覆盖。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= carpetLen &lt;= floor.length &lt;= 1000</code></li>
	<li><code>floor[i]</code> 要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code>&nbsp;。</li>
	<li><code>1 &lt;= numCarpets &lt;= 1000</code></li>
</ul>


    
## 解题方法：深度优先搜索(DFS)

写一个函数`dfs(n, index)`，代表使用`n`块地毯从下标`index`开始往后覆盖剩余的最小白色砖块数。

+ 如果不覆盖当前砖块：

    `dfs(n, index + 1) + (floor[index] == '1')`

    1. 可以使用`n`块地毯覆盖后续砖块，最少有`dfs(n, index + 1)`块白砖不能覆盖
    2. 如果这块砖是白色，则未覆盖白砖数量加一

+ 如果覆盖当前砖块：

    `dfs(n - 1, index + 地毯长度)`

    1. 可以使用`n - 1`块地毯覆盖从`index + 地毯长度`开始的砖块

终止条件：当前地毯能覆盖剩下所有砖块。

然后，再使用一个缓存记忆化一下就好了。

+ 时间复杂度$O(numCarpets\times len(floor))$
+ 空间复杂度$O(numCarpets\times len(floor))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-21 12:25:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-21 13:05:12
 */
class Solution {
private:
    unordered_map<int, int> cache;
    string floor;
    int perLen;

    int dfs(int n, int startIndex) {
        int code = n * 1000 + startIndex;
        if (cache.count(code)) {
            return cache[code];
        }
        if (n * perLen >= floor.size() - startIndex) {
            return cache[code] = 0;
        }
        int ans = dfs(n, startIndex + 1) + (floor[startIndex] == '1');  // 不覆盖
        if (n) {
            ans = min(ans, dfs(n - 1, startIndex + perLen));  // 覆盖
        }
        return cache[code] = ans;
    }
public:
    int minimumWhiteTiles(string& floor, int numCarpets, int carpetLen) {
        this->floor = move(floor);
        this->perLen = carpetLen;
        return dfs(numCarpets, 0);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-21 13:05:56
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-21 13:11:13
'''
from functools import cache


class Solution:
    @cache
    def dfs(self, n: int, startIndex: int) -> int:
        if n * self.perLen >= len(self.floor) - startIndex:
            return 0
        ans = self.dfs(n, startIndex + 1) + (self.floor[startIndex] == '1')
        if n:
            ans = min(ans, self.dfs(n - 1, startIndex + self.perLen))
        return ans
    
    def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
        self.floor = floor
        self.perLen = carpetLen
        return self.dfs(numCarpets, 0)

```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-21 13:05:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-21 14:39:29
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    private String floor;
    private int perLen;
    private Map<Integer, Integer> cache = new HashMap<>();

    private int dfs(int n, int index) {
        int code = n * 1000 + index;
        if (cache.containsKey(code)) {
            return cache.get(code);
        }
        if (n * perLen >= floor.length() - index) {
            cache.put(code, 0);
            return 0;
        }
        int ans = dfs(n, index + 1);
        if (floor.charAt(index) == '1') {
            ans++;
        }
        if (n > 0) {
            ans = Math.min(ans, dfs(n - 1, index + perLen));
        }
        cache.put(code, ans);
        return ans;
    }

    public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
        this.floor = floor;
        perLen = carpetLen;
        return dfs(numCarpets, 0);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-21 13:06:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-21 14:21:55
 */
package main

func dfs_MWTACWC(n, startIndex int, floor string, perLen int, cache map[int]int) (ans int) {
    code := n * 1000 + startIndex
    ans, ok := cache[code]
    if ok {
        return
    }
    if n * perLen >= len(floor) - startIndex {
        cache[code] = 0
        return 0
    }
    ans = dfs_MWTACWC(n, startIndex + 1, floor, perLen, cache)
    if floor[startIndex] == '1' {
        ans++
    }
    if n > 0 {
        ans = min(ans, dfs_MWTACWC(n - 1, startIndex + perLen, floor, perLen, cache))
    }
    cache[code] = ans
    return
}

func minimumWhiteTiles(floor string, numCarpets int, carpetLen int) int {
    return dfs_MWTACWC(numCarpets, 0, floor, carpetLen, map[int]int{})
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145777611)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/21/LeetCode%202209.%E7%94%A8%E5%9C%B0%E6%AF%AF%E8%A6%86%E7%9B%96%E5%90%8E%E7%9A%84%E6%9C%80%E5%B0%91%E7%99%BD%E8%89%B2%E7%A0%96%E5%9D%97/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
