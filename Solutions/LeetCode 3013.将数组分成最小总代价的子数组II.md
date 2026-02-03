---
title: 3013.将数组分成最小总代价的子数组 II：两个堆维护k-1小 + 滑动窗口
date: 2026-02-03 22:12:40
tags: [题解, LeetCode, 困难, 数组, 哈希表, set, 有序集合, 滑动窗口, 堆（优先队列）]
categories: [题解, LeetCode]
---

# 【LetMeFly】3013.将数组分成最小总代价的子数组 II：两个堆维护k-1小 + 滑动窗口

力扣题目链接：[https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/](https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和两个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code> 和&nbsp;<code>dist</code>&nbsp;。</p>

<p>一个数组的 <strong>代价</strong>&nbsp;是数组中的 <strong>第一个</strong>&nbsp;元素。比方说，<code>[1,2,3]</code>&nbsp;的代价为&nbsp;<code>1</code>&nbsp;，<code>[3,4,1]</code>&nbsp;的代价为&nbsp;<code>3</code>&nbsp;。</p>

<p>你需要将 <code>nums</code>&nbsp;分割成 <code>k</code>&nbsp;个 <strong>连续且互不相交</strong>&nbsp;的<span data-keyword="subarray">子数组</span>，满足 <strong>第二</strong>&nbsp;个子数组与第 <code>k</code>&nbsp;个子数组中第一个元素的下标距离 <strong>不超过</strong>&nbsp;<code>dist</code>&nbsp;。换句话说，如果你将&nbsp;<code>nums</code>&nbsp;分割成子数组&nbsp;<code>nums[0..(i<sub>1</sub> - 1)], nums[i<sub>1</sub>..(i<sub>2</sub> - 1)], ..., nums[i<sub>k-1</sub>..(n - 1)]</code>&nbsp;，那么它需要满足&nbsp;<code>i<sub>k-1</sub> - i<sub>1</sub> &lt;= dist</code>&nbsp;。</p>

<p>请你返回这些子数组的 <strong>最小</strong>&nbsp;总代价。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,3,2,6,4,2], k = 3, dist = 3
<b>输出：</b>5
<b>解释：</b>将数组分割成 3 个子数组的最优方案是：[1,3] ，[2,6,4] 和 [2] 。这是一个合法分割，因为 i<sub>k-1</sub> - i<sub>1</sub> 等于 5 - 2 = 3 ，等于 dist 。总代价为 nums[0] + nums[2] + nums[5] ，也就是 1 + 2 + 2 = 5 。
5 是分割成 3 个子数组的最小总代价。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,1,2,2,2,1], k = 4, dist = 3
<b>输出：</b>15
<b>解释：</b>将数组分割成 4 个子数组的最优方案是：[10] ，[1] ，[2] 和 [2,2,1] 。这是一个合法分割，因为 i<sub>k-1</sub> - i<sub>1</sub> 等于 3 - 1 = 2 ，小于 dist 。总代价为 nums[0] + nums[1] + nums[2] + nums[3] ，也就是 10 + 1 + 2 + 2 = 15 。
分割 [10] ，[1] ，[2,2,2] 和 [1] 不是一个合法分割，因为 i<sub>k-1</sub> 和 i<sub>1</sub> 的差为 5 - 1 = 4 ，大于 dist 。
15 是分割成 4 个子数组的最小总代价。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [10,8,18,9], k = 3, dist = 1
<b>输出：</b>36
<b>解释：</b>将数组分割成 4 个子数组的最优方案是：[10] ，[8] 和 [18,9] 。这是一个合法分割，因为 i<sub>k-1</sub> - i<sub>1</sub> 等于 2 - 1 = 1 ，等于 dist 。总代价为 nums[0] + nums[1] + nums[2] ，也就是 10 + 8 + 18 = 36 。
分割 [10] ，[8,18] 和 [9] 不是一个合法分割，因为 i<sub>k-1</sub> 和 i<sub>1</sub> 的差为 3 - 1 = 2 ，大于 dist 。
36 是分割成 3 个子数组的最小总代价。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>3 &lt;= k &lt;= n</code></li>
	<li><code>k - 2 &lt;= dist &lt;= n - 2</code></li>
</ul>


    
## 解题方法：有序集合 + 滑动窗口

$nums$第一个元素必选，剩下$k-1$个元素的起始位置间隔必须$\leq dist$。使用一个大小为$dist+1$的滑动窗口，每次求这个窗口中$k-1$小元素的和。

问题变成了滑动窗口向右滑动过程中，窗口中不断新增一个元素、移除一个元素的状态下如何保持计算$k-1$小的元素有哪些：

> 我们可以使用两个有序集合，一个叫$stage$代表(正在舞台上的)$k-1$小元素，一个叫$candidate$代表在窗口中但(暂)未被选中的元素。
> 
> 窗口右移过程中，假设要新加入窗口的元素是$in$，移除窗口的元素是$out$，
> 
> 对于$out$有：
> 
> + 如果$out$在$candidate$候选集合中，那么$out$永无上台之日，直接移出候选
> + 如果$out$在$stage$选中集合中，那么$out$是时候退役了，移出$stage$集合，并更新集合中元素之和
> 
> 对于$in$有：
> 
> + 如果$in$比$stage$中最大元素小，说明更优秀的人来了，移出$stage$集合中最大的那个，将$in$加入$stage$集合，并更新$stage$集合中元素之和
> + 否则，将$in$加入候选
> 
> 之后进行$stage$集合大小的调整：
> 
> + 如果$stage$集合小于$k-1$，说明有人退役暂无人顶上，从$candidate$中选最小的那个顶上(移出$candidate$并加入$stage$)，并更新$stage$集合中元素之和
> + 如果$stage$集合大于$k+1$，说明有更优秀的人来了，要把$stage$中最大的那个移出并加入到$candidate$，并更新$stage$集合中元素之和

整个滑动窗口移动的过程中，所有$stage$元素和中最小的那个即为答案。

为了方便计算，我们开局直接把$k$减一。

+ 时间复杂度$O(n\log dist)$
+ 空间复杂度$O(dist)$


### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-03 22:11:11
 */
typedef long long ll;
class Solution {
public:
    ll minimumCost(vector<int>& nums, int k, int dist) {
        k--;
        multiset<ll> stage(nums.begin() + 1, nums.begin() + dist + 2), candidate;
        ll ans = accumulate(nums.begin(), nums.begin() + dist + 2, 0ll);
        while (stage.size() > k) {
                int retiree = *stage.rbegin();
                stage.erase(prev(stage.end()));
                ans -= retiree;
                candidate.insert(retiree);
        }

        ll nowAns = ans;
        for (int end = dist + 2; end < nums.size(); end++) {
            int in = nums[end], out = nums[end - dist - 1];
            
            // out
            multiset<ll>::iterator it = candidate.find(out);
            if (it != candidate.end()) {
                candidate.erase(it);
            } else {
                stage.erase(stage.find(out));
                nowAns -= out;
            }

            // in
            if (in < *stage.rbegin()) {
                stage.insert(in);
                nowAns += in;
            } else {
                candidate.insert(in);
            }

            // resize
            if (stage.size() == k - 1) {
                int newActor = *candidate.begin();
                candidate.erase(candidate.begin());
                stage.insert(newActor);
                nowAns += newActor;
            } else if (stage.size() == k + 1) {
                int retiree = *stage.rbegin();
                stage.erase(prev(stage.end()));
                nowAns -= retiree;
                candidate.insert(retiree);
            }

            ans = min(ans, nowAns);
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[1,3,2,6,4,2]
3
3

5
*/
int main() {
    string s;
    int a, b;
    while (cin >> s >> a >> b) {
        Solution sol;
        vector<int> v = stringToVector(s);
        cout << sol.minimumCost(v, a, b) << endl;
    }
    return 0;
}
#endif
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157700064)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/03/LeetCode%203013.%E5%B0%86%E6%95%B0%E7%BB%84%E5%88%86%E6%88%90%E6%9C%80%E5%B0%8F%E6%80%BB%E4%BB%A3%E4%BB%B7%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
