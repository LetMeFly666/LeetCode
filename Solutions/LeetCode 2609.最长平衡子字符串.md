---
title: 2609.最长平衡子字符串
date: 2023-11-08 18:55:20
tags: [题解, LeetCode, 简单, 字符串, 模拟]
---

# 【LetMeFly】2609.最长平衡子字符串

力扣题目链接：[https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/](https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/)

<p>给你一个仅由 <code>0</code> 和 <code>1</code> 组成的二进制字符串 <code>s</code> 。<span style="">&nbsp;</span><span style="">&nbsp;</span></p>

<p>如果子字符串中 <strong>所有的<span style=""> </span></strong><code><span style="">0</span></code><strong><span style=""> </span>都在 </strong><code>1</code><strong> 之前</strong> 且其中 <code>0</code> 的数量等于 <code>1</code> 的数量，则认为 <code>s</code> 的这个子字符串是平衡子字符串。请注意，空子字符串也视作平衡子字符串。<span style="">&nbsp;</span></p>

<p>返回&nbsp;<span style=""> </span><code>s</code> 中最长的平衡子字符串长度。</p>

<p>子字符串是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "01000111"
<strong>输出：</strong>6
<strong>解释：</strong>最长的平衡子字符串是 "000111" ，长度为 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "00111"
<strong>输出：</strong>4
<strong>解释：</strong>最长的平衡子字符串是 "0011" ，长度为 <span style="">&nbsp;</span>4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "111"
<strong>输出：</strong>0
<strong>解释：</strong>除了空子字符串之外不存在其他平衡子字符串，所以答案为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>'0' &lt;= s[i] &lt;= '1'</code></li>
</ul>


    
## 方法一：字符串处理

“平衡字符串”的前提是数个0后面有数个1。因此，我们可以使用一个变量index来存储当前处理到的字符，每次遍历完所有相连的0后遍历所有相邻的1，其中0和1的最小值的二倍即为当前“平衡子字符串”的长度。

```python
index = 0
while index < len(s):
    cnt0 = 0
    while index < len(s) and s[index] == '0':  # 遍历完所有的0
        cnt0++, index++
    while index < len(s) and s[index] == '1':  # 遍历完所有的0
        cnt1++, index++
	thisLength = 2 * min(cnt0, cnt1)
	# 更新answer
```

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0, index = 0;
        while (index < s.size()) {
            int cnt0 = 0, cnt1 = 0;
            while (index < s.size() && s[index] == '0') {
                cnt0++, index++;
            }
            while (index < s.size() && s[index] == '1') {
                cnt1++, index++;
            }
            ans = max(ans, 2 * min(cnt0, cnt1));
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans, index = 0, 0
        while index < len(s):
            cnt0, cnt1 = 0, 0
            while index < len(s) and s[index] == '0':
                cnt0, index = cnt0 + 1, index + 1
            while index < len(s) and s[index] == '1':
                cnt1, index = cnt1 + 1, index + 1
            ans = max(ans, 2 * min(cnt0, cnt1))
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/11/08/LeetCode%202609.%E6%9C%80%E9%95%BF%E5%B9%B3%E8%A1%A1%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134296484](https://letmefly.blog.csdn.net/article/details/134296484)
