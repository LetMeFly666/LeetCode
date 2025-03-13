---
title: 706.设计哈希映射
date: 2024-04-15 17:16:03
tags: [题解, LeetCode, 简单, 设计, 数组, 哈希表, 链表, 哈希函数, 哈希, map]
categories: [题解, LeetCode]
---

# 【LetMeFly】706.设计哈希映射：使用数组实现好了

力扣题目链接：[https://leetcode.cn/problems/design-hashmap/](https://leetcode.cn/problems/design-hashmap/)

<p>不使用任何内建的哈希表库设计一个哈希映射（HashMap）。</p>

<p>实现 <code>MyHashMap</code> 类：</p>

<ul>
	<li><code>MyHashMap()</code> 用空映射初始化对象</li>
	<li><code>void put(int key, int value)</code> 向 HashMap 插入一个键值对 <code>(key, value)</code> 。如果 <code>key</code> 已经存在于映射中，则更新其对应的值 <code>value</code> 。</li>
	<li><code>int get(int key)</code> 返回特定的 <code>key</code> 所映射的 <code>value</code> ；如果映射中不包含 <code>key</code> 的映射，返回 <code>-1</code> 。</li>
	<li><code>void remove(key)</code> 如果映射中存在 <code>key</code> 的映射，则移除 <code>key</code> 和它所对应的 <code>value</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>：
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
<strong>输出</strong>：
[null, null, null, 1, -1, null, 1, null, -1]

<strong>解释</strong>：
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= key, value &lt;= 10<sup>6</sup></code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>put</code>、<code>get</code> 和 <code>remove</code> 方法</li>
</ul>


    
## 解题方法：使用数组作为哈希表

本题数据范围$0\leq key \leq 10^6$，因此我们可以开辟一个大小为$10^6+1$的整数数组，初始值全部为$-1$。

+ put操作：令$hashMap[key] = val$
+ get操作：返回$hashMap[key]$
+ remove操作：令$hashMap[key] = -1$

以上。

+ 时间复杂度：$O(1)$
+ 空间复杂度：初始化$O(C)$，单次操作$O(1)$，其中$C=10^6+1$

若$key$的范围过大，可以使用取模的方式。例如开辟一个大小为$769$的数组$hashMap2$，$hashMap2[key \mod 769]$存放所有$key\mod 769$的$key$和$val$。

### AC代码

#### C++

```cpp
class MyHashMap {
private:
    vector<int> hashMap;
public:
    MyHashMap() {
        hashMap.resize(1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    int get(int key) {
        return hashMap[key];
    }
    
    void remove(int key) {
        hashMap[key] = -1;
    }
};

```

#### Python

```python
class MyHashMap:
    def __init__(self):
        self.hashMap = [-1] * 1_000_001

    def put(self, key: int, value: int) -> None:
        self.hashMap[key] = value

    def get(self, key: int) -> int:
        return self.hashMap[key]

    def remove(self, key: int) -> None:
        self.hashMap[key] = -1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/15/LeetCode%200706.%E8%AE%BE%E8%AE%A1%E5%93%88%E5%B8%8C%E6%98%A0%E5%B0%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137788441](https://letmefly.blog.csdn.net/article/details/137788441)
