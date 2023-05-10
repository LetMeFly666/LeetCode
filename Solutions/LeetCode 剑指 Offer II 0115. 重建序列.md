---
title: 剑指 Offer II 115.重建序列
date: 2022-07-23 10:27:08
tags: [题解, LeetCode, 中等, 图, 拓扑排序, 数组]
---

# 【LetMeFly】图解：剑指 Offer II 115.重建序列 - 拓扑排序

力扣题目链接：[https://leetcode.cn/problems/ur2n8P/](https://leetcode.cn/problems/ur2n8P/)

<p>请判断原始的序列&nbsp;<code>org</code>&nbsp;是否可以从序列集&nbsp;<code>seqs</code>&nbsp;中唯一地 <strong>重建&nbsp;</strong>。</p>

<p>序列&nbsp;<code>org</code>&nbsp;是 1 到 n 整数的排列，其中 1 &le; n &le; 10<sup>4</sup>。<strong>重建&nbsp;</strong>是指在序列集 <code>seqs</code> 中构建最短的公共超序列，即&nbsp;&nbsp;<code>seqs</code>&nbsp;中的任意序列都是该最短序列的子序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>org = [1,2,3], seqs = [[1,2],[1,3]]
<strong>输出: </strong>false
<strong>解释：</strong>[1,2,3] 不是可以被重建的唯一的序列，因为 [1,3,2] 也是一个合法的序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入: </strong>org = [1,2,3], seqs = [[1,2]]
<strong>输出: </strong>false
<strong>解释：</strong>可以重建的序列只有 [1,2]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入: </strong>org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
<strong>输出: </strong>true
<strong>解释：</strong>序列 [1,2], [1,3] 和 [2,3] 可以被唯一地重建为原始的序列 [1,2,3]。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入: </strong>org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
<strong>输出: </strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>org</code> 是数字 <code>1</code> 到 <code>n</code> 的一个排列</li>
	<li><code>1 &lt;= segs[i].length &lt;= 10<sup>5</sup></code></li>
	<li><code>seqs[i][j]</code> 是 <code>32</code> 位有符号整数</li>
</ul>

<p>&nbsp;</p>

<p>注意：本题与主站 444&nbsp;题相同：<a href="https://leetcode-cn.com/problems/sequence-reconstruction/">https://leetcode-cn.com/problems/sequence-reconstruction/</a></p>


## 方法一：拓扑排序

我们根据样例来分析：

**样例一：**

```
nums = [1,2,3], sequences = [[1,2],[1,3]]
```

样例一中，我们已知排列```[1, 2, 3]```的两个子序列```[1, 2]```和```[1, 3]```。这就说明：```1```必须出现在```2```的前面并且```1```必须出现在```3```的前面。（因为子序列中元素相对位置必须保持不变）

但是```2```和```3```哪个在前哪个在后呢？根据给定输入```[[1,2],[1,3]]```无法判断。

因此，样例一不能唯一确定“```超序列```”

**样例二：**

```
nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
```

样例二中，我们已知排列```[1, 2, 3]```的三个子序列```[1, 2]```、```[1, 3]```和```[2, 3]```。这就说明```1```在```2```前、```1```在```3```前、```2```在```3```前。

那么要满足上述三个条件，有且仅有一种排列方式：```[1, 2, 3]```

因此样例二能唯一确定“```超序列```”```[1, 2, 3]```

**实现思路：**

“```1```在```2```前、```1```在```3```前”让我们很容易想到```拓扑排序```。

我们可以构建一张图，图中节点是```nums```中的每一个元素。如果```1```在```2```前就添加一条```1→2```的边。

那么样例一的图将被构建为：

<!-- ![\[\[1, 2\], \[1, 3\]\].png](https://pic.leetcode-cn.com/1658545276-fKlUZN-%5B%5B1,%202%5D,%20%5B1,%203%5D%5D.png) -->
![\[\[1, 2\], \[1, 3\]\].png](https://img-blog.csdnimg.cn/img_convert/762f0fd484890d5bafcd97ec2cc806b9.png)

从```入度为0```的节点```1```开始进行拓扑排序，排序之后发现剩下两个节点，彼此之间无法确定相对顺序。

样例二的图将被构建为：

<!-- ![\[\[1, 2\], \[1, 3\], \[2, 3\]\].png](https://pic.leetcode-cn.com/1658545463-cKKVqc-%5B%5B1,%202%5D,%20%5B1,%203%5D,%20%5B2,%203%5D%5D.png) -->
![\[\[1, 2\], \[1, 3\], \[2, 3\]\].png](https://img-blog.csdnimg.cn/img_convert/859ea01b2abb82009669262e8ca27776.png)

从```入度为0```的节点```1```开始进行拓扑排序，排序之后只剩下了最终节点```3```

**具体实现方法**

1. 初始时遍历```sequences```中的所有元素，对于```sequences```中的```[a, b, c]```，构建一条```a→b```的边和一条```b→c```的边，并把```b```和```c```的入度```+1```
2. 遍历所有节点，将入度为0的节点入队。不断从队列中取出节点，去掉从这个节点开始的所有的边，并把去掉的边所指向的节点的入度-1。（假如从节点```a```出发有两条边```a→b```和```a→c```，那么```b```和```c```的入度-1）
3. 直到队列为空

注意：

1. 整个排序过程中，队列中最多有1个节点。（那是因为如果同时有多个入度为0的节点，就无法判断这些节点之间的相对顺序）
2. 排序结束后，所有节点的入度必须全部为0

如果同时满足上述两个条件，就返回```true```

---

**2023.3.25日更：** 感谢[@Theseus](https://leetcode.cn/u/great-vaughannym/)大佬的提醒！！

本题中题目描述说明了“sequences[i] 是 nums 的子序列”，因此所构建的图**不会存在自环**。

因此不必检查“是否所有节点的入度都为0”，这是判断是否能进行拓扑排序的（有向无环图才能进行拓扑排序）

只需要满足上述两个条件中的第一个即可返回```true```

---

+ 时间复杂度$O(n + m)$，其中$n$是排列的长度，$m$是$sequences$中元素的个数
+ 空间复杂度$O(n + m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<vector<int>> from(n + 1);
        vector<int> inDegree(n + 1, 0);
        for (vector<int>& v : sequences) {
            for (int i = 1; i < v.size(); i++) {  // v[i - 1] → v[i]
                from[v[i - 1]].push_back(v[i]);
                inDegree[v[i]]++;
            }
        }
        queue<int> zero;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                zero.push(i);
            }
        }
        while (zero.size()) {
            if (zero.size() != 1)
                return false;
            int thisFrom = zero.front();
            zero.pop();
            for (int& thisTo : from[thisFrom]) {
                inDegree[thisTo]--;
                if (!inDegree[thisTo]) {
                    zero.push(thisTo);
                }
            }
        }
        // for (int i = 1; i <= n; i++) {  // 这里并不需要！
        //     if (inDegree[i])
        //         return false;
        // }
        return true;
    }
};
```

#### Java

🔥 感谢 [@Fomalhaut1998](https://leetcode.cn/u/fomalhaut1998/)大佬 提供Java版本的代码~

```Java
class Solution {
    public boolean sequenceReconstruction(int[] nums, int[][] seq) {
        /*
        拓扑排序:
        1 <= n <= 1e4
        1 <= sequences[i].length <= 1e4
        1 <= sum(sequences[i].length) <= 1e5
        我们先将seq表示的子序列顺序都保存为一张图，并能统计每一个节点的对应的入度
        要满足题目要求必须满足3个条件:
        1.入度为0的节点只能有1个，否则出来的超序列不唯一
        2.不能成环，否则出来的超序列不唯一
        3.最后入队的节点数=n，否则不能保证超序列最短
        如果全部满足返回true，构造返回false
         */
        int n = nums.length;
        boolean[] vis = new boolean[n + 1];
        List<Integer>[] edges = new List[n + 1];
        for (int i = 0; i <= n; i++) {
            edges[i] = new ArrayList<>();
        }
        // 建图
        for (int[] p : seq) {
            for (int j = 0; j < p.length - 1; j++) {
                edges[p[j]].add(p[j + 1]);
            }
        }
        int[] inDegree = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            for (Integer ne : edges[i]) {
                inDegree[ne]++;
            }
        }
        Queue<Integer> que = new LinkedList<>();
        int cnt = 0;    // 统计某一时间入度为0的节点数目
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                que.add(i);
                vis[i] = true;
                cnt++;
            }
            if (cnt > 1) return false;  // >1个节点入度为0返回false
        }
        while (!que.isEmpty()) {
            int p = que.poll(); // 要删除的节点
            cnt = 0;
            for (Integer ne : edges[p]) {
                if (--inDegree[ne] == 0) {
                    que.add(ne);
                    vis[ne] = true;
                    cnt++;
                }
            }
            if (cnt > 1) return false;
        }
        // 环检测
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] != 0) return false;
        }
        // 检测是否n个节点都入队了
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) return false;
        }
        return true;
    }
}
```

#### TypeScript

🔥 感谢 [@木鲸](https://leetcode.cn/u/woodwhale/)大佬 提供TypeScript版本的代码~

```TypeScript
function sequenceReconstruction(nums: number[], sequences: number[][]): boolean {
    let len: number = nums.length
    let map: number[][] = new Array(len+1)  // map[i]表示i指向的儿子们
    for (let i = 0; i < map.length; i++) map[i] = new Array()
    let degree: number[] = new Array(len + 1).fill(0)
    degree[0] = -1  // degree[i]表示i的度数，nums是从1开始的，所以0没用

    // 存入map
    sequences.forEach(it => {
        for (let i = 1; i < it.length; i++) {
            map[it[i-1]].push(it[i])
            degree[it[i]]++
        }
    })

    // 拓扑排序
    let que: number[] = []
    degree.forEach((it, idx) => {if (it === 0) que.push(idx)}) // 入度为0的数字进入队列

    while (que.length) {
        if (que.length > 1) return false  // 如果有多个入度为0的点，那么就是无法推测唯一最短序列
        let idx: number = que.shift()
        let sons: number[] = map[idx]
        sons.forEach(it => {
            degree[it]-- // 所有的儿子，入度-1
            if (!degree[it]) que.push(it)  // 再次查找入度为0的节点
        })
    }

    return !degree.some((val) => val > 0)   // 如果存在入度大于0的，证明有问题
}
```

**图片制作不易，喜欢了就点个赞再走吧~**

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/23/LeetCode%20%E5%89%91%E6%8C%87%20Offer%20II%200115.%20%E9%87%8D%E5%BB%BA%E5%BA%8F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125945290](https://letmefly.blog.csdn.net/article/details/125945290)