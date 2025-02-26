---
title: 1206.设计跳表：算法详解
date: 2025-02-26 10:16:23
tags: [题解, LeetCode, 困难, 设计, 链表, 跳表, 算法]
---

# 【LetMeFly】1206.设计跳表：算法详解

力扣题目链接：[https://leetcode.cn/problems/design-skiplist/](https://leetcode.cn/problems/design-skiplist/)

<p>不使用任何库函数，设计一个 <strong>跳表</strong> 。</p>

<p><strong>跳表</strong> 是在 <code>O(log(n))</code> 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。</p>

<p>例如，一个跳表包含 <code>[30, 40, 50, 60, 70, 90]</code> ，然后增加 <code>80</code>、<code>45</code> 到跳表中，以下图的方式操作：</p>

<p><img alt="" src="https://pic.leetcode.cn/1702370216-mKQcTt-1506_skiplist.gif" style="width: 500px; height: 173px;" /></p>

<!-- https://i-blog.csdnimg.cn/img_convert/b8474d69c822f6bdd0563ce459e03fc7.gif -->

<p>跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 <code>O(n)</code>。跳表的每一个操作的平均时间复杂度是 <code>O(log(n))</code>，空间复杂度是 <code>O(n)</code>。</p>

<p>了解更多 :&nbsp;<a href="https://oi-wiki.org/ds/skiplist/" target="_blank">https://oi-wiki.org/ds/skiplist/</a></p>

<p>在本题中，你的设计应该要包含这些函数：</p>

<ul>
	<li><code>bool search(int target)</code> : 返回target是否存在于跳表中。</li>
	<li><code>void add(int num)</code>:&nbsp;插入一个元素到跳表。</li>
	<li><code>bool erase(int num)</code>: 在跳表中删除一个值，如果&nbsp;<code>num</code>&nbsp;不存在，直接返回false. 如果存在多个&nbsp;<code>num</code>&nbsp;，删除其中任意一个即可。</li>
</ul>

<p>注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<b>输入</b>
["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase", "search"]
[[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
<strong>输出</strong>
[null, null, null, null, false, null, true, false, true, false]

<strong>解释</strong>
Skiplist skiplist = new Skiplist();
skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0);   // 返回 false
skiplist.add(4);
skiplist.search(1);   // 返回 true
skiplist.erase(0);    // 返回 false，0 不在跳表中
skiplist.erase(1);    // 返回 true
skiplist.search(1);   // 返回 false，1 已被擦除
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= num, target &lt;= 2 * 10<sup>4</sup></code></li>
	<li>调用<code>search</code>, <code>add</code>, &nbsp;<code>erase</code>操作次数不大于&nbsp;<code>5 * 10<sup>4</sup></code>&nbsp;</li>
</ul>


    
## 设计跳表

![跳表-静态.png](https://cdn.letmefly.xyz/img/blog/_LeetCode/skiplist.png)

<!-- ![跳表-静态.png](https://pic.leetcode.cn/1740540118-lgzwaB-000.png) -->
<!-- ![跳表-静态.png](https://i-blog.csdnimg.cn/img_convert/4d58d8acb36c5073044c17cc275ed9c8.png) -->

链表查询复杂度是$O(n)$，因为要从头到尾遍历。怎么解决这个问题？多几层链表(最下层level1是全链表)，上层链表元素少，先查上层（查一次就能**跳**过level1好多元素），再查下层，最终查到level1。

### 节点设计

对于一个节点（例如$50$），我们可以只创建一个$50$节点，并分别保留这个节点在level1到level3的下一个节点。

```cpp
class SkiplistNode {
public:
    int value;
    vector<SkiplistNode*> next;

    SkiplistNode(int val, int level): value(val), next(level) {}  // 一个节点一旦生成，level就是固定的
};
```

```cpp
class Skiplist {
private:
    SkiplistNode* head;  // 为了方便，统一添加头节点
    int level;  // 当前跳表层数，可依据实际数据范围确定
public:
    Skiplist() {
        head = new SkiplistNode(-1, MAX_LEVEL);  // 每层一旦出现，就一定需要head节点
        level = 0;
    }
    
    bool search(int target) {}
    
    void add(int num) {}
    
    bool erase(int num) {}
};
```

### 查询

+ 每一层的查询依据是：找到最后一个严格小于$target$的节点；
+ 上层到下层的依据是：同一个节点直接下移一层。

![跳表-查60.jpg](https://cdn.letmefly.xyz/img/blog/_LeetCode/skiplist-find60.jpg)

<!-- ![跳表-查60.jpg](https://pic.leetcode.cn/1740540201-IOeEAR-111.jpg) -->
<!-- ![跳表-查60.jpg](https://i-blog.csdnimg.cn/img_convert/e34976dd6cfafcad3f9f42fb7a9df2bd.jpeg) -->

例如上图要查询元素$60$：

1. 先从最上层(level4)开始查询，$30$是最后一个小于$60$的元素，在$30$停止，跳到level3的$30$
2. level3从$30$开始向右查询，$50$是最后一个小于$60$的元素，直接跳到$50$（可以发现最下层的$40$和$45$d都被跳过了），跳到level2的$50$
3. level2从$50$开始向右查询，最后一个小于$60$的节点就是$50$，停止并跳到level1的$50$
4. level1从$50$开始向右查询，最后一个小于$60$的节点就是$50$，停止。

最终停止的节点是level1的$50$。

**注意：**

1. 最终一定停止在level1
2. 每一层都是在最后一个严格小于target的节点停止并移动到下层(如有)
3. 所查询节点就是最终停止到的节点的右边相邻节点

```cpp
bool search(int target) {
	SkiplistNode* p = head;  // 从头节点开始
    for (int i = level - 1; i >= 0; i--) {  // 从上层到下层
        while (p->next[i] && p->next[i]->value < target) {  // 每一层找到最后一个严格小于target的节点
            p = p->next[i];
        }
    }
    p = p->next[0];  // 最终停止到了level1的50，50在level1的next就是待查找的60
    return p && p->value == target;
}
```

### 插入

新增一个节点，这个节点都要在哪些层出现呢？直接`rand`呗。每个节点都要在最下层出现，可以定义一个全局概率$P$，表示这个节点有$P$的概率在上一层再出现一次。

对于本题，要求复杂度$\log_2 n$所以可取$P=\frac12$；最多50000次操作，$\log_2 50000\approx 15.6$，因此可取最大层数$15$。

```cpp
int randLevel() {
    int ans = 1;
    while (ans < MAX_LEVEL && rand() < p) {
        ans++;
    }
    return ans;
}
```

对于新增节点$num$，假设随机出来确定它要在$level_1$到$level_{newLevel}$层出现，那么就可以创建一个大小为$newLevel$的$update$数组，其中$update[i]=p$代表$level_{i+1}$层$p$元素的$next$需要修改为指向新节点。

确定$update$数组的方法和查询类似，每层找到最后一个严格小于$num$的节点即可。

```cpp
void add(int num) {
    int newLevel = randLevel();
    vector<SkiplistNode*> update(newLevel, head);  // 默认值为head
    SkiplistNode* p = head;
    for (int i = level - 1; i >= 0; i--) {
        while (p->next[i] && p->next[i]->value < num) {  // 每层找最后一个严格小于num的节点
            p = p->next[i];
        }
        if (i < newLevel) {  // 只有低newLevel层需要插入p节点
            update[i] = p;
        }
    }

    level = max(level, newLevel);  // 更新跳表最大层数
    SkiplistNode* newNode = new SkiplistNode(num, newLevel);
    for (int i = 0; i < newLevel; i++) {  // 低newLevel层每层插入新节点
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
    }
}
```

### 删除

删除和新增类似，找到每层需要更新next的节点，更新next并更新层数。

与插入不同的是，在开始遍历前不知道$num$一共有几层，所以我们可以初始化$update$大小为当前跳表的总层数。在真正删除节点时从最下层往最上层删除，一旦update[i]的next不是目标节点了就直接break。

注意，若$num$本身就不再跳表中就不要误删其他元素了。

删除完目标节点后，从上到下遍历确定是否有空层（head的next直接为null）需要删除即可。

```cpp
bool erase(int num) {
    vector<SkiplistNode*> update(level);  // 其实并不需要初始值
    SkiplistNode* p = head;
    for (int i = level - 1; i >= 0; i--) {
        while (p->next[i] && p->next[i]->value < num) {  // 每层找最后一个严格小于num的节点
            p = p->next[i];
        }
        update[i] = p;
    }
    
    p = p->next[0];  // 目标节点
    if (!p || p->value != num) {  // num在跳表中根本不存在
        return false;
    }
    
    for (int i = 0; i < level; i++) {  // 从下往上开始删除目标节点
        if (update[i]->next[i] != p) {
            break;
        }
        update[i]->next[i] = p->next[i];
    }
    delete p;

    while (level > 0 && !head->next[level - 1]) {  // “移除”空层
        level--;
    }
    return true;
}
```

## 时空复杂度

+ 时间复杂度：单次操作$O(\log n)$
+ 空间复杂度$O(n)$

## AC代码

### C++

```cpp
const int MAX_LEVEL = 15;
const double p = 0.5;

class SkiplistNode {
public:
    int value;
    vector<SkiplistNode*> next;

    SkiplistNode(int val, int level): value(val), next(level) {}  // 一个节点一旦生成，level就是固定的
};

class Skiplist {
private:
    SkiplistNode* head;
    int level;

    int randLevel() {
        int ans = 1;
        while (ans < MAX_LEVEL && rand() < p) {
            ans++;
        }
        return ans;
    }
public:
    Skiplist() {
        head = new SkiplistNode(-1, MAX_LEVEL);  // 每层一旦出现，就一定需要head节点
        level = 0;
    }
    
    bool search(int target) {
        SkiplistNode* p = head;
        for (int i = level - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < target) {
                p = p->next[i];
            }
        }
        p = p->next[0];
        return p && p->value == target;
    }
    
    void add(int num) {
        int newLevel = randLevel();
        vector<SkiplistNode*> update(newLevel, head);
        SkiplistNode* p = head;
        for (int i = level - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < num) {
                p = p->next[i];
            }
            if (i < newLevel) {
                update[i] = p;
            }
        }

        level = max(level, newLevel);
        SkiplistNode* newNode = new SkiplistNode(num, newLevel);
        for (int i = 0; i < newLevel; i++) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }
    
    bool erase(int num) {
        vector<SkiplistNode*> update(level);
        SkiplistNode* p = head;
        for (int i = level - 1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->value < num) {
                p = p->next[i];
            }
            update[i] = p;
        }
        
        p = p->next[0];
        if (!p || p->value != num) {
            return false;
        }
        
        for (int i = 0; i < level; i++) {
            if (update[i]->next[i] != p) {
                break;
            }
            update[i]->next[i] = p->next[i];
        }
        delete p;

        while (level > 0 && !head->next[level - 1]) {
            level--;
        }
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
```

### Python

```python
from typing import List, Any
import random


MAX_LEVEL = 15
P = 0.5

class SkiplistNode:
    def __init__(self, v: int, level: int):
        self.value = v
        self.next: List[SkiplistNode] = [None] * level

class Skiplist:
    def __init__(self):
        self.head = SkiplistNode(-1, MAX_LEVEL)
        self.level = 0
    
    def __randLevel(self):
        ans = 1
        while ans < MAX_LEVEL and random.random() < P:
            ans += 1
        return ans

    def search(self, target: int) -> bool:
        p = self.head
        for i in range(self.level - 1, -1, -1):
            while p.next[i] and p.next[i].value < target:
                p = p.next[i]
        p = p.next[0]
        # return p and p.value == target  # 不可！p为None的化这一行会return None而不是False！
        return p is not None and p.value == target

    def add(self, num: int) -> None:
        newLevel = self.__randLevel()
        update = [self.head] * newLevel
        p = self.head
        for i in range(self.level - 1, -1, -1):
            while p.next[i] and p.next[i].value < num:
                p = p.next[i]
            if i < newLevel:
                update[i] = p
        
        self.level = max(self.level, newLevel)
        newNode = SkiplistNode(num, newLevel)
        for i in range(newLevel):
            newNode.next[i] = update[i].next[i]
            update[i].next[i] = newNode

    def erase(self, num: int) -> bool:
        update: List[SkiplistNode | Any] = [None] * self.level
        p = self.head
        for i in range(self.level - 1, -1, -1):
            while p.next[i] and p.next[i].value < num:
                p = p.next[i]
            update[i] = p
        
        p = p.next[0]
        if not p or p.value != num:
            return False
        
        for i in range(self.level):
            if update[i].next[i] != p:
                break
            update[i].next[i] = p.next[i]
        while self.level > 0 and not self.head.next[self.level - 1]:
            self.level -= 1
        return True


# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145873636)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/26/LeetCode%201206.%E8%AE%BE%E8%AE%A1%E8%B7%B3%E8%A1%A8/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
