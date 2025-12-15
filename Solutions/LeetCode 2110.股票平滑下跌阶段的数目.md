---
title: 2110.股票平滑下跌阶段的数目：数学（一次遍历）
date: 2025-12-15 21:43:30
tags: [题解, LeetCode, 中等, 数组, 数学, 动态规划]
categories: [题解, LeetCode]
---

# 【LetMeFly】2110.股票平滑下跌阶段的数目：数学（一次遍历）

力扣题目链接：[https://leetcode.cn/problems/number-of-smooth-descent-periods-of-a-stock/](https://leetcode.cn/problems/number-of-smooth-descent-periods-of-a-stock/)

<p>给你一个整数数组&nbsp;<code>prices</code>&nbsp;，表示一支股票的历史每日股价，其中&nbsp;<code>prices[i]</code>&nbsp;是这支股票第&nbsp;<code>i</code>&nbsp;天的价格。</p>

<p>一个 <strong>平滑下降的阶段</strong>&nbsp;定义为：对于&nbsp;<strong>连续一天或者多天</strong>&nbsp;，每日股价都比 <strong>前一日股价恰好少 </strong><code>1</code>&nbsp;，这个阶段第一天的股价没有限制。</p>

<p>请你返回 <strong>平滑下降阶段</strong>&nbsp;的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>prices = [3,2,1,4]
<b>输出：</b>7
<b>解释：</b>总共有 7 个平滑下降阶段：
[3], [2], [1], [4], [3,2], [2,1] 和 [3,2,1]
注意，仅一天按照定义也是平滑下降阶段。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>prices = [8,6,7,7]
<b>输出：</b>4
<b>解释：</b>总共有 4 个连续平滑下降阶段：[8], [6], [7] 和 [7]
由于 8 - 6 ≠ 1 ，所以 [8,6] 不是平滑下降阶段。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>prices = [1]
<b>输出：</b>1
<b>解释：</b>总共有 1 个平滑下降阶段：[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：遍历

假设有$3$个`连续下滑天`$[3, 2, 1]$，那么可以有$3, 2, 1$（连续3天共1种）、$3, 2$、$2, 1$（连续2天共2种）、$3$、$2$、$1$（连续1天共3种）这共计$1+2+3=\frac{3(3+1)}{2}=6$种`平滑下降阶段`。

同样的，$n$个`连续下滑天`就有$\frac{n(n+1)}2$种`平滑下降阶段`。

因此，我们只需要遍历一遍，看下原始数组中有多少`连续下滑天`，并将每个连续下滑天的`平滑下降阶段`种类数求和即可。

### 具体做法

具体而言，可以使用两个变量：$last$和$cnt$分别记录上一天的价格和当前`连续下滑天`，遇到`连续下滑天`中断的情况就计算一次$ans$，最后返回前也计算一次$ans$。

### 时空复杂度

+ 时间复杂度$O(len(prices))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-15 18:52:23
 */
typedef long long ll;
class Solution {
public:
    ll getDescentPeriods(vector<int>& prices) {
        ll ans = 0, cnt = 0;
        int last = 0;
        for (int t : prices) {
            if (t != last - 1) {
                ans += cnt * (cnt + 1) / 2;
                // printf("t = %d, cnt = %lld\n", t, cnt);
                cnt = 0;
            }
            last = t;
            cnt++;
        }
        return ans + cnt * (cnt + 1) / 2;
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-12-15 18:54:39
'''
from typing import List

class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        ans = last = cnt = 0
        for p in prices:
            if p != last - 1:
                ans += cnt * (cnt + 1) // 2
                cnt = 0
            cnt += 1
            last = p
        return ans + cnt * (cnt + 1) // 2

```

#### Java

```java
/*
 * @LastEditTime: 2025-12-15 21:37:22
 */
class Solution {
    public long getDescentPeriods(int[] prices) {
        long ans = 0, cnt = 0;
        for (int last = 0, i = 0; i <= prices.length; i++) {
            if (i == prices.length || prices[i] != last - 1) {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
            cnt++;
            if (i < prices.length) {
                last = prices[i];
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-12-15 21:35:08
 */
package main

func getDescentPeriods(prices []int) (ans int64) {
    var cnt int64
    last := 0
    for i := 0; i <= len(prices); i++ {
        if i == len(prices) || prices[i] != last - 1 {
            ans += cnt * (cnt + 1) / 2
            cnt = 0
        }
        cnt++
        if i < len(prices) {
            last = prices[i]
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-12-15 21:41:17
 */
impl Solution {
    pub fn get_descent_periods(prices: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut cnt: i64 = 0;
        let mut last: i32 = 0;
        for p in prices {  // 一借不还
            if p != last - 1 {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
            cnt += 1;
            last = p;
        }
        ans + cnt * (cnt + 1) / 2
    }
}
```

## End

<span title="2025.12.15">今天跌得可不轻啊</span>

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/155951986)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/15/LeetCode%202110.%E8%82%A1%E7%A5%A8%E5%B9%B3%E6%BB%91%E4%B8%8B%E8%B7%8C%E9%98%B6%E6%AE%B5%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
