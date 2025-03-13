---
title: 299.猜数字游戏
date: 2024-03-10 11:56:34
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】299.猜数字游戏：计数

力扣题目链接：[https://leetcode.cn/problems/bulls-and-cows/](https://leetcode.cn/problems/bulls-and-cows/)

<p>你在和朋友一起玩 <a href="https://baike.baidu.com/item/%E7%8C%9C%E6%95%B0%E5%AD%97/83200?fromtitle=Bulls+and+Cows&amp;fromid=12003488&amp;fr=aladdin" target="_blank">猜数字（Bulls and Cows）</a>游戏，该游戏规则如下：</p>

<p>写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：</p>

<ul>
	<li>猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），</li>
	<li>有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。</li>
</ul>

<p>给你一个秘密数字&nbsp;<code>secret</code> 和朋友猜测的数字&nbsp;<code>guess</code> ，请你返回对朋友这次猜测的提示。</p>

<p>提示的格式为 <code>"xAyB"</code> ，<code>x</code> 是公牛个数， <code>y</code> 是奶牛个数，<code>A</code> 表示公牛，<code>B</code>&nbsp;表示奶牛。</p>

<p>请注意秘密数字和朋友猜测的数字都可能含有重复数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>secret = "1807", guess = "7810"
<strong>输出：</strong>"1A3B"
<strong>解释：</strong>数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1807"
  |
"<em><strong>7</strong></em>8<em><strong>10</strong></em>"</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>secret = "1123", guess = "0111"
<strong>输出：</strong>"1A1B"
<strong>解释：</strong>数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1123"        "1123"
  |      or     |
"01<em><strong>1</strong></em>1"        "011<em><strong>1</strong></em>"
注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= secret.length, guess.length &lt;= 1000</code></li>
	<li><code>secret.length == guess.length</code></li>
	<li><code>secret</code> 和 <code>guess</code> 仅由数字组成</li>
</ul>


    
## 方法一：计数

+ $A$的值为：```secret[i] == guess[i]```的个数
+ $A+B$的值为：```secret```中与```guess```中相同数字的个数

因此使用两个大小为$10$的整数数组（或哈希表）来分别存放两个字符串中每个数字出现的次数，$\min(bin1[i], bin2[i])$之和即为$A+B$的值。

+ 时间复杂度$O(len(secrets) + C)$，其中$C=10$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int se[10] = {0}, gu[10] = {0};
        int A = 0, AB = 0;
        for (char c : secret) {
            se[c - '0']++;
        }
        for (int i = 0; i < guess.size(); i++) {
            gu[guess[i] - '0']++;
            if (guess[i] == secret[i]) {
                A++;
            }
        }
        for (int i = 0; i < 10; i++) {
            AB += min(se[i], gu[i]);
        }
        return to_string(A) + "A" + to_string(AB - A) + "B";
    }
};
```

#### Python

```python
from collections import Counter

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        A = sum(secret[i] == guess[i] for i in range(len(secret)))
        AB = sum((Counter(secret) & Counter(guess)).values())
        return f'{A}A{AB - A}B'
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/10/LeetCode%200299.%E7%8C%9C%E6%95%B0%E5%AD%97%E6%B8%B8%E6%88%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136598725](https://letmefly.blog.csdn.net/article/details/136598725)
