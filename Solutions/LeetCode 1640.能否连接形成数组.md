---
title: 1640.能否连接形成数组
date: 2022-09-22 08:28:29
tags: [题解, LeetCode, 简单, 数组, 哈希表]
categories: [题解, LeetCode]
---

# 【LetMeFly】1640.能否连接形成数组

力扣题目链接：[https://leetcode.cn/problems/check-array-formation-through-concatenation/](https://leetcode.cn/problems/check-array-formation-through-concatenation/)

<p>给你一个整数数组 <code>arr</code> ，数组中的每个整数 <strong>互不相同</strong> 。另有一个由整数数组构成的数组 <code>pieces</code>，其中的整数也 <strong>互不相同</strong> 。请你以 <strong>任意顺序</strong> 连接 <code>pieces</code> 中的数组以形成 <code>arr</code> 。但是，<strong>不允许</strong> 对每个数组 <code>pieces[i]</code> 中的整数重新排序。</p>

<p>如果可以连接<em> </em><code>pieces</code> 中的数组形成 <code>arr</code> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [15,88], pieces = [[88],[15]]
<strong>输出：</strong>true
<strong>解释：</strong>依次连接 <code>[15]</code> 和 <code>[88]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [49,18,16], pieces = [[16,18,49]]
<strong>输出：</strong>false
<strong>解释：</strong>即便数字相符，也不能重新排列 pieces[0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
<strong>输出：</strong>true
<strong>解释：</strong>依次连接 <code>[91]</code>、<code>[4,64]</code> 和 <code>[78]</code></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pieces.length &lt;= arr.length &lt;= 100</code></li>
	<li><code>sum(pieces[i].length) == arr.length</code></li>
	<li><code>1 &lt;= pieces[i].length &lt;= arr.length</code></li>
	<li><code>1 &lt;= arr[i], pieces[i][j] &lt;= 100</code></li>
	<li><code>arr</code> 中的整数 <strong>互不相同</strong></li>
	<li><code>pieces</code> 中的整数 <strong>互不相同</strong>（也就是说，如果将 <code>pieces</code> 扁平化成一维数组，数组中的所有整数互不相同）</li>
</ul>


    
## 方法一：模拟：遇到一个piece的开始，就得陪伴到这个piece的结束

用一个变量$nowTh$来记录当前正在处理pieces的第几个piece。-1表示无处理了一半的piece。

用一个变量$nowThTh$来记录当前处理到$pieces[nowTh]$的第几个元素。

从前往后遍历arr，如果$nowTh$为-1，就说明不是“某个piece处理到了一半”。那么就遍历pieces中所有piece的第一个元素，遇到和arr中当前元素相同的，就更新nowTh，并将nowThTh置为0（该处理pieces[nowTh][0]了）

如果未找到相同元素，就返回false。

之后如果arr中当前遍历到的元素不等于pieces[nowTh][nowThTh]，就返回false

arr成功遍历完后，就返回true

+ 时间复杂度$O(n\times m)$, 其中$n=arr.length, m = pieces.length$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int nowTh = -1, nowThTh;
        for (int& t : arr) {
            if (nowTh == -1) {  // 说明没有哪个piece处理到了一半
                for (int i = 0; i < pieces.size(); i++) {  // 那么就找哪个piece的第一个元素和t相同
                    if (pieces[i][0] == t) {  // 找到了就更新nowTh和nowThTh
                        nowTh = i;
                        nowThTh = 0;
						break;
                    }
                }
                if (nowTh == -1) {  // 全部遍历完未找到就返回false
                    return false;
                }
            }
            if (t != pieces[nowTh][nowThTh]) {  // 这个元素和待处理元素不同就返回false
                return false;
            }
            nowThTh++;  // 下一个待处理元素
            if (nowThTh == pieces[nowTh].size()) {  // 这个piece处理完了，下次就需要重新寻找了
                nowTh = -1;
            }
        }
        return true;  // 全部成功遍历完了arr
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/22/LeetCode%201640.%E8%83%BD%E5%90%A6%E8%BF%9E%E6%8E%A5%E5%BD%A2%E6%88%90%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126984622](https://letmefly.blog.csdn.net/article/details/126984622)
