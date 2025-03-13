---
title: 831.隐藏个人信息
date: 2023-04-01 09:49:53
tags: [题解, LeetCode, 中等, 字符串, 模拟, 字符串解析]
categories: [题解, LeetCode]
---

# 【LetMeFly】831.隐藏个人信息

力扣题目链接：[https://leetcode.cn/problems/masking-personal-information/](https://leetcode.cn/problems/masking-personal-information/)

<p>给你一条个人信息字符串 <code>s</code> ，可能表示一个 <strong>邮箱地址</strong> ，也可能表示一串 <strong>电话号码</strong> 。返回按如下规则 <strong>隐藏</strong> 个人信息后的结果：</p>

<p><em><strong>电子邮件地址：</strong></em></p>

<p>一个电子邮件地址由以下部分组成：</p>

<ul>
	<li>一个 <strong>名字</strong> ，由大小写英文字母组成，后面跟着</li>
	<li>一个 <code>'@'</code> 字符，后面跟着</li>
	<li>一个 <strong>域名</strong> ，由大小写英文字母和一个位于中间的 <code>'.'</code> 字符组成。<code>'.'</code> 不会是域名的第一个或者最后一个字符。</li>
</ul>

<p>要想隐藏电子邮件地址中的个人信息：</p>

<ul>
	<li><strong>名字</strong> 和 <strong>域名</strong> 部分的大写英文字母应当转换成小写英文字母。</li>
	<li><strong>名字</strong> 中间的字母（即，除第一个和最后一个字母外）必须用 5 个 <code>"*****"</code> 替换。</li>
</ul>

<p><em><strong>电话号码：</strong></em></p>

<p>一个电话号码应当按下述格式组成：</p>

<ul>
	<li>电话号码可以由 10-13 位数字组成</li>
	<li>后 10 位构成 <strong>本地号码</strong></li>
	<li>前面剩下的 0-3 位，构成 <strong>国家代码</strong></li>
	<li>利用 <code>{'+', '-', '(', ')', ' '}</code> 这些 <strong>分隔字符</strong> 按某种形式对上述数字进行分隔</li>
</ul>

<p>要想隐藏电话号码中的个人信息：</p>

<ul>
	<li>移除所有 <strong>分隔字符</strong></li>
	<li>隐藏个人信息后的电话号码应该遵从这种格式：
	<ul>
		<li><code>"***-***-XXXX"</code> 如果国家代码为 0 位数字</li>
		<li><code>"+*-***-***-XXXX"</code> 如果国家代码为 1 位数字</li>
		<li><code>"+**-***-***-XXXX"</code> 如果国家代码为 2 位数字</li>
		<li><code>"+***-***-***-XXXX"</code> 如果国家代码为 3 位数字</li>
	</ul>
	</li>
	<li><code>"XXXX"</code> 是最后 4 位 <strong>本地号码</strong></li>
</ul>
&nbsp;

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "LeetCode@LeetCode.com"
<strong>输出：</strong>"l*****e@leetcode.com"
<strong>解释：</strong>s 是一个电子邮件地址。
名字和域名都转换为小写，名字的中间用 5 个 * 替换。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "AB@qq.com"
<strong>输出：</strong>"a*****b@qq.com"
<strong>解释：</strong>s 是一个电子邮件地址。
名字和域名都转换为小写，名字的中间用 5 个 * 替换。
注意，尽管 "ab" 只有两个字符，但中间仍然必须有 5 个 * 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "1(234)567-890"
<strong>输出：</strong>"***-***-7890"
<strong>解释：</strong>s 是一个电话号码。
共计 10 位数字，所以本地号码为 10 位数字，国家代码为 0 位数字。
因此，隐藏后的电话号码应该是 "***-***-7890" 。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "86-(10)12345678"
<strong>输出：</strong>"+**-***-***-5678"
<strong>解释：</strong>s 是一个电话号码。
共计 12 位数字，所以本地号码为 10 位数字，国家代码为 2 位数字。
因此，隐藏后的电话号码应该是 "+**-***-***-7890" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s</code> 是一个 <strong>有效</strong> 的电子邮件或者电话号码</li>
	<li>如果 <code>s</code> 是一个电子邮件：
	<ul>
		<li><code>8 &lt;= s.length &lt;= 40</code></li>
		<li><code>s</code> 是由大小写英文字母，恰好一个 <code>'@'</code> 字符，以及 <code>'.'</code> 字符组成</li>
	</ul>
	</li>
	<li>如果 <code>s</code> 是一个电话号码：
	<ul>
		<li><code>10 &lt;= s.length &lt;= 20</code></li>
		<li><code>s</code> 是由数字、空格、字符 <code>'('</code>、<code>')'</code>、<code>'-'</code> 和 <code>'+'</code> 组成</li>
	</ul>
	</li>
</ul>
</div>
</div>
</div>


    
## 方法一：字符串解析

首先判断字符串中是否存在```'@'```或```'.'```，以此来区分字符串是电话还是邮箱。

### 邮箱

找到字符串中```'@'```的下标，将答案字符串加上“字符串的第一个字符的小写形式”和“```'@'```下标的前一个下标对应字符的小写形式”

之后从```'@'```开始遍历字符串，若是大写字母则在答案字符串中加上其小写形式，否则直接加上原字母。

### 电话

首先统计字符串中数字的个数$cntNum$。依据$cntNum - 10$是0还是1还是2还是3分别在答案中加上打码号码的前缀```***-***-```或```+*-***-***-```或```+**-***-***-```或```+***-***-***-```

之后解析出字符串中的最后四个数字并添加到答案的末尾。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$（或$O(len(s))$）

### AC代码

#### C++

```cpp
class Solution {
public:
    string maskPII(string s) {
        bool isemail = false;
        for (char c : s) {
            if (c == '@' || c == '.') {
                isemail = true;
                break;
            }
        }
        string ans;
        if (isemail) {
            ans += tolower(s[0]);
            ans += "*****";
            int locAt = 0;
            while (s[locAt] != '@') {
                locAt++;
            }
            ans += tolower(s[locAt - 1]);
            while (locAt < s.size()) {
                if (isupper(s[locAt])) {
                    ans += tolower(s[locAt]);
                }
                else {
                    ans += s[locAt];
                }
                locAt++;
            }
        }
        else {
            int cntNum = 0;
            for (char c : s) {
                cntNum += isdigit(c);
            }
            if (cntNum == 10) {
                ans = "***-***-";
            }
            else if (cntNum == 11) {
                ans = "+*-***-***-";
            }
            else if (cntNum == 12) {
                ans = "+**-***-***-";
            }
            else {
                ans = "+***-***-***-";
            }
            int cntTail = 0;
            char tail[4];
            for (int i = s.size() - 1; cntTail < 4; i--) {
                if (isdigit(s[i])) {
                    tail[cntTail++] = s[i];
                }
            }
            for (int i = 3; i >= 0; i--) {
                ans += tail[i];
            }
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def maskPII(self, s: str) -> str:
        if '@' in s:  # email
            locAt = s.find('@')
            return s[0].lower() + '*****' + s[locAt - 1].lower() + s[locAt:].lower()
        else:
            cntNum = sum(c.isdigit() for c in s)
            ans = ["***-***-", "+*-***-***-", "+**-***-***-", "+***-***-***-"][cntNum - 10]
            allDigital = "".join(c if c.isdigit() else "" for c in s)
            for i in range(len(allDigital) - 4, len(allDigital)):
                ans += allDigital[i]
            return ans
```

## What's more

写完后看了看[官解](https://leetcode.cn/problems/masking-personal-information/solutions/2200759/yin-cang-ge-ren-xin-xi-by-leetcode-solut-2enf/)，太sao了

transform、正则

```cpp
class Solution {
public:
    vector<string> country = {"", "+*-", "+**-", "+***-"};

    string maskPII(string s) {
        string res;
        int at = s.find("@");
        if (at != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(at - 1);
        }
        s = regex_replace(s, regex("[^0-9]"), "");
        return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
    }
};
```

```python
class Solution:
    def maskPII(self, s: str) -> str:
        at = s.find('@')
        if at >= 0:
            return (s[0] + "*" * 5 + s[at - 1:]).lower()
        s = "".join(i for i in s if i.isdigit())
        return ["", "+*-", "+**-", "+***-"][len(s) - 10] + "***-***-" + s[-4:]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/01/LeetCode%200831.%E9%9A%90%E8%97%8F%E4%B8%AA%E4%BA%BA%E4%BF%A1%E6%81%AF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129893329](https://letmefly.blog.csdn.net/article/details/129893329)
