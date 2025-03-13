---
title: 638.大礼包
date: 2024-11-03 15:14:25
tags: [题解, LeetCode, 中等, 位运算, 记忆化搜索, 数组, 动态规划, 回溯, 状态压缩, 深度优先搜索, DFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】638.大礼包：记忆化搜索（无脑尝试每种可能就好了）DFS

力扣题目链接：[https://leetcode.cn/problems/shopping-offers/](https://leetcode.cn/problems/shopping-offers/)

<p>在 LeetCode 商店中， 有 <code>n</code> 件在售的物品。每件物品都有对应的价格。然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品。</p>

<p>给你一个整数数组 <code>price</code> 表示物品价格，其中 <code>price[i]</code> 是第 <code>i</code> 件物品的价格。另有一个整数数组 <code>needs</code> 表示购物清单，其中 <code>needs[i]</code> 是需要购买第 <code>i</code> 件物品的数量。</p>

<p>还有一个数组 <code>special</code> 表示大礼包，<code>special[i]</code> 的长度为 <code>n + 1</code> ，其中 <code>special[i][j]</code> 表示第 <code>i</code> 个大礼包中内含第 <code>j</code> 件物品的数量，且 <code>special[i][n]</code> （也就是数组中的最后一个整数）为第 <code>i</code> 个大礼包的价格。</p>

<p>返回<strong> 确切 </strong>满足购物清单所需花费的最低价格，你可以充分利用大礼包的优惠活动。你不能购买超出购物清单指定数量的物品，即使那样会降低整体价格。任意大礼包可无限次购买。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
<strong>输出：</strong>14
<strong>解释：</strong>有 A 和 B 两种物品，价格分别为 ¥2 和 ¥5 。 
大礼包 1 ，你可以以 ¥5 的价格购买 3A 和 0B 。 
大礼包 2 ，你可以以 ¥10 的价格购买 1A 和 2B 。 
需要购买 3 个 A 和 2 个 B ， 所以付 ¥10 购买 1A 和 2B（大礼包 2），以及 ¥4 购买 2A 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
<strong>输出：</strong>11
<strong>解释：</strong>A ，B ，C 的价格分别为 ¥2 ，¥3 ，¥4 。
可以用 ¥4 购买 1A 和 1B ，也可以用 ¥9 购买 2A ，2B 和 1C 。 
需要买 1A ，2B 和 1C ，所以付 ¥4 买 1A 和 1B（大礼包 1），以及 ¥3 购买 1B ， ¥4 购买 1C 。 
不可以购买超出待购清单的物品，尽管购买大礼包 2 更加便宜。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == price.length == needs.length</code></li>
	<li><code>1 &lt;= n &lt;= 6</code></li>
	<li><code>0 &lt;= price[i], needs[i] &lt;= 10</code></li>
	<li><code>1 &lt;= special.length &lt;= 100</code></li>
	<li><code>special[i].length == n + 1</code></li>
	<li><code>0 &lt;= special[i][j] &lt;= 50</code></li>
	<li>生成的输入对于&nbsp;<code>0 &lt;= j &lt;= n - 1</code> 至少有一个&nbsp;<code>special[i][j]</code>&nbsp;非零。</li>
</ul>


    
## 解题方法：记忆化搜索

写一个深度优先搜索函数dfs，函数接收“此时的needs”作为参数，返回满足当前needs所需的最小花费。

对于这个函数，默认最小花费$ans$是依据price中的价格单独购买每一件物品。

之后遍历special数组，若某个方案中每种物品数量都不超过需求needs，就尝试这种方案：

> $ans = \min(ans, special[-1] + dfs(needs - special))$

这就(深度优先)搜索。所谓记忆化，就是使用一个哈希表记录函数参数和返回值，当再次调用dfs函数计算相同的参数时，直接返回哈希表中记录的结果。

+ 时间复杂度$O(len(special)\times n\times \prod (needs_i + 1))$。$needs$数组最多有$\prod (needs_i + 1)$种情况（例如$needs=[0,1,2]$一共有$1\times 2\times 3=6$种情况；对于每种情况要判断$len(special)$种套餐；对于每种套餐，要分别计算其中的$n$件商品。时间复杂度最大值为$100\times 6\times (10+1)^6=1,062,936,600$，还以为这种算法无法通过，但C++实际执行耗时0ms。。。
+ 空间复杂度$O(n\times \prod needs_i)$：空间复杂度等于商品种类数乘以状态数。

### AC代码

#### C++

```cpp
struct my_hash {
    size_t operator()(const vector<int>& v) const {
        size_t ans = 0;
        for (int t : v) {
            ans = ans * 15 + t;
        }
        return ans;
    }
};

class Solution {
private:
    unordered_map<vector<int>, int, my_hash> cache;

    inline bool canThisSpecial(vector<int>& thisSpecial, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            if (thisSpecial[i] > needs[i]) {
                return false;
            }
        }
        return true;
    }

    inline void useThisSpecial(vector<int>& thisSpecial, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            needs[i] -= thisSpecial[i];
        }
    }

    inline void cancelThisSpecial(vector<int>& thisSpecial, vector<int>& needs) {
        for (int i = 0; i < needs.size(); i++) {
            needs[i] += thisSpecial[i];
        }
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (cache.count(needs)) {
            return cache[needs];
        }
        int ans = 0;
        for (int i = 0; i < needs.size(); i++) {
            ans += needs[i] * price[i];
        }
        for (vector<int>& thisSpecial : special) {
            if (canThisSpecial(thisSpecial, needs)) {
                useThisSpecial(thisSpecial, needs);
                ans = min(ans, thisSpecial.back() + dfs(price, special, needs));
                cancelThisSpecial(thisSpecial, needs);
            }
        }
        return cache[needs] = ans;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};
```

#### Python

```python
from typing import List, Tuple
from functools import cache

class Solution:
    @cache
    def dfs(self, needs: Tuple[int]) -> int:
        ans = sum(self.price[i] * needs[i] for i in range(len(needs)))
        for thisSpecial in self.special:
            if any(thisSpecial[i] > needs[i] for i in range(len(needs))):
                continue
            newNeedsList = list(needs)
            for i in range(len(newNeedsList)):
                newNeedsList[i] -= thisSpecial[i]
            ans = min(ans, thisSpecial[-1] + self.dfs(tuple(newNeedsList)))
        return ans

    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        self.price = price
        self.special = special
        return self.dfs(tuple(needs))
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/03/LeetCode%200638.%E5%A4%A7%E7%A4%BC%E5%8C%85/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143465993](https://letmefly.blog.csdn.net/article/details/143465993)
