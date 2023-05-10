---
title: 347.前 K 个高频元素
date: 2022-10-01 09:56:36
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, 分治, 桶排序, 计数, 快速选择, 排序, 堆（优先队列）]
---

# 【LetMeFly】347.前 K 个高频元素

力扣题目链接：[https://leetcode.cn/problems/top-k-frequent-elements/](https://leetcode.cn/problems/top-k-frequent-elements/)

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，请你返回其中出现频率前 <code>k</code> 高的元素。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>nums = [1,1,1,2,2,3], k = 2
<strong>输出: </strong>[1,2]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>nums = [1], k = 1
<strong>输出: </strong>[1]</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>k</code> 的取值范围是 <code>[1, 数组中不相同的元素的个数]</code></li>
	<li>题目数据保证答案唯一，换句话说，数组中前 <code>k</code> 个高频元素的集合是唯一的</li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你所设计算法的时间复杂度 <strong>必须</strong> 优于 <code>O(n log n)</code> ，其中 <code>n</code><em> </em>是数组大小。</p>


    
## 方法一：哈希 + 排序

首先用哈希表统计每个数字出现的次数,次操作的总时间复杂度是O$(n)$（一共有$n$个元素）

之后将哈希表中的<数字,出现次数>键值对存入数组中，并对其排序，排序规则是“出现次数大的优先”  $O(n\log n)$

最后，从前到后输出前$k$个排序后的“数字”即可

+ 时间复杂度$O(n\log n)$，其中$n$是元素个数
+ 空间复杂度$O(n)$

运行结果：时间/空间 超越了97.97%,19.06% 的用户

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;

bool cmp(const pii& a, const pii& b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ma;
        for (int& t : nums) {
            ma[t]++;
        }
        vector<pii> v;
        for (auto thisPair : ma) {
            v.push_back(thisPair);
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/01/LeetCode%200347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127131965](https://letmefly.blog.csdn.net/article/details/127131965)
