---
title: 1262.可被三整除的最大和：时间O(n)空间O(1)
date: 2023-06-19 16:33:04
tags: [题解, LeetCode, 中等, 贪心, 数组, 动态规划, 数学, 取模, 同余]
categories: [题解, LeetCode]
---

# 【LetMeFly】1262.可被三整除的最大和：时间O(n)空间O(1)

力扣题目链接：[https://leetcode.cn/problems/greatest-sum-divisible-by-three/](https://leetcode.cn/problems/greatest-sum-divisible-by-three/)

<p>给你一个整数数组&nbsp;<code>nums</code>，请你找出并返回能被三整除的元素最大和。</p>

<ol>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,6,5,1,8]
<strong>输出：</strong>18
<strong>解释：</strong>选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4]
<strong>输出：</strong>0
<strong>解释：</strong>4 不能被 3 整除，所以无法选出数字，返回 0。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,4]
<strong>输出：</strong>12
<strong>解释：</strong>选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 4 * 10^4</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^4</code></li>
</ul>


    
## 方法一：数学 + 同余

一个数对3取模，只有0、1、2这三种情况。

我们只需要对nums中所有数求和(cnt)并对3取模：
   + 如果取模结果为0，直接返回cnt
   + 如果取模结果为1，cnt减去一个最小的模3为1的数 或 减去两个最小的模3为2的数 并返回（若无充足的数可供减去，则返回0）
   + 如果取模结果为1，cnt减去一个最小的模3为2的数 或 减去两个最小的模3为1的数 并返回

上述表达中，“两个最小的数”意思为最小的和第二小的两个数。

那么，怎么确定模3为1的所有的数中，最小的一个或最小的两个呢？

最简单的方法就是排序。但是排序需要消耗O(n)的时间和O(log n)的空间，**时空消耗太大了**。

有没有什么时间O(n)空间O(1)的方法呢？当然有。

我们只需要写一个类，类中有三个变量：min1、min2、num。

其中min1代表最小的数，min2代表第二小的数，num代表min1和min2两个变量中有效变量的数量。

每次遇到一个模3为1的数，我们只需要调用类中的更新函数，遍历结束后即可获得最小值和第二小值。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Min2 {  // 最小的两个数（范围1-10^4）
private:
    int min1, min2;
    int num;
public:
    Min2() {
        min1 = min2 = num = 0;
    }

    void update(int n) {
        if (!num) {
            min1 = n;
            num = 1;
        }
        else if (num == 1) {
            min2 = n;
            num = 2;
            if (min1 > min2) {
                swap(min1, min2);
            }
        }
        else {
            if (n < min1) {
                min2 = min1;
                min1 = n;
            }
            else if (n < min2) {
                min2 = n;
            }
        }
    }

    int getMin1() {
        return min1;
    }

    int getMin2() {
        return min2;
    }

    int getMinNum() {
        return num;
    }
};

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        Min2 mod1, mod2;
        int cnt = 0;
        for (int t : nums) {
            cnt += t;
            if (t % 3 == 1) {
                mod1.update(t);
            }
            else if (t % 3 == 2) {
                mod2.update(t);
            }
        }
        if (cnt % 3 == 0) {
            return cnt;
        }
        else if (cnt % 3 == 1) {  // 减去一个模为1的或两个模为2的
            if (mod1.getMinNum() < 1 && mod2.getMinNum() < 2) {
                return 0;
            }
            int ans = 0;
            if (mod1.getMinNum()) {
                ans = max(ans, cnt - mod1.getMin1());
            }
            if (mod2.getMinNum() >= 2) {
                ans = max(ans, cnt - mod2.getMin1() - mod2.getMin2());
            }
            return ans;
        }
        else {  // 减去一个模为2的或两个模为1的
            if (mod2.getMinNum() < 1 && mod1.getMinNum() < 2) {
                return 0;
            }
            int ans = 0;
            if (mod2.getMinNum()) {
                ans = max(ans, cnt - mod2.getMin1());
            }
            if (mod1.getMinNum() >= 2) {
                ans = max(ans, cnt - mod1.getMin1() - mod1.getMin2());
            }
            return ans;
        }
    }
};
```

#### Python

```python
# from typing import List


class Min2:
    min1 = 0
    min2 = 0
    num = 0

    def update(self, n: int) -> None:
        if not self.num:
            self.min1 = n
            self.num = 1
        elif self.num == 1:
            self.min2 = n
            self.num = 2
            if self.min1 > self.min2:
                self.min1, self.min2 = self.min2, self.min1
        else:
            if n < self.min1:
                self.min2 = self.min1
                self.min1 = n
            elif n < self.min2:
                self.min2 = n
    
    def getMin1(self) -> int:
        return self.min1
    
    def getMin2(self) -> int:
        return self.min2
    
    def getMinNum(self) -> int:
        return self.num


class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        mod1, mod2 = Min2(), Min2()
        cnt = 0
        for t in nums:
            cnt += t
            if t % 3 == 1:
                mod1.update(t)
            elif t % 3 == 2:
                mod2.update(t)
        if cnt % 3 == 0:
            return cnt
        elif cnt % 3 == 1:
            ans = 0
            if mod1.getMinNum():
                ans = max(ans, cnt - mod1.getMin1())
            if mod2.getMinNum() >= 2:
                ans = max(ans, cnt - mod2.getMin1() - mod2.getMin2())
            return ans
        else:
            ans = 0
            if mod2.getMinNum():
                ans = max(ans, cnt - mod2.getMin1())
            if mod1.getMinNum() >= 2:
                ans = max(ans, cnt - mod1.getMin1() - mod1.getMin2())
            return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/19/LeetCode%201262.%E5%8F%AF%E8%A2%AB%E4%B8%89%E6%95%B4%E9%99%A4%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131290984](https://letmefly.blog.csdn.net/article/details/131290984)
