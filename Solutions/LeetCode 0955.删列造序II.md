---
title: 955.删列造序 II：模拟（O(mn)） + 提前退出
date: 2025-12-21 20:48:50
tags: [题解, LeetCode, 中等, 贪心, 数组, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】955.删列造序 II：模拟（O(mn)） + 提前退出

力扣题目链接：[https://leetcode.cn/problems/delete-columns-to-make-sorted-ii/](https://leetcode.cn/problems/delete-columns-to-make-sorted-ii/)

<p>给定由 <code>n</code> 个字符串组成的数组 <code>strs</code>，其中每个字符串长度相等。</p>

<p>选取一个删除索引序列，对于 <code>strs</code> 中的每个字符串，删除对应每个索引处的字符。</p>

<p>比如，有 <code>strs = ["abcdef", "uvwxyz"]</code>，删除索引序列 <code>{0, 2, 3}</code>，删除后 <code>strs</code> 为<code>["bef", "vyz"]</code>。</p>

<p>假设，我们选择了一组删除索引 <code>answer</code>，那么在执行删除操作之后，最终得到的数组的元素是按 <strong>字典序</strong>（<code>strs[0] <= strs[1] <= strs[2] ... <= strs[n - 1]</code>）排列的，然后请你返回 <code>answer.length</code> 的最小可能值。</p>

<p> </p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["ca","bb","ac"]
<strong>输出：</strong>1
<strong>解释： </strong>
删除第一列后，strs = ["a", "b", "c"]。
现在 strs 中元素是按字典排列的 (即，strs[0] <= strs[1] <= strs[2])。
我们至少需要进行 1 次删除，因为最初 strs 不是按字典序排列的，所以答案是 1。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["xc","yb","za"]
<strong>输出：</strong>0
<strong>解释：</strong>
strs 的列已经是按字典序排列了，所以我们不需要删除任何东西。
注意 strs 的行不需要按字典序排列。
也就是说，strs[0][0] <= strs[0][1] <= ... 不一定成立。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>strs = ["zyx","wvu","tsr"]
<strong>输出：</strong>3
<strong>解释：</strong>
我们必须删掉每一列。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == strs.length</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>1 <= strs[i].length <= 100</code></li>
	<li><code>strs[i]</code> 由小写英文字母组成</li>
</ul>


    
## 解题方法：模拟

### 解题思路

先来理解题意：

> 删除尽可能少的列，使得上面一行字符串的字典序不大于下面一行。

什么时候上面(a)字典序不大于下面一行(b)呢？

> 从前往后遍历两个字符串：
>
> + 一旦遇到`a[i] > b[i]`，直接不符
> + 一旦遇到`a[i] > b[i]`，直接符合（后面不用看了）
> + 如果遇到`a[i] = b[i]`，目前符合，继续往后看

好了，现在开始一列一列地遍历，去保留满足条件的列，删去不满足条件的列吧！

### 具体做法

使用一个布尔数组canSkip，其中canSkip[i]为true则代表第i行可以跳过与上一行的比较。

第一层循环枚举列，一列一列开始遍历；

第二层循环枚举行，从第二行开始枚举到最后一行：

+ 如果当前行被skip则直接跳过当前行
+ 否则，如果当前行小于上一行，这一列必须移除，退出第二层循环，删除这行（实际是答案数量+1）
+ 如果遍历到最后一行仍然满足条件，则这一列无需移除，再次遍历这一列，如果下一行大于上一行，则下一行永远不会比上一行字典序大，下次不用遍历“下一行”了，将`canSkip[下一行]`设置为true。

特殊的，我们可以记录下一共有多少行可以跳过，当所有行都可以被跳过时，后续再也不用遍历了，直接返回答案即可。

### 时空复杂度

+ 时间复杂度$O(size(strs))$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-21 20:46:33
 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs.size(), m = strs[0].size();
        int totalSkip = 1;  // 第一行不用校验
        vector<bool> canSkip(n);
        for (int j = 0; j < m; j++) {
            bool can = true;
            for (int i = 1; i < n; i++) {
                if (canSkip[i]) {
                    continue;
                }
                if (strs[i][j] < strs[i-1][j]) {
                    can = false;
                    break;
                }
            }
            if (can) {
                for (int i = 1; i < n; i++) {
                    if (strs[i][j] != strs[i-1][j] && !canSkip[i]) {
                        canSkip[i] = true;
                        totalSkip++;
                        if (totalSkip == n) {
                            return ans;
                        }
                    }
                }
            } else {
                ans++;
            }
        }
        return ans;
    }
};
```

+ 执行用时分布0ms击败100.00%
+ 消耗内存分布12.57MB击败81.82%

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156134471)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/21/LeetCode%200955.%E5%88%A0%E5%88%97%E9%80%A0%E5%BA%8FII/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
