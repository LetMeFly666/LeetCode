---
title: 705.设计哈希集合
date: 2024-04-14 09:51:01
tags: [题解, LeetCode, 简单, 设计, 数组, 哈希表, 链表, 哈希函数, 哈希, set]
---

# 【LetMeFly】705.设计哈希集合：很多人都是这样做的吧【逃】

力扣题目链接：[https://leetcode.cn/problems/design-hashset/](https://leetcode.cn/problems/design-hashset/)

<p>不使用任何内建的哈希表库设计一个哈希集合（HashSet）。</p>

<p>实现 <code>MyHashSet</code> 类：</p>

<ul>
	<li><code>void add(key)</code> 向哈希集合中插入值 <code>key</code> 。</li>
	<li><code>bool contains(key)</code> 返回哈希集合中是否存在这个值 <code>key</code> 。</li>
	<li><code>void remove(key)</code> 将给定值 <code>key</code> 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。</li>
</ul>
&nbsp;

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
<strong>输出：</strong>
[null, null, null, true, false, null, true, null, false]

<strong>解释：</strong>
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // 返回 True
myHashSet.contains(3); // 返回 False ，（未找到）
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // 返回 True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // 返回 False ，（已移除）</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= key &lt;= 10<sup>6</sup></code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>add</code>、<code>remove</code> 和 <code>contains</code></li>
</ul>


    
## 解题方法：只要数组足够大，就不会冲突

![力扣打卡1k天](https://cdn.letmefly.xyz/img/log/LeetCode/checkin1000days.jpg)

Easy题就按Easy的方法做好了。注意到这题数据范围是$0\leq key \leq 10^6$，因此只需要开辟一个大小为$10^6+1$的布尔类型的数组$hashset$：

+ $add$操作时将$hashset[key]$设置为$true$
+ $remove$操作时将$hashset[key]$设置为$false$
+ $contains$操作时返回$hashset[key]$的值

以上。

+ 时间复杂度：初始化$O(C)$，单次操作$O(1)$
+ 空间复杂度：初始化$O(C)$，单次操作$O(1)$

### AC代码

#### C++

```cpp
class MyHashSet {  // 1k天偷个懒
private:
    vector<bool> hashset;
public:
    MyHashSet() {
        hashset.resize(1e6 + 1);
    }
    
    void add(int key) {
        hashset[key] = true;
    }
    
    void remove(int key) {
        hashset[key] = false;
    }
    
    bool contains(int key) {
        return hashset[key];
    }
};
```

#### Python

```python
class MyHashSet:  # easy题很多人都是这么写的吧[逃]
    def __init__(self):
        self.hashset = [False] * 1_000_001

    def add(self, key: int) -> None:
        self.hashset[key] = True

    def remove(self, key: int) -> None:
        self.hashset[key] = False

    def contains(self, key: int) -> bool:
        return self.hashset[key]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/14/LeetCode%200705.%E8%AE%BE%E8%AE%A1%E5%93%88%E5%B8%8C%E9%9B%86%E5%90%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137738309](https://letmefly.blog.csdn.net/article/details/137738309)
