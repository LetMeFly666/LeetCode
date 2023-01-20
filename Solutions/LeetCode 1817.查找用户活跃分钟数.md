---
title: 1817.查找用户活跃分钟数
date: 2023-01-20 09:25:42
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希]
---

# 【LetMeFly】1817.查找用户活跃分钟数

力扣题目链接：[https://leetcode.cn/problems/finding-the-users-active-minutes/](https://leetcode.cn/problems/finding-the-users-active-minutes/)

<p>给你用户在 LeetCode 的操作日志，和一个整数 <code>k</code> 。日志用一个二维整数数组 <code>logs</code> 表示，其中每个 <code>logs[i] = [ID<sub>i</sub>, time<sub>i</sub>]</code> 表示 ID 为 <code>ID<sub>i</sub></code> 的用户在 <code>time<sub>i</sub></code> 分钟时执行了某个操作。</p>

<p><strong>多个用户 </strong>可以同时执行操作，单个用户可以在同一分钟内执行 <strong>多个操作</strong> 。</p>

<p>指定用户的<strong> 用户活跃分钟数（user active minutes，UAM）</strong> 定义为用户对 LeetCode 执行操作的 <strong>唯一分钟数</strong> 。 即使一分钟内执行多个操作，也只能按一分钟计数。</p>

<p>请你统计用户活跃分钟数的分布情况，统计结果是一个长度为 <code>k</code> 且 <strong>下标从 1 开始计数</strong> 的数组 <code>answer</code> ，对于每个 <code>j</code>（<code>1 <= j <= k</code>），<code>answer[j]</code> 表示 <strong>用户活跃分钟数</strong> 等于 <code>j</code> 的用户数。</p>

<p>返回上面描述的答案数组<i> </i><code>answer</code><i> </i>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
<strong>输出：</strong>[0,2,0,0,0]
<strong>解释：</strong>
ID=0 的用户执行操作的分钟分别是：5 、2 和 5 。因此，该用户的用户活跃分钟数为 2（分钟 5 只计数一次）
ID=1 的用户执行操作的分钟分别是：2 和 3 。因此，该用户的用户活跃分钟数为 2
2 个用户的用户活跃分钟数都是 2 ，answer[2] 为 2 ，其余 answer[j] 的值都是 0
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>logs = [[1,1],[2,2],[2,3]], k = 4
<strong>输出：</strong>[1,1,0,0]
<strong>解释：</strong>
ID=1 的用户仅在分钟 1 执行单个操作。因此，该用户的用户活跃分钟数为 1
ID=2 的用户执行操作的分钟分别是：2 和 3 。因此，该用户的用户活跃分钟数为 2
1 个用户的用户活跃分钟数是 1 ，1 个用户的用户活跃分钟数是 2 
因此，answer[1] = 1 ，answer[2] = 1 ，其余的值都是 0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= logs.length <= 10<sup>4</sup></code></li>
	<li><code>0 <= ID<sub>i</sub> <= 10<sup>9</sup></code></li>
	<li><code>1 <= time<sub>i</sub> <= 10<sup>5</sup></code></li>
	<li><code>k</code> 的取值范围是 <code>[用户的最大用户活跃分钟数, 10<sup>5</sup>]</code></li>
</ul>


    
## 方法一：哈希

这道题很明显是要使用哈希表。所需要使用的哈希表主要有两种类型，一种是“字典类型”，能够将用户的id映射到用户的“操作分钟”（说白了就是给你一个用户id你能快速知道这个用户都什么时候进行了“操作”）；另一种是“集合类型”，能够对某个用户的所有操作所在的分钟进行去重。

接着我们只需要遍历所有的操作记录，将每个操作记录到对应id的用户的操作记录上。

这样，我们就得到了“id，操作记录”对应表。

开辟一个大小为k的整型数组，初始值全部为0

遍历刚刚得到的对应表，假设a操作了b次，那么就将整型数组的第b个整数的值+1

最终返回这个整型数组即可

+ 时间复杂度$O(len(logs) + k)$
+ 空间复杂度$O(len(logs))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>> ma;  // 其实这里可以使用unordered_map<int, unordered_set<int>>
        for (auto& log : logs) {
            ma[log[0]].insert(log[1]);
        }
        vector<int> ans(k);
        for (auto a : ma) {
            ans[a.second.size() - 1]++;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        ma = {}
        for log in logs:
            if ma.get(log[0]):
                ma[log[0]].add(log[1])
            else:
                ma[log[0]] = {log[1]}
        ans = [0 for _ in range(k)]
        for who, what in ma.items():
            ans[len(what) - 1] += 1
        return ans
```

**优化：**

1. 使用collections的defaultdict，这样就不需要先特判字典的键值是否已经存在，而是可以直接进行操作
2. 使用ma.values()替换ma.items()，因为统计答案的时候字典的键值是不需要的

```python
# from typing import List
# from collections import defaultdict


class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        ma = defaultdict(set)
        for log in logs:
            ma[log[0]].add(log[1])
        ans = [0 for _ in range(k)]  # 或者写成 ans = [0] * k 也可
        for times in ma.values():
            ans[times - 1] += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/01/20/LeetCode%201817.%E6%9F%A5%E6%89%BE%E7%94%A8%E6%88%B7%E6%B4%BB%E8%B7%83%E5%88%86%E9%92%9F%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128739844](https://letmefly.blog.csdn.net/article/details/128739844)
