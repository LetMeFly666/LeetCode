---
title: 869.重新排序得到 2 的幂：哈希表+排序（一次初始化）
date: 2025-08-10 21:18:50
tags: [题解, LeetCode, 中等, 哈希表, set, 数学, 计数, 枚举, 排序, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】869.重新排序得到 2 的幂：哈希表+排序（一次初始化）

力扣题目链接：[https://leetcode.cn/problems/reordered-power-of-2/](https://leetcode.cn/problems/reordered-power-of-2/)

<p>给定正整数&nbsp;<code>n</code>&nbsp;，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。</p>

<p>如果我们可以通过上述方式得到&nbsp;2 的幂，返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：排序+哈希表

$10^9$范围内，一共有$2^0$到$2^{29}$这30个2的幂。

我们可以提前把每个2的幂对应的字符串按自身字符从小到大的顺序拍个序并加入哈希表中，这样对于一个数字$n$，我们只需要将其转为字符串并自排序后看是否在哈希表中就行了。

### 时空复杂度分析

不计初始化时空复杂度的话，对于一次查询$n$：

+ 时间复杂度$O(l\log l)$，其中$l=\log_{10}n$
+ 空间复杂度$O(l)$

初始化不论多少测试用例（目前137个）一共会执行一次：

+ 时间复杂度$O(Cl\log l)$，其中$C=30$，$l$是一个2的幂十进制下的长度
+ 空间复杂度$O(Cl)$

### AC代码

以下代码中哈希表加入了$2^{30}$，其实有点多余

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-10 17:20:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-10 17:27:46
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    // unordered_set<unordered_map<int, int>> times;  // 无默认哈希函数
    static unordered_set<string> can;

    void initCan() {
        if (!can.empty()) {
            return;
        }
        for (int i = 0; i <= 30; i++) {  // 其实到i<30即可
            string s = to_string(1 << i);
            sort(s.begin(), s.end());
            can.insert(s);
        }
    }
public:
    bool reorderedPowerOf2(int n) {
        initCan();
        string s = to_string(n);
        sort(s.begin(), s.end());
        return can.count(s);
    }
};

unordered_set<string> Solution::can;
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-10 17:20:07
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-10 20:12:28
'''
can = set(''.join(sorted(str(1 << i))) for i in range(31))

class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        return ''.join(sorted(str(n))) in can
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-08-10 17:20:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-10 20:51:10
 */
import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;

class Solution {
    private static final Set<String> can = new HashSet<>();

    static {
        for (int i = 0; i < 31; i++) {
            can.add(itoa(1 << i));
        }
    }

    private static String itoa(int n) {
        char[] s = String.valueOf(n).toCharArray();
        Arrays.sort(s);
        return new String(s);
    }

    public boolean reorderedPowerOf2(int n) {
        return can.contains(itoa(n));
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-08-10 17:20:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-10 20:46:54
 */
package main

import (
	"slices"
	"strconv"
)

var can0869 = map[string]bool{}

func init0869() {
    if len(can0869) > 0 {
        return
    }
    for i := 0; i < 31; i++ {
        can0869[itoa869(1 << i)] = true
    }
}

func itoa869(i int) string {
    s := []byte(strconv.Itoa(i))
    slices.Sort(s)
    return string(s)
}

func reorderedPowerOf2(n int) bool {
    init0869()
    return can0869[itoa869(n)]
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-08-10 17:20:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-10 21:17:39
 */
use std::collections::HashSet;

lazy_static::lazy_static! {
    static ref CAN: HashSet<String> = {
        let mut can = HashSet::new();
        for i in 0..31 {
            can.insert(Solution::itoa(1 << i));
        }
        can
    };
}

impl Solution {
    fn itoa(i: i32) -> String {
        let mut v: Vec<char> = i.to_string().chars().collect();
        v.sort();
        v.into_iter().collect()
    }
    
    pub fn reordered_power_of2(n: i32) -> bool {
        CAN.contains(&Self::itoa(n))
    }
}
```

# End

不知道是不是一种错觉，感觉域名注册商在cloudflare的话CDN会快很多。

似乎真多是很多。和域名注册商在阿里云相比。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/150158685)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/10/LeetCode%200869.%E9%87%8D%E6%96%B0%E6%8E%92%E5%BA%8F%E5%BE%97%E5%88%B02%E7%9A%84%E5%B9%82/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
