---
title: 2982.找出出现至少三次的最长特殊子字符串 II
date: 2024-05-30 17:39:59
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 二分查找, 计数, 滑动窗口]
---

# 【LetMeFly】2982.找出出现至少三次的最长特殊子字符串 II：计数O(n)

力扣题目链接：[https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/](https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/)

<p>给你一个仅由小写英文字母组成的字符串 <code>s</code> 。</p>

<p>如果一个字符串仅由单一字符组成，那么它被称为 <strong>特殊 </strong>字符串。例如，字符串 <code>"abc"</code> 不是特殊字符串，而字符串 <code>"ddd"</code>、<code>"zz"</code> 和 <code>"f"</code> 是特殊字符串。</p>

<p>返回在 <code>s</code> 中出现 <strong>至少三次 </strong>的<strong> 最长特殊子字符串 </strong>的长度，如果不存在出现至少三次的特殊子字符串，则返回 <code>-1</code> 。</p>

<p><strong>子字符串 </strong>是字符串中的一个连续<strong> 非空 </strong>字符序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaaa"
<strong>输出：</strong>2
<strong>解释：</strong>出现三次的最长特殊子字符串是 "aa" ：子字符串 "<em><strong>aa</strong></em>aa"、"a<em><strong>aa</strong></em>a" 和 "aa<em><strong>aa</strong></em>"。
可以证明最大长度是 2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdef"
<strong>输出：</strong>-1
<strong>解释：</strong>不存在出现至少三次的特殊子字符串。因此返回 -1 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abcaba"
<strong>输出：</strong>1
<strong>解释：</strong>出现三次的最长特殊子字符串是 "a" ：子字符串 "<em><strong>a</strong></em>bcaba"、"abc<em><strong>a</strong></em>ba" 和 "abcab<em><strong>a</strong></em>"。
可以证明最大长度是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>


    
## 解题方法：计数

### 解题思路

“特殊子字符串”只能包含一种字符，因此我们可以将26种英文字符分开考虑。下面以字符```a```为例：

假设字符串```a```分别**连续**出现了```t1```次、```t2```次、```...```次、```tn```次，那么答案应该是多少呢？

其实我们只需要关注出现次数**最多**的3次（假设为```t1```、```t2```、```t3```）：

方法一，3个最长字符串都在```t1```中：

> 假设$t1=5$，则“aaaaa”中可以获得3个长度为3的字符串：“**aaa**aa”、“a**aaa**a”、“aa**aaa**”。
>
> 长度为$n$的连续字符串中可以提取3个长为$n-2$的“特殊子字符串”。

方法二，2个最长字符串在```t1```中，1个最长字符串在```t2```中：

> 假设$t1=5$而$t2=4$，则“aaaaa”中可以获得2个长度为4的字符串：“**aaaa**a”、“a**aaaa**”、“aaaa”中可以获得1个长度为4的字符串：“**aaaa**”。
>
> 长度为$n_1$和$n_2$（$n_1\geq n_2$）的连续字符串中可以提取3个长为$\min(n_1-1, n_2)$的“特殊子字符串”。

方法三，1个最长字符串在```t1```中，1个最长字符串在```t2```中，1个最长字符串在```t3```中：

> 假设$t1=5$而$t2=5$且$t3=5$，则其中分别可以提取一个长度为$5$的字符串。
>
> 长度为$n_1$、$n_2$和$n_3$（$n_1\geq n_2\geq n_3$）的连续字符串中可以提取3个长为$\min(n_1, n_2, n_3)$的“特殊子字符串”。

### 具体方法

开辟26个“三元组”，用来记录26个字母“连续出现次数”的前3名。遍历一次字符串即可得到该数组。

针对每个“三元组”，[解题思路](#解题思路)的三种方法中，最大的那个即为该字母的“最长特殊子字符串”。

26个字母中最长的即为答案。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(C)$，其中一共26种字符（$C=26$）

### AC代码

#### C++

```cpp
class Solution {
private:
    inline void add1times(int times[], int n) {
        if (n > times[2]) {
            times[2] = n;
            if (times[2] > times[1]) {
                swap(times[2], times[1]);
                if (times[1] > times[0]) {
                    swap(times[1], times[0]);
                }
            }
        }        
    }

    inline int getTimes(int times[]) {
        return max(
            min(times[0], min(times[1], times[2])),
            max(
                min(times[0] - 1, times[1]),
                times[0] - 2
            )
        );
    }
public:
    int maximumLength(string s) {
        int times[26][3] = {0};
        int from = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (i == s.size() || s[i] != s[i - 1]) {
                add1times(times[s[i - 1] - 'a'], i - from);
                from = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = max(ans, getTimes(times[i]));
        }
        return ans ? ans : -1;
    }
};
```

时间击败95.24%，空间击败96.03%。

#### Go

```go
// package main

func add(times []int, n int) {
    if n > times[2] {
        times[2] = n
        if times[2] > times[1] {
            times[2], times[1] = times[1], times[2]
            if times[1] > times[0] {
                times[1], times[0] = times[0], times[1]
            }
        }
    }
}

func max2(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func max3(a int, b int, c int) int {
    return max2(a, max2(b, c))
}

func min2(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func min3(a int, b int, c int) int {
    return min2(a, min2(b, c))
}

func getTimes(times []int) int {
    return max3 (
        min3(times[0], times[1], times[2]),
        min2(times[0] - 1, times[1]),
        times[0] - 2,  // 此逗号不可省略
    )
}

func maximumLength(s string) int {
    times := make([][3]int, 26)
    from := 0
    for i := 1; i <= len(s); i++ {
        if i == len(s) || s[i] != s[i - 1] {
            add(times[s[i - 1] - 'a'][:], i - from)
            from = i
        }
    }
    ans := 0
    for i := 0; i < 26; i++ {
        ans = max2(ans, getTimes(times[i][:]))
    }
    if ans != 0 {
        return ans
    }
    return -1
}
```

时间击败100%，空间击败100%。

#### Java

```java
class Solution {
    private void add(int[] times, int n) {
        if (n > times[2]) {
            times[2] = n;
            if (times[2] > times[1]) {
                times[2] = times[2] ^ times[1] ^ (times[1] = times[2]);
                if (times[1] > times[0]) {
                    times[1] = times[1] ^ times[0] ^ (times[0] = times[1]);
                }
            }
        }
    }

    private int getTimes(int[] times) {
        return Math.max(
            Math.min(times[0], Math.min(times[1], times[2])),
            Math.max(
                Math.min(times[0] - 1, times[1]),
                times[0] - 2
            )
        );
    }

    public int maximumLength(String s) {
        int[][] times = new int[26][3];
        int from = 0;
        for (int i = 1; i <= s.length(); i++) {
            if (i == s.length() || s.charAt(i) != s.charAt(i - 1)) {
                add(times[s.charAt(i - 1) - 'a'], i - from);
                from = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = Math.max(ans, getTimes(times[i]));
        }
        return ans != 0 ? ans : -1;
    }
}
```

时间击败88.89%，空间击败44.44%。

#### Python

```python
# from typing import List

class Solution:
    def add(self, times, n) -> None:
        if n > times[2]:
            times[2] = n
            if times[2] > times[1]:
                times[1], times[2] = times[2], times[1]
                if times[1] > times[0]:
                    times[0], times[1] = times[1], times[0]
    
    def getTimes(self, times) -> int:
        return max(
            min(times),
            min(times[0] - 1, times[1]),
            times[0] - 2
        )

    def maximumLength(self, s: str) -> int:
        times = [[0, 0, 0] for _ in range(26)]
        from_ = 0
        for i in range(1, len(s) + 1):
            if i == len(s) or s[i] != s[i - 1]:
                self.add(times[ord(s[i - 1]) - ord('a')], i - from_)
                from_ = i
        ans = 0
        for i in range(26):
            ans = max(ans, self.getTimes(times[i]))
        return ans if ans else -1
```

时间击败75.34%，空间击败100%。

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/30/LeetCode%202982.%E6%89%BE%E5%87%BA%E5%87%BA%E7%8E%B0%E8%87%B3%E5%B0%91%E4%B8%89%E6%AC%A1%E7%9A%84%E6%9C%80%E9%95%BF%E7%89%B9%E6%AE%8A%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139334864](https://letmefly.blog.csdn.net/article/details/139334864)
