---
title: 2446.判断两个事件是否存在冲突
date: 2023-05-17 09:17:06
tags: [题解, LeetCode, 简单, 数组, 字符串, 时间, 区间重叠]


# 【LetMeFly】2446.判断两个事件是否存在冲突

力扣题目链接：[https://leetcode.cn/problems/determine-if-two-events-have-conflict/](https://leetcode.cn/problems/determine-if-two-events-have-conflict/)

<p>给你两个字符串数组 <code>event1</code> 和&nbsp;<code>event2</code>&nbsp;，表示发生在同一天的两个闭区间时间段事件，其中：</p>

<ul>
	<li><code>event1 = [startTime<sub>1</sub>, endTime<sub>1</sub>]</code> 且</li>
	<li><code>event2 = [startTime<sub>2</sub>, endTime<sub>2</sub>]</code></li>
</ul>

<p>事件的时间为有效的 24 小时制且按&nbsp;<code>HH:MM</code>&nbsp;格式给出。</p>

<p>当两个事件存在某个非空的交集时（即，某些时刻是两个事件都包含的），则认为出现 <strong>冲突</strong>&nbsp;。</p>

<p>如果两个事件之间存在冲突，返回&nbsp;<code>true</code><em>&nbsp;</em>；否则，返回<em>&nbsp;</em><code>false</code> 。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
<b>输出：</b>true
<b>解释：</b>两个事件在 2:00 出现交集。
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
<b>输出：</b>true
<b>解释：</b>两个事件的交集从 01:20 开始，到 02:00 结束。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
<b>输出：</b>false
<b>解释：</b>两个事件不存在交集。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>evnet1.length == event2.length == 2.</code></li>
	<li><code>event1[i].length == event2[i].length == 5</code></li>
	<li><code>startTime<sub>1</sub> &lt;= endTime<sub>1</sub></code></li>
	<li><code>startTime<sub>2</sub> &lt;= endTime<sub>2</sub></code></li>
	<li>所有事件的时间都按照&nbsp;<code>HH:MM</code>&nbsp;格式给出</li>
</ul>


    
## 方法一：（麻烦方法）让第一个开始时间不晚于第二个 + 字符串转整数

方法一是刚开始我想的方法。AC过后看了官解发现有更简单的方法。可以直接跳转到方法二。

不失一般性，我们让事件1的开始时间不晚于事件2。如果事件1的开始时间晚于事件2，就交换事件1和事件2。

这样，如果事件2的开始时间在事件1结束时间之后，就说明不冲突；反之则说明冲突。

怎么比较两个时间的先后呢？可以将时间（字符串）转为整数，代表这个时间是今天的第几分钟，之后就可以通过整数进行比较了。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
inline int convertTime(string& s) {
    return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int t1s = convertTime(event1[0]), t1e = convertTime(event1[1]);  // t1 start, t1 end
        int t2s = convertTime(event2[0]), t2e = convertTime(event2[1]);
        if (t1s > t2s) {  // 令第一个开始时间不晚于第二个
            swap(t1s, t2s);
            swap(t1e, t2e);
        }
        return t2s <= t1e;
    }
};
```

#### Python

```python
def convertTime(s: str) -> int:
    _0 = ord('0')
    return (ord(s[0]) - _0) * 600 + (ord(s[1]) - _0) * 60 + (ord(s[3]) - _0) * 10 + (ord(s[4]) - _0)

class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        t1s, t1e = convertTime(event1[0]), convertTime(event1[1])
        t2s, t2e = convertTime(event2[0]), convertTime(event2[1])
        if t1s > t2s:
            t1s, t2s = t2s, t1s
            t1e, t2e = t2e, t1e
        return t2s <= t1e
```

## 方法二：直接开始比较

首先，不需要交换事件1和事件2的早晚。我们需要明白的是：事件1的开始时间晚于事件2的结束时间 或 事件2的开始时间晚于事件1的结束时间，则两事件不冲突。

其次，不需要将时间字符串转为整数，因为字符串之间可以直接比较。。。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return !(event1[1] < event2[0] || event2[1] < event1[0]);
    }
};
```

#### Python

```python
class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        return not(event1[1] < event2[0] or event2[1] < event1[0])
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/17/LeetCode%202446.%E5%88%A4%E6%96%AD%E4%B8%A4%E4%B8%AA%E4%BA%8B%E4%BB%B6%E6%98%AF%E5%90%A6%E5%AD%98%E5%9C%A8%E5%86%B2%E7%AA%81/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130718458](https://letmefly.blog.csdn.net/article/details/130718458)
