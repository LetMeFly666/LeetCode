---
title: 2225.找出输掉零场或一场比赛的玩家
date: 2024-05-22 20:25:16
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map, 计数, 排序]
---

# 【LetMeFly】2225.找出输掉零场或一场比赛的玩家：哈希表计数

力扣题目链接：[https://leetcode.cn/problems/find-players-with-zero-or-one-losses/](https://leetcode.cn/problems/find-players-with-zero-or-one-losses/)

<p>给你一个整数数组 <code>matches</code> 其中 <code>matches[i] = [winner<sub>i</sub>, loser<sub>i</sub>]</code> 表示在一场比赛中 <code>winner<sub>i</sub></code> 击败了 <code>loser<sub>i</sub></code> 。</p>

<p>返回一个长度为 2 的列表<em> </em><code>answer</code> ：</p>

<ul>
	<li><code>answer[0]</code> 是所有 <strong>没有</strong> 输掉任何比赛的玩家列表。</li>
	<li><code>answer[1]</code> 是所有恰好输掉 <strong>一场</strong> 比赛的玩家列表。</li>
</ul>

<p>两个列表中的值都应该按 <strong>递增</strong> 顺序返回。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>只考虑那些参与 <strong>至少一场</strong> 比赛的玩家。</li>
	<li>生成的测试用例保证 <strong>不存在</strong> 两场比赛结果 <strong>相同</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
<strong>输出：</strong>[[1,2,10],[4,5,7,8]]
<strong>解释：</strong>
玩家 1、2 和 10 都没有输掉任何比赛。
玩家 4、5、7 和 8 每个都输掉一场比赛。
玩家 3、6 和 9 每个都输掉两场比赛。
因此，answer[0] = [1,2,10] 和 answer[1] = [4,5,7,8] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matches = [[2,3],[1,3],[5,4],[6,4]]
<strong>输出：</strong>[[1,2,5,6],[]]
<strong>解释：</strong>
玩家 1、2、5 和 6 都没有输掉任何比赛。
玩家 3 和 4 每个都输掉两场比赛。
因此，answer[0] = [1,2,5,6] 和 answer[1] = [] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= matches.length &lt;= 10<sup>5</sup></code></li>
	<li><code>matches[i].length == 2</code></li>
	<li><code>1 &lt;= winner<sub>i</sub>, loser<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>winner<sub>i</sub> != loser<sub>i</sub></code></li>
	<li>所有 <code>matches[i]</code> <strong>互不相同</strong></li>
</ul>


    
## 解题方法：哈希表

使用一个哈希表，记录每个玩家的输的次数。

遍历所有比赛数组：

+ winner的输次数加0；
+ loser的输次数加1。

最后遍历哈希表，将总输次数为0和1的玩家分别放入答案数组的对应位置，最后再分别排个序。

为什么winner还要“加0”？因为不“加0”的话可能导致哈希表中从来没有出现过这个人，最后就统计不到“东方不败”了。

+ 时间复杂度$O(len(matches)\times \log len(matches))$
+ 空间复杂度$O(len(matches))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int, int> cnt;
        for (vector<int>& match : matches) {
            cnt[match[0]] += 0;
            cnt[match[1]]++;
        }
        for (auto&& [id, times] : cnt) {
            if (times == 0) {
                ans[0].push_back(id);
            }
            else if (times == 1) {
                ans[1].push_back(id);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import defaultdict

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        ans = [[], []]
        cnt = defaultdict(int)
        for winner, loser in matches:
            cnt[winner] += 0
            cnt[loser] += 1
        for id_, times in cnt.items():
            if times == 0:
                ans[0].append(id_)
            elif times == 1:
                ans[1].append(id_)
        ans[0].sort()
        ans[1].sort()
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/22/LeetCode%202225.%E6%89%BE%E5%87%BA%E8%BE%93%E6%8E%89%E9%9B%B6%E5%9C%BA%E6%88%96%E4%B8%80%E5%9C%BA%E6%AF%94%E8%B5%9B%E7%9A%84%E7%8E%A9%E5%AE%B6/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139128938](https://letmefly.blog.csdn.net/article/details/139128938)
