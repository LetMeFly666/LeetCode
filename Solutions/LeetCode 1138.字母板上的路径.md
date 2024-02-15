---
title: 1138.字母板上的路径
date: 2023-02-12 10:05:08
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 模拟]
---

# 【LetMeFly】1138.字母板上的路径

力扣题目链接：[https://leetcode.cn/problems/alphabet-board-path/](https://leetcode.cn/problems/alphabet-board-path/)

<p>我们从一块字母板上的位置&nbsp;<code>(0, 0)</code>&nbsp;出发，该坐标对应的字符为&nbsp;<code>board[0][0]</code>。</p>

<p>在本题里，字母板为<code>board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]</code>，如下所示。</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/07/28/azboard.png" style="width: 300px;" /></p>

<p>我们可以按下面的指令规则行动：</p>

<ul>
	<li>如果方格存在，<code>'U'</code>&nbsp;意味着将我们的位置上移一行；</li>
	<li>如果方格存在，<code>'D'</code>&nbsp;意味着将我们的位置下移一行；</li>
	<li>如果方格存在，<code>'L'</code>&nbsp;意味着将我们的位置左移一列；</li>
	<li>如果方格存在，<code>'R'</code>&nbsp;意味着将我们的位置右移一列；</li>
	<li><code>'!'</code>&nbsp;会把在我们当前位置 <code>(r, c)</code> 的字符&nbsp;<code>board[r][c]</code>&nbsp;添加到答案中。</li>
</ul>

<p>（注意，字母板上只存在有字母的位置。）</p>

<p>返回指令序列，用最小的行动次数让答案和目标&nbsp;<code>target</code>&nbsp;相同。你可以返回任何达成目标的路径。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = "leet"
<strong>输出：</strong>"DDR!UURRR!!DDD!"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = "code"
<strong>输出：</strong>"RR!DDRR!UUL!R!"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 100</code></li>
	<li><code>target</code>&nbsp;仅含有小写英文字母。</li>
</ul>


    
## 方法一：计算坐标

我们以字母a为原点，右为x轴正方向，下为y轴正方向建立坐标轴，单位长度为题目描述中字母表中的一个字母。

```
O--------> x
|
|
↓
y
```

这样，只要知道起点和终点的坐标，就能很方便地得出要移动的方向。

怎么由字符映射为坐标呢？很简单，假设字符c是字母表中的第3个字母，我们从0开始计数，则c的位次为2。

那么，$2 // 6 = 2$即为字符c的纵坐标，$2\%6=0$即为字符c的横坐标

**那么剩下的问题就是知道起点和终点的坐标，怎么得到移动路径**

很简单，如果终点坐标的纵坐标小于起点的纵坐标，则向上移动二者的差值次；否则向下移动这么多次。如果终点坐标的横坐标小于起点的横坐标，则向左移动二者的差值次；否则向右移动这么多次。

**细节问题：题目中字母表不是规则的矩形，怎么保证移动过程中不会超出字母表的边界呢？**

有两种方法：

1. 特判终点是否为z。如果终点为z则先左右移动后上下移动，否则先上下移动后左右移动即可
2. 不论何时都先尽量向左上移动（如果需要），后向右下移动（如果需要）

**复杂度分析：**

+ 时间复杂度$O(len(target)\times C)$，其中$C$为平均每次的移动次数
+ 空间复杂度$O(1)$或$O(len(target))$。对于字符串可变的编程语言（例如C/C++），只需要每次将移动路径添加到字符串末尾；对于字符串不可变的编程语言（例如Python），则需要额外开辟一个空间存储每次的移动路径，或者每次复制字符串并结合为一个新的字符串。

### AC代码

#### C++

**特判终点是否为z：**

```cpp
// 特判是否终点是z，如果终点是z则先左右移动后上下移动；否则先上下移动后左右移动即可
typedef pair<int, int> pii;

inline pii c2p(char c) {
    int th = c - 'a';
    return {th / 5, th % 5};
}

class Solution {
public:
    string alphabetBoardPath(string& target) {
        string ans;
        pii nowLoc = {0, 0};
        for (char c : target) {
            pii newLoc = c2p(c);
            if (c == 'z') {
                ans += string(abs(newLoc.second - nowLoc.second), newLoc.second > nowLoc.second ? 'R' : 'L');
                ans += string(abs(newLoc.first - nowLoc.first), newLoc.first > nowLoc.first ? 'D' : 'U');
            }
            else {
                ans += string(abs(newLoc.first - nowLoc.first), newLoc.first > nowLoc.first ? 'D' : 'U');
                ans += string(abs(newLoc.second - nowLoc.second), newLoc.second > nowLoc.second ? 'R' : 'L');
            }
            ans += '!';
            nowLoc = newLoc;
        }
        return ans;
    }
};
```

**先尽量左上移后右下移：**

```cpp
// 四个方向分别判断，优先先左上移动后右下移动即可
typedef pair<int, int> pii;

inline pii c2p(char c) {
    int th = c - 'a';
    return {th / 5, th % 5};
}

class Solution {
public:
    string alphabetBoardPath(string& target) {
        string ans;
        pii nowLoc = {0, 0};
        for (char c : target) {
            pii newLoc = c2p(c);
            if (newLoc.first < nowLoc.first)
                ans += string(nowLoc.first - newLoc.first, 'U');
            if (newLoc.second < nowLoc.second)
                ans += string(nowLoc.second - newLoc.second, 'L');
            if (newLoc.first > nowLoc.first)
                ans += string(newLoc.first - nowLoc.first, 'D');
            if (newLoc.second > nowLoc.second)
                ans += string(newLoc.second - nowLoc.second, 'R');
            ans += '!';
            nowLoc = newLoc;
        }
        return ans;
    }
};
```

#### Python

先尽量左上移后右下移：

```python
# from typing import Tuple


def c2p(c: str) -> Tuple[int, int]:
    th = ord(c) - ord('a')
    return th // 5, th % 5

class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        ans = []
        nowY, nowX = 0, 0
        for c in target:
            newY, newX = c2p(c)
            if newY < nowY:
                ans.append('U' * (nowY - newY))
            if newX < nowX:
                ans.append('L' * (nowX - newX))
            if newY > nowY:
                ans.append('D' * (newY - nowY))
            if newX > nowX:
                ans.append('R' * (newX - nowX))
            ans.append('!')
            nowY, nowX = newY, newX
        return "".join(ans)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/02/12/LeetCode%201138.%E5%AD%97%E6%AF%8D%E6%9D%BF%E4%B8%8A%E7%9A%84%E8%B7%AF%E5%BE%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128992281](https://letmefly.blog.csdn.net/article/details/128992281)
