---
title: 3121.统计特殊字母的数量 II：状态机
date: 2026-05-27 22:34:39
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 状态机]
categories: [题解, LeetCode]
---

# 【LetMeFly】3121.统计特殊字母的数量 II：状态机

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-special-characters-ii/](https://leetcode.cn/problems/count-the-number-of-special-characters-ii/)

<p>给你一个字符串 <code>word</code>。如果 <code>word</code> 中同时出现某个字母 <code>c</code> 的小写形式和大写形式，并且<strong> 每个 </strong>小写形式的 <code>c</code> 都出现在第一个大写形式的 <code>c</code> 之前，则称字母 <code>c</code> 是一个 <strong>特殊字母</strong> 。</p>

<p>返回 <code>word</code> 中 <strong>特殊字母</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "aaAbcBC"</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>特殊字母是 <code>'a'</code>、<code>'b'</code> 和 <code>'c'</code>。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "abc"</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中不存在特殊字母。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">word = "AbBCab"</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p><code>word</code> 中不存在特殊字母。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>word</code> 仅由小写和大写英文字母组成。</li>
</ul>


    
## 解题方法：状态机

对于每种字母而言，一共有几种状态？

|状态|标记|
|:--:|:--:|
|初始状态|NONE|
|只遇到了小写字母|SMALL|
|遇到过小写字母且在此之后只遇到了大写字母|OK|
|此字母状态不合法|CANNOT|

遍历字符串，对于第$i$个字母：

+ 如果其状态是NONE：
    
    + 如果这个字母是小写，则转为SMALL
    + 否则不合法，转为CANNOT

+ 如果其状态是SMALL:

    + 如果这个字母是大写，则这个字母到目前为止满足条件，转为OK，答案数量加一

+ 如果其状态是OK：

    + 如果这个字母是小写，则大写后出现小写不合法，转为CANNOT，答案数量减一

+ 否则（状态已经是CANNOT），不用管了，反正这个字母没希望了

以上。

+ 时间复杂度$O(len(word))$
+ 空间复杂度$O(C)$，其中$C=26$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-27 22:33:20
 */
enum State {
    NONE,
    SMALL,
    OK,
    CANNOT,
};

class Solution {
public:
    int numberOfSpecialChars(string word) {
        State state[26];
        int ans = 0;
        for (char c : word) {
            bool small = 'a' <= c && c <= 'z';
            int idx = small ? c - 'a' : c - 'A';
            switch (state[idx]) {
            case NONE:
                state[idx] = small ? SMALL : CANNOT;
                break;
            case SMALL:
                if (!small) {
                    state[idx] = OK;
                    ans++;
                }
                break;
            case OK:
                if (small) {
                    state[idx] = CANNOT;
                    ans--;
                }
                break;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161463196)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/27/LeetCode%203121.%E7%BB%9F%E8%AE%A1%E7%89%B9%E6%AE%8A%E5%AD%97%E6%AF%8D%E7%9A%84%E6%95%B0%E9%87%8FII/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
