---
title: 1600.王位继承顺序
date: 2024-04-07 17:08:41
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 设计, 哈希表, 哈希, map]
categories: [题解, LeetCode]
---

# 【LetMeFly】1600.王位继承顺序：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/throne-inheritance/](https://leetcode.cn/problems/throne-inheritance/)

<p>一个王国里住着国王、他的孩子们、他的孙子们等等。每一个时间点，这个家庭里有人出生也有人死亡。</p>

<p>这个王国有一个明确规定的王位继承顺序，第一继承人总是国王自己。我们定义递归函数&nbsp;<code>Successor(x, curOrder)</code>&nbsp;，给定一个人&nbsp;<code>x</code>&nbsp;和当前的继承顺序，该函数返回 <code>x</code>&nbsp;的下一继承人。</p>

<pre>
Successor(x, curOrder):
    如果 x 没有孩子或者所有 x 的孩子都在 curOrder 中：
        如果 x 是国王，那么返回 null
        否则，返回 Successor(x 的父亲, curOrder)
    否则，返回 x 不在 curOrder 中最年长的孩子
</pre>

<p>比方说，假设王国由国王，他的孩子&nbsp;Alice 和 Bob （Alice 比 Bob&nbsp;年长）和 Alice 的孩子&nbsp;Jack 组成。</p>

<ol>
	<li>一开始，&nbsp;<code>curOrder</code>&nbsp;为&nbsp;<code>["king"]</code>.</li>
	<li>调用&nbsp;<code>Successor(king, curOrder)</code>&nbsp;，返回 Alice ，所以我们将 Alice 放入 <code>curOrder</code>&nbsp;中，得到&nbsp;<code>["king", "Alice"]</code>&nbsp;。</li>
	<li>调用&nbsp;<code>Successor(Alice, curOrder)</code>&nbsp;，返回 Jack ，所以我们将 Jack 放入&nbsp;<code>curOrder</code>&nbsp;中，得到&nbsp;<code>["king", "Alice", "Jack"]</code>&nbsp;。</li>
	<li>调用&nbsp;<code>Successor(Jack, curOrder)</code>&nbsp;，返回 Bob ，所以我们将 Bob 放入&nbsp;<code>curOrder</code>&nbsp;中，得到&nbsp;<code>["king", "Alice", "Jack", "Bob"]</code>&nbsp;。</li>
	<li>调用&nbsp;<code>Successor(Bob, curOrder)</code>&nbsp;，返回&nbsp;<code>null</code>&nbsp;。最终得到继承顺序为&nbsp;<code>["king", "Alice", "Jack", "Bob"]</code>&nbsp;。</li>
</ol>

<p>通过以上的函数，我们总是能得到一个唯一的继承顺序。</p>

<p>请你实现&nbsp;<code>ThroneInheritance</code>&nbsp;类：</p>

<ul>
	<li><code>ThroneInheritance(string kingName)</code> 初始化一个&nbsp;<code>ThroneInheritance</code>&nbsp;类的对象。国王的名字作为构造函数的参数传入。</li>
	<li><code>void birth(string parentName, string childName)</code>&nbsp;表示&nbsp;<code>parentName</code>&nbsp;新拥有了一个名为&nbsp;<code>childName</code>&nbsp;的孩子。</li>
	<li><code>void death(string name)</code>&nbsp;表示名为&nbsp;<code>name</code>&nbsp;的人死亡。一个人的死亡不会影响&nbsp;<code>Successor</code>&nbsp;函数，也不会影响当前的继承顺序。你可以只将这个人标记为死亡状态。</li>
	<li><code>string[] getInheritanceOrder()</code>&nbsp;返回 <strong>除去</strong>&nbsp;死亡人员的当前继承顺序列表。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death", "getInheritanceOrder"]
[["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], ["andy", "matthew"], ["bob", "alex"], ["bob", "asha"], [null], ["bob"], [null]]
<strong>输出：</strong>
[null, null, null, null, null, null, null, ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"], null, ["king", "andy", "matthew", "alex", "asha", "catherine"]]

<strong>解释：</strong>
ThroneInheritance t= new ThroneInheritance("king"); // 继承顺序：<strong>king</strong>
t.birth("king", "andy"); // 继承顺序：king &gt; <strong>andy</strong>
t.birth("king", "bob"); // 继承顺序：king &gt; andy &gt; <strong>bob</strong>
t.birth("king", "catherine"); // 继承顺序：king &gt; andy &gt; bob &gt; <strong>catherine</strong>
t.birth("andy", "matthew"); // 继承顺序：king &gt; andy &gt; <strong>matthew</strong> &gt; bob &gt; catherine
t.birth("bob", "alex"); // 继承顺序：king &gt; andy &gt; matthew &gt; bob &gt; <strong>alex</strong> &gt; catherine
t.birth("bob", "asha"); // 继承顺序：king &gt; andy &gt; matthew &gt; bob &gt; alex &gt; <strong>asha</strong> &gt; catherine
t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
t.death("bob"); // 继承顺序：king &gt; andy &gt; matthew &gt; <strong>bob（已经去世）</strong>&gt; alex &gt; asha &gt; catherine
t.getInheritanceOrder(); // 返回 ["king", "andy", "matthew", "alex", "asha", "catherine"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= kingName.length, parentName.length, childName.length, name.length &lt;= 15</code></li>
	<li><code>kingName</code>，<code>parentName</code>，&nbsp;<code>childName</code>&nbsp;和&nbsp;<code>name</code>&nbsp;仅包含小写英文字母。</li>
	<li>所有的参数&nbsp;<code>childName</code> 和&nbsp;<code>kingName</code>&nbsp;<strong>互不相同</strong>。</li>
	<li>所有&nbsp;<code>death</code>&nbsp;函数中的死亡名字 <code>name</code>&nbsp;要么是国王，要么是已经出生了的人员名字。</li>
	<li>每次调用 <code>birth(parentName, childName)</code> 时，测试用例都保证 <code>parentName</code> 对应的人员是活着的。</li>
	<li>最多调用&nbsp;<code>10<sup>5</sup></code>&nbsp;次<code>birth</code> 和&nbsp;<code>death</code>&nbsp;。</li>
	<li>最多调用&nbsp;<code>10</code>&nbsp;次&nbsp;<code>getInheritanceOrder</code>&nbsp;。</li>
</ul>


    
## 解题方法：深度优先搜索(DFS)

其实不难发现，```王位继承顺序```就是```多叉树前序遍历的顺序```。

那么，我们只需要设计一个```国王节点```的数据结构：

> + 首选需要```字符串```类型的```姓名```
> + 其次需要```列表```类型的```孩子节点```
> + 最后需要```布尔```类型的```是否存活```

除此之外，我们还需要一个```哈希表```，用来快速地从```姓名```映射到```节点```。

> + 借此可以由```parentName```快速定位到```父节点```。
> + 借此可以由```死亡姓名```快速定位到```死亡节点```。

接着，如果是“新增节点”就新增节点，如果是“返回序列”就前序遍历，如果是“有人死亡”就标记死亡。

+ 时间复杂度：初始化、单次出生、单次死亡$O(1)$；返回继承顺序$O(n)$
+ 空间复杂度：初始化、单次出生、单次死亡$O(1)$；总计$O(n)$

### AC代码

#### C++

```cpp
struct KingNode {
    string name;
    vector<KingNode*> childs;
    bool isAlive;

    KingNode(string name) : name(name) {
        isAlive = true;
    }
};

class ThroneInheritance {
private:
    unordered_map<string, KingNode*> ma;
    KingNode* root;
    vector<string> tempForInheritanceOrder;

    void dfs(KingNode* root) {
        if (root->isAlive) {
            tempForInheritanceOrder.push_back(root->name);
        }
        for (KingNode* child : root->childs) {
            dfs(child);
        }
    }
public:
    ThroneInheritance(string kingName) {
        root = new KingNode(kingName);
        ma[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        KingNode* child = new KingNode(childName);
        ma[childName] = child;
        ma[parentName]->childs.push_back(child);
    }
    
    void death(string name) {
        ma[name]->isAlive = false;
    }
    
    vector<string> getInheritanceOrder() {
        tempForInheritanceOrder.clear();
        dfs(root);
        return tempForInheritanceOrder;
    }
};
```

#### Python

```python
# from typing import List


class KingNode:
    def __init__(self, name) -> None:
        self.name = name
        self.childs = []
        self.isAlive = True


class ThroneInheritance:
    def _dfs(self, root: KingNode) -> None:
        if root.isAlive:
            self.tempForInheritanceOrder.append(root.name)
        for child in root.childs:
            self._dfs(child)

    def __init__(self, kingName: str):
        self.name2node = dict()
        self.root = KingNode(kingName)
        self.name2node[kingName] = self.root

    def birth(self, parentName: str, childName: str) -> None:
        child = KingNode(childName)
        self.name2node[childName] = child
        self.name2node[parentName].childs.append(child)

    def death(self, name: str) -> None:
        self.name2node[name].isAlive = False

    def getInheritanceOrder(self) -> List[str]:
        self.tempForInheritanceOrder = []
        self._dfs(self.root)
        return self.tempForInheritanceOrder
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/07/LeetCode%201600.%E7%8E%8B%E4%BD%8D%E7%BB%A7%E6%89%BF%E9%A1%BA%E5%BA%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137471254](https://letmefly.blog.csdn.net/article/details/137471254)
