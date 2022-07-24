---
title: 1184.公交站间的距离
date: 2022-07-24 15:31:08
tags: [题解, LeetCode, 简单, 数组, 模拟, 一圈]
---

# 【LetMeFly】1184.公交站间的距离

力扣题目链接：[https://leetcode.cn/problems/distance-between-bus-stops/](https://leetcode.cn/problems/distance-between-bus-stops/)

<p>环形公交路线上有&nbsp;<code>n</code>&nbsp;个站，按次序从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;进行编号。我们已知每一对相邻公交站之间的距离，<code>distance[i]</code>&nbsp;表示编号为&nbsp;<code>i</code>&nbsp;的车站和编号为&nbsp;<code>(i + 1) % n</code>&nbsp;的车站之间的距离。</p>

<p>环线上的公交车都可以按顺时针和逆时针的方向行驶。</p>

<p>返回乘客从出发点&nbsp;<code>start</code>&nbsp;到目的地&nbsp;<code>destination</code>&nbsp;之间的最短距离。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<!-- <p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/08/untitled-diagram-1.jpg" style="height: 240px; width: 388px;"></p> -->
<p><img alt="" src="https://img-blog.csdnimg.cn/76569fe05e0b4ade8dd1cf057655f9fa.jpeg" style="height: 240px; width: 388px;"></p>

<pre><strong>输入：</strong>distance = [1,2,3,4], start = 0, destination = 1
<strong>输出：</strong>1
<strong>解释：</strong>公交站 0 和 1 之间的距离是 1 或 9，最小值是 1。</pre>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<!-- <p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/08/untitled-diagram-1-1.jpg" style="height: 240px; width: 388px;"></p> -->
<p><img alt="" src="https://img-blog.csdnimg.cn/c767a7f2d13c4837891b59bf80c968d0.jpeg" style="height: 240px; width: 388px;"></p>

<pre><strong>输入：</strong>distance = [1,2,3,4], start = 0, destination = 2
<strong>输出：</strong>3
<strong>解释：</strong>公交站 0 和 2 之间的距离是 3 或 7，最小值是 3。
</pre>

<p>&nbsp;</p>

<p><strong>示例 3：</strong></p>

<!-- <p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/08/untitled-diagram-1-2.jpg" style="height: 240px; width: 388px;"></p> -->
<p><img alt="" src="https://img-blog.csdnimg.cn/4cefdc64770d4512a0309eef028d0f3d.jpeg" style="height: 240px; width: 388px;"></p>

<pre><strong>输入：</strong>distance = [1,2,3,4], start = 0, destination = 3
<strong>输出：</strong>4
<strong>解释：</strong>公交站 0 和 3 之间的距离是 6 或 4，最小值是 4。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n&nbsp;&lt;= 10^4</code></li>
	<li><code>distance.length == n</code></li>
	<li><code>0 &lt;= start, destination &lt; n</code></li>
	<li><code>0 &lt;= distance[i] &lt;= 10^4</code></li>
</ul>


    
## 方法一：模拟

既然公交车是双向的，那么不如计算一下“从$start$和$destination$中编号较小的那个到编号较大的那个 的距离”$s1$

然后计算一下一圈的总距离$s$

那么乘坐另一方向的公交车的距离就是$s-s1$

返回$s1$和$s-s1$中较小的那个即可

+ 时间复杂度$O(n)$，其中$n$是公交车站的个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int s1 = 0;
        for (int i = start; i < destination; i++) {
            s1 += distance[i];
        }
        int s = 0;
        for (int i = 0; i < distance.size(); i++) {
            s += distance[i];
        }
        return min(s1, s - s1);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/24/LeetCode%201184.%E5%85%AC%E4%BA%A4%E7%AB%99%E9%97%B4%E7%9A%84%E8%B7%9D%E7%A6%BB/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125960214](https://letmefly.blog.csdn.net/article/details/125960214)
