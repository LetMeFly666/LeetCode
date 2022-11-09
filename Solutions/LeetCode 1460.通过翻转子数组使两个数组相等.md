---
title: 1460.通过翻转子数组使两个数组相等
date: 2022-08-24 10:28:38
tags: [题解, LeetCode, 简单, 数组, 哈希表, 排序]
---

# 【LetMeFly】1460.通过翻转子数组使两个数组相等

力扣题目链接：[https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays/](https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays/)

<p>给你两个长度相同的整数数组&nbsp;<code>target</code>&nbsp;和&nbsp;<code>arr</code>&nbsp;。每一步中，你可以选择&nbsp;<code>arr</code>&nbsp;的任意 <strong>非空子数组</strong>&nbsp;并将它翻转。你可以执行此过程任意次。</p>

<p><em>如果你能让 <code>arr</code>&nbsp;变得与 <code>target</code>&nbsp;相同，返回 True；否则，返回 False 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = [1,2,3,4], arr = [2,4,1,3]
<strong>输出：</strong>true
<strong>解释：</strong>你可以按照如下步骤使 arr 变成 target：
1- 翻转子数组 [2,4,1] ，arr 变成 [1,4,2,3]
2- 翻转子数组 [4,2] ，arr 变成 [1,2,4,3]
3- 翻转子数组 [4,3] ，arr 变成 [1,2,3,4]
上述方法并不是唯一的，还存在多种将 arr 变成 target 的方法。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = [7], arr = [7]
<strong>输出：</strong>true
<strong>解释：</strong>arr 不需要做任何翻转已经与 target 相等。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>target = [3,7,9], arr = [3,7,11]
<strong>输出：</strong>false
<strong>解释：</strong>arr 没有数字 9 ，所以无论如何也无法变成 target 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>target.length == arr.length</code></li>
	<li><code>1 &lt;= target.length &lt;= 1000</code></li>
	<li><code>1 &lt;= target[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：排序

每次只翻转子数组，就可以实现排序。（大家都直到冒泡排序吧，只要每次都选择长度为$2$的子数组进行反转，那么效果就和冒泡排序一样了）

这道题不限制交换次数，因此只要最终两个数组排序后的元素一一对应，二者就一定能通过数次的“翻转子数组”达到一致。

反之，如果排序后二者有不同，那么就说明二者中的元素都不完全一样，无论如何反转都不能使二者相同。

所以，我们只需要对二者分别进行排序，并看排序之后两数组是否相同即可。

+ 时间复杂度$O(n\log n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
		// 以下也可以简写为“return target == arr;”
        for (int i = target.size() - 1; i >= 0; i--) {
            if (target[i] != arr[i]) {
                return false;
            }
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/24/LeetCode%201460.%E9%80%9A%E8%BF%87%E7%BF%BB%E8%BD%AC%E5%AD%90%E6%95%B0%E7%BB%84%E4%BD%BF%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9B%B8%E7%AD%89/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126499790](https://letmefly.blog.csdn.net/article/details/126499790)
