---
title: 150.逆波兰表达式求值
date: 2022-07-31 12:25:56
tags: [题解, LeetCode, 中等, 栈, 数组, 数学, 逆波兰表达式]
---

# 【LetMeFly】150.逆波兰表达式求值

力扣题目链接：[https://leetcode.cn/problems/evaluate-reverse-polish-notation/](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)

<p>根据<a href="https://baike.baidu.com/item/%E9%80%86%E6%B3%A2%E5%85%B0%E5%BC%8F/128437" target="_blank"> 逆波兰表示法</a>，求表达式的值。</p>

<p>有效的算符包括&nbsp;<code>+</code>、<code>-</code>、<code>*</code>、<code>/</code>&nbsp;。每个运算对象可以是整数，也可以是另一个逆波兰表达式。</p>

<p><b>注意&nbsp;</b>两个整数之间的除法只保留整数部分。</p>

<p>可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>tokens = ["2","1","+","3","*"]
<strong>输出：</strong>9
<strong>解释：</strong>该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>tokens = ["4","13","5","/","+"]
<strong>输出：</strong>6
<strong>解释：</strong>该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
</pre>

<p><strong>示例&nbsp;3：</strong></p>

<pre>
<strong>输入：</strong>tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
<strong>输出：</strong>22
<strong>解释：</strong>该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tokens.length &lt;= 10<sup>4</sup></code></li>
	<li><code>tokens[i]</code>&nbsp;是一个算符（<code>"+"</code>、<code>"-"</code>、<code>"*"</code> 或 <code>"/"</code>），或是在范围 <code>[-200, 200]</code> 内的一个整数</li>
</ul>

<p>&nbsp;</p>

<p><strong>逆波兰表达式：</strong></p>

<p>逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。</p>

<ul>
	<li>平常使用的算式则是一种中缀表达式，如 <code>( 1 + 2 ) * ( 3 + 4 )</code> 。</li>
	<li>该算式的逆波兰表达式写法为 <code>( ( 1 2 + ) ( 3 4 + ) * )</code> 。</li>
</ul>

<p>逆波兰表达式主要有以下两个优点：</p>

<ul>
	<li>去掉括号后表达式无歧义，上式即便写成 <code>1 2 + 3 4 + * </code>也可以依据次序计算出正确结果。</li>
	<li>适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中</li>
</ul>


    
## 方法一：栈模拟

如果懂了什么是逆波兰表达式，那么这道题将会非常简单。

逆波兰表达式的计算要比求表达式的逆波兰容易得多。

使用一个栈，

遍历逆波兰表达式，如果遇到运算符，就从栈中取出对应个数的元素，并进行运算，再把结果入栈。

> 例如，如果遇到了```+```，就从栈中取出两个元素（因为加号是双目运算符），求和并将结果入栈。

注意，栈中的顺序与原顺序是反着的，先出栈的是位置较后的元素。

如果遇到数字，就之间入栈。

+ 时间复杂度$O(n)$，其中$n$是逆波兰表达式中的元素/运算符个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                if (s == "+")
                    st.push(first + second);
                else if (s == "-")
                    st.push(first - second);
                else if (s == "*")
                    st.push(first * second);
                else if (s == "/")
                    st.push(first / second);
            }
            else {
                st.push(atoi(s.c_str()));
            }
        }
        return st.top();
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/31/LeetCode%200150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126084278](https://letmefly.blog.csdn.net/article/details/126084278)
