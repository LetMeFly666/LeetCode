---
title: 707.设计链表
date: 2022-09-23 13:28:46
tags: [题解, LeetCode, 中等, 设计, 链表]
---

# 【LetMeFly】707.设计链表：C++小详解，万字小长文：分别借助和不借助STL解决

力扣题目链接：[https://leetcode.cn/problems/design-linked-list/](https://leetcode.cn/problems/design-linked-list/)

<p>设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：<code>val</code>&nbsp;和&nbsp;<code>next</code>。<code>val</code>&nbsp;是当前节点的值，<code>next</code>&nbsp;是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性&nbsp;<code>prev</code>&nbsp;以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。</p>

<p>在链表类中实现这些功能：</p>

<ul>
	<li>get(index)：获取链表中第&nbsp;<code>index</code>&nbsp;个节点的值。如果索引无效，则返回<code>-1</code>。</li>
	<li>addAtHead(val)：在链表的第一个元素之前添加一个值为&nbsp;<code>val</code>&nbsp;的节点。插入后，新节点将成为链表的第一个节点。</li>
	<li>addAtTail(val)：将值为&nbsp;<code>val</code> 的节点追加到链表的最后一个元素。</li>
	<li>addAtIndex(index,val)：在链表中的第&nbsp;<code>index</code>&nbsp;个节点之前添加值为&nbsp;<code>val</code>&nbsp; 的节点。如果&nbsp;<code>index</code>&nbsp;等于链表的长度，则该节点将附加到链表的末尾。如果 <code>index</code> 大于链表长度，则不会插入节点。如果<code>index</code>小于0，则在头部插入节点。</li>
	<li>deleteAtIndex(index)：如果索引&nbsp;<code>index</code> 有效，则删除链表中的第&nbsp;<code>index</code> 个节点。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-&gt; 2-&gt; 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-&gt; 3
linkedList.get(1);            //返回3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>所有<code>val</code>值都在&nbsp;<code>[1, 1000]</code>&nbsp;之内。</li>
	<li>操作次数将在&nbsp;&nbsp;<code>[1, 1000]</code>&nbsp;之内。</li>
	<li>请不要使用内置的 LinkedList 库。</li>
</ul>


    
## 方法一：借助STL解决

如果借助STL解决，那么就会比较简单，因为STL中的list已经实现了大部分功能，所需要的就是特判一下index，按照题意对输入的index进行相应的操作。

**额外功能：**

为了方便实现，我们自定义一个“获取链表第index个元素的迭代器”的函数（因为STL的list不支持随机访问，因此需要从头节点开始逐渐往后遍历）

```cpp
inline list<int>::iterator getIndexIterator(int index) {
    list<int>::iterator it = li.begin();
    while (index--) {
        it++;
    }
    return it;
}
```

这个函数不判断输入是否合法

**初始化：**

无需进行任何操作

**取元素：**

题目中说，“如果索引无效，则返回-1”

因此首先判断index是否合法，不合法则返回-1，合法则直接返回迭代器“getIndexIterator(index)”所指的元素

```cpp
int get(int index) {
    if (index < 0 || index >= li.size())
        return -1;
    return *getIndexIterator(index);
}
```

**往头部插入元素：**

直接调用现有函数“push_front(int val)”

```cpp
void addAtHead(int val) {
    li.push_front(val);
}
```

**往尾部插入元素：**

直接调用现有函数“push_back(int val)”

```cpp
void addAtTail(int val) {
    li.push_back(val);
}
```

**往中间位置插入元素：**

按照题目要求：

+ 如果index小于零，则插入到头部（index=0）
+ 如果index大于链表长度，则不进行任何操作（return）
+ 否则插入到对应位置（迭代器，可由getIndexIterator获取）

```cpp
void addAtIndex(int index, int val) {
    if (index < 0)
        index = 0;
    if (index > li.size())
        return;
    li.insert(getIndexIterator(index), val);
}
```

**删除元素：**

按照题目要求：

+ 如果index有效，则删除（直接调用erase即可）
+ index无效，则不操作

```cpp
void deleteAtIndex(int index) {
    if (index >= li.size())
        return;
    li.erase(getIndexIterator(index));
}
```


+ 时间复杂度：初始化$O(1)$，插入/删除/获取元素$O(index)$
+ 空间复杂度$O(n)$，其中$n$取决于某时刻链表中最多的节点个数

### AC代码

#### C++

```cpp
class MyLinkedList {
private:
    list<int> li;

    inline list<int>::iterator getIndexIterator(int index) {
        list<int>::iterator it = li.begin();
        while (index--) {
            it++;
        }
        return it;
    }

    inline void debugList() {
        for (auto t : li) {
            cout << t << ", ";
        }
        puts("");
    }
public:
    MyLinkedList() {

    }
    
    int get(int index) {
        if (index < 0 || index >= li.size())
            return -1;
        return *getIndexIterator(index);
    }
    
    void addAtHead(int val) {
        li.push_front(val);
    }
    
    void addAtTail(int val) {
        li.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0)
            index = 0;
        if (index > li.size())
            return;
        li.insert(getIndexIterator(index), val);
    }
    
    void deleteAtIndex(int index) {
        if (index >= li.size())
            return;
        li.erase(getIndexIterator(index));
    }
};
```

## 方法二：不借助STL解决

如果不借助STL解决，那么可以自定义一个结构体，来存放某个节点。

之后手动实现各种操作。

**额外功能：**

定义结构体，来存放某个节点。

我们需要存放：

1. 节点的值
2. 节点的下一个节点的指针

```cpp
struct __LetMeFly_ListNode {
    int val;
    __LetMeFly_ListNode* next;

    __LetMeFly_ListNode() : next(nullptr) {}  // 默认下一个节点为NULL
    __LetMeFly_ListNode(int val) : val(val), next(nullptr) {}
};
```

为了方便实现，我们自定义一个“获取链表第index个元素的指针”的函数（从头节点开始逐渐往后遍历）

```cpp
__LetMeFly_ListNode* getIndexIterator(int index) {  // 无脑计算，不验证合法性
    __LetMeFly_ListNode* p = head->next;
    while (index--) {
        p = p->next;
    }
    return p;
}
```

**初始化：**

初始化的时候，我们需要初始化头节点（为了方便，我们额外开辟一个不存放任何值的头节点）

同时，初始化节点长度为0

```cpp
MyLinkedList() {
    head = new __LetMeFly_ListNode;
    size = 0;
}
```

**取元素：**

题目中说，“如果索引无效，则返回-1”

因此首先判断index是否合法，不合法则返回-1，合法则直接返回节点指针“getIndexIterator(index)”所指的节点的元素

```cpp
int get(int index) {
    if (index < 0 || index >= size) {
        return -1;
    }
    return getIndexIterator(index)->val;
}
```

**往头部插入元素：**

首先获取原始的第一个节点：```head->next```（是因为头部多开辟了一个不存放任何值的节点）

然后将头部节点的```next```指向新```new```出来的节点

并将新节点的```next```指向原始的第一个节点

最后更新size，将size加一

```cpp
void addAtHead(int val) {
    __LetMeFly_ListNode* secondNode = head->next;
    head->next = new __LetMeFly_ListNode(val);
    head->next->next = secondNode;
    size++;
}
```

**往尾部插入元素：**

往尾部插入元素包括：

1. 获取原始尾部元素
2. 将原始尾部元素的next指向新节点
3. 链表节点个数size加一

需要注意的是，尾部元素的下标是“节点个数 - 1”

因此需要特判，如果原始链表为空，节点个数减一就变成了负数。

其实，原始链表为空的时候，“往链表尾部插入一个元素” 等价于 “往链表头部插入一个元素”

```cpp
void addAtTail(int val) {
    if (size == 0) {
        return addAtHead(val);
    }
    getIndexIterator(size - 1)->next = new __LetMeFly_ListNode(val);
    size++;
}
```

**往中间位置插入元素：**

按照题目要求：

+ 如果index小于零，则插入到头部（index=0时也是插入到头部），直接调用刚刚写好的“addAtHead”即可
+ 如果index大于链表长度，则不进行任何操作（return）
+ 否则插入到对应位置。对应位置又分为两种：
   1. index等于链表长度，就插入到链表尾部（直接调用刚刚写好的“addAtTail”即可）
   2. 否则，通过“getIndexIterator”获取要插入元素上一个元素的位置，记录上一个元素的下一个元素，将上一个元素的指向新new出来的节点，并将新节点的next指向原本的“上一个元素的下一个元素”，更新链表中节点个数size

```cpp
void addAtIndex(int index, int val) {
    if (index <= 0) {
        index = 0;
        addAtHead(val);
        return;
    }
    if (index > size)
        return;
    if (index == size) {
        addAtTail(val);
        return;
    }
    __LetMeFly_ListNode* lastNode = getIndexIterator(index - 1);
    __LetMeFly_ListNode* nextNode = lastNode->next;
    lastNode->next = new __LetMeFly_ListNode(val);
    lastNode->next->next = nextNode;
    size++;
}
```

**删除元素：**

按照题目要求，如果index有效，才进行删除操作：

+ 如果index为0，则是删除头部元素：
   + 记录原始的第二个元素（可能是空指针，但是没关系）
   + 删除第一个元素
   + 将链表中的头节点的next指向第二个元素
+ 否则：
   + 通过“getIndexIterator”获取待删除元素的前一个节点
   + 记录前一个节点的下一个节点的下一个节点
   + 删除前一个节点的下一个节点
   + 前一个节点的next指向原始的“下一个节点的下一个节点”

上述两种操作无需担心越界问题，因为已经判断了index有效。

无论怎样，只要index有效，就要更新size（size--）

```cpp
void deleteAtIndex(int index) {
    if (index >= 0 && index < size) {
        if (index == 0) {
            __LetMeFly_ListNode* nextNode = head->next->next;
            delete head->next;
            head->next = nextNode;
        }
        else {
            __LetMeFly_ListNode* lastNode = getIndexIterator(index - 1);
            __LetMeFly_ListNode* nextNode = lastNode->next->next;
            delete lastNode->next;
            lastNode->next = nextNode;
        }
        size--;
    }
}
```


+ 时间复杂度：初始化$O(1)$，插入/删除/获取元素$O(index)$
+ 空间复杂度$O(n)$，其中$n$取决于某时刻链表中最多的节点个数

### AC代码

#### C++

```cpp
struct __LetMeFly_ListNode {
    int val;
    __LetMeFly_ListNode* next;

    __LetMeFly_ListNode() : next(nullptr) {}
    __LetMeFly_ListNode(int val) : val(val), next(nullptr) {}
};


class MyLinkedList {
private:
    __LetMeFly_ListNode* head;
    size_t size;

    __LetMeFly_ListNode* getIndexIterator(int index) {  // 无脑计算，不验证合法性
        __LetMeFly_ListNode* p = head->next;
        while (index--) {
            p = p->next;
        }
        return p;
    }
public:
    MyLinkedList() {
        head = new __LetMeFly_ListNode;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        return getIndexIterator(index)->val;
    }
    
    void addAtHead(int val) {
        __LetMeFly_ListNode* secondNode = head->next;
        head->next = new __LetMeFly_ListNode(val);
        head->next->next = secondNode;
        size++;
    }
    
    void addAtTail(int val) {
        if (size == 0) {
            return addAtHead(val);
        }
        getIndexIterator(size - 1)->next = new __LetMeFly_ListNode(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            index = 0;
            addAtHead(val);
            return;
        }
        if (index > size)
            return;
        if (index == size) {
            addAtTail(val);
            return;
        }
        __LetMeFly_ListNode* lastNode = getIndexIterator(index - 1);
        __LetMeFly_ListNode* nextNode = lastNode->next;
        lastNode->next = new __LetMeFly_ListNode(val);
        lastNode->next->next = nextNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= 0 && index < size) {
            if (index == 0) {
                __LetMeFly_ListNode* nextNode = head->next->next;
                delete head->next;
                head->next = nextNode;
            }
            else {
                __LetMeFly_ListNode* lastNode = getIndexIterator(index - 1);
                __LetMeFly_ListNode* nextNode = lastNode->next->next;
                delete lastNode->next;
                lastNode->next = nextNode;
            }
            size--;
        }
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/09/23/LeetCode%200707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127009642](https://letmefly.blog.csdn.net/article/details/127009642)
