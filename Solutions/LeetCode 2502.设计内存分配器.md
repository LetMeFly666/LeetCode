---
title: 2502.设计内存分配器：暴力模拟
date: 2025-02-25 18:37:22
tags: [题解, LeetCode, 中等, 设计, 数组, 哈希表, 模拟, 暴力]
---

# 【LetMeFly】2502.设计内存分配器：暴力模拟

力扣题目链接：[https://leetcode.cn/problems/design-memory-allocator/](https://leetcode.cn/problems/design-memory-allocator/)

<p>给你一个整数 <code>n</code> ，表示下标从 <strong>0</strong> 开始的内存数组的大小。所有内存单元开始都是空闲的。</p>

<p>请你设计一个具备以下功能的内存分配器：</p>

<ol>
	<li><strong>分配 </strong>一块大小为 <code>size</code> 的连续空闲内存单元并赋 id <code>mID</code> 。</li>
	<li><strong>释放</strong> 给定 id <code>mID</code> 对应的所有内存单元。</li>
</ol>

<p><strong>注意：</strong></p>

<ul>
	<li>多个块可以被分配到同一个 <code>mID</code> 。</li>
	<li>你必须释放 <code>mID</code> 对应的所有内存单元，即便这些内存单元被分配在不同的块中。</li>
</ul>

<p>实现 <code>Allocator</code> 类：</p>

<ul>
	<li><code>Allocator(int n)</code> 使用一个大小为 <code>n</code> 的内存数组初始化 <code>Allocator</code> 对象。</li>
	<li><code>int allocate(int size, int mID)</code> 找出大小为 <code>size</code> 个连续空闲内存单元且位于&nbsp; <strong>最左侧</strong> 的块，分配并赋 id <code>mID</code> 。返回块的第一个下标。如果不存在这样的块，返回 <code>-1</code> 。</li>
	<li><code>int freeMemory(int mID)</code> 释放 id <code>mID</code> 对应的所有内存单元。返回释放的内存单元数目。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["Allocator", "allocate", "allocate", "allocate", "freeMemory", "allocate", "allocate", "allocate", "freeMemory", "allocate", "freeMemory"]
[[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
<strong>输出</strong>
[null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]

<strong>解释</strong>
Allocator loc = new Allocator(10); // 初始化一个大小为 10 的内存数组，所有内存单元都是空闲的。
loc.allocate(1, 1); // 最左侧的块的第一个下标是 0 。内存数组变为 [<strong>1</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 0 。
loc.allocate(1, 2); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,<strong>2</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 1 。
loc.allocate(1, 3); // 最左侧的块的第一个下标是 2 。内存数组变为 [1,2,<strong>3</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 2 。
loc.freeMemory(2); // 释放 mID 为 2 的所有内存单元。内存数组变为 [1,<u> </u>,<strong>3</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>,<u> </u>] 。返回 1 ，因为只有 1 个 mID 为 2 的内存单元。
loc.allocate(3, 4); // 最左侧的块的第一个下标是 3 。内存数组变为 [1,<u> </u>,3,<strong>4</strong>,<strong>4</strong>,<strong>4</strong>,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 3 。
loc.allocate(1, 1); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,<strong>1</strong>,3,4,4,4,<u> </u>,<u> </u>,<u> </u>,<u> </u>]。返回 1 。
loc.allocate(1, 1); // 最左侧的块的第一个下标是 6 。内存数组变为 [1,1,3,4,4,4,<strong>1</strong>,<u> </u>,<u> </u>,<u> </u>]。返回 6 。
loc.freeMemory(1); // 释放 mID 为 1 的所有内存单元。内存数组变为 [<u> </u>,<u> </u>,3,4,4,4,<u><strong> </strong></u>,<u> </u>,<u> </u>,<u> </u>] 。返回 3 ，因为有 3 个 mID 为 1 的内存单元。
loc.allocate(10, 2); // 无法找出长度为 10 个连续空闲内存单元的空闲块，所有返回 -1 。
loc.freeMemory(7); // 释放 mID 为 7 的所有内存单元。内存数组保持原状，因为不存在 mID 为 7 的内存单元。返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, size, mID &lt;= 1000</code></li>
	<li>最多调用 <code>allocate</code> 和 <code>free</code> 方法 <code>1000</code> 次</li>
</ul>


    
## 解题方法：暴力模拟

看题过程中一直在想怎么设计，结果一看数据量只有1000，所以决定暴力模拟了。直接使用大小为$n$的数据模拟内存数组。

+ 初始化：每个内存单元都为$0$
+ 分配：按下标从小到大遍历内存单元，一旦出现连续$size$个为$0$的内存单元，就将这些内存单元分配给$mID$；若分配失败则返回$-1$
+ 释放：遍历内存单元，统计值为$mID$的内存单元的个数并将它们标记为$0$

以上。

+ 时间复杂度：初始化$O(n)$，单次分配$O(n)$，单次释放$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-25 16:18:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-25 16:30:51
 */
class Allocator {
private:
    vector<int> v;
    int n;
public:
    Allocator(int n): n(n), v(n) {}
    
    int allocate(int size, int mID) {
        for (int l = -1, r = 0, cnt = 0; r < n; r++) {
            if (v[r]) {
                cnt = 0;
                l = r;
                continue;
            }
            cnt++;
            if (cnt == size) {
                while (++l <= r) {
                    v[l] = mID;
                }
                return r - size + 1;
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int ans = 0;
        for (int &t : v) {
            if (t == mID) {
                ans++;
                t = 0;
            }
        }
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-25 16:19:05
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-25 16:34:50
'''
class Allocator:

    def __init__(self, n: int):
        self.v = [None] * n

    def allocate(self, size: int, mID: int) -> int:
        l, cnt = -1, 0
        for r in range(len(self.v)):
            if self.v[r]:
                l, cnt = r, 0
                continue
            cnt += 1
            if cnt == size:
                for i in range(l + 1, r + 1):
                    self.v[i] = mID
                return l + 1
        return -1

    def freeMemory(self, mID: int) -> int:
        ans = 0
        for i in range(len(self.v)):
            if self.v[i] == mID:
                self.v[i] = 0
                ans += 1
        return ans


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-25 16:19:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-25 16:38:15
 */
class Allocator {
    private int[] v;
    private int n;

    public Allocator(int n) {
        v = new int[n];
        this.n = n;
    }
    
    public int allocate(int size, int mID) {
        for (int l = -1, r = 0, cnt = 0; r < n; r++) {
            if (v[r] != 0) {
                cnt = 0;
                l = r;
                continue;
            }
            cnt++;
            if (cnt == size) {
                while (++l <= r) {
                    v[l] = mID;
                }
                return r - size + 1;
            }
        }
        return -1;
    }
    
    public int freeMemory(int mID) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == mID) {
                ans++;
                v[i] = 0;
            }
        }
        return ans;
    }
}

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator obj = new Allocator(n);
 * int param_1 = obj.allocate(size,mID);
 * int param_2 = obj.freeMemory(mID);
 */
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-25 16:19:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-25 16:45:09
 */
package main

type Allocator struct {
    v []int
}


func Constructor(n int) Allocator {
    return Allocator{
        v: make([]int, n),
    }
}


func (this *Allocator) Allocate(size int, mID int) int {
    for r, cnt := 0, 0; r < len(this.v); r++ {
        if this.v[r] != 0 {
            cnt = 0
            continue
        }
        cnt++
        if (cnt == size) {
            for ; size > 0; size, r = size - 1, r - 1 {
                this.v[r] = mID
            }
            return r + 1
        }
    }
    return -1
}


func (this *Allocator) FreeMemory(mID int) (ans int) {
    for i, v := range this.v {
        if v == mID {
            ans++
            this.v[i] = 0
        }
    }
    return
}


/**
 * Your Allocator object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Allocate(size,mID);
 * param_2 := obj.FreeMemory(mID);
 */
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145861823)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/25/LeetCode%202502.%E8%AE%BE%E8%AE%A1%E5%86%85%E5%AD%98%E5%88%86%E9%85%8D%E5%99%A8/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
