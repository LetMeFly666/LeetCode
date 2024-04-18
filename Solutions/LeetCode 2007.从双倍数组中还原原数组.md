---
title: 2007.从双倍数组中还原原数组
date: 2024-04-18 13:18:32
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, 哈希, map, 排序]
---

# 【LetMeFly】2007.从双倍数组中还原原数组：哈希表——从nlogn到n

力扣题目链接：[https://leetcode.cn/problems/find-original-array-from-doubled-array/](https://leetcode.cn/problems/find-original-array-from-doubled-array/)

<p>一个整数数组&nbsp;<code>original</code>&nbsp;可以转变成一个 <strong>双倍</strong>&nbsp;数组&nbsp;<code>changed</code>&nbsp;，转变方式为将 <code>original</code>&nbsp;中每个元素 <strong>值乘以 2 </strong>加入数组中，然后将所有元素 <strong>随机打乱</strong>&nbsp;。</p>

<p>给你一个数组&nbsp;<code>changed</code>&nbsp;，如果&nbsp;<code>change</code>&nbsp;是&nbsp;<strong>双倍</strong>&nbsp;数组，那么请你返回&nbsp;<code>original</code>数组，否则请返回空数组。<code>original</code>&nbsp;的元素可以以&nbsp;<strong>任意</strong>&nbsp;顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>changed = [1,3,4,2,6,8]
<b>输出：</b>[1,3,4]
<b>解释：</b>一个可能的 original 数组为 [1,3,4] :
- 将 1 乘以 2 ，得到 1 * 2 = 2 。
- 将 3 乘以 2 ，得到 3 * 2 = 6 。
- 将 4 乘以 2 ，得到 4 * 2 = 8 。
其他可能的原数组方案为 [4,3,1] 或者 [3,1,4] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>changed = [6,3,0,1]
<b>输出：</b>[]
<b>解释：</b>changed 不是一个双倍数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>changed = [1]
<b>输出：</b>[]
<b>解释：</b>changed 不是一个双倍数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= changed.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= changed[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：哈希表 + 排序

使用哈希表记录每个元素出现（剩余）的次数。对原始数组排个序，接着遍历原始数组：

+ 如果这个元素已经被“消耗”了，则跳过；
+ 否则，“移除”这个元素。这个元素的二倍必须在哈希表中：
   + 若在，则找到“一对”，记入答案数组中，并将二倍元素移除；
   + 否则，无法还原，返回空数组。

为什么要排序？因为排序后遍历结果保证是从小到大，一个元素要么已经被“消耗”（则其为二倍元素），要么（其为一倍元素）必须消耗一个二倍元素。

+ 时间复杂度$O(n\log n)$，其中$n=len(changed)$。**时间复杂度的瓶颈在于排序**
+ 空间复杂度$O(n)$，或者说$O(C)$，其中$C=range(changed)=10^5$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> a(200000 + 1);  // 手动unordered_map  // 2倍防越界
        for (int t : changed) {
            a[t]++;
        }
        vector<int> ans;
        for (int t : changed) {
            if (!a[t]) {
                continue;
            }
            a[t]--;
            if (!a[t * 2]) {
                return {};
            }
            a[t * 2]--;
            ans.push_back(t);
        }
        return ans;
    }
};
```

为什么使用数组模拟哈希表？因为内置的```unordered_map```没试，```unordered_multiset```[非常慢](https://github.com/LetMeFly666/LeetCode/blob/master/Codes/2007-find-original-array-from-doubled-array.cpp#L58)会超时。

## 方法二：哈希表 + 反推

方法一时间复杂度的瓶颈是排序，排序是为了在遍历过程中判断一个元素是“一倍元素”还是“二倍元素”。

有没有办法不排序呢？当然有，那就是遍历过程中，“遇到1/2元素则先跳过”：

> 遍历到元素$t$，如果$\frac{t}{2}$还存在，就先跳过$t$，遍历到$\frac{t}{2}$时再处理$t$。

这样就需要一个计数器记录还剩下多少元素（防止两个$t$和一个$\frac{t}{2}$的情况），以及特判$0$的情况（因为$\frac{0}{2}=0$不能跳过）。

完了吗？没完，还需要加个```while循环```：

> 给定一组样例```[2,4,2,1]```，如果按照上述思路则会：跳过$2$、跳过$4$、跳过$2$，处理$1$，最终剩下一个$2$和$4$，本应是一对确误判有所剩余。
>
> 这是因为对于$4$本来应该在遍历到$2$时处理，结果遍历到$2$时一看有$1$跳过了。
>
> 因此遇到$\frac{t}{2}$不存在的$t$时，应当在$t$有剩余时，不断“反推”，令$t=2t$并继续“抵消”，直到$t$无剩余。
>
> 这样对于```[2,4,2,1]```：
> 
> > 处理到$1$时$t=1$，$\frac{t}{2}=0.5$不存在，因此抵消$t$和$2t$（配对成功一个$1$和$2$）
> >
> > 令$t=2t=2$，抵消$2$和$4$（配对成功一个$2$和$4$）
> >
> > 令$t = 2t = 4$，发现$4$已经不存在了，结束
>
> 最终得到原始数组```[1, 2]```

完了吗？没完，单单$2t$不存在了还不能结束循环，要判断$4t$是否存在：

> 给定样例```[4,8,2,1]```，处理到$4$、$8$、$2$时都会跳过，而处理到$1$时：
>
> > $t=1$发现$1$和$2$
> >
> > $t=2t=2$发现$2$不存在了，循环结束
>
> 则会剩下一个本应是一对的$4$和$8$。
>
> 因此，在```while循环```中，不能单单地令$t=2t$做这一步的反推。
>
> 当$2t$已经不存在时，应该令$t=4t$。
> 
> 若$4t$也不存在，再结束```while循环```。

至此，算法达成。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$，或者说$O(C)$，其中$C=range(changed)=10^5$

### AC代码

#### C++

降低了时间复杂度，代价是代码变得很长且很容易有没考虑周全的地方。

```cpp
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> a(400001);
        for (int t : changed) {
            a[t]++;
        }
        int remain = changed.size();
        vector<int> ans;
        if (a[0] % 2) {
            return {};
        }
        remain -= a[0];
        ans.resize(a[0] / 2);
        a[0] = 0;
        for (int t : changed) {
            if (t % 2 == 0 && a[t / 2]) {
                continue;
            }
            while (a[t]) {
                int thisCnt = a[t];
                a[t] = 0;
                remain -= thisCnt;
                if (a[t * 2] < thisCnt) {
                    return {};
                }
                a[t * 2] -= thisCnt;
                remain -= thisCnt;
                ans.insert(ans.end(), thisCnt, t);
                if (a[t * 2]) {
                    t *= 2;
                }
                else {
                    t *= 4;
                }
            }
        }
        return remain ? vector<int>() : ans;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/18/LeetCode%202007.%E4%BB%8E%E5%8F%8C%E5%80%8D%E6%95%B0%E7%BB%84%E4%B8%AD%E8%BF%98%E5%8E%9F%E5%8E%9F%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137924488](https://letmefly.blog.csdn.net/article/details/137924488)
