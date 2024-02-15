---
title: 2383.赢得比赛需要的最少训练时长
date: 2023-03-13 12:07:12
tags: [题解, LeetCode, 简单, 贪心, 数组]
---

# 【LetMeFly】2383.赢得比赛需要的最少训练时长

力扣题目链接：[https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/](https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition/)

<p>你正在参加一场比赛，给你两个 <strong>正</strong> 整数 <code>initialEnergy</code> 和 <code>initialExperience</code> 分别表示你的初始精力和初始经验。</p>

<p>另给你两个下标从 <strong>0</strong> 开始的整数数组 <code>energy</code> 和 <code>experience</code>，长度均为 <code>n</code> 。</p>

<p>你将会 <strong>依次</strong> 对上 <code>n</code> 个对手。第 <code>i</code> 个对手的精力和经验分别用 <code>energy[i]</code> 和 <code>experience[i]</code> 表示。当你对上对手时，需要在经验和精力上都 <strong>严格</strong> 超过对手才能击败他们，然后在可能的情况下继续对上下一个对手。</p>

<p>击败第 <code>i</code> 个对手会使你的经验 <strong>增加</strong> <code>experience[i]</code>，但会将你的精力 <strong>减少</strong>&nbsp; <code>energy[i]</code> 。</p>

<p>在开始比赛前，你可以训练几个小时。每训练一个小时，你可以选择将增加经验增加 1 <strong>或者</strong> 将精力增加 1 。</p>

<p>返回击败全部 <code>n</code> 个对手需要训练的 <strong>最少</strong> 小时数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>initialEnergy = 5, initialExperience = 3, energy = [1,4,3,2], experience = [2,6,3,1]
<strong>输出：</strong>8
<strong>解释：</strong>在 6 小时训练后，你可以将精力提高到 11 ，并且再训练 2 个小时将经验提高到 5 。
按以下顺序与对手比赛：
- 你的精力与经验都超过第 0 个对手，所以获胜。
  精力变为：11 - 1 = 10 ，经验变为：5 + 2 = 7 。
- 你的精力与经验都超过第 1 个对手，所以获胜。
  精力变为：10 - 4 = 6 ，经验变为：7 + 6 = 13 。
- 你的精力与经验都超过第 2 个对手，所以获胜。
  精力变为：6 - 3 = 3 ，经验变为：13 + 3 = 16 。
- 你的精力与经验都超过第 3 个对手，所以获胜。
  精力变为：3 - 2 = 1 ，经验变为：16 + 1 = 17 。
在比赛前进行了 8 小时训练，所以返回 8 。
可以证明不存在更小的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>initialEnergy = 2, initialExperience = 4, energy = [1], experience = [3]
<strong>输出：</strong>0
<strong>解释：</strong>你不需要额外的精力和经验就可以赢得比赛，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == energy.length == experience.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= initialEnergy, initialExperience, energy[i], experience[i] &lt;= 100</code></li>
</ul>


    
## 方法一：模拟

我们不需要预计算，只需要遍历对手，如果当前的精力**不高于**对手精力，就将精力提升至$对手精力+1$（同时将所提升的精力数量累加到答案中），经验同理。

当精力和经验提升后，我们就战胜当前对手，抵消对手的精力，汲取对手的经验。

最终返回答案即可

+ 时间复杂度$O(len(energy))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        for (int i = 0; i < energy.size(); i++) {
            if (initialEnergy <= energy[i]) {
                ans += energy[i] + 1 - initialEnergy;
                initialEnergy = energy[i] + 1;
            }
            if (initialExperience <= experience[i]) {
                ans += experience[i] + 1 - initialExperience;
                initialExperience = experience[i] + 1;
            }
            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
        ans = 0
        for i in range(len(experience)):
            if initialEnergy <= energy[i]:
                ans += energy[i] + 1 - initialEnergy
                initialEnergy = energy[i] + 1
            if initialExperience <= experience[i]:
                ans += experience[i] + 1 - initialExperience
                initialExperience = experience[i] + 1
            initialEnergy -= energy[i]
            initialExperience += experience[i]
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/13/LeetCode%202383.%E8%B5%A2%E5%BE%97%E6%AF%94%E8%B5%9B%E9%9C%80%E8%A6%81%E7%9A%84%E6%9C%80%E5%B0%91%E8%AE%AD%E7%BB%83%E6%97%B6%E9%95%BF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129490556](https://letmefly.blog.csdn.net/article/details/129490556)
