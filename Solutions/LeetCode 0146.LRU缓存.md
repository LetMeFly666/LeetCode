---
title: 146.LRU 缓存
date: 2023-09-24 15:22:17
tags: [题解, LeetCode, 中等, 设计, 哈希表, 哈希, map, 链表, 双向链表]
---

# 【LetMeFly】146.LRU 缓存：双向链表 + 哈希

力扣题目链接：[https://leetcode.cn/problems/lru-cache/](https://leetcode.cn/problems/lru-cache/)

<div class="title__3Vvk">请你设计并实现一个满足&nbsp; <a href="https://baike.baidu.com/item/LRU" target="_blank">LRU (最近最少使用) 缓存</a> 约束的数据结构。</div>

<div class="title__3Vvk">实现 <code>LRUCache</code> 类：</div>

<div class="original__bRMd">
<div>
<ul>
	<li><code>LRUCache(int capacity)</code> 以 <strong>正整数</strong> 作为容量&nbsp;<code>capacity</code> 初始化 LRU 缓存</li>
	<li><code>int get(int key)</code> 如果关键字 <code>key</code> 存在于缓存中，则返回关键字的值，否则返回 <code>-1</code> 。</li>
	<li><code>void put(int key, int value)</code>&nbsp;如果关键字&nbsp;<code>key</code> 已经存在，则变更其数据值&nbsp;<code>value</code> ；如果不存在，则向缓存中插入该组&nbsp;<code>key-value</code> 。如果插入操作导致关键字数量超过&nbsp;<code>capacity</code> ，则应该 <strong>逐出</strong> 最久未使用的关键字。</li>
</ul>

<p>函数 <code>get</code> 和 <code>put</code> 必须以 <code>O(1)</code> 的平均时间复杂度运行。</p>
</div>
</div>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
<strong>输出</strong>
[null, null, null, 1, null, -1, null, -1, 3, 4]

<strong>解释</strong>
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= capacity &lt;= 3000</code></li>
	<li><code>0 &lt;= key &lt;= 10000</code></li>
	<li><code>0 &lt;= value &lt;= 10<sup>5</sup></code></li>
	<li>最多调用 <code>2 * 10<sup>5</sup></code> 次 <code>get</code> 和 <code>put</code></li>
</ul>


    
## 方法一：双向链表 + 哈希

使用一个```双向链表```来作为LRU缓存。越靠近链表头部的节点使用时间越近。

使用一个哈希表，来实现从```key```映射到```节点```的功能。

为了能从节点映射到哈希表的键值```key```，在节点中也额外存储一份这个节点的```key```值：

```cpp
class LRU_Node {
public:
    LRU_Node* previous, *next;
    int key, value;
}
```

为了方便操作，可以在双向链表的首尾各添加一个空节点，以避免“是否为空”的特判。

**对于get操作：**

若哈希表中存有该```key```，则由哈希表映射出该节点，将该节点移动为链表的第一个节点，并返回节点的```value```。

若哈希表中不存在该```key```，直接返回```-1```。

**对于put操作：**

若哈希表中存有该```key```，则由哈希表映射出该节点，更新该节点的值，并将该节点移动为链表的第一个节点。

若哈希表中不存在该```key```，创建该节点并将其置于链表的第一个节点。若哈希表的容量大于最大容量，则由```tail.previous```得到最后一个节点，在哈希表中删除这个节点的```key```，并在链表中删除这个节点。

+ 时间复杂度：每次操作的时间复杂度都是$O(1)$
+ 空间复杂度$O(max(put, capacity))$

### AC代码

#### C++

```cpp
class LRU_Node {
public:
    LRU_Node* previous, *next;
    int key, value;
    LRU_Node(LRU_Node* previous, LRU_Node* next, int key, int value) {
        this->previous = previous;
        this->next = next;
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
private:
    LRU_Node* head, *tail;
    int capacity;
    unordered_map<int, LRU_Node*> ma;

    void refresh(int key, int value) {
        LRU_Node* thisNode = ma[key];
        thisNode->value = value;

        LRU_Node* previous = thisNode->previous, *next = thisNode->next;
        previous->next = next, next->previous = previous;
        
        thisNode->next = head->next;
        head->next = thisNode;
        thisNode->previous = head;
        thisNode->next->previous = thisNode;
    }
public:
    LRUCache(int capacity) {
        head = new LRU_Node(nullptr, nullptr, 0, 0);
        tail = new LRU_Node(head, nullptr, 0, 0);
        head->next = tail;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (ma.count(key)) {
            refresh(key, ma[key]->value);
            return ma[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (ma.count(key)) {
            refresh(key, value);
            return;
        }
        LRU_Node* thisNode = new LRU_Node(head, head->next, key, value);
        ma[key] = thisNode;
        head->next = thisNode, thisNode->next->previous = thisNode;
        if (ma.size() > capacity) {
            LRU_Node* toRemove = tail->previous;
            ma.erase(toRemove->key);
            toRemove->previous->next = tail;
            tail->previous = toRemove->previous;
        }
    }

    void debug() {
        cout << "Now size: " << ma.size() << ": [";
        LRU_Node* p = head->next;
        while (p != tail) {
            if (p != head->next) {
                cout << ", ";
            }
            cout << "(" << p->key << "|" << p->value << ")";
            p = p->next;
        }
        cout << "] | [";
        p = tail->previous;
        while (p != head) {
            if (p != tail->previous) {
                cout << ", ";
            }
            cout << "(" << p->key << "|" << p->value << ")";
            p = p->previous;
        }
        cout << "]" << endl;
    }
};
```

#### Python

```python
class LRU_Node:
    
    def __init__(self, previous, next, key, value):
        self.previous = previous
        self.next = next
        self.key = key
        self.value = value


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = LRU_Node(None, None, 0, 0)
        self.tail = LRU_Node(self.head, None, 0, 0)
        self.head.next = self.tail
        self.ma = dict()
    

    def move2first(self, thisNode: LRU_Node):
        thisNode.previous.next = thisNode.next
        thisNode.next.previous = thisNode.previous
        
        thisNode.previous = self.head
        thisNode.next = self.head.next
        self.head.next = thisNode
        thisNode.next.previous = thisNode


    def get(self, key: int) -> int:
        if key in self.ma:
            self.move2first(self.ma[key])
            return self.ma[key].value
        return -1


    def put(self, key: int, value: int) -> None:
        if key in self.ma:
            thisNode = self.ma[key]
            thisNode.value = value
            self.move2first(thisNode)
        else:
            thisNode = LRU_Node(self.head, self.head.next, key, value)
            self.ma[key] = thisNode
            self.head.next = thisNode
            thisNode.next.previous = thisNode
            if len(self.ma) > self.capacity:
                toRemove = self.tail.previous
                del self.ma[toRemove.key]
                toRemove.previous.next = self.tail
                self.tail.previous = toRemove.previous

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/24/LeetCode%200146.LRU%E7%BC%93%E5%AD%98/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133241877](https://letmefly.blog.csdn.net/article/details/133241877)
