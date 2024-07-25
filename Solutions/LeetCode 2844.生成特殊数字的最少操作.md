---
title: 2844.生成特殊数字的最少操作
date: 2024-07-25 17:07:41
tags: [题解, LeetCode, 中等, 贪心, 数学, 字符串, 枚举]
---

# 【LetMeFly】2844.生成特殊数字的最少操作：模拟（分析）

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/](https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/)

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>num</code> ，表示一个非负整数。</p>

<p>在一次操作中，您可以选择 <code>num</code> 的任意一位数字并将其删除。请注意，如果你删除 <code>num</code> 中的所有数字，则 <code>num</code> 变为 <code>0</code>。</p>

<p>返回最少需要多少次操作可以使 <code>num</code> 变成特殊数字。</p>

<p>如果整数 <code>x</code> 能被 <code>25</code> 整除，则该整数 <code>x</code> 被认为是特殊数字。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = "2245047"
<strong>输出：</strong>2
<strong>解释：</strong>删除数字 num[5] 和 num[6] ，得到数字 "22450" ，可以被 25 整除。
可以证明要使数字变成特殊数字，最少需要删除 2 位数字。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = "2908305"
<strong>输出：</strong>3
<strong>解释：</strong>删除 num[3]、num[4] 和 num[6] ，得到数字 "2900" ，可以被 25 整除。
可以证明要使数字变成特殊数字，最少需要删除 3 位数字。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = "10"
<strong>输出：</strong>1
<strong>解释：</strong>删除 num[0] ，得到数字 "0" ，可以被 25 整除。
可以证明要使数字变成特殊数字，最少需要删除 1 位数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 100</code></li>
	<li><code>num</code> 仅由数字 <code>'0'</code> 到 <code>'9'</code> 组成</li>
	<li><code>num</code> 不含任何前导零</li>
</ul>


    
## 解题方法：模拟分析

一个数如果是25的倍数，那么它要么是$0$，要么以：$00$、$25$、$50$或$75$结尾。

如果要将num变成0，最少需要移除多少个元素呢？

> + 如果num中本来就包含数字0，则需要移除len(num) - 1个元素
> + 否则，需要将num中的数字全部移除，即需移除len(num)个元素

如果要将num变成以25结尾呢？

> 首先找到num中最后一个以5结尾的元素的位置（记为i）。
>
> 接着在`[0, i)`范围内找以2结尾的元素的位置。
>
> 若都找到，则返回`len(num) - i - 2`，否则返回`len(num)`

找以$00$结尾、以$50$或$75$结尾同理。

其中所有的方案中，所需移除元素最少的一个记为所求。

+ 时间复杂度$O(len(num))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int thisEnd(string& s, int n) {
        int i = s.size() - 1;
        char finding = n % 10 + '0';
        while (i >= 0 && s[i] != finding) {
            i--;
        }
        i--;
        finding = n / 10 % 10 + '0';
        while (i >= 0 && s[i] != finding) {
            i--;
        }
        return i == -1 ? s.size() : s.size() - i - 2;
    }
public:
    int minimumOperations(string& s) {
        int ans = s.find('0') == string::npos ? s.size() : s.size() - 1;
        ans = min(ans, min(
            thisEnd(s, 0), min(
                thisEnd(s, 25), min(
                    thisEnd(s, 50), thisEnd(s, 75)
                )
            )
        ));
        return ans;
    }
};
```

#### Java

```java
class Solution {
    private int thisEnd(String num, int n) {
        char finding = (char)(n % 10 + '0');
        int i = num.lastIndexOf(finding);
        finding = (char)(n / 10 % 10 + '0');
        i = num.lastIndexOf(finding, i - 1);
        return i == -1 ? num.length() : num.length() - i - 2;
    }

    public int minimumOperations(String num) {
        int ans = num.indexOf('0') == -1 ? num.length() : num.length() - 1;
        ans = Math.min(ans, Math.min(
            thisEnd(num, 0), Math.min(
                thisEnd(num, 25), Math.min(
                    thisEnd(num, 50), thisEnd(num, 75)
                )
            )
        ));
        return ans;
    }
}
```

#### Python

```python
class Solution:
    def thisEnd(self, num: str, n: int) -> int:
        finding = chr(ord('0') + n % 10)
        i = num.rfind(finding)
        if i == -1:
            return len(num)
        finding = chr(ord('0') + n // 10 % 10)
        i = num.rfind(finding, 0, i)
        return len(num) - i - 2 if i != -1 else len(num)
    
    def minimumOperations(self, num: str) -> int:
        ans = len(num) if '0' not in num else len(num) - 1
        for end in [0, 25, 50, 75]:
            ans = min(ans, self.thisEnd(num, end))
        return ans

```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/25/LeetCode%202844.%E7%94%9F%E6%88%90%E7%89%B9%E6%AE%8A%E6%95%B0%E5%AD%97%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140695211](https://letmefly.blog.csdn.net/article/details/140695211)
