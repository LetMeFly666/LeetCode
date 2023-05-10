---
title: 455.分发饼干
date: 2022-10-22 12:35:12
tags: [题解, LeetCode, 简单, 贪心, 数组, 排序, 双指针]
---

# 【LetMeFly】455.分发饼干

力扣题目链接：[https://leetcode.cn/problems/assign-cookies/](https://leetcode.cn/problems/assign-cookies/)

<p>假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。</p>

<p>对每个孩子 <code>i</code>，都有一个胃口值 <code>g[i]</code><sub>，</sub>这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 <code>j</code>，都有一个尺寸 <code>s[j]</code><sub> </sub>。如果 <code>s[j] >= g[i]</code>，我们可以将这个饼干 <code>j</code> 分配给孩子 <code>i</code> ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。</p>
 

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> g = [1,2,3], s = [1,1]
<strong>输出:</strong> 1
<strong>解释:</strong> 
你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
所以你应该输出1。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> g = [1,2], s = [1,2,3]
<strong>输出:</strong> 2
<strong>解释:</strong> 
你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以你应该输出2.
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= g.length <= 3 * 10<sup>4</sup></code></li>
	<li><code>0 <= s.length <= 3 * 10<sup>4</sup></code></li>
	<li><code>1 <= g[i], s[j] <= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 方法一：双指针

先对孩子的胃和饼干分别从小到大排序，然后使用两个指针，分别指向处理到的“孩子”、“饼干”

不难发现：

> 一块饼干如果能喂饱“大胃娃”，那么一定能喂饱“小胃娃”

因此我们从小胃小孩开始满足，在当前饼干无法满足这个小孩时（那么一定也无法满足其他未胃饱的小孩），不断往后遍历，直到找到能满足这孩子的饼干为止

如果遍历完了所有饼干还是不能满足当前孩子，那么剩下所有孩子都无法得到满足，直接结束遍历即可。

+ 时间复杂度$O(n\log n + m\log m)$，其中$n$是孩子数量，$m$是饼干数量
+ 空间复杂度$O(\log n + \log m)$

> By the way, g应该代表greed，s应该代表size (+: 我猜的

### AC代码

#### C++

```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int ls = 0, lg = 0;
        for (; lg < g.size(); lg++) {
            while (ls <s.size() && s[ls] < g[lg])
                ls++;
            if (ls < s.size())
                ans++, ls++;
            else
                break;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/22/LeetCode%200455.%E5%88%86%E5%8F%91%E9%A5%BC%E5%B9%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127460427](https://letmefly.blog.csdn.net/article/details/127460427)
