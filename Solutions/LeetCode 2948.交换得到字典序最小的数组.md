---
title: 2948.交换得到字典序最小的数组：两层排序
date: 2026-08-29 11:30:30
tags: [题解, LeetCode, 中等, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2948.交换得到字典序最小的数组：两层排序

力扣题目链接：[https://leetcode.cn/problems/make-lexicographically-smallest-array-by-swapping-elements/](https://leetcode.cn/problems/make-lexicographically-smallest-array-by-swapping-elements/)

<p>给你一个下标从 <strong>0 </strong>开始的 <strong>正整数</strong> 数组 <code>nums</code> 和一个 <strong>正整数</strong> <code>limit</code> 。</p>

<p>在一次操作中，你可以选择任意两个下标 <code>i</code> 和 <code>j</code>，<strong>如果</strong> 满足 <code>|nums[i] - nums[j]| &lt;= limit</code> ，则交换 <code>nums[i]</code> 和 <code>nums[j]</code> 。</p>

<p>返回执行任意次操作后能得到的 <strong>字典序最小的数组</strong><em> </em>。</p>

<p>如果在数组 <code>a</code> 和数组 <code>b</code> 第一个不同的位置上，数组 <code>a</code> 中的对应元素比数组 <code>b</code> 中的对应元素的字典序更小，则认为数组 <code>a</code> 就比数组 <code>b</code> 字典序更小。例如，数组 <code>[2,10,3]</code> 比数组 <code>[10,2,3]</code> 字典序更小，下标 <code>0</code> 处是两个数组第一个不同的位置，且 <code>2 &lt; 10</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,3,9,8], limit = 2
<strong>输出：</strong>[1,3,5,8,9]
<strong>解释：</strong>执行 2 次操作：
- 交换 nums[1] 和 nums[2] 。数组变为 [1,3,5,9,8] 。
- 交换 nums[3] 和 nums[4] 。数组变为 [1,3,5,8,9] 。
即便执行更多次操作，也无法得到字典序更小的数组。
注意，执行不同的操作也可能会得到相同的结果。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,7,6,18,2,1], limit = 3
<strong>输出：</strong>[1,6,7,18,1,2]
<strong>解释：</strong>执行 3 次操作：
- 交换 nums[1] 和 nums[2] 。数组变为 [1,6,7,18,2,1] 。
- 交换 nums[0] 和 nums[4] 。数组变为 [2,6,7,18,1,1] 。
- 交换 nums[0] 和 nums[5] 。数组变为 [1,6,7,18,1,2] 。
即便执行更多次操作，也无法得到字典序更小的数组。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,7,28,19,10], limit = 3
<strong>输出：</strong>[1,7,28,19,10]
<strong>解释：</strong>[1,7,28,19,10] 是字典序最小的数组，因为不管怎么选择下标都无法执行操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：排序

对于示例2的`nums = [1,7,6,18,2,1], limit = 3`，不难发现`[1,2,1]`这三个元素是一组、`[7,6]`这两个元素是一组、`[18]`是一组。

我们把其中的`[1,2,1]`排序得到`[1,1,2]`并放到原来的位置上，`[7,6]`同理，`[18]`同理，就得到了结果`[1,6,7,18,1,2]`。

怎么确定都哪些元素是一组？排序就好。`[1,7,6,18,2,1]`排序后是`[1,1,2,6,7,18]`，从左往右遍历并查看相邻两元素的差值是否大于`limit`，如果大于则说明需要新分一组。

但是排序后我们就丢失了原来的下标信息，所以我们需要一个下标数组来记录原来的下标。具体而言可以创建从$0$到$len(nums) - 1$的下标数组`idxs`，然后按照`nums[idxs[i]]`的值来排序`idxs`，这样就可以在排序后知道原来的下标。遍历排序后数组的方式是从`nums[idxs[0]]`遍历到`nums[idxs[len(nums) - 1]]`。

现在我们可以得到下标为`[0, 5, 4]`的元素`[1, 1, 2]`是一组了，现在我们要把`[1, 1, 2]` **按顺序** 填回原来的位置，所以我们还需要对这组的下标`[0, 5, 4]`再排个序得到`[0, 4, 5]`，并按顺序填入`[1, 1, 2]`即可。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-29 11:27:22
 */
class Solution {
private:
    void full(vector<int>& ans, vector<int>& nums, vector<int>& idxs, int l, int r) {
        vector<int> pos(r - l);
        for (int i = l, th = 0; i < r; i++, th++) {
            pos[th] = idxs[i];
        }
        ranges::sort(pos);
        for (int i = l, th = 0; i < r; i++, th++) {
            ans[pos[th]] = nums[idxs[i]];
        }
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> idxs(nums.size());
        ranges::iota(idxs, 0);
        sort(idxs.begin(), idxs.end(), [&nums](const int& a, const int& b) { return nums[a] < nums[b]; });

        vector<int> ans(nums.size());
        for (int i = 1, n = nums.size(), last = 0; i <= n; i++) {
            if (i == n || nums[idxs[i]] - nums[idxs[i - 1]] > limit) {
                full(ans, nums, idxs, last, i);
                last = i;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/164167744)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/29/LeetCode%202948.%E4%BA%A4%E6%8D%A2%E5%BE%97%E5%88%B0%E5%AD%97%E5%85%B8%E5%BA%8F%E6%9C%80%E5%B0%8F%E7%9A%84%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
