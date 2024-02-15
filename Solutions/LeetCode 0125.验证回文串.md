---
title: 125.验证回文串
date: 2022-07-20 12:39:15
tags: [题解, LeetCode, 简单, 双指针, 字符串, 回文串]
---

# 【LetMeFly】125.验证回文串

力扣题目链接：[https://leetcode.cn/problems/valid-palindrome/](https://leetcode.cn/problems/valid-palindrome/)

<p>给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。</p>

<p><strong>说明：</strong>本题中，我们将空字符串定义为有效的回文串。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> "A man, a plan, a canal: Panama"
<strong>输出:</strong> true
<strong>解释：</strong>"amanaplanacanalpanama" 是回文串
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> "race a car"
<strong>输出:</strong> false
<strong>解释：</strong>"raceacar" 不是回文串
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 2 * 10<sup>5</sup></code></li>
	<li>字符串 <code>s</code> 由 ASCII 字符组成</li>
</ul>


    
## 方法一：清洗字符串 + 判断

这种方法容易想到，但是空间复杂度稍微大一些

既然题目说只考虑```字母数字```，那么不如我们把字母数字提取出来，形成一个新串。

```cpp
string strip(string& s) {
    string ans;
    for (char& c : s) {
        if (c >= 'a' && c <= 'z')
            ans += c;
        else if (c >= 'A' && c <= 'Z')  // 大写字母的话顺统一便转成小写（本题大小写不敏感）
            ans += (char)(c + 32);
        else if (c >= '0' && c <= '9')
            ans += c;
    }
    return ans;
}
```

之后，再判断清洗过的字符串是否为回文串即可（从前往后变量半个字符，看第$i$个和倒数第$i$个字符是否相同）

```cpp
bool isPalindrome(string& s) {
    s = strip(s);
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
```

+ 时间复杂度$O(N)$，其中$N$是字符串的长度
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    string strip(string& s) {
        string ans;
        for (char& c : s) {
            if (c >= 'a' && c <= 'z')
                ans += c;
            else if (c >= 'A' && c <= 'Z')
                ans += (char)(c + 32);
            else if (c >= '0' && c <= '9')
                ans += c;
        }
        return ans;
    }
public:
    bool isPalindrome(string& s) {
        s = strip(s);
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
};
```

## 方法二：不开辟额外空间，直接忽略非字母数字的字符

这样没法直接确定前面第$i$个字母数字对应的倒数第$i$个字母数字是谁。

那么直接使用双指针，一个从前往后，一个从后往前，遇到非字母数字就忽略，直到前后指针重叠为止

+ 时间复杂度$O(N)$，其中$N$是字符串的长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    inline bool isCN(char c) {
        if (c >= 'A' && c <= 'Z')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            // 找到下一个字母数字
            while (!isCN(s[l]) && l < r)
                l++;
            while (!isCN(s[r]) && l < r)
                r--;
            // 字母的话统一转为小写
            if (s[l] >= 'A' && s[l] <= 'Z')
                s[l] += 32;
            if (s[r] >= 'A' && s[r] <= 'Z')
                s[r] += 32;
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/20/LeetCode%200125.%E9%AA%8C%E8%AF%81%E5%9B%9E%E6%96%87%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125889961](https://letmefly.blog.csdn.net/article/details/125889961)
