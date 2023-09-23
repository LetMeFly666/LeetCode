---
title: 1993.树上的操作
date: 2023-09-23 09:56:02
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 设计, 哈希表, 模拟, 大模拟, DFS]
---

# 【LetMeFly】1993.树上的操作：大模拟

力扣题目链接：[https://leetcode.cn/problems/operations-on-tree/](https://leetcode.cn/problems/operations-on-tree/)

<p>给你一棵&nbsp;<code>n</code>&nbsp;个节点的树，编号从&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，以父节点数组&nbsp;<code>parent</code>&nbsp;的形式给出，其中&nbsp;<code>parent[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个节点的父节点。树的根节点为 <code>0</code>&nbsp;号节点，所以&nbsp;<code>parent[0] = -1</code>&nbsp;，因为它没有父节点。你想要设计一个数据结构实现树里面对节点的加锁，解锁和升级操作。</p>

<p>数据结构需要支持如下函数：</p>

<ul>
	<li><strong>Lock：</strong>指定用户给指定节点 <strong>上锁</strong>&nbsp;，上锁后其他用户将无法给同一节点上锁。只有当节点处于未上锁的状态下，才能进行上锁操作。</li>
	<li><strong>Unlock：</strong>指定用户给指定节点 <strong>解锁</strong>&nbsp;，只有当指定节点当前正被指定用户锁住时，才能执行该解锁操作。</li>
	<li><b>Upgrade：</b>指定用户给指定节点&nbsp;<strong>上锁</strong>&nbsp;，并且将该节点的所有子孙节点&nbsp;<strong>解锁</strong>&nbsp;。只有如下 3 个条件 <strong>全部</strong> 满足时才能执行升级操作：
	<ul>
		<li>指定节点当前状态为未上锁。</li>
		<li>指定节点至少有一个上锁状态的子孙节点（可以是 <strong>任意</strong>&nbsp;用户上锁的）。</li>
		<li>指定节点没有任何上锁的祖先节点。</li>
	</ul>
	</li>
</ul>

<p>请你实现&nbsp;<code>LockingTree</code>&nbsp;类：</p>

<ul>
	<li><code>LockingTree(int[] parent)</code>&nbsp;用父节点数组初始化数据结构。</li>
	<li><code>lock(int num, int user)</code> 如果&nbsp;id 为&nbsp;<code>user</code>&nbsp;的用户可以给节点&nbsp;<code>num</code>&nbsp;上锁，那么返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。如果可以执行此操作，节点&nbsp;<code>num</code>&nbsp;会被 id 为 <code>user</code>&nbsp;的用户 <strong>上锁</strong>&nbsp;。</li>
	<li><code>unlock(int num, int user)</code>&nbsp;如果 id 为 <code>user</code>&nbsp;的用户可以给节点 <code>num</code>&nbsp;解锁，那么返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。如果可以执行此操作，节点 <code>num</code>&nbsp;变为 <strong>未上锁</strong>&nbsp;状态。</li>
	<li><code>upgrade(int num, int user)</code>&nbsp;如果 id 为 <code>user</code>&nbsp;的用户可以给节点 <code>num</code>&nbsp;升级，那么返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。如果可以执行此操作，节点 <code>num</code>&nbsp;会被&nbsp;<strong>升级 </strong>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/07/29/untitled.png" style="width: 375px; height: 246px;"></p>

<pre><strong>输入：</strong>
["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"]
[[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]
<strong>输出：</strong>
[null, true, false, true, true, true, false]

<strong>解释：</strong>
LockingTree lockingTree = new LockingTree([-1, 0, 0, 1, 1, 2, 2]);
lockingTree.lock(2, 2);    // 返回 true ，因为节点 2 未上锁。
                           // 节点 2 被用户 2 上锁。
lockingTree.unlock(2, 3);  // 返回 false ，因为用户 3 无法解锁被用户 2 上锁的节点。
lockingTree.unlock(2, 2);  // 返回 true ，因为节点 2 之前被用户 2 上锁。
                           // 节点 2 现在变为未上锁状态。
lockingTree.lock(4, 5);    // 返回 true ，因为节点 4 未上锁。
                           // 节点 4 被用户 5 上锁。
lockingTree.upgrade(0, 1); // 返回 true ，因为节点 0 未上锁且至少有一个被上锁的子孙节点（节点 4）。
                           // 节点 0 被用户 1 上锁，节点 4 变为未上锁。
lockingTree.lock(0, 1);    // 返回 false ，因为节点 0 已经被上锁了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == parent.length</code></li>
	<li><code>2 &lt;= n &lt;= 2000</code></li>
	<li>对于&nbsp;<code>i != 0</code>&nbsp;，满足&nbsp;<code>0 &lt;= parent[i] &lt;= n - 1</code></li>
	<li><code>parent[0] == -1</code></li>
	<li><code>0 &lt;= num &lt;= n - 1</code></li>
	<li><code>1 &lt;= user &lt;= 10<sup>4</sup></code></li>
	<li><code>parent</code>&nbsp;表示一棵合法的树。</li>
	<li><code>lock</code>&nbsp;，<code>unlock</code>&nbsp;和&nbsp;<code>upgrade</code>&nbsp;的调用&nbsp;<strong>总共&nbsp;</strong>不超过&nbsp;<code>2000</code>&nbsp;次。</li>
</ul>


    
## 方法一：大模拟

使用三个数组：

+ ```parent[i]```表示```i```的parent
+ ```child[i]```表示```i```的孩子们
+ ```lockUser[i]```表示```i```的上锁者（0表示未上锁）

初始化：记录每个节点的child。

上锁：看```num```是否已经被锁，若无则上锁并返回```True```，否则直接返回```False```。

解锁：看```num```的上锁者是否恰好为```user```，若是则解锁并返回```True```，否则直接返回```False```。

更新：写两个函数，```hasLockedParent(num)```用来判断```num```的祖先节点中是否有锁、```hasLockedChildAndUnlock(num)```用来判断```num```的孩子节点中是否有锁（若有锁，则顺便解锁）。如果“```num```无锁”且“其祖先节点无锁”且“其后代节点中有锁”，则上锁该节点并返回```True```（判断后代节点是否有锁时若有锁则已经顺便解锁了）。

> 对于函数```hasLockedParent(num)```，其实只需要在```num```不为```-1```时不断将```num```赋值为```parent[num]```，若某次```lockUser[num]```不为```0```则返回```False```。
>
> 对于函数```hasLockedChildAndUnlock(num)```，为什么能做到“后代节点有锁的话顺便解锁”呢？因为只要后代中存在锁，函数就一定返回```True```，早晚就一定要解锁这个带锁的后代。这就是为什么先判断```num无锁```和```其祖先节点无锁```后再判断```其后代节点中有锁```。

+ 时间复杂度：初始化$O(len(parent))$，单次Lock、Unlock操作$O(1)$，单次Upgrade操作$O(len(parents))$。
+ 空间复杂度$O(len(parents))$

### AC代码

#### C++

```cpp
class LockingTree {
private:
    vector<int> lockUser;  // 谁锁的这个节点（0表示未锁）
    vector<int> parent;
    vector<vector<int>> child;

    bool hasLockedParent(int num) {
        while (parent[num] != -1) {
            num = parent[num];
            if (lockUser[num]) {
                return true;
            }
        }
        return false;
    }

    bool hasLockedChildAndUnlock(int num) {
        bool hasLockedChild = false;
        if (lockUser[num]) {
            lockUser[num] = 0;
            hasLockedChild = true;
        }
        for (int thisChild : child[num]) {
            hasLockedChild |= hasLockedChildAndUnlock(thisChild);
        }
        return hasLockedChild;
    }
    
public:
    LockingTree(vector<int>& parent): parent(parent) {
        lockUser = vector<int>(parent.size());
        child = vector<vector<int>>(parent.size());
        for (int i = 1; i < parent.size(); i++) {
            child[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (lockUser[num]) {
            return false;
        }
        lockUser[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (lockUser[num] == user) {
            lockUser[num] = 0;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (!lockUser[num] && !hasLockedParent(num) && hasLockedChildAndUnlock(num)) {
            lockUser[num] = user;
            return true;
        }
        return false;
    }
};
```

#### Python

```python
# from typing import List

class LockingTree:

    def __init__(self, parent: List[int]):
        self.parent = parent
        self.lockUser = [0] * len(parent)
        self.child = [[] for _ in range(len(parent))]
        for i in range(1, len(parent)):
            self.child[parent[i]].append(i)


    def lock(self, num: int, user: int) -> bool:
        if self.lockUser[num]:
            return False
        self.lockUser[num] = user
        return True


    def unlock(self, num: int, user: int) -> bool:
        if self.lockUser[num] == user:
            self.lockUser[num] = 0
            return True
        return False


    def upgrade(self, num: int, user: int) -> bool:
        if not self.lockUser[num] and not self.__hasLockedParent__(num) and self.__hasLockedChildAndUnlock__(num):
            self.lockUser[num] = user
            return True
        return False
    

    def __hasLockedParent__(self, num: int) -> bool:
        while self.parent[num] != -1:
            num = self.parent[num]
            if self.lockUser[num]:
                return True
        return False
    

    def __hasLockedChildAndUnlock__(self, num: int) -> bool:
        hasLockedChild = False
        if self.lockUser[num]:
            self.lockUser[num] = 0
            hasLockedChild = True
        for thisChild in self.child[num]:
            hasLockedChild |= self.__hasLockedChildAndUnlock__(thisChild)
        return hasLockedChild
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/09/23/LeetCode%201993.%E6%A0%91%E4%B8%8A%E7%9A%84%E6%93%8D%E4%BD%9C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133198960](https://letmefly.blog.csdn.net/article/details/133198960)
