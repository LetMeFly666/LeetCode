---
title: 3043.最长公共前缀的长度：哈希表(不转string)
date: 2026-05-21 22:34:26
tags: [题解, LeetCode, 中等, 字典树, 数组, 哈希表, set, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】3043.最长公共前缀的长度：哈希表(不转string)

力扣题目链接：[https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix/](https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix/)

<p>给你两个 <strong>正整数 </strong>数组 <code>arr1</code> 和 <code>arr2</code> 。</p>

<p>正整数的 <strong>前缀 </strong>是其 <strong>最左边 </strong>的一位或多位数字组成的整数。例如，<code>123</code> 是整数 <code>12345</code> 的前缀，而 <code>234</code><strong> 不是 </strong>。</p>

<p>设若整数 <code>c</code> 是整数 <code>a</code> 和 <code>b</code> 的<strong> 公共前缀 </strong>，那么 <code>c</code> 需要同时是 <code>a</code> 和 <code>b</code> 的前缀。例如，<code>5655359</code> 和 <code>56554</code> 有公共前缀 <code>565</code>&nbsp;和 <code>5655</code>，而 <code>1223</code> 和 <code>43456</code><strong> 没有 </strong>公共前缀。</p>

<p>你需要找出属于 <code>arr1</code> 的整数 <code>x</code> 和属于 <code>arr2</code> 的整数 <code>y</code> 组成的所有数对 <code>(x, y)</code> 之中最长的公共前缀的长度。</p>

<p>返回所有数对之中最长公共前缀的长度。如果它们之间不存在公共前缀，则返回 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,10,100], arr2 = [1000]
<strong>输出：</strong>3
<strong>解释：</strong>存在 3 个数对 (arr1[i], arr2[j]) ：
- (1, 1000) 的最长公共前缀是 1 。
- (10, 1000) 的最长公共前缀是 10 。
- (100, 1000) 的最长公共前缀是 100 。
最长的公共前缀是 100 ，长度为 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,2,3], arr2 = [4,4,4]
<strong>输出：</strong>0
<strong>解释：</strong>任何数对 (arr1[i], arr2[j]) 之中都不存在公共前缀，因此返回 0 。
请注意，同一个数组内元素之间的公共前缀不在考虑范围内。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr1[i], arr2[i] &lt;= 10<sup>8</sup></code></li>
</ul>


    
## 解题方法：哈希表

两个数的所有前缀可以相互匹配，所有就把一个数组中每个数的所有前缀放到一个set哈希表中不就好了(不断插入哈希表之后除以10并向下取整)。之后遍历另一个数组，看这个数组中每个数的每个前缀是否在哈希表中出现过，出现则匹配成功。

+ 时间复杂度$O((len(arr1)+len(arr2))\times \log arr[i])$
+ 空间复杂度$O(len(arr1)\log arr1[i])$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-21 22:32:19
 */
class Solution {
private:
    int len(int t) {
        int ans = 0;
        while (t) {
            ans++;
            t /= 10;
        }
        return ans;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> can;
        for (int t : arr1) {
            while (t) {
                can.insert(t);
                t /= 10;
            }
        }
        
        int ans = 0;
        for (int t : arr2) {
            while (t) {
                if (can.count(t)) {
                    ans = max(ans, len(t));
                    break;
                }
                t /= 10;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161294062)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/21/LeetCode%203043.%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%89%8D%E7%BC%80%E7%9A%84%E9%95%BF%E5%BA%A6/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
