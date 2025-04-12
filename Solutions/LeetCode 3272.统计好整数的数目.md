---
title: 3272.统计好整数的数目：枚举+排列组合+哈希表
date: 2025-04-12 12:31:12
tags: [题解, LeetCode, 困难, 哈希表, 数学, 组合数学, 排列组合, 枚举, 字符串, 字符串解析, 回文串]
categories: [题解, LeetCode]
---

# 【LetMeFly】3272.统计好整数的数目：枚举+排列组合+哈希表

力扣题目链接：[https://leetcode.cn/problems/find-the-count-of-good-integers/](https://leetcode.cn/problems/find-the-count-of-good-integers/)

<p>给你两个 <strong>正</strong>&nbsp;整数&nbsp;<code>n</code> 和&nbsp;<code>k</code>&nbsp;。</p>

<p>如果一个整数&nbsp;<code>x</code>&nbsp;满足以下条件，那么它被称为 <strong>k</strong><strong>&nbsp;回文</strong>&nbsp;整数&nbsp;。</p>

<ul>
	<li><code>x</code>&nbsp;是一个&nbsp;<span data-keyword="palindrome-integer">回文整数 。</span></li>
	<li><code>x</code>&nbsp;能被 <code>k</code>&nbsp;整除。</li>
</ul>

<p>如果一个整数的数位重新排列后能得到一个 <strong>k 回文整数</strong>&nbsp;，那么我们称这个整数为&nbsp;<strong>好 </strong>整数。比方说，<code>k = 2</code>&nbsp;，那么&nbsp;2020 可以重新排列得到 2002 ，2002 是一个 k 回文串，所以 2020 是一个好整数。而 1010 无法重新排列数位得到一个 k 回文整数。</p>

<p>请你返回 <code>n</code>&nbsp;个数位的整数中，有多少个 <strong>好</strong>&nbsp;整数。</p>

<p><b>注意</b>&nbsp;，任何整数在重新排列数位之前或者之后 <strong>都不能</strong> 有前导 0 。比方说 1010 不能重排列得到&nbsp;101 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 3, k = 5</span></p>

<p><span class="example-io"><b>输出：</b>27</span></p>

<p><b>解释：</b></p>

<p>部分好整数如下：</p>

<ul>
	<li>551 ，因为它可以重排列得到 515 。</li>
	<li>525 ，因为它已经是一个 k 回文整数。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 1, k = 4</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>两个好整数分别是 4 和 8 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 5, k = 6</span></p>

<p><span class="example-io"><b>输出：</b>2468</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= k &lt;= 9</code></li>
</ul>


    
## 解题方法：枚举+排列组合+哈希表

我们可以枚举所有长度为$n$的数字回文字符串。对于一个回文串，如果其对应整数能够被$k$整除，则这个字符串的所有排列都能被$k$整除。

问题就转化为了以下三个：

1. 如何枚举所有长度为$n$的数字回文串？

    > 我们可以枚举字符串的前半部分，然后反转得到后半部分并拼接，就得到了回文字符串。
    >
    > 具体的，我们可以从$[10^{\lfloor\frac{n-1}2\rfloor}, 10^{\lfloor\frac{n-1}2\rfloor+1})$枚举前半字符串，若$n$为奇数则包含中间位置元素。

2. 一个“k回文整数字符串”有多少个排列？多少个字符串重新排列后能得到这个字符串？

    > 我们分别统计字符串中每个数字出现了多少次，假设字符串长度为$n$。
    >
    > 首先计算第一位有多少种可能，第一位不能为$0$，因此方案数为$n-times[0]$；
    >
    > 接着计算其他位，其他的$n-1$个数字可以随便排列，其他位的方案数为$(n-1)!$。
    >
    > 由于其中可能存在重复元素，例如$121$中有两个$1$，这两个$1$谁在前谁在后无法区分，只能有一种方案，所以要除以$2!$。
    >
    > 总的方案数为：$\frac{(n-times[0])\times (n-1)!}{\Pi_{i=0}^{9}times[i]}$。

3. 如何保证每个排列不会被重复统计？

    > 假设我已经统计过$1221$的所有全排列了，那么我遇到$2112$时就不能再统计$2112$的所有全排列了，因为$1221$和$2112$的全排列时相同的。
    >
    > 如何做到？其实我们只需要使用一个哈希表，记录字符串$s$排序后的字符串是否出现过就好了。

### 时空复杂度分析

+ 时间复杂度$O(10^{m}\times n\log n)$，其中$m=\lfloor\frac{n-1}2\rfloor$
+ 空间复杂度$O(10^m\times n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 07:51:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 09:25:01
 * @Description: AC,21.21%,93.94%
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
1 -> 1-9
2 -> 1-9
3 -> 10->99
4 -> 10->99
5 -> 100->999
6 -> 100->999

n -> [10^((n-1)/2-1), 10^((n-1)/2)-1)
*/
typedef long long ll;

class Solution {
private:
    int k;
    unordered_set<string> visited;
    vector<int> factor;
    int times[10];

    void initFactor(int n) {
        factor.resize(n + 1);
        factor[0] = 1;
        for (int i = 1; i <= n; i++) {
            factor[i] = factor[i - 1] * i;
        }
    }

    bool ifVisited(string s) {
        sort(s.begin(), s.end());
        if (visited.count(s)) {
            return true;
        }
        visited.insert(s);
        return false;
    }
    
    bool isOk(string& s) {
        ll val = stoll(s);
        // printf("%s: %d\n", s.c_str(), val % k == 0);  // *****
        return val % k == 0;
    };

    ll calc(string& s) {
        memset(times, 0, sizeof(times));
        for (char c : s) {
            times[c - '0']++;
        }
        ll ans = (s.size() - times[0]) * factor[s.size() - 1];
        for (int i = 0; i < 10; i++) {
            ans /= factor[times[i]];
        }
        return ans;
    }
public:
    ll countGoodIntegers(int n, int k) {
        initFactor(n);
        this->k = k;
        ll ans = 0;
        for (int start = pow(10, (n - 1) / 2), end = start * 10; start < end; start++) {
            string prefix = to_string(start), suffix = prefix.substr(0, prefix.size() - n % 2);
            reverse(suffix.begin(), suffix.end());
            string thisNum = prefix + suffix;
            if (isOk(thisNum) && !ifVisited(thisNum)) {  // 注意ifVisited会将thisNum加入哈希表的话记得先判断isOk再判断ifVisited
                // printf("ans: %lld, calc(%s): %lld, ans = ans + calc(%s) = %lld\n", ans, thisNum.c_str(), calc(thisNum), thisNum.c_str(), ans + calc(thisNum));  // ****
                ans += calc(thisNum);
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-12 09:44:25
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-12 10:52:36
Description: 中间终中断了下
'''
from collections import Counter

class Solution:
    def isOk(self, s: str) -> bool:
        return int(s) % self.k == 0
    
    def ifVisited(self, s: str) -> bool:
        s = ''.join(sorted(s))
        if s in self.visited:
            return True
        self.visited.add(s)
        return False
    
    def calc(self, s: str) -> int:
        times = Counter(s)
        ans = (len(s) - times['0']) * self.factor[len(s) - 1]
        for _, val in times.items():
            ans //= self.factor[val]
        return ans

    def countGoodIntegers(self, n: int, k: int) -> int:
        self.k = k
        self.factor = [1] * (n + 1)
        for i in range(1, n + 1):
            self.factor[i] = self.factor[i - 1] * i
        self.visited = set()
        base = pow(10, (n - 1) // 2)
        ans = 0
        for i in range(base, base * 10):
            prefix = str(i)
            s = prefix + prefix[::-1][n % 2:]
            if self.isOk(s) and not self.ifVisited(s):
                ans += self.calc(s)
        return ans

```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 10:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 11:13:08
 */
import java.util.Set;
import java.util.HashSet;
// import java.lang.StringBuilder;  // 默认自动导入 无需手动导入
import java.util.Arrays;

class Solution {
    private int k;
    private int[] factor;
    private Set<String> visited = new HashSet<>();

    private boolean isOk(String s) {
        return Long.parseLong(s) % k == 0;
    }

    private boolean ifVisited(String s) {
        char[] array = s.toCharArray();
        Arrays.sort(array);
        String sorted = new String(array);
        return !visited.add(sorted);
    }

    private long calc(String s) {
        int[] times = new int[10];
        for (char c : s.toCharArray()) {
            times[c - '0']++;
        }
        long ans = (s.length() - times[0]) * factor[s.length() - 1];
        for (int i = 0; i < 10; i++) {
            ans /= factor[times[i]];
        }
        return ans;
    }

    public long countGoodIntegers(int n, int k) {
        this.k = k;
        factor = new int[n + 1];
        factor[0] = 1;
        for (int i = 1; i <= n; i++) {
            factor[i] = factor[i - 1] * i;
        }
        long ans = 0;
        for (int from = (int)Math.pow(10, (n - 1) / 2), to = from * 10; from < to; from++) {
            String prefix = String.valueOf(from);
            String suffix = new StringBuilder(prefix).reverse().substring(n % 2);
            String s = prefix + suffix;
            if (isOk(s) && !ifVisited(s)) {
                ans += calc(s);
            }
        }
        return ans;
    }
}

/*
API:

java 子字符串
反转字符串
整数转字符串
字符串拼接
字符串转整数
*/
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-12 11:14:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-12 11:40:36
 * @Description: AC,25.00%,75.00%,一遍过
 */
package main

import (
    "math"
    "strconv"
    "sort"
    "strings"
)

type solution3273 struct{
    n, k int
    factor []int
    visited map[string]bool
}

func init3273(n int, k int) *solution3273 {
    ans := &solution3273{
        n: n,
        k: k,
        factor: make([]int, n + 1),
        visited : map[string]bool{},
    }
    ans.factor[0] = 1
    for i := 1; i <= n; i++ {
        ans.factor[i] = ans.factor[i - 1] * i
    }
    return ans
}

func (t* solution3273) isOk(s string) bool {
    val, _ := strconv.Atoi(s)
    return val % t.k == 0
}

func (t* solution3273) ifVisited(s string) bool {
    array := strings.Split(s, "")
    sort.Strings(array)
    s = strings.Join(array, "")
    if t.visited[s] {
        return true
    }
    t.visited[s] = true
    return false
}

func (t* solution3273) calc(s string) (ans int64) {
    times := [10]int{}
    for i, _ := range s {
        times[s[i] - '0']++
    }
    ans = int64(t.n - times[0]) * int64(t.factor[t.n - 1])
    for _, v := range times {
        ans /= int64(t.factor[v])
    }
    return
}

func (t* solution3273) getFullS(prefix string) string {
    suffix := []byte(prefix)
    if t.n % 2 == 1 {
        suffix = suffix[:len(suffix) - 1]
    }
    for i := 0; i < len(suffix) / 2; i++ {
        suffix[i], suffix[len(suffix) - i - 1] = suffix[len(suffix) - i - 1], suffix[i]
    }
    return prefix + string(suffix)
}

func countGoodIntegers(n int, k int) (ans int64) {
    solution := init3273(n, k)
    from := int(math.Pow10((n - 1) / 2))
    to := from * 10
    for i := from; i < to; i++ {
        s := solution.getFullS(strconv.Itoa(i))
        if solution.isOk(s) && !solution.ifVisited(s) {
            ans += solution.calc(s)
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147163366)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/12/LeetCode%203272.%E7%BB%9F%E8%AE%A1%E5%A5%BD%E6%95%B4%E6%95%B0%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
