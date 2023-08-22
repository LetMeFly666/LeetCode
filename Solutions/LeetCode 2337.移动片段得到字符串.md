---
title: 2337.移动片段得到字符串：双指针
date: 2023-08-22 09:45:39
tags: [题解, LeetCode, 中等, 双指针, 字符串]
---

# 【LetMeFly】2337.移动片段得到字符串：双指针

力扣题目链接：[https://leetcode.cn/problems/move-pieces-to-obtain-a-string/](https://leetcode.cn/problems/move-pieces-to-obtain-a-string/)

<p>给你两个字符串 <code>start</code> 和 <code>target</code> ，长度均为 <code>n</code> 。每个字符串 <strong>仅</strong> 由字符 <code>'L'</code>、<code>'R'</code> 和 <code>'_'</code> 组成，其中：</p>

<ul>
	<li>字符 <code>'L'</code> 和 <code>'R'</code> 表示片段，其中片段 <code>'L'</code> 只有在其左侧直接存在一个 <strong>空位</strong> 时才能向 <strong>左</strong> 移动，而片段 <code>'R'</code> 只有在其右侧直接存在一个 <strong>空位</strong> 时才能向 <strong>右</strong> 移动。</li>
	<li>字符 <code>'_'</code> 表示可以被 <strong>任意</strong> <code>'L'</code> 或 <code>'R'</code> 片段占据的空位。</li>
</ul>

<p>如果在移动字符串 <code>start</code> 中的片段任意次之后可以得到字符串 <code>target</code> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>start = "_L__R__R_", target = "L______RR"
<strong>输出：</strong>true
<strong>解释：</strong>可以从字符串 start 获得 target ，需要进行下面的移动：
- 将第一个片段向左移动一步，字符串现在变为 "<strong>L</strong>___R__R_" 。
- 将最后一个片段向右移动一步，字符串现在变为 "L___R___<strong>R</strong>" 。
- 将第二个片段向右移动散步，字符串现在变为 "L______<strong>R</strong>R" 。
可以从字符串 start 得到 target ，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>start = "R_L_", target = "__LR"
<strong>输出：</strong>false
<strong>解释：</strong>字符串 start 中的 'R' 片段可以向右移动一步得到 "_<strong>R</strong>L_" 。
但是，在这一步之后，不存在可以移动的片段，所以无法从字符串 start 得到 target 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>start = "_R", target = "R_"
<strong>输出：</strong>false
<strong>解释：</strong>字符串 start 中的片段只能向右移动，所以无法从字符串 start 得到 target 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == start.length == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>start</code> 和 <code>target</code> 由字符 <code>'L'</code>、<code>'R'</code> 和 <code>'_'</code> 组成</li>
</ul>


    
## 方法一：双指针

满足以下条件时，返回True：

1. 去掉```_```后，字符串相同（```LR```的相对位置及数量相同）
2. ```start```中的```L```的位置不**早**于**对应的***```target```中的```L```
3. ```start```中的```R```的位置不**晚**于**对应的***```target```中的```R```

**细节描述（具体实现）：**

可以使用两个指针分别指向两个字符串中遍历到的位置。

每次指针都指到```L```或```R```（或字符串末尾）为止：

+ 若二者不同，则说明去掉```_```后剩余的```LR```不对应
+ 否则：
   + 若指针指向的字符为```L```：若第一个指针小于第二个指针，返回```false```
   + 否则（指向的字符为```R```）：若第一个指针大于第二个指针，返回```false```

结束上述循环后，为防止一个字符串指完而另一个字符串还未遍历完的情况，遍历未遍历完的字符串，遇到非下划线就返回```false```。

若未返回过```false```，则返回```true```。

+ 时间复杂度$O(len(target))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool canChange(string& a, string& b) {
        int n = a.size();
        int ia = -1, ib = -1;
        while (ia + 1 < n && ib + 1 < n) {
            while (++ia < n && a[ia] == '_');
            while (++ib < n && b[ib] == '_');
            if (a[ia] != b[ib]) {
                return false;
            }
            if (a[ia] == 'L') {
                if (ia < ib) {
                    return false;
                }
            }
            else {  // R
                if (ia > ib) {
                    return false;
                }
            }
        }
        while (ia + 1 < n) {
            if (a[++ia] != '_') {
                return false;
            }
        }
        while (ib + 1 < n) {
            if (b[++ib] != '_') {
                return false;
            }
        }
        return true;
    }
};
```

#### Python

```python
class Solution:
    def canChange(self, a: str, b: str) -> bool:
        n = len(a)
        ia, ib = 0, 0
        while ia < n and ib < n:
            while ia < n and a[ia] == '_':
                ia += 1
            while ib < n and b[ib] == '_':
                ib += 1
            if ia >= n or ib >= n:
                break
            if a[ia] != b[ib]:
                return False
            if a[ia] == 'L':  # L
                if ia < ib:
                    return False
            else:  # R
                if ia > ib:
                    return False
            ia, ib = ia + 1, ib + 1
        while ia < n:
            if a[ia] != '_':
                return False
            ia += 1
        while ib < n:
            if b[ib] != '_':
                return False
            ib += 1
        return True
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/08/22/LeetCode%202337.%E7%A7%BB%E5%8A%A8%E7%89%87%E6%AE%B5%E5%BE%97%E5%88%B0%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132421605](https://letmefly.blog.csdn.net/article/details/132421605)
