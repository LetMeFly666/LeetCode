---
title: 2078.两栋颜色不同且距离最远的房子：一次遍历(脑筋急转弯)
date: 2026-04-20 21:52:17
tags: [题解, LeetCode, 简单, 贪心, 数组, 遍历, 脑筋急转弯]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/10/31/eg1.png
---

# 【LetMeFly】2078.两栋颜色不同且距离最远的房子：一次遍历(脑筋急转弯)

力扣题目链接：[https://leetcode.cn/problems/two-furthest-houses-with-different-colors/](https://leetcode.cn/problems/two-furthest-houses-with-different-colors/)

<p>街上有 <code>n</code> 栋房子整齐地排成一列，每栋房子都粉刷上了漂亮的颜色。给你一个下标从 <strong>0</strong> 开始且长度为 <code>n</code> 的整数数组 <code>colors</code> ，其中 <code>colors[i]</code> 表示第&nbsp; <code>i</code> 栋房子的颜色。</p>

<p>返回 <strong>两栋</strong> 颜色 <strong>不同</strong> 房子之间的 <strong>最大</strong> 距离。</p>

<p>第 <code>i</code> 栋房子和第 <code>j</code> 栋房子之间的距离是 <code>abs(i - j)</code> ，其中 <code>abs(x)</code> 是 <code>x</code> 的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/31/eg1.png" style="width: 610px; height: 84px;" /></p>

<pre>
<strong>输入：</strong>colors = [<strong><em>1</em></strong>,1,1,<em><strong>6</strong></em>,1,1,1]
<strong>输出：</strong>3
<strong>解释：</strong>上图中，颜色 1 标识成蓝色，颜色 6 标识成红色。
两栋颜色不同且距离最远的房子是房子 0 和房子 3 。
房子 0 的颜色是颜色 1 ，房子 3 的颜色是颜色 6 。两栋房子之间的距离是 abs(0 - 3) = 3 。
注意，房子 3 和房子 6 也可以产生最佳答案。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/31/eg2.png" style="width: 426px; height: 84px;" /></p>

<pre>
<strong>输入：</strong>colors = [<em><strong>1</strong></em>,8,3,8,<em><strong>3</strong></em>]
<strong>输出：</strong>4
<strong>解释：</strong>上图中，颜色 1 标识成蓝色，颜色 8 标识成黄色，颜色 3 标识成绿色。
两栋颜色不同且距离最远的房子是房子 0 和房子 4 。
房子 0 的颜色是颜色 1 ，房子 4 的颜色是颜色 3 。两栋房子之间的距离是 abs(0 - 4) = 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>colors = [<em><strong>0</strong></em>,<em><strong>1</strong></em>]
<strong>输出：</strong>1
<strong>解释：</strong>两栋颜色不同且距离最远的房子是房子 0 和房子 1 。
房子 0 的颜色是颜色 0 ，房子 1 的颜色是颜色 1 。两栋房子之间的距离是 abs(0 - 1) = 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n ==&nbsp;colors.length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= colors[i] &lt;= 100</code></li>
	<li>生成的测试数据满足 <strong>至少 </strong>存在 2 栋颜色不同的房子</li>
</ul>


    
## 解题方法：一次遍历

距离一个房子最远的异色房子，这个最远怎么找？当然是想优先寻找最左或最有的房子。
诶，那如果第一个房子和最后一个房子颜色不同，是不是就可以直接返回$n-1$了；
诶，那如果第一个房子和最后一个房子颜色不同，是不是就可以直接返回$n-1$了；

如果第一个房子和最后一个房子颜色相同，那么假如一个房子和它们颜色不同，这个房子的最远异色距离要么是`与第一个房子的距离`要么是`与最后一个房子的距离`。所以我们遍历一遍房子，更新异色房子的两个最远距离的最大值就好了。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-20 21:51:36
 */
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if (colors[0] != colors.back()) {
            return n - 1;
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (colors[i] != colors[0]) {
                ans = max(ans, max(i, n - i - 1));
            }
        }
        return ans;
    }
};

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160346906)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/20/LeetCode%202078.%E4%B8%A4%E6%A0%8B%E9%A2%9C%E8%89%B2%E4%B8%8D%E5%90%8C%E4%B8%94%E8%B7%9D%E7%A6%BB%E6%9C%80%E8%BF%9C%E7%9A%84%E6%88%BF%E5%AD%90/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
