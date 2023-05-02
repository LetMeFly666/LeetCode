---
title: 970.强整数
date: 2023-05-02 10:20:42
tags: [题解, LeetCode, 中等, 哈希表, set, 数学, 枚举]
---

# 【LetMeFly】970.强整数

力扣题目链接：[https://leetcode.cn/problems/powerful-integers/](https://leetcode.cn/problems/powerful-integers/)

<p>给定三个整数 <code>x</code>&nbsp;、&nbsp;<code>y</code>&nbsp;和<em>&nbsp;</em><code>bound</code><em>&nbsp;</em>，返回 <em>值小于或等于&nbsp;<code>bound</code>&nbsp;的所有&nbsp;<strong>强整数</strong>&nbsp;组成的列表</em>&nbsp;。</p>

<p>如果某一整数可以表示为&nbsp;<code>x<sup>i</sup>&nbsp;+ y<sup>j</sup></code>&nbsp;，其中整数&nbsp;<code>i &gt;= 0</code> 且&nbsp;<code>j &gt;= 0</code>，那么我们认为该整数是一个&nbsp;<strong>强整数</strong>&nbsp;。</p>

<p>你可以按 <strong>任何顺序</strong> 返回答案。在你的回答中，每个值 <strong>最多</strong> 出现一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 2, y = 3, bound = 10
<strong>输出：</strong>[2,3,4,5,7,9,10]
<strong>解释： </strong>
2 = 2<sup>0</sup> + 3<sup>0</sup>
3 = 2<sup>1</sup> + 3<sup>0</sup>
4 = 2<sup>0</sup> + 3<sup>1</sup>
5 = 2<sup>1</sup> + 3<sup>1</sup>
7 = 2<sup>2</sup> + 3<sup>1</sup>
9 = 2<sup>3</sup> + 3<sup>0</sup>
10 = 2<sup>0</sup> + 3<sup>2</sup></pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>x = 3, y = 5, bound = 15
<strong>输出：</strong>[2,4,6,8,10,14]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x, y &lt;= 100</code></li>
	<li><code>0 &lt;= bound &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：枚举

如果$x = 1$，那么$x^i=1$，只有一种情况

否则则有$x\geq2$，那么$x^{20}\geq2^{20}=1048576\gt10^6$，最多有20种情况

所以我们直接枚举即可。当超过$bound$或者$x=1$时，退出循环（y同理）

```python
i = 0
while True:
    first = x ** i
    if first > bound:
        break
    # 枚举j
    if x == 1:
        break
    i += 1
```

当然，我们也可以无脑从0枚举到20，这样退出循环的条件比较少，不容易出错

+ 时间复杂度$O(\log^2bound)$
+ 空间复杂度$O(\log bound)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> se;
        int i = 0;
        while (true) {
            int first = pow(x, i);
            if (first > bound) {
                break;
            }
            int j = 0;
            while (true) {
                int second = pow(y, j);
                int s = first + second;
                if (s > bound) {
                    break;
                }
                se.insert(s);
                if (y == 1) {
                    break;
                }
                j++;
            }
            if (x == 1) {
                break;
            }
            i++;
        }
        return vector<int>(se.begin(), se.end());
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        se = set()
        i = 0
        while True:
            first = x ** i
            if first > bound:
                break

            j = 0
            while True:
                second = y ** j
                s = first + second
                if s > bound:
                    break
                se.add(s)
                if y == 1:
                    break
                j += 1

            if x == 1:
                break
            i += 1
        return list(se)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/05/02/LeetCode%200970.%E5%BC%BA%E6%95%B4%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130461751](https://letmefly.blog.csdn.net/article/details/130461751)
