---
title: 136.只出现一次的数字
date: 2022-07-25 16:43:01
tags: [题解, LeetCode, 简单, 位运算, 数组, 异或, XOR]
categories: [题解, LeetCode]
---

# 【LetMeFly】136.只出现一次的数字：异或

力扣题目链接：[https://leetcode.cn/problems/single-number/](https://leetcode.cn/problems/single-number/)

<p>给定一个<strong>非空</strong>整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。</p>

<p><strong>说明：</strong></p>

<p>你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> [2,2,1]
<strong>输出:</strong> 1
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> [4,1,2,1,2]
<strong>输出:</strong> 4</pre>


    
## 方法一：异或

异或的重要性质：

1. $a\oplus b\oplus b=a$
2. $0\oplus a = a$
3. 异或结果与异或顺序无关

因此，我们用$0$开始，异或每一个数，最终结果就是答案。

（除了答案都出现了两次，$0$异或一个数两次还是$0$；答案只出现了一次，$0$异或答案一次就等于答案）

+ 时间复杂度$O(n)$，其中$n$是元素个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& t : nums) {
            ans ^= t;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for t in nums:
            ans ^= t
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/25/LeetCode%200136.%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125978508](https://letmefly.blog.csdn.net/article/details/125978508)
