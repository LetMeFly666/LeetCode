---
title: 1375.二进制字符串前缀一致的次数
date: 2023-06-14 18:03:58
tags: [题解, LeetCode, 中等, 数组, 思维]
---

# 【LetMeFly】1375.二进制字符串前缀一致的次数

力扣题目链接：[https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/](https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/)

<p>给你一个长度为 <code>n</code> 、下标从 <strong>1</strong> 开始的二进制字符串，所有位最开始都是 <code>0</code> 。我们会按步翻转该二进制字符串的所有位（即，将 <code>0</code> 变为 <code>1</code>）。</p>

<p>给你一个下标从 <strong>1</strong> 开始的整数数组 <code>flips</code> ，其中 <code>flips[i]</code> 表示对应下标 <code>i</code> 的位将会在第 <code>i</code> 步翻转。</p>

<p>二进制字符串 <strong>前缀一致</strong> 需满足：在第 <code>i</code> 步之后，在 <strong>闭</strong> 区间&nbsp;<code>[1, i]</code> 内的所有位都是 1 ，而其他位都是 0 。</p>

<p>返回二进制字符串在翻转过程中 <strong>前缀一致</strong> 的次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>flips = [3,2,4,1,5]
<strong>输出：</strong>2
<strong>解释：</strong>二进制字符串最开始是 "00000" 。
执行第 1 步：字符串变为 "00100" ，不属于前缀一致的情况。
执行第 2 步：字符串变为 "01100" ，不属于前缀一致的情况。
执行第 3 步：字符串变为 "01110" ，不属于前缀一致的情况。
执行第 4 步：字符串变为 "11110" ，属于前缀一致的情况。
执行第 5 步：字符串变为 "11111" ，属于前缀一致的情况。
在翻转过程中，前缀一致的次数为 2 ，所以返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>flips = [4,1,2,3]
<strong>输出：</strong>1
<strong>解释：</strong>二进制字符串最开始是 "0000" 。
执行第 1 步：字符串变为 "0001" ，不属于前缀一致的情况。
执行第 2 步：字符串变为 "1001" ，不属于前缀一致的情况。
执行第 3 步：字符串变为 "1101" ，不属于前缀一致的情况。
执行第 4 步：字符串变为 "1111" ，属于前缀一致的情况。
在翻转过程中，前缀一致的次数为 1 ，所以返回 1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == flips.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>flips</code> 是范围 <code>[1, n]</code> 中所有整数构成的一个排列</li>
</ul>


    
## 方法一：思维

这道题不用线段树前缀和什么什么的，想明白了其实很简单。

如果前$i$个全是$1$其他全是$0$，那么说明前$i$次操作正好翻转的前$i$个元素。

我们只需要记录一下最大的翻转下标即可，如果最大翻转下标等于当前翻转次数，就说明前$i$个全部翻转了，答案加一。

+ 时间复杂度$O(len(flips))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int M = 0;
        int ans = 0;
        for (int i = 0; i < flips.size(); i++) {
            M = max(flips[i], M);
            ans += (M == i + 1);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        M = 0
        ans = 0
        for i in range(len(flips)):
            M = max(M, flips[i])
            ans += (M == i + 1)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/14/LeetCode%201375.%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%89%8D%E7%BC%80%E4%B8%80%E8%87%B4%E7%9A%84%E6%AC%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131213418](https://letmefly.blog.csdn.net/article/details/131213418)
