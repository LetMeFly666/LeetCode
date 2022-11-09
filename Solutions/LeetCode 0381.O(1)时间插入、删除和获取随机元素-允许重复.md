---
title: 381.O(1) 时间插入、删除和获取随机元素 - 允许重复
date: 2022-10-11 13:16:35
tags: [题解, LeetCode, 困难, 设计, 数组, 哈希表, 数学, 随机化, STL]
---

# 【LetMeFly】STL的应用：381.O(1) 时间插入、删除和获取随机元素 - 允许重复

力扣题目链接：[https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/](https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/)

<p><code>RandomizedCollection</code> 是一种包含数字集合(可能是重复的)的数据结构。它应该支持插入和删除特定元素，以及删除随机元素。</p>

<p>实现 <code>RandomizedCollection</code> 类:</p>

<ul>
	<li><code>RandomizedCollection()</code>初始化空的 <code>RandomizedCollection</code> 对象。</li>
	<li><code>bool insert(int val)</code>&nbsp;将一个 <code>val</code> 项插入到集合中，即使该项已经存在。如果该项不存在，则返回 <code>true</code> ，否则返回 <code>false</code> 。</li>
	<li><code>bool remove(int val)</code>&nbsp;如果存在，从集合中移除一个 <code>val</code> 项。如果该项存在，则返回 <code>true</code> ，否则返回 <code>false</code> 。注意，如果 <code>val</code> 在集合中出现多次，我们只删除其中一个。</li>
	<li><code>int getRandom()</code> 从当前的多个元素集合中返回一个随机元素。每个元素被返回的概率与集合中包含的相同值的数量 <strong>线性相关</strong> 。</li>
</ul>

<p>您必须实现类的函数，使每个函数的 <strong>平均</strong> 时间复杂度为 <code>O(1)</code> 。</p>

<p><strong>注意：</strong>生成测试用例时，只有在 <code>RandomizedCollection</code> 中 <strong>至少有一项</strong> 时，才会调用 <code>getRandom</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入</strong>
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
<strong>输出</strong>
[null, true, false, true, 2, true, 1]

<strong>解释</strong>
RandomizedCollection collection = new RandomizedCollection();// 初始化一个空的集合。
collection.insert(1);// 向集合中插入 1 。返回 true 表示集合不包含 1 。
collection.insert(1);// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
collection.insert(2);// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
collection.getRandom();// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
collection.remove(1);// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
collection.getRandom();// getRandom 应有相同概率返回 1 和 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= val &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
	<li><code>insert</code>,&nbsp;<code>remove</code>&nbsp;和&nbsp;<code>getRandom</code>&nbsp;最多 <strong>总共</strong> 被调用&nbsp;<code>2 * 10<sup>5</sup></code>&nbsp;次</li>
	<li>当调用 <code>getRandom</code> 时，数据结构中 <strong>至少有一个</strong> 元素</li>
</ul>


    
## 方法一：STL的灵活运用

本题考查对STL的灵活运用。

如果使用STL，那么插入删除操作都很容易完成。

但是如果想要在$O(1)$时间内返回随机值，想使用STL就不是那么容易了。

数组中返回一个随机值很容易，时间复杂度是$O(1)$，插入数据也很容易，只是删除数据有点麻烦（一是难以找到待删除的数据在哪里，二是删除中间的数据的时间复杂度并不是$O(1)$）

因此，我们可以把以上两者结合起来：

+ 既然数组中难以找到值为```val```的元素的下标，那么我们就用哈希表把值为```val```的元素的下标存起来
+ 既然删除中间元素耗时交长，那么我们不删除中间的元素，二是把中间的元素和末尾的元素进行交换，再删除末尾的元素

好了，目的明确，开始搞事情

我们很容易使用哈希表来存放某个元素在数组中的下标。比如```unordered_map<int, int>```

但由于元素可能重复，因此改成使用```unordered_map<int, unordered_set<int>>```

至于为什么不使用```unordered_multimap<int, int>```，是因为```unordered_multimap<int, int>```难以在$O(1)$的时间内删除指定键值对```pair<int, int>```

具体可见代码注释。

+ 单次操作时间复杂度$O(1)$。虽为$O(1)$，但是时间复杂度常数特别大。
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> ma;  // <val, [locOfThisVal]>
    vector<int> a;
public:
    RandomizedCollection() {

    }
    
    bool insert(int val) {  // 插入并返回插入前是否无此数
        ma[val].insert(a.size());
        a.push_back(val);
        return ma[val].size() == 1;
    }
    
    bool remove(int val) {
        if (!ma.count(val))  // 不存在次数
            return false;
		
		// erase掉这个数
        unordered_set<int>::iterator it = ma[val].begin();
        int index = *it;
        ma[val].erase(it);
        if (ma[val].empty())
            ma.erase(val);
		
		// 如果这个数在数组中不是最后一个元素，那么就需要将其与最后一个元素交换，再将最后一个元素删除
        if (index < a.size() - 1) {
            int index2swap = a.size() - 1;
            a[index] = a[index2swap];
			// 更新最后一个元素的下标
            ma[a[index2swap]].erase(index2swap);
            ma[a[index2swap]].insert(index);
        }
        a.pop_back();
        return true;
    }
    
    int getRandom() {
        return a[rand() % a.size()];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/11/LeetCode%200381.O%281%29%E6%97%B6%E9%97%B4%E6%8F%92%E5%85%A5%E3%80%81%E5%88%A0%E9%99%A4%E5%92%8C%E8%8E%B7%E5%8F%96%E9%9A%8F%E6%9C%BA%E5%85%83%E7%B4%A0-%E5%85%81%E8%AE%B8%E9%87%8D%E5%A4%8D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127262069](https://letmefly.blog.csdn.net/article/details/127262069)
