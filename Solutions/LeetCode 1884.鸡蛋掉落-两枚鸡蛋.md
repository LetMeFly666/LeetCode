---
title: 1884.鸡蛋掉落-两枚鸡蛋
date: 2024-10-13 23:58:53
tags: [题解, LeetCode, 中等, 数学, 动态规划, DP, 趣]
---

# 【LetMeFly】1884.鸡蛋掉落-两枚鸡蛋：动态规划

力扣题目链接：[https://leetcode.cn/problems/egg-drop-with-2-eggs-and-n-floors/](https://leetcode.cn/problems/egg-drop-with-2-eggs-and-n-floors/)

<p>给你 <strong>2&nbsp;枚相同 </strong>的鸡蛋，和一栋从第 <code>1</code>&nbsp;层到第 <code>n</code> 层共有 <code>n</code> 层楼的建筑。</p>

<p>已知存在楼层 <code>f</code> ，满足&nbsp;<code>0 &lt;= f &lt;= n</code> ，任何从 <strong>高于 </strong><code>f</code> 的楼层落下的鸡蛋都<strong> 会碎 </strong>，从 <strong><code>f</code> 楼层或比它低 </strong>的楼层落下的鸡蛋都 <strong>不会碎 </strong>。</p>

<p>每次操作，你可以取一枚<strong> 没有碎</strong> 的鸡蛋并把它从任一楼层 <code>x</code> 扔下（满足&nbsp;<code>1 &lt;= x &lt;= n</code>）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中<strong> 重复使用 </strong>这枚鸡蛋。</p>

<p>请你计算并返回要确定 <code>f</code> <strong>确切的值 </strong>的 <strong>最小操作次数</strong> 是多少？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>2
<strong>解释：</strong>我们可以将第一枚鸡蛋从 1 楼扔下，然后将第二枚从 2 楼扔下。
如果第一枚鸡蛋碎了，可知 f = 0；
如果第二枚鸡蛋碎了，但第一枚没碎，可知 f = 1；
否则，当两个鸡蛋都没碎时，可知 f = 2。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 100
<strong>输出：</strong>14
<strong>解释：
</strong>一种最优的策略是：
- 将第一枚鸡蛋从 9 楼扔下。如果碎了，那么 f 在 0 和 8 之间。将第二枚从 1 楼扔下，然后每扔一次上一层楼，在 8 次内找到 f 。总操作次数 = 1 + 8 = 9 。
- 如果第一枚鸡蛋没有碎，那么再把第一枚鸡蛋从 22 层扔下。如果碎了，那么 f 在 9 和 21 之间。将第二枚鸡蛋从 10 楼扔下，然后每扔一次上一层楼，在 12 次内找到 f 。总操作次数 = 2 + 12 = 14 。
- 如果第一枚鸡蛋没有再次碎掉，则按照类似的方法从 34, 45, 55, 64, 72, 79, 85, 90, 94, 97, 99 和 100 楼分别扔下第一枚鸡蛋。
不管结果如何，最多需要扔 14 次来确定 f 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


    
## 解题方法：动态规划

使用`dp[i]`表示`i`层的建筑使用两枚鸡蛋最少的确定次数。初始值`dp[0] = 0`，其余`dp[i] = ∞`。

为了计算`dp[i]`，我们第一枚鸡蛋可以从楼层`j`开始尝试：

+ 若鸡蛋碎了，说明答案在`[1, j - 1]`，并且只剩一枚鸡蛋了，必须从`1`楼开始尝试到`j - 1`楼，所需次数为`1 + (j - 1) = j`；
+ 若鸡蛋没碎，`[1, j - 1]`层直接排除了，对于剩下的`i - j`层，方法和`1`到`i - j`层相同，所需次数为`1 + (dp[i - j])`。

也就是说，第一枚鸡蛋从`j`层开始尝试的话，所需总次数为(一定可以测出安全楼层)`max(j, 1 + dp[i - j])`。

所有`j`中，所需次数最小的那个，即为`dp[i]`的值。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, 100000);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = min(dp[i], max(j, dp[i - j] + 1));
            }
        }
        return dp.back();
    }
};
```

#### Go

```go
package main

func twoEggDrop(n int) int {
    dp := make([]int, n + 1)
    for i := range(dp) {
        dp[i] = 10000
    }
    dp[0] = 0
    for i := 1; i <= n; i++ {
        for j := 1; j <= i; j++ {
            dp[i] = min(dp[i], max(j, dp[i - j] + 1))
        }
    }
    return dp[n]
}
```

#### Java

```java
import java.util.Arrays;

class Solution {
    public int twoEggDrop(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 10000);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = Math.min(dp[i], Math.max(j, dp[i - j] + 1));
            }
        }
        return dp[n];
    }
}
```

#### Python

```python
class Solution:
    def twoEggDrop(self, n: int) -> int:
        dp = [0] + [10000] * n
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                dp[i] = min(dp[i], max(j, dp[i - j] + 1))
        return dp[-1]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/13/LeetCode%201884.%E9%B8%A1%E8%9B%8B%E6%8E%89%E8%90%BD-%E4%B8%A4%E6%9E%9A%E9%B8%A1%E8%9B%8B/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142906976](https://letmefly.blog.csdn.net/article/details/142906976)
