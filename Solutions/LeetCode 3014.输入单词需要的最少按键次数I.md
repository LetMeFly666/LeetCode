---
title: 3014.输入单词需要的最少按键次数 I：遍历 / if-else计算(比纯数学公式写起来麻烦但好想)
date: 2026-07-30 19:02:09
tags: [题解, LeetCode, 简单, 贪心, 数学, 字符串]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2023/12/26/keypaddesc.png
---

# 【LetMeFly】3014.输入单词需要的最少按键次数 I：遍历 / if-else计算(比纯数学公式写起来麻烦但好想)

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-i/](https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-i/)

<p>给你一个字符串 <code>word</code>，由 <strong>不同 </strong>小写英文字母组成。</p>

<p>电话键盘上的按键与 <strong>不同 </strong>小写英文字母集合相映射，可以通过按压按键来组成单词。例如，按键 <code>2</code> 对应 <code>["a","b","c"]</code>，我们需要按一次键来输入 <code>"a"</code>，按两次键来输入 <code>"b"</code>，按三次键来输入 <code>"c"</code><em>。</em></p>

<p>现在允许你将编号为 <code>2</code> 到 <code>9</code> 的按键重新映射到 <strong>不同 </strong>字母集合。每个按键可以映射到<strong> 任意数量 </strong>的字母，但每个字母 <strong>必须</strong> <strong>恰好</strong> 映射到 <strong>一个 </strong>按键上。你需要找到输入字符串 <code>word</code> 所需的<strong> 最少 </strong>按键次数。</p>

<p>返回重新映射按键后输入 <code>word</code> 所需的 <strong>最少 </strong>按键次数。</p>

<p>下面给出了一种电话键盘上字母到按键的映射作为示例。注意 <code>1</code>，<code>*</code>，<code>#</code> 和 <code>0</code> <strong>不</strong> 对应任何字母。</p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/12/26/keypaddesc.png" style="width: 329px; height: 313px;" />
<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/12/26/keypadv1e1.png" style="width: 329px; height: 313px;" />
<pre>
<strong>输入：</strong>word = "abcde"
<strong>输出：</strong>5
<strong>解释：</strong>图片中给出的重新映射方案的输入成本最小。
"a" -&gt; 在按键 2 上按一次
"b" -&gt; 在按键 3 上按一次
"c" -&gt; 在按键 4 上按一次
"d" -&gt; 在按键 5 上按一次
"e" -&gt; 在按键 6 上按一次
总成本为 1 + 1 + 1 + 1 + 1 = 5 。
可以证明不存在其他成本更低的映射方案。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/12/26/keypadv1e2.png" style="width: 329px; height: 313px;" />
<pre>
<strong>输入：</strong>word = "xycdefghij"
<strong>输出：</strong>12
<strong>解释：</strong>图片中给出的重新映射方案的输入成本最小。
"x" -&gt; 在按键 2 上按一次
"y" -&gt; 在按键 2 上按两次
"c" -&gt; 在按键 3 上按一次
"d" -&gt; 在按键 3 上按两次
"e" -&gt; 在按键 4 上按一次
"f" -&gt; 在按键 5 上按一次
"g" -&gt; 在按键 6 上按一次
"h" -&gt; 在按键 7 上按一次
"i" -&gt; 在按键 8 上按一次
"j" -&gt; 在按键 9 上按一次
总成本为 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12 。
可以证明不存在其他成本更低的映射方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 26</code></li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
	<li><code>word</code> 中的所有字母互不相同。</li>
</ul>


## 解题思路

一共有8个可用按键，分配按键时应该优先使用按1次的位置，分配完再分配按2次的位置，...。

## 解题方法一：遍历

从$0$到$len(word)-1$遍历，第$i$个字母的按键次数为$\lfloor\frac{i}{8}\rfloor+1$。

+ 时间复杂度$O(len(word))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-30 19:00:50
 */
class Solution {
public:
    int minimumPushes(string& word) {
        int ans = 0;
        for (int i = 0, n = word.size(); i < n; i++) {
            ans += i / 8 + 1;
        }
        return ans;
    }
};
```

## 解题方法二：if-else计算

如果字母个数为1-8, 则每个字母只需要按一次；

否则（先分配8个字母共计需要按8次）如果字母个数为9-16, 则第9-16个字母需要按两次；

否则（再分配8个需要按两次的字母）如果字母个数为17-24, 则第17-24个字母需要按三次；

否则（再分配8个需要按三次的字母），第25-n个字母需要按四次。

+ 时间复杂度$O(1)$，其实是$\lfloor\frac{len(word)}{8}\rfloor$
+ 空间复杂度$O(1)$

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-30 18:59:13
 */
class Solution {
public:
    int minimumPushes(string& word) {
        // 1-8: n
        // 9-16: 2n
        // 17-24: 3n
        // 25-26: 4n
        int n = word.size();
        int cnt = 0;
        if (n <= 8) {
            return n;
        }
        cnt += 8;
        if (n <= 16) {
            return cnt + (n - 8) * 2;
        }
        cnt += 8 * 2;
        if (n <= 24) {
            return cnt + (n - 16) * 3;
        }
        cnt += 8 * 3;
        return cnt + (n - 24) * 4;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163342773)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/30/LeetCode%203014.%E8%BE%93%E5%85%A5%E5%8D%95%E8%AF%8D%E9%9C%80%E8%A6%81%E7%9A%84%E6%9C%80%E5%B0%91%E6%8C%89%E9%94%AE%E6%AC%A1%E6%95%B0I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
