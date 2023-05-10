---
title: 1630.等差子数组
date: 2023-03-23 18:06:14
tags: [题解, LeetCode, 中等, 数组, 排序, 哈希表, 哈希, set, 等差数列]
---

# 【LetMeFly】1630.等差子数组

力扣题目链接：[https://leetcode.cn/problems/arithmetic-subarrays/](https://leetcode.cn/problems/arithmetic-subarrays/)

<p>如果一个数列由至少两个元素组成，且每两个连续元素之间的差值都相同，那么这个序列就是 <strong>等差数列</strong> 。更正式地，数列 <code>s</code> 是等差数列，只需要满足：对于每个有效的 <code>i</code> ， <code>s[i+1] - s[i] == s[1] - s[0]</code> 都成立。</p>

<p>例如，下面这些都是 <strong>等差数列</strong> ：</p>

<pre>1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9</pre>

<p>下面的数列 <strong>不是等差数列</strong> ：</p>

<pre>1, 1, 2, 5, 7</pre>

<p>给你一个由 <code>n</code> 个整数组成的数组 <code>nums</code>，和两个由 <code>m</code> 个整数组成的数组 <code>l</code> 和 <code>r</code>，后两个数组表示 <code>m</code> 组范围查询，其中第 <code>i</code> 个查询对应范围 <code>[l[i], r[i]]</code> 。所有数组的下标都是 <strong>从 0 开始</strong> 的。</p>

<p>返回<em> </em><code>boolean</code> 元素构成的答案列表 <code>answer</code> 。如果子数组 <code>nums[l[i]], nums[l[i]+1], ... , nums[r[i]]</code> 可以 <strong>重新排列</strong> 形成 <strong>等差数列</strong> ，<code>answer[i]</code> 的值就是 <code>true</code>；否则<code>answer[i]</code> 的值就是 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = <code>[4,6,5,9,3,7]</code>, l = <code>[0,0,2]</code>, r = <code>[2,3,5]</code>
<strong>输出：</strong><code>[true,false,true]</code>
<strong>解释：</strong>
第 0 个查询，对应子数组 [4,6,5] 。可以重新排列为等差数列 [6,5,4] 。
第 1 个查询，对应子数组 [4,6,5,9] 。无法重新排列形成等差数列。
第 2 个查询，对应子数组 <code>[5,9,3,7] 。</code>可以重新排列为等差数列 <code>[3,5,7,9] 。</code></pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
<strong>输出：</strong>[false,true,false,false,true,true]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == l.length</code></li>
	<li><code>m == r.length</code></li>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= m &lt;= 500</code></li>
	<li><code>0 &lt;= l[i] &lt; r[i] &lt; n</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：哈希表

怎么判断```num[l, r]```区间是否能构成等差数列呢？

最简单的办法就是排序，然后从num[l]遍历到num[r]，看相邻两数之差是否相同。

**当然可以！**

但是排序的时间复杂度是$O(n\log n)$（其中$n=r-l+1$），有没有时间复杂度耕地的做法呢？

当然有。首先找到num[l]到num[r]的最大值M和最小值m：

+ 如果M = m，则说明num[l]到num[r]的数全部相等，能构成等差数列
+ 否则，若能构成等差数列，则公差为$d=\frac{M-m}{num[r]-num[l]}$，这就需要满足
   1. 公差$d$为整数
   2. num[l]到num[r]中每个数都只出现了一次（这个可以使用哈希表来完成）

这样，每次判断的时间复杂度就是$r-l$了

+ 时间复杂度$O(len(nums)\times(\sum (r[i]-l[i]))$
+ 空间复杂度$O(\max(r[i]-l[i]))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        for (int i = 0; i < l.size(); i++) {
            int m = *min_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            int M = *max_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            if (m == M) {
                ans[i] = true;
                continue;
            }
            if ((M - m) % (r[i] - l[i])) {
                ans[i] = false;
                continue;
            }
            int d = (M - m) / (r[i] - l[i]);
            unordered_set<int> se;
            for (int j = l[i]; j <= r[i]; j++) {
                if (se.count(nums[j])) {
                    ans[i] = false;
                    goto loop;
                }
                if ((nums[j] - m) % d) {
                    ans[i] = false;
                    goto loop;
                }
                se.insert(nums[j]);
            }
            ans[i] = true;
            loop:;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        ans = [False for i in range(len(l))]
        for i in range(len(l)):
            m = min(nums[l[i] : r[i] + 1])
            M = max(nums[l[i] : r[i] + 1])
            if m == M:
                ans[i] = True
                continue
            if (M - m) % (r[i] - l[i]):
                ans[i] = False
                continue
            d = (M - m) // (r[i] - l[i])
            se = set()
            ok = True
            for j in range(l[i], r[i] + 1):
                if nums[j] in se:
                    ok = False
                    break
                if (nums[j] - m) % d:
                    ok = False
                    break
                se.add(nums[j])
            ans[i] = ok
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/03/23/LeetCode%201630.%E7%AD%89%E5%B7%AE%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129736480](https://letmefly.blog.csdn.net/article/details/129736480)
