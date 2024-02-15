---
title: 2342.数位和相等数对的最大和
date: 2023-11-18 11:19:07
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map, 排序, 堆（优先队列）]
---

# 【LetMeFly】2342.数位和相等数对的最大和：哈希表

力扣题目链接：[https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/](https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/)

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组中的元素都是 <strong>正</strong> 整数。请你选出两个下标 <code>i</code> 和 <code>j</code>（<code>i != j</code>），且 <code>nums[i]</code> 的数位和 与&nbsp; <code>nums[j]</code> 的数位和相等。</p>

<p>请你找出所有满足条件的下标 <code>i</code> 和 <code>j</code> ，找出并返回<em> </em><code>nums[i] + nums[j]</code><em> </em>可以得到的 <strong>最大值</strong> <em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [18,43,36,13,7]
<strong>输出：</strong>54
<strong>解释：</strong>满足条件的数对 (i, j) 为：
- (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
- (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
所以可以获得的最大和是 54 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,12,19,14]
<strong>输出：</strong>-1
<strong>解释：</strong>不存在满足条件的数对，返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：哈希表

我们只需要建立一个哈希表，维护哈希表中“和为$key$的最大的两个数”即可。

具体怎么做呢？

遍历数组中的元素$t$，如果$t$的和在哈希表中，那么就保留“哈希表中”和“$t$”中较大的两个元素。

这里有一个小技巧：可以保持哈希表中的两个元素的相对顺序为第一个元素不小于第二个元素，这样替换时只需要比较$t$和哈希表对应元素的第二个元素即可。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
inline int getSum(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> ma;
        int ans = -1;
        for (int t : nums) {
            int s = getSum(t);
            if (t > ma[s].second) {
                ma[s].second = t;
            }
            if (ma[s].first < ma[s].second) {
                swap(ma[s].first, ma[s].second);
            }
            if (ma[s].second) {
                ans = max(ans, ma[s].first + ma[s].second);
            }
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def getSum(self, n: int) -> int:
        ans = 0
        while n:
            ans += n % 10
            n //= 10
        return ans
    
    def maximumSum(self, nums: List[int]) -> int:
        ans = -1
        ma = dict()
        for t in nums:
            s = self.getSum(t)
            if s in ma:
                if t > ma[s][1]:
                    ma[s][1] = t
                if ma[s][0] < ma[s][1]:
                    ma[s][0], ma[s][1] = ma[s][1], ma[s][0]
                ans = max(ans, sum(ma[s]))
            else:
                ma[s] = [t, 0]
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/18/LeetCode%202342.%E6%95%B0%E4%BD%8D%E5%92%8C%E7%9B%B8%E7%AD%89%E6%95%B0%E5%AF%B9%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134476645](https://letmefly.blog.csdn.net/article/details/134476645)
