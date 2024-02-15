---
title: 467.环绕字符串中唯一的子字符串
date: 2022-05-25 13:45:46
tags: [题解, LeetCode, 中等, dp, 动态规划, 子问题]
---

# 【LetMeFly】467.环绕字符串中唯一的子字符串

力扣题目链接：[https://leetcode.cn/problems/unique-substrings-in-wraparound-string/](https://leetcode.cn/problems/unique-substrings-in-wraparound-string/)

把字符串```s```看作是```“abcdefghijklmnopqrstuvwxyz”```的无限环绕字符串，所以```s```看起来是这样的：

+ ```"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...."``` . 

现在给定另一个字符串```p```。返回```s```中 **唯一** 的```p```的 **非空子串** 的数量 。 

<del>笔者：<small>给LeetCode提的<a href="https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/7420">issue</a>通过了竟然。“唯一”改成了“不同”，虽然可能更容易理解了，但是与题目不匹配了。</small></del>

**示例 1:**

```
输入: p = "a"
输出: 1
解释: 字符串 s 中只有一个"a"子字符。
```

**示例 2:**

```
输入: p = "cac"
输出: 2
解释: 字符串 s 中的字符串“cac”只有两个子串“a”、“c”。
```

**示例 3:**

```
输入: p = "zab"
输出: 6
解释: 在字符串 s 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。
```

**提示:**

+ $1\leq p.length\leq 10^5$
+ $p$ 由小写英文字母构成

# 题目大意

给你一个全是小写字母的字符串p，让你找到其中所有的“连续递增子串”。

其中，“连续递增子串”满足：

> 后一个字母是前一个字母的下一个字母，字母z除外。
>  > 也就是说，a的下一个字母是b，b的下一个字母是c，...，z的下一个字母是a。

例如 “abc”、“xyz”、“zab”都是“连续递增子串”

# 思路

先讲一下我之前的思路，想直接看结论的话请点击[这里](#RightWay)

**子串来自于连续“递增”串**。也就是说某个串如果从左到右字母按字母序依次递增，这个串的所有连续子串都是答案。

于是我们只需要把原串划分成多个“连续递增串”，每个串的长度至少为1。这个步骤时间复杂度O(q.length)

对于某个划分出来的串(假设长度为l)，它的连续子串的个数是“l + (l - 1) + (l - 2) + ... + 1 = l * (l + 1) / 2”

但是这样会导致结果偏大，因为题目要求“**唯一**的p的非空子串”。其实我觉得改成“**不同**的”更好[。](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/7420)

如果仅计数，对于长度为l的串所需的时间复杂度就是O(1)，但如果要去重（以时间复杂度为O(1)的哈希表为例），那时间复杂度就会上升为O(l<sup>2</sup>)，显然会超时。

那么怎么办呢？接下来请出正题：动态规划。

<a id="RightWay"></a>

## 方法一：动态规划

其实不难发现：**如果答案串的长度定了，最后一个字符也定了，那么我们就可以唯一推断出这个字符串。**

> 例如例三中“zab”的一个“连续递增子串”是“ab”。我们知道了“ab”的长度(2)，也知道了“ab”的最后一个字母(b)，因此我们就能还原出原串为“ab”。

同时：**如果“ab”是答案串，那么“b”一定是答案串**。

> 这是因为“b”是“ab”的子串。

因此：

**我们只需要记录以各个字母结尾的串的最大长度，并将它们加起来就是答案。**

> 比如：用endBy[i] 代表以第i个小写字母结尾的串的最大长度，假设endBy[25] = 5，那么就说明存在以z结尾的串最大长度为5。也就是说p中存在子串“vwxyz”。这样我们就能得到以“z”结尾的符合条件的5个答案“vwxyz”、“wxyz”、“xyz”、“yz”、“z”。同时endBy[24]一定也不会为0，以“y”结尾的答案串累计道了endBy[24]中。

+ 时间复杂度$O(n)$，其中$n$是字符串$p$的长度。
+ 空间复杂度$O(|Σ|)$，其中$|Σ|$是字符集的大小。本题字符串由小写字母构成，因此$|Σ|=26$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findSubstringInWraproundString(string& p) {
        int endBy[26] = {0};
        int length = 0;
        for (int i = 0; i < p.size(); i++) {
            if (i && (p[i] - 'a') == (p[i - 1] - 'a' + 1) % 26) {
                length++;
            }
            else {
                length = 1;
            }
            endBy[p[i] - 'a'] = max(endBy[p[i] - 'a'], length);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
            ans += endBy[i];
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/05/25/LeetCode%200467.%E7%8E%AF%E7%BB%95%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E5%94%AF%E4%B8%80%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/124972046](https://letmefly.blog.csdn.net/article/details/124972046)
