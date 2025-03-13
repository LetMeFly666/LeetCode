---
title: 825.适龄的朋友
date: 2024-11-17 18:11:16
tags: [题解, LeetCode, 中等, 数组, 双指针, 二分查找, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】825.适龄的朋友：双指针(排序nlog n) 或 桶排序(n + C^2)

力扣题目链接：[https://leetcode.cn/problems/friends-of-appropriate-ages/](https://leetcode.cn/problems/friends-of-appropriate-ages/)

<p>在社交媒体网站上有 <code>n</code> 个用户。给你一个整数数组 <code>ages</code> ，其中 <code>ages[i]</code> 是第 <code>i</code> 个用户的年龄。</p>

<p>如果下述任意一个条件为真，那么用户 <code>x</code> 将不会向用户 <code>y</code>（<code>x != y</code>）发送好友请求：</p>

<ul>
	<li><code>ages[y] &lt;= 0.5 * ages[x] + 7</code></li>
	<li><code>ages[y] &gt; ages[x]</code></li>
	<li><code>ages[y] &gt; 100 &amp;&amp; ages[x] &lt; 100</code></li>
</ul>

<p>否则，<code>x</code> 将会向 <code>y</code> 发送一条好友请求。</p>

<p>注意，如果 <code>x</code> 向 <code>y</code> 发送一条好友请求，<code>y</code> 不必也向 <code>x</code> 发送一条好友请求。另外，用户不会向自己发送好友请求。</p>

<p>返回在该社交媒体网站上产生的好友请求总数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>ages = [16,16]
<strong>输出：</strong>2
<strong>解释：</strong>2 人互发好友请求。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>ages = [16,17,18]
<strong>输出：</strong>2
<strong>解释：</strong>产生的好友请求为 17 -&gt; 16 ，18 -&gt; 17 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>ages = [20,30,100,110,120]
<strong>输出：</strong>3
<strong>解释：</strong>产生的好友请求为 110 -&gt; 100 ，120 -&gt; 110 ，120 -&gt; 100 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == ages.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= ages[i] &lt;= 120</code></li>
</ul>


    
## 方法一：双指针

如果满足第三条`ages[y] > 100 && ages[x] < 100`，那么一定满足第二条`ages[y] > ages[x]`，因此第三条可以忽略（只要满足第二条，不需要看是否满足第三条就一定不会受到邀请）。

由第一条和第二条可知，当`y`满足`0.5x+7 < y <= x`时`y`才会收到来自`x`的邀请。由`0.5x+7 < x`可得只有`>= 15`的`x`才会有可能发送邀请。

对于邀请发送者`x`，`y`的最小值需要满足`y > 0.5x+7`，`y`的最大值需要满足`y <= x`。

假设`y_l`是第一个满足`> 0.5x+7`的`y`下标，`y_r`是最后一个满足`<= x`的`y`下标，那么对于区间`[y_l, y_r]`，只有`x`自身不会收到`x`的邀请，其他用户都会收到`x`的邀请。因此`x`的邀请发送数量为`区间长度 - 1 = y_r - y_l`。

不难发现随着`x`的非递减，`y`区间的左右端点`y_l`和`y_r`也是非递减的，因此就可以使用双指针来实现每个元素只被遍历数次。

+ 时间复杂度$O(n\log n)$：排序时间复杂度$O(n\log n)$，双指针时间复杂度$O(n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-11-17 17:39:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-17 18:11:18
 */
/*
对于x：x要加：
0.5x+7 < y <= x
x + 7 < 2y
也就是说
0.5x+7 < x 可得 x>14 才能有朋友
*/
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(), ages.end());
        int y_l = 0;
        while (y_l < ages.size() && ages[y_l] <= 14) {
            y_l++;
        }
        for (int y_r = y_l, x = y_l; x < ages.size(); x++) {
            while (ages[y_l] * 2 <= ages[x] + 14) {
                y_l++;
            }
            while (y_r + 1 < ages.size() && ages[y_r + 1] <= ages[x]) {
                y_r++;
            }
            ans += y_r - y_l;
        }
        return ans;
    }
};
```

## 方法二：桶排序

有没有一种办法避免方法一的时间瓶颈——排序呢？当然有。

不难发现每个人的年龄范围是`1`到`120`，因此我们只需要统计一下每个年龄段分别有多少人，再枚举`x`和`y`的年龄判定是否符合第一第二两个条件就好了。

+ 时间复杂度$O(n + C^2)$：其中$C=120$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2021-12-27 09:00:07
 * @LastEditors: LetMeFly
 * @LastEditTime: 2021-12-27 09:07:32
 */
int a[121];
class Solution {
public:
    // age[y] * 2 <= age[x] + 14
    int numFriendRequests(vector<int>& ages) {
        for (int i = 0; i < 121; i++)
            a[i] = 0;
        for (int& t : ages)
            a[t]++;
        int ans = 0;
        for (int y = 1; y <= 120; y++) {
            for (int x = y; x <= 120; x++) {
                if (y * 2 <= x + 14 || (y > 100 && x < 100))
                    continue;
                ans += x == y ? a[x] * (a[x] - 1) : a[x] * a[y];
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/17/LeetCode%200825.%E9%80%82%E9%BE%84%E7%9A%84%E6%9C%8B%E5%8F%8B/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143836115](https://letmefly.blog.csdn.net/article/details/143836115)
