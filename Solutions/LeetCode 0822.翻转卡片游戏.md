---
title: 822.翻转卡片游戏：双O(n)的做法
date: 2023-08-02 08:00:00
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, set]
categories: [题解, LeetCode]
---

# 【LetMeFly】822.翻转卡片游戏：双O(n)的做法

力扣题目链接：[https://leetcode.cn/problems/card-flipping-game/](https://leetcode.cn/problems/card-flipping-game/)

<p>在桌子上有 <code>N</code> 张卡片，每张卡片的正面和背面都写着一个正数（正面与背面上的数有可能不一样）。</p>

<p>我们可以先翻转任意张卡片，然后选择其中一张卡片。</p>

<p>如果选中的那张卡片背面的数字 <code>X</code> 与任意一张卡片的正面的数字都不同，那么这个数字是我们想要的数字。</p>

<p>哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？如果没有一个数字符合要求的，输出 0。</p>

<p>其中, <code>fronts[i]</code>&nbsp;和&nbsp;<code>backs[i]</code>&nbsp;分别代表第&nbsp;<code>i</code>&nbsp;张卡片的正面和背面的数字。</p>

<p>如果我们通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
<strong>输出：</strong><code>2</code>
<strong>解释：</strong>假设我们翻转第二张卡片，那么在正面的数变成了 <code>[1,3,4,4,7]</code> ， 背面的数变成了 <code>[1,2,4,1,3]。</code>
接着我们选择第二张卡片，因为现在该卡片的背面的数是 2，2 与任意卡片上正面的数都不同，所以 2 就是我们想要的数字。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= fronts.length == backs.length&nbsp;&lt;=&nbsp;1000</code></li>
	<li><code>1 &lt;=&nbsp;fronts[i]&nbsp;&lt;= 2000</code></li>
	<li><code>1 &lt;= backs[i]&nbsp;&lt;= 2000</code></li>
</ol>


    
## 方法一：双O(n)的做法

翻转任意张牌后，某张牌的牌背与所有牌的正面都不相同。说明什么？如果这张牌的牌背是$a$，说明**没有牌正反面都是**$a$。

（只要没有牌的正反面都是$a$，那么我一定可以让所有的$a$朝下，然后选取向下的$a$就和所有牌的正面都不同了）。

因此，**我们只需要记录正反面相同的牌即可**，遍历所有牌的正反面，若某值没被记录在哈希表中，则此值可作为答案。

+ 时间复杂度$O(len(fronts))$
+ 空间复杂度$O(len(fronts))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> se;
        int n = fronts.size();
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                se.insert(fronts[i]);
            }
        }
        int ans = 2001;
        for (int i = 0; i < n; i++) {
            if (!se.count(fronts[i])) {
                ans = min(ans, fronts[i]);
            }
            if (!se.count(backs[i])) {
                ans = min(ans, backs[i]);
            }
        }
        return ans == 2001 ? 0 : ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        se = set()
        n = len(fronts)
        for i in range(n):
            if fronts[i] == backs[i]:
                se.add(fronts[i])
        ans = 2001
        for i in range(n):
            for value in (fronts[i], backs[i]):
                if value not in se:
                    ans = min(ans, value)
        return 0 if ans == 2001 else ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/08/02/LeetCode%200822.%E7%BF%BB%E8%BD%AC%E5%8D%A1%E7%89%87%E6%B8%B8%E6%88%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132053927](https://letmefly.blog.csdn.net/article/details/132053927)
