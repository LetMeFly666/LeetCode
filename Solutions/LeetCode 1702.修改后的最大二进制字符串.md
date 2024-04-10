---
title: 1702.修改后的最大二进制字符串
date: 2024-04-10 13:01:22
tags: [题解, LeetCode, 中等, 贪心, 字符串, 构造]
---

# 【LetMeFly】1702.修改后的最大二进制字符串：脑筋急转弯（构造，贪心）

力扣题目链接：[https://leetcode.cn/problems/maximum-binary-string-after-change/](https://leetcode.cn/problems/maximum-binary-string-after-change/)

<p>给你一个二进制字符串 <code>binary</code> ，它仅有 <code>0</code> 或者 <code>1</code> 组成。你可以使用下面的操作任意次对它进行修改：</p>

<ul>
	<li>操作 1 ：如果二进制串包含子字符串 <code>"00"</code> ，你可以用 <code>"10"</code> 将其替换。

	<ul>
		<li>比方说， <code>"<strong>00</strong>010" -> "<strong>10</strong>010"</code></li>
	</ul>
	</li>
	<li>操作 2 ：如果二进制串包含子字符串 <code>"10"</code> ，你可以用 <code>"01"</code> 将其替换。
	<ul>
		<li>比方说， <code>"000<strong>10</strong>" -> "000<strong>01</strong>"</code></li>
	</ul>
	</li>
</ul>

<p>请你返回执行上述操作任意次以后能得到的 <strong>最大二进制字符串</strong> 。如果二进制字符串 <code>x</code> 对应的十进制数字大于二进制字符串 <code>y</code> 对应的十进制数字，那么我们称二进制字符串<em> </em><code>x</code><em> </em>大于二进制字符串<em> </em><code>y</code><em> </em>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>binary = "000110"
<b>输出：</b>"111011"
<b>解释：</b>一个可行的转换为：
"0001<strong>10</strong>" -> "0001<strong>01</strong>" 
"<strong>00</strong>0101" -> "<strong>10</strong>0101" 
"1<strong>00</strong>101" -> "1<strong>10</strong>101" 
"110<strong>10</strong>1" -> "110<strong>01</strong>1" 
"11<strong>00</strong>11" -> "11<strong>10</strong>11"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>binary = "01"
<b>输出：</b>"01"
<b>解释：</b>"01" 没办法进行任何转换。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= binary.length <= 10<sup>5</sup></code></li>
	<li><code>binary</code> 仅包含 <code>'0'</code> 和 <code>'1'</code> 。</li>
</ul>


    
## 解题方法：构造（贪心）

### 题目分析

如果给定字符串中没有```0```，则不在本次讨论的范围之列，直接返回原字符串。

**推论1：最终字符串中一定有0**

仅有的两种变换分别是```00->10```和```10->01```，只能减少```0```的个数，但永远不可能将所有```0```消除。

**推论2：最终字符串中一定只有一个0**

以```10111011```为例，该字符串中有两个```0```，则可以进行以下变换```10111011->10011111->11011111```，具体变换过程如下：

```
10111011
10110111 ---+
10101111    +---后面的那个0不断地通过10->01的变换最终和前面那个0相邻
10011111 ---+
11011111 -> 相邻两个0通过00->10的变换使得二进制字符串相比于初始值更大了
```

也就是说，假设最终字符串中有两个```0```，那么后面的那个```0```一定可以通过```10->01```的变换与前面的```0```相邻，相邻两个```0```再通过```00->10```变换，使得第一个```0```变成了```1```，字符串值更大了。

若有多个```0```则同理，最终一定只剩下一个```0```，变成```111..11011..111```的形态。

为什么不继续变化了呢？因为```11```、```01```都不可变，唯一可变的是```10->01```。但是这么变的话相当于“```0```往前移”了，字符串值更小，不可取。

**如何判断最终字符串中0的位置？**

由给定的两种变换```00->10```和```10->01```可以发现，```0```要么被消除（变换一）要么左移（变换二），单纯的左移会导致字符串变小，因此尽量将最前面的```0```“消除”。

如何消除？通过变换一消除。通过推论2我们知道，只要存在两个```0```，则右边的```0```必定能千里迢迢地来到左边的```0```身边并与之进行变换一：

```
111..11011..11011..11
111..11001..11111..11
111..11101..11111..11
```

也就是说，第一个```0```的右边每存在一个```0```，就能让第一个```0```的位置“右移一位”。

最终第一个```0```（也就是唯一的一个```0```）的位置，是原始字符串中第一个```0```的位置，再右移$0的总个数 - 1$位。

### 具体方法

给定字符串，统计其中```0```的个数（记为```cnt0```）。

若无```0```，则直接返回原始字符串；否则继续。

找到字符串中第一个```0```的位置（记为```pos0```），构造一个只有```pos0 + cnt0 - 1```这个位置为```0```其余位置全部为```1```的字符串并返回。

### 时空复杂度分析

+ 时间复杂度$O(len(binary))$
+ 空间复杂度$O(len(binary))$：空间复杂度来自字符串构造过程中的临时变量。

### AC代码

#### C++

```cpp
class Solution {
public:
    string maximumBinaryString(string binary) {
        int cnt0 = count(binary.begin(), binary.end(), '0');
        if (!cnt0) {
            return binary;
        }
        int first0 = binary.find('0');
        return string(first0 + (cnt0 - 1), '1') + '0' + string(binary.size() - (first0 + (cnt0 - 1)) - 1, '1');
    }
};
```

#### Python

```python
class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        cnt0 = binary.count('0')
        if not cnt0:
            return binary
        first0 = binary.find('0')
        pos0 = first0 + (cnt0 - 1)
        return '1' * pos0 + '0' + '1' * (len(binary) - pos0 - 1)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/10/LeetCode%201702.%E4%BF%AE%E6%94%B9%E5%90%8E%E7%9A%84%E6%9C%80%E5%A4%A7%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137593422](https://letmefly.blog.csdn.net/article/details/137593422)
