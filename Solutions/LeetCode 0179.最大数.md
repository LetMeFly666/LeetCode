---
title: 179.最大数
date: 2022-08-08 09:05:30
tags: [题解, LeetCode, 中等, 贪心, 字符串, 排序, cmp]
categories: [题解, LeetCode]
---

# 【LetMeFly】179.最大数

力扣题目链接：[https://leetcode.cn/problems/largest-number/](https://leetcode.cn/problems/largest-number/)

<p>给定一组非负整数 <code>nums</code>，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。</p>

<p><strong>注意：</strong>输出结果可能非常大，所以你需要返回一个字符串而不是整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入<code>：</code></strong><code>nums = [10,2]</code>
<strong>输出：</strong><code>"210"</code></pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入<code>：</code></strong><code>nums = [3,30,34,5,9]</code>
<strong>输出：</strong><code>"9534330"</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：自定义排序方式

其实不证明的话，这题非常简单。

对于两个数而言，哪个应该放在前面，哪个应该放在后面呢？

我们只需要比较一下哪个放前面结果比较大即可。

也就是说，对于两个数```a```和```b```，如果```ab > ba```，那么就把```a```放在```b```前。反之将```b```置前。

**注意：**如果所有元素全部为$0$，记得不要返回```000...0```，只能返回一个```0```。

+ 时间复杂度$O(L\times n\log n)$，其中$n$是数组中元素的个数，$L$是数字的平均位数
+ 空间复杂度$O(L\times\log n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    static bool cmp(const int& a, const int& b) {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), cmp);
        for (int& t : nums) {
            ans += to_string(t);
        }
        if (ans[0] == '0') {  // 不能是00000
            return "0";
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/08/LeetCode%200179.%E6%9C%80%E5%A4%A7%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126221099](https://letmefly.blog.csdn.net/article/details/126221099)
