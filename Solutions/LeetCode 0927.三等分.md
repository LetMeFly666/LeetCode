---
title: 927.三等分
date: 2022-10-06 22:36:33
tags: [题解, LeetCode, 困难, 数组, 数学]
---

# 【LetMeFly】927.三等分

力扣题目链接：[https://leetcode.cn/problems/three-equal-parts/](https://leetcode.cn/problems/three-equal-parts/)

<p>给定一个由 <code>0</code> 和 <code>1</code> 组成的数组<meta charset="UTF-8" />&nbsp;<code>arr</code>&nbsp;，将数组分成 &nbsp;<strong>3&nbsp;个非空的部分</strong> ，使得所有这些部分表示相同的二进制值。</p>

<p>如果可以做到，请返回<strong>任何</strong>&nbsp;<code>[i, j]</code>，其中 <code>i+1 &lt; j</code>，这样一来：</p>

<ul>
	<li><code>arr[0], arr[1], ..., arr[i]</code>&nbsp;为第一部分；</li>
	<li><code>arr[i + 1], arr[i + 2], ..., arr[j - 1]</code>&nbsp;为第二部分；</li>
	<li><code>arr[j], arr[j + 1], ..., arr[arr.length - 1]</code>&nbsp;为第三部分。</li>
	<li>这三个部分所表示的二进制值相等。</li>
</ul>

<p>如果无法做到，就返回&nbsp;<code>[-1, -1]</code>。</p>

<p>注意，在考虑每个部分所表示的二进制时，应当将其看作一个整体。例如，<code>[1,1,0]</code>&nbsp;表示十进制中的&nbsp;<code>6</code>，而不会是&nbsp;<code>3</code>。此外，前导零也是<strong>被允许</strong>的，所以&nbsp;<code>[0,1,1]</code> 和&nbsp;<code>[1,1]</code>&nbsp;表示相同的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,0,1,0,1]
<strong>输出：</strong>[0,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,0,1,1]
<strong>输出：</strong>[-1,-1]</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入：</strong>arr = [1,1,0,0,1]
<strong>输出：</strong>[0,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>3 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>arr[i]</code>&nbsp;是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
</ul>


    
## 方法一：模拟

这题主要需要明白的是：

+ 每个数字后面的0的个数由第三个数字决定

首先统计1的个数，若不能被3整除，则返回false。

如果没有1，直接返回```{0, 2}```

到此为止，我们直到每个数中，有多少个1，以及最后一个1后面又多少个0

这样就可以从前往后遍历，首先关注1，数够足够的1，就开始数0。如果0数量也数够了，那么就确定了第一个数的范围。

同理，以同样的方法，能统计出第二个数字的范围。

之和，再判断三个数是否等价（仅仅1的个数相同不能确定等价。要等价还需要从第一个1开始，到这个数结束为止，全部一一对应地相等）

+ 时间复杂度$O(n)$，其中$n$是数组长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    /*
        寻找以begin开始，拥有numof1个1，结尾有end0个0  的二进制串的最后一位的下标
        若找不到，则返回-1
    */
    int findTheEndOfOneNum(int begin, int numof1, int end0, vector<int>& arr) {
        int cnt1 = 0;
        for (; begin < arr.size(); begin++) {
            if (arr[begin])
                cnt1++;
            if (cnt1 == numof1)
                break;
        }
        // 一定能找到足够数量的1，因为1是计算过后平分的
        if (!end0)
            return begin;
        int cnt0 = 0;
        while (++begin < arr.size()) {
            if (arr[begin]) {
                return -1;
            }
            cnt0++;
            if (cnt0 == end0)
                return begin;
        }
        return -1;  // FakeReturn
    }

    /* 判断1总量相同、后缀0相同 的前提下， 两串数字是否等价 */
    bool same(int firstNumBegin, int firstNumEnd, int secondNumBegin, int secondNumEnd, vector<int>& arr) {
        function<int(int)> findFirst1 = [&](int beginLoc) {
            while (!arr[beginLoc])
                beginLoc++;
            return beginLoc;
        };
        int firstNumFirst1 = findFirst1(firstNumBegin);
        int secondNumFirst1 = findFirst1(secondNumBegin);
        if (secondNumEnd - secondNumFirst1 != firstNumEnd - firstNumFirst1) {
            return false;
        }
        while (firstNumFirst1 <= firstNumEnd) {
            if (arr[firstNumFirst1] != arr[secondNumFirst1])
                return false;
            firstNumFirst1++;
            secondNumFirst1++;
        }
        return true;
    }
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int cnt1 = 0;
        for (int& t : arr) {
            cnt1 += t;
        }
        if (cnt1 % 3)
            return {-1, -1};
        if (!cnt1)  // 全0
            return {0, 2};
        int per1 = cnt1 / 3;  // 每个二进制下有多少个1
        int end0 = 0;  // 每个二进制下最后有几个0取决于第三个数
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i])
                break;
            else
                end0++;
        }
        int firstNumEnd = findTheEndOfOneNum(0, per1, end0, arr);
        if (firstNumEnd == -1)
            return {-1, -1};
        int secondNumEnd = findTheEndOfOneNum(firstNumEnd + 1, per1, end0, arr);
        if (secondNumEnd == -1)
            return {-1, -1};
        if (same(0, firstNumEnd, firstNumEnd + 1, secondNumEnd, arr) && same(0, firstNumEnd, secondNumEnd + 1, arr.size() - 1, arr))
            return {firstNumEnd, secondNumEnd + 1};
        else
            return {-1, -1};
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/06/LeetCode%200927.%E4%B8%89%E7%AD%89%E5%88%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127189062](https://letmefly.blog.csdn.net/article/details/127189062)
