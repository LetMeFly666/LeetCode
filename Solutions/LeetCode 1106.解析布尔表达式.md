---
title: 1106.解析布尔表达式
date: 2022-11-05 09:38:52
tags: [题解, LeetCode, 困难, 栈, 递归, 字符串]
---

# 【LetMeFly】1106.解析布尔表达式

力扣题目链接：[https://leetcode.cn/problems/parsing-a-boolean-expression/](https://leetcode.cn/problems/parsing-a-boolean-expression/)

<p>给你一个以字符串形式表述的&nbsp;<a href="https://baike.baidu.com/item/%E5%B8%83%E5%B0%94%E8%A1%A8%E8%BE%BE%E5%BC%8F/1574380?fr=aladdin" target="_blank">布尔表达式</a>（boolean） <code>expression</code>，返回该式的运算结果。</p>

<p>有效的表达式需遵循以下约定：</p>

<ul>
	<li><code>&quot;t&quot;</code>，运算结果为 <code>True</code></li>
	<li><code>&quot;f&quot;</code>，运算结果为 <code>False</code></li>
	<li><code>&quot;!(expr)&quot;</code>，运算过程为对内部表达式 <code>expr</code> 进行逻辑 <strong>非的运算</strong>（NOT）</li>
	<li><code>&quot;&amp;(expr1,expr2,...)&quot;</code>，运算过程为对 2 个或以上内部表达式 <code>expr1, expr2, ...</code> 进行逻辑 <strong>与的运算</strong>（AND）</li>
	<li><code>&quot;|(expr1,expr2,...)&quot;</code>，运算过程为对 2 个或以上内部表达式 <code>expr1, expr2, ...</code> 进行逻辑 <strong>或的运算</strong>（OR）</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>expression = &quot;!(f)&quot;
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>expression = &quot;|(f,t)&quot;
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>expression = &quot;&amp;(t,f)&quot;
<strong>输出：</strong>false
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>expression = &quot;|(&amp;(t,f,t),!(t))&quot;
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 20000</code></li>
	<li><code>expression[i]</code> 由 <code>{&#39;(&#39;, &#39;)&#39;, &#39;&amp;&#39;, &#39;|&#39;, &#39;!&#39;, &#39;t&#39;, &#39;f&#39;, &#39;,&#39;}</code> 中的字符组成。</li>
	<li><code>expression</code> 是以上述形式给出的有效表达式，表示一个布尔值。</li>
</ul>


    
## 方法一：栈

这道题比较好的一点是，基本上不需要考虑运算符的优先级（不像加减乘除那样需要先乘除后加减），因为“&|!”的后面都会跟上一个括号

那么就好办了，遇到运算符```&|!```就将运算符入栈，遇到布尔值```tf```就将布尔值入栈；

遇到右括号```)```就将栈顶的布尔值不断弹出并统计，直到栈顶为运算符，弹出这个运算符并将弹出的布尔值按运算符的规则进行布尔运算，最后将运算结果再入栈即可。

**例如** ```&(t,f,t,|(t,f),t,!(f))```

从左到右遍历字符串，遇到```&|!tf```都入栈，遇到```(,```不用管，直到遇到右括号开始计算

```
[ &tft|tf
```

这时候遇到了第一个右括号```)```，我们将栈中元素出栈并统计，直到栈顶元素为运算符

```
[ &tft|
```

共出栈了```1```个```t```和```1```个```f```，此时栈顶元素为运算符```|```，```1```个```t```和```1```个```f```相或的结果为```t```，运算符出栈，```t```入栈

```
[ &tftt
```

至此，由```&tft|tf```到```&tftt```，我们实际上是将```|tf```转换成了```t```

继续遍历字符串

```
[ &tfttt!f
```

此时我们遇到了第二个右括号```)```，我们将出栈```1```个```f```

```
[ &tfttt!
```

而```!f```的结果是```t```，将```|```出栈并将```t```入栈

```
[ &tftttt
```

继续遍历字符串，我们遇到了最右一个右括号```)```，我们将出栈```5```个```t```和```1```个```f```

```
[ &
```

此时栈顶元素为```&```，```5```个```t```和```1```个```f```相与的结果为```f```

```
[ f
```

字符串遍历结束，返回栈顶元素```f```即为答案

+ 时间复杂度$O(n)$，其中$n$为字符串长度
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool parseBoolExpr(string& expression) {
        stack<char> st;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            if (expression[i] == '!' || expression[i] == '&' || expression[i] == '|' || expression[i] == 't' || expression[i] == 'f') {
                st.push(expression[i]);
            }
            else if (expression[i] == ')') {
                int cntT = 0, cntF = 0;
                while (st.top() == 't' || st.top() == 'f') {
                    if (st.top() == 't')
                        cntT++;
                    else
                        cntF++;
                    st.pop();
                }
                char op = st.top();
                st.pop();
                if (op == '&') {
                    st.push(cntF ? 'f' : 't');
                }
                else if (op == '|') {
                    st.push(cntT ? 't' : 'f');
                }
                else {
                    st.push(cntT ? 'f' : 't');
                }
            }
            // else will be “(”、“,”
        }
        return st.top() == 't';
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/05/LeetCode%201106.%E8%A7%A3%E6%9E%90%E5%B8%83%E5%B0%94%E8%A1%A8%E8%BE%BE%E5%BC%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127700117](https://letmefly.blog.csdn.net/article/details/127700117)
