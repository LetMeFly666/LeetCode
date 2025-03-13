---
title: 1598.文件夹操作日志搜集器
date: 2022-09-09 13:27:39
tags: [题解, LeetCode, 简单, 栈, 数组, 字符串, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】1598.文件夹操作日志搜集器：模拟 + 记录深度

力扣题目链接：[https://leetcode.cn/problems/crawler-log-folder/](https://leetcode.cn/problems/crawler-log-folder/)

<p>每当用户执行变更文件夹操作时，LeetCode 文件系统都会保存一条日志记录。</p>

<p>下面给出对变更操作的说明：</p>

<ul>
	<li><code>&quot;../&quot;</code> ：移动到当前文件夹的父文件夹。如果已经在主文件夹下，则 <strong>继续停留在当前文件夹</strong> 。</li>
	<li><code>&quot;./&quot;</code> ：继续停留在当前文件夹<strong>。</strong></li>
	<li><code>&quot;x/&quot;</code> ：移动到名为 <code>x</code> 的子文件夹中。题目数据 <strong>保证总是存在文件夹 <code>x</code></strong> 。</li>
</ul>

<p>给你一个字符串列表 <code>logs</code> ，其中 <code>logs[i]</code> 是用户在 <code>i<sup>th</sup></code> 步执行的操作。</p>

<p>文件系统启动时位于主文件夹，然后执行 <code>logs</code> 中的操作。</p>

<p>执行完所有变更文件夹操作后，请你找出 <strong>返回主文件夹所需的最小步数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/26/sample_11_1957.png" style="height: 151px; width: 775px;"></p>

<pre><strong>输入：</strong>logs = [&quot;d1/&quot;,&quot;d2/&quot;,&quot;../&quot;,&quot;d21/&quot;,&quot;./&quot;]
<strong>输出：</strong>2
<strong>解释：</strong>执行 &quot;../&quot; 操作变更文件夹 2 次，即可回到主文件夹
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/26/sample_22_1957.png" style="height: 270px; width: 600px;"></p>

<pre><strong>输入：</strong>logs = [&quot;d1/&quot;,&quot;d2/&quot;,&quot;./&quot;,&quot;d3/&quot;,&quot;../&quot;,&quot;d31/&quot;]
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>logs = [&quot;d1/&quot;,&quot;../&quot;,&quot;../&quot;,&quot;../&quot;]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= logs.length &lt;= 10<sup>3</sup></code></li>
	<li><code>2 &lt;= logs[i].length &lt;= 10</code></li>
	<li><code>logs[i]</code> 包含小写英文字母，数字，<code>&#39;.&#39;</code> 和 <code>&#39;/&#39;</code></li>
	<li><code>logs[i]</code> 符合语句中描述的格式</li>
	<li>文件夹名称由小写英文字母和数字组成</li>
</ul>


    
## 方法一：模拟 + 记录深度

用一个变量记录当前文件深度（初始值位于根目录，深度为0）

+ 遇到```../```就深度减一，同时确保深度不会为负

+ 遇到```./```就不进行操作

+ 遇到其他就深度加一

最后返回最终深度即可。

+ 时间复杂度$O(n)$，其中$n$是操作次数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int nowDepth = 0;
        for (string& thisLog : logs) {
            if (thisLog == "../") {
                nowDepth = max(nowDepth - 1, 0);
            }
            else if (thisLog == "./") {
                continue;
            }
            else {
                nowDepth++;
            }
        }
        return nowDepth;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/09/LeetCode%201598.%E6%96%87%E4%BB%B6%E5%A4%B9%E6%93%8D%E4%BD%9C%E6%97%A5%E5%BF%97%E6%90%9C%E9%9B%86%E5%99%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126781249](https://letmefly.blog.csdn.net/article/details/126781249)
