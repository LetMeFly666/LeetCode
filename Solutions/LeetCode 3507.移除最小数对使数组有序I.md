---
title: 3507.移除最小数对使数组有序 I：纯模拟
date: 2026-01-22 23:57:26
tags: [题解, LeetCode, 简单, 数组, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3507.移除最小数对使数组有序 I：纯模拟

力扣题目链接：[https://leetcode.cn/problems/minimum-pair-removal-to-sort-array-i/](https://leetcode.cn/problems/minimum-pair-removal-to-sort-array-i/)

<p>给你一个数组 <code>nums</code>，你可以执行以下操作任意次数：</p>

<ul>
	<li>选择 <strong>相邻&nbsp;</strong>元素对中 <strong>和最小</strong> 的一对。如果存在多个这样的对，选择最左边的一个。</li>
	<li>用它们的和替换这对元素。</li>
</ul>

<p>返回将数组变为&nbsp;<strong>非递减&nbsp;</strong>所需的&nbsp;<strong>最小操作次数&nbsp;</strong>。</p>

<p>如果一个数组中每个元素都大于或等于它前一个元素（如果存在的话），则称该数组为<strong>非递减</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [5,2,3,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>元素对 <code>(3,1)</code> 的和最小，为 4。替换后&nbsp;<code>nums = [5,2,4]</code>。</li>
	<li>元素对 <code>(2,4)</code> 的和为 6。替换后&nbsp;<code>nums = [5,6]</code>。</li>
</ul>

<p>数组 <code>nums</code> 在两次操作后变为非递减。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>数组 <code>nums</code> 已经是非递减的。</p>
</div>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>-1000&nbsp;&lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 解题方法：模拟

写个函数判断是否已经非递减、写个函数判断哪个下标开始的数对被合并、写个函数合并两个数。

完事。

+ 时间复杂度$O(len(nums)^2)$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-22 23:47:47
 */
template<class Type>
void debug(vector<Type>v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    puts("");
}

class Solution {
private:
    bool finished(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // len(nums)一定大于等于2
    int getMinPairIdx(vector<int>& nums) {
        int idx = 0, mini = 50001;  // 这里不能是2001
        for (int i = 0; i + 1 < nums.size(); i++) {
            int cnt = nums[i] + nums[i + 1];
            if (cnt < mini) {
                mini = cnt;
                idx = i;
            }
        }
        return idx;
    }

    vector<int> merge(vector<int>& nums, int idx) {
        vector<int> ans;
        for (int i = 0; i < idx; i++) {
            ans.push_back(nums[i]);
        }
        ans.push_back(nums[idx] + nums[idx + 1]);
        for (int i = idx + 2; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!finished(nums)) {
            int idx = getMinPairIdx(nums);
            nums = merge(nums, idx);
            // debug(nums);
            ans++;  // don't forgot
        }
        return ans;
    }
};

/*
[689,-360,234,673,663,-741,480,860,-707,209,246,792,930,696,-305]

My:
689 -360 234 673 663 -741 480 860 -498 246 792 930 696 -305 
689 -360 234 673 663 -261 860 -498 246 792 930 696 -305 
689 -360 234 673 663 -261 860 -252 792 930 696 -305 
689 -126 673 663 -261 860 -252 792 930 696 -305 
689 -126 673 663 -261 860 -252 792 930 391 
689 -126 673 402 860 -252 792 930 391 
689 -126 673 402 860 540 930 391 
689 547 402 860 540 930 391 
689 949 860 540 930 391 
689 949 860 540 1321 
689 949 1400 1321 
1638 1400 1321   <-----应该merge后俩
3038 1321 
4359 

14


should:
689 -360 234 673 663 -741 480 860 -498 246 792 930 696 -305 
689 -360 234 673 663 -261 860 -498 246 792 930 696 -305 
689 -360 234 673 663 -261 860 -252 792 930 696 -305
689 -126 673 663 -261 860 -252 792 930 696 -305
689 -126 673 663 -261 860 -252 792 930 391
689 -126 673 402 860 -252 792 930 391
689 -126 673 402 860 540 930 391
689 547 402 860 540 930 391
689 949 860 540 930 391
689 949 860 540 1321
689 949 1400 1321
1638 1400 1321
1638 2721

13
*/
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-22 23:55:38
 */
impl Solution {
    fn finished(nums: &Vec<i32>) -> bool {
        for i in 1..nums.len() {
            if nums[i] < nums[i - 1] {
                return false;
            }
        }
        true
    }

    fn get_mini_pair_idx(nums: &Vec<i32>) -> usize {
        let mut idx = 0;
        let mut mini = 500001;
        for i in 0..nums.len() - 1 {
            let cnt = nums[i] + nums[i + 1];
            if cnt < mini {
                mini = cnt;
                idx = i;
            }
        }
        idx
    }

    fn merge(nums: &Vec<i32>, idx: usize) -> Vec<i32> {
        let mut ans = Vec::with_capacity(nums.len() - 1);
        for i in 0..idx {
            ans.push(nums[i]);
        }
        ans.push(nums[idx] + nums[idx + 1]);
        for i in idx + 2..nums.len() {
            ans.push(nums[i]);
        }
        ans
    }

    pub fn minimum_pair_removal(mut nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        while !Self::finished(&nums) {
            let idx = Self::get_mini_pair_idx(&nums);
            nums = Self::merge(&nums, idx);
            ans += 1;
        }
        ans
    }
}
```

More: [3510.移除最小数对使数组有序 II：有序集合](https://blog.letmefly.xyz/2026/01/23/LeetCode%203510.%E7%A7%BB%E9%99%A4%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AF%B9%E4%BD%BF%E6%95%B0%E7%BB%84%E6%9C%89%E5%BA%8FII/)

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157263848)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/22/LeetCode%203507.%E7%A7%BB%E9%99%A4%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AF%B9%E4%BD%BF%E6%95%B0%E7%BB%84%E6%9C%89%E5%BA%8FI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
