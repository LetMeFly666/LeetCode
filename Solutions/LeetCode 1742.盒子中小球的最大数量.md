---
title: 1742.盒子中小球的最大数量：哈希表（附Python一行版）
date: 2022-11-23 09:36:43
tags: [题解, LeetCode, 简单, 哈希表, 哈希, 数学, 计数]
---

# 【LetMeFly】1742.盒子中小球的最大数量：哈希表（附Python一行版）

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/](https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/)

<p>你在一家生产小球的玩具厂工作，有 <code>n</code> 个小球，编号从 <code>lowLimit</code> 开始，到 <code>highLimit</code> 结束（包括 <code>lowLimit</code> 和 <code>highLimit</code> ，即 <code>n == highLimit - lowLimit + 1</code>）。另有无限数量的盒子，编号从 <code>1</code> 到 <code>infinity</code> 。</p>

<p>你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。例如，编号 <code>321</code> 的小球应当放入编号 <code>3 + 2 + 1 = 6</code> 的盒子，而编号 <code>10</code> 的小球应当放入编号 <code>1 + 0 = 1</code> 的盒子。</p>

<p>给你两个整数 <code>lowLimit</code> 和 <code>highLimit</code> ，返回放有最多小球的盒子中的小球数量<em>。</em>如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>lowLimit = 1, highLimit = 10
<strong>输出：</strong>2
<strong>解释：</strong>
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：2 1 1 1 1 1 1 1 1 0  0  ...
编号 1 的盒子放有最多小球，小球数量为 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>lowLimit = 5, highLimit = 15
<strong>输出：</strong>2
<strong>解释：</strong>
盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
小球数量：1 1 1 1 2 2 1 1 1 0  0  ...
编号 5 和 6 的盒子放有最多小球，每个盒子中的小球数量都是 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>lowLimit = 19, highLimit = 28
<strong>输出：</strong>2
<strong>解释：</strong>
盒子编号：1 2 3 4 5 6 7 8 9 10 11 12 ...
小球数量：0 1 1 1 1 1 1 1 1 2  0  0  ...
编号 10 的盒子放有最多小球，小球数量为 2 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= lowLimit <= highLimit <= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：哈希表

### 题目分析

假设$s$是数字$n$十进制下每一位的和，那么题目意思就是：将编号为$n$的小球放到编号为$s$的盒子里。问将$[lowLimit, hightLimit]$范围内的所有小球都放到盒子中后，小球最多的盒子中有多少小球。

### 解题思路

那么很简单，就按照题目要求进行模拟呗

我们使用哈希表来统计每个盒子中小球的数量（这里换成数组也可，因为$10^5$范围内的小球所放到的最大盒子编号为$9\times5=45$，只需要开辟长度为$46$的数组即可）

怎么计算出一个数字十进制下每一位的和呢？也很简单。在这个数字不为零时，不断取出这个数字十进制下的最后一位，并将这个数字除以$10$即可。

```cpp
int cnt = 0;
while (n) {
	cnt += n % 10;
	n /= 10;
}
// cnt即为n十进制下每一位的和
```

### 复杂度

+ 时间复杂度$O((highLimit - lowLimit)\times \log(highLimit))$
+ 空间复杂度$O(hightLimit\times \log(highLimit))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-11-23 09:29:13
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-11-23 09:32:11
 */
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> ma;
        for (int i = lowLimit; i <= highLimit; i++) {
            int n = i;
            int cnt = 0;
            while (n) {
                cnt += n % 10;
                n /= 10;
            }
            ma[cnt]++;
        }
        int ans = 0;
        for (auto&& [box, times] : ma) {
            ans = max(ans, times);
        }
        return ans;
    }
};
```

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 16:19:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 16:20:31
 */
class Solution {
private:
    inline int get(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int countBalls(int l, int h) {
        int cnt[46] = {0};
        for (; l <= h; l++) {
            cnt[get(l)]++;
        }
        return *max_element(cnt, cnt + 46);
    }
};
```

#### Python

极简Python版本

```python
'''
Author: LetMeFly
Date: 2022-11-23 09:38:55
LastEditors: LetMeFly
LastEditTime: 2022-11-23 09:40:21
'''
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        return max(Counter(sum(map(int, str(i))) for i in range(lowLimit, highLimit + 1)).values())
```

其中$Counter$函数来自$collections$

```python
from collections import Counter
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-13 16:25:12
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-13 16:25:13
'''
from collections import Counter

class Solution:
    def countBalls(self, l: int, r: int) -> int:
        return max(Counter(sum(ord(c) - 48 for c in str(i)) for i in range(l, r + 1)).values())
```

似乎还没有1坤年前写的好。。。

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 16:22:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 16:27:51
 */
class Solution {
    private int get(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    public int countBalls(int l, int r) {
        int[] cnt = new int[46];
        int ans = 0;
        for (; l <= r; l++) {
            int thisCnt = get(l);
            cnt[thisCnt]++;
            ans = Math.max(ans, cnt[thisCnt]);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 16:22:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 16:31:13
 */
package main

func get_MNB1B(n int) (ans int) {
    for n > 0 {
        ans += n % 10
        n /= 10
    }
    return
}

func min_MNB1B(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func countBalls(l int, h int) (ans int) {
    cnt := make([]int, 46)
    for ; l <= h; l++ {
        thisCnt := get_MNB1B(l)
        cnt[thisCnt]++
        ans = max(ans, cnt[thisCnt])
    }
    return
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/23/LeetCode%201742.%E7%9B%92%E5%AD%90%E4%B8%AD%E5%B0%8F%E7%90%83%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E9%87%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127994569](https://letmefly.blog.csdn.net/article/details/127994569)
