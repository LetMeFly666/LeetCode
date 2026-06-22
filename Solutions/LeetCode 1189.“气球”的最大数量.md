---
title: 1189.“气球” 的最大数量：计数
date: 2026-06-22 19:49:21
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 计数]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/09/14/1536_ex1_upd.jpeg
---

# 【LetMeFly】1189.“气球” 的最大数量：计数

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-balloons/](https://leetcode.cn/problems/maximum-number-of-balloons/)

<p>给你一个字符串&nbsp;<code>text</code>，你需要使用 <code>text</code> 中的字母来拼凑尽可能多的单词&nbsp;<strong>"balloon"（气球）</strong>。</p>

<p>字符串&nbsp;<code>text</code> 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词&nbsp;<strong>"balloon"</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/09/14/1536_ex1_upd.jpeg" style="height: 35px; width: 154px;" /></strong></p>

<pre>
<strong>输入：</strong>text = "nlaebolko"
<strong>输出：</strong>1
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/09/14/1536_ex2_upd.jpeg" style="height: 35px; width: 233px;" /></strong></p>

<pre>
<strong>输入：</strong>text = "loonbalxballpoon"
<strong>输出：</strong>2
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>text = "leetcode"
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 10<sup>4</sup></code></li>
	<li><code>text</code>&nbsp;全部由小写英文字母组成</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与&nbsp;<a href="https://leetcode.cn/problems/rearrange-characters-to-make-target-string/">2287. 重排字符形成目标字符串</a>&nbsp;相同。</p>


    
## 解题方法：计数

使用26个（或5个）整数(数组)统计每种字母出现了多少次，则能组成的balloon的个数为以下的最小值：

+ `b`出现次数
+ `a`出现次数
+ `l`出现次数除以二
+ `o`出现次数
+ `n`出现次数

以上。

+ 时间复杂度$O(len(text))$
+ 空间复杂度$O(C)$，其中$C=26$或$C=5$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-22 19:44:41
 */
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26] = {0};
        for (char c : text) {
            cnt[c - 'a']++;
        }
        return min(cnt['b' - 'a'], 
            min(cnt['a' - 'a'],
            min(cnt['l' - 'a'] / 2,
            min(cnt['o' - 'a'] / 2,
            cnt['n' - 'a'])
        )));
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162210645)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/22/LeetCode%201189.%E2%80%9C%E6%B0%94%E7%90%83%E2%80%9D%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E9%87%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
