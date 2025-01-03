---
title: 731.我的日程安排表 II
date: 2025-01-03 13:38:36
tags: [题解, LeetCode, 中等, 设计, 线段树, 数组, 二分查找, 有序集合, 前缀和]
---

# 【LetMeFly】731.我的日程安排表 II：既然是II，那就继续暴力模拟

力扣题目链接：[https://leetcode.cn/problems/my-calendar-ii/](https://leetcode.cn/problems/my-calendar-ii/)

<p>实现一个程序来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。</p>

<p>当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生 <strong>三重预订</strong>。</p>

<p>事件能够用一对整数&nbsp;<code>startTime</code>&nbsp;和&nbsp;<code>endTime</code>&nbsp;表示，在一个半开区间的时间&nbsp;<code>[startTime, endTime)</code>&nbsp;上预定。实数&nbsp;<code>x</code> 的范围为&nbsp;&nbsp;<code>startTime &lt;= x &lt; endTime</code>。</p>

<p>实现&nbsp;<code>MyCalendarTwo</code> 类：</p>

<ul>
	<li><code>MyCalendarTwo()</code>&nbsp;初始化日历对象。</li>
	<li><code>boolean book(int startTime, int endTime)</code>&nbsp;如果可以将日程安排成功添加到日历中而不会导致三重预订，返回 <code>true</code>。否则，返回 <code>false</code> 并且不要将该日程安排添加到日历中。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
<strong>输出：</strong>
[null, true, true, true, false, true, true]

<strong>解释：</strong>
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // 返回 True，能够预定该日程。
myCalendarTwo.book(50, 60); // 返回 True，能够预定该日程。
myCalendarTwo.book(10, 40); // 返回 True，该日程能够被重复预定。
myCalendarTwo.book(5, 15);  // 返回 False，该日程导致了三重预定，所以不能预定。
myCalendarTwo.book(5, 10); // 返回 True，能够预定该日程，因为它不使用已经双重预订的时间 10。
myCalendarTwo.book(25, 55); // 返回 True，能够预定该日程，因为时间段 [25, 40) 将被第三个日程重复预定，时间段 [40, 50) 将被单独预定，而时间段 [50, 55) 将被第二个日程重复预定。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= start &lt; end &lt;= 10<sup>9</sup></code></li>
	<li>最多调用&nbsp;<code>book</code>&nbsp;1000 次。</li>
</ul>


    
## 解题方法：记录二重叠时间，判断是否有交集

在[LeetCode 729.我的日程安排表 I](https://blog.letmefly.xyz/2025/01/02/LeetCode%200729.%E6%88%91%E7%9A%84%E6%97%A5%E7%A8%8B%E5%AE%89%E6%8E%92%E8%A1%A8I/#%E8%A7%A3%E9%A2%98%E6%96%B9%E6%B3%95%EF%BC%9A%E6%A8%A1%E6%8B%9F)中得知：对于起止时间是`[s1, e1)`和`[s2, e2)`两个时间段，如果`e1 > s2 且 e2 > s1`则两个时间段有重叠。

因此我们可以额外开辟一个数组记录“重叠时间”`[max(s1, s2), min(e1, e2))`，在新增订阅需求时判断这个订阅是否和“重叠时间”有重叠。

若有则会产生“三重预订”，直接返回`false`；若无则将新预定时间添加到预定数组中，并且将新预定时间段与旧预定时间段产生的“二重重叠”添加到“重叠时间数组”中。

+ 时间复杂度$O(n^2)$，其中$n$是调用总次数
+ 空间复杂度$O(n)$

在力扣题库中搜了一下发现还有III，因此决定在[LeetCode 732.我的日程安排表 III](https://blog.letmefly.xyz/2025/01/04/LeetCode%200732.%E6%88%91%E7%9A%84%E6%97%A5%E7%A8%8B%E5%AE%89%E6%8E%92%E8%A1%A8III)中再使用线段树。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-03 13:06:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-03 13:11:02
 */
class MyCalendarTwo {
private:
    vector<int> booked_start, booked_end, overlap_start, overlap_end;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (int i = 0; i < overlap_start.size(); i++) {
            if (endTime > overlap_start[i] && overlap_end[i] > startTime) {
                return false;
            }
        }
        for (int i = 0; i < booked_start.size(); i++) {
            if (endTime > booked_start[i] && booked_end[i] > startTime) {
                overlap_start.push_back(max(startTime, booked_start[i]));
                overlap_end.push_back(min(endTime, booked_end[i]));
            }
        }
        booked_start.push_back(startTime);
        booked_end.push_back(endTime);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-03 13:11:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-03 13:16:04
'''
class MyCalendarTwo:

    def __init__(self):
        self.booked = []
        self.overlap = []

    def book(self, startTime: int, endTime: int) -> bool:
        if any(endTime > s and e > startTime for s, e in self.overlap):
            return False
        for s, e in self.booked:
            if endTime > s and e > startTime:
                self.overlap.append((max(startTime, s), min(endTime, e)))
        self.booked.append((startTime, endTime))
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(startTime,endTime)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-03 13:17:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-03 13:21:03
 */
import java.util.ArrayList;

class MyCalendarTwo {
    private ArrayList<Integer> booked_start, booked_end, overlap_start, overlap_end;

    public MyCalendarTwo() {
        booked_start = new ArrayList<>();
        booked_end = new ArrayList<>();
        overlap_start = new ArrayList<>();
        overlap_end = new ArrayList<>();
    }
    
    public boolean book(int startTime, int endTime) {
        for (int i = 0; i < overlap_start.size(); i++) {
            if (endTime > overlap_start.get(i) && overlap_end.get(i) > startTime) {
                return false;
            }
        }
        for (int i = 0; i < booked_start.size(); i++) {
            if (endTime > booked_start.get(i) && booked_end.get(i) > startTime) {
                overlap_start.add(Math.max(startTime, booked_start.get(i)));
                overlap_end.add(Math.min(endTime, booked_end.get(i)));
            }
        }
        booked_start.add(startTime);
        booked_end.add(endTime);
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(startTime,endTime);
 */
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-03 13:22:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-03 13:31:46
 */
package main

type pair struct{s, e int}
type MyCalendarTwo struct {booked, overlap []pair}


func Constructor() MyCalendarTwo {
    return MyCalendarTwo{}
}


func (this *MyCalendarTwo) Book(startTime int, endTime int) bool {
    for _, o := range this.overlap {
        if endTime > o.s && o.e > startTime {
            return false
        }
    }
    for _, b := range this.booked {
        if endTime > b.s && b.e > startTime {
            this.overlap = append(this.overlap, pair{max(startTime, b.s), min(endTime, b.e)})
        }
    }
    this.booked = append(this.booked, pair{startTime, endTime})
    return true
}


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(startTime,endTime);
 */
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/03/LeetCode%200731.%E6%88%91%E7%9A%84%E6%97%A5%E7%A8%8B%E5%AE%89%E6%8E%92%E8%A1%A8II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144908626](https://letmefly.blog.csdn.net/article/details/144908626)
