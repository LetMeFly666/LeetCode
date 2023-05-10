---
title: 1812.判断国际象棋棋盘中一个格子的颜色
date: 2022-12-08 09:23:33
tags: [题解, LeetCode, 简单, 数学, 字符串, 取模]
---

# 【LetMeFly】1812.判断国际象棋棋盘中一个格子的颜色

力扣题目链接：[https://leetcode.cn/problems/determine-color-of-a-chessboard-square/](https://leetcode.cn/problems/determine-color-of-a-chessboard-square/)

<p>给你一个坐标 <code>coordinates</code> ，它是一个字符串，表示国际象棋棋盘中一个格子的坐标。下图是国际象棋棋盘示意图。</p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/04/03/chessboard.png" style="width: 400px; height: 396px;" /></p>

<p>如果所给格子的颜色是白色，请你返回 <code>true</code>，如果是黑色，请返回 <code>false</code> 。</p>

<p>给定坐标一定代表国际象棋棋盘上一个存在的格子。坐标第一个字符是字母，第二个字符是数字。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>coordinates = "a1"
<b>输出：</b>false
<b>解释：</b>如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>coordinates = "h3"
<b>输出：</b>true
<b>解释：</b>如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>coordinates = "c7"
<b>输出：</b>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>coordinates.length == 2</code></li>
	<li><code>'a' <= coordinates[0] <= 'h'</code></li>
	<li><code>'1' <= coordinates[1] <= '8'</code></li>
</ul>


    
## 方法一：取模

其实不难发现，```a1```、```a3```、```a5```是黑色，```a2```、```a4```是白色，```b2```是黑色

我们把```a ~ h```映射为```0 ~ 7```，把```1 ~ 8```也映射为```0 ~ 7```，此时我们就能发现，当字母映射成的数字和数字映射成的数字的奇偶性相同时，格子为黑色。

因此，我们只需要判断```字母 - 'a'```和```数字 - '1'```的奇偶性是否相同，若不同则为白色，返回```true```

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] - 'a') % 2 != (coordinates[1] - '1') % 2;
    }
};
```

## 方法二：基于方法一的小改进

方法一中我们令字母减```'a'```令数字减```'1'```，然后判断二者奇偶性是否相同。

方法二中我们对此做一个小小的优化：

```a```的ASCII码是```97```，```1```的ASCII码是```49```，二者本来奇偶性就相同。

因此，在方法二中，我们可以“字母不减```'a'```”了，“数字也不减```'1'```”了，直接判断字母和数字的奇偶性是否相同即可

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return coordinates[0] % 2 != coordinates[1] % 2;
    }
};
```

方法二相比于方法一少了两次减法运算。

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/08/LeetCode%201812.%E5%88%A4%E6%96%AD%E5%9B%BD%E9%99%85%E8%B1%A1%E6%A3%8B%E6%A3%8B%E7%9B%98%E4%B8%AD%E4%B8%80%E4%B8%AA%E6%A0%BC%E5%AD%90%E7%9A%84%E9%A2%9C%E8%89%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128231293](https://letmefly.blog.csdn.net/article/details/128231293)
