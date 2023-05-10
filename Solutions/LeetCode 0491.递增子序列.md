---
title: 491.递增子序列
date: 2022-11-02 10:55:59
tags: [题解, LeetCode, 中等, 位运算, 数组, 哈希表, 回溯, 二进制枚举, 状态压缩, 深度优先搜索, DFS]
---

# 【LetMeFly】491.递增子序列：两大方法三小方法

力扣题目链接：[https://leetcode.cn/problems/increasing-subsequences/](https://leetcode.cn/problems/increasing-subsequences/)

<p>给你一个整数数组 <code>nums</code> ，找出并返回所有该数组中不同的递增子序列，递增子序列中 <strong>至少有两个元素</strong> 。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,6,7,7]
<strong>输出：</strong>[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,4,3,2,1]
<strong>输出：</strong>[[4,4]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 15</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 方法一：二进制枚举

二进制枚举每一种子序列，然后判断这个子序列是否合法，如果合法就添加到答案中

其中二进制的每一位对应原始数组中的一个元素，这一位为0则不取这个元素，否则取这个元素。

主要答案需要去重，可以使用自带哈希表

+ 时间复杂度$O(2^n\times n)$，二进制枚举的时间复杂度是$2^n$；哈希表中最大元素个数为$2^n$，此时一次插入的时间复杂度是$\log 2^n=n\times log2\to n$
+ 空间复杂度$O(2^n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // unordered_set<vector<int>, VectorHash, VectorEqual> se;
        set<vector<int>> se;
        int n = nums.size(), to = 1 << n;
        for (int i = 0; i < to; i++) {
            int last = -100;
            vector<int> thisV;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (nums[j] < last)
                        goto loop;
                    thisV.push_back(nums[j]);
                    last = nums[j];
                }
            }
            if (thisV.size() > 1)
                se.insert(thisV);
            loop:;
        }
        vector<vector<int>> ans;
        for (auto& v : se)
            ans.push_back(v);
        return ans;
    }
};
```

## 方法一.2：针对方法一中哈希表的优化

与方法一相比，我们使用$unordered_set$，这样插入的效率会变高。

但是$C++$的$STL$默认没有$vector$的哈希函数，需要我们自定义$vector$的哈希函数或者将$vector$映射为整数，同时将整数映射为$vector$

具体映射方法为：

> 因为vector中每个数的取值范围是$[-100, 100]$，所以我们可以将每个数加上$100$，这样每个数的取值范围就是$[1, 201]$一共$201$种。使用无符号整数每次乘以$201$后加上新的数 自然溢出，发现对于力扣此题没有产生哈希冲突。

+ 时间复杂度$O(2^n\times n)$，unordered_set的插入时间复杂度是$O(1)$，但是需要遍历最大长度为$n$的数组来求得哈希值
+ 空间复杂度$O(2^n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<unsigned, vector<int>> ma;

    unsigned hash(vector<int>& v) {
        unsigned ans = 0;  // 32位无符号整数自然溢出
        for (int& t : v) {
            ans = ans * 201 + (t + 101);  // t + 101 -> [1, 201]  // +100不可以！！！会冲突  // 如果+100的话，[-100, 5]和[5]都会是105
        }
        ma[ans] = v;
        return ans;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // unordered_set<vector<int>, VectorHash, VectorEqual> se;
        unordered_set<int> se;
        int n = nums.size(), to = 1 << n;
        for (int i = 0; i < to; i++) {
            int last = -100;
            vector<int> thisV;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (nums[j] < last)
                        goto loop;
                    thisV.push_back(nums[j]);
                    last = nums[j];
                }
            }
            if (thisV.size() > 1)
                se.insert(hash(thisV));
            loop:;
        }
        vector<vector<int>> ans;
        for (auto& t : se)
            ans.push_back(ma[t]);
        return ans;
    }
};
```

## 方法三：深度优先搜索DFS

我们用函数```dfs(nums, loc, lastNum)```来计算$nums$数组从$loc$开始，上一个数是$lastNum$的所有可行方案

用一个临时数组$temp$来存放当前方案

如果$loc == nums.size()$（已经超出有效范围了），那么就看$temp$中存放的方案是否合法（至少两个数），如果合法就添加到答案中。

如果$loc < nums.size()$，那么就有“选nums[loc]”和“不选nums[loc]”两种方案。“选nums[loc]”的前提是$nums[loc] >= lastNum$。

如果选择$nums[loc]$，那么就将$nums[loc]$添加到临时数组中，递归深搜，返回时再将其从临时数组的末尾移除。

如果不选择$nums[loc]$，那么当且仅当$nums[loc] \neq lastNum$时才进行深搜，因为前面的$lastNum$和$nums[loc]$相等，所以“选了lastNum不选nums[loc]”和“选了nums[loc]不选lastNum”是等价的，不选择$nums[loc]$而仍然递归深搜会导致答案重复。


+ 时间复杂度$O(2^n\times n)$
+ 空间复杂度$O(n)$，临时数组和递归消耗的空间复杂度都是$(n)$

虽然时间复杂度看似和方法一相同，但实际执行效率还是要高一些。

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<unsigned, vector<int>> ma;

    unsigned hash(vector<int>& v) {
        unsigned ans = 0;  // 32位无符号整数自然溢出
        for (int& t : v) {
            ans = ans * 201 + (t + 101);  // t + 101 -> [1, 201]  // +100不可以！！！会冲突  // 如果+100的话，[-100, 5]和[5]都会是105
        }
        ma[ans] = v;
        return ans;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // unordered_set<vector<int>, VectorHash, VectorEqual> se;
        unordered_set<int> se;
        int n = nums.size(), to = 1 << n;
        for (int i = 0; i < to; i++) {
            int last = -100;
            vector<int> thisV;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (nums[j] < last)
                        goto loop;
                    thisV.push_back(nums[j]);
                    last = nums[j];
                }
            }
            if (thisV.size() > 1)
                se.insert(hash(thisV));
            loop:;
        }
        vector<vector<int>> ans;
        for (auto& t : se)
            ans.push_back(ma[t]);
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/02/LeetCode%200491.%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127649530](https://letmefly.blog.csdn.net/article/details/127649530)
