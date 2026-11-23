---
title: 1352.最后 K 个数的乘积：前缀积（注意0的情况）
date: 2026-11-23 18:53:01
tags: [题解, LeetCode, 中等, 设计, 数组, 数学, 数据流, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】1352.最后 K 个数的乘积：前缀积（注意0的情况）

力扣题目链接：[https://leetcode.cn/problems/product-of-the-last-k-numbers/](https://leetcode.cn/problems/product-of-the-last-k-numbers/)

<p>设计一个算法，该算法接受一个整数流并检索该流中最后 <code>k</code> 个整数的乘积。</p>

<p>实现&nbsp;<code>ProductOfNumbers</code>&nbsp;类：</p>

<ul>
	<li><code>ProductOfNumbers()</code>&nbsp;用一个空的流初始化对象。</li>
	<li><code>void add(int num)</code>&nbsp;将数字&nbsp;<code>num</code>&nbsp;添加到当前数字列表的最后面。</li>
	<li><code>int getProduct(int k)</code>&nbsp;返回当前数字列表中，最后&nbsp;<code>k</code>&nbsp;个数字的乘积。你可以假设当前列表中始终 <strong>至少</strong> 包含 <code>k</code> 个数字。</li>
</ul>

<p>题目数据保证：任何时候，任一连续数字序列的乘积都在 32 位整数范围内，不会溢出。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

<strong>输出：</strong>
[null,null,null,null,null,null,20,40,0,null,32]

<strong>解释：</strong>
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
productOfNumbers.getProduct(3); // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num&nbsp;&lt;=&nbsp;100</code></li>
	<li><code>1 &lt;= k &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>add</code> 和 <code>getProduct</code>&nbsp;最多被调用&nbsp;<code>4 * 10<sup>4</sup></code> 次。</li>
	<li>在任何时间点流的乘积都在 32 位整数范围内。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>您能否 <strong>同时</strong> 将 <code>GetProduct</code> 和 <code>Add</code> 的实现改为 <code>O(1)</code> 时间复杂度，而不是 <code>O(k)</code> 时间复杂度？</p>


    
## 解题方法：前缀积

如果输入流中没有$0$，那么可以类似前缀和的思想，我们令$stream[i]$代表 输入的前$i$个数的乘积，则最近$k$个数的乘积为$\frac{stream[i]}{stream[i-k]}$。

但现在问题是给定输入中存在$0$，直接这么相乘可能会让乘积结果变成全$0$，且$\frac{0}{0}$无意义。所以对于$0$的情况我们需要特殊处理：

> 使用一个变量记录上次$0$距离现在的距离，如果给定$k$小于这个距离则说明乘积序列中没有$0$，否则直接返回$0$。
>
> 遇到$0$则重新开始前缀积的计算。

+ 时间复杂度：单次操作$O(1)$
+ 空间复杂度：$O(add次数)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-11-23 18:35:57
 */
class ProductOfNumbers {
private:
    int lastZero = 100000;
    vector<long long> stream;
public:
    ProductOfNumbers() {
        stream.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            lastZero = 1;
            stream.push_back(1);
        } else {
            lastZero++;
            stream.push_back(stream.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= lastZero) {
            return 0;
        }
        return static_cast<int>(stream.back() / stream[stream.size() - k - 1]);
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/171253307)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/11/23/LeetCode%201352.%E6%9C%80%E5%90%8EK%E4%B8%AA%E6%95%B0%E7%9A%84%E4%B9%98%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
