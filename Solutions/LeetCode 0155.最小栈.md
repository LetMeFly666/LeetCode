---
title: 155.最小栈
date: 2022-08-03 16:47:17
tags: [题解, LeetCode, 简单, 栈, 设计, 思维, 构造, 哈希, 辅助栈]
---

# 【LetMeFly】155.最小栈

力扣题目链接：[https://leetcode.cn/problems/min-stack/](https://leetcode.cn/problems/min-stack/)

<p>设计一个支持 <code>push</code> ，<code>pop</code> ，<code>top</code> 操作，并能在常数时间内检索到最小元素的栈。</p>

<p>实现 <code>MinStack</code> 类:</p>

<ul>
	<li><code>MinStack()</code> 初始化堆栈对象。</li>
	<li><code>void push(int val)</code> 将元素val推入堆栈。</li>
	<li><code>void pop()</code> 删除堆栈顶部的元素。</li>
	<li><code>int top()</code> 获取堆栈顶部的元素。</li>
	<li><code>int getMin()</code> 获取堆栈中的最小元素。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

<strong>输出：</strong>
[null,null,null,null,-3,null,0,-2]

<strong>解释：</strong>
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --&gt; 返回 -3.
minStack.pop();
minStack.top();      --&gt; 返回 0.
minStack.getMin();   --&gt; 返回 -2.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= val &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
	<li><code>pop</code>、<code>top</code> 和 <code>getMin</code> 操作总是在 <strong>非空栈</strong> 上调用</li>
	<li><code>push</code>,&nbsp;<code>pop</code>,&nbsp;<code>top</code>, and&nbsp;<code>getMin</code>最多被调用&nbsp;<code>3 * 10<sup>4</sup></code>&nbsp;次</li>
</ul>


    
## 方法一：map

入栈时，真正入栈的同时，用哈希表将入栈的数字累加。

例如，C++中```map<int, int>```默认是有序存放的，因此```map<int, int>.begin()->first```就是栈中元素的最小值

出栈时，真正出栈的同时，哈希表中该出栈元素的个数减$1$。如果减一之后出现次数为$0$，就删除掉哈希表中这一键值对。

+ 时间复杂度$O(n\log n)$，其中$n$是操作次数。这种方法严格上不能被称为“常数时间内”。
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class MinStack {
private:
    map<int, int> ma;
    stack<int> st;
public:
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        ma[val]++;
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        ma[val]--;
        if (!ma[val]) {
            ma.erase(val);
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ma.begin()->first;
    }
};
```

## 方法二：辅助栈

出栈的顺序是由入栈决定的。

我们可以额外开辟一个“辅助栈”，每次有元素入栈**后**，辅助栈中入栈当前栈中的最小元素（$min\{辅助栈.top(), thisVal\}$）

例如当前栈中元素为```-1 -2 3```（最小元素为$-2$），现在如果新入栈一个元素$6$，那么你最小元素还是$-2$，就将$-2$压入辅助栈；如果现在入栈一个元素$-8$，那么最小元素就应该为$-8$，就往辅助栈中压入$-8$

原始栈：

```
|    |   |    |
| -1 |   | -2 |
| -2 |   | -2 |
|  3 |   |  3 |
+----+   +----+
  栈      辅助栈
```

+ 如果入栈$6$：
	```
	|  6 |   | -2 |
	| -1 |   | -2 |
	| -2 |   | -2 |
	|  3 |   |  3 |
	+----+   +----+
	  栈      辅助栈
	```
+ 如果入栈$-8$：
	```
	| -8 |   | -8 |
	| -1 |   | -2 |
	| -2 |   | -2 |
	|  3 |   |  3 |
	+----+   +----+
	  栈      辅助栈
	```

为了方便，可以在初始化时往辅助栈中放入元素```INT_MAX```以防止```辅助栈.top()越界```

+ 时间复杂度$O(n)$，其中$n$是操作次数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class MinStack {
private:
    stack<int> realStack;
    stack<int> minStack;
public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        realStack.push(val);
        minStack.push(min(val, minStack.top()));
    }
    
    void pop() {
        realStack.pop();
        minStack.pop();
    }
    
    int top() {
        return realStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/08/03/LeetCode%200155.%E6%9C%80%E5%B0%8F%E6%A0%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126144246](https://letmefly.blog.csdn.net/article/details/126144246)
