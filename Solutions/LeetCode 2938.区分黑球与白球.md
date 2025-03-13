---
title: 2938.区分黑球与白球
date: 2024-06-06 22:51:23
tags: [题解, LeetCode, 中等, 贪心, 双指针, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2938.区分黑球与白球：黑球要与后面每个白球交换一次

力扣题目链接：[https://leetcode.cn/problems/separate-black-and-white-balls/](https://leetcode.cn/problems/separate-black-and-white-balls/)

<p>桌子上有 <code>n</code> 个球，每个球的颜色不是黑色，就是白色。</p>

<p>给你一个长度为 <code>n</code> 、下标从 <strong>0</strong> 开始的二进制字符串 <code>s</code>，其中 <code>1</code> 和 <code>0</code> 分别代表黑色和白色的球。</p>

<p>在每一步中，你可以选择两个相邻的球并交换它们。</p>

<p>返回「将所有黑色球都移到右侧，所有白色球都移到左侧所需的 <strong>最小步数</strong>」。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "101"
<strong>输出：</strong>1
<strong>解释：</strong>我们可以按以下方式将所有黑色球移到右侧：
- 交换 s[0] 和 s[1]，s = "011"。
最开始，1 没有都在右侧，需要至少 1 步将其移到右侧。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "100"
<strong>输出：</strong>2
<strong>解释：</strong>我们可以按以下方式将所有黑色球移到右侧：
- 交换 s[0] 和 s[1]，s = "010"。
- 交换 s[1] 和 s[2]，s = "001"。
可以证明所需的最小步数为 2 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "0111"
<strong>输出：</strong>0
<strong>解释：</strong>所有黑色球都已经在右侧。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 不是 <code>'0'</code>，就是 <code>'1'</code>。</li>
</ul>


    
## 解题方法：一次遍历

同色球交换无意义，因此所有的交换都是：前面的黑球与黑球后面的白球。

因此统计一下每个黑球后面有多少个白球即可。

怎么统计？使用一个变量记录当前遍历到的黑球数，遇到一个黑球就黑球数加一，遇到一个白球答案就加上黑球数。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
1010
1001
0101
0011
*/
typedef long long ll;
class Solution {
public:
    ll minimumSteps(string s) {
        ll ans = 0, times = 0;
        for (char c : s) {
            if (c == '1') {
                times++;
            }
            else {
                ans += times;
            }
        }
        return ans;
    }
};
```

#### Go

```go
// package main

func minimumSteps(s string) int64 {
    ans, times := int64(0), 0
    for _, c := range s {
        if c == '1' {
            times++
        } else {  // 必须和上一个大括号写在同一行
            ans += int64(times)
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public long minimumSteps(String s) {
        long ans = 0, times = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                times++;
            }
            else {
                ans += times;
            }
        }
        return ans;
    }
}
```

#### Python

```python
class Solution:
    def minimumSteps(self, s: str) -> int:
        ans, times = 0, 0
        for c in s:
            if c == '1':
                times += 1
            else:
                ans += times
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/06/LeetCode%202938.%E5%8C%BA%E5%88%86%E9%BB%91%E7%90%83%E4%B8%8E%E7%99%BD%E7%90%83/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139511813](https://letmefly.blog.csdn.net/article/details/139511813)
