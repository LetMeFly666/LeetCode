---
title: 1845.座位预约管理系统
date: 2024-10-02 23:19:06
tags: [题解, LeetCode, 中等, 设计, 堆（优先队列）, 优先队列, 堆]
---

# 【LetMeFly】1845.座位预约管理系统：优先队列

力扣题目链接：[https://leetcode.cn/problems/seat-reservation-manager/](https://leetcode.cn/problems/seat-reservation-manager/)

<p>请你设计一个管理 <code>n</code> 个座位预约的系统，座位编号从 <code>1</code> 到 <code>n</code> 。</p>

<p>请你实现 <code>SeatManager</code> 类：</p>

<ul>
	<li><code>SeatManager(int n)</code> 初始化一个 <code>SeatManager</code> 对象，它管理从 <code>1</code> 到 <code>n</code> 编号的 <code>n</code> 个座位。所有座位初始都是可预约的。</li>
	<li><code>int reserve()</code> 返回可以预约座位的 <strong>最小编号</strong> ，此座位变为不可预约。</li>
	<li><code>void unreserve(int seatNumber)</code> 将给定编号 <code>seatNumber</code> 对应的座位变成可以预约。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>
["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
[[5], [], [], [2], [], [], [], [], [5]]
<strong>输出：</strong>
[null, 1, 2, null, 2, 3, 4, 5, null]

<strong>解释：</strong>
SeatManager seatManager = new SeatManager(5); // 初始化 SeatManager ，有 5 个座位。
seatManager.reserve();    // 所有座位都可以预约，所以返回最小编号的座位，也就是 1 。
seatManager.reserve();    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
seatManager.unreserve(2); // 将座位 2 变为可以预约，现在可预约的座位为 [2,3,4,5] 。
seatManager.reserve();    // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
seatManager.reserve();    // 可以预约的座位为 [3,4,5] ，返回最小编号的座位，也就是 3 。
seatManager.reserve();    // 可以预约的座位为 [4,5] ，返回最小编号的座位，也就是 4 。
seatManager.reserve();    // 唯一可以预约的是座位 5 ，所以返回 5 。
seatManager.unreserve(5); // 将座位 5 变为可以预约，现在可预约的座位为 [5] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= seatNumber &lt;= n</code></li>
	<li>每一次对 <code>reserve</code> 的调用，题目保证至少存在一个可以预约的座位。</li>
	<li>每一次对 <code>unreserve</code> 的调用，题目保证 <code>seatNumber</code> 在调用函数前都是被预约状态。</li>
	<li>对 <code>reserve</code> 和 <code>unreserve</code> 的调用 <strong>总共</strong> 不超过 <code>10<sup>5</sup></code> 次。</li>
</ul>


    
## 解题方法：优先队列

使用一个优先队列存放空位的编号，初始值优先队列中为每个`1`到`n`这`n`个元素，值越小的元素越优先。

对于座位预约，直接返回队首元素并将队首元素出队即可；

对于座位释放，直接将所释放座位入队即可。

+ 时间复杂度：初始化$O(n)$，单次操作$O(\log n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> q;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
    }
    
    int reserve() {
        int ans = q.top();
        q.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};
```

#### Python

```python
import heapq

class SeatManager:
    def __init__(self, n: int):
        self.q = list(range(1, n + 1))
        heapq.heapify(self.q)

    def reserve(self) -> int:
        return heapq.heappop(self.q)

    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.q, seatNumber)
```

#### Java

```java
import java.util.PriorityQueue;

class SeatManager {
    private PriorityQueue<Integer> q = new PriorityQueue<>();

    public SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            q.add(i);
        }
    }
    
    public int reserve() {
        return q.poll();
    }
    
    public void unreserve(int seatNumber) {
        q.add(seatNumber);
    }
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/02/LeetCode%201845.%E5%BA%A7%E4%BD%8D%E9%A2%84%E7%BA%A6%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142686842](https://letmefly.blog.csdn.net/article/details/142686842)
