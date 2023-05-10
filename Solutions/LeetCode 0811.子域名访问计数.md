---
title: 811.子域名访问计数
date: 2022-10-05 20:36:53
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, 字符串, 计数]
---

# 【LetMeFly】811.子域名访问计数

力扣题目链接：[https://leetcode.cn/problems/subdomain-visit-count/](https://leetcode.cn/problems/subdomain-visit-count/)

<p>网站域名 <code>"discuss.leetcode.com"</code> 由多个子域名组成。顶级域名为 <code>"com"</code> ，二级域名为 <code>"leetcode.com"</code> ，最低一级为 <code>"discuss.leetcode.com"</code> 。当访问域名 <code>"discuss.leetcode.com"</code> 时，同时也会隐式访问其父域名 <code>"leetcode.com" </code>以及 <code>"com"</code> 。</p>

<p><strong>计数配对域名</strong> 是遵循 <code>"rep d1.d2.d3"</code> 或 <code>"rep d1.d2"</code> 格式的一个域名表示，其中 <code>rep</code> 表示访问域名的次数，<code>d1.d2.d3</code> 为域名本身。</p>

<ul>
	<li>例如，<code>"9001 discuss.leetcode.com"</code> 就是一个 <strong>计数配对域名</strong> ，表示 <code>discuss.leetcode.com</code> 被访问了 <code>9001</code> 次。</li>
</ul>

<p>给你一个<strong> 计数配对域名 </strong>组成的数组 <code>cpdomains</code> ，解析得到输入中每个子域名对应的&nbsp;<strong>计数配对域名</strong> ，并以数组形式返回。可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>cpdomains = ["9001 discuss.leetcode.com"]
<strong>输出：</strong>["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
<strong>解释：</strong>例子中仅包含一个网站域名："discuss.leetcode.com"。
按照前文描述，子域名 "leetcode.com" 和 "com" 都会被访问，所以它们都被访问了 9001 次。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
<strong>输出：</strong>["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
<strong>解释：</strong>按照前文描述，会访问 "google.mail.com" 900 次，"yahoo.com" 50 次，"intel.mail.com" 1 次，"wiki.org" 5 次。
而对于父域名，会访问 "mail.com" 900 + 1 = 901 次，"com" 900 + 50 + 1 = 951 次，和 "org" 5 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= cpdomain.length &lt;= 100</code></li>
	<li><code>1 &lt;= cpdomain[i].length &lt;= 100</code></li>
	<li><code>cpdomain[i]</code> 会遵循 <code>"rep<sub>i</sub> d1<sub>i</sub>.d2<sub>i</sub>.d3<sub>i</sub>"</code> 或 <code>"rep<sub>i</sub> d1<sub>i</sub>.d2<sub>i</sub>"</code> 格式</li>
	<li><code>rep<sub>i</sub></code> 是范围 <code>[1, 10<sup>4</sup>]</code> 内的一个整数</li>
	<li><code>d1<sub>i</sub></code>、<code>d2<sub>i</sub></code> 和 <code>d3<sub>i</sub></code> 由小写英文字母组成</li>
</ul>


    
## 方法一：哈希

遍历每个字符串，在遍历过程中将“出现次数”、“域名”分开

遍历域名，将域名及所有的子域名在哈希表中出现的次数都加上“出现次数”

最终，再遍历哈希表，将哈希表中的元素存入数组中即可。

+ 时间复杂度$O(N)$，其中$N$是给定数组中的所有字符的个数之和。
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> ma;
        for (string& s : cpdomains) {
            int locSpace = s.find(' ');
            int times = atoi(s.substr(0, locSpace).c_str());
            string domain = s.substr(locSpace + 1, s.size() - locSpace - 1);
            ma[domain] += times;
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    ma[domain.substr(i + 1, domain.size() - i - 1)] += times;
                }
            }
        }
        vector<string> ans;
        for (auto& [domain, times] : ma) {
            ans.push_back(to_string(times) + ' ' + domain);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/05/LeetCode%200811.%E5%AD%90%E5%9F%9F%E5%90%8D%E8%AE%BF%E9%97%AE%E8%AE%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127176602](https://letmefly.blog.csdn.net/article/details/127176602)
