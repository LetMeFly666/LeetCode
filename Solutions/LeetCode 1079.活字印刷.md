---
title: 1079.活字印刷
date: 2023-05-19 19:53:14
tags: [题解, LeetCode, 中等, 字符串, 回溯, DFS, 深度优先搜索]
categories: [题解, LeetCode]
---

# 【LetMeFly】1079.活字印刷

力扣题目链接：[https://leetcode.cn/problems/letter-tile-possibilities/](https://leetcode.cn/problems/letter-tile-possibilities/)

<p>你有一套活字字模&nbsp;<code>tiles</code>，其中每个字模上都刻有一个字母&nbsp;<code>tiles[i]</code>。返回你可以印出的非空字母序列的数目。</p>

<p><strong>注意：</strong>本题中，每个活字字模只能使用一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>"AAB"
<strong>输出：</strong>8
<strong>解释：</strong>可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>"AAABBC"
<strong>输出：</strong>188
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>"V"
<strong>输出：</strong>1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tiles.length &lt;= 7</code></li>
	<li><code>tiles</code> 由大写英文字母组成</li>
</ul>


    
## 方法一：深度优先搜索DFS

首先使用哈希表ma统计每个字符**可用**多少次。

接着编写一个搜索函数dfs，代表当前状态的ma下有多少种组合方案。

在dfs函数中，初始组合方案ans=0。

遍历哈希表ma，如果某个字符的出现次数大于0，就尝试在当前位置使用该字符（ans++），并更新ma中该字符的可用次数，继续递归调用dfs函数，ans加上后续字符串的种类数。

+ 时间复杂度$O(n!)$，因为$n\times n!\approx (n+1)!$，其中$n$是字符串中不同字母的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<char, int> ma;
    
    int dfs() {
        int ans = 0;
        for (auto&& [c, times] : ma) {
            if (times > 0) {
                ans++;
                times--;
                // printf("times = %d, ma[%c] = %d\n", times, c, ma[c]);  //********
                ans += dfs();
                times++;
            }
        }
        return ans;
    }
public:
    int numTilePossibilities(string tiles) {
        for (char c : tiles) {
            ma[c]++;
        }
        return dfs();
    }
};
```

#### Python

```python
# from collections import Counter


class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        dic = Counter(tiles)
        def dfs() -> int:
            ans = 0
            for c, times in dic.items():
                if times > 0:
                    ans += 1
                    dic[c] -= 1
                    ans += dfs()
                    dic[c] += 1
            return ans

        return dfs()
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/05/19/LeetCode%201079.%E6%B4%BB%E5%AD%97%E5%8D%B0%E5%88%B7/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130773195](https://letmefly.blog.csdn.net/article/details/130773195)
