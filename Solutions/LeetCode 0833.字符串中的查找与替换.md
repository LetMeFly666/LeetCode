---
title: 833.字符串中的查找与替换
date: 2023-08-15 08:18:06
tags: [题解, LeetCode, 中等, 数组, 字符串, 字符串匹配, 排序, 模拟, 大模拟]
---

# 【LetMeFly】833.字符串中的查找与替换

力扣题目链接：[https://leetcode.cn/problems/find-and-replace-in-string/](https://leetcode.cn/problems/find-and-replace-in-string/)

<p>你会得到一个字符串 <code>s</code>&nbsp;(索引从 0 开始)，你必须对它执行 <code>k</code> 个替换操作。替换操作以三个长度均为 <code>k</code> 的并行数组给出：<code>indices</code>,&nbsp;<code>sources</code>,&nbsp;&nbsp;<code>targets</code>。</p>

<p>要完成第 <code>i</code> 个替换操作:</p>

<ol>
	<li>检查 <strong>子字符串</strong> &nbsp;<code>sources[i]</code>&nbsp;是否出现在 <strong>原字符串</strong> <code>s</code> 的索引&nbsp;<code>indices[i]</code>&nbsp;处。</li>
	<li>如果没有出现，&nbsp;<strong>什么也不做</strong>&nbsp;。</li>
	<li>如果出现，则用&nbsp;<code>targets[i]</code>&nbsp;<strong>替换</strong>&nbsp;该子字符串。</li>
</ol>

<p>例如，如果 <code>s = "abcd"</code>&nbsp;，&nbsp;<code>indices[i] = 0</code> ,&nbsp;<code>sources[i] = "ab"</code>， <code>targets[i] = "eee"</code> ，那么替换的结果将是 <code>"<u>eee</u>cd"</code> 。</p>

<p>所有替换操作必须 <strong>同时</strong> 发生，这意味着替换操作不应该影响彼此的索引。测试用例保证元素间<strong>不会重叠 </strong>。</p>

<ul>
	<li>例如，一个 <code>s = "abc"</code> ，&nbsp; <code>indices = [0,1]</code> ， <code>sources = ["ab"，"bc"]</code>&nbsp;的测试用例将不会生成，因为 <code>"ab"</code> 和 <code>"bc"</code> 替换重叠。</li>
</ul>

<p><em>在对 <code>s</code>&nbsp;执行所有替换操作后返回 <strong>结果字符串</strong> 。</em></p>

<p><strong>子字符串</strong> 是字符串中连续的字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/06/12/833-ex1.png" style="height: 251px; width: 411px;" /></p>

<pre>
<strong>输入：</strong>s = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
<strong>输出：</strong>"eeebffff"
<strong>解释：
</strong>"a" 从 s 中的索引 0 开始，所以它被替换为 "eee"。
"cd" 从 s 中的索引 2 开始，所以它被替换为 "ffff"。
</pre>

<p><strong>示例 2：</strong><img src="https://assets.leetcode.com/uploads/2021/06/12/833-ex2-1.png" style="height: 251px; width: 411px;" /></p>

<pre>
<strong>输入：</strong>s = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
<strong>输出：</strong>"eeecd"
<strong>解释：
</strong>"ab" 从 s 中的索引 0 开始，所以它被替换为 "eee"。
"ec" 没有从<strong>原始的</strong> S 中的索引 2 开始，所以它没有被替换。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>k == indices.length == sources.length == targets.length</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li><code>0 &lt;= indexes[i] &lt; s.length</code></li>
	<li><code>1 &lt;= sources[i].length, targets[i].length &lt;= 50</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>sources[i]</code> 和 <code>targets[i]</code> 仅由小写英文字母组成</li>
</ul>


    
## 方法一：模拟

首先将“替换信息”```indices```、```sources```、```targets```打包起来，按照```indices```从小到大排序，记为```v```。

写一个函数```equal(s, toCmp, start)```用来判断```s```从```start```处开始是否与```toCmp```匹配。

这样，我们只需要用下标$i$遍历```s```：
   + 若$i$等于$v$中待处理的$indices$，看字符串$s$从$i$处开始是否与$v$中待处理的$sources$匹配：
      + 若匹配：进行替换（答案加上对应的$targets$，$i$加上被替换掉的字符串的长度减1）
	  + 否则：不进行替换（答案加上$s[i]$）
   + 否则：不进行替换（答案加上$s[i]$）

+ 时间复杂度$O(C + n\log n)$，其中$C$是$sources$和$targets$中字母个数之和，$n=len(sources)$。
+ 空间复杂度$O(C + \log n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool equal(string& s, string& toCmp, int start) {  // 返回s从下标start开始，是否与toCmp匹配
        if (start + toCmp.size() > s.size()) {
            return false;
        }
        for (int i = 0; i < toCmp.size(); i++) {
            if (s[start + i] != toCmp[i]) {
                return false;
            }
        }
        return true;
    }

public:
    string findReplaceString(string& s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<tuple<int, string, string>> v;
        for (int i = 0; i < indices.size(); i++) {
            v.push_back({indices[i], sources[i], targets[i]});
        }
        sort(v.begin(), v.end(), [](tuple<int, string, string>& a, tuple<int, string, string>& b) {
            return get<0>(a) < get<0>(b);
        });
        
        string ans;
        int nowV = 0;
        for (int i = 0; i < s.size(); i++) {
            if (nowV < v.size() && get<0>(v[nowV]) == i) {
                if (equal(s, get<1>(v[nowV]), i)) {
                    ans += get<2>(v[nowV]);
                    i += get<1>(v[nowV]).size() - 1;
                }
                else {
                    ans += s[i];
                }
                nowV++;
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/15/LeetCode%200833.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE%E4%B8%8E%E6%9B%BF%E6%8D%A2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132289306](https://letmefly.blog.csdn.net/article/details/132289306)
