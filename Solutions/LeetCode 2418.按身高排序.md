---
title: 2418.按身高排序
date: 2023-04-25 20:41:34
tags: [题解, LeetCode, 简单, 数组, 哈希表, 字符串, 排序]
---

# 【LetMeFly】2418.按身高排序

力扣题目链接：[https://leetcode.cn/problems/sort-the-people/](https://leetcode.cn/problems/sort-the-people/)

<p>给你一个字符串数组 <code>names</code> ，和一个由 <strong>互不相同</strong> 的正整数组成的数组 <code>heights</code> 。两个数组的长度均为 <code>n</code> 。</p>

<p>对于每个下标 <code>i</code>，<code>names[i]</code> 和 <code>heights[i]</code> 表示第 <code>i</code> 个人的名字和身高。</p>

<p>请按身高 <strong>降序</strong> 顺序返回对应的名字数组 <code>names</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>names = ["Mary","John","Emma"], heights = [180,165,170]
<strong>输出：</strong>["Mary","Emma","John"]
<strong>解释：</strong>Mary 最高，接着是 Emma 和 John 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>names = ["Alice","Bob","Bob"], heights = [155,185,150]
<strong>输出：</strong>["Bob","Alice","Bob"]
<strong>解释：</strong>第一个 Bob 最高，然后是 Alice 和第二个 Bob 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == names.length == heights.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= names[i].length &lt;= 20</code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>names[i]</code> 由大小写英文字母组成</li>
	<li><code>heights</code> 中的所有值互不相同</li>
</ul>


    
## 方法一：排序

首先，我们将 每个人的身高、姓名打包到一块，放到一个数组中。

这样，我们就能对数组**以升高较高的人优先的规则**排序，排序后，数组中每个人“信息对”的“姓名”信息组成一个新的数组，即为答案。

**What's More:**

现在很多编程语言都自带排序功能，并且很多默认都是从小到大的规则排序的。

要么我们可以自定义排序规则，要么我们也可以采取一个小技巧，将“负的身高”作为键值排序即可。“负的身高”越小，真实身高越大。

+ 时间复杂度$O(len(names)\times \log len(names))$
+ 空间复杂度$O(len(names))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> a(names.size());
        for (int i = 0; i < names.size(); i++) {
            a[i] = {-heights[i], names[i]};
        }
        sort(a.begin(), a.end());
        vector<string> ans(a.size());
        for (int i = 0; i < a.size(); i++) {
            ans[i] = a[i].second;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        a = [[-heights[i], names[i]] for i in range(len(names))]
        a.sort()
        return [i[1] for i in a]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/04/25/LeetCode%202418.%E6%8C%89%E8%BA%AB%E9%AB%98%E6%8E%92%E5%BA%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130373729](https://letmefly.blog.csdn.net/article/details/130373729)
