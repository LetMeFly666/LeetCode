---
title: 1888.使二进制字符串字符交替的最少反转次数：前缀和O(1)
date: 2026-03-08 15:09:24
tags: [题解, LeetCode, 中等, 字符串, 动态规划, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】1888.使二进制字符串字符交替的最少反转次数：前缀和O(1)

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/](https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

<p>给你一个二进制字符串 <code>s</code> 。你可以按任意顺序执行以下两种操作任意次：</p>

<ul>
	<li><strong>类型 1 ：删除</strong> 字符串 <code>s</code> 的第一个字符并将它 <strong>添加</strong> 到字符串结尾。</li>
	<li><strong>类型 2 ：选择 </strong>字符串 <code>s</code> 中任意一个字符并将该字符 <strong>反转 </strong>，也就是如果值为 <code>'0'</code> ，则反转得到 <code>'1'</code> ，反之亦然。</li>
</ul>

<p>请你返回使 <code>s</code> 变成 <strong>交替</strong> 字符串的前提下， <strong>类型 2 </strong>的 <strong>最少</strong> 操作次数 。</p>

<p>我们称一个字符串是 <strong>交替</strong> 的，需要满足任意相邻字符都不同。</p>

<ul>
	<li>比方说，字符串 <code>"010"</code> 和 <code>"1010"</code> 都是交替的，但是字符串 <code>"0100"</code> 不是。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "111000"
<b>输出：</b>2
<b>解释：</b>执行第一种操作两次，得到 s = "100011" 。
然后对第三个和第六个字符执行第二种操作，得到 s = "10<strong>1</strong>01<strong>0</strong>" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "010"
<b>输出：</b>0
<strong>解释：</strong>字符串已经是交替的。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>s = "1110"
<b>输出：</b>1
<b>解释：</b>对第二个字符执行第二种操作，得到 s = "1<strong>0</strong>10" 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 要么是 <code>'0'</code> ，要么是 <code>'1'</code> 。</li>
</ul>


    
## 解题方法：前缀和

如果没有操作1（字符串轮转），那么问题就变成了[1758. 生成交替二进制字符串的最少操作数](https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/)。

现在多了个操作1，有什么用呢？

> 例如`110`，把`1`往后轮转，就变成了`101`，就不用翻转操作了。

其实不难发现轮转操作只对字符串长度为奇数时候有效：

> 如果字符串长度为偶数的话，最终有效的`1010`要么由`1010`变来，要么由`0101`变来。总之就是最终的01交替字符串无论是经过怎样的轮转得来的，其轮转之前就一定是01交替字符串。
>
> 但是奇数长度的字符串就不一样了，奇数长度的01字符串首位字符相同，所以最终有效的01字符串首位字符一定相同（如`10101`），所以就可能是原有两个相邻相同元素拆开轮转得到的（如`01101`）

所以我们模拟这个“拆开的位置”就好了。对于奇数长度的字符串，先假设变成0开头0结尾：

具体来说，`01101`如果全部变成`01010`需要改变3次，从前到后遍历字符串，遍历过`01`后，若从此处拆开，相当于后面本来要变成`010`的三个字符要变成`101`，后面只需要变化`len(101) - 3 = 0`次就好了。

记下全部变成`010`需要反转的次数，然后从前到后遍历，记录下遍历到的位置为止变成`010..`需要反转的次数，那么后面变成`101...`需要的次数就是`len(后面字符串长度) - (原本总反转次数 - 前面已经反转次数)`

讨论过变成010后，变成101同理。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-08 11:41:56
 */
/*
01001001101
   3次右移
01001101010
   ||
01010101010

相当于
01001001101
      ||
01001010101
  --
01010101010
_         _
*/
class Solution {
public:
    int minFlips(const string& s) {
        int total = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            total += s[i] % 2 == i % 2;
        }
        int ans = min(total, n - total);
        if (n % 2 == 0) {
            return ans;
        }
        for (int i = 0, now = 0; i < n; i++) {
            now += s[i] % 2 == i % 2;
            int original_front = now;
            int original_back = total - original_front;
            int changed_front = i + 1 - original_front;
            int changed_back = n - i - 1 - original_back;
            ans = min(ans, min(original_front + changed_back, changed_front + original_back));
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
001000000010
|   | | |
101010101010

001000000010
    | | |
001010101010
-  右移一位
010101010100
   3次不可

4
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.minFlips(s) << endl;
    }
    return 0;
}
#endif
```

## 解题方法二：滑动窗口

其实也可以把字符串double，然后定长滑动窗口len(s)，求每个窗口变成010或101的最小次数。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158813763)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/07/LeetCode%201888.%E4%BD%BF%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%AD%97%E7%AC%A6%E4%BA%A4%E6%9B%BF%E7%9A%84%E6%9C%80%E5%B0%91%E5%8F%8D%E8%BD%AC%E6%AC%A1%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
