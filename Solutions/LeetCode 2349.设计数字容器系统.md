---
title: 2349.设计数字容器系统：双哈希表(要咋查就咋映射)
date: 2025-09-17 21:58:10
tags: [题解, LeetCode, 中等, 设计, 哈希表, map, 有序集合, 堆（优先队列）]
categories: [题解, LeetCode]
---

# 【LetMeFly】2349.设计数字容器系统：双哈希表(要咋查就咋映射)

力扣题目链接：[https://leetcode.cn/problems/design-a-number-container-system/](https://leetcode.cn/problems/design-a-number-container-system/)

<p>设计一个数字容器系统，可以实现以下功能：</p>

<ul>
	<li>在系统中给定下标处&nbsp;<strong>插入</strong>&nbsp;或者 <strong>替换</strong>&nbsp;一个数字。</li>
	<li><strong>返回</strong>&nbsp;系统中给定数字的最小下标。</li>
</ul>

<p>请你实现一个&nbsp;<code>NumberContainers</code>&nbsp;类：</p>

<ul>
	<li><code>NumberContainers()</code>&nbsp;初始化数字容器系统。</li>
	<li><code>void change(int index, int number)</code> 在下标&nbsp;<code>index</code>&nbsp;处填入&nbsp;<code>number</code>&nbsp;。如果该下标&nbsp;<code>index</code>&nbsp;处已经有数字了，那么用 <code>number</code>&nbsp;替换该数字。</li>
	<li><code>int find(int number)</code>&nbsp;返回给定数字&nbsp;<code>number</code>&nbsp;在系统中的最小下标。如果系统中没有&nbsp;<code>number</code>&nbsp;，那么返回&nbsp;<code>-1</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
<strong>输出：</strong>
[null, -1, null, null, null, null, 1, null, 2]

<strong>解释：</strong>
NumberContainers nc = new NumberContainers();
nc.find(10); // 没有数字 10 ，所以返回 -1 。
nc.change(2, 10); // 容器中下标为 2 处填入数字 10 。
nc.change(1, 10); // 容器中下标为 1 处填入数字 10 。
nc.change(3, 10); // 容器中下标为 3 处填入数字 10 。
nc.change(5, 10); // 容器中下标为 5 处填入数字 10 。
nc.find(10); // 数字 10 所在的下标为 1 ，2 ，3 和 5 。因为最小下标为 1 ，所以返回 1 。
nc.change(1, 20); // 容器中下标为 1 处填入数字 20 。注意，下标 1 处之前为 10 ，现在被替换为 20 。
nc.find(10); // 数字 10 所在下标为 2 ，3 和 5 。最小下标为 2 ，所以返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= index, number &lt;= 10<sup>9</sup></code></li>
	<li>调用&nbsp;<code>change</code> 和&nbsp;<code>find</code>&nbsp;的&nbsp;<strong>总次数</strong>&nbsp;不超过&nbsp;<code>10<sup>5</sup></code> 次。</li>
</ul>


    
## 解题方法：两个哈希表

核心目标有两个：

1. number查index
2. index改number

所以可以建立两个哈希表映射，一个是index映射为number，一个是number映射为index(s)。

一个index只对应一个number，所以使用int2int就行；一个number可能对应多个index，所以可以使用int2有序集合。

+ 时间复杂度$O(\log n)$，其中$n$是表中总数据量
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-17 20:30:45
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-17 20:58:14
 */
class NumberContainers {
private:
    unordered_map<int, set<int>> num2idx;
    unordered_map<int, int> idx2num;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto it = idx2num.find(index);
        if (it != idx2num.end()) {
            int number = (*it).second;
            num2idx[number].erase(index);
        }
        idx2num[index] = number;
        num2idx[number].insert(index);
    }
    
    int find(int number) {
        auto it = num2idx.find(number);
        if (it == num2idx.end() || (*it).second.size() == 0) {
            return -1;
        }
        return *(*it).second.begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151803541)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/17/LeetCode%202349.%E8%AE%BE%E8%AE%A1%E6%95%B0%E5%AD%97%E5%AE%B9%E5%99%A8%E7%B3%BB%E7%BB%9F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
