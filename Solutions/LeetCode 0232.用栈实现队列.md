---
title: 232.用队实现队列
date: 2024-03-04 09:20:00
tags: [题解, LeetCode, 简单, 栈, 设计, 队列]
categories: [题解, LeetCode]
---

# 【LetMeFly】232.用栈实现队列：基础数据结构的学习

力扣题目链接：[https://leetcode.cn/problems/implement-queue-using-stacks/](https://leetcode.cn/problems/implement-queue-using-stacks/)

<p>请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（<code>push</code>、<code>pop</code>、<code>peek</code>、<code>empty</code>）：</p>

<p>实现 <code>MyQueue</code> 类：</p>

<ul>
	<li><code>void push(int x)</code> 将元素 x 推到队列的末尾</li>
	<li><code>int pop()</code> 从队列的开头移除并返回元素</li>
	<li><code>int peek()</code> 返回队列开头的元素</li>
	<li><code>boolean empty()</code> 如果队列为空，返回 <code>true</code> ；否则，返回 <code>false</code></li>
</ul>

<p><strong>说明：</strong></p>

<ul>
	<li>你 <strong>只能</strong> 使用标准的栈操作 —— 也就是只有&nbsp;<code>push to top</code>,&nbsp;<code>peek/pop from top</code>,&nbsp;<code>size</code>, 和&nbsp;<code>is empty</code>&nbsp;操作是合法的。</li>
	<li>你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
<strong>输出：</strong>
[null, null, null, 1, 1, false]

<strong>解释：</strong>
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
</pre>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 9</code></li>
	<li>最多调用 <code>100</code> 次 <code>push</code>、<code>pop</code>、<code>peek</code> 和 <code>empty</code></li>
	<li>假设所有操作都是有效的 （例如，一个空的队列不会调用 <code>pop</code> 或者 <code>peek</code> 操作）</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你能否实现每个操作均摊时间复杂度为 <code>O(1)</code> 的队列？换句话说，执行 <code>n</code> 个操作的总时间复杂度为 <code>O(n)</code> ，即使其中一个操作可能花费较长时间。</li>
</ul>


    
## 方法一：用栈实现队列

对于现成库，能使用的是栈的：(右边)入栈、(右边)出队、大小、非空  这四种操作。

不难发现数据量很小，因此我们可以使用两个栈：

+ 一个作为```输入栈```，新元素“入队”时直接加入到```输入栈```中。
+ 一个作为```输出栈```，返回“队”中元素信息时，（若```输出栈```为空则依次将```输入栈```中的元素弹出到```输出栈```中）返回```输出栈```信息即可。

这样“元素序列”入栈出栈各两次，正好序列顺序保持不变（实现了先入先出的效果）。

+ 时间复杂度（单次操作）：入队$O(n)$，其余$O(1)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class MyQueue {
private:
    stack<int> input, output;

    void preTreatment() {
        if (output.size()) {
            return;
        }
        while (input.size()) {
            output.push(input.top());
            input.pop();
        }
    }

public:
    MyQueue() {

    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        preTreatment();
        int ans = output.top();
        output.pop();
        return ans;
    }
    
    int peek() {
        preTreatment();
        return output.top();
    }
    
    bool empty() {
        preTreatment();
        return output.empty();
    }
};
```

#### Python

```python
class MyQueue:

    def __init__(self):
        self.input = []
        self.output = []
    
    def __preTreatment(self):
        if self.output:
            return
        while self.input:
            self.output.append(self.input.pop())

    def push(self, x: int) -> None:
        self.input.append(x)

    def pop(self) -> int:
        self.__preTreatment()
        return self.output.pop()

    def peek(self) -> int:
        self.__preTreatment()
        return self.output[-1]

    def empty(self) -> bool:
        self.__preTreatment()
        return not self.output
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/04/LeetCode%200232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136443771](https://letmefly.blog.csdn.net/article/details/136443771)
