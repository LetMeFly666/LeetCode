---
title: 2682.找出转圈游戏输家
date: 2023-08-16 08:43:57
tags: [题解, LeetCode, 简单, 数组, 哈希表, 模拟]
---

# 【LetMeFly】2682.找出转圈游戏输家

力扣题目链接：[https://leetcode.cn/problems/find-the-losers-of-the-circular-game/](https://leetcode.cn/problems/find-the-losers-of-the-circular-game/)

<p><code>n</code> 个朋友在玩游戏。这些朋友坐成一个圈，按 <strong>顺时针方向</strong> 从 <code>1</code> 到 <code>n</code> 编号。从第 <code>i</code> 个朋友的位置开始顺时针移动 <code>1</code> 步会到达第 <code>(i + 1)</code> 个朋友的位置（<code>1 &lt;= i &lt; n</code>），而从第 <code>n</code> 个朋友的位置开始顺时针移动 <code>1</code> 步会回到第 <code>1</code> 个朋友的位置。</p>

<p>游戏规则如下：</p>

<p>第 <code>1</code> 个朋友接球。</p>

<ul>
	<li>接着，第 <code>1</code> 个朋友将球传给距离他顺时针方向 <code>k</code> 步的朋友。</li>
	<li>然后，接球的朋友应该把球传给距离他顺时针方向 <code>2 * k</code> 步的朋友。</li>
	<li>接着，接球的朋友应该把球传给距离他顺时针方向 <code>3 * k</code> 步的朋友，以此类推。</li>
</ul>

<p>换句话说，在第 <code>i</code> 轮中持有球的那位朋友需要将球传递给距离他顺时针方向 <code>i * k</code> 步的朋友。</p>

<p>当某个朋友第 2 次接到球时，游戏结束。</p>

<p>在整场游戏中没有接到过球的朋友是 <strong>输家</strong> 。</p>

<p>给你参与游戏的朋友数量 <code>n</code> 和一个整数 <code>k</code> ，请按升序排列返回包含所有输家编号的数组 <code>answer</code> 作为答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5, k = 2
<strong>输出：</strong>[4,5]
<strong>解释：</strong>以下为游戏进行情况：
1）第 1 个朋友接球，第 <code>1</code> 个朋友将球传给距离他顺时针方向 2 步的玩家 —— 第 3 个朋友。
2）第 3 个朋友将球传给距离他顺时针方向 4 步的玩家 —— 第 2 个朋友。
3）第 2 个朋友将球传给距离他顺时针方向 6 步的玩家 —— 第 3 个朋友。
4）第 3 个朋友接到两次球，游戏结束。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, k = 4
<strong>输出：</strong>[2,3,4]
<strong>解释：</strong>以下为游戏进行情况：
1）第 1 个朋友接球，第 <code>1</code> 个朋友将球传给距离他顺时针方向 4 步的玩家 —— 第 1 个朋友。
2）第 1 个朋友接到两次球，游戏结束。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 50</code></li>
</ul>


    
## 方法一：模拟

开辟一个长度为$n$的布尔类型的数组$visited$，初始值全部为$0$，用来记录哪个小朋友拿到过球。

使用两个变量$who$和$th$分别记录当前球在谁的手里、这是第几次传球。

当$visited[who]$为$false$时，不断更新$visited$、$who$、$th$。

最终，遍历一遍$visited$数组，将没接到过球的娃子添加到答案数组中即可。

+ 时间复杂度$O(n)$，每个人最多接到球$1$次（第二次还没接就退出循环了）
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n);
        int who = 0, th = 0;
        while (!visited[who]) {
            visited[who] = true;
            who = (who + ++th * k) % n;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def circularGameLosers(self, n: int, k: int) -> List[int]:
        visited = [False] * n
        who, th = 0, 0
        while not visited[who]:
            visited[who] = True
            th += 1
            who = (who + th * k) % n
        ans = []
        for i in range(n):
            if not visited[i]:
                ans.append(i + 1)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/16/LeetCode%202682.%E6%89%BE%E5%87%BA%E8%BD%AC%E5%9C%88%E6%B8%B8%E6%88%8F%E8%BE%93%E5%AE%B6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132311270](https://letmefly.blog.csdn.net/article/details/132311270)
