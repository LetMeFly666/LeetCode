---
title: 895.最大频率栈
date: 2022-11-30 22:57:12
tags: [题解, LeetCode, 困难, 栈, 设计, 哈希表, 有序集合]
---

# 【LetMeFly】895.最大频率栈

力扣题目链接：[https://leetcode.cn/problems/maximum-frequency-stack/](https://leetcode.cn/problems/maximum-frequency-stack/)

<p>设计一个类似堆栈的数据结构，将元素推入堆栈，并从堆栈中弹出<strong>出现频率</strong>最高的元素。</p>

<p>实现 <code>FreqStack</code>&nbsp;类:</p>

<ul>
	<li><meta charset="UTF-8" /><code>FreqStack()</code>&nbsp;构造一个空的堆栈。</li>
	<li><meta charset="UTF-8" /><code>void push(int val)</code>&nbsp;将一个整数&nbsp;<code>val</code>&nbsp;压入栈顶。</li>
	<li><meta charset="UTF-8" /><code>int pop()</code>&nbsp;删除并返回堆栈中出现频率最高的元素。
	<ul>
		<li>如果出现频率最高的元素不只一个，则移除并返回最接近栈顶的元素。</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
<strong>输出：</strong>[null,null,null,null,null,null,null,5,7,5,4]
<strong>解释：</strong>
FreqStack = new FreqStack();
freqStack.push (5);//堆栈为 [5]
freqStack.push (7);//堆栈是 [5,7]
freqStack.push (5);//堆栈是 [5,7,5]
freqStack.push (7);//堆栈是 [5,7,5,7]
freqStack.push (4);//堆栈是 [5,7,5,7,4]
freqStack.push (5);//堆栈是 [5,7,5,7,4,5]
freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,5,7,4]。
freqStack.pop ();//返回 7 ，因为 5 和 7 出现频率最高，但7最接近顶部。堆栈变成 [5,7,5,4]。
freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,4]。
freqStack.pop ();//返回 4 ，因为 4, 5 和 7 出现频率最高，但 4 是最接近顶部的。堆栈变成 [5,7]。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= val &lt;= 10<sup>9</sup></code></li>
	<li><code>push</code>&nbsp;和 <code>pop</code>&nbsp;的操作数不大于 <code>2 * 10<sup>4</sup></code>。</li>
	<li>输入保证在调用&nbsp;<code>pop</code>&nbsp;之前堆栈中至少有一个元素。</li>
</ul>


    
## 方法一：哈希表设计

其实主要也就是两个数据结构，一个是```int```转```int```的哈希表，一个是```int```转```stack<int>```的哈希表

+ ```unordered_map<int, int> value2times```记录一个数值出现的次数。假如```value2times[1] = 5```，那么就说明栈中有```5```个```1```
+ ```unordered_map<int, stack<int>> times2values```记录某个频率的数。假如```times2values[3] = [1, 2, 5```，那么就说明```1```、```2```、```5```都出现过```3```次

最后，我们再使用一个整数类型的数据```maxTimes```来记录整个栈中的“最大频率”

**当元素入栈时：**

假设入栈了元素```val```，那么```val```在栈中出现的次数增加（```value2times[val]++```）

出现次数增加后，这个元素出现了```value2times[val]```次（记为```thisTimes```）

那么我们同时就需要将这个元素插入```times2values[thisTimes]```这个栈中

最后，更新整个栈中的最大频率```maxTimes```即可

**当元素出栈时：**

通过```maxTimes```我们可以得到栈中元素的“最大出现次数”

因此，```value2times[maxTimes]```栈的栈顶元素记为要找的元素。（记为```value```）

将这个元素弹出栈，并将这个元素在栈中的出现次数减一。

如果出栈后```maxTimes```对应的栈空了，那么就将```maxTimes```减1


+ 时间复杂度$O(1)$，单次入栈和出栈的时间复杂度都是$O(1)$
+ 空间复杂度$O(n)$，其中$n$是栈中的最大元素个数

### AC代码

#### C++

```cpp
class FreqStack {
private:
    unordered_map<int, int> value2times;
    unordered_map<int, stack<int>> times2values;
    int maxTimes;
public:
    FreqStack() {
        maxTimes = 0;
    }
    
    void push(int val) {
        value2times[val]++;
        int thisTimes = value2times[val];
        times2values[thisTimes].push(val);
        maxTimes = max(maxTimes, thisTimes);
    }
    
    int pop() {
        int value = times2values[maxTimes].top();
        times2values[maxTimes].pop();
        value2times[value]--;
        if (times2values[maxTimes].empty()) {
            maxTimes--;
        }
        return value;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/30/LeetCode%200895.%E6%9C%80%E5%A4%A7%E9%A2%91%E7%8E%87%E6%A0%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128124298](https://letmefly.blog.csdn.net/article/details/128124298)
