---
title: 2034.股票价格波动
date: 2023-10-08 12:36:36
tags: [题解, LeetCode, 中等, 设计, 哈希表, 数据流, 有序集合, 堆（优先队列）, set, map]
---

# 【LetMeFly】2034.股票价格波动：哈希表 + 有序集合

力扣题目链接：[https://leetcode.cn/problems/stock-price-fluctuation/](https://leetcode.cn/problems/stock-price-fluctuation/)

<p>给你一支股票价格的数据流。数据流中每一条记录包含一个 <strong>时间戳</strong>&nbsp;和该时间点股票对应的 <strong>价格</strong>&nbsp;。</p>

<p>不巧的是，由于股票市场内在的波动性，股票价格记录可能不是按时间顺序到来的。某些情况下，有的记录可能是错的。如果两个有相同时间戳的记录出现在数据流中，前一条记录视为错误记录，后出现的记录 <b>更正</b>&nbsp;前一条错误的记录。</p>

<p>请你设计一个算法，实现：</p>

<ul>
	<li><strong>更新 </strong>股票在某一时间戳的股票价格，如果有之前同一时间戳的价格，这一操作将&nbsp;<strong>更正</strong>&nbsp;之前的错误价格。</li>
	<li>找到当前记录里 <b>最新股票价格</b>&nbsp;。<strong>最新股票价格</strong>&nbsp;定义为时间戳最晚的股票价格。</li>
	<li>找到当前记录里股票的 <strong>最高价格</strong>&nbsp;。</li>
	<li>找到当前记录里股票的 <strong>最低价格</strong>&nbsp;。</li>
</ul>

<p>请你实现&nbsp;<code>StockPrice</code>&nbsp;类：</p>

<ul>
	<li><code>StockPrice()</code>&nbsp;初始化对象，当前无股票价格记录。</li>
	<li><code>void update(int timestamp, int price)</code>&nbsp;在时间点 <code>timestamp</code>&nbsp;更新股票价格为 <code>price</code>&nbsp;。</li>
	<li><code>int current()</code>&nbsp;返回股票 <strong>最新价格</strong>&nbsp;。</li>
	<li><code>int maximum()</code>&nbsp;返回股票 <strong>最高价格</strong>&nbsp;。</li>
	<li><code>int minimum()</code>&nbsp;返回股票 <strong>最低价格</strong>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
[[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
<strong>输出：</strong>
[null, null, null, 5, 10, null, 5, null, 2]

<strong>解释：</strong>
StockPrice stockPrice = new StockPrice();
stockPrice.update(1, 10); // 时间戳为 [1] ，对应的股票价格为 [10] 。
stockPrice.update(2, 5);  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
stockPrice.current();     // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
stockPrice.maximum();     // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
stockPrice.update(1, 3);  // 之前时间戳为 1 的价格错误，价格更新为 3 。
                          // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
stockPrice.maximum();     // 返回 5 ，更正后最高价格为 5 。
stockPrice.update(4, 2);  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
stockPrice.minimum();     // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= timestamp, price &lt;= 10<sup>9</sup></code></li>
	<li><code>update</code>，<code>current</code>，<code>maximum</code>&nbsp;和&nbsp;<code>minimum</code>&nbsp;<strong>总</strong> 调用次数不超过&nbsp;<code>10<sup>5</sup></code>&nbsp;。</li>
	<li><code>current</code>，<code>maximum</code>&nbsp;和&nbsp;<code>minimum</code>&nbsp;被调用时，<code>update</code>&nbsp;操作 <strong>至少</strong>&nbsp;已经被调用过 <strong>一次</strong>&nbsp;。</li>
</ul>


    
## 方法一：哈希表 + 有序集合

只需要维护三个变量：

+ 哈希表```ma```用来将```时间戳```映射为```价格```
+ 有序集合```se```（例如C++的multiset）用来存储所有的股票价格
+ 整数```Mtime```用来存最新的时间戳

那么：

+ 对于```update```操作，如果哈希表```ma```中已经存在了这个时间戳，就删除有序集合```se```中这个时间戳对应的价格。然后更新```ma```、```se```和```Mtime```
+ 对于```current```操作，直接返回哈希表```ma```中最新时间戳```Mtime```对应的价格
+ 对于```maximum```操作，直接返回有序集合```se```中的最后一个元素
+ 对于```minimum```操作，直接返回有序集合```se```中的第一个元素

完毕。

+ 时间复杂度：单次操作涉及有序集合增删的复杂的为$O(\log n)$，否则复杂度为$O(1)$
+ 空间复杂度：$O(n)$，其中$n$是不用的时间戳数量

### AC代码

#### C++

```cpp
class StockPrice {
private:
    unordered_map<int, int> ma;
    multiset<int> se;
    int Mtime;
public:
    StockPrice() {
        Mtime = 0;
    }
    
    void update(int timestamp, int price) {
        if (ma.count(timestamp)) {
            se.erase(se.find(ma[timestamp]));
        }
        ma[timestamp] = price;
        se.insert(price);
        Mtime = max(Mtime, timestamp);
    }
    
    int current() {
        return ma[Mtime];
    }
    
    int maximum() {
        return *se.rbegin();
    }
    
    int minimum() {
        return *se.begin();
    }
};
```

#### Python

```python
# from sortedcontainers import SortedList


class StockPrice:

    def __init__(self):
        self.ma = {}
        self.se = SortedList()
        self.Mtime = 0


    def update(self, timestamp: int, price: int) -> None:
        if timestamp in self.ma:
            self.se.discard(self.ma[timestamp])
        self.ma[timestamp] = price
        self.se.add(price)
        self.Mtime = max(self.Mtime, timestamp)


    def current(self) -> int:
        return self.ma[self.Mtime]


    def maximum(self) -> int:
        return self.se[-1]


    def minimum(self) -> int:
        return self.se[0]

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/08/LeetCode%202034.%E8%82%A1%E7%A5%A8%E4%BB%B7%E6%A0%BC%E6%B3%A2%E5%8A%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133677649](https://letmefly.blog.csdn.net/article/details/133677649)