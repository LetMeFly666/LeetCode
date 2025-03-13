---
title: 1073.负二进制数相加：简单算法 + 原理解析
date: 2023-05-18 09:50:53
tags: [题解, LeetCode, 中等, 数组, 数学, 进制转换, 高精度加法]
categories: [题解, LeetCode]
---

# 【LetMeFly】1073.负二进制数相加：简单算法 + 原理解析

力扣题目链接：[https://leetcode.cn/problems/adding-two-negabinary-numbers/](https://leetcode.cn/problems/adding-two-negabinary-numbers/)

<p>给出基数为 <strong>-2</strong>&nbsp;的两个数&nbsp;<code>arr1</code> 和&nbsp;<code>arr2</code>，返回两数相加的结果。</p>

<p>数字以&nbsp;<em>数组形式</em><strong>&nbsp;</strong>给出：数组由若干 0 和 1 组成，按最高有效位到最低有效位的顺序排列。例如，<code>arr&nbsp;= [1,1,0,1]</code>&nbsp;表示数字&nbsp;<code>(-2)^3&nbsp;+ (-2)^2 + (-2)^0 = -3</code>。<em>数组形式</em>&nbsp;中的数字 <code>arr</code> 也同样不含前导零：即&nbsp;<code>arr == [0]</code>&nbsp;或&nbsp;<code>arr[0] == 1</code>。</p>

<p>返回相同表示形式的 <code>arr1</code> 和 <code>arr2</code> 相加的结果。两数的表示形式为：不含前导零、由若干 0 和 1 组成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,1,1,1,1], arr2 = [1,0,1]
<strong>输出：</strong>[1,0,0,0,0]
<strong>解释：</strong>arr1 表示 11，arr2 表示 5，输出表示 16 。
</pre>

<p><meta charset="UTF-8" /></p>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [0], arr2 = [0]
<strong>输出：</strong>[0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [0], arr2 = [1]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= arr1.length,&nbsp;arr2.length &lt;= 1000</code></li>
	<li><code>arr1[i]</code>&nbsp;和&nbsp;<code>arr2[i]</code>&nbsp;都是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
	<li><code>arr1</code>&nbsp;和&nbsp;<code>arr2</code>&nbsp;都没有前导0</li>
</ul>


    
## 方法一：模拟

使用一个变量$c$来存放加法的进位。我们从最低位开始遍历两个数组，记两个数组的当前元素分别为$a$和$b$。令$x = a + b + c$。

+ 若$x\geq 2$，则$x -= 2, c = -1$，即逢$2$进$-1$（后面会解释）
+ 若$x = -1$，则$x = 1, c = 1$（后面会解释）
+ 否则，$c=0$（不产生进位）

将$x$的最终值加入到答案数组中，继续处理下一位。

最终将答案数组翻转并去除前导零即可。

**原因解释：**

首先假设上述方法正确，因两个$0$或$1$相加的结果在$0$到$2$之间，进位$c$的范围在$-1$到$1$之间，所以$x=a+b+c$的范围在$-1$到$3$之间。

+ 若$x=2$或$x=3$，因为负2进制每一位的范围是$0$到$1$，所以$x$需要进位。记进位后的数为$x_{final}$，则有$x=2+x_{final}$。
   > $$\begin{align*}
  x\times(-2)^{i}& =(2+x_{final})\times(-2)^{i}\\
  &=2\times(-2)^i+x_{final}\times(-2)^i \\
  &=(-1)\times(-2)\times(-2)^i+x_{final}\times(-2)^i \\
  &=(-1)\times(-2)^{i+1}+x_{final}\times(-2)^i
\end{align*}$$
   > 因此，进位为$-1$，本位为$x_{final}=x - 2$（在$0$到$1$的范围内）
+ 若$x=-1$，同理，$x\times(-2)^i=(-1)\times(-2)^i=((-2)+(1))\times(-2)^i=(-2)^{i+1}+(-2)^i$，所以进位为$1$，本位为$1$
+ 若$x=0$或$x=1$，则不必考虑进位（$c=0$）

完毕。

+ 时间复杂度$\mathcal O(len(arr1) + len(arr2))$
+ 空间复杂度$\mathcal O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        for (int i = arr1.size() - 1, j = arr2.size() - 1, c = 0; i >= 0 || j >= 0 || c; i--, j--) {
            int a = i >= 0 ? arr1[i] : 0;
            int b = j >= 0 ? arr2[j] : 0;
            int x = a + b + c;
            if (x >= 2) {
                x -= 2;
                c = -1;
            }
            else if (x == -1) {
                x = 1;
                c = 1;
            }
            else {
                c = 0;
            }
            ans.push_back(x);
        }
        while (ans.size() > 1 && !ans.back()) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        i, j, c = len(arr1) - 1, len(arr2) - 1, 0
        ans = []
        while i >= 0 or j >= 0 or c:
            a = arr1[i] if i >= 0 else 0
            b = arr2[j] if j >= 0 else 0
            x = a + b + c
            if x >= 2:
                x -= 2
                c = -1
            elif x == -1:
                x = 1
                c = 1
            else:
                c = 0
            ans.append(x)
            i, j = i - 1, j - 1
        while len(ans) > 1 and not ans[-1]:
            ans.pop()
        ans.reverse()
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/05/18/LeetCode%201073.%E8%B4%9F%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E7%9B%B8%E5%8A%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130741318](https://letmefly.blog.csdn.net/article/details/130741318)
