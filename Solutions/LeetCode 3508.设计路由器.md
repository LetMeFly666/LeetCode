---
title: 3508.设计路由器：STL套STL——有什么需求就设计什么数据结构
date: 2025-09-20 17:40:53
tags: [题解, LeetCode, 中等, 设计, 队列, 数组, 哈希表, set, map, 二分查找, 有序集合]
categories: [题解, LeetCode]
---

# 【LetMeFly】3508.设计路由器：STL套STL——有什么需求就设计什么数据结构

力扣题目链接：[https://leetcode.cn/problems/implement-router/](https://leetcode.cn/problems/implement-router/)

<p>请你设计一个数据结构来高效管理网络路由器中的数据包。每个数据包包含以下属性：</p>

<ul>
	<li><code>source</code>：生成该数据包的机器的唯一标识符。</li>
	<li><code>destination</code>：目标机器的唯一标识符。</li>
	<li><code>timestamp</code>：该数据包到达路由器的时间戳。</li>
</ul>

<p>实现 <code>Router</code> 类：</p>

<p><code>Router(int memoryLimit)</code>：初始化路由器对象，并设置固定的内存限制。</p>

<ul>
	<li><code>memoryLimit</code> 是路由器在任意时间点可以存储的 <strong>最大</strong> 数据包数量。</li>
	<li>如果添加一个新数据包会超过这个限制，则必须移除 <strong>最旧的</strong> 数据包以腾出空间。</li>
</ul>

<p><code>bool addPacket(int source, int destination, int timestamp)</code>：将具有给定属性的数据包添加到路由器。</p>

<ul>
	<li>如果路由器中已经存在一个具有相同 <code>source</code>、<code>destination</code> 和 <code>timestamp</code> 的数据包，则视为重复数据包。</li>
	<li>如果数据包成功添加（即不是重复数据包），返回 <code>true</code>；否则返回 <code>false</code>。</li>
</ul>

<p><code>int[] forwardPacket()</code>：以 FIFO（先进先出）顺序转发下一个数据包。</p>

<ul>
	<li>从存储中移除该数据包。</li>
	<li>以数组 <code>[source, destination, timestamp]</code> 的形式返回该数据包。</li>
	<li>如果没有数据包可以转发，则返回空数组。</li>
</ul>

<p><code>int getCount(int destination, int startTime, int endTime)</code>：</p>

<ul>
	<li>返回当前存储在路由器中（即尚未转发）的，且目标地址为指定 <code>destination</code> 且时间戳在范围 <code>[startTime, endTime]</code>（包括两端）内的数据包数量。</li>
</ul>

<p><strong>注意</strong>：对于 <code>addPacket</code> 的查询会按照 <code>timestamp</code> 的递增顺序进行。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><br />
<span class="example-io">["Router", "addPacket", "addPacket", "addPacket", "addPacket", "addPacket", "forwardPacket", "addPacket", "getCount"]<br />
[[3], [1, 4, 90], [2, 5, 90], [1, 4, 90], [3, 5, 95], [4, 5, 105], [], [5, 2, 110], [5, 100, 110]]</span></p>

<p><strong>输出：</strong><br />
<span class="example-io">[null, true, true, false, true, true, [2, 5, 90], true, 1] </span></p>

<p><strong>解释：</strong></p>
<code>Router router = new Router(3);</code> // 初始化路由器，内存限制为 3。<br />
<code>router.addPacket(1, 4, 90);</code> // 数据包被添加，返回 True。<br />
<code>router.addPacket(2, 5, 90);</code> // 数据包被添加，返回 True。<br />
<code>router.addPacket(1, 4, 90);</code> // 这是一个重复数据包，返回 False。<br />
<code>router.addPacket(3, 5, 95);</code> // 数据包被添加，返回 True。<br />
<code>router.addPacket(4, 5, 105);</code> // 数据包被添加，<code>[1, 4, 90]</code> 被移除，因为数据包数量超过限制，返回 True。<br />
<code>router.forwardPacket();</code> // 转发数据包 <code>[2, 5, 90]</code> 并将其从路由器中移除。<br />
<code>router.addPacket(5, 2, 110);</code> // 数据包被添加，返回 True。<br />
<code>router.getCount(5, 100, 110);</code> // 唯一目标地址为 5 且时间在 <code>[100, 110]</code>&nbsp;范围内的数据包是 <code>[4, 5, 105]</code>，返回 1。</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><br />
<span class="example-io">["Router", "addPacket", "forwardPacket", "forwardPacket"]<br />
[[2], [7, 4, 90], [], []]</span></p>

<p><strong>输出：</strong><br />
<span class="example-io">[null, true, [7, 4, 90], []] </span></p>

<p><strong>解释：</strong></p>
<code>Router router = new Router(2);</code> // 初始化路由器，内存限制为 2。<br />
<code>router.addPacket(7, 4, 90);</code> // 返回 True。<br />
<code>router.forwardPacket();</code> // 返回 <code>[7, 4, 90]</code>。<br />
<code>router.forwardPacket();</code> // 没有数据包可以转发，返回 <code>[]</code>。</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= memoryLimit &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= source, destination &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= timestamp &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= startTime &lt;= endTime &lt;= 10<sup>9</sup></code></li>
	<li><code>addPacket</code>、<code>forwardPacket</code> 和 <code>getCount</code> 方法的总调用次数最多为 <code>10<sup>5</sup></code>。</li>
	<li>对于 <code>addPacket</code> 的查询，<code>timestamp</code> 按递增顺序给出。</li>
</ul>


    
## 解题方法：STL套STL

首先拆解需求，无非以下三个：

1. FIFO；
2. 判断一个packet是否已经存在；
3. 查找指定destination的所有包中时间戳在`[s, e]`中的有多少个。

让我们逐个分析破解之，有什么需求就设计什么数据结构。

**FIFO**

首先对于第一个需求，当路由器中数据包数量已经达到memoryLimit个时，新来的数据包会挤掉最早加入的数据包。

很简单，使用一个队列就行。如果想效率更高点，也可以使用数组模拟队列（容量多开一个来区分队列是满是空，两个指针指向队列第一个元素下标和最后一个元素下标的下一个下标）。

由于使用了多个数据结构，所以有元素出队时记得更新其他数据结构中的内容。

**判断一个packet是否已经存在**

这个需求来自新加入包时是返回true还是false。这个也简单，使用一个哈希表判断路由器中都有哪些包就好了。

**查找指定destination的所有包中时间戳在`[s, e]`中的有多少个**

这个相对复杂一点。所好在于，题目给定数据满足添加addPacket的timestamp是递增的。

> 最后那句“注意”我也没看懂，也不知道到底是同destination的包timestamp递增还是所有包整体上timestamp递增，反正无所谓，就当成“针对这道题随便操作，只要你所涉及到的数据包都是timestamp递增的”就好了。

好吧，既然给定的数据包都是timestamp递增的了，那么范围查询就容易实现了。

既然查询的范围是指定的destination，那么我们就建立一个哈希表finder，把键设置为destination好了。finder[destination]是所有目标地址为destination的数据包。

这些数据包怎么存储呢？使用一个vector存放每个数据包的timestamp就可以了，新来数据包就直接push到vector后面，就能实现vector中的数据包是天然按照timestamp递增的，就能使用二分法在log级别的时间内找到时间戳在`[s, e]`中的数据包有多少个了。

这就解决了？等下，数据包还能被移除呢！怎么办，好说，再使用一个整数startIdx记录vector中没被移除的数据包下标是从哪个开始的就好了。

> 相当于移除数据包时，在针对需求3设计的结构体中，并没有真正移除，而是把“有效范围指针”右移了一位。实际设计中可别这样！内存分分钟爆炸。

### 时空复杂度分析

+ 时间复杂度：add和forward $O(1)$，count $(\log memoryLimit)$
+ 空间复杂度$O(memoryLimit)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-20 16:10:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-20 17:38:56
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
FIFO: 一个数组一个指针
是否重复：一个哈希表
Find：哈希表+有序集合

啊，我不想写了
*/
inline void hash_combine(size_t &seed, size_t h) {
    seed ^= h + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
}

struct TupleHash {
    size_t operator()(const tuple<int, int, int>& t) const noexcept {
        size_t seed = 0;
        hash_combine(seed, hash<int>{}(get<0>(t)));
        hash_combine(seed, hash<int>{}(get<1>(t)));
        hash_combine(seed, hash<int>{}(get<2>(t)));
        return seed;
    }
};

struct TupleEq {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const noexcept {  // 记得const noexcept（好难记）
        return a == b;
    }
};

class Router {
private:
    vector<tuple<int, int, int>> fifo;
    int fifoLeft, fifoRight, memoryLimit;
    unordered_set<tuple<int, int, int>, TupleHash, TupleEq> already;
    unordered_map<int, pair<vector<int>, int>> finder;  // destination -> <[timestamp], 有效范围>

    void removePacket() {  // remove fifoLeft，不判断是否为空
        tuple<int, int, int> toRemove = fifo[fifoLeft];
        already.erase(toRemove);
        finder[get<1>(toRemove)].second++;
        fifoLeft = (fifoLeft + 1) % (memoryLimit + 1);
    }
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
        fifo.resize(memoryLimit + 1);  // 多开一个区分空和满
        fifoLeft = fifoRight = 0;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int, int, int> package = tuple(source, destination, timestamp);
        if (already.count(package)) {
            return false;
        }
        already.insert(package);
        if ((fifoRight + 1) % (memoryLimit + 1) == fifoLeft) {  // remove fifo[fifoLeft]
            removePacket();
        }
        fifo[fifoRight] = package;
        fifoRight = (fifoRight + 1) % (memoryLimit + 1);
        finder[destination].first.push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (fifoLeft == fifoRight) {
            return {};
        }
        auto [source, destination, timeStamp] = fifo[fifoLeft];
        removePacket();
        return {source, destination, timeStamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto&& [timeStamps, startIdx] = finder[destination];
        return upper_bound(timeStamps.begin() + startIdx, timeStamps.end(), endTime) - lower_bound(timeStamps.begin() + startIdx, timeStamps.end(), startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151901838)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/20/LeetCode%203508.%E8%AE%BE%E8%AE%A1%E8%B7%AF%E7%94%B1%E5%99%A8/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)

ios26更新好烫！
