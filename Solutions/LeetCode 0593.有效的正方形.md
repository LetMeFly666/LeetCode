---
title: 593.有效的正方形
date: 2022-07-29 11:41:43
tags: [题解, LeetCode, 中等, 几何, 数学, 模拟, 正方形判断, 重载]
categories: [题解, LeetCode]
---

# 【LetMeFly】593.有效的正方形

力扣题目链接：[https://leetcode.cn/problems/valid-square/](https://leetcode.cn/problems/valid-square/)

<p>给定2D空间中四个点的坐标&nbsp;<code>p1</code>,&nbsp;<code>p2</code>,&nbsp;<code>p3</code>&nbsp;和&nbsp;<code>p4</code>，如果这四个点构成一个正方形，则返回 <code>true</code> 。</p>

<p>点的坐标&nbsp;<code>p<sub>i</sub></code> 表示为 <code>[xi, yi]</code> 。输入 <strong>不是</strong> 按任何顺序给出的。</p>

<p>一个 <strong>有效的正方形</strong> 有四条等边和四个等角(90度角)。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
<strong>输出:</strong> True
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
<b>输出：</b>false
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<b>输入：</b>p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
<b>输出：</b>true
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>p1.length == p2.length == p3.length == p4.length == 2</code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= x<sub>i</sub>, y<sub>i</sub>&nbsp;&lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：模拟

如果四个点能组成一个正方形，那么这$4$个点必须满足以下$3$个条件：

1. 没有重合的点
2. 四条边等长
3. 存在直角

第$1$条比较容易理解，如果满足第$2$条，那么四边形就是**菱形**

只要菱形中存在一个直角（第$3$条），那么这个菱形就是**矩形**

**有没有重合的点：**

把四个点添加到一个数组里，然后用$i$和$j$遍历数组，一一判断是否有重合的点。

**四条边等长：**

注意，我们不知道哪两个点是一条边上的点，哪两个点是对角上的点。

但是只有$4$个点，我们把$4$个点的相对顺序，全部模拟一遍即可。

也就是说求一遍$4$个点的全排列。

**存在直角：**

相比起来，这个就很容易判断了。

直接使用勾股定理即可。

+ 时间复杂度$O(C! + C^2)$，其中$C$是点的个数($=4$)。判断是否有相同的点的时间复杂度是$O(C^2)$，全排列的时间复杂度是$O(C!)$
+ 空间复杂度$O(C)$，使用了数个等大小的临时变量。

### 拓展

如果想要debug某个点，可以重载运算符

```cpp
ostream& operator<< (ostream& out, vector<int>& v) {
    out << '[';
    for (int i = 0; i < v.size(); i++) {
        if (i)
            out << ", ";
        out << v[i];
    }
    out << ']';
    return out;
}
```

这样，我们直接```cout```某个点即可：

```cpp
cout << "Ok: [" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << endl;
```

### AC代码

#### C++

```cpp
class Solution {
private:
    /* 计算两个点之间的距离 */
    inline int distance2(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }

    bool ifOkThisOrder(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12 = distance2(p1, p2);
        int d23 = distance2(p2, p3);
        int d34 = distance2(p3, p4);
        int d41 = distance2(p4, p1);
        // 四条边等长
        if (d12 != d23 || d23 != d34 || d34 != d41)
            return false;
        // 有直角
        return d12 + d23 == distance2(p1, p3);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> v[4] = {p1, p2, p3, p4};
        // 点不重合
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (v[i] == v[j])
                    return false;
            }
        }
        vector<int> order = {0, 1, 2, 3};
        do {
            if (ifOkThisOrder(v[order[0]], v[order[1]], v[order[2]], v[order[3]])) {
                // cout << "Ok: [" << v[order[0]] << ", " << v[order[1]] << ", " << v[order[2]] << ", " << v[order[3]] << endl;
                return true;
            }
        } while (next_permutation(order.begin(), order.end()));
        return false;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/29/LeetCode%200593.%E6%9C%89%E6%95%88%E7%9A%84%E6%AD%A3%E6%96%B9%E5%BD%A2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126053093](https://letmefly.blog.csdn.net/article/details/126053093)
