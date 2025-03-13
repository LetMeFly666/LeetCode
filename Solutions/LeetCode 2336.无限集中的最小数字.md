---
title: 2336.无限集中的最小数字
date: 2023-11-29 12:24:24
tags: [题解, LeetCode, 中等, 设计, 哈希表, 堆（优先队列）, 有序集合, set]
categories: [题解, LeetCode]
---

# 【LetMeFly】2336.无限集中的最小数字：有序集合

力扣题目链接：[https://leetcode.cn/problems/smallest-number-in-infinite-set/](https://leetcode.cn/problems/smallest-number-in-infinite-set/)

<p>现有一个包含所有正整数的集合 <code>[1, 2, 3, 4, 5, ...]</code> 。</p>

<p>实现 <code>SmallestInfiniteSet</code> 类：</p>

<ul>
	<li><code>SmallestInfiniteSet()</code> 初始化 <strong>SmallestInfiniteSet</strong> 对象以包含 <strong>所有</strong> 正整数。</li>
	<li><code>int popSmallest()</code> <strong>移除</strong> 并返回该无限集中的最小整数。</li>
	<li><code>void addBack(int num)</code> 如果正整数 <code>num</code> <strong>不</strong> 存在于无限集中，则将一个 <code>num</code> <strong>添加</strong> 到该无限集中。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入</strong>
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
<strong>输出</strong>
[null, null, 1, 2, 3, null, 1, 4, 5]

<strong>解释</strong>
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 已经在集合中，所以不做任何变更。
smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 是最小的整数，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 2 ，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 3 ，并将其从集合中移除。
smallestInfiniteSet.addBack(1);    // 将 1 添加到该集合中。
smallestInfiniteSet.popSmallest(); // 返回 1 ，因为 1 在上一步中被添加到集合中，
                                   // 且 1 是最小的整数，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 4 ，并将其从集合中移除。
smallestInfiniteSet.popSmallest(); // 返回 5 ，并将其从集合中移除。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 1000</code></li>
	<li>最多调用 <code>popSmallest</code> 和 <code>addBack</code> 方法 <strong>共计</strong> <code>1000</code> 次</li>
</ul>


    
## 方法一：有序集合

使用一个整数continuousSmallest记录“连续的正整数的最小值”（初始值为1）；使用一个有序集合记录新插入的比continuousSmallest还小的整数。

+ 移除整数时，若有序集合非空，则返回有序集合中第一个元素（最小的元素）；否则，返回continuousSmallest并令其加一
+ 加入整数时，若待加整数大于等于continuousSmallest，则忽略；否则，往有序集合中插入这个元素

以上。

+ 时间复杂度$O(1)$或$O(\log n)。若没涉及到集合，则时间复杂度为$O(1)$，否则为$O(\log n)$
+ 空间复杂度$O(n)。实际大小为集合中同时存在的最多元素个数。（插入的数小于最小连续整数）

### AC代码

#### C++

```cpp
class SmallestInfiniteSet {
private:
    int continuousSmallest;
    set<int> added;
public:
    SmallestInfiniteSet() {
        continuousSmallest = 1;
    }
    
    int popSmallest() {
        if (added.size()) {
            int ans = *added.begin();
            added.erase(added.begin());
            return ans;
        }
        return continuousSmallest++;
    }
    
    void addBack(int num) {
        if (num >= continuousSmallest) {
            return;
        }
        added.insert(num);
    }
};
```

#### Python

```python
from sortedcontainers import SortedSet 
# sortedcontainers不是Python自带的，需要pip install
# 力扣中默认不具有此函数，因此不能被注释掉

class SmallestInfiniteSet:

    def __init__(self):
        self.continuousSmallest = 1
        self.added = SortedSet()


    def popSmallest(self) -> int:
        if self.added:
            return -self.added.pop()
        self.continuousSmallest += 1
        return self.continuousSmallest - 1


    def addBack(self, num: int) -> None:
        if num >= self.continuousSmallest:
            return
        self.added.add(-num)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/29/LeetCode%202336.%E6%97%A0%E9%99%90%E9%9B%86%E4%B8%AD%E7%9A%84%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134687046](https://letmefly.blog.csdn.net/article/details/134687046)
