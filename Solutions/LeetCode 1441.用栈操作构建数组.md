---
title: 1441.用栈操作构建数组
date: 2022-10-15 10:00:04
tags: [题解, LeetCode, 简单, 栈, 数组, 模拟]
---

# 【LetMeFly】1441.用栈操作构建数组

力扣题目链接：[https://leetcode.cn/problems/build-an-array-with-stack-operations/](https://leetcode.cn/problems/build-an-array-with-stack-operations/)

<p>给你一个目标数组 <code>target</code> 和一个整数 <code>n</code>。每次迭代，需要从&nbsp; <code>list = {1,2,3..., n}</code> 中依序读取一个数字。</p>

<p>请使用下述操作来构建目标数组 <code>target</code> ：</p>

<ul>
	<li><strong>Push</strong>：从 <code>list</code> 中读取一个新元素， 并将其推入数组中。</li>
	<li><strong>Pop</strong>：删除数组中的最后一个元素。</li>
	<li>如果目标数组构建完成，就停止读取更多元素。</li>
</ul>

<p>题目数据保证目标数组严格递增，并且只包含 <code>1</code> 到 <code>n</code> 之间的数字。</p>

<p>请返回构建目标数组所用的操作序列。</p>

<p>题目数据保证答案是唯一的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = [1,3], n = 3
<strong>输出：</strong>["Push","Push","Pop","Push"]
<strong>解释： 
</strong>读取 1 并自动推入数组 -&gt; [1]
读取 2 并自动推入数组，然后删除它 -&gt; [1]
读取 3 并自动推入数组 -&gt; [1,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = [1,2,3], n = 3
<strong>输出：</strong>["Push","Push","Push"]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>target = [1,2], n = 4
<strong>输出：</strong>["Push","Push"]
<strong>解释：</strong>只需要读取前 2 个数字就可以停止。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 100</code></li>
	<li><code>1 &lt;= target[i]&nbsp;&lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>target</code> 是严格递增的</li>
</ul>


    
## 方法一：模拟

### 题目分析

题目中说：

> 题目数据保证目标数组严格递增，并且只包含 1 到 n 之间的数字。

这就不需要考虑“无法构建”的问题了。也就是说输入一定合法，给定的```target```一定能构建出来。

既然```list```中的元素是从1到n，而target相当于是“list的子序列”，也就是说从list中**删除**了一些元素，但相对顺序不变。

欸嘿，打住。从```list```中“删除”了一些元素，那是怎么删除的呢？

很简单，想要删除某个元素，直接让这个元素“入栈”后直接“出栈”就可以了。

以样例一为例，```target = [1, 3]```，```list = {1, 2, 3}```

+ 首先是```list```的第一个元素```1```，因为```target```中**存在**```1```，所以直接让```1```“入栈”就好
+ 其次是```list```的第二个元素```2```，因为```target```中**不存在**```2```，所以让```2```“入栈”后直接“出栈”就好
+ 再次是```list```的第三个元素```3```，因为```target```中**存在**```3```，所以直接让```3```“入栈”就好

因此返回```[Push, Push, Pop, Push]```即可。

### 解题思路

那么怎么编程实现呢？

可以用一个变量```now```来记录处理到了```list```中的哪个元素，初始值是```1```

之后遍历```target```数组：

当```now```不等于当前遍历到的元素时，就执行“入栈”和“出栈”两种操作，然后```now```指向```list```中的下一个元素（$now++$）

直到```now```等于当前遍历到的元素，就执行一次“入栈”，并将```now```指向```list```中的下一个元素（$now++$）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int now = 1;
        for (int& t : target) {
            while (t != now) {
                ans.push_back("Push");
                ans.push_back("Pop");
                now++;
            }
            ans.push_back("Push");
            now++;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/15/LeetCode%201441.%E7%94%A8%E6%A0%88%E6%93%8D%E4%BD%9C%E6%9E%84%E5%BB%BA%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127331876](https://letmefly.blog.csdn.net/article/details/127331876)
