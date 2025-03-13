---
title: 1694.重新格式化电话号码
date: 2022-10-01 09:08:24
tags: [题解, LeetCode, 简单, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】1694.重新格式化电话号码

力扣题目链接：[https://leetcode.cn/problems/reformat-phone-number/](https://leetcode.cn/problems/reformat-phone-number/)

<p>给你一个字符串形式的电话号码 <code>number</code> 。<code>number</code> 由数字、空格 <code>' '</code>、和破折号 <code>'-'</code> 组成。</p>

<p>请你按下述方式重新格式化电话号码。</p>

<ul>
	<li>首先，<strong>删除</strong> 所有的空格和破折号。</li>
	<li>其次，将数组从左到右 <strong>每 3 个一组</strong> 分块，<strong>直到 </strong>剩下 4 个或更少数字。剩下的数字将按下述规定再分块：
	<ul>
		<li>2 个数字：单个含 2 个数字的块。</li>
		<li>3 个数字：单个含 3 个数字的块。</li>
		<li>4 个数字：两个分别含 2 个数字的块。</li>
	</ul>
	</li>
</ul>

<p>最后用破折号将这些块连接起来。注意，重新格式化过程中 <strong>不应该</strong> 生成仅含 1 个数字的块，并且 <strong>最多</strong> 生成两个含 2 个数字的块。</p>

<p>返回格式化后的电话号码。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>number = "1-23-45 6"
<strong>输出：</strong>"123-456"
<strong>解释：</strong>数字是 "123456"
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 3 个数字，将它们放入单个含 3 个数字的块。第 2 个块是 "456" 。
连接这些块后得到 "123-456" 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>number = "123 4-567"
<strong>输出：</strong>"123-45-67"
<strong>解释：</strong>数字是 "1234567".
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 4 个数字，所以将它们分成两个含 2 个数字的块。这 2 块分别是 "45" 和 "67" 。
连接这些块后得到 "123-45-67" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>number = "123 4-5678"
<strong>输出：</strong>"123-456-78"
<strong>解释：</strong>数字是 "12345678" 。
步骤 1：第 1 个块 "123" 。
步骤 2：第 2 个块 "456" 。
步骤 3：剩下 2 个数字，将它们放入单个含 2 个数字的块。第 3 个块是 "78" 。
连接这些块后得到 "123-456-78" 。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>number = "12"
<strong>输出：</strong>"12"
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>number = "--17-5 229 35-39475 "
<strong>输出：</strong>"175-229-353-94-75"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= number.length <= 100</code></li>
	<li><code>number</code> 由数字和字符 <code>'-'</code> 及 <code>' '</code> 组成。</li>
	<li><code>number</code> 中至少含 <strong>2</strong> 个数字。</li>
</ul>


    
## 方法一：模拟

为了方便处理，可以先将原始字符串中的数字摘出来，存储道一个新的字符串中

之后我们遍历这个纯数字字符串，如果前面已经“三三组队”，并且剩余字符数目不超过4个，就开始特判

否则答案中就拼接上这个字符，如果“又拼了三个”，就加上一个“-”

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string reformatNumber(string& number) {
        string num;
        for (char& c : number) {
            if (c >= '0' && c <= '9') {
                num += c;
            }
        }
        string ans;
        for (int i = 0; i < num.size(); i++) {
            if (i % 3 == 0 && num.size() - i <= 4) {
                int remain = num.size() - i;
                if (remain == 2) {
                    ans += num[i];
                    ans += num[i + 1];
                }
                else if (remain == 3) {
                    ans += num[i];
                    ans += num[i + 1];
                    ans += num[i + 2];
                }
                else {
                    ans += num[i];
                    ans += num[i + 1];
                    ans += '-';
                    ans += num[i + 2];
                    ans += num[i + 3];
                }
                break;
            }
            ans += num[i];
            if (i % 3 == 2) {
                ans += '-';
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/01/LeetCode%201694.%E9%87%8D%E6%96%B0%E6%A0%BC%E5%BC%8F%E5%8C%96%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127131733](https://letmefly.blog.csdn.net/article/details/127131733)
