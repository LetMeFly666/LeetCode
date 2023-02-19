---
title: 1792.最大平均通过率
date: 2023-02-19 21:45:44
tags: [题解, LeetCode, 中等, 贪心, 数组, 堆（优先队列）, 优先队列]
---

# 【LetMeFly】1792.最大平均通过率

力扣题目链接：[https://leetcode.cn/problems/maximum-average-pass-ratio/](https://leetcode.cn/problems/maximum-average-pass-ratio/)

<p>一所学校里有一些班级，每个班级里有一些学生，现在每个班都会进行一场期末考试。给你一个二维数组 <code>classes</code> ，其中 <code>classes[i] = [pass<sub>i</sub>, total<sub>i</sub>]</code> ，表示你提前知道了第 <code>i</code> 个班级总共有 <code>total<sub>i</sub></code> 个学生，其中只有 <code>pass<sub>i</sub></code> 个学生可以通过考试。</p>

<p>给你一个整数 <code>extraStudents</code> ，表示额外有 <code>extraStudents</code> 个聪明的学生，他们 <strong>一定</strong> 能通过任何班级的期末考。你需要给这 <code>extraStudents</code> 个学生每人都安排一个班级，使得 <strong>所有</strong> 班级的 <strong>平均</strong> 通过率 <strong>最大</strong> 。</p>

<p>一个班级的 <strong>通过率</strong> 等于这个班级通过考试的学生人数除以这个班级的总人数。<strong>平均通过率</strong> 是所有班级的通过率之和除以班级数目。</p>

<p>请你返回在安排这 <code><span style="">extraStudents</span></code> 个学生去对应班级后的 <strong>最大</strong> 平均通过率。与标准答案误差范围在 <code>10<sup>-5</sup></code> 以内的结果都会视为正确结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>classes = [[1,2],[3,5],[2,2]], <code>extraStudents</code> = 2
<b>输出：</b>0.78333
<b>解释：</b>你可以将额外的两个学生都安排到第一个班级，平均通过率为 (3/4 + 3/5 + 2/2) / 3 = 0.78333 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>classes = [[2,4],[3,9],[4,5],[2,10]], <code>extraStudents</code> = 4
<strong>输出：</strong>0.53485
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= classes.length <= 10<sup>5</sup></code></li>
	<li><code>classes[i].length == 2</code></li>
	<li><code>1 <= pass<sub>i</sub> <= total<sub>i</sub> <= 10<sup>5</sup></code></li>
	<li><code>1 <= extraStudents <= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：优先队列

假设一个班级有a个学生通过测试，这个班级共有b个学生，那么给这个班级分配一个“超级无敌学生娃”的话，这个班级的优秀率将会提高$\frac{a+1}{b+1}-\frac{a}{b}$

诶，那么我不就知道某个学生娃怎么分了吗？每次分配学生娃，都分给$\frac{a+1}{b+1}-\frac{a}{b}$这个值最高的班级即可。

我们只需要建立一个优先队列，以$\frac{a+1}{b+1}-\frac{a}{b}$为优先规则，让$\frac{a+1}{b+1}-\frac{a}{b}$大的在栈顶（先出栈），每次分配学生时，给栈顶班级分配即可（分配后新的学生人数入栈）

+ 时间复杂度$O(len(classes)\times \log classes + extraStudents\times \log classes)$
+ 空间复杂度$O(len(classes))$

### AC代码

#### C++

```cpp
typedef pair<double, double> pii;

inline double getScore(pii& a) {
    return (a.first + 1) / (a.second + 1) - a.first / a.second;
}

struct cmp {
    bool operator() (pii& a, pii& b) {
        return getScore(a) < getScore(b);
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pii, vector<pii>, cmp> pq;
        for (auto& c : classes) {
            pq.emplace(c[0], c[1]);
        }
        while (extraStudents--) {
            auto [a, b] = pq.top();
            // cout << "a = " << a << ", b = " << b << endl;  //**********
            pq.pop();
            pq.emplace(a + 1, b + 1);
        }
        double total = 0;
        while (pq.size()) {
            total += pq.top().first / pq.top().second;
            pq.pop();
        }
        return total / classes.size();
    }
};
```

#### Python

我对一些Py打竞赛的代码还不是很熟悉，此Py代码是参考着官题写的

```python
# from typing import List
# from heapq import heapify, heapreplace


class Entry:
    __slots__ = "a", "b"

    def __init__(self, a: int, b: int):
        self.a = a
        self.b = b
    
    def __lt__(self, b: "Entry") -> bool:
        return getScore(self) > getScore(b)


def getScore(a: "Entry") -> float:
    return (a.a + 1) / (a.b + 1) - a.a / a.b


class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        pq = [Entry(*c) for c in classes]
        heapify(pq)
        for _ in range(extraStudents):
            heapreplace(pq, Entry(pq[0].a + 1, pq[0].b + 1))
        return sum(c.a / c.b for c in pq) / len(pq)

```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/02/19/LeetCode%201792.%E6%9C%80%E5%A4%A7%E5%B9%B3%E5%9D%87%E9%80%9A%E8%BF%87%E7%8E%87/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129115416](https://letmefly.blog.csdn.net/article/details/129115416)
