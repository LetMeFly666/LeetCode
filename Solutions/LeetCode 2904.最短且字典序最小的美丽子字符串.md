---
title: 2904.最短且字典序最小的美丽子字符串：滑动窗口
date: 2026-08-26 14:20:44
tags: [题解, LeetCode, 中等, 字符串, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】2904.最短且字典序最小的美丽子字符串：滑动窗口

力扣题目链接：[https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/](https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/)

<p>给你一个二进制字符串 <code>s</code> 和一个正整数 <code>k</code> 。</p>

<p>如果 <code>s</code> 的某个子字符串中 <code>1</code> 的个数恰好等于 <code>k</code> ，则称这个子字符串是一个 <strong>美丽子字符串</strong> 。</p>

<p>令 <code>len</code> 等于 <strong>最短</strong> 美丽子字符串的长度。</p>

<p>返回长度等于 <code>len</code> 且字典序 <strong>最小</strong> 的美丽子字符串。如果 <code>s</code> 中不含美丽子字符串，则返回一个 <strong>空</strong> 字符串。</p>

<p>对于相同长度的两个字符串 <code>a</code> 和 <code>b</code> ，如果在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置上，<code>a</code> 中该位置上的字符严格大于 <code>b</code> 中的对应字符，则认为字符串 <code>a</code> 字典序 <strong>大于</strong> 字符串 <code>b</code> 。</p>

<ul>
	<li>例如，<code>"abcd"</code> 的字典序大于 <code>"abcc"</code> ，因为两个字符串出现不同的第一个位置对应第四个字符，而 <code>d</code> 大于 <code>c</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "100011001", k = 3
<strong>输出：</strong>"11001"
<strong>解释：</strong>示例中共有 7 个美丽子字符串：
1. 子字符串 "<u>100011</u>001" 。
2. 子字符串 "<u>1000110</u>01" 。
3. 子字符串 "<u>10001100</u>1" 。
4. 子字符串 "1<u>00011001</u>" 。
5. 子字符串 "10<u>0011001</u>" 。
6. 子字符串 "100<u>011001</u>" 。
7. 子字符串 "1000<u>11001</u>" 。
最短美丽子字符串的长度是 5 。
长度为 5 且字典序最小的美丽子字符串是子字符串 "11001" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "1011", k = 2
<strong>输出：</strong>"11"
<strong>解释：</strong>示例中共有 3 个美丽子字符串：
1. 子字符串 "<u>101</u>1" 。
2. 子字符串 "1<u>011</u>" 。
3. 子字符串 "10<u>11</u>" 。
最短美丽子字符串的长度是 2 。
长度为 2 且字典序最小的美丽子字符串是子字符串 "11" 。 
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "000", k = 1
<strong>输出：</strong>""
<strong>解释：</strong>示例中不存在美丽子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
</ul>


    
## 解题方法：滑动窗口

左右两个指针$l$和$r$代表“窗口”，每次右指针右移一位，若不满足如下条件则左指针右移：

1. 窗口中`1`的个数**大于**$k$
2. 窗口中`1`的个数**等于**$k$且左指针指向的字符为`0`

若左指针移动结束后窗口中`1`的个数**等于**$k$，则*可能*更新答案字符串。怎么判断是否更新呢？当满足以下任一条件时更新：

1. 答案字符串为空
2. 答案字符串比当前窗口字符串长
3. 答案字符串与前窗口字符串长等长但是字典序更大

以上。

+ 时间复杂度$O(len(s)\times k)$
+ 空间复杂度$O(k)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-26 14:16:35
 */
class Solution {
private:
    void update(string& ans, string& s, int l, int r) {
        int len = r - l + 1;
        std::string_view cur(s.data() + l, len);
        if (ans.empty() || len < ans.size() || len == ans.size() && cur < ans) {
            ans = cur;
        }
    }
public:
    string shortestBeautifulSubstring(string& s, int k) {
        string ans;
        for (int l = 0, r = 0, cnt = 0, n = s.size(); r < n; r++) {
            cnt += s[r] == '1';
            while (cnt > k) {
                cnt -= s[l++] == '1';
            }
            if (cnt == k) {
                while (s[l] == '0') {  // do not forget!
                    l++;
                }
                update(ans, s, l, r);
            }
        }
        return ans;
    }
};
```

+ 执行用时分布 0 ms 击败 100.00% 
+ 消耗内存分布 8.32 MB 击败 98.88%


> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/164088556)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/26/LeetCode%202904.%E6%9C%80%E7%9F%AD%E4%B8%94%E5%AD%97%E5%85%B8%E5%BA%8F%E6%9C%80%E5%B0%8F%E7%9A%84%E7%BE%8E%E4%B8%BD%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
