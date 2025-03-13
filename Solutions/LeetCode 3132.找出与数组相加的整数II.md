---
title: 3132.找出与数组相加的整数 II
date: 2024-08-09 23:13:43
tags: [题解, LeetCode, 中等, 数组, 双指针, 枚举, 排序, 匹配]
categories: [题解, LeetCode]
---

# 【LetMeFly】3132.找出与数组相加的整数 II：排序+3次尝试(nlog n)

力扣题目链接：[https://leetcode.cn/problems/find-the-integer-added-to-array-ii/](https://leetcode.cn/problems/find-the-integer-added-to-array-ii/)

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code>。</p>

<p>从 <code>nums1</code> 中移除两个元素，并且所有其他元素都与变量 <code>x</code> 所表示的整数相加。如果 <code>x</code> 为负数，则表现为元素值的减少。</p>

<p>执行上述操作后，<code>nums1</code> 和 <code>nums2</code> <strong>相等</strong> 。当两个数组中包含相同的整数，并且这些整数出现的频次相同时，两个数组 <strong>相等</strong> 。</p>

<p>返回能够实现数组相等的 <strong>最小 </strong>整数<em> </em><code>x</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [4,20,16,12,8], nums2 = [14,18,10]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">-2</span></p>

<p><strong>解释：</strong></p>

<p>移除 <code>nums1</code> 中下标为 <code>[0,4]</code> 的两个元素，并且每个元素与 <code>-2</code> 相加后，<code>nums1</code> 变为 <code>[18,14,10]</code> ，与 <code>nums2</code> 相等。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">nums1 = [3,5,5,3], nums2 = [7,7]</span></p>

<p><strong>输出：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">2</span></p>

<p><strong>解释：</strong></p>

<p>移除 <code>nums1</code> 中下标为 <code>[0,3]</code> 的两个元素，并且每个元素与 <code>2</code> 相加后，<code>nums1</code> 变为 <code>[7,7]</code> ，与 <code>nums2</code> 相等。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums1.length &lt;= 200</code></li>
	<li><code>nums2.length == nums1.length - 2</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
	<li>测试用例以这样的方式生成：存在一个整数 <code>x</code>，<code>nums1</code> 中的每个元素都与 <code>x</code> 相加后，再移除两个元素，<code>nums1</code> 可以与 <code>nums2</code> 相等。</li>
</ul>


    
## 解题方法：排序+3次尝试

分别对两个数组排序。因为一定有解，所以nums1中前3个元素至少有一个和nums2[0]对应。也就是说，可能的x最多有3种情况。对于每种情况，我们从大到小尝试，如果当前x可行，则返回。

怎么判定nums1删除两个元素后是否每个元素加上x后都和nums2对应呢？只需要两个指针分别指向两个数组中的元素。

> 在指针没有超出数组有效范围时：
> 
> + 若$nums1[n1] + x == nums2[n2]$，则两个指针分别后移
> + 否则跳过nums1中的这个数：n1后移n2不动，“跳过次数”加一。（若跳过次数大于2则说明这个x不可行）
>
> 最终如果n2指到nums2的末尾，则说明这个x可行。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool isOk(vector<int>& nums1, vector<int>& nums2, int x) {
        int skip = 0;
        int n1 = 0, n2 = 0;
        while (n1 < nums1.size() && n2 < nums2.size()) {
            if (nums1[n1] + x == nums2[n2]) {
                n1++, n2++;
            }
            else {
                n1++, skip++;
                if (skip > 2) {
                    return false;
                }
            }
        }
        return n2 == nums2.size();
    }
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 2; i >= 0; i--) {
            if (isOk(nums1, nums2, nums2[0] - nums1[i])) {
                return nums2[0] - nums1[i];
            }
        }
        return -1;  // Fake Return
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/09/LeetCode%203132.%E6%89%BE%E5%87%BA%E4%B8%8E%E6%95%B0%E7%BB%84%E7%9B%B8%E5%8A%A0%E7%9A%84%E6%95%B4%E6%95%B0II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141072842](https://letmefly.blog.csdn.net/article/details/141072842)
