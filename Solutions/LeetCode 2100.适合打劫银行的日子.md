---
title: 2100.适合打劫银行的日子
date: 2023-09-26 22:02:10
tags: [题解, LeetCode, 中等, 数组, 动态规划, 前缀和]
Description: 写于2022.4，尝试给代码随想录提PR被拒了，有了自己的博客后添加到了自己的博客上。
---

# 【LetMeFly】2100.适合打劫银行的日子

> 现在力扣上好像改题面为```2100. 适合野炊的日子```了。

力扣题目链接：[https://leetcode.cn/problems/find-good-days-to-rob-the-bank/](https://leetcode.cn/problems/find-good-days-to-rob-the-bank/)

<p>你和一群强盗准备打劫银行。给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>security</code>&nbsp;，其中&nbsp;<code>security[i]</code>&nbsp;是第 <code>i</code>&nbsp;天执勤警卫的数量。日子从 <code>0</code>&nbsp;开始编号。同时给你一个整数&nbsp;<code>time</code>&nbsp;。</p>

<p>如果第 <code>i</code>&nbsp;天满足以下所有条件，我们称它为一个适合打劫银行的日子：</p>

<ul>
	<li>第 <code>i</code>&nbsp;天前和后都分别至少有 <code>time</code>&nbsp;天。</li>
	<li>第 <code>i</code>&nbsp;天前连续 <code>time</code>&nbsp;天警卫数目都是非递增的。</li>
	<li>第 <code>i</code>&nbsp;天后连续 <code>time</code>&nbsp;天警卫数目都是非递减的。</li>
</ul>

<p>更正式的，第 <code>i</code> 天是一个合适打劫银行的日子当且仅当：<code>security[i - time] &gt;= security[i - time + 1] &gt;= ... &gt;= security[i] &lt;= ... &lt;= security[i + time - 1] &lt;= security[i + time]</code>.</p>

<p>请你返回一个数组，包含 <strong>所有</strong> 适合打劫银行的日子（下标从 <strong>0</strong>&nbsp;开始）。返回的日子可以 <strong>任意</strong>&nbsp;顺序排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>security = [5,3,3,3,5,6,2], time = 2
<b>输出：</b>[2,3]
<strong>解释：</strong>
第 2 天，我们有 security[0] &gt;= security[1] &gt;= security[2] &lt;= security[3] &lt;= security[4] 。
第 3 天，我们有 security[1] &gt;= security[2] &gt;= security[3] &lt;= security[4] &lt;= security[5] 。
没有其他日子符合这个条件，所以日子 2 和 3 是适合打劫银行的日子。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>security = [1,1,1,1,1], time = 0
<b>输出：</b>[0,1,2,3,4]
<strong>解释：</strong>
因为 time 等于 0 ，所以每一天都是适合打劫银行的日子，所以返回每一天。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>security = [1,2,3,4,5,6], time = 2
<b>输出：</b>[]
<strong>解释：</strong>
没有任何一天的前 2 天警卫数目是非递增的。
所以没有适合打劫银行的日子，返回空数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= security.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= security[i], time &lt;= 10<sup>5</sup></code></li>
</ul>


    
# 思路

## 方法一：分类讨论

<small> **时间复杂度$O(n)$，空间复杂度O(1)，难度※※** </small>

![https://leetcode-cn.com/problems/find-good-days-to-rob-the-bank/solution/letmefly-fen-lei-tao-lun-on-o1-by-letmef-1jgw/](https://pic.leetcode-cn.com/1646540562-QqloLO-0.jpg)

$time=0$的情况特殊考虑，每天都是“打劫日”。否则：

能够成为答案的一天，必定是 $前一天\geq这一天\leq下一天$

因此我们使用两个变量 $lianXuXiaDays$(表示非递增的天数)和$couldAsUp4Begin$(从此以后可以开始非递减的那一天)

也就是说，在连续$lianXuXiaDays$天的非递增后，若$lianXuXiaDays\geq time$，那么只要从**今天**起的连续$time$天都非递减，今天就“抢劫日”。

所以我们在$lianXuXiaDays\geq time$时，就可以将$couldAsUp4Begin$记为今天。

若之后的$time$天及以上都非递减，那么此时记录的$couldAsUp4Begin$就是一个“抢劫日”。

因此在向后的遍历中，如果仍然处于非递减状态，就可以判断是否有$couldAsUp4Begin$，如果有($\neq -1$)就判断今天距离$couldAsUp4Begin$是否$\geq time$天，如果$\geq time$，就说明$couldAsUp4Begin$后的连续$time$天都是非递减，因此$couldAsUp4Begin$就是一个抢劫日。

更加详细的描述可参考注释



### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        if (!time) {  // time = 0，每天都是“打劫日”
            vector<int> ans(security.size());  // 答案共有security.size()天
            for (int i = 0; i < security.size(); i++) {
                ans[i] = i;  // 第i个答案是第i天
            }
            return ans;
        }
        vector<int> ans;
        int lianXuXiaDays = 0;  // 连续↓或→的天数
        int couldAsUp4Begin = -1;  // 最早可以认为是开始连续上升的那一天 | 如果couldAsUp4Begin=a≠-1，说明第a天之前至少有time天的非递增
        for (int i = 1; i < security.size(); i++) {  // 从第二天开始遍历
            if (security[i] < security[i - 1]) {  // ↓
                lianXuXiaDays++;  // 连续非递增天数++
                if (lianXuXiaDays >= time) {  // 如果连续非递增天数≥time，那么今天之前就有≥time的非递减
                    couldAsUp4Begin = i;  // 从今天开始可以非递减了
                }
                else {  // 还没有连续非递增time天
                    couldAsUp4Begin = -1;
                }
            }
            else if (security[i] == security[i - 1]) {  // 今天和昨天相等，也就是说既符合非递增又符合非递减
                lianXuXiaDays++;  // 符合非递增，连续非递增天数++
                if (couldAsUp4Begin != -1) {  // 前面有≥time的非递减，并且从那天起没有递增的一天 | Lable1
                    if (i - couldAsUp4Begin >= time) {  // 如果今天距离那天≥time，那天就是抢劫日
                        ans.push_back(couldAsUp4Begin);  // 先把抢劫日添加到答案中去
                        if (security[couldAsUp4Begin + 1] <= security[couldAsUp4Begin]) {  // 如果抢劫日的下一天仍然是非递增，那么下一天之前肯定有至少time天的非递增
                            couldAsUp4Begin++;  // 下一天也可以作为开始非递减的一天
                        }
                        else {  // 否则
                            couldAsUp4Begin = -1;  // 下一天＞这个抢劫日，说明下一天必不满足“前面有至少time天的非递增”
                        }
                    }
                }
                else {  // couldAsUp4Begin = -1
                    if (lianXuXiaDays >= time) {  // 连续非递增天数≥time
                        couldAsUp4Begin = i;  // 从今天起可以开始非递减了
                    }
                }
            }
            else {  // 今 > 昨
                lianXuXiaDays = 0;  // 连续非递减天数中断
                if (couldAsUp4Begin != -1) {  // 这个同理于上面的“Lable1”处
                    if (i - couldAsUp4Begin >= time) {
                        ans.push_back(couldAsUp4Begin);
                        if (security[couldAsUp4Begin + 1] <= security[couldAsUp4Begin]) {
                            couldAsUp4Begin++;
                        }
                        else {
                            couldAsUp4Begin = -1;
                        }
                    }
                }
            }
        }
        return ans;  // 返回答案即可
    }
};
```

## 方法二

<small> **时间复杂度$O(n)$，空间复杂度O(n)，难度※** </small>

**这种方法比上一种方法更容易实现，但是空间复杂度比上种方法要高。**

我们可以用$O(n)$的时间复杂度求出每一天的“之前的连续非递增天数”和“之后的连续非递减天数”

$xia[i]$表示第$i$天之前有几天非递增，$shang[i]$表示第$i$天之前有几天非递减

<details>
<summary><b>具体方法：</b></summary>
从前向后遍历数组，如果<code>今天≤昨天</code>，那么<code>xia[i] = xia[i - 1] + 1</code>；否则，<code>xia[i] = 0</code>。初始值<code>xia[0] = 0</code>
从后向前遍历数组，如果<code>今天≤昨天</code>，那么<code>shang[i] = shang[i + 1] + 1</code>；否则，<code>shang[i] = 0</code>。初始值<code>shang[security.size() - 1] = 0</code>
</details>

然后我们遍历每一天，如果某天同时满足 $xia[i]\geq time$ 和 $shang[i] \geq time$，这天就是抢劫日。

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> xia(security.size());
        vector<int> shang(security.size());
        xia[0] = 0, shang[shang.size() - 1] = 0;
        for (int i = 1; i < security.size(); i++) {
            xia[i] = security[i] > security[i - 1] ? 0 : xia[i - 1] + 1;
        }
        for (int i = security.size() - 2; i >= 0; i--) {
            shang[i] = security[i] > security[i + 1] ? 0 : shang[i + 1] + 1;
        }
        vector<int> ans;
        for (int i = 0; i < security.size(); i++) {
            if (xia[i] >= time && shang[i] >= time)
                ans.push_back(i);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/09/26/LeetCode%202100.%E9%80%82%E5%90%88%E6%89%93%E5%8A%AB%E9%93%B6%E8%A1%8C%E7%9A%84%E6%97%A5%E5%AD%90/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133324938](https://letmefly.blog.csdn.net/article/details/133324938)
