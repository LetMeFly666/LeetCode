---
title: 682.棒球比赛
date: 2024-07-29 22:56:25
tags: [题解, LeetCode, 简单, 栈, 数组, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】682.棒球比赛：模拟

力扣题目链接：[https://leetcode.cn/problems/baseball-game/](https://leetcode.cn/problems/baseball-game/)

<p>你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。</p>

<p>比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 <code>ops</code>，其中 <code>ops[i]</code> 是你需要记录的第 <code>i</code> 项操作，<code>ops</code> 遵循下述规则：</p>

<ol>
	<li>整数 <code>x</code> - 表示本回合新获得分数 <code>x</code></li>
	<li><code>"+"</code> - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。</li>
	<li><code>"D"</code> - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。</li>
	<li><code>"C"</code> - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。</li>
</ol>

<p>请你返回记录中所有得分的总和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ops = ["5","2","C","D","+"]
<strong>输出：</strong>30
<strong>解释：</strong>
"5" - 记录加 5 ，记录现在是 [5]
"2" - 记录加 2 ，记录现在是 [5, 2]
"C" - 使前一次得分的记录无效并将其移除，记录现在是 [5].
"D" - 记录加 2 * 5 = 10 ，记录现在是 [5, 10].
"+" - 记录加 5 + 10 = 15 ，记录现在是 [5, 10, 15].
所有得分的总和 5 + 10 + 15 = 30
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>ops = ["5","-2","4","C","D","9","+","+"]
<strong>输出：</strong>27
<strong>解释：</strong>
"5" - 记录加 5 ，记录现在是 [5]
"-2" - 记录加 -2 ，记录现在是 [5, -2]
"4" - 记录加 4 ，记录现在是 [5, -2, 4]
"C" - 使前一次得分的记录无效并将其移除，记录现在是 [5, -2]
"D" - 记录加 2 * -2 = -4 ，记录现在是 [5, -2, -4]
"9" - 记录加 9 ，记录现在是 [5, -2, -4, 9]
"+" - 记录加 -4 + 9 = 5 ，记录现在是 [5, -2, -4, 9, 5]
"+" - 记录加 9 + 5 = 14 ，记录现在是 [5, -2, -4, 9, 5, 14]
所有得分的总和 5 + -2 + -4 + 9 + 5 + 14 = 27
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>ops = ["1"]
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= ops.length <= 1000</code></li>
	<li><code>ops[i]</code> 为 <code>"C"</code>、<code>"D"</code>、<code>"+"</code>，或者一个表示整数的字符串。整数范围是 <code>[-3 * 10<sup>4</sup>, 3 * 10<sup>4</sup>]</code></li>
	<li>对于 <code>"+"</code> 操作，题目数据保证记录此操作时前面总是存在两个有效的分数</li>
	<li>对于 <code>"C"</code> 和 <code>"D"</code> 操作，题目数据保证记录此操作时前面总是存在一个有效的分数</li>
</ul>


    
## 解题方法：模拟

使用一个数组记录每次的得分。然后开始遍历操作数组：

+ 如果当前操作是`+`：就将得分数组中的最后两个元素相加并将结果添加到得分数组中
+ 如果当前操作是`D`：就将得分数组中的最后一个元素乘二并将结果添加到得分数组中
+ 如果当前操作是`C`：就移除得分数组中的最后一个元素
+ 否则，将当前字符串转化为整数并加入得分数组中

最终返回得分数组中的元素之和。

+ 时间复杂度$O(len(ops))$
+ 空间复杂度$O(len(ops))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> score;
        for (string& op : operations) {
            if (op == "+") {
                score.push_back(score[score.size() - 1] + score[score.size() - 2]);
            }
            else if (op == "D") {
                score.push_back(score.back() * 2);
            }
            else if (op == "C") {
                score.pop_back();
            }
            else {
                score.push_back(atoi(op.c_str()));
            }
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};
```

#### Go

```go
package main

import "strconv"

func calPoints(operations []string) int {
    score := []int{}
    for _, op := range operations {
        switch op[0] {
        case '+':
            score = append(score, score[len(score) - 1] + score[len(score) - 2])
        case 'D':
            score = append(score, score[len(score) - 1] * 2)
        case 'C':
            score = score[:len(score) - 1]
        default:
            t, _ := strconv.Atoi(op)
            score = append(score, t)
        }
    }
    ans := 0
    for _, t := range score {
        ans += t
    }
    return ans
}
```

#### Java

```java
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int calPoints(String[] operations) {
        List<Integer> score = new ArrayList<>();
        for (String op : operations) {
            switch (op.charAt(0)) {
                case '+':
                    score.add(score.get(score.size() - 1) + score.get(score.size() - 2));
                    break;
                case 'D':
                    score.add(score.get(score.size() - 1) * 2);
                    break;
                case 'C':
                    score.remove(score.size() - 1);
                    break;
                default:
                    score.add(Integer.parseInt(op));
                    break;
            }
        }
        int ans = 0;
        for (int t : score) {
            ans += t;
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def calPoints(self, operations: List[str]) -> int:
        score = []
        for op in operations:
            if op == '+':
                score.append(score[-1] + score[-2])
            elif op == 'D':
                score.append(score[-1] * 2)
            elif op == 'C':
                score.pop()
            else:
                score.append(int(op))
        return sum(score)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/29/LeetCode%200682.%E6%A3%92%E7%90%83%E6%AF%94%E8%B5%9B/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140783345](https://letmefly.blog.csdn.net/article/details/140783345)
