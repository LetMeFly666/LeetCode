---
title: 946.验证栈序列
date: 2022-08-31 09:02:57
tags: [题解, LeetCode, 中等, 栈, 数组, 模拟]
---

# 【LetMeFly】946.验证栈序列

力扣题目链接：[https://leetcode.cn/problems/validate-stack-sequences/](https://leetcode.cn/problems/validate-stack-sequences/)

<p>给定&nbsp;<code>pushed</code>&nbsp;和&nbsp;<code>popped</code>&nbsp;两个序列，每个序列中的 <strong>值都不重复</strong>，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 <code>true</code>；否则，返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
<strong>输出：</strong>true
<strong>解释：</strong>我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -&gt; 4,
push(5), pop() -&gt; 5, pop() -&gt; 3, pop() -&gt; 2, pop() -&gt; 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>1 不能在 2 之前弹出。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pushed.length &lt;= 1000</code></li>
	<li><code>0 &lt;= pushed[i] &lt;= 1000</code></li>
	<li><code>pushed</code> 的所有元素 <strong>互不相同</strong></li>
	<li><code>popped.length == pushed.length</code></li>
	<li><code>popped</code> 是 <code>pushed</code> 的一个排列</li>
</ul>


    
## 方法一：栈模拟

既然```pushed```中的元素要顺序入栈，那么模拟的时候就让其中的元素顺序入栈。

既然想要出栈顺序为```popped```中的元素顺序，那么就依据其中的顺序，决定入栈的元素何时出栈。

**具体方法步骤为：**

1. 在```popped```中的元素没有处理完时，进行循环：
2. 循环的时候，如果栈为空或栈顶元素不是```popped```的下一个元素时，不断入栈。直到无元素可再入栈（返回```false```）或栈顶元素和```popped```的下一个待遍历元素相同。
3. 如果第一层循环结束（```popped```中的元素都成功出栈了），就返回```true```

+ 时间复杂度$O(n)$，其中$n$是数组中元素个数‘
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int locPushed = 0, locPopped = 0;
        while (locPopped < popped.size()) {
            while (st.empty() || st.top() != popped[locPopped]) {
                if (locPushed == pushed.size())
                    return false;
                st.push(pushed[locPushed++]);
            }
            st.pop();
            locPopped++;
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/31/LeetCode%200946.%E9%AA%8C%E8%AF%81%E6%A0%88%E5%BA%8F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126616819](https://letmefly.blog.csdn.net/article/details/126616819)
