---
title: 732.我的日程安排表 III
date: 2025-01-05 22:01:14
tags: [题解, LeetCode, 困难, 设计, 线段树, 二分查找, 有序集合, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】732.我的日程安排表 III：线段树

力扣题目链接：[https://leetcode.cn/problems/my-calendar-iii/](https://leetcode.cn/problems/my-calendar-iii/)

<p>当 <code>k</code> 个日程存在一些非空交集时（即, <code>k</code> 个日程包含了一些相同时间），就会产生 <code>k</code> 次预订。</p>

<p>给你一些日程安排 <code>[startTime, endTime)</code> ，请你在每个日程安排添加后，返回一个整数 <code>k</code> ，表示所有先前日程安排会产生的最大 <code>k</code> 次预订。</p>

<p>实现一个 <code>MyCalendarThree</code> 类来存放你的日程安排，你可以一直添加新的日程安排。</p>

<ul>
	<li><code>MyCalendarThree()</code> 初始化对象。</li>
	<li><code>int book(int startTime, int endTime)</code> 返回一个整数 <code>k</code> ，表示日历中存在的 <code>k</code> 次预订的最大值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
<strong>输出：</strong>
[null, 1, 1, 2, 3, 3, 3]

<strong>解释：</strong>
MyCalendarThree myCalendarThree = new MyCalendarThree();
myCalendarThree.book(10, 20); // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
myCalendarThree.book(50, 60); // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
myCalendarThree.book(5, 10); // 返回 3
myCalendarThree.book(25, 55); // 返回 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= startTime &lt; endTime &lt;= 10<sup>9</sup></code></li>
	<li>每个测试用例，调用 <code>book</code>&nbsp;函数最多不超过&nbsp;<code>400</code>次</li>
</ul>


    
## 解题方法：线段树

离散化线段树，tree记录区间最大值，lazy懒标记区间的累加次数。

+ 时间复杂度$O(n\log C)$，线段树最大深度为$\log C$，其中$C=10^9$
+ 空间复杂度$O(n\log C)$，每次预定最多新增$\log C$个节点

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-05 21:26:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-05 21:33:46
 */
class MyCalendarThree {
private:
    unordered_map<int, int> tree, lazy;

    void update(int start, int end, int index, int l, int r) {
        if (start > r || l > end) {
            return;
        }
        if (l >= start && r <= end) {
            tree[index]++;
            lazy[index]++;
        } else {
            int mid = (l + r) >> 1;
            update(start, end, index * 2 + 1, l, mid);
            update(start, end, index * 2 + 2, mid + 1, r);
            tree[index] = lazy[index] + max(tree[index * 2 + 1], tree[index * 2 + 2]);
        }
    }
public:
    MyCalendarThree() {}
    
    int book(int startTime, int endTime) {
        update(startTime, endTime - 1, 0, 0, 1000000000);
        return tree[0];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-05 21:34:19
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-05 21:38:20
'''
from collections import defaultdict

class MyCalendarThree:

    def __init__(self):
        self.tree = defaultdict(int)
        self.lazy = defaultdict(int)

    def update(self, start: int, end: int, index: int, l: int, r: int) -> None:
        if l > end or start > r:
            return
        if start <= l and r <= end:
            self.tree[index] += 1
            self.lazy[index] += 1
        else:
            mid = (l + r) >> 1
            self.update(start, end, index * 2 + 1, l, mid)
            self.update(start, end, index * 2 + 2, mid + 1, r)
            self.tree[index] = self.lazy[index] + max(self.tree[index * 2 + 1], self.tree[index * 2 + 2])

    def book(self, startTime: int, endTime: int) -> int:
        self.update(startTime, endTime - 1, 0, 0, 1000000000)
        return self.tree[0]


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(startTime,endTime)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-05 21:39:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-05 21:44:12
 */
import java.util.HashMap;

class MyCalendarThree {
    private HashMap<Integer, Integer> tree, lazy;

    private void update(int start, int end, int index, int l, int r) {
        if (l > end || start > r) {
            return;
        }
        if (l >= start && r <= end) {
            tree.put(index, tree.getOrDefault(index, 0) + 1);
            lazy.put(index, lazy.getOrDefault(index, 0) + 1);
        } else {
            int mid = (l + r) >> 1;
            update(start, end, index * 2 + 1, l, mid);
            update(start, end, index * 2 + 2, mid + 1, r);
            tree.put(index, lazy.getOrDefault(index, 0) + Math.max(tree.getOrDefault(index * 2 + 1, 0), tree.getOrDefault(index * 2 + 2, 0)));
        }
    }

    public MyCalendarThree() {
        tree = new HashMap<Integer, Integer>();
        lazy = new HashMap<Integer, Integer>();
    }
    
    public int book(int startTime, int endTime) {
        update(startTime, endTime - 1, 0, 0, 1000000000);
        return tree.get(0);
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(startTime,endTime);
 */
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-05 21:45:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-05 21:57:58
 */
package main

type pair_myCalendarIII struct {num, lazy int}
type MyCalendarThree map[int]pair_myCalendarIII

func max_MC3(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func Constructor() MyCalendarThree {
    return MyCalendarThree{}
}

func (this MyCalendarThree) update(start, end, index, l, r int) {
    if l > end || start > r {
        return
    }
    if l >= start && r <= end {
        p := this[index]
        p.num++  // 不可直接this[index].num++
        p.lazy++
        this[index] = p
    } else {
        mid := (l + r) >> 1
        this.update(start, end, index * 2 + 1, l, mid)
        this.update(start, end, index * 2 + 2, mid + 1, r)
        p := this[index]
        p.num = this[index].lazy + max_MC3(this[index * 2 + 1].num, this[index * 2 + 2].num)
        this[index] = p
    }
}

func (this MyCalendarThree) Book(startTime int, endTime int) int {
    this.update(startTime, endTime - 1, 0, 0, 1000000000)
    return this[0].num
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(startTime,endTime);
 */
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/05/LeetCode%200732.%E6%88%91%E7%9A%84%E6%97%A5%E7%A8%8B%E5%AE%89%E6%8E%92%E8%A1%A8III/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144951803](https://letmefly.blog.csdn.net/article/details/144951803)
