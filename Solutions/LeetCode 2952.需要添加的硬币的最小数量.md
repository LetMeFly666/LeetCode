---
title: 2952.需要添加的硬币的最小数量
date: 2024-03-30 22:33:10
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序]
---

# 【LetMeFly】2952.需要添加的硬币的最小数量：贪心（排序）

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-coins-to-be-added/](https://leetcode.cn/problems/minimum-number-of-coins-to-be-added/)

<p>给你一个下标从 <strong>0 </strong>开始的整数数组 <code>coins</code>，表示可用的硬币的面值，以及一个整数 <code>target</code> 。</p>

<p>如果存在某个 <code>coins</code> 的子序列总和为 <code>x</code>，那么整数 <code>x</code> 就是一个 <strong>可取得的金额 </strong>。</p>

<p>返回需要添加到数组中的<strong> 任意面值 </strong>硬币的 <strong>最小数量 </strong>，使范围 <code>[1, target]</code> 内的每个整数都属于 <strong>可取得的金额</strong> 。</p>

<p>数组的 <strong>子序列</strong> 是通过删除原始数组的一些（<strong>可能不删除</strong>）元素而形成的新的 <strong>非空</strong> 数组，删除过程不会改变剩余元素的相对位置。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>coins = [1,4,10], target = 19
<strong>输出：</strong>2
<strong>解释：</strong>需要添加面值为 2 和 8 的硬币各一枚，得到硬币数组 [1,2,4,8,10] 。
可以证明从 1 到 19 的所有整数都可由数组中的硬币组合得到，且需要添加到数组中的硬币数目最小为 2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>coins = [1,4,10,5,7,19], target = 19
<strong>输出：</strong>1
<strong>解释：</strong>只需要添加一枚面值为 2 的硬币，得到硬币数组 [1,2,4,5,7,10,19] 。
可以证明从 1 到 19 的所有整数都可由数组中的硬币组合得到，且需要添加到数组中的硬币数目最小为 1 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>coins = [1,1,1], target = 20
<strong>输出：</strong>3
<strong>解释：</strong>
需要添加面值为 4 、8 和 16 的硬币各一枚，得到硬币数组 [1,1,1,4,8,16] 。 
可以证明从 1 到 20 的所有整数都可由数组中的硬币组合得到，且需要添加到数组中的硬币数目最小为 3 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins[i] &lt;= target</code></li>
</ul>


    
## 解题方法：排序 + 贪心

二话不说先对```coins```数组从小到大排个序。使用变量```to```记录当前能组成到几（初始值为0）。遍历```coins```数组：

+ 如果```coins[i] <= to + 1```，那么```coins[i]```就可以“拼接上”，原本可以组成的数据范围```[1, 2, ..., to]```加上```coins[i]```后就可以组成范围```[1, 2, ..., to + coins[i]]```。因此，更新```to```为```to + coins[i]```；
+ 否则（```coins[i] > to + 1```）无法“拼接”，必须添加新的硬币。既然无法组成```to + 1```，那么必须要添加硬币```to + 1```。添加后便能组成到```to + to + 1```。

直到```to >= target```为止。

+ 时间复杂度$O(coins\log coins + \log target)$（最多新增硬币```\log target```次）
+ 空间复杂度$O(\log coins)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0, to = 0, i = 0;
        while (to < target) {
            if (i < coins.size() && coins[i] <= to + 1) {
                to += coins[i];
                i++;
            }
            else {
                to += to + 1;
                ans++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        coins.sort()
        to, ans, i = 0, 0, 0
        while to < target:
            if i < len(coins) and coins[i] <= to + 1:
                to += coins[i]
                i += 1
            else:
                to += to + 1
                ans += 1
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/30/LeetCode%202952.%E9%9C%80%E8%A6%81%E6%B7%BB%E5%8A%A0%E7%9A%84%E7%A1%AC%E5%B8%81%E7%9A%84%E6%9C%80%E5%B0%8F%E6%95%B0%E9%87%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137185903](https://letmefly.blog.csdn.net/article/details/137185903)
