---
title: 316.去除重复字母
date: 2022-09-23 15:03:58
tags: [题解, LeetCode, 中等, 栈, 贪心, 字符串, 单调栈]
categories: [题解, LeetCode]
---

# 【LetMeFly】316.去除重复字母：单调栈

力扣题目链接：[https://leetcode.cn/problems/remove-duplicate-letters/](https://leetcode.cn/problems/remove-duplicate-letters/)

<p>给你一个字符串 <code>s</code> ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 <strong>返回结果的字典序最小</strong>（要求不能打乱其他字符的相对位置）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>s = "bcabc"</code>
<strong>输出<code>：</code></strong><code>"abc"</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong><code>s = "cbacdcbc"</code>
<strong>输出：</strong><code>"acdb"</code></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>该题与 1081 <a href="https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters">https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters</a> 相同</p>


    
## 方法一：单调栈

这道题需要满足三个要求：

1. 去重
2. 按原始相对顺序
3. 字典序最小

我们先来用栈实现一下“1.”和“2.”。至于为什么用栈，到后面就知道了。

```cpp
string removeDuplicateLetters(string& s) {
	bool isInStack[26] = {false};  // isInStack[i]：字母'a'+i是否已经在栈中

	stack<char> st;
	for (char& c : s) {  // 遍历字符串
		if (isInStack[c - 'a']) {  // 因为要去重，所以时刻保证一种字母在栈中只出现一次
			continue;
		}
		st.push(c);
		isInStack[c - 'a'] = true;
	}

	string ans;
	while (st.size()) {  // 将栈中元素全部加入字符串中
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());  // 由于栈的特性，故需要反转一下字符串，以保证相对顺序不变
	return ans;
}
```

上述代码中，我们用布尔类型的```isInStack```来记录某个元素是否已经位于了栈中。遍历字符串时，如果某个元素还不在栈中，就将这个元素入栈，同时更新isInStack

如何实现字典序最小呢？很容易想到，越小的字母尽量地越靠前，就能使字典序尽可能地小。

因此，在遍历到一个不在栈中的字母时，如果前面有**比它大**的字母，并且前面这个字母**以后还会出现**，就让前面这个字母出栈。

例如，现在遍历到了字符串中的字符'a'，如果栈中上一个元素是'b'（'b' > 'a'），并且'b'以后还会再次出现，那么就让'b'出栈，等再次遇到'b'时，再让'b'重新入栈。

这就需要我们再开辟一个整数型的数组，来记录遍历到当前元素时，某个元素还会再出现多少次。

```cpp
string removeDuplicateLetters(string& s) {
    // 预处理，统计每个字符出现了多少次
    int remain[26] = {0};
    for (char& c : s) {
        remain[c - 'a']++;
    }
    // 单调栈开始
    stack<char> st;
    bool isInStack[26] = {false};  // 某个元素是否在栈中
    for (char& c : s) {  // 遍历字符串
        remain[c - 'a']--;  // 这个字符出现了一次，后面还会再出现的次数--
        if (isInStack[c - 'a'])  // 这个字符已经在栈中了
            continue;
        while (st.size() && st.top() > c && remain[st.top() - 'a']) {  // 如果栈顶字符大于这个字符，并且栈顶字符还会再次出现，就让栈顶字符先出栈，后面再次遇到的时候再入栈
            isInStack[st.top() - 'a'] = false;
            st.pop();
        }
		// 这个字符入栈
        st.push(c);
        isInStack[c - 'a'] = true;
    }
	// 同理，弹出栈中的每一个字符，之后再反转一下字符串
    string ans;
    while (st.size()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(C)$，其中$C$是字符集大小（26个小写英文字母，C=26）

推荐一篇描述更为详细的博客：[由浅入深，单调栈思路去除重复字符](https://leetcode.cn/problems/remove-duplicate-letters/solution/you-qian-ru-shen-dan-diao-zhan-si-lu-qu-chu-zhong-/1766857/)

### AC代码

#### C++

```cpp
class Solution {
public:
    string removeDuplicateLetters(string& s) {
        // 预处理，统计每个字符出现了多少次
        int remain[26] = {0};
        for (char& c : s) {
            remain[c - 'a']++;
        }
        // 单调栈开始
        stack<char> st;
        bool isInStack[26] = {false};
        for (char& c : s) {
            remain[c - 'a']--;
            if (isInStack[c - 'a'])
                continue;
            while (st.size() && st.top() > c && remain[st.top() - 'a']) {
                isInStack[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            isInStack[c - 'a'] = true;
        }
        string ans;
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/23/LeetCode%200316.%E5%8E%BB%E9%99%A4%E9%87%8D%E5%A4%8D%E5%AD%97%E6%AF%8D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127011739](https://letmefly.blog.csdn.net/article/details/127011739)
