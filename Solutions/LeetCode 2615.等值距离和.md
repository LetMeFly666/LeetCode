---
title: 2615.等值距离和：分组(哈希表+前缀和)
date: 2026-04-24 13:21:53
tags: [题解, LeetCode, 中等, 数组, 哈希表, map, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】2615.等值距离和：分组(哈希表+前缀和)

力扣题目链接：[https://leetcode.cn/problems/sum-of-distances/](https://leetcode.cn/problems/sum-of-distances/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。现有一个长度等于 <code>nums.length</code> 的数组 <code>arr</code> 。对于满足 <code>nums[j] == nums[i]</code> 且 <code>j != i</code> 的所有 <code>j</code> ，<code>arr[i]</code> 等于所有 <code>|i - j|</code> 之和。如果不存在这样的 <code>j</code> ，则令 <code>arr[i]</code> 等于 <code>0</code> 。</p>

<p>返回数组<em> </em><code>arr</code><em> 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,1,1,2]
<strong>输出：</strong>[5,0,3,4,0]
<strong>解释：</strong>
i = 0 ，nums[0] == nums[2] 且 nums[0] == nums[3] 。因此，arr[0] = |0 - 2| + |0 - 3| = 5 。 
i = 1 ，arr[1] = 0 因为不存在值等于 3 的其他下标。
i = 2 ，nums[2] == nums[0] 且 nums[2] == nums[3] 。因此，arr[2] = |2 - 0| + |2 - 3| = 3 。
i = 3 ，nums[3] == nums[0] 且 nums[3] == nums[2] 。因此，arr[3] = |3 - 0| + |3 - 2| = 4 。 
i = 4 ，arr[4] = 0 因为不存在值等于 2 的其他下标。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,5,3]
<strong>输出：</strong>[0,0,0]
<strong>解释：</strong>因为 nums 中的元素互不相同，对于所有 i ，都有 arr[i] = 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：哈希表 + 前缀和

读起来题意理解稍难，在此转述下：

> 对于数组中下标为$i$的元素$nums[i]$，它对应的要返回的结果$ans[i]$怎么算呢？
> 
> 对于$nums$中所有和$nums[i]$相等的$nums[j]$们，计算$abs(j-i)$之和即为所求。

显而易见，对于元素$nums[i]$，其最终结果仅与和$nums[i]$相等的元素有关。因此我们可以使用一个哈希表，键为$nums[i]$值为所有等于$nums[i]$的下标们，遍历一遍即可实现原始数组按照值的分组。

好了，分好组了，现在我们得到了很多的$idxs$数组，每个$idxs$数组存放的都是在$nums$中值相等的下标们。问题就变成了给你一个升序的$idxs$数组，对于其中的元素$a$，求数组中其他所有元素和$a$的差的绝对值之和。

怎么算？前缀和+后缀和就好：

> 创建一个后缀和数组$suffix$，令$suffix[i]$为$\sum_{j=i}^{j\lt len(idxs)} idxs[j]$（即$idxs$数组中从$idxs[i]$到最后一个元素的元素和）。
> 
> 从前到后遍历$idxs$数组，使用一个变量$prefix$，$prefix$代表这个元素之前所有元素的和（不包含当前遍历到的元素）。
> 
> 那么，$idxs[i]$要算出的最终结果就是：$i$后面所有元素之和($suffix[i+1]$) $-$ 后面元素个数$\times idxs[i] + i$前面元素个数$\times idxs[i]$ $-$ 前面元素之和$prefix$。

另外，也可以不使用$suffix$数组，改为$suffix[i+1]$由$total-prefix-idxs[i]$得出。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-24 13:53:47
 */
typedef long long ll;
class Solution {
private:
    void cal(vector<int>& idxs, vector<ll>& ans) {
        int n = idxs.size();
        ll total = accumulate(idxs.begin(), idxs.end(), 0LL);
        ll prefix = 0;
        for (int i = 0; i < n; i++) {
            ans[idxs[i]] += (total - prefix - idxs[i]) - (ll)(n - i - 1) * idxs[i];
            ans[idxs[i]] += (ll)i * idxs[i] - prefix;
            prefix += idxs[i];
        }
    }
public:
    vector<ll> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> ma;
        for (int i = 0; i < nums.size(); i++) {
            ma[nums[i]].push_back(i);
        }

        vector<ll> ans(nums.size());
        for (auto&& [_, idxs] : ma) {
            cal(idxs, ans);
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160474032)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/23/LeetCode%202615.%E7%AD%89%E5%80%BC%E8%B7%9D%E7%A6%BB%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
