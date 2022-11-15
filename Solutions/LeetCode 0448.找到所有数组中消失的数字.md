---
title: 448.找到所有数组中消失的数字
date: 2022-10-20 09:49:10
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, 原地修改, 双指针]
---

# 【LetMeFly】三种方法解决：448.找到所有数组中消失的数字

力扣题目链接：[https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/](https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/)

<p>给你一个含 <code>n</code> 个整数的数组 <code>nums</code> ，其中 <code>nums[i]</code> 在区间 <code>[1, n]</code> 内。请你找出所有在 <code>[1, n]</code> 范围内但没有出现在 <code>nums</code> 中的数字，并以数组的形式返回结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,3,2,7,8,2,3,1]
<strong>输出：</strong>[5,6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1]
<strong>输出：</strong>[2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= n</code></li>
</ul>

<p><strong>进阶：</strong>你能在不使用额外空间且时间复杂度为<em> </em><code>O(n)</code><em> </em>的情况下解决这个问题吗? 你可以假定返回的数组不算在额外空间内。</p>


    
## 方法一：哈希

方法一实现起来很简单，使用一个哈希表存放出现过的元素，再从$1$到$n$遍历一遍看哪个元素没有在哈希表中，哪个元素就“没有出现过”

+ 时间复杂度$O(n)$，其中$n$是数组中元素个数
+ 空间复杂度$O(n)$，空间复杂度主要来自哈希表

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> se;
        for (int& t : nums)
            se.insert(t);
        vector<int> ans;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            if (!se.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};
```

## 方法二：原地修改

方法一的空间复杂度主要来自哈希表

那么想要不额外开辟空间，有种办法就是在原始数组上修改。

如果原始数组中存在$x$，那么我们就把原始数组的第$x$个数变成负数。

这样，我们只需要从第一个数遍历到第$n$个数，看看哪个数是正数（假设是第$a$个），就说$a$没有在数组中出现过。

但是代价是，我们修改了原始数组！！！

+ 时间复杂度$O(n)$，其中$n$是数组中元素个数
+ 空间复杂度$O(1)$，如果原始数组不允许修改，则此方法无效

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int& t : nums) {
            int loc = abs(t) - 1;
            nums[loc] = -abs(nums[loc]);
        }
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};
```

## 方法三：双指针

不如给原始数组排个序，然后用一个“指针”指向数组中处理过的元素，另一个“指针”从“1”指到“n”

指针二从1到n遍历，当指针一所指位置合法并且所指元素小于指针二时，指针一后移

接着判断指针一所指是否和指针二相同，相同则表示指针二所指出现过，否则表示没有出现过

+ 时间复杂度$O(n\log n)$，其中$n$是数组中元素个数
+ 空间复杂度$O(\log n)$，空间复杂度来源主要是排序

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        int loc = 0;
        for (int to = 1; to <= n; to++) {
            while (loc < n && nums[loc] < to)
                loc++;
            if (loc == n || nums[loc] != to)
                ans.push_back(to);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/20/LeetCode%200448.%E6%89%BE%E5%88%B0%E6%89%80%E6%9C%89%E6%95%B0%E7%BB%84%E4%B8%AD%E6%B6%88%E5%A4%B1%E7%9A%84%E6%95%B0%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127421428](https://letmefly.blog.csdn.net/article/details/127421428)
