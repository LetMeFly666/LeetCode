---
title: 904.水果成篮
date: 2022-10-17 09:39:00
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】两种方法小详解：904.水果成篮

力扣题目链接：[https://leetcode.cn/problems/fruit-into-baskets/](https://leetcode.cn/problems/fruit-into-baskets/)

<p>你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 <code>fruits</code> 表示，其中 <code>fruits[i]</code> 是第 <code>i</code> 棵树上的水果 <strong>种类</strong> 。</p>

<p>你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：</p>

<ul>
	<li>你只有 <strong>两个</strong> 篮子，并且每个篮子只能装 <strong>单一类型</strong> 的水果。每个篮子能够装的水果总量没有限制。</li>
	<li>你可以选择任意一棵树开始采摘，你必须从 <strong>每棵</strong> 树（包括开始采摘的树）上 <strong>恰好摘一个水果</strong> 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。</li>
	<li>一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。</li>
</ul>

<p>给你一个整数数组 <code>fruits</code> ，返回你可以收集的水果的 <strong>最大</strong> 数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>fruits = [<em><strong>1,2,1</strong></em>]
<strong>输出：</strong>3
<strong>解释：</strong>可以采摘全部 3 棵树。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>fruits = [0,<em><strong>1,2,2</strong></em>]
<strong>输出：</strong>3
<strong>解释：</strong>可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>fruits = [1,<em><strong>2,3,2,2</strong></em>]
<strong>输出：</strong>4
<strong>解释：</strong>可以采摘 [2,3,2,2] 这四棵树。
如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>fruits = [3,3,3,<em><strong>1,2,1,1,2</strong></em>,3,3,4]
<strong>输出：</strong>5
<strong>解释：</strong>可以采摘 [1,2,1,1,2] 这五棵树。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= fruits[i] &lt; fruits.length</code></li>
</ul>


    
## 方法一：先存为[<5个3>, <6个2>, ...]，再统计

这种方法实现起来没有方法二简单，并且其空间复杂度也比方法二高，但优势是使用了较少的STL，在力扣上提交的结果中执行时间小于方法二（方法一用时88ms击败87%，方法二用时140ms击败46%）。如果觉得方法一复杂，也可以直接跳到[方法二](#LetMeFly_Method2)。

这种方法的核心思想是“划分”，即：将相同的水果合并到一起。

加入原始水果为```[3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, ...]```，那么我们就将原始水果存为```<3, 5>, <2, 6>```

这样预处理的时间复杂度是$O(n)$，其好处是：不用再往前逐个寻找某种水果是从下标几开始的。因为我们只需要关注两种水果，所以一旦遇到了第三种水果，我们可以立刻将“上上种水果”舍弃。

之后我们就可以愉快地遍历了，记录一下第一种水果和第二种水果的种类，接着开始往后遍历，当水果种类等于第一种或者第二种时，不断往后遍历并将水果累加（比如```3, 2, 3, 2, 3, ...```），直到遇到了第三种水果为止，更新答案最大值，并更新“水果1”和“水果2”

+ 时间复杂度$O(n)$，其中$n$是水果个数
+ 空间复杂度$O(M)$，其中$M$是相邻不相同的水果种类数

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;  // <number, times> 比如<5, 3>：5出现了3次
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
		// 存为[<5个3>, <6个2>, ...]
        vector<pii> append;
        int lastNum = fruits[0], cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (i == n || fruits[i] != fruits[i - 1]) {
                append.push_back({fruits[i - 1], cnt});
                cnt = 0;
            }
            cnt++;
        }
        if (append.size() == 1)
            return append[0].second;
		// 开始统计
        int firstTypeLoc = 0, secondTypeLoc = 1;
        int cntTimes = append[0].second + append[1].second;
        int ans = cntTimes;
        for (int nowTypeLoc = 2; nowTypeLoc < append.size(); nowTypeLoc++) {
            while (nowTypeLoc < append.size() && (append[nowTypeLoc].first == append[firstTypeLoc].first || append[nowTypeLoc].first == append[secondTypeLoc].first)) {  // 第三种水果和前两种水果之一相同
                cntTimes += append[nowTypeLoc++].second;
            }
            ans = max(ans, cntTimes);
            if (nowTypeLoc == append.size()) {
                break;
            }
			// 更新水果1和水果2
            firstTypeLoc = nowTypeLoc - 1;
            secondTypeLoc = nowTypeLoc;
            cntTimes = append[firstTypeLoc].second + append[secondTypeLoc].second;
        }
        ans = max(ans, cntTimes);  // 此行不可去掉
        return ans;
    }
};
```

<a id="LetMeFly_Method2"></a>

## 方法二：滑动窗口，哈希表助阵

方法一的核心是“纵览全局，统筹大局”，将一个一个分散的水果化为了一堆一堆的水果，相同且连续的水果再多，都只是“一堆”

但是其代价就是需要额外的空间来存放统计的结果。

方法二中，我们使用滑动窗口，时时遍历，时时统计，不预先处理。

使用一个“左指针”```left```和一个“右指针”```right```，在```[left, right]```中的水果是能够两筐放得下的水果。

右指针不断右移（扩大窗口），如果水果种类数超过了三种，左指针就开始右移（缩小窗口），直到水果种类再次为2

这样，左指针和右指针最多分别从前到后遍历一次，总时间复杂度是$O(n)$

至于窗口中有哪些水果，可以用哈希表来存放。因为最多有两种合法水果，所以哈希表中最多同时出现三种键值，总空间复杂度是$O(1)$

+ 时间复杂度$O(n)$，其中$n$是水果个数
+ 空间复杂度$O(1)$，但是需要将水果个数为0的水果从哈希表中erase掉（虽是常数复杂度，但是时间开销挺大的）

### AC代码

#### C++

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            cnt[fruits[right]]++;
            while (cnt.size() > 2) {
                unordered_map<int, int>::iterator it = cnt.find(fruits[left]);
                it->second--;
                left++;
                if (!it->second) {
                    cnt.erase(it);
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/17/LeetCode%200904.%E6%B0%B4%E6%9E%9C%E6%88%90%E7%AF%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127358126](https://letmefly.blog.csdn.net/article/details/127358126)
