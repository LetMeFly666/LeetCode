---
title: 1366.通过投票对团队排名
date: 2024-12-30 02:20:37
tags: [题解, LeetCode, 中等, 数组, 哈希表, map, 字符串, 计数, 排序]
---

# 【LetMeFly】1366.通过投票对团队排名：自定义排序

力扣题目链接：[https://leetcode.cn/problems/rank-teams-by-votes/](https://leetcode.cn/problems/rank-teams-by-votes/)

<p>现在有一个特殊的排名系统，依据参赛团队在投票人心中的次序进行排名，每个投票者都需要按从高到低的顺序对参与排名的所有团队进行排位。</p>

<p>排名规则如下：</p>

<ul>
	<li>参赛团队的排名次序依照其所获「排位第一」的票的多少决定。如果存在多个团队并列的情况，将继续考虑其「排位第二」的票的数量。以此类推，直到不再存在并列的情况。</li>
	<li>如果在考虑完所有投票情况后仍然出现并列现象，则根据团队字母的字母顺序进行排名。</li>
</ul>

<p>给你一个字符串数组&nbsp;<code>votes</code> 代表全体投票者给出的排位情况，请你根据上述排名规则对所有参赛团队进行排名。</p>

<p>请你返回能表示按排名系统 <strong>排序后</strong> 的所有团队排名的字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>votes = ["ABC","ACB","ABC","ACB","ACB"]
<strong>输出：</strong>"ACB"
<strong>解释：</strong>
A 队获得五票「排位第一」，没有其他队获得「排位第一」，所以 A 队排名第一。
B 队获得两票「排位第二」，三票「排位第三」。
C 队获得三票「排位第二」，两票「排位第三」。
由于 C 队「排位第二」的票数较多，所以 C 队排第二，B 队排第三。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>votes = ["WXYZ","XYZW"]
<strong>输出：</strong>"XWYZ"
<strong>解释：</strong>
X 队在并列僵局打破后成为排名第一的团队。X 队和 W 队的「排位第一」票数一样，但是 X 队有一票「排位第二」，而 W 没有获得「排位第二」。 
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
<strong>输出：</strong>"ZMNAGUEDSJYLBOPHRQICWFXTVK"
<strong>解释：</strong>只有一个投票者，所以排名完全按照他的意愿。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= votes.length &lt;= 1000</code></li>
	<li><code>1 &lt;= votes[i].length &lt;= 26</code></li>
	<li><code>votes[i].length ==&nbsp;votes[j].length</code> for&nbsp;<code>0 &lt;= i, j &lt; votes.length</code></li>
	<li><code>votes[i][j]</code>&nbsp;是英文 <strong>大写</strong> 字母</li>
	<li><code>votes[i]</code>&nbsp;中的所有字母都是唯一的</li>
	<li><code>votes[0]</code>&nbsp;中出现的所有字母 <strong>同样也</strong> 出现在&nbsp;<code>votes[j]</code>&nbsp;中，其中&nbsp;<code>1 &lt;= j &lt; votes.length</code></li>
</ul>


    
## 解题方法：统计 + 自定义排序

创建哈希表counts，其中counts[i][j]代表团队`i + 'A'`排位第`j + 1`的次数。

然后排序时按照题意自定义排序规则即可。

+ 时间复杂度$O(nm+n^2\log n)$，其中有$n$个参与者，$m$个投票者
+ 空间复杂度$O(nC)$，其中$C=26$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-29 14:17:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-29 14:24:20
 */

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int voter = votes.size(), voted = votes[0].size();
        vector<vector<int>> counts(26, vector<int>(voted));
        for (string& vote : votes) {
            for (int i = 0; i < voted; i++) {
                counts[vote[i] - 'A'][i]++;
            }
        }
        string ans = votes[0];
        sort(ans.begin(), ans.end(), [&](const char& a, const char& b) {
            vector<int>& va = counts[a - 'A'], &vb = counts[b - 'A'];
            for (int i = 0; i < voted; i++) {
                if (va[i] != vb[i]) {
                    return va[i] > vb[i];
                }
            }
            return a < b;
        });
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-29 14:58:42
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-29 21:08:46
'''
"""
from typing import List

class Solution:    
    def rankTeams(self, votes: List[str]) -> str:
        n = len(votes[0])
        counts = [[0] * n for _ in range(26)]
        for vote in votes:
            for i in range(n):
                counts[ord(vote[i]) - ord('A')][i] -= 1
        return ''.join(sorted(votes[0], key=lambda a: (counts[ord(a) - ord('A')], a)))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-29 21:09:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-30 02:16:01
 */
// 好复杂
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String rankTeams(String[] votes) {
        int n = votes[0].length();
        int[][] counts = new int[26][n];
        for (String vote : votes) {
            for (int i = 0; i < n; i++) {
                counts[vote.charAt(i) - 'A'][i]++;
            }
        }
        Character[] charList = new Character[n];
        for (int i = 0; i < n; i++) {
            charList[i] = votes[0].charAt(i);
        }
        Arrays.sort(charList, new Comparator<Character>() {
            @Override
            public int compare(Character a, Character b) {
                int c = Arrays.compare(counts[b - 'A'], counts[a - 'A']);
                return c == 0 ? a - b : c;
            }
        });
        String ans = new String();
        for (Character c : charList) {
            ans += c;
        }
        return ans;
    }
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/30/LeetCode%201366.%E9%80%9A%E8%BF%87%E6%8A%95%E7%A5%A8%E5%AF%B9%E5%9B%A2%E9%98%9F%E6%8E%92%E5%90%8D/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144814103](https://letmefly.blog.csdn.net/article/details/144814103)
