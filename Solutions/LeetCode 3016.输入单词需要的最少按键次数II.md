---
title: 3016.输入单词需要的最少按键次数 II：排序（贪心）
date: 2026-07-31 08:30:50
tags: [题解, LeetCode, 中等, 贪心, 字符串, 计数, 排序]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2023/12/26/keypaddesc.png
---

# 【LetMeFly】3016.输入单词需要的最少按键次数 II：排序（贪心）

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-ii/](https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-ii/)

<p>给你一个字符串 <code>word</code>，由小写英文字母组成。</p>

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
<img alt="" src="https://assets.leetcode.com/uploads/2023/12/26/keypadv2e2.png" style="width: 329px; height: 313px;" />
<pre>
<strong>输入：</strong>word = "xyzxyzxyzxyz"
<strong>输出：</strong>12
<strong>解释：</strong>图片中给出的重新映射方案的输入成本最小。
"x" -&gt; 在按键 2 上按一次
"y" -&gt; 在按键 3 上按一次
"z" -&gt; 在按键 4 上按一次
总成本为 1 * 4 + 1 * 4 + 1 * 4 = 12 。
可以证明不存在其他成本更低的映射方案。
注意按键 9 没有映射到任何字母：不必让每个按键都存在与之映射的字母，但是每个字母都必须映射到按键上。
</pre>

<p><strong class="example">示例 3：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/12/27/keypadv2.png" style="width: 329px; height: 313px;" />
<pre>
<strong>输入：</strong>word = "aabbccddeeffgghhiiiiii"
<strong>输出：</strong>24
<strong>解释：</strong>图片中给出的重新映射方案的输入成本最小。
"a" -&gt; 在按键 2 上按一次
"b" -&gt; 在按键 3 上按一次
"c" -&gt; 在按键 4 上按一次
"d" -&gt; 在按键 5 上按一次
"e" -&gt; 在按键 6 上按一次
"f" -&gt; 在按键 7 上按一次
"g" -&gt; 在按键 8 上按一次
"h" -&gt; 在按键 9 上按两次
"i" -&gt; 在按键 9 上按一次
总成本为 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24 。
可以证明不存在其他成本更低的映射方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
</ul>


    
## 解题方法：排序

贪心思路：出现次数多的字符分配到按键次数少的位置。

遍历一遍原始字符串，使用一个大小为$26$的数组记录每种字符的出现次数，把出现次数按从大到小的顺序排序，接着按照只用按1次的位置开始分配（最多分配8个字符）、需要按2次的位置继续分配（最多分配8个字符）、...、直至分配完毕为止。

分配完的标志可以视为26种字符处理完毕，也可视为处理到了出现次数为0的字符。

+ 时间复杂度$O(len(w) + C\log C)$，其中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-31 08:24:25
 */
class Solution {
public:
    int minimumPushes(string& word) {
        int cnt[26] = {0};
        for (char c : word) {
            cnt[c - 'a']++;
        }
        ranges::sort(cnt, greater<>());
        int ans = 0, round = 1, th = 0;
        for (int t : cnt) {
            th++;
            if (th == 9) {
                th = 1;
                round++;
            }
            ans += t * round;
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163353536)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/31/LeetCode%203016.%E8%BE%93%E5%85%A5%E5%8D%95%E8%AF%8D%E9%9C%80%E8%A6%81%E7%9A%84%E6%9C%80%E5%B0%91%E6%8C%89%E9%94%AE%E6%AC%A1%E6%95%B0II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
