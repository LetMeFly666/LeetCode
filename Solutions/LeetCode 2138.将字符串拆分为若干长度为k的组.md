---
title: 2138.将字符串拆分为若干长度为 k 的组：模拟
date: 2025-06-23 13:28:19
tags: [题解, LeetCode, 简单, 字符串, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2138.将字符串拆分为若干长度为 k 的组：模拟

力扣题目链接：[https://leetcode.cn/problems/divide-a-string-into-groups-of-size-k/](https://leetcode.cn/problems/divide-a-string-into-groups-of-size-k/)

<p>字符串 <code>s</code> 可以按下述步骤划分为若干长度为 <code>k</code> 的组：</p>

<ul>
	<li>第一组由字符串中的前 <code>k</code> 个字符组成，第二组由接下来的 <code>k</code> 个字符串组成，依此类推。每个字符都能够成为 <strong>某一个</strong> 组的一部分。</li>
	<li>对于最后一组，如果字符串剩下的字符 <strong>不足</strong> <code>k</code> 个，需使用字符 <code>fill</code> 来补全这一组字符。</li>
</ul>

<p>注意，在去除最后一个组的填充字符 <code>fill</code>（如果存在的话）并按顺序连接所有的组后，所得到的字符串应该是 <code>s</code> 。</p>

<p>给你一个字符串 <code>s</code> ，以及每组的长度 <code>k</code> 和一个用于填充的字符 <code>fill</code> ，按上述步骤处理之后，返回一个字符串数组，该数组表示 <code>s</code> 分组后 <strong>每个组的组成情况</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abcdefghi", k = 3, fill = "x"
<strong>输出：</strong>["abc","def","ghi"]
<strong>解释：</strong>
前 3 个字符是 "abc" ，形成第一组。
接下来 3 个字符是 "def" ，形成第二组。
最后 3 个字符是 "ghi" ，形成第三组。
由于所有组都可以由字符串中的字符完全填充，所以不需要使用填充字符。
因此，形成 3 组，分别是 "abc"、"def" 和 "ghi" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcdefghij", k = 3, fill = "x"
<strong>输出：</strong>["abc","def","ghi","jxx"]
<strong>解释：</strong>
与前一个例子类似，形成前三组 "abc"、"def" 和 "ghi" 。
对于最后一组，字符串中仅剩下字符 'j' 可以用。为了补全这一组，使用填充字符 'x' 两次。
因此，形成 4 组，分别是 "abc"、"def"、"ghi" 和 "jxx" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li><code>fill</code> 是一个小写英文字母</li>
</ul>


    
## 解题方法：模拟

```cpp
for (int i = 0; i < len(s); i += k) {
    if (剩下字符串还有k个) {
        取子串
    } else {
        取剩下字符串+fill填充
    }
}
```

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-22 12:43:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-22 20:42:15
 */
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for (int i = 0; i < s.size(); i += k) {
            if (s.size() - i < k) {
                ans.push_back(s.substr(i, s.size() - i) + string(k - (s.size() - i), fill));
            } else {
                ans.push_back(s.substr(i, k));
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
Date: 2025-06-22 12:43:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-22 20:55:30
'''
from typing import List

# 'a' * -1 -> ''
# [1, 2][1:100] -> [2]
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        return [s[i:i+k] + fill * (k - (len(s) - i)) for i in range(0, len(s), k)]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-06-22 12:43:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-22 21:04:09
 */
class Solution {
    public String[] divideString(String s, int k, char fill) {
        String[] ans = new String[(s.length() + k - 1) / k];
        for (int i = 0; i < s.length(); i += k) {
            if (s.length() - i < k) {
                ans[i / k] = s.substring(i) + String.valueOf(fill).repeat(k - (s.length() - i));
            } else {
                ans[i / k] = s.substring(i, i + k);
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-06-22 12:43:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-22 20:59:28
 */
package main

import "strings"

func divideString(s string, k int, fill byte) []string {
    ans := make([]string, 0, (len(s) + k - 1) / k)
    for i := 0; i < len(s); i += k {
        if len(s) - i < k {
            ans = append(ans, s[i:] + strings.Repeat(string(fill), k - (len(s) - i)))
        } else {
            ans = append(ans, s[i:i+k])
        }
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148844890)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/06/22/LeetCode%202138.%E5%B0%86%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%8B%86%E5%88%86%E4%B8%BA%E8%8B%A5%E5%B9%B2%E9%95%BF%E5%BA%A6%E4%B8%BAk%E7%9A%84%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
