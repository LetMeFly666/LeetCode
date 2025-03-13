---
title: 816.模糊坐标
date: 2022-11-07 10:34:56
tags: [题解, LeetCode, 中等, 字符串, 回溯, 模拟, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】816.模糊坐标

力扣题目链接：[https://leetcode.cn/problems/ambiguous-coordinates/](https://leetcode.cn/problems/ambiguous-coordinates/)

<p>我们有一些二维坐标，如&nbsp;<code>&quot;(1, 3)&quot;</code>&nbsp;或&nbsp;<code>&quot;(2, 0.5)&quot;</code>，然后我们移除所有逗号，小数点和空格，得到一个字符串<code>S</code>。返回所有可能的原始字符串到一个列表中。</p>

<p>原始的坐标表示法不会存在多余的零，所以不会出现类似于&quot;00&quot;, &quot;0.0&quot;, &quot;0.00&quot;, &quot;1.0&quot;, &quot;001&quot;, &quot;00.01&quot;或一些其他更小的数来表示坐标。此外，一个小数点前至少存在一个数，所以也不会出现&ldquo;.1&rdquo;形式的数字。</p>

<p>最后返回的列表可以是任意顺序的。而且注意返回的两个数字中间（逗号之后）都有一个空格。</p>

<p>&nbsp;</p>

<pre>
<strong>示例 1:</strong>
<strong>输入:</strong> &quot;(123)&quot;
<strong>输出:</strong> [&quot;(1, 23)&quot;, &quot;(12, 3)&quot;, &quot;(1.2, 3)&quot;, &quot;(1, 2.3)&quot;]
</pre>

<pre>
<strong>示例 2:</strong>
<strong>输入:</strong> &quot;(00011)&quot;
<strong>输出:</strong> &nbsp;[&quot;(0.001, 1)&quot;, &quot;(0, 0.011)&quot;]
<strong>解释:</strong> 
0.0, 00, 0001 或 00.01 是不被允许的。
</pre>

<pre>
<strong>示例 3:</strong>
<strong>输入:</strong> &quot;(0123)&quot;
<strong>输出:</strong> [&quot;(0, 123)&quot;, &quot;(0, 12.3)&quot;, &quot;(0, 1.23)&quot;, &quot;(0.1, 23)&quot;, &quot;(0.1, 2.3)&quot;, &quot;(0.12, 3)&quot;]
</pre>

<pre>
<strong>示例 4:</strong>
<strong>输入:</strong> &quot;(100)&quot;
<strong>输出:</strong> [(10, 0)]
<strong>解释:</strong> 
1.0 是不被允许的。
</pre>

<p>&nbsp;</p>

<p><strong>提示: </strong></p>

<ul>
	<li><code>4 &lt;= S.length &lt;= 12</code>.</li>
	<li><code>S[0]</code> = &quot;(&quot;, <code>S[S.length - 1]</code> = &quot;)&quot;, 且字符串&nbsp;<code>S</code>&nbsp;中的其他元素都是数字。</li>
</ul>

<p>&nbsp;</p>


    
## 方法一：枚举

在主函数中，我们枚举“切割位置”。即将原始字符串切割成非空的两部分，一个代表第一个数，一个代表第二个数

然后写一个函数```vector<string> addPoint(string s)```，接收参数字符串，返回这个字符串添加至多一个小数点所形成的所有可能的合法数字

在主函数中，调用```addPoint```函数，则可分别得到第一个数、第二个数的所有合法数字，再将其一一组合起来添加到答案中

```cpp
vector<string> ambiguousCoordinates(string& s) {
    s = s.substr(1, s.size() - 2);  // 去掉原始字符串中的两个括号(0)
    vector<string> ans;
    for (int i = 0; i + 1 < s.size(); i++) {
        vector<string> front = addPoint(s.substr(0, i + 1));  // 为s[0, i]添加零个或一个小数点 所能得到的所有合法数字
        vector<string> back = addPoint(s.substr(i + 1, s.size() - i - 1));  // s[i + 1, s.size() - 1]
        for (string& s1 : front)
            for (string& s2 : back)
                ans.push_back("(" + s1 + ", " + s2 + ")");  // 分别拼接组合
    }
    return ans;
}
```

那么```addPoint```函数怎么实现呢？

我们再写一个函数```bool aviliable(string& s)```，这个函数接收“受至多一个.”且“不为空”的字符串s，并返回s是否为一个合法数字

那么，```addPoint```函数中，我们只需要枚举小数点的位置，将小数点插入后调用```aviliable```函数判断新生成的数是否合法即可

```cpp
vector<string> addPoint(string s) {
    vector<string> ans;
    if (aviliable(s))  // 无小数点
        ans.push_back(s);
    for (int i = 0; i + 1 < s.size(); i++) {  // 枚举小数点位置
        string thisS = s.substr(0, i + 1) + "." + s.substr(i + 1, s.size() - i - 1);
        if (aviliable(thisS))
            ans.push_back(thisS);
    }
    return ans;
}
```

最后，```aviliable```函数怎么实现呢？

只需要判断是否为以下三种情况：

1. 0axxx：例如0123（其中$a$不是小数点）
2. .xx：例如.3
3. x.x0：例如1.20

出现以上三种情况的一种，即为“不合法字符串”

否则为合法字符串

```cpp
bool aviliable(string& s) {  // 只接受至多一个.的s，只接受不为空的s
    if (s.size() > 1 && s[0] == '0' && s[1] != '.')  // 0axxx
        return false;
    if (s[0] == '.')  // .xx
        return false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            if (s.back() == '0')  // x.x0
                return false;
            if (i == s.size() - 1)
                return false;
            break;
        }
    }
    return true;
}
```

+ 时间复杂度$O(n^3)$，其中$n$是原始字符串的长度
+ 空间复杂度$O(n^3)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool aviliable(string& s) {  // 只接受至多一个.的s，只接受不为空的s
        if (s.size() > 1 && s[0] == '0' && s[1] != '.')  // 0axxx
            return false;
        if (s[0] == '.')  // .xx
            return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                if (s.back() == '0')  // x.x0
                    return false;
                if (i == s.size() - 1)
                    return false;
                break;
            }
        }
        return true;
    }

    vector<string> addPoint(string s) {
        vector<string> ans;
        if (aviliable(s))
            ans.push_back(s);
        for (int i = 0; i + 1 < s.size(); i++) {
            string thisS = s.substr(0, i + 1) + "." + s.substr(i + 1, s.size() - i - 1);
            if (aviliable(thisS))
                ans.push_back(thisS);
        }
        return ans;
    }
public:
    vector<string> ambiguousCoordinates(string& s) {
        s = s.substr(1, s.size() - 2);
        vector<string> ans;
        for (int i = 0; i + 1 < s.size(); i++) {
            vector<string> front = addPoint(s.substr(0, i + 1));
            vector<string> back = addPoint(s.substr(i + 1, s.size() - i - 1));
            for (string& s1 : front)
                for (string& s2 : back)
                    ans.push_back("(" + s1 + ", " + s2 + ")");
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/07/LeetCode%200816.%E6%A8%A1%E7%B3%8A%E5%9D%90%E6%A0%87/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127727007](https://letmefly.blog.csdn.net/article/details/127727007)
