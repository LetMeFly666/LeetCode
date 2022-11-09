---
title: 735.行星碰撞
date: 2022-07-13 22:56:42
tags: [题解, LeetCode, 中等, 栈, 数组, 列表, 趣]
---

# 【LetMeFly】735.行星碰撞：vector优化

力扣题目链接：[https://leetcode.cn/problems/asteroid-collision/](https://leetcode.cn/problems/asteroid-collision/)

<p>给定一个整数数组 <code>asteroids</code>，表示在同一行的行星。</p>

<p>对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。</p>

<p>找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>asteroids = [5,10,-5]
<strong>输出：</strong>[5,10]
<b>解释：</b>10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>asteroids = [8,-8]
<strong>输出：</strong>[]
<b>解释：</b>8 和 -8 碰撞后，两者都发生爆炸。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>asteroids = [10,2,-5]
<strong>输出：</strong>[10]
<b>解释：</b>2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= asteroids.length&nbsp;&lt;= 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= asteroids[i] &lt;= 1000</code></li>
	<li><code>asteroids[i] != 0</code></li>
</ul>


    

我觉得这道题题目非常有意思

## 方法一：用列表

从左向右遍历小行星asteroids，如果这个小行星方向向右，就添加到列表中。否则，不断从列表后面取出行星，和遍历到的行星进行碰撞，直到列表为空或遍历到的行星爆炸为止，若遍历到的行星没有爆炸，就添加到答案中。

最后把列表中的行星从前到后依次添加到答案中即可。

其实这道题用栈而不用列表的话回更容易了解。至于为什么用列表而不是用栈，是因为栈不能从栈底到栈顶遍历。若使用栈，则最终还需要用一个额外的临时栈来把栈中的元素reverse一遍

+ 时间复杂度$O(n)$，其中$n$是小行星asteroids的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        list<int> lr;  // From left to right
        for (int &t : asteroids) {
            if (t > 0)
                lr.push_back(t);
            else {
                bool destroyed = false;
                while (lr.size()) {
                    int Mlr = lr.back();
                    if (Mlr < abs(t)) {
                        lr.pop_back();
                    }
                    else if (Mlr == abs(t)) {
                        lr.pop_back();
                        destroyed = true;
                        break;
                    }
                    else {
                        destroyed = true;
                        break;
                    }
                }
                if (!destroyed)
                    ans.push_back(t);
            }
        }
        for (int &t : lr) {
            ans.push_back(t);
        }
        return ans;
    }
};
```


    
## 方法一：直接用数组

方法二是方法一的优化。我们可以不适用列表，而是直接使用数组来代替列表。

数组中小于0的数是待返回的答案，大于0的数是原始列表中的数。

最终也不用再由列表添加到答案中了，很巧一方法。

+ 时间复杂度$O(n)$，其中$n$是小行星asteroids的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;  // From left to right
        for (int &t : asteroids) {
            if (t > 0) {
                ans.push_back(t);
            }
            else {
                bool alive = true;
                while (alive && ans.size() && ans.back() > 0) {
                    alive = ans.back() < -t;
                    if (ans.back() <= -t)
                        ans.pop_back();
                }
                if (alive)
                    ans.push_back(t);
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/13/LeetCode%200735.%E8%A1%8C%E6%98%9F%E7%A2%B0%E6%92%9E/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125774687](https://letmefly.blog.csdn.net/article/details/125774687)
