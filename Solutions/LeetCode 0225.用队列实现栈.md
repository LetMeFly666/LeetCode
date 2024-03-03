---
title: 225.用队列实现栈
date: 2024-03-03 12:07:31
tags: [题解, LeetCode, 简单, 栈, 设计, 队列]
---

# 【LetMeFly】225.用队列实现栈：基础数据结构的学习

力扣题目链接：[https://leetcode.cn/problems/implement-stack-using-queues/](https://leetcode.cn/problems/implement-stack-using-queues/)

<p>请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（<code>push</code>、<code>top</code>、<code>pop</code> 和 <code>empty</code>）。</p>

<p>实现 <code>MyStack</code> 类：</p>

<ul>
	<li><code>void push(int x)</code> 将元素 x 压入栈顶。</li>
	<li><code>int pop()</code> 移除并返回栈顶元素。</li>
	<li><code>int top()</code> 返回栈顶元素。</li>
	<li><code>boolean empty()</code> 如果栈是空的，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ul>
	<li>你只能使用队列的基本操作 —— 也就是&nbsp;<code>push to back</code>、<code>peek/pop from front</code>、<code>size</code> 和&nbsp;<code>is empty</code>&nbsp;这些操作。</li>
	<li>你所使用的语言也许不支持队列。&nbsp;你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列&nbsp;, 只要是标准的队列操作即可。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
<strong>输出：</strong>
[null, null, null, 2, 2, false]

<strong>解释：</strong>
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 9</code></li>
	<li>最多调用<code>100</code> 次 <code>push</code>、<code>pop</code>、<code>top</code> 和 <code>empty</code></li>
	<li>每次调用 <code>pop</code> 和 <code>top</code> 都保证栈不为空</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否仅用一个队列来实现栈。</p>


    
## 方法一：用队列实现栈

对于现成库，能使用的是队列的：(右边)入队、(左边)出队、大小、非空  这四种操作。

不难发现数据量很小，因此我们可以使用两个队列：

+ 一个是像栈一样的队列```q```（新加入的元素已经处理到了队首）
+ 一个是临时队列```tempQ```，辅助真正的队列倒腾用的。

新元素入队时，先将新元素加到临时队列（那必是队首），然后将```q```中的元素依次添加到```tempQ```中，再交换```q```和```tempQ```。

这样，相当于把新元素加到了队首，实现了栈一样的*后入*先出的效果。

+ 时间复杂度（单次操作）：入栈$O(n)$，其余$O(1)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class MyStack {
private:
    queue<int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
        queue<int> tempQ;
        tempQ.push(x);
        while (q.size()) {
            tempQ.push(q.front());
            q.pop();
        }
        swap(q, tempQ);
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
```

#### Python

```python
# from collections import deque

class MyStack:

    def __init__(self):
        self.q = deque()

    def push(self, x: int) -> None:
        temp = deque()
        temp.append(x)
        while self.q:
            temp.append(self.q.popleft())
        self.q = temp

    def pop(self) -> int:
        return self.q.popleft()

    def top(self) -> int:
        return self.q[0]


    def empty(self) -> bool:
        return not self.q
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/03/LeetCode%200225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136429312](https://letmefly.blog.csdn.net/article/details/136429312)
