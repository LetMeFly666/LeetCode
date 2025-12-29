---
title: 756.金字塔转换矩阵：深度优先搜索
date: 2025-12-29 23:06:41
tags: [题解, LeetCode, 中等, 位运算, 深度优先搜索, DFS]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/08/26/pyramid2-grid.jpg
---

# 【LetMeFly】756.金字塔转换矩阵：深度优先搜索

力扣题目链接：[https://leetcode.cn/problems/pyramid-transition-matrix/](https://leetcode.cn/problems/pyramid-transition-matrix/)

<p>你正在把积木堆成金字塔。每个块都有一个颜色，用一个字母表示。每一行的块比它下面的行 <strong>少一个块</strong> ，并且居中。</p>

<p>为了使金字塔美观，只有特定的 <strong>三角形图案</strong> 是允许的。一个三角形的图案由&nbsp;<strong>两个块</strong>&nbsp;和叠在上面的 <strong>单个块</strong> 组成。模式是以三个字母字符串的列表形式&nbsp;<code>allowed</code>&nbsp;给出的，其中模式的前两个字符分别表示左右底部块，第三个字符表示顶部块。</p>

<ul>
	<li>例如，<code>"ABC"</code>&nbsp;表示一个三角形图案，其中一个 <code>“C”</code> 块堆叠在一个&nbsp;<code>'A'</code>&nbsp;块(左)和一个&nbsp;<code>'B'</code>&nbsp;块(右)之上。请注意，这与 <code>"BAC"</code>&nbsp;不同，<code>"B"</code>&nbsp;在左下角，<code>"A"</code>&nbsp;在右下角。</li>
</ul>

<p>你从作为单个字符串给出的底部的一排积木&nbsp;<code>bottom</code>&nbsp;开始，<strong>必须</strong>&nbsp;将其作为金字塔的底部。</p>

<p>在给定&nbsp;<code>bottom</code>&nbsp;和&nbsp;<code>allowed</code>&nbsp;的情况下，如果你能一直构建到金字塔顶部，使金字塔中的 <strong>每个三角形图案</strong> 都是在&nbsp;<code>allowed</code>&nbsp;中的，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/08/26/pyramid1-grid.jpg" style="height: 232px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
<strong>输出：</strong>true
<strong>解释：</strong>允许的三角形图案显示在右边。
从最底层(第 3 层)开始，我们可以在第 2 层构建“CE”，然后在第 1 层构建“E”。
金字塔中有三种三角形图案，分别是 “BCC”、“CDE” 和 “CEA”。都是允许的。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/08/26/pyramid2-grid.jpg" style="height: 359px; width: 600px;" /></p>

<pre>
<strong>输入：</strong>bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
<strong>输出：</strong>false
<strong>解释：</strong>允许的三角形图案显示在右边。
从最底层(即第 4 层)开始，创造第 3 层有多种方法，但如果尝试所有可能性，你便会在创造第 1 层前陷入困境。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= bottom.length &lt;= 6</code></li>
	<li><code>0 &lt;= allowed.length &lt;= 216</code></li>
	<li><code>allowed[i].length == 3</code></li>
	<li>所有输入字符串中的字母来自集合&nbsp;<code>{'A', 'B', 'C', 'D', 'E', 'F'}</code>。</li>
	<li>&nbsp;<code>allowed</code>&nbsp;中所有值都是 <strong>唯一的</strong></li>
</ul>


    
## 解题方法：深度优先搜索

```
    A
  B   C
D   E   F
```

上面金字塔可以写成下面的样子：

```
A
B C
D E F
```

这样就可以使用二维数组来表示了（二维数组变量名设为pyramid）。

按什么顺序填充呢？已知题目给定了bottom，那就由下往上由左往右地填充呗！

写一个dfs函数接收两个参数，`dfs(int i, int j)`代表填充到二维数组`pyramid[i][j]`时，整个金字塔是否有解。

如何填充？把所有可以填充的方案依次尝试一下：

```cpp
bool dfs(int i, int j) {
    for (char c : canFill(pyramid[i+1][j], pyramid[i+1][j+1])) {
        pyramid[i][j] = c;
        if (dfs(i, j + 1)) {  // 下一步：填充右边一格
            return true;
        }
    }
    return false;
}
```

其中canFill可以是一个map，快速通过底层两个元素映射到所有上层可以填充的元素。

终止条件？首先递归逻辑是接下来填充右边一格，如果这一行填充完了则改为填充上一行：

```cpp
bool dfs(int i, int j) {
    if (j > i) {
        return dfs(i - 1, 0);
    }
}
```

如果第一行（`i=0`）也填满了，就会递归到`i=-1`行，此时也说明整个金字塔已经填充完毕了，返回`true`。

+ 时间复杂度$O(|\sum|^{n^2})$，其中$n=len(bottom)$而$|\sum|$代表字母集合的大小$6$，搜索树的高度为`i*j`共计$n^2$，每个节点至多$|\sum|$个儿子。
+ 空间复杂度$O(m+n^2)$，其中$m=len(allowed)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-29 22:37:18
 */
class Solution {
private:

    vector<char> mappings[36];
    vector<vector<char>> pyramid;

    inline int bottom2int(char a, char b) {
        return (a - 'A') * 6 + b - 'A';
    }

    bool dfs(int i, int j) {
        if (i < 0) {
            return true;
        }
        if (j > i) {
            return dfs(i - 1, 0);
        }

        for (char c : mappings[bottom2int(pyramid[i + 1][j], pyramid[i + 1][j + 1])]) {
            pyramid[i][j] = c;
            if (dfs(i, j + 1)) {
                return true;
            }
        }
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string& s : allowed) {
            mappings[bottom2int(s[0], s[1])].push_back(s[2]);
        }
        int n = bottom.size();
        pyramid.resize(n);
        for (int i = 0; i < n; i++) {
            pyramid[i].resize(i + 1);
        }
        for (int i = 0; i < n; i++) {
            pyramid[n - 1][i] = bottom[i];
        }
        return dfs(n - 2, 0);
    }
};
```

# End

今日黄金仍在持续下跌中~ 每盎司单日跌超200美元了

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156400643)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/29/LeetCode%200756.%E9%87%91%E5%AD%97%E5%A1%94%E8%BD%AC%E6%8D%A2%E7%9F%A9%E9%98%B5/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
