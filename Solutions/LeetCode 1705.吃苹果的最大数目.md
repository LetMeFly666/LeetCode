---
title: 1705.吃苹果的最大数目
date: 2024-12-24 23:48:02
tags: [题解, LeetCode, 中等, 贪心, 数组, 堆（优先队列）]
---

# 【LetMeFly】1705.吃苹果的最大数目：贪心(优先队列) - 清晰题解

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-eaten-apples/](https://leetcode.cn/problems/maximum-number-of-eaten-apples/)

<p>有一棵特殊的苹果树，一连 <code>n</code> 天，每天都可以长出若干个苹果。在第 <code>i</code> 天，树上会长出 <code>apples[i]</code> 个苹果，这些苹果将会在 <code>days[i]</code> 天后（也就是说，第 <code>i + days[i]</code> 天时）腐烂，变得无法食用。也可能有那么几天，树上不会长出新的苹果，此时用 <code>apples[i] == 0</code> 且 <code>days[i] == 0</code> 表示。</p>

<p>你打算每天 <strong>最多</strong> 吃一个苹果来保证营养均衡。注意，你可以在这 <code>n</code> 天之后继续吃苹果。</p>

<p>给你两个长度为 <code>n</code> 的整数数组 <code>days</code> 和 <code>apples</code> ，返回你可以吃掉的苹果的最大数目<em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>apples = [1,2,3,5,2], days = [3,2,1,4,2]
<strong>输出：</strong>7
<strong>解释：</strong>你可以吃掉 7 个苹果：
- 第一天，你吃掉第一天长出来的苹果。
- 第二天，你吃掉一个第二天长出来的苹果。
- 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
- 第四天到第七天，你吃的都是第四天长出来的苹果。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
<strong>输出：</strong>5
<strong>解释：</strong>你可以吃掉 5 个苹果：
- 第一天到第三天，你吃的都是第一天长出来的苹果。
- 第四天和第五天不吃苹果。
- 第六天和第七天，你吃的都是第六天长出来的苹果。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>apples.length == n</code></li>
	<li><code>days.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= apples[i], days[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li>只有在 <code>apples[i] = 0</code> 时，<code>days[i] = 0</code> 才成立</li>
</ul>


    
## 解题方法：贪心

思路很简单：

> 有一些苹果，你先吃哪个？答案是先吃腐烂最早的。

因此可以使用优先队列，从第0天开始模拟到第$n-1$天：

> 每天将当天新苹果入队；腐烂较早的最优先；
>
> 当`队列不空`且`今天还没吃到苹果`时不断出队，若已腐烂则丢弃，若未腐烂则吃一个并将剩下的苹果入队。

遍历完$0$到$n-1$天，不再有新苹果了，但队列中可能有旧苹果。

这次和之前有所不同，不再一天一天吃，而是几天几天连续算：

> 假设当前是第$day$天，队首苹果有$appleNum$个且将在$rotDay$腐烂，则能连续吃$max(0, min(rotDay - day, appleNum))$天。

为什么$0$到$n-1$天要一天一天地吃，而从第$n$天开始可以连续吃同一批苹果？

> 因为从第$n$天开始不会产生新苹果了，我们不再关心苹果的“产生日期”，只要没过保质期就能吃。
>
> 但是前$n$天可不一样，例如第$0$天产$2$个$1000$天保质期的苹果，第$1$天产$1$个保质期$1$天的苹果，那么就不能照着第$0$天的$2$个连续吃完，而应该第$0$和$3$天吃第$0$天产的，第$1$天吃第$1$天产的。
>
> 本质上来说就是前$n$天每天都有新苹果产生，可能导致队首苹果不再是腐烂最早的苹果。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-24 10:56:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-24 18:41:09
 */
// 不能只按照腐烂截止时间
// 例如不能为了吃截止时间为6的4,5而空出第3天
/*
[1,2,3,5,2]
[3,2,1,4,2]


<0-3, 1>, <1-3, 2>, <2-3, 1>, <3-7, 5>, <4-6, 2>
    0        1, 2                3, 6     4, 5
*/
// 前n天应该 边遍历边入队
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int ans = 0, day = 0;
        for (; day < apples.size(); day++) {
            if (apples[day]) {
                pq.push({day + days[day], apples[day]});
            }
            while (pq.size()) {
                auto [rotDay, appleNum] = pq.top();
                pq.pop();
                if (rotDay <= day) {
                    continue;
                }
                ans++;
                appleNum--;
                if (appleNum) {
                    pq.push({rotDay, appleNum});
                }
                break;
            }
        }
        while (pq.size()) {
            auto [rotDay, appleNum] = pq.top();
            pq.pop();
            int eat = max(0, min(rotDay - day, appleNum));
            ans += eat;
            day += eat;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-24 18:46:52
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-24 18:56:55
'''
from typing import List
import heapq

class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        pq = []
        ans = 0
        for day in range(len(apples)):
            if apples[day]:
                heapq.heappush(pq, (day + days[day], apples[day]))
            while pq:
                rotDay, appleNum = heapq.heappop(pq)
                if rotDay <= day:
                    continue
                ans += 1
                appleNum -= 1
                if appleNum:
                    heapq.heappush(pq, (rotDay, appleNum))
                break
        day += 1  # 注意这里和C不一样，python执行完day是能取到的右值
        while pq:
            rotDay, appleNum = heapq.heappop(pq)
            eat = max(0, min(rotDay - day, appleNum))
            ans += eat
            day += eat
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-24 18:58:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-24 19:07:07
 */
import java.util.PriorityQueue;

class Solution {
    public int eatenApples(int[] apples, int[] days) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        int ans = 0, day = 0;
        for (; day < apples.length; day++) {
            if (apples[day] > 0) {
                pq.add(new int[]{day + days[day], apples[day]});
            }
            while (pq.size() > 0) {
                int[] temp = pq.poll();
                int rotDay = temp[0], appleNum = temp[1];
                if (rotDay <= day) {
                    continue;
                }
                ans++;
                appleNum--;
                if (appleNum > 0) {
                    pq.add(new int[]{rotDay, appleNum});
                }
                break;
            }
        }
        while (!pq.isEmpty()) {
            int[] temp = pq.poll();
            int rotDay = temp[0], appleNum = temp[1];
            int eat = Math.max(0, Math.min(rotDay - day, appleNum));
            ans += eat;
            day += eat;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2024-12-24 19:07:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-24 23:43:52
 */
package main
import "container/heap"

type pair struct{ rotDay, appleNum int}
type PQ []pair

func (pq PQ) Len() int           { return len(pq) }
func (pq PQ) Less(i, j int) bool { return pq[i].rotDay < pq[j].rotDay }
func (pq PQ) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }
func (pq *PQ) Push(v any)        { *pq = append(*pq, v.(pair)) }
func (pq *PQ) Pop() any          { v := (*pq)[len(*pq) - 1]; *pq = (*pq)[:len(*pq) - 1]; return v }

func min_eatenApples(a, b int) int { if a < b { return a}; return b}
func max_eatenApples(a, b int) int { if a > b { return a}; return b}

func eatenApples(apples []int, days []int) (ans int) {
    var pq PQ
    for day := range apples {
        if apples[day] > 0 {
            heap.Push(&pq, pair{day + days[day], apples[day]})
        }
        for len(pq) > 0 {
            v := heap.Pop(&pq).(pair)
            rotDay, appleNum := v.rotDay, v.appleNum
            if rotDay <= day {
                continue
            }
            ans++
            appleNum--
            if appleNum > 0 {
                heap.Push(&pq, pair{rotDay, appleNum})
            }
            break
        }
    }
    day := len(apples)
    for len(pq) > 0 {
        v := heap.Pop(&pq).(pair)
        rotDay, appleNum := v.rotDay, v.appleNum
        eat := max_eatenApples(0, min_eatenApples(rotDay - day, appleNum))
        ans += eat
        day += eat
    }
    return
}
```

Golang的堆是一个接口，需要实现Len、Less、Swap、Push、Pop方法。

可参考[与ChatGPT的对话](https://chatgpt.com/share/676ad777-6298-8001-9cbb-5cc63a731723)

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/24/LeetCode%201705.%E5%90%83%E8%8B%B9%E6%9E%9C%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E7%9B%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144705583](https://letmefly.blog.csdn.net/article/details/144705583)
