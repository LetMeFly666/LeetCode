---
title: 167.两数之和 II - 输入有序数组
date: 2022-08-04 11:04:24
tags: [题解, LeetCode, 中等, 数组, 双指针, 二分, 哈希]
---

# 【LetMeFly】167.两数之和 II - 输入有序数组

力扣题目链接：[https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)

<p>给你一个下标从 <strong>1</strong> 开始的整数数组&nbsp;<code>numbers</code> ，该数组已按<strong><em> </em>非递减顺序排列&nbsp; </strong>，请你从数组中找出满足相加之和等于目标数&nbsp;<code>target</code> 的两个数。如果设这两个数分别是 <code>numbers[index<sub>1</sub>]</code> 和 <code>numbers[index<sub>2</sub>]</code> ，则 <code>1 &lt;= index<sub>1</sub> &lt; index<sub>2</sub> &lt;= numbers.length</code> 。</p>

<p>以长度为 2 的整数数组 <code>[index<sub>1</sub>, index<sub>2</sub>]</code> 的形式返回这两个整数的下标 <code>index<sub>1</sub></code><em> </em>和<em> </em><code>index<sub>2</sub></code>。</p>

<p>你可以假设每个输入 <strong>只对应唯一的答案</strong> ，而且你 <strong>不可以</strong> 重复使用相同的元素。</p>

<p>你所设计的解决方案必须只使用常量级的额外空间。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>numbers = [<strong><em>2</em></strong>,<strong><em>7</em></strong>,11,15], target = 9
<strong>输出：</strong>[1,2]
<strong>解释：</strong>2 与 7 之和等于目标数 9 。因此 index<sub>1</sub> = 1, index<sub>2</sub> = 2 。返回 [1, 2] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>numbers = [<strong><em>2</em></strong>,3,<strong><em>4</em></strong>], target = 6
<strong>输出：</strong>[1,3]
<strong>解释：</strong>2 与 4 之和等于目标数 6 。因此 index<sub>1</sub> = 1, index<sub>2</sub> = 3 。返回 [1, 3] 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>numbers = [<strong><em>-1</em></strong>,<strong><em>0</em></strong>], target = -1
<strong>输出：</strong>[1,2]
<strong>解释：</strong>-1 与 0 之和等于目标数 -1 。因此 index<sub>1</sub> = 1, index<sub>2</sub> = 2 。返回 [1, 2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= numbers.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= numbers[i] &lt;= 1000</code></li>
	<li><code>numbers</code> 按 <strong>非递减顺序</strong> 排列</li>
	<li><code>-1000 &lt;= target &lt;= 1000</code></li>
	<li><strong>仅存在一个有效答案</strong></li>
</ul>


## 方法0.0：暴力

直接两重循环遍历数组，看能否找到两个数之和正好等于target。

+ 时间复杂度$O(n^2)$，其中$n$是数组长度
+ 空间复杂度$O(1)$

数组长度最大为$3\times 10^4$，$O(n^2)$运算量要接近$10^9$，不知道能不能通过，因此命名为```方法0```

## 方法0.1：哈希

预处理用哈希表记录出现过哪些元素（以及出现次数(防止$a+a=2a$重复计算)）

遍历一遍数组，看是否存在$target-当前元素$

+ 时间复杂度$O(n)$，其中$n$是数组长度
+ 空间复杂度$O(n)$

虽然能通过，但是不满足题目要求“使用常数的额外空间”

    
## 方法一：二分

数组是非递减的。因此我们可以遍历一遍原数组，在寻找$target - 当前元素$时，使用二分查找，看是否存在即可。

+ 时间复杂度$O(n\log n)$，其中$n$是数组长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            int finding = target - numbers[i];
            vector<int>::iterator it = lower_bound(numbers.begin() + i + 1, numbers.end(), finding);
            if (it == numbers.end() || *it != finding)
                continue;
            return {i + 1, (int)(it - numbers.begin() + 1)};
        }
        return {};  // Fake Return
    }
};
```

## 方法二：双指针

数组是非递减的。因此我们可以使用两个“指针”，初始位置分别为第一个元素和最后一个元素。

当两指针不重合时：

+ 如果两元素之和正好等于target，那么我们就找到了答案，直接返回。
+ 如果两元素之和小于target，那么左指针右移（越往右数越大）
+ 如果两元素之和大于target，那么右指针左移（越往左数越小）

这样，每个元素最多被遍历一遍。

+ 时间复杂度$O(n)$，其中$n$是数组长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int s = numbers[l] + numbers[r];
            if (s == target)
                return {l + 1, r + 1};
            else if (s < target)
                l++;
            else
                r--;
        }
        return {};  // Fake Return
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/04/LeetCode%200167.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8CII-%E8%BE%93%E5%85%A5%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126155983](https://letmefly.blog.csdn.net/article/details/126155983)
