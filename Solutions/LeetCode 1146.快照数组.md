---
title: 1146.快照数组
date: 2024-04-26 11:20:05
tags: [题解, LeetCode, 中等, 设计, 数组, 哈希表, 二分查找]
categories: [题解, LeetCode]
---

# 【LetMeFly】1146.快照数组：二分查找

力扣题目链接：[https://leetcode.cn/problems/snapshot-array/](https://leetcode.cn/problems/snapshot-array/)

<p>实现支持下列接口的「快照数组」-&nbsp;SnapshotArray：</p>

<ul>
	<li><code>SnapshotArray(int length)</code>&nbsp;- 初始化一个与指定长度相等的 类数组 的数据结构。<strong>初始时，每个元素都等于</strong><strong>&nbsp;0</strong>。</li>
	<li><code>void set(index, val)</code>&nbsp;- 会将指定索引&nbsp;<code>index</code>&nbsp;处的元素设置为&nbsp;<code>val</code>。</li>
	<li><code>int snap()</code>&nbsp;- 获取该数组的快照，并返回快照的编号&nbsp;<code>snap_id</code>（快照号是调用&nbsp;<code>snap()</code>&nbsp;的总次数减去&nbsp;<code>1</code>）。</li>
	<li><code>int get(index, snap_id)</code>&nbsp;- 根据指定的&nbsp;<code>snap_id</code>&nbsp;选择快照，并返回该快照指定索引 <code>index</code>&nbsp;的值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[&quot;SnapshotArray&quot;,&quot;set&quot;,&quot;snap&quot;,&quot;set&quot;,&quot;get&quot;]
     [[3],[0,5],[],[0,6],[0,0]]
<strong>输出：</strong>[null,null,0,null,5]
<strong>解释：
</strong>SnapshotArray snapshotArr = new SnapshotArray(3); // 初始化一个长度为 3 的快照数组
snapshotArr.set(0,5);  // 令 array[0] = 5
snapshotArr.snap();  // 获取快照，返回 snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= length&nbsp;&lt;= 50000</code></li>
	<li>题目最多进行<code>50000</code> 次<code>set</code>，<code>snap</code>，和&nbsp;<code>get</code>的调用 。</li>
	<li><code>0 &lt;= index&nbsp;&lt;&nbsp;length</code></li>
	<li><code>0 &lt;=&nbsp;snap_id &lt;&nbsp;</code>我们调用&nbsp;<code>snap()</code>&nbsp;的总次数</li>
	<li><code>0 &lt;=&nbsp;val &lt;= 10^9</code></li>
</ul>


    
## 解题方法：二分查找

我们只需要开辟一个大小为```length```的数组```a```，其中```a[i]```记录下标```i```的每个历史版本```[[快照编号, 值], ...]```。

这样，在修改元素时，只需要往```a[index]```数组中添加一个```(snapID, val)```，求```a[index]```的```snapId```版本时，只需要二分查找出```a[index]```对应版本时的值即可。

+ 时间复杂度：初始化$O(length)$，设置值$O(1)$，快照$O(1)$，查询$O(\log S)$其中$S$是查询时对应元素的赋值次数
+ 空间复杂度$O(length + S2)$，其中$S2$是```set```操作总次数

### AC代码

#### C++

```cpp
class SnapshotArray {
private:
    vector<vector<pair<int, int>>> a;  // a[i]: i的每个历史版本[[快照编号, 值], ...]
    int snapId;

public:
    SnapshotArray(int length) : a(length), snapId(0) {}
    
    void set(int index, int val) {
        a[index].push_back({snapId, val});
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int, int>>::iterator it = upper_bound(a[index].begin(), a[index].end(), pair<int, int>{snap_id + 1, -1});
        return it == a[index].begin() ? 0 : prev(it)->second;
    }
};
```

#### Python

```python
# from bisect import bisect_right

class SnapshotArray:
    def __init__(self, length: int):
        self.a = [[] for _ in range(length)]
        self.snapId = 0

    def set(self, index: int, val: int) -> None:
        self.a[index].append((self.snapId, val))

    def snap(self) -> int:
        self.snapId += 1
        return self.snapId - 1

    def get(self, index: int, snap_id: int) -> int:
        it = bisect_right(self.a[index], (snap_id + 1, -1))
        return 0 if not it else self.a[index][it - 1][1]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/26/LeetCode%201146.%E5%BF%AB%E7%85%A7%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138214080](https://letmefly.blog.csdn.net/article/details/138214080)
