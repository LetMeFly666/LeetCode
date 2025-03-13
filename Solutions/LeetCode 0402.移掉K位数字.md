---
title: 402.移掉 K 位数字
date: 2022-10-15 11:08:33
tags: [题解, LeetCode, 中等, 栈, 贪心, 字符串, 单调栈]
categories: [题解, LeetCode]
---

# 【LetMeFly】402.移掉 K 位数字

力扣题目链接：[https://leetcode.cn/problems/remove-k-digits/](https://leetcode.cn/problems/remove-k-digits/)

<p>给你一个以字符串表示的非负整数 <code>num</code> 和一个整数 <code>k</code> ，移除这个数中的 <code>k</code><em> </em>位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。</p>
 

<p><strong>示例 1 ：</strong></p>

<pre>
<strong>输入：</strong>num = "1432219", k = 3
<strong>输出：</strong>"1219"
<strong>解释：</strong>移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>num = "10200", k = 1
<strong>输出：</strong>"200"
<strong>解释：</strong>移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
</pre>

<p><strong>示例 3 ：</strong></p>

<pre>
<strong>输入：</strong>num = "10", k = 2
<strong>输出：</strong>"0"
<strong>解释：</strong>从原数字移除所有的数字，剩余为空就是 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k <= num.length <= 10<sup>5</sup></code></li>
	<li><code>num</code> 仅由若干位数字（0 - 9）组成</li>
	<li>除了 <strong>0</strong> 本身之外，<code>num</code> 不含任何前导零</li>
</ul>


    
## 方法一：单调栈

这道题的核心是“让前面的数字尽可能小”

因此我们可以使用单调栈，遍历一遍字符串，当栈顶数字比当前数字大时，栈顶元素出栈（前提是还有“删除次数”，也就是说k大于0）。然后将当前元素入栈。

这样，越靠近栈底的元素就越小。

如果“删除次数k”还有剩余，那么就从栈顶开始出栈，直到“删除次数”用完

之后将栈顶元素弹出来，加入字符串中。

因为栈中是“后入先出”的，所以我们还需要把字符串反转一下。

之后，删除前导零（如果字符串删空了就返回“0”）

[力扣官解](https://leetcode.cn/problems/remove-k-digits/solution/yi-diao-kwei-shu-zi-by-leetcode-solution/)的动图不错，可以方便理解这个算法，特推荐一波。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string removeKdigits(string& num, int k) {
		// 单调栈核心部分
        stack<char> st;
        for (char c : num) {
            while (st.size() && k && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k--) {
            st.pop();
        }
        // 转为字符串
        string ans;
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int front0 = 0;
        while (front0 < ans.size()) {
            if (ans[front0] == '0')
                front0++;
            else
                break;
        }
        if (front0 == ans.size()) {  // 全0
            ans = "0";
        }
        else {
            ans = ans.substr(front0, ans.size() - front0);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/15/LeetCode%200402.%E7%A7%BB%E6%8E%89K%E4%BD%8D%E6%95%B0%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127332829](https://letmefly.blog.csdn.net/article/details/127332829)
