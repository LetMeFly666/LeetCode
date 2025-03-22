---
title: 牛客-某公司笔试题-20250316-全解析
date: 2025-03-16 23:44:51
tags: [题解, Nowcoder, 字符串, 贪心, 前缀和, 进制转换, 模拟]
categories: [题解, 牛客]
---

# 【LetMeFly】牛客-某公司笔试题-20250316-全解析

<span title="柠檬微趣">该公司</span>给我留下了十分不错的印象，包括我大四时候去参观的一次，以及研究生期间听其他同学说去参观的一次，给人印象十分不错。

大四保完研印象中都三面了，结果为了奉献研究生实验室的项目给HR姐姐打了个电话婉拒了。后悔死了，到现在还没有一段实习经历。

怀揣着对该公司不错的印象，若能有时间为之贡献一份锦帛之力，也能还一个“去一去第一个即将愿意给我发OFFER的公司”的愿吧。

不过公司要求C++求职者只能使用C++且不能使用STL库函数以及sort等函数，那就尽量手动实现吧。

## 一：单词规律(模式匹配)

题目地址：[LeetCode - 290.单词规律](https://leetcode.cn/problems/word-pattern/)

标签：[字符串](https://blog.letmefly.xyz/tags/%E5%AD%97%E7%AC%A6%E4%B8%B2/)

### 题目描述

<p>给定一种规律 <code>pattern</code>&nbsp;和一个字符串&nbsp;<code>s</code>&nbsp;，判断 <code>s</code>&nbsp;是否遵循相同的规律。</p>

<p>这里的&nbsp;<strong>遵循&nbsp;</strong>指完全匹配，例如，&nbsp;<code>pattern</code>&nbsp;里的每个字母和字符串&nbsp;<code>s</code><strong>&nbsp;</strong>中的每个非空单词之间存在着双向连接的对应规律。</p>

<p>&nbsp;</p>

<p><strong class="example">示例1:</strong></p>

<pre>
<strong>输入:</strong> pattern = <code>"abba"</code>, s = <code>"dog cat cat dog"</code>
<strong>输出:</strong> true</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<strong>输入:</strong>pattern = <code>"abba"</code>, s = <code>"dog cat cat fish"</code>
<strong>输出:</strong> false</pre>

<p><strong class="example">示例 3:</strong></p>

<pre>
<strong>输入:</strong> pattern = <code>"aaaa"</code>, s = <code>"dog cat cat dog"</code>
<strong>输出:</strong> false</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 300</code></li>
	<li><code>pattern</code>&nbsp;只包含小写英文字母</li>
	<li><code>1 &lt;= s.length &lt;= 3000</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母和&nbsp;<code>' '</code></li>
	<li><code>s</code>&nbsp;<strong>不包含</strong> 任何前导或尾随对空格</li>
	<li><code>s</code>&nbsp;中每个单词都被 <strong>单个空格 </strong>分隔</li>
</ul>

### 解题思路

两个哈希表，记录哪个字符对应哪个字符串、哪个字符串对应哪个字符。

然后遍历一遍字符串把字符串拆分为字符串数组，若pattern和字符串数组长度相同则一一判断是否一一对应。

### AC代码

```cpp
class Solution {
private:
    vector<string> s2v(string s) {
        vector<string> ans;
        int last = -1;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                string thisStr = s.substr(last + 1, i - last - 1);
                if (thisStr.size()) {
                    ans.push_back(thisStr);
                }
                last = i;
            }
        }
        return ans;
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pattern string字符串 
     * @param str string字符串 
     * @return bool布尔型
     */
    bool wordPattern(string pattern, string str) {
        // write code here
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        vector<string> v = s2v(str);
        if (pattern.size() != v.size()) {
            return false;
        }
        for (int i = 0; i < v.size(); i++) {
            if (p2s.count(pattern[i])) {
                if (p2s[pattern[i]] != v[i]) {
                    return false;
                }
            } else {
                p2s[pattern[i]] = v[i];
            }

            if (s2p.count(v[i])) {
                if (s2p[v[i]] != pattern[i]) {
                    return false;
                }
            } else {
                s2p[v[i]] = pattern[i];
            }
        }
        return true;
    }
};
```

当时没想到拿字符串映射字符（没有使用s2p）那个哈希表，竟然过了90%。

## 二：下一个更大元素

类似题目：[LeetCode - 556.下一个更大元素III](https://leetcode.cn/problems/next-greater-element-iii/)

标签：[贪心](https://blog.letmefly.xyz/tags/%E8%B4%AA%E5%BF%83/)

### 题目描述

<p>给你一个正整数 <code>n</code> ，请你找出符合条件的最小整数，其由重新排列 <code>n</code><strong> </strong>中存在的每位数字组成，并且其值大于 <code>n</code> 。如果不存在这样的正整数，则返回 <code>-1</code> 。</p>

<p><strong>注意</strong> ，返回的整数应当是一个 <strong>32 位整数</strong> ，如果存在满足题意的答案，但不是 <strong>32 位整数</strong> ，同样返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 12
<strong>输出：</strong>21
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 21
<strong>输出：</strong>-1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 2<sup>31</sup> - 1</code></li>
</ul>

### 解题思路

解这道题之前推荐先解一下另外一道题：[LeetCode - 0031.下一个排列](https://leetcode.cn/problems/next-permutation/)：

> 力扣官方题解的动图做的不错：
> 
> ![0031力扣官方题解动图](https://assets.leetcode.cn/solution-static/31/31.gif)
>
> <!-- https://i-blog.csdnimg.cn/img_convert/cfe8dab382d906ee772abc57b9ab951e.gif -->
>
> 首先找到最后一个“后面有比他大的数”的数（假设下标为$i$），接着找$i$后面最后一个大于它的数（假设下标为$j$），交换元素$i$、$j$
>
> 这样，对于交换的两个数，就满足了“最小数尽可能靠右”、“最大数尽可能小”。
>
> 然后将第一个交换位置后面的数组逆序（因为后面的数组一定是递减的）

那么这道题也就迎刃而解了，多的步骤就是十进制数和字符串之间的相互转换。同时，可以用64位整数存储中间结果以防止32位整数溢出。

### AC代码

```cpp
typedef long long ll;
class Solution {
private:
    string itos(int n) {
        string s;
        while (n) {
            s = char('0' + n % 10) + s;
            n /= 10;
        }
        return s;
    }

    ll stoi(string s) {
        ll ans = 0;
        for (char c : s) {
            ans = ans * 10 + c - '0';
        }
        return ans;
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param N int整型 
     * @return int整型

     12334
     12343

     12343
     12433

     1235
     */
    int nextGreaterElement(int N) {
        // write code here
        string s = itos(N);
        int last = -1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] > s[i - 1]) {
                last = i - 1;
            }
        }
        if (last == -1) {
            return -1;
        }
        cout << last << endl;
        int j = s.size() - 1;
        for (; ; j--) {
            if (s[j] > s[last]) {
                break;
            }
        }
        swap(s[last], s[j]);
        // cout << s << endl;
        reverse(s.begin() + last + 1, s.end());
        // cout << s << endl;
        ll ans = stoi(s);
        cout << ans << endl;
        if (ans > INT_MAX) {
            return -1;
        }
        return ans;
    }
};
```

这道题当时有两个问题：

1. 排序范围错了
2. 交换错了（没有交换后方尽可能小的值而是直接交换了相邻值）

当时竟然通过了80%。

## 三：找两个和为目标值且不重叠的子数组

题目地址：[LeetCode - 1477.找两个和为目标值且不重叠的子数组](https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)

标签：[前缀和](https://blog.letmefly.xyz/tags/%E5%89%8D%E7%BC%80%E5%92%8C/)

### 题目描述

<p>给你一个整数数组&nbsp;<code>arr</code> 和一个整数值&nbsp;<code>target</code>&nbsp;。</p>

<p>请你在 <code>arr</code>&nbsp;中找 <strong>两个互不重叠的子数组</strong>&nbsp;且它们的和都等于&nbsp;<code>target</code>&nbsp;。可能会有多种方案，请你返回满足要求的两个子数组长度和的 <strong>最小值</strong> 。</p>

<p>请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 <strong>-1</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,2,2,4,3], target = 3
<strong>输出：</strong>2
<strong>解释：</strong>只有两个子数组和为 3 （[3] 和 [3]）。它们的长度和为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [7,3,4,7], target = 7
<strong>输出：</strong>2
<strong>解释：</strong>尽管我们有 3 个互不重叠的子数组和为 7 （[7], [3,4] 和 [7]），但我们会选择第一个和第三个子数组，因为它们的长度和 2 是最小值。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [4,3,2,6,2,3,4], target = 6
<strong>输出：</strong>-1
<strong>解释：</strong>我们只有一个和为 6 的子数组。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [5,5,4,4,5], target = 3
<strong>输出：</strong>-1
<strong>解释：</strong>我们无法找到和为 3 的子数组。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [3,1,1,1,5,1,2,1], target = 3
<strong>输出：</strong>3
<strong>解释：</strong>注意子数组 [1,2] 和 [2,1] 不能成为一个方案因为它们重叠了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= target &lt;= 10^8</code></li>
</ul>

### 解题思路

类似滑动窗口，由于元素全正，所以窗口中元素越多窗口中的和越大。对于一个指定的“窗口终点”，(元素和不大于target的)窗口起点是固定的。

我们可以开辟一个数组minPrefix，其中minPrefix[i]代表下标不超过i的子数组中，最小的和为target的元素个数。

这样，对于每个“窗口终点”，如果窗口中元素和恰好为target，则使用当前窗口大小更新历史最小窗口大小。

同理，我们也可以**反过来**倒着滑动一次，得到minSuffix。minSuffix[i]代表所有下标不小于i的子数组中，和为target的最小子数组的元素个数。

这样，我们只需要遍历一遍数组，$\min\{minPrefix[i] + minSuffix[i + 1]\}$即为所求。

### AC代码

```cpp
class Solution {
private:
    void debug(vector<int>& a) {
        for (int t : a) {
            cout << t << ' ';
        }
        puts("");
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A int整型vector 
     * @param T int整型 
     * @return int整型
     */
    int minSumOfLengths(vector<int>& a, int T) {
        // write code here
        vector<int> minPrefix(a.size());
        int l = 0, cnt = 0, ans = 100000000;
        for (int r = 0; r < a.size(); r++) {
            cnt += a[r];
            while (l < r && cnt > T) {
                cnt -= a[l++];
            }
            if (cnt == T) {
                ans = min(ans, r - l + 1);
            }
            minPrefix[r] = ans;
        }
        // debug(minPrefix);

        vector<int> minSuffix(a.size());
        int r = a.size() - 1;
        cnt = 0, ans = 10000000;
        for (int l = a.size() - 1; l >= 0; l--) {
            cnt += a[l];
            while (l < r && cnt > T) {
                cnt -= a[r--];
            }
            if (cnt == T) {
                ans = min(ans, r - l + 1);
            }
            minSuffix[l] = ans;
        }

        ans = 10000000;
        for (int i = 0; i + 1 < a.size(); i++) {
            ans = min(ans, minPrefix[i] + minSuffix[i + 1]);
        }
        return ans > a.size() ? -1 : ans;
    }
};
```

这道题第一遍读题没想到思路，第二遍读题想到并且很快AC了。

## 四：Protocol Buffers序列化和反序列化模拟

题目地址：暂未找到

标签：[进制转换](https://blog.letmefly.xyz/tags/%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2/)、[模拟](https://blog.letmefly.xyz/tags/%E6%A8%A1%E6%8B%9F/)

### 题目描述

Google采用数字变长编码来传输。 给定一个数字和一个编码后的字符串，输出数字的编码和对字符串解码后的数字。

**编码方式：** 对于给定数字M，将其转换成二进制，取前七位（低位），并将第八位（高位）作为标志位。如果第八位是1，则说明需要继续编码，是0则说明编码结束。编码结果是纯大写的十六进制字符串，例如0XE3。

对于给定编码字符串S，其是一个纯大写的十六进制表示数字的字符串，比如0XE70X07，其中0XE7是第一个数字，取出来并将16进制转换成二进制，观察其高位是1还是0。是1，则弃其高位，继续计算下边的0X07并拼接到前边的高位上，转换成数字输出回来。

**举例：**

输入：

```
100
0XE70X0&
```

输出：

```
0X64
999
```

解释：

100 = 0x64 = 0b01100100，高位（第八位）是0，所以编码后是0X64。

0XE70X07 先看0XE7。

0xe7 = 0b11100111，高位为1，所以要继续往后算0X07。

0x07 = 0b00000111，高位为0，所以这个数字应该是：

0b00000111（去掉高位）连接0b11100111（去掉高位）

0b00001111100111 = 999

因此输出应该是0X64和999。

### 解题思路

就主打一个进制转换、字符串数字转换、细心读题和模拟呗。

### AC代码

```cpp
#include <iostream>
using namespace std;
typedef long long ll;

/*
1100100
4 + 32 + 64 = 100


*/

/*
100 -> 1100100
*/
string itos(ll a) {
    string s;
    while (a) {
        s = char('0' + a % 2) + s;
        a >>= 1;
    }
    return s;
}

/*
0111 -> 7
*/
string _422(string s) {
    ll n = 0;
    for (char c : s) {
        n = n * 2 + c - '0';
    }
    // cout << "n: " << n << endl;
    string ans;
    if (n < 10) {
        ans = string(1, char('0' + n));
    } else {
        ans = string(1, char('A' + n - 10));
    }
    // cout << ans << endl;
    return ans;
}

/*
11100111 -> 0XE7
*/
string stos(string s) {
    // cout << s << endl;
    if (s.size() < 8) {
        s = string(8 - s.size(), '0') + s;
    }
    // cout << "stos: " << s << endl;
    return "0X" + _422(s.substr(0, 4)) + _422(s.substr(4, 4));
}

string fi(ll a) {
    string s = itos(a);
    // cout << s << endl;
    string ans = "";
    while (s.size() > 7) {
        string thisStr = '1' + s.substr(s.size() - 7, 7);
        s = s.substr(0, s.size() - 7);
        ans += stos(thisStr);
    }
    ans += stos(s);
    return ans;
}

ll c2i(char c) {
    if (c <= '9') {
        return c - '0';
    }
    return 10 + c - 'A';
}

string c2s(char c) {
    ll n = c2i(c);
    string temp = itos(n);
    if (temp.size() < 4) {
        temp = string(4 - temp.size(), '0') + temp;
    }
    return temp;
}

/*
0XE7 -> 1100111(丢掉最高位)
*/
string _16_2(string s) {
    // cout << "_16_2: " << s << endl;
    return (c2s(s[2]) + c2s(s[3])).substr(1, 7);
}

/*
二进制->10进制
*/
ll _2_10(string s) {
    ll ans = 0;
    for (char c : s) {
        ans = ans * 2 + c - '0';
    }
    return ans;
}

ll fs(string s) {
    string bin;
    for (ll i = 0; i < s.size(); i += 4) {
        bin = _16_2(s.substr(i, 4)) + bin;
    }
    return _2_10(bin);
}

int main() {
    ll a;
    string s;
    cin >> a >> s;
    cout << fi(a) << endl;
    cout << fs(s) << endl;
}
// 64 位输出请用 prllf("%lld")
```

这道题写了好多函数，甚至有重复的。。。

牛客无法调试，中间print了好多次。

但是最终也用屎山代码AC了。

## End

**考完之后**搜考题的时候搜到了一个[帖子](https://www.nowcoder.com/discuss/497532413803773952)，竟然是原题！

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146304076)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/16/Nowcoder-NingMengWeiQu-20250316-YiMian/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
