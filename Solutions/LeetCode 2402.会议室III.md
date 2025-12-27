---
title: 2402.会议室 III：优先队列大模拟
date: 2025-12-27 23:38:12
tags: [题解, LeetCode, 困难, 数组, 哈希表, 排序, 模拟, 大模拟, 堆（优先队列）, 优先队列]
categories: [题解, LeetCode]
---

# 【LetMeFly】2402.会议室 III：优先队列大模拟

力扣题目链接：[https://leetcode.cn/problems/meeting-rooms-iii/](https://leetcode.cn/problems/meeting-rooms-iii/)

<p>给你一个整数 <code>n</code> ，共有编号从 <code>0</code> 到 <code>n - 1</code> 的 <code>n</code> 个会议室。</p>

<p>给你一个二维整数数组 <code>meetings</code> ，其中 <code>meetings[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 表示一场会议将会在 <strong>半闭</strong> 时间区间 <code>[start<sub>i</sub>, end<sub>i</sub>)</code> 举办。所有 <code>start<sub>i</sub></code> 的值 <strong>互不相同</strong> 。</p>

<p>会议将会按以下方式分配给会议室：</p>

<ol>
	<li>每场会议都会在未占用且编号 <strong>最小</strong> 的会议室举办。</li>
	<li>如果没有可用的会议室，会议将会延期，直到存在空闲的会议室。延期会议的持续时间和原会议持续时间 <strong>相同</strong> 。</li>
	<li>当会议室处于未占用状态时，将会优先提供给原 <strong>开始</strong> 时间更早的会议。</li>
</ol>

<p>返回举办最多次会议的房间 <strong>编号</strong> 。如果存在多个房间满足此条件，则返回编号 <strong>最小</strong> 的房间。</p>

<p><strong>半闭区间 </strong><code>[a, b)</code> 是 <code>a</code> 和 <code>b</code> 之间的区间，<strong>包括</strong> <code>a</code> 但<strong> 不包括</strong> <code>b</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
<strong>输出：</strong>0
<strong>解释：</strong>
- 在时间 0 ，两个会议室都未占用，第一场会议在会议室 0 举办。
- 在时间 1 ，只有会议室 1 未占用，第二场会议在会议室 1 举办。
- 在时间 2 ，两个会议室都被占用，第三场会议延期举办。
- 在时间 3 ，两个会议室都被占用，第四场会议延期举办。
- 在时间 5 ，会议室 1 的会议结束。第三场会议在会议室 1 举办，时间周期为 [5,10) 。
- 在时间 10 ，两个会议室的会议都结束。第四场会议在会议室 0 举办，时间周期为 [10,11) 。
会议室 0 和会议室 1 都举办了 2 场会议，所以返回 0 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
<strong>输出：</strong>1
<strong>解释：</strong>
- 在时间 1 ，所有三个会议室都未占用，第一场会议在会议室 0 举办。
- 在时间 2 ，会议室 1 和 2 未占用，第二场会议在会议室 1 举办。
- 在时间 3 ，只有会议室 2 未占用，第三场会议在会议室 2 举办。
- 在时间 4 ，所有三个会议室都被占用，第四场会议延期举办。 
- 在时间 5 ，会议室 2 的会议结束。第四场会议在会议室 2 举办，时间周期为 [5,10) 。
- 在时间 6 ，所有三个会议室都被占用，第五场会议延期举办。 
- 在时间 10 ，会议室 1 和 2 的会议结束。第五场会议在会议室 1 举办，时间周期为 [10,12) 。 
会议室 1 和会议室 2 都举办了 2 场会议，所以返回 1 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>start<sub>i</sub></code> 的所有值 <strong>互不相同</strong></li>
</ul>


    
## 解题方法：大模拟——两个优先队列

有没有发现这道题有严格的顺序**优先级**，使用优先队列再合适不过了。

先想想我们的策略，再思考具体怎么模拟：

> 遍历按**开始时间递增**的会议（因为开始时间早是安排会议的优先级依据），对于某个待安排的会议：
>
> 1. 查看到会议开始时间为止有没有新释放的会议室
> 2. 查看此刻有没有空的会议室
> 
>    1. 如果有，则使用**编号最小**的那个会议室
>    2. 否则，等待到一个会议室释放为止并使用之（同一时间多会议室到期则优先释放**编号较小**的那个）

多清晰的流水线啊，只需要用代码将其表现出来就好了。

1. 对于会议，只需要按照开始时间从小到大排个序，因为会议的安排顺序是严格按照开始时间安排的且开始时间互不相同。
2. 对于会议室的使用（空闲会议室），优先使用编号最小的，所以可以使用一个优先队列来存放空闲会议室。
3. 对于在使用的会议室，优先释放结束时间最早的那个，有释放时间相同则优先释放编号较小的那个，所以也可以使用一个优先队列来维护。

注意，$10^5$个$5\times10^5$可能会超过`int32`。

+ 时间复杂度$O(m\log m + n\log n + m\log n)$，其中$m=len(meetings)$。$m\log m$来自会议的排序，$n\log n$来自$n$个会议室初始状态的入队，$m\log n$来自每个会议的会议室分配；
+ 空间复杂度$O(n)$。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-27 23:36:34
 */
typedef long long ll;  // 10^5个5*10^5可能会超int32!
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> canuse;
        for (int i = 0; i < n; i++) {
            canuse.push(i);
        }
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> inuse;
        vector<int> times(n);
        for (vector<int>& meeting : meetings) {
            // 先看有没有新释放的
            while (!inuse.empty() && inuse.top().first <= meeting[0]) {
                auto[_, thisRoom] = inuse.top();
                canuse.push(thisRoom);
                inuse.pop();
            }
            int thisRoom;
            ll endTime;
            // 看看有没有空的
            if (!canuse.empty()) {
                thisRoom = canuse.top();
                endTime = meeting[1];
                canuse.pop();
            } else {  // 等到第一个释放
                auto[freeTime, room] = inuse.top();
                thisRoom = room;
                endTime = freeTime + meeting[1] - meeting[0];
                inuse.pop();
            }
            times[thisRoom]++;
            inuse.push({endTime, thisRoom});
        }
        return max_element(times.begin(), times.end()) - times.begin();
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
2
[[0,10],[1,5],[2,7],[3,4]]

0
*/
int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        Solution sol;
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.mostBooked(n, v) << endl;
    }
    return 0;
}
#endif
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156343312)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/27/LeetCode%202402.%E4%BC%9A%E8%AE%AE%E5%AE%A4III/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
