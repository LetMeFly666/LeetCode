---
title: 729.我的日程安排表 I
date: 2025-01-02 16:33:43
tags: [题解, LeetCode, 中等, 设计, 线段树, 数组, 二分查找, 有序集合, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】729.我的日程安排表 I：既然是I，那就暴力模拟

力扣题目链接：[https://leetcode.cn/problems/my-calendar-i/](https://leetcode.cn/problems/my-calendar-i/)

<p>实现一个 <code>MyCalendar</code> 类来存放你的日程安排。如果要添加的日程安排不会造成 <strong>重复预订</strong> ，则可以存储这个新的日程安排。</p>

<p>当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生 <strong>重复预订</strong> 。</p>

<p>日程可以用一对整数 <code>startTime</code> 和 <code>endTime</code> 表示，这里的时间是半开区间，即 <code>[startTime, endTime)</code>, 实数&nbsp;<code>x</code> 的范围为， &nbsp;<code>startTime &lt;= x &lt; endTime</code> 。</p>

<p>实现 <code>MyCalendar</code> 类：</p>

<ul>
	<li><code>MyCalendar()</code> 初始化日历对象。</li>
	<li><code>boolean book(int startTime, int endTime)</code> 如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 <code>true</code> 。否则，返回 <code>false</code>&nbsp;并且不要将该日程安排添加到日历中。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<pre>
<strong>输入：</strong>
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
<strong>输出：</strong>
[null, true, false, true]

<strong>解释：</strong>
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False ，这个日程安排不能添加到日历中，因为时间 15 已经被另一个日程安排预订了。
myCalendar.book(20, 30); // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于 20 ，且不包含时间 20 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= start &lt; end &lt;= 10<sup>9</sup></code></li>
	<li>每个测试用例，调用 <code>book</code> 方法的次数最多不超过 <code>1000</code> 次。</li>
</ul>


    
## 解题方法：模拟

这道题是“日程安排**I**”，数据量是$10^3$量级的，$O(n^2)$时间复杂度的算法就能过。因此直接模拟就好了。

使用一个数组或两个数组记录每次成功被预定的起止时间，对于一个新的预定，如果与历史上每个起止时间都不冲突，则记入预定数组并返回`true`；否则返回`false`。

对于起止时间是`[s1, e1)`和`[s2, e2)`两个时间段，如何判断二者是否有冲突？

> 如果`e1 > s2 且 e2 > s1`则有冲突。
>
> 如果不理解，也可以使用下面是思路逆向推导：
>
> 两端时间没有交集说明`s1 >= e2 或 s2 >= e1`，对其取非就是了。

+ 时间复杂度$O(n^2)$，其中$n$是调用总次数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-02 16:13:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-02 16:15:23
 */
class MyCalendar {
private:
    vector<int> start, end;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (int i = 0; i < start.size(); i++) {
            if (!(end[i] <= startTime || endTime <= start[i])) {
                return false;
            }
        }
        start.push_back(startTime);
        end.push_back(endTime);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-02 16:16:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-02 16:22:15
'''
# 产生交集：!(e1 <= s2 || e2 <= s1) 等价于 e1 > s2 && e2 > s1
class MyCalendar:

    def __init__(self):
        self.bookList = []

    def book(self, startTime: int, endTime: int) -> bool:
        if any(e > startTime and endTime > s for s, e in self.bookList):
            return False
        self.bookList.append((startTime, endTime))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-02 16:22:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-02 16:27:07
 */
import java.util.ArrayList;

class MyCalendar {
    private ArrayList<Integer> start, end;

    public MyCalendar() {
        start = new ArrayList<Integer>();
        end = new ArrayList<Integer>();
    }
    
    public boolean book(int startTime, int endTime) {
        for (int i = 0; i < start.size(); i++) {
            if (end.get(i) > startTime && endTime > start.get(i)) {
                return false;
            }
        }
        start.add(startTime);
        end.add(endTime);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(startTime,endTime);
 */
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-02 16:27:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-02 16:32:36
 */
package main

type pair struct{ start, end int }
type MyCalendar []pair


func Constructor() MyCalendar {
    return MyCalendar{}
}


func (this *MyCalendar) Book(startTime int, endTime int) bool {
    for _, p := range *this {
        if endTime > p.start && p.end > startTime {
            return false
        }
    }
    *this = append(*this, pair{startTime, endTime})
    return true
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(startTime,endTime);
 */
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/02/LeetCode%200729.%E6%88%91%E7%9A%84%E6%97%A5%E7%A8%8B%E5%AE%89%E6%8E%92%E8%A1%A8I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144889921](https://letmefly.blog.csdn.net/article/details/144889921)
