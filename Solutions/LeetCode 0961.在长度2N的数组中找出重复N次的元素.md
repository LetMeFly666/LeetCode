---
title: 961.在长度 2N 的数组中找出重复 N 次的元素：5种语言x5种方法(及其变种) —— All By Hand
date: 2026-01-02 13:01:10
tags: [题解, LeetCode, 简单, 数组, 哈希表]
categories: [题解, LeetCode]
---

# 【LetMeFly】961.在长度 2N 的数组中找出重复 N 次的元素：5种语言x5种方法(及其变种) —— All By Hand

力扣题目链接：[https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/](https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/)

<p>给你一个整数数组 <code>nums</code> ，该数组具有以下属性：</p>

<div class="original__bRMd">
<div>
<ul>
	<li><code>nums.length == 2 * n</code>.</li>
	<li><code>nums</code> 包含 <code>n + 1</code> 个 <strong>不同的</strong> 元素</li>
	<li><code>nums</code> 中恰有一个元素重复 <code>n</code> 次</li>
</ul>

<p>找出并返回重复了 <code>n</code><em> </em>次的那个元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,3]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,2,5,3,2]
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,1,5,2,5,3,5,4]
<strong>输出：</strong>5
</pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5000</code></li>
	<li><code>nums.length == 2 * n</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 由 <code>n + 1</code> 个<strong> 不同的</strong> 元素组成，且其中一个元素恰好重复 <code>n</code> 次</li>
</ul>


    
## 解题方法一.1：排序+看相邻

nums排个序，有且仅有出现$n$次的元素会相邻且相同。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;  // FAKE RETURN
    }
};
```

竟然和2022.5.21[写的](https://blog.letmefly.xyz/2022/05/21/LeetCode%200961.%E5%9C%A8%E9%95%BF%E5%BA%A62N%E7%9A%84%E6%95%B0%E7%BB%84%E4%B8%AD%E6%89%BE%E5%87%BA%E9%87%8D%E5%A4%8DN%E6%AC%A1%E7%9A%84%E5%85%83%E7%B4%A0-20220521/#lastcpp)几乎一模一样。

#### Python

```python
from typing import List

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return nums[i]
```

#### Go

```go
package main

import "sort"

func repeatedNTimes(nums []int) int {
    sort.Ints(nums)
    for i := 1; i < len(nums); i++ {
        if nums[i] == nums[i - 1] {
            return nums[i]
        }
    }
    return -1  // FAKE RETURN
}
```

#### Java

```java
import java.util.Arrays;

class Solution {
    public int repeatedNTimes(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return -1;
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        for i in 1..nums.len() {
            if nums[i] == nums[i - 1] {
                return nums[i];
            }
        }
        -1  // FAKE RETURN
    }
}
```

## 解题方法一.2：排序+看中间

有一个数字恰好出现了$n$次，那么排序后中间位置的两个元素至少有一个是它。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        return nums[mid] == nums[mid + 1] ? nums[mid] : nums[mid - 1];
    }
};
```

#### C++. 不能通过版本

不能这样思考：

> 有一个数字恰好出现了$n$次，那么排序后要么前半段全是它要么后半段全是它。

> 排序后看看前两个元素相同的话就是前半段，否则就是后半段。

```cpp
// THIS CANNOT BE ACCEPTED
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0] == nums[1] ? nums[0] : nums.back();
    }
};
```

反例：`[1, 2, 2, 3]`。

#### Python

```python
from typing import List

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        nums.sort()
        mid = len(nums) // 2
        return nums[mid] if nums[mid] == nums[mid + 1] else nums[mid - 1]
```

#### Go

```go
package main

import "sort"

func repeatedNTimes(nums []int) int {
    sort.Ints(nums)
    mid := len(nums) / 2
    if nums[mid] == nums[mid + 1] {
        return nums[mid]
    }
    return nums[mid - 1]
}
```

#### Java

```java
import java.util.Arrays;

class Solution {
    public int repeatedNTimes(int[] nums) {
        Arrays.sort(nums);
        int mid = nums.length / 2;
        return nums[mid] == nums[mid + 1] ? nums[mid] : nums[mid - 1];
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mid: usize = nums.len() / 2;
        if nums[mid] == nums[mid + 1] {
            return nums[mid];
        }
        nums[mid - 1]
    }
}
```

## 解题方法二：哈希表

使用哈希表记录出现过的元素，如果一个元素二次出现则视为找到答案。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> visited;
        for (int t : nums) {
            if (visited.count(t)) {
                return t;
            }
            visited.insert(t);
        }
        return -1;  // FAKE RETURN
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        visited = set()
        for t in nums:
            if t in visited:
                return t
            visited.add(t)
```

#### Go

```go
package main

func repeatedNTimes(nums []int) int {
    visited := map[int]bool{}
    for _, t := range nums {
        if _, ok := visited[t]; ok {
            return t
        }
        visited[t] = true
    }
    return -1  // FAKE RETURN
}
```

#### Java

```java
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int repeatedNTimes(int[] nums) {
        Set<Integer> visited = new HashSet<>();
        for (int t : nums) {
            if (visited.contains(t)) {
                return t;
            }
            visited.add(t);
        }
        return -1;  // FAKE RETURN
    }
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        let mut visited = HashSet::new();
        for t in nums.iter() {
            if visited.contains(&t) {
                return *t;
            }
            visited.insert(t);
        }
        -1  // FAKE RETURN
    }
}
```

## 解题方法三：相邻相隔一次遍历

长度为$2n$的数组中一个数出现了$n$次，那么数组中这个数（假设为$t$）一定存在一下情况之一：

1. 两个$t$相邻
2. 两个$t$中间隔一个元素

否则，任何两个$t$之间都间隔至少两个元素，$t$的数量将会无法达到$n$。

所以我们只需要遍历一遍数组，找到`相邻相同`或`相隔一数且相同`的数就好了。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2]) {
                return nums[i];
            }
        }
        return nums[0];  // 前面循环中未判断nums[0]是否等于nums[1]，若前面未return则说明nums[0]=nums[1]如[1, 1, 2, 3]
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        for i in range(2, len(nums)):
            if nums[i] == nums[i-1] or nums[i] == nums[i-2]:
                return nums[i]
        return nums[0]
```

#### Go

```go
package main

import "sort"

func repeatedNTimes(nums []int) int {
    sort.Ints(nums)
    for i := 2; i < len(nums); i++ {
        if nums[i] == nums[i-1] || nums[i] == nums[i-2] {
            return nums[i]
        }
    }
    return nums[0]
}
```

#### Java

```java
class Solution {
    public int repeatedNTimes(int[] nums) {
        for (int i = 2; i < nums.length; i++) {
            if (nums[i] == nums[i-1] || nums[i] == nums[i-2]) {
                return nums[i];
            }
        }
        return nums[0];
    }
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        for i in 2..nums.len() {
            if nums[i] == nums[i - 1] || nums[i] == nums[i - 2] {
                return nums[i]
            }
        }
        nums[0]
    }
}
```

## 解题方法四：擂台赛（摩尔投票法）

假设某个元素在数组中数量占绝对优势（大于半数），那么可以数组中元素依次上擂台：

* 如果擂台上没有人，自己成为霸主，生命值为1
* 如果擂台上有人，且和自己相同，则霸主生命值加1
* 如果擂台上有人，且和自己不同，则霸主生命值减1（减少至0视为死亡）

这种方法不限制其他数是否有重复，但是与本题相比本题其他数不会重复但是所寻找元素比严格大于半数少1次。

怎么办呢？将数组分为第一个数和剩下其他数两部分：

* 如果所找元素是第一个数，那么在剩下的数组中一定存在和这个数相同的数，相同则找到
* 如果所找元素和第一个数不相等，那么所找元素在剩下的数组中出现次数大于半数，可以使用摩尔投票法

**这种方法更适合其他元素也有相同的情况** ，用在此处略有牵强。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if (nums[0] == nums[1]) {
            return nums[0];
        }
        int now = -1, hp = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[0]) {
                return nums[0];
            }
            if (hp == 0) {
                hp = 1;
                now = nums[i];
            } else if (now == nums[i]) {
                hp++;  // 其实也可以直接return了
            } else {
                hp--;
            }
        }
        return now;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        ans, hp = -1, 0
        for t in nums[1:]:
            if t == nums[0]:
                return t
            if not hp:
                ans, hp = t, 1
            elif ans == t:
                hp += 1
            else:
                hp -= 1
        return ans
```

#### GO

```go
package main

func repeatedNTimes(nums []int) int {
    ans, hp := -1, 0
    for i := 1; i < len(nums); i++ {
        if nums[i] == nums[0] {
            return nums[0]
        }
        if hp == 0 {
            ans, hp = nums[i], 1
        } else if ans == nums[i] {
            hp++
        } else {
            hp--
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int repeatedNTimes(int[] nums) {
        int ans = 0, hp = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[0]) {
                return nums[0];
            }
            if (hp == 0) {
                ans = nums[i];
                hp = 1;
            } else if (ans == nums[i]) {
                hp++;
            } else {
                hp--;
            }
        }
        return ans;
    }
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        let mut ans: i32 = -1;
        let mut hp: i32 = 0;
        for i in 1..nums.len() {
            if nums[i] == nums[0] {
                return nums[0]
            }
            if hp == 0 {
                ans = nums[i];
                hp = 1;
            } else if ans == nums[i] {
                hp += 1;
            } else {
                hp -= 1;
            }
        }
        ans
    }
}
```

## 解题方法五(trick)：随机

每次随机选取两个元素，直到选到两个相等的元素为止。

这种方法看似很盲目，其实效率很高，所选两元素相同的概率为$\frac{n}{2n}\times \frac{n-1}{2n}\approx \frac{1}{4}$，平均4次随机选择就能找到答案，因此期望时间复杂度为$O(1)$。

> 为什么是$\frac{n}{2n}\times \frac{n-1}{2n}$呢？因为是全随机，第一次在$2n$个数字里面有$n$个可选，第二次还是在$2n$个数字里面有$n-1$个可选。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    inline static mt19937 gen = mt19937(random_device{}());
    inline static uniform_int_distribution<> dis;
public:
    int repeatedNTimes(vector<int>& nums) {
        dis.param(uniform_int_distribution<>::param_type(0, nums.size() - 1));
        int loc1, loc2;
        do {
            loc1 = dis(gen);
            loc2 = dis(gen);
        } while (loc1 == loc2 || nums[loc1] != nums[loc2]);
        return nums[loc1];
    }
};
```

#### Python

```python
from typing import List
from random import randint

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums) - 1
        while True:
            loc1 = randint(0, n)
            loc2 = randint(0, n)
            # print(loc1, loc2)
            if loc1 != loc2 and nums[loc1] == nums[loc2]:
                return nums[loc1]
```

#### Python.TLE

注意python random.randint包含左右区间端点，而random.randrange不包含右端点，所以下面代码在`[1, 2, 3, 3]`这种时候会因为永远无法随机到`3`而超时：

```python
from typing import List
from random import randrange

# THIS CANNOT ACCESS
class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums) - 1
        while True:
            loc1 = randrange(0, n)
            loc2 = randrange(0, n)
            if loc1 != loc2 and nums[loc1] == nums[loc2]:
                return nums[loc1]
```

#### Go

```go
package main

import "math/rand"

func repeatedNTimes(nums []int) int {
    n := len(nums)
    for true {
        l1 := rand.Intn(n)
        l2 := rand.Intn(n)
        if l1 != l2 && nums[l1] == nums[l2] {
            return nums[l1]
        }
    }
    return -1  // FAKE RETURN
}
```

#### Java

```java
import java.util.Random;

class Solution {
    public int repeatedNTimes(int[] nums) {
        Random random = new Random();
        int n = nums.length;
        while (true) {
            int l1 = random.nextInt(n);
            int l2 = random.nextInt(n);
            if (l1 != l2 && nums[l1] == nums[l2]) {
                return nums[l1];
            }
        }
    }
}
```

#### Rust

```rust
use rand::Rng;

impl Solution {
    pub fn repeated_n_times(mut nums: Vec<i32>) -> i32 {
        let mut rng = rand::thread_rng();  // 一定要为mut
        let n= nums.len();
        loop {
            let l1 = rng.gen_range(0..n);
            let l2 = rng.gen_range(0..n);
            if l1 != l2 && nums[l1] == nums[l2] {
                return nums[l1];
            }
        }
    }
}
```

# End

<center><font size="6px" face="Ink Free">The Real End, Thanks!</font></center>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156519064)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/02/LeetCode%200961.%E5%9C%A8%E9%95%BF%E5%BA%A62N%E7%9A%84%E6%95%B0%E7%BB%84%E4%B8%AD%E6%89%BE%E5%87%BA%E9%87%8D%E5%A4%8DN%E6%AC%A1%E7%9A%84%E5%85%83%E7%B4%A0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
