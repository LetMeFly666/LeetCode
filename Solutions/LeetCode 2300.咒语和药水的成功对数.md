---
title: 2300.咒语和药水的成功对数：二分查找（附(lower/upper)_bound库函数大于小于个数查找表）
date: 2023-11-10 14:18:05
tags: [题解, LeetCode, 中等, 数组, 双指针, 二分查找, 二分, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2300.咒语和药水的成功对数：二分查找（附(lower/upper)_bound库函数大于小于个数查找表）

力扣题目链接：[https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/](https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/)

<p>给你两个正整数数组&nbsp;<code>spells</code> 和&nbsp;<code>potions</code>&nbsp;，长度分别为&nbsp;<code>n</code> 和&nbsp;<code>m</code>&nbsp;，其中&nbsp;<code>spells[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个咒语的能量强度，<code>potions[j]</code>&nbsp;表示第&nbsp;<code>j</code>&nbsp;瓶药水的能量强度。</p>

<p>同时给你一个整数&nbsp;<code>success</code>&nbsp;。一个咒语和药水的能量强度 <strong>相乘</strong> 如果&nbsp;<strong>大于等于</strong>&nbsp;<code>success</code>&nbsp;，那么它们视为一对&nbsp;<strong>成功</strong>&nbsp;的组合。</p>

<p>请你返回一个长度为 <code>n</code>&nbsp;的整数数组<em>&nbsp;</em><code>pairs</code>，其中<em>&nbsp;</em><code>pairs[i]</code>&nbsp;是能跟第 <code>i</code>&nbsp;个咒语成功组合的 <b>药水</b>&nbsp;数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>spells = [5,1,3], potions = [1,2,3,4,5], success = 7
<b>输出：</b>[4,0,3]
<strong>解释：</strong>
- 第 0 个咒语：5 * [1,2,3,4,5] = [5,<em><strong>10</strong></em>,<em><strong>15</strong></em>,<em><strong>20</strong></em>,<em><strong>25</strong></em>] 。总共 4 个成功组合。
- 第 1 个咒语：1 * [1,2,3,4,5] = [1,2,3,4,5] 。总共 0 个成功组合。
- 第 2 个咒语：3 * [1,2,3,4,5] = [3,6,<em><strong>9</strong></em>,<em><strong>12</strong></em>,<em><strong>15</strong></em>] 。总共 3 个成功组合。
所以返回 [4,0,3] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>spells = [3,1,2], potions = [8,5,8], success = 16
<b>输出：</b>[2,0,2]
<strong>解释：</strong>
- 第 0 个咒语：3 * [8,5,8] = [<em><strong>24</strong></em>,15,<em><strong>24</strong></em>] 。总共 2 个成功组合。
- 第 1 个咒语：1 * [8,5,8] = [8,5,8] 。总共 0 个成功组合。
- 第 2 个咒语：2 * [8,5,8] = [<em><strong>16</strong></em>,10,<em><strong>16</strong></em>] 。总共 2 个成功组合。
所以返回 [2,0,2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == spells.length</code></li>
	<li><code>m == potions.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= spells[i], potions[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= success &lt;= 10<sup>10</sup></code></li>
</ul>


    
## 解题方法：二分查找

我们首先将“毒药”数组从小到大排序，那么对于咒语$i$，计算出其想要达到$success$所需的最小毒药强度$toFind$，接着二分查找$toFind$的位置即可。

+ 时间复杂度$O(n\log n)$，其中$n=len(potions)$
+ 空间复杂度$O(log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2023-11-10 14:17:25
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-10 14:23:41
 */
typedef long long ll;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, ll success) {
        sort(potions.begin(), potions.end());
        for (int& t : spells) {
            ll toFind = success / t;
            if (toFind * t < success) {
                toFind++;
            }
            t = potions.end() - lower_bound(potions.begin(), potions.end(), toFind);
        }
        return spells;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2023-11-10 14:25:21
LastEditors: LetMeFly
LastEditTime: 2023-11-10 14:28:30
'''
# from typing import List
# from bisect import bisect_left

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        for i in range(len(spells)):
            toFind = success // spells[i]
            if toFind * spells[i] < success:
                toFind += 1
            spells[i] = len(potions) - bisect_left(potions, toFind)
        return spells

```

## 查找范围小优化+不进行类型转换小优化

上述有两个可以优化的地方：

1. 确定$toFind$的值，实质上就是$\lceil success / t\rceil$
2. `lower_bound(vector<int>::iterator, vector<int>::iterator, long long)`会在比较的过程中将每个int自动转为`long long`类型，有一丢丢耗时；可以在$toFind$明显超出毒药毒性数据范围时直接返回$0$。

以上。

+ 时间复杂度$O(n\log n)$，其中$n=len(potions)$
+ 空间复杂度$O(log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-10-08 21:37:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-08 22:17:48
 */
/*
a * b >= success
a >= success/b
s b s/b a
6 2  3  3
6 3  2  2
6 4 1.5 2
6 5 1.x 2
a >= ⌈s/b⌉
a >= ⌊(s+b-1)/b⌋
*/
typedef long long ll;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for (int& s : spells) {
            ll toFind = (success + s - 1) / s;
            if (toFind > 100000) {
                s = 0;
            } else {
                s = potions.end() - lower_bound(potions.begin(), potions.end(), toFind);
            }
        }
        return spells;
    }
};
```

## 查找范围小优化

上述有一个可以优化的地方：

> $\geq\lceil \frac{success}{t}\rceil$ ⇔ $\geq\lfloor\frac{success+t-1}{t}\rfloor$ ⇔ $\geq\lfloor\frac{success-1}{t}\rfloor+1$
>
> 由于所涉及的数据都是整数，所以有$\geq\lfloor\frac{success-1}{t}\rfloor+1$ ⇔ $\gt \lfloor\frac{success-1}{t}\rfloor$

以上。

+ 时间复杂度$O(n\log n)$，其中$n=len(potions)$
+ 空间复杂度$O(log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-10-08 21:37:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-08 22:21:04
 */
/*
a * b >= success
a >= success/b
s b s/b a
6 2  3  3
6 3  2  2
6 4 1.5 2
6 5 1.x 2
a >= ⌈s/b⌉
a >= ⌊(s+b-1)/b⌋
a >= ⌊(s-1)/b⌋+1
a > ⌊(s-1)/b⌋
*/
typedef long long ll;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        success -= 1;  // 提前-1后面不用每次都-1了
        for (int& s : spells) {
            ll target = success / s;
            if (target > 100000) {
                s = 0;
            } else {
                s = potions.end() - upper_bound(potions.begin(), potions.end(), target);
            }
        }
        return spells;
    }
};
```

## (lower/upper)_bound库函数含义、大于小于个数查找表

### (lower/upper)_bound库函数含义

| 函数 | 返回的位置含义 |
|------|----------------|
| `lower_bound(a.begin(), a.end(), x)` | 第一个 **≥ x** 的元素的位置 |
| `upper_bound(a.begin(), a.end(), x)` | 第一个 **> x** 的元素的位置 |

### 查找(大于等于/大于/小于/小于等于)x的元素的个数

| 条件 | 表达式 | 含义 |
|------|----------|------|
| **≥ x** | `a.end() - lower_bound(a.begin(), a.end(), x)` | 从 ≥x 开始到末尾 |
| **> x** | `a.end() - upper_bound(a.begin(), a.end(), x)` | 从 >x 开始到末尾 |
| **≤ x** | `upper_bound(a.begin(), a.end(), x) - a.begin()` | 从开头到 ≤x 结束 |
| **< x** | `lower_bound(a.begin(), a.end(), x) - a.begin()` | 从开头到 <x 结束 |

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/134332611)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/10/LeetCode%202300.%E5%92%92%E8%AF%AD%E5%92%8C%E8%8D%AF%E6%B0%B4%E7%9A%84%E6%88%90%E5%8A%9F%E5%AF%B9%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)

<!-- https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/solutions/3800734/letmefly-2300zhou-yu-he-yao-shui-de-chen-pyqp/ -->