---
title: 368.最大整除子集
date: 2022-10-08 15:19:41
tags: [题解, LeetCode, 中等, 数组, 数学, 动态规划, DP, 排序]
---

# 【LetMeFly】368.最大整除子集

力扣题目链接：[https://leetcode.cn/problems/largest-divisible-subset/](https://leetcode.cn/problems/largest-divisible-subset/)

给你一个由 <strong>无重复</strong> 正整数组成的集合 <code>nums</code> ，请你找出并返回其中最大的整除子集 <code>answer</code> ，子集中每一元素对 <code>(answer[i], answer[j])</code> 都应当满足：
<ul>
	<li><code>answer[i] % answer[j] == 0</code> ，或</li>
	<li><code>answer[j] % answer[i] == 0</code></li>
</ul>

<p>如果存在多个有效解子集，返回其中任何一个均可。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>[1,3] 也会被视为正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4,8]
<strong>输出：</strong>[1,2,4,8]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>1 <= nums[i] <= 2 * 10<sup>9</sup></code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>


    
## 方法一：动态规划 + traceback

上来先给nums从小到大排个序，这没什么好说的。

排完序后：

### step1. 动态规划求得以nums[i]结尾的最长“递增倍数串”的长度

数组中各个元素各不相同，想要“互为倍数”，就要“大的 是 小的 的 整数倍”

假如一个“互为倍数”数组中已经有了两个元素```5, 15```，那么想要往这个数组中再添加一个元素的话，新的元素就要是```15```的整数倍。这是因为我们“上来就给nums从小到大排了个序”。

如果一个数是```15```的整数倍，那么它一定是```5```的整数倍。

这不，动态规划的转移方程就来了？

$dp[i] = \max\{dp[i], dp[j] + 1\}$，其中$j < i \wedge nums[i] \% nums[j] = 0$

说人话就是，怎么求$dp[i]$呢？在所有的小于$i$的下标中，如果某个数能被$nums[i]$整除（假设为第$j$个数），那么$dp[i] = \max(dp[i],dp[j]+1)$

因为$nums[i]$是$nums[j]$的倍数的话，$num[i]$可以添加到以$nums[j]$结尾的“递增互为倍数集合”中。

这样，两层循环就能求出$dp$数组的值，其中$dp[i]$表示以$nums[i]$结尾的“递增互为倍数集合”的最大大小。

```cpp
vector<int> dp(n, 1);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}
```

### step2. 根据“递增倍数串”后面的元素倒推出前面的元素

题目问的不是“互为倍数集合的最大元素个数”，而是要你把这个集合给出来。

但是这就不难了。我们在step1中动态规划求“最大大小”时，可以额外记录一下：

1. 最大大小是多少
2. 最大的集合中，最大的数有多大

只需要做如下更改：

```cpp
vector<int> dp(n, 1);
int maxLength = 0;
int maxVal = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    if (dp[i] > maxLength) {
        maxLength = dp[i];
        maxVal = nums[i];
    }
}
```

这样，我们就知道了“答案集合的最大数”、“答案集合的大小”

假如答案集合是```[5, 15, 30]```，那么我们知道的是：

1. 答案中的最大数是```30```
2. 答案集合的大小是```3```

同时我们也知道了整个dp数组，其中```5```对应的```dp```值是```1```，```15```对应的```dp```值是```2```，```30```对应的```dp```值是```3```

因此我们可以从后往前遍历一遍数组（从大到小）

如果遇到某个数对应的dp值恰好等于“maxLength”，并且这个数能被“maxVal”整除，那么就说明这个数是集合中的一个数

更新```maxLength```为```maxLength - 1```，更新```maxVal```为```这个数```。

```cpp
vector<int> ans(maxLength);
for (int i = n - 1; i >= 0; i--) {
    if (maxVal % nums[i] == 0 && dp[i] == maxLength) {
        ans[--maxLength] = nums[i];
        maxVal = nums[i];
        if (!maxLength)
            break;
    }
}
```

同样以答案集合```[5, 15, 30]```为例：

1. ```maxLength = 3, maxVal = 30```，找到```30```时，发现```30```对应的```dp```值恰好为```3```，且```30```能被```30```整除。因此我们得到了答案集合中的```30```，并将```maxLength```更新为```2```，将```maxVal```更新为```30```
2. ```maxLength = 2, maxVal = 30```，找到```15```时，发现```15```对应的```dp```值恰好为```2```，且```30```能被```15```整除。因此我们得到了答案集合中的```15```，并将```maxLength```更新为```1```，将```maxVal```更新为```15```
3. ```maxLength = 1, maxVal = 15```，找到```5```时，发现```15```对应的```dp```值恰好为```1```，且```15```能被```5```整除。因此我们得到了答案集合中的```5```，并将```maxLength```更新为```.```，将```maxVal```更新为```5```

寻找结束。

+ 时间复杂度$O(n^2)$，其中$n$是$nums$的大小
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int maxLength = 0;
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                maxVal = nums[i];
            }
        }
        vector<int> ans(maxLength);
        for (int i = n - 1; i >= 0; i--) {
            if (maxVal % nums[i] == 0 && dp[i] == maxLength) {
                ans[--maxLength] = nums[i];
                maxVal = nums[i];
                if (!maxLength)
                    break;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/08/LeetCode%200368.%E6%9C%80%E5%A4%A7%E6%95%B4%E9%99%A4%E5%AD%90%E9%9B%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127210616](https://letmefly.blog.csdn.net/article/details/127210616)
