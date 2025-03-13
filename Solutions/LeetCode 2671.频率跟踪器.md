---
title: 2671.频率跟踪器
date: 2024-03-21 22:28:49
tags: [题解, LeetCode, 中等, 设计, 哈希表, 哈希, map]
categories: [题解, LeetCode]
---

# 【LetMeFly】2671.频率跟踪器：俩计数哈希表

力扣题目链接：[https://leetcode.cn/problems/frequency-tracker/](https://leetcode.cn/problems/frequency-tracker/)

<p>请你设计并实现一个能够对其中的值进行跟踪的数据结构，并支持对频率相关查询进行应答。</p>

<p>实现 <code>FrequencyTracker</code> 类：</p>

<ul>
	<li><code>FrequencyTracker()</code>：使用一个空数组初始化 <code>FrequencyTracker</code> 对象。</li>
	<li><code>void add(int number)</code>：添加一个 <code>number</code> 到数据结构中。</li>
	<li><code>void deleteOne(int number)</code>：从数据结构中删除一个 <code>number</code> 。数据结构 <strong>可能不包含</strong> <code>number</code> ，在这种情况下不删除任何内容。</li>
	<li><code>bool hasFrequency(int frequency)</code>: 如果数据结构中存在出现 <code>frequency</code> 次的数字，则返回 <code>true</code>，否则返回 <code>false</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入</strong>
["FrequencyTracker", "add", "add", "hasFrequency"]
[[], [3], [3], [2]]
<strong>输出</strong>
[null, null, null, true]

<strong>解释</strong>
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(3); // 数据结构现在包含 [3]
frequencyTracker.add(3); // 数据结构现在包含 [3, 3]
frequencyTracker.hasFrequency(2); // 返回 true ，因为 3 出现 2 次
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入</strong>
["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
[[], [1], [1], [1]]
<strong>输出</strong>
[null, null, null, false]

<strong>解释</strong>
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(1); // 数据结构现在包含 [1]
frequencyTracker.deleteOne(1); // 数据结构现在为空 []
frequencyTracker.hasFrequency(1); // 返回 false ，因为数据结构为空
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入</strong>
["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
[[], [2], [3], [1]]
<strong>输出</strong>
[null, false, null, true]

<strong>解释</strong>
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.hasFrequency(2); // 返回 false ，因为数据结构为空
frequencyTracker.add(3); // 数据结构现在包含 [3]
frequencyTracker.hasFrequency(1); // 返回 true ，因为 3 出现 1 次
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= number &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= frequency &lt;= 10<sup>5</sup></code></li>
	<li>最多调用 <code>add</code>、<code>deleteOne</code> 和 <code>hasFrequency</code> <strong>共计</strong> <code>2 *&nbsp;10<sup>5</sup></code> 次</li>
</ul>


    
## 方法一：俩计数哈希表

+ 使用一个哈希表```val2times```记录值```val```一共出现了多少次。
+ 使用一个哈希表```times2times```记录```val2times```中的每个```times```一共出现了多少次。

添加或删除元素时，更新```val2times[val]```的值，并更新```times2times[val2times[val] (+diff)]```的值。

询问是否存在出现了```frequency```次的数字时，直接返回```times2times[frequency]```是否非零。

+ 时间复杂度$O(1)/操作$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class FrequencyTracker {
private:
    unordered_map<int, int> val2times, times2times;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number, int diff=1) {
        int originalTimes = val2times[number];
        val2times[number] += diff;
        times2times[originalTimes]--;
        times2times[originalTimes + diff]++;
    }
    
    void deleteOne(int number) {
        if (val2times[number]) {
            add(number, -1);
        }
    }
    
    bool hasFrequency(int frequency) {
        return times2times[frequency];
    }
};
```

#### Python

```python
# from collections import defaultdict

class FrequencyTracker:

    def __init__(self):
        self.val2times = defaultdict(int)
        self.times2times = defaultdict(int)

    def add(self, number: int, diff=1) -> None:
        originalTimes = self.val2times[number]
        self.val2times[number] += diff
        self.times2times[originalTimes] -= 1
        self.times2times[originalTimes + diff] += 1

    def deleteOne(self, number: int) -> None:
        if self.val2times[number]:
            self.add(number, -1)

    def hasFrequency(self, frequency: int) -> bool:
        return self.times2times[frequency] != 0
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/21/LeetCode%202671.%E9%A2%91%E7%8E%87%E8%B7%9F%E8%B8%AA%E5%99%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136922983](https://letmefly.blog.csdn.net/article/details/136922983)
