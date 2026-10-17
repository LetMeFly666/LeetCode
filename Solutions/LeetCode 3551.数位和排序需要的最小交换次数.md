---
title: 3551.数位和排序需要的最小交换次数：计算连通块个数
date: 2026-10-17 20:57:43
tags: [题解, LeetCode, 中等, 数组, 哈希表, 排序, 图, 连通图, 并查集]
categories: [题解, LeetCode]
---

# 【LetMeFly】3551.数位和排序需要的最小交换次数：计算连通块个数

力扣题目链接：[https://leetcode.cn/problems/minimum-swaps-to-sort-by-digit-sum/](https://leetcode.cn/problems/minimum-swaps-to-sort-by-digit-sum/)

<p>给你一个由 <strong>互不相同</strong>&nbsp;的正整数组成的数组 <code>nums</code>，需要根据每个数字的数位和（即每一位数字相加求和）按&nbsp;<strong>升序&nbsp;</strong>对数组进行排序。如果两个数字的数位和相等，则较小的数字排在前面。</p>

<p>返回将 <code>nums</code> 排列为上述排序顺序所需的&nbsp;<strong>最小&nbsp;</strong>交换次数。</p>

<p>一次&nbsp;<strong>交换&nbsp;</strong>定义为交换数组中两个不同位置的值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">nums = [37,100]</span></p>

<p><strong>输出:</strong> <span class="example-io">1</span></p>

<p><strong>解释:</strong></p>

<ul>
	<li>计算每个整数的数位和：<code>[3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]</code></li>
	<li>根据数位和排序：<code>[100, 37]</code>。将 <code>37</code> 与 <code>100</code> 交换，得到排序后的数组。</li>
	<li>因此，将 <code>nums</code> 排列为排序顺序所需的最小交换次数为 1。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">nums = [22,14,33,7]</span></p>

<p><strong>输出:</strong> <span class="example-io">0</span></p>

<p><strong>解释:</strong></p>

<ul>
	<li>计算每个整数的数位和：<code>[2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]</code></li>
	<li>根据数位和排序：<code>[22, 14, 33, 7]</code>。数组已经是排序好的。</li>
	<li>因此，将 <code>nums</code> 排列为排序顺序所需的最小交换次数为 0。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">nums = [18,43,34,16]</span></p>

<p><strong>输出:</strong> <span class="example-io">2</span></p>

<p><strong>解释:</strong></p>

<ul>
	<li>计算每个整数的数位和：<code>[1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]</code></li>
	<li>根据数位和排序：<code>[16, 34, 43, 18]</code>。将 <code>18</code> 与 <code>16</code> 交换，再将 <code>43</code> 与 <code>34</code> 交换，得到排序后的数组。</li>
	<li>因此，将 <code>nums</code> 排列为排序顺序所需的最小交换次数为 2。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code> 由 <strong>互不相同</strong> 的正整数组成。</li>
</ul>


    
## 解题方法：计算连通块个数

我们可以创建一个下标数组`idxs`，其中`idxs[i]`表示排序后`nums[i]`的下标。

假设排序后`idxs`数组为`[1, 0, 3, 4, 2]`，则说明下标需要由原来的`[0, 1, 2, 3, 4]`变为`[1, 0, 3, 4, 2]`。怎么变？

不难发现`[0, 1]`互相交换（共1次），`[2, 3, 4]`互相交换（共2次）即可。

我们可以把每个下标抽象为图中一个节点，`idxs[i]`表示节点`i`和节点`idxs[i]`之间有一条边。只需要求出整张图中有多少个连通块（上述例子中有两个连通块），则最小交换次数为`n - 连通块个数`。

### 具体方法一：并查集

从`0`到`n-1`遍历每个下标`i`，将`i`和`idxs[i]`合并。最后返回`n - 连通块个数`。

### 具体方法二：迭代

使用一个`visited`数组标记每个下标是否被访问过，从`0`到`n-1`遍历每个下标`i`，如果`visited[i]`为`false`，则说明找到了一个新的连通块，将连通块个数加一，并将该连通块中的**所有**下标都标记为已访问。

### 时空复杂度

+ 时间复杂度$O(n\log U + n\log n)$，其中$n=len(nums)$，$U=\max (nums)$
+ 空间复杂度$O(n)$

### AC代码

#### C++ —— 并查集

```cpp
/*
 * @LastEditTime: 2026-10-17 18:40:12
 */
class Solution {
private:
    vector<int> parent;
    vector<int> sz;

    int getSum(int a) {
        int ans = 0;
        while (a) {
            ans += a % 10;
            a /= 10;
        }
        return ans;
    }

    void initUnion(int n) {
        parent.resize(n);
        ranges::iota(parent, 0);
        sz.assign(n, 1);
    }

    int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }

    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (sz[pa] > sz[pb]) {
            // swap(a, b);
            swap(pa, pb);
        }
        parent[pa] = pb;
        sz[pb] += sz[pa];
        return true;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> idxs(n);
        ranges::iota(idxs, 0);
        sort(idxs.begin(), idxs.end(), [this, &nums](const int& a, const int& b) {
            int sa = getSum(nums[a]);
            int sb = getSum(nums[b]);
            return sa == sb ? nums[a] < nums[b] : sa < sb;
        });
        // debug(idxs);

        int ans = nums.size();
        initUnion(n);
        for (int i = 0; i < n; i++) {
            ans -= !unite(i, idxs[i]);
        }
        return ans;
    }
};
```

#### C++ —— 迭代

```cpp
/*
 * @LastEditTime: 2026-10-17 19:08:54
 */
class Solution {
private:
    int getSum(int a) {
        int ans = 0;
        while (a) {
            ans += a % 10;
            a /= 10;
        }
        return ans;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> idxs(n);
        ranges::iota(idxs, 0);
        sort(idxs.begin(), idxs.end(), [this, &nums](const int& a, const int& b) {
            int sa = getSum(nums[a]);
            int sb = getSum(nums[b]);
            return sa == sb ? nums[a] < nums[b] : sa < sb;
        });
        // debug(idxs);

        int ans = nums.size();
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans--;
            }
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                x = idxs[x];
            }
        }
        return ans;
    }
};
```

#### Python —— 并查集

```python
'''
LastEditTime: 2026-10-17 19:03:51
'''
from typing import List

class Union:
    def __init__(self, n: int) -> None:
        self.parent = [i for i in range(n)]
        self.sz = [1] * n
        self.count = n
    
    def merge(self, x: int, y: int) -> None:
        px = self.find(x)
        py = self.find(y)
        if px == py:
            return
        if self.sz[px] > self.sz[py]:
            px, py = py, px
        self.parent[px] = py
        self.sz[py] += self.sz[px]
        self.count -= 1
    
    def find(self, x: int) -> int:
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

class Solution:
    def _getSum(self, n: int) -> int:
        ans = 0
        while n:
            ans += n % 10
            n //= 10
        return ans
        
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        idxs = [i for i in range(n)]
        idxs.sort(key=lambda i: (self._getSum(nums[i]), nums[i]))
        # print(idxs)
        
        union = Union(n)
        for i in range(n):
            union.merge(i, idxs[i])
        return n - union.count
```

#### Java —— 并查集

```java
/*
 * @LastEditTime: 2026-10-17 20:22:23
 */
import java.util.Arrays;

class Union {
    private final int[] parent;
    private final int[] sz;
    int count;

    Union(int n) {
        parent = new int[n];
        sz = new int[n];
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return;
        }
        count--;
        if (sz[px] > sz[py]) {
            int tmp = px;
            px = py;
            py = tmp;
        }
        sz[py] += sz[px];
        parent[px] = py;
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
}

class Solution {
    private int getSum(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;
        Integer[] idxs = new Integer[n];
        for (int i = 0; i < n; i++) {
            idxs[i] = i;
        }
        Arrays.sort(idxs, (a, b) -> {
            int sa = getSum(nums[a]);
            int sb = getSum(nums[b]);
            return sa == sb ? nums[a] - nums[b] : sa - sb;
        });

        Union union = new Union(n);
        for (int i = 0; i < n; i++) {
            union.merge(i, idxs[i]);
        }
        return n - union.count;
    }
}
```

#### Go —— 并查集

```go
/*
 * @LastEditTime: 2026-10-17 20:36:32
 */
package main

import "sort"

type Union3551 struct {
    parent []int
    sz     []int
    count  int
}

func newUnion3551(n int) *Union3551 {
    parent := make([]int, n)
    sz := make([]int, n)
    for i := range parent {
        parent[i] = i
        sz[i] = 1
    }
    return &Union3551 {
        parent: parent,
        sz: sz,
        count: n,
    }
}

func (u *Union3551) Find(x int) int {
    if u.parent[x] == x {
        return x
    }
    u.parent[x] = u.Find(u.parent[x])
    return u.parent[x]
}

func (u *Union3551) Merge(x, y int) {
    px := u.Find(x)
    py := u.Find(y)
    if px == py {
        return
    }
    if u.sz[px] > u.sz[py] {
        px, py = py, px
    }
    u.sz[py] += u.sz[px]
    u.parent[px] = py
    u.count--
}

func getSum3551(x int) (ans int) {
    for x > 0 {
        ans += x % 10
        x /= 10
    }
    return
}

func minSwaps(nums []int) int {
    n := len(nums)
    idxs := make([]int, n)
    sums := make([]int, n)
    for i, t := range nums {
        idxs[i] = i;
        sums[i] = getSum3551(t)
    }
    sort.Slice(idxs, func(i, j int) bool {
        if sums[idxs[i]] == sums[idxs[j]] {
            return nums[idxs[i]] < nums[idxs[j]]
        }
        return sums[idxs[i]] < sums[idxs[j]]
    })

    union := newUnion3551(n)
    for i, t := range idxs {
        union.Merge(i, t)
    }
    return n - union.count
}
```

#### Rust —— 并查集

```rust
/*
 * @LastEditTime: 2026-10-17 20:57:05
 */
struct Union {
    parent: Vec<usize>,
    sz: Vec<usize>,
    count: usize,
}

impl Union {
    fn new(n: usize) -> Self {
        Union {
            parent: (0..n).collect(),
            sz: vec![1; n],
            count: n
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] == x {
            x
        } else {
            self.parent[x] = self.find(self.parent[x]);
            self.parent[x]
        }
    }

    fn merge(&mut self, x: usize, y: usize) {
        let mut px = self.find(x);
        let mut py = self.find(y);
        if px == py {
            return;
        }
        if self.sz[px] > self.sz[py] {
            std::mem::swap(&mut px, &mut py);
        }
        self.sz[py] += self.sz[px];
        self.parent[px] = py;
        self.count -= 1;
    }
}

impl Solution {
    fn get_sum(mut n: i32) -> i32 {
        let mut ans = 0;
        while n > 0 {
            ans += n % 10;
            n /= 10;
        }
        ans
    }

    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut idxs: Vec<usize> = (0..n).collect();
        idxs.sort_by_key(|&i| (Solution::get_sum(nums[i]), nums[i]));  // i是&usize类型，&i是usize类型
        
        let mut union = Union::new(n);
        for i in 0..n {
            union.merge(i, idxs[i]);
        }
        (n - union.count) as i32
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/168249233)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/17/LeetCode%203551.%E6%95%B0%E4%BD%8D%E5%92%8C%E6%8E%92%E5%BA%8F%E9%9C%80%E8%A6%81%E7%9A%84%E6%9C%80%E5%B0%8F%E4%BA%A4%E6%8D%A2%E6%AC%A1%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
