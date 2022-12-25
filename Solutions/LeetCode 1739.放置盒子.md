---
title: 1739.放置盒子
date: 2022-12-25 17:23:55
tags: [题解, LeetCode, 困难, 贪心, 数学, 二分查找, 思维]
---

# 【LetMeFly】1739.放置盒子

力扣题目链接：[https://leetcode.cn/problems/building-boxes/](https://leetcode.cn/problems/building-boxes/)

<p>有一个立方体房间，其长度、宽度和高度都等于 <code>n</code> 个单位。请你在房间里放置 <code>n</code> 个盒子，每个盒子都是一个单位边长的立方体。放置规则如下：</p>

<ul>
	<li>你可以把盒子放在地板上的任何地方。</li>
	<li>如果盒子 <code>x</code> 需要放置在盒子 <code>y</code> 的顶部，那么盒子 <code>y</code> 竖直的四个侧面都 <strong>必须</strong> 与另一个盒子或墙相邻。</li>
</ul>

<p>给你一个整数 <code>n</code> ，返回接触地面的盒子的 <strong>最少</strong> 可能数量<em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/24/3-boxes.png" style="width: 135px; height: 143px;" /></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>3
<strong>解释：</strong>上图是 3 个盒子的摆放位置。
这些盒子放在房间的一角，对应左侧位置。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/24/4-boxes.png" style="width: 135px; height: 179px;" /></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>3
<strong>解释：</strong>上图是 3 个盒子的摆放位置。
这些盒子放在房间的一角，对应左侧位置。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/01/24/10-boxes.png" style="width: 271px; height: 257px;" /></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>6
<strong>解释：</strong>上图是 10 个盒子的摆放位置。
这些盒子放在房间的一角，对应后方位置。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：思维

具体的放置方法可以参考[灵神@灵茶山艾府](https://leetcode.cn/u/endlesscheng/)的[动态图](https://leetcode.cn/problems/building-boxes/solutions/2031813/mei-xiang-ming-bai-yi-ge-dong-hua-miao-d-8vbe/)

首先，就是在放置总量$total$未达到$n$时，不断地将某层放满。（第一层1个，第二层3个，第三层6个，第四层10个）

这时候，盒子总量已经等于或者超过$n$了。我们将盒子状态返回“最后一层”放完之前的状态，然后，一个一个地往最下面一层放盒子。

第$i$次往最下面一层放盒子，盒子总量能增加$i$个。

接着枚举直到总量大于等于$n$即可。

+ 时间复杂度：不好计算，[官解](https://leetcode.cn/problems/building-boxes/solutions/2030450/fang-zhi-he-zi-by-leetcode-solution-7ah2/)说：$^3\sqrt{n}$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    int minimumBoxes(ll n) {
        ll bottom = 1, nextAdd = 2;
        ll total = 1;
        ll lastBottom, lastTotal;
        while (total <= n) {  // 最下面一层“放满”，上面也放满
            lastBottom = bottom, lastTotal = total;
            bottom += nextAdd, nextAdd++;
            total += bottom;
        }
        total = lastTotal, bottom = lastBottom;
        ll ans = bottom;
        for (int i = 1; total < n; i++) {
            ans++;
            total += i;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/12/25/LeetCode%201739.%E6%94%BE%E7%BD%AE%E7%9B%92%E5%AD%90/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128436934](https://letmefly.blog.csdn.net/article/details/128436934)
