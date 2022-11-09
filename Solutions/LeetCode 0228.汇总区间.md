---
title: 228.汇总区间
date: 2022-09-07 20:24:44
tags: [题解, LeetCode, 简单, 数组, 构造]
---

# 【LetMeFly】228.汇总区间

力扣题目链接：[https://leetcode.cn/problems/summary-ranges/](https://leetcode.cn/problems/summary-ranges/)

<p>给定一个 &nbsp;<strong>无重复元素</strong> 的&nbsp;<strong>有序</strong> 整数数组 <code>nums</code> 。</p>

<p>返回 <em><strong>恰好覆盖数组中所有数字</strong> 的 <strong>最小有序</strong> 区间范围列表&nbsp;</em>。也就是说，<code>nums</code> 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 <code>nums</code> 的数字 <code>x</code> 。</p>

<p>列表中的每个区间范围 <code>[a,b]</code> 应该按如下格式输出：</p>

<ul>
	<li><code>"a-&gt;b"</code> ，如果 <code>a != b</code></li>
	<li><code>"a"</code> ，如果 <code>a == b</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,2,4,5,7]
<strong>输出：</strong>["0-&gt;2","4-&gt;5","7"]
<strong>解释：</strong>区间范围是：
[0,2] --&gt; "0-&gt;2"
[4,5] --&gt; "4-&gt;5"
[7,7] --&gt; "7"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,2,3,4,6,8,9]
<strong>输出：</strong>["0","2-&gt;4","6","8-&gt;9"]
<strong>解释：</strong>区间范围是：
[0,0] --&gt; "0"
[2,4] --&gt; "2-&gt;4"
[6,6] --&gt; "6"
[8,9] --&gt; "8-&gt;9"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 20</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>nums</code> 中的所有值都 <strong>互不相同</strong></li>
	<li><code>nums</code> 按升序排列</li>
</ul>


    
## 方法一：模拟

记录上一个“区间”的开始元素（初始值是第一个元素），之后从第二个元素开始遍历

如果这个元素和上个元素“不连续”（不等于上个元素+1），那么就在答案中加入这个区间（开始元素到上一个元素）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    string num2str(int numBegin, int numEnd) {
        if (numBegin == numEnd) {
            return to_string(numBegin);
        }
        else {
            return to_string(numBegin) + "->" + to_string(numEnd);
        }
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        
        vector<string> ans;
        int lastBeginNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                ans.push_back(num2str(lastBeginNum, nums[i - 1]));
                lastBeginNum = nums[i];
            }
        }
        ans.push_back(num2str(lastBeginNum, nums.back()));
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/09/07/LeetCode%200228.%E6%B1%87%E6%80%BB%E5%8C%BA%E9%97%B4/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126753220](https://letmefly.blog.csdn.net/article/details/126753220)
