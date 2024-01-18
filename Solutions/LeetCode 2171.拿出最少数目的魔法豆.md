---
title: 2171.拿出最少数目的魔法豆
date: 2024-01-18 19:29:06
tags: [题解, LeetCode, 中等, 数组, 前缀和, 排序]
---

# 【LetMeFly】2171.拿出最少数目的魔法豆：排序 + 枚举

力扣题目链接：[https://leetcode.cn/problems/removing-minimum-number-of-magic-beans/](https://leetcode.cn/problems/removing-minimum-number-of-magic-beans/)

<p>给你一个 <strong>正</strong>&nbsp;整数数组&nbsp;<code>beans</code>&nbsp;，其中每个整数表示一个袋子里装的魔法豆的数目。</p>

<p>请你从每个袋子中&nbsp;<strong>拿出</strong>&nbsp;一些豆子（也可以<strong>&nbsp;不拿出</strong>），使得剩下的 <strong>非空</strong> 袋子中（即 <strong>至少</strong>&nbsp;还有 <strong>一颗</strong>&nbsp;魔法豆的袋子）魔法豆的数目&nbsp;<strong>相等</strong>&nbsp;。一旦魔法豆从袋子中取出，你不能将它放到任何其他的袋子中。</p>

<p>请你返回你需要拿出魔法豆的 <strong>最少数目</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>beans = [4,<em><strong>1</strong></em>,6,5]
<b>输出：</b>4
<b>解释：</b>
- 我们从有 1 个魔法豆的袋子中拿出 1 颗魔法豆。
  剩下袋子中魔法豆的数目为：[4,<em><b>0</b></em>,6,5]
- 然后我们从有 6 个魔法豆的袋子中拿出 2 个魔法豆。
  剩下袋子中魔法豆的数目为：[4,0,<em><strong>4</strong></em>,5]
- 然后我们从有 5 个魔法豆的袋子中拿出 1 个魔法豆。
  剩下袋子中魔法豆的数目为：[4,0,4,<em><b>4</b></em>]
总共拿出了 1 + 2 + 1 = 4 个魔法豆，剩下非空袋子中魔法豆的数目相等。
没有比取出 4 个魔法豆更少的方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>beans = [<em><strong>2</strong></em>,10,<em><strong>3</strong></em>,<em><strong>2</strong></em>]
<b>输出：</b>7
<strong>解释：</strong>
- 我们从有 2 个魔法豆的其中一个袋子中拿出 2 个魔法豆。
  剩下袋子中魔法豆的数目为：[<em><strong>0</strong></em>,10,3,2]
- 然后我们从另一个有 2 个魔法豆的袋子中拿出 2 个魔法豆。
  剩下袋子中魔法豆的数目为：[0,10,3,<em><strong>0</strong></em>]
- 然后我们从有 3 个魔法豆的袋子中拿出 3 个魔法豆。
  剩下袋子中魔法豆的数目为：[0,10,<em><strong>0</strong></em>,0]
总共拿出了 2 + 2 + 3 = 7 个魔法豆，剩下非空袋子中魔法豆的数目相等。
没有比取出 7 个魔法豆更少的方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= beans.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= beans[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：排序 + 枚举

二话不说先将豆子数量从小到大排个序。

统计一下一共有多少个豆子（即为all）。

遍历每个袋子中豆子的数量（假设当前豆子数量为bean），计算将小于bean的袋子移空、大于等于bean的袋子移为bean所需移除的豆子总数。

返回所有总数中的最小值即为答案。

+ 时间复杂度$O(len(beans))$
+ 空间复杂度$O(len(beans))$

### AC代码

#### C++

```cpp
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long all = accumulate(beans.begin(), beans.end(), 0LL);
        long long ans = all;
        for (int i = 0; i < beans.size(); i++) {
            ans = min(ans, all - ((long long)beans.size() - i) * beans[i]);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        beans.sort()
        all_ = sum(beans)
        ans = all_
        for i, thisBean in enumerate(beans):
            ans = min(ans, all_ - thisBean * (len(beans) - i))
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2024/01/18/LeetCode%202171.%E6%8B%BF%E5%87%BA%E6%9C%80%E5%B0%91%E6%95%B0%E7%9B%AE%E7%9A%84%E9%AD%94%E6%B3%95%E8%B1%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135682601](https://letmefly.blog.csdn.net/article/details/135682601)
