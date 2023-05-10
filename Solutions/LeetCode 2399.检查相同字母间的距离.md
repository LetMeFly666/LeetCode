---
title: 2399.检查相同字母间的距离
date: 2023-04-09 09:50:02
tags: [题解, LeetCode, 简单, 数组, 哈希表, 字符串]
---

# 【LetMeFly】2399.检查相同字母间的距离

力扣题目链接：[https://leetcode.cn/problems/check-distances-between-same-letters/](https://leetcode.cn/problems/check-distances-between-same-letters/)

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，该字符串仅由小写英文字母组成，<code>s</code> 中的每个字母都 <strong>恰好</strong> 出现 <strong>两次</strong> 。另给你一个下标从 <strong>0</strong> 开始、长度为 <code>26</code> 的的整数数组 <code>distance</code> 。</p>

<p>字母表中的每个字母按从 <code>0</code> 到 <code>25</code> 依次编号（即，<code>'a' -&gt; 0</code>, <code>'b' -&gt; 1</code>, <code>'c' -&gt; 2</code>, ... , <code>'z' -&gt; 25</code>）。</p>

<p>在一个 <strong>匀整</strong> 字符串中，第 <code>i</code> 个字母的两次出现之间的字母数量是 <code>distance[i]</code> 。如果第 <code>i</code> 个字母没有在 <code>s</code> 中出现，那么 <code>distance[i]</code> 可以 <strong>忽略</strong> 。</p>

<p>如果 <code>s</code> 是一个 <strong>匀整</strong> 字符串，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abaccb", distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>输出：</strong>true
<strong>解释：</strong>
- 'a' 在下标 0 和下标 2 处出现，所以满足 distance[0] = 1 。
- 'b' 在下标 1 和下标 5 处出现，所以满足 distance[1] = 3 。
- 'c' 在下标 3 和下标 4 处出现，所以满足 distance[2] = 0 。
注意 distance[3] = 5 ，但是由于 'd' 没有在 s 中出现，可以忽略。
因为 s 是一个匀整字符串，返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "aa", distance = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
<strong>输出：</strong>false
<strong>解释：</strong>
- 'a' 在下标 0 和 1 处出现，所以两次出现之间的字母数量为 0 。
但是 distance[0] = 1 ，s 不是一个匀整字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 52</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>s</code> 中的每个字母恰好出现两次</li>
	<li><code>distance.length == 26</code></li>
	<li><code>0 &lt;= distance[i] &lt;= 50</code></li>
</ul>


    
## 方法一：首次出现判断，判完原地修改

题目已经说明了数据的规范性，也就是说每个字母只要出现就必定出现两次，并且distance的长度是26，每个出现的字母都能在里面找到对应的distance。

因此，我们只需要遍历字符串，如果这个字符是第一次遇到（distance中不为-1），就判断$当前位置i + distance + 1$是否在字符串范围内，并且对应位置是否为相同的字符。

一旦不满足就返回False，如果满足就将distance中对应的位置标记为-1。

最终返回True即可。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$，原地修改了distance数组，因此空间复杂度为$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        for (int i = 0; i < s.size(); i++) {
            if (distance[s[i] - 'a'] != -1) {
                int should = i + distance[s[i] - 'a'] + 1;
                if (should >= s.size() || s[should] != s[i]) {
                    return false;
                }
                distance[s[i] - 'a'] = -1;
            }
        }
        return true;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        for i in range(len(s)):
            if distance[ord(s[i]) - ord('a')] != -1:
                should = i + distance[ord(s[i]) - ord('a')] + 1
                if should >= len(s) or s[should] != s[i]:
                    return False
                distance[ord(s[i]) - ord('a')] = -1
        return True
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/04/09/LeetCode%202399.%E6%A3%80%E6%9F%A5%E7%9B%B8%E5%90%8C%E5%AD%97%E6%AF%8D%E9%97%B4%E7%9A%84%E8%B7%9D%E7%A6%BB/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130038643](https://letmefly.blog.csdn.net/article/details/130038643)
