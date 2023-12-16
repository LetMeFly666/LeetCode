---
title: 2276.统计区间中的整数数目
date: 2023-12-16 19:05:54
tags: [题解, LeetCode, 困难, 设计, 线段树, 有序集合]
---

# 【LetMeFly】2276.统计区间中的整数数目

力扣题目链接：[https://leetcode.cn/problems/count-integers-in-intervals/](https://leetcode.cn/problems/count-integers-in-intervals/)

<p>给你区间的 <strong>空</strong> 集，请你设计并实现满足要求的数据结构：</p>

<ul>
	<li><strong>新增：</strong>添加一个区间到这个区间集合中。</li>
	<li><strong>统计：</strong>计算出现在 <strong>至少一个</strong> 区间中的整数个数。</li>
</ul>

<p>实现 <code>CountIntervals</code> 类：</p>

<ul>
	<li><code>CountIntervals()</code> 使用区间的空集初始化对象</li>
	<li><code>void add(int left, int right)</code> 添加区间 <code>[left, right]</code> 到区间集合之中。</li>
	<li><code>int count()</code> 返回出现在 <strong>至少一个</strong> 区间中的整数个数。</li>
</ul>

<p><strong>注意：</strong>区间 <code>[left, right]</code> 表示满足 <code>left &lt;= x &lt;= right</code> 的所有整数 <code>x</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入</strong>
["CountIntervals", "add", "add", "count", "add", "count"]
[[], [2, 3], [7, 10], [], [5, 8], []]
<strong>输出</strong>
[null, null, null, 6, null, 8]

<strong>解释</strong>
CountIntervals countIntervals = new CountIntervals(); // 用一个区间空集初始化对象
countIntervals.add(2, 3);  // 将 [2, 3] 添加到区间集合中
countIntervals.add(7, 10); // 将 [7, 10] 添加到区间集合中
countIntervals.count();    // 返回 6
                           // 整数 2 和 3 出现在区间 [2, 3] 中
                           // 整数 7、8、9、10 出现在区间 [7, 10] 中
countIntervals.add(5, 8);  // 将 [5, 8] 添加到区间集合中
countIntervals.count();    // 返回 8
                           // 整数 2 和 3 出现在区间 [2, 3] 中
                           // 整数 5 和 6 出现在区间 [5, 8] 中
                           // 整数 7 和 8 出现在区间 [5, 8] 和区间 [7, 10] 中
                           // 整数 9 和 10 出现在区间 [7, 10] 中</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>9</sup></code></li>
	<li>最多调用&nbsp; <code>add</code> 和 <code>count</code> 方法 <strong>总计</strong> <code>10<sup>5</sup></code> 次</li>
	<li>调用 <code>count</code> 方法至少一次</li>
</ul>


    
## 方法一：二分

使用一个变量cnt记录区间中的整数个数，使用一个数据结构ma记录所有的区间。其中数据结构要满足：能在$O(\log n)$的时间内找到新区间应插入的位置。

+ 如果询问区间中整数的个数，就直接返回cnt
+ 如果要添加区间$[left, right]$，就在ma中（二分等方式）找到第一个要合并的区间的位置，不断向后遍历，直到区间合并进来为止。
   > 合并过程中记得维持数据结构性质不变、更新区间中整数个数cnt

以上。（本题思路不难，实现起来有很多细节要考虑）

+ 时间复杂度：单次查询操作时间复杂度$O(1)$，单次合并操作时间复杂度平均$O(\log n)$（因为每个区间最多呗背合并一次）
+ 空间复杂度$O(n)$，其中$n$是不同区间的个数

### AC代码

#### C++

```cpp
class CountIntervals {
private:
    map<int, int> ma;
    int cnt;
public:
    CountIntervals() {
        cnt = 0;
    }
    
    void add(int left, int right) {
        map<int, int>::iterator it = ma.upper_bound(right);
        if (it != ma.begin())  {
            it--;
        }
        while (it != ma.end() && it->first <= right && it->second >= left) {
            int leftInmap = it->first, rightInmap = it->second;
            cnt -= rightInmap - leftInmap + 1;
            left = min(left, leftInmap), right = max(right, rightInmap);
            ma.erase(it);
            it = ma.upper_bound(right);
            if (it != ma.begin()) {
                it--;
            }
        }
        ma[left] = right;
        cnt += right - left + 1;
    }
    
    int count() {
        return cnt;
    }
};
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/12/16/LeetCode%202276.%E7%BB%9F%E8%AE%A1%E5%8C%BA%E9%97%B4%E4%B8%AD%E7%9A%84%E6%95%B4%E6%95%B0%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135036679](https://letmefly.blog.csdn.net/article/details/135036679)
