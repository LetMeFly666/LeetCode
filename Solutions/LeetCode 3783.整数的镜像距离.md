---
title: 3783.整数的镜像距离：数学
date: 2026-04-18 18:54:04
tags: [题解, LeetCode, 简单, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3783.整数的镜像距离：数学

力扣题目链接：[https://leetcode.cn/problems/mirror-distance-of-an-integer/](https://leetcode.cn/problems/mirror-distance-of-an-integer/)

<p>给你一个整数 <code>n</code>。</p>

<p>定义它的&nbsp;<strong>镜像距离</strong>&nbsp;为：<code>abs(n - reverse(n))</code>​​​​​​​，其中 <code>reverse(n)</code> 表示将 <code>n</code> 的数字反转后形成的整数。</p>

<p>返回表示 <code>n</code> 的镜像距离的整数。</p>

<p>其中，<code>abs(x)</code> 表示 <code>x</code> 的绝对值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 25</span></p>

<p><strong>输出：</strong> <span class="example-io">27</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>reverse(25) = 52</code>。</li>
	<li>因此，答案为 <code>abs(25 - 52) = 27</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 10</span></p>

<p><strong>输出：</strong> <span class="example-io">9</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>reverse(10) = 01</code>，即 1。</li>
	<li>因此，答案为 <code>abs(10 - 1) = 9</code>。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 7</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>reverse(7) = 7</code>。</li>
	<li>因此，答案为 <code>abs(7 - 7) = 0</code>。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：数学

如何获得一个整数的reverse？ 这样就好：

```cpp
inline int reverse(int n) {
    int ans = 0;
    while (n) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}
```

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-18 18:53:10
 */
class Solution {
private:
    inline int reverse(int n) {
        int ans = 0;
        while (n) {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160284745)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/18/LeetCode%203783.%E6%95%B4%E6%95%B0%E7%9A%84%E9%95%9C%E5%83%8F%E8%B7%9D%E7%A6%BB/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
