---
title: 2511.最多可以摧毁的敌人城堡数目
date: 2023-09-02 09:43:34
tags: [题解, LeetCode, 简单, 数组, 双指针, 遍历, 模拟]
---

# 【LetMeFly】2511.最多可以摧毁的敌人城堡数目

力扣题目链接：[https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/](https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/)

<p>给你一个长度为 <code>n</code>&nbsp;，下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>forts</code>&nbsp;，表示一些城堡。<code>forts[i]</code> 可以是&nbsp;<code>-1</code>&nbsp;，<code>0</code>&nbsp;或者&nbsp;<code>1</code>&nbsp;，其中：</p>

<ul>
	<li><code>-1</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个位置 <strong>没有</strong>&nbsp;城堡。</li>
	<li><code>0</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个位置有一个 <strong>敌人</strong>&nbsp;的城堡。</li>
	<li><code>1</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个位置有一个你控制的城堡。</li>
</ul>

<p>现在，你需要决定，将你的军队从某个你控制的城堡位置&nbsp;<code>i</code>&nbsp;移动到一个空的位置&nbsp;<code>j</code>&nbsp;，满足：</p>

<ul>
	<li><code>0 &lt;= i, j &lt;= n - 1</code></li>
	<li>军队经过的位置 <strong>只有</strong>&nbsp;敌人的城堡。正式的，对于所有&nbsp;<code>min(i,j) &lt; k &lt; max(i,j)</code>&nbsp;的&nbsp;<code>k</code>&nbsp;，都满足&nbsp;<code>forts[k] == 0</code>&nbsp;。</li>
</ul>

<p>当军队移动时，所有途中经过的敌人城堡都会被 <strong>摧毁</strong> 。</p>

<p>请你返回 <strong>最多</strong>&nbsp;可以摧毁的敌人城堡数目。如果 <strong>无法</strong>&nbsp;移动你的军队，或者没有你控制的城堡，请返回 <code>0</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>forts = [1,0,0,-1,0,0,0,0,1]
<b>输出：</b>4
<strong>解释：</strong>
- 将军队从位置 0 移动到位置 3 ，摧毁 2 个敌人城堡，位置分别在 1 和 2 。
- 将军队从位置 8 移动到位置 3 ，摧毁 4 个敌人城堡。
4 是最多可以摧毁的敌人城堡数目，所以我们返回 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>forts = [0,0,1,-1]
<b>输出：</b>0
<b>解释：</b>由于无法摧毁敌人的城堡，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= forts.length &lt;= 1000</code></li>
	<li><code>-1 &lt;= forts[i] &lt;= 1</code></li>
</ul>


    
## 方法一：遍历

这道题说白了就是问你```1```和```-1```之间最大的连续```0```的个数。

因此我们只需要使用一个变量```last```来记录上一个```非0```数是```1```还是```-1```，再使用一个变量```cnt```来记录当前连续```0```的个数。

接着遍历地图数组：

+ 如果当前元素非零：
   + 就看是否为 “```1遇到-1```或```-1遇到1```”，如果是则更新答案最大值
   + 更新```cnt```和```last```
+ 否则（当前元素为0）：$cnt++$

即可。

+ 时间复杂度$O(len(forts))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int captureForts(vector<int>& forts) {  // 1和-1之间最多连续0的个数
        int ans = 0;
        int last = 2, cnt = 0;
        for (int i = 0; i < forts.size(); i++) {
            if (forts[i]) {
                if ( last != forts[i] && last != 2) {
                    ans = max(ans, cnt);
                }
                last = forts[i];
                cnt = 0;
            }
            else {  // 0
                cnt++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def captureForts(self, forts: List[int]) -> int:
        ans = 0
        last, cnt = 2, 0
        for fort in forts:
            if fort:
                if fort != last and last != 2:
                    ans = max(ans, cnt)
                cnt = 0
                last = fort
            else:
                cnt += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/09/02/LeetCode%202511.%E6%9C%80%E5%A4%9A%E5%8F%AF%E4%BB%A5%E6%91%A7%E6%AF%81%E7%9A%84%E6%95%8C%E4%BA%BA%E5%9F%8E%E5%A0%A1%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132634912](https://letmefly.blog.csdn.net/article/details/132634912)
