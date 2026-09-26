---
title: 1404.将二进制表示减到 1 的步骤数：模拟+高精度模拟玩玩(运算符重载)
date: 2026-02-27 22:32:01
tags: [题解, LeetCode, 中等, 位运算, 字符串, 模拟, 高精度, 重载]
categories: [题解, LeetCode]
---

# 【LetMeFly】1404.将二进制表示减到 1 的步骤数：模拟+高精度模拟玩玩(运算符重载)

力扣题目链接：[https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/](https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/)

<p>给你一个以二进制形式表示的数字 <code>s</code> 。请你返回按下述规则将其减少到 1 所需要的步骤数：</p>

<ul>
	<li>
	<p>如果当前数字为偶数，则将其除以 <code>2</code> 。</p>
	</li>
	<li>
	<p>如果当前数字为奇数，则将其加上 <code>1</code> 。</p>
	</li>
</ul>

<p>题目保证你总是可以按上述规则将测试用例变为 1 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "1101"
<strong>输出：</strong>6
<strong>解释：</strong>"1101" 表示十进制数 13 。
Step 1) 13 是奇数，加 1 得到 14&nbsp;
Step 2) 14 是偶数，除 2 得到 7
Step 3) 7  是奇数，加 1 得到 8
Step 4) 8  是偶数，除 2 得到 4&nbsp; 
Step 5) 4  是偶数，除 2 得到 2&nbsp;
Step 6) 2  是偶数，除 2 得到 1&nbsp; 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "10"
<strong>输出：</strong>1
<strong>解释：</strong>"10" 表示十进制数 2 。
Step 1) 2 是偶数，除 2 得到 1 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "1"
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length&nbsp;&lt;= 500</code></li>
	<li><code>s</code> 由字符 <code>'0'</code> 或 <code>'1'</code> 组成。</li>
	<li><code>s[0] == '1'</code></li>
</ul>


    
## 解题方法：模拟

Python直接转int，C++使用字符串双端队列代替

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(\log s)$或$O(len(s))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-27 22:29:56
 */
class LetsNum {
private:
    // 低位->高位
    deque<char> num;
public:
    // From binary string
    LetsNum(string& s) {
        for (char c : s) {
            *this <<= 1;
            *this += c;
        }
    }

    LetsNum& operator++(int) {
        int carry = 1;
        for (deque<char>::iterator it = num.begin(); it != num.end(); it++) {
            carry += *it - '0';
            *it = carry % 10 + '0';
            carry /= 10;
        }
        if (carry) {
            num.push_back(carry + '0');
        }
        return *this;
    }

    // only 0/1 supported
    LetsNum& operator+=(const int& n) {
        if (!n) {
            return *this;
        }
        (*this)++;
        return *this;
    }

    // only 0/1 supported
    LetsNum& operator+=(const char& c) {
        *this += c - '0';
        return *this;
    }

    // only <<1 supported
    LetsNum& operator<<=(const int&) {
        int carry = 0;
        for (deque<char>::iterator it = num.begin(); it != num.end(); it++) {
            carry += (*it - '0') * 2;
            *it = carry % 10 + '0';
            carry /= 10;
        }
        if (carry) {
            num.push_back(carry + '0');
        }
        return *this;
    }

    // only >>1 supported
    LetsNum& operator>>=(const int&) {
        int mod = 0;
        for (deque<char>::reverse_iterator it = num.rbegin(); it != num.rend(); it++) {
            mod = mod * 10 + (*it - '0');
            *it = mod / 2 + '0';
            mod %= 2;
        }
        if (*num.rbegin() == '0') {
            num.pop_back();
        }
        return *this;
    }

    // only 1 supported
    bool operator!=(const int&) {
        return num.size() != 1 || *num.begin() != '1';
    }

    bool isOdd() {
        return (*num.begin() - '0') % 2;
    }

    void print() {
        for (deque<char>::reverse_iterator it = num.rbegin(); it != num.rend(); it++) {
            putchar(*it);
        }
        puts("");
    }
};

class Solution {
public:
    int numSteps(string s) {
        LetsNum num(s);
        int ans = 0;
        while (num != 1) {
            if (num.isOdd()) {
                num += 1;
            } else {
                num >>= 1;
            }
            ans++;
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
1101
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        cout << sol.numSteps(s) << endl;
    }
    return 0;
}
#endif

```

#### Python

```python
'''
LastEditTime: 2026-02-26 23:59:25
'''
"""
1101
1110
111
1000
100
10
1
"""
class Solution:
    def numSteps(self, s: str) -> int:
        a = int(s, 2)
        ans = 0
        while a != 1:
            if a % 2:
                a += 1
            else:
                a //= 2
            ans += 1
            # print(a)
        return ans

# print(Solution.numSteps('', '1101'))

```

C++完胜！(bushi)

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158472038)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/27/LeetCode%201404.%E5%B0%86%E4%BA%8C%E8%BF%9B%E5%88%B6%E8%A1%A8%E7%A4%BA%E5%87%8F%E5%88%B01%E7%9A%84%E6%AD%A5%E9%AA%A4%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
