---
title: 3074.重新分装苹果：排序
date: 2025-12-24 18:48:30
tags: [题解, LeetCode, 简单, 贪心, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3074.重新分装苹果：排序

力扣题目链接：[https://leetcode.cn/problems/apple-redistribution-into-boxes/](https://leetcode.cn/problems/apple-redistribution-into-boxes/)

<p>给你一个长度为 <code>n</code> 的数组 <code>apple</code> 和另一个长度为 <code>m</code> 的数组 <code>capacity</code> 。</p>

<p>一共有 <code>n</code> 个包裹，其中第 <code>i</code> 个包裹中装着 <code>apple[i]</code> 个苹果。同时，还有 <code>m</code> 个箱子，第 <code>i</code> 个箱子的容量为 <code>capacity[i]</code> 个苹果。</p>

<p>请你选择一些箱子来将这 <code>n</code> 个包裹中的苹果重新分装到箱子中，返回你需要选择的箱子的<strong> 最小</strong> 数量。</p>

<p><strong>注意</strong>，同一个包裹中的苹果可以分装到不同的箱子中。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>apple = [1,3,2], capacity = [4,3,1,5,2]
<strong>输出：</strong>2
<strong>解释：</strong>使用容量为 4 和 5 的箱子。
总容量大于或等于苹果的总数，所以可以完成重新分装。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>apple = [5,5,5], capacity = [2,4,2,7]
<strong>输出：</strong>4
<strong>解释：</strong>需要使用所有箱子。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == apple.length &lt;= 50</code></li>
	<li><code>1 &lt;= m == capacity.length &lt;= 50</code></li>
	<li><code>1 &lt;= apple[i], capacity[i] &lt;= 50</code></li>
	<li>输入数据保证可以将包裹中的苹果重新分装到箱子中。</li>
</ul>


    
## 解题方法：排序

每个<font title="2025.12.24">苹果</font>都要有它的归宿，一共有多少个苹果呢？算一算就知道了。

如何使用最少的箱子？当然是用尽可能大的箱子！

把箱子从大到小排个序，遍历箱子并依次消费苹果，直到苹果消费完毕。

+ 时间复杂度$O(n+m\log m)$
+ 空间复杂度$O(\log m)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-24 13:32:26
 */
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<>());
        int cnt = 0;
        for (int t : apple) {
            cnt += t;
        }
        int ans = 0;
        for (int t : capacity) {
            cnt -= t;
            ans++;
            if (cnt <= 0) {
                return ans;
            }
        }
        return -1;  // Fake Return
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-12-24 13:40:50
'''
from typing import List

class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        cnt = sum(apple)
        ans = 0
        for t in sorted(capacity, reverse=True):
            cnt -= t
            ans += 1
            if cnt <= 0:
                return ans


# if __name__ == "__main__":
#     sol = Solution()
#     print(sol.minimumBoxes([1,3,2], [4,3,1,5,2]))
```

#### Java

```java
/*
 * @LastEditTime: 2025-12-24 18:35:17
 */
import java.util.Arrays;

class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int cnt = 0;
        for (int t : apple) {
            cnt += t;
        }
        Arrays.sort(capacity);
        int ans = 0;
        for (int i = capacity.length - 1; i >= 0; i--) {
            cnt -= capacity[i];
            ans++;
            if (cnt <= 0) {
                return ans;
            }
        }
        return -1;  // FAKE RETURN
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-12-24 13:45:02
 */
package main

import "sort"

func minimumBoxes(apple []int, capacity []int) int {
    cnt := 0
    for _, t := range apple {
        cnt += t
    }
    sort.Sort(sort.Reverse(sort.IntSlice(capacity)))
    for i, t := range capacity {
        cnt -= t
        if cnt <= 0 {
            return i + 1
        }
    }
    return -1  // Fake Return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-12-24 18:47:13
 */
impl Solution {
    pub fn minimum_boxes(apple: Vec<i32>, mut capacity: Vec<i32>) -> i32 {
        let mut cnt: i32 = 0;
        for t in apple.iter() {
            cnt += t;
        }
        capacity.sort_by(|a, b| b.cmp(a));

        let mut ans: i32 = 0;
        for t in capacity.iter() {
            cnt -= t;
            ans += 1;
            if cnt <= 0 {
                return ans
            }
        }
        ans
    }
}
```

## End

Merry Christmas？

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156239770)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/24/LeetCode%203074.%E9%87%8D%E6%96%B0%E5%88%86%E8%A3%85%E8%8B%B9%E6%9E%9C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
