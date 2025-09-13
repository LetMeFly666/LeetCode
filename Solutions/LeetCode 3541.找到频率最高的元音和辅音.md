---
title: 3541.找到频率最高的元音和辅音：计数(位运算)
date: 2025-09-13 16:33:24
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 计数, 位运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】3541.找到频率最高的元音和辅音：计数(位运算)

力扣题目链接：[https://leetcode.cn/problems/find-most-frequent-vowel-and-consonant/](https://leetcode.cn/problems/find-most-frequent-vowel-and-consonant/)

<p>给你一个由小写英文字母（<code>'a'</code> 到 <code>'z'</code>）组成的字符串 <code>s</code>。你的任务是找出出现频率&nbsp;<strong>最高&nbsp;</strong>的元音（<code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code>、<code>'u'</code> 中的一个）和出现频率<strong>最高</strong>的辅音（除元音以外的所有字母），并返回这两个频率之和。</p>

<p><strong>注意</strong>：如果有多个元音或辅音具有相同的最高频率，可以任选其中一个。如果字符串中没有元音或没有辅音，则其频率视为 0。</p>
一个字母 <code>x</code> 的&nbsp;<strong>频率&nbsp;</strong>是它在字符串中出现的次数。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">s = "successes"</span></p>

<p><strong>输出:</strong> <span class="example-io">6</span></p>

<p><strong>解释:</strong></p>

<ul>
	<li>元音有：<code>'u'</code> 出现 1 次，<code>'e'</code> 出现 2 次。最大元音频率 = 2。</li>
	<li>辅音有：<code>'s'</code> 出现 4 次，<code>'c'</code> 出现 2 次。最大辅音频率 = 4。</li>
	<li>输出为 <code>2 + 4 = 6</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">s = "aeiaeia"</span></p>

<p><strong>输出:</strong> <span class="example-io">3</span></p>

<p><strong>解释:</strong></p>

<ul>
	<li>元音有：<code>'a'</code> 出现 3 次，<code>'e'</code> 出现 2 次，<code>'i'</code> 出现 2 次。最大元音频率 = 3。</li>
	<li><code>s</code> 中没有辅音。因此，最大辅音频率 = 0。</li>
	<li>输出为 <code>3 + 0 = 3</code>。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 只包含小写英文字母</li>
</ul>


    
## 解题方法：计数(位运算)

使用一个大小为26的数组记录每个字符出现了多少次（遍历一遍字符串即可得到）。

之后遍历这26种字符，统计元音字符和辅音字符分别出现了多少次。返回这两个最大值之和即可。

+ 时间复杂度$O(len(s)+C)$，其中$C=26$
+ 空间复杂度$O(C)$，那些所有写着$O(1)$的题解实际上大概也是$O(C)$

### 细节问答

1. 如何判断一个字符是否为元音音符？

第一种方法就是4个或

```cpp
c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
```

第二种方法是位运算：

```cpp
int mask = 1<<0 | 1<<4 | 1<<8 | 1<<14 | 1<<20;
int idx = mask >> i & 1;  // i代表是第几个字符，从0开始计（'a'对应的i=0）
```

这样一个字符是元音的话`idx`就会为`1`，否则为`0`。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-13 16:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-13 16:10:22
 */
class Solution {
private:
    inline bool isYuan(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxFreqSum(string s) {
        int times[26] = {0};
        for (char c : s) {
            times[c - 'a']++;
        }
        int y = 0, f = 0;
        for (int i = 0; i < 26; i++) {
            if (isYuan('a' + i)) {
                y = max(y, times[i]);
            } else {
                f = max(f, times[i]);
            }
        }
        return y + f;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-09-13 16:07:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-13 16:19:20
'''
class Solution:
    mask = 1<<0 | 1<<4 | 1<<8 | 1<<14 | 1<<20
    def maxFreqSum(self, s: str) -> int:
        times = [0] * 26
        for c in s:
            times[ord(c) - ord('a')] += 1
        c = [0, 0]
        for i in range(26):
            idx = self.mask >> i & 1
            c[idx] = max(c[idx], times[i])
        return c[0] + c[1]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-09-13 16:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-13 16:23:21
 */
class Solution {
    private final static int mask = 1<<0 | 1<<4 | 1<<8 | 1<<14 | 1<<20;

    public int maxFreqSum(String s) {
        int[] times = new int[26];
        for (int i = 0; i < s.length(); i++) {
            times[s.charAt(i) - 'a']++;
        }
        int[] cnt = new int[2];
        for (int i = 0; i < 26; i++) {
            int idx = mask >> i & 1;
            cnt[idx] = Math.max(cnt[idx], times[i]);
        }
        return cnt[0] + cnt[1];
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-09-13 16:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-13 16:22:43
 */
package main

const mask int = 1<<0 | 1<<4 | 1<<8 | 1<<14 | 1<<20

func maxFreqSum(s string) int {
    times := make([]int, 26)
    for _, c := range s {
        times[byte(c) - 'a']++
    }
    cnt := []int{0, 0}
    for i, v := range times {
        idx := mask >> i & 1
        cnt[idx] = max(cnt[idx], v)
    }
    return cnt[0] + cnt[1]
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-09-13 16:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-13 16:32:24
 */
impl Solution {
    const MASK: usize = 1<<0 | 1<<4 | 1<<8 | 1<<14 | 1<<20;

    pub fn max_freq_sum(s: String) -> i32 {
        let mut times: Vec<i32> = vec![0; 26];
        for c in s.bytes() {
            times[(c - b'a') as usize] += 1;
        }
        let mut cnt: Vec<i32> = vec![0; 2];
        for i in 0..26 {
            let idx: usize = Self::MASK >> i & 1;
            cnt[idx] = cnt[idx].max(times[i]);
        }
        cnt[0] + cnt[1]
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151653999)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/13/LeetCode%203541.%E6%89%BE%E5%88%B0%E9%A2%91%E7%8E%87%E6%9C%80%E9%AB%98%E7%9A%84%E5%85%83%E9%9F%B3%E5%92%8C%E8%BE%85%E9%9F%B3/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
