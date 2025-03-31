---
title: 2109.向字符串添加空格：双指针
date: 2025-03-31 15:22:36
tags: [题解, LeetCode, 中等, 数组, 双指针, 字符串, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2109.向字符串添加空格：双指针

力扣题目链接：[https://leetcode.cn/problems/adding-spaces-to-a-string/](https://leetcode.cn/problems/adding-spaces-to-a-string/)

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>s</code> ，以及一个下标从 <strong>0</strong> 开始的整数数组 <code>spaces</code> 。</p>

<p>数组 <code>spaces</code> 描述原字符串中需要添加空格的下标。每个空格都应该插入到给定索引处的字符值 <strong>之前</strong> 。</p>

<ul>
	<li>例如，<code>s = "EnjoyYourCoffee"</code> 且 <code>spaces = [5, 9]</code> ，那么我们需要在 <code>'Y'</code> 和 <code>'C'</code> 之前添加空格，这两个字符分别位于下标 <code>5</code> 和下标 <code>9</code> 。因此，最终得到 <code>"Enjoy <em><strong>Y</strong></em>our <em><strong>C</strong></em>offee"</code> 。</li>
</ul>

<p>请你添加空格，并返回修改后的字符串<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
<strong>输出：</strong>"Leetcode Helps Me Learn"
<strong>解释：</strong>
下标 8、13 和 15 对应 "Leetcode<em><strong>H</strong></em>elps<em><strong>M</strong></em>e<em><strong>L</strong></em>earn" 中加粗斜体字符。
接着在这些字符前添加空格。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "icodeinpython", spaces = [1,5,7,9]
<strong>输出：</strong>"i code in py thon"
<strong>解释：</strong>
下标 1、5、7 和 9 对应 "i<em><strong>c</strong></em>ode<em><strong>i</strong></em>n<em><strong>p</strong></em>y<em><strong>t</strong></em>hon" 中加粗斜体字符。
接着在这些字符前添加空格。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "spacing", spaces = [0,1,2,3,4,5,6]
<strong>输出：</strong>" s p a c i n g"
<strong>解释：</strong>
字符串的第一个字符前可以添加空格。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由大小写英文字母组成</li>
	<li><code>1 &lt;= spaces.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= spaces[i] &lt;= s.length - 1</code></li>
	<li><code>spaces</code> 中的所有值 <strong>严格递增</strong></li>
</ul>


## 方法一：直接插入

记录下插入了几个空格（每次插入一个空格原字符串长度会加一），遍历spaces数组的过程中，往字符串的$插入下标+已插入空格个数$的位置插入一个空格。

这样每次插入操作会导致插入位置后面的所有字符均向后移动一个位置，单次插入时间复杂度为$O(n)$。

+ 时间复杂度$O(len(s)\times len(spaces))$
+ 空间复杂度$O(1)$

但是C++能丝滑通过。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-30 16:51:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-30 16:53:16
 * @Description: 可能会TLE的做法，试试C++字符串的insert
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int cnt = 0;
        for (int t : spaces) {
            s.insert(s.begin() + (cnt++ + t), ' ');
        }
        return s;
    }
};
```

### C++字符串相关操作耗时测试

测试一下C++的`向字符串前面位置插入元素`、`改变字符串前面位置某个字符`、`向字符串末尾添加元素`的耗时

```cpp
// g++ Codes\2109-adding-spaces-to-a-string_TestForTimeConsume.cpp -o temp.exe; ./temp.exe
// ./temp.exe
int main() {
    string s(100000, '0');
    time_t start = clock();
    for (int i = 0; i < 100000; i++) {
        s.insert(s.begin() + rand() % 10, rand() % 20);
    }
    time_t end = clock();
    cout << end - start << endl;  // 基本上280-290ms

    start = end;
    for (int i = 0; i < 100000; i++) {
        s[rand() % 10] = rand() % 20;  // 基本上3ms
    }
    end = clock();
    cout << end - start << endl;

    start = end;
    for (int i = 0; i < 100000; i++) {
        s += rand() % 20;    // 基本上2ms
    }
    end = clock();
    cout << end - start << endl;
    return 0;
}
```

可以发现向字符串前面插入元素确实较耗时。

## 方法二：双指针

一个指针遍历被插空格的字符串，一个指针指向空格数组。

遍历字符串的过程中，如果空格数组指针指向的空格下标和字符串下标相同，则往答案中添加一个空格。不论是否添加了空格，遍历过程中都要将当前字符加入答案中。

+ 时间复杂度$O(len(s))$
+ 空间复杂度：可变字符串如C++：$O(1)$；不可变字符串如Python/Golang/Java：$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 14:31:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 14:32:48
 */
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (j < spaces.size() && spaces[j] == i) {
                ans += ' ';
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};
```

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 14:21:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 14:24:26
 */
class Solution {
private:
    inline bool isSpace(vector<int>& spaces, int i, int j) {
        if (j == spaces.size()) {
            return false;
        }
        return i == spaces[j];
    }
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (isSpace(spaces, i, j)) {
                ans += ' ';
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-31 14:33:18
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-31 14:34:50
'''
from typing import List

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = []
        j = 0
        for i, c in enumerate(s):
            if j < len(spaces) and spaces[j] == i:
                ans.append(' ')
                j += 1
            ans.append(c)
        return ''.join(ans)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 14:37:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 14:44:41
 */
import java.lang.StringBuffer;

class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuffer sb = new StringBuffer(s.length() + spaces.length);
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (j < spaces.length && spaces[j] == i) {
                sb.append(' ');
                j++;
            }
            sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-31 14:45:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-31 15:18:02
 */
package main

func addSpaces(s string, spaces []int) string {
    ans := make([]byte, 0, len(s) + len(spaces))
    j := 0
    for i, c := range s {
        if j < len(spaces) && spaces[j] == i {
            ans = append(ans, ' ')
            j++
        }
        ans = append(ans, byte(c))
    }
    return string(ans)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146863199)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/31/LeetCode%202109.%E5%90%91%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%B7%BB%E5%8A%A0%E7%A9%BA%E6%A0%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
