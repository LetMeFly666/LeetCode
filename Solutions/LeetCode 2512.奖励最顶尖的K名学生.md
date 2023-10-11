---
title: 2512.奖励最顶尖的 K 名学生
date: 2023-10-11 09:55:48
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, set, map, 字符串, 排序, 堆（优先队列）, 设计]
---

# 【LetMeFly】2512.奖励最顶尖的 K 名学生：哈希表设计

力扣题目链接：[https://leetcode.cn/problems/reward-top-k-students/](https://leetcode.cn/problems/reward-top-k-students/)

<p>给你两个字符串数组&nbsp;<code>positive_feedback</code> 和&nbsp;<code>negative_feedback</code>&nbsp;，分别包含表示正面的和负面的词汇。<strong>不会</strong>&nbsp;有单词同时是正面的和负面的。</p>

<p>一开始，每位学生分数为&nbsp;<code>0</code>&nbsp;。每个正面的单词会给学生的分数 <strong>加&nbsp;</strong><code>3</code>&nbsp;分，每个负面的词会给学生的分数 <strong>减&nbsp;</strong>&nbsp;<code>1</code>&nbsp;分。</p>

<p>给你&nbsp;<code>n</code>&nbsp;个学生的评语，用一个下标从 <strong>0</strong>&nbsp;开始的字符串数组&nbsp;<code>report</code>&nbsp;和一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>student_id</code>&nbsp;表示，其中&nbsp;<code>student_id[i]</code>&nbsp;表示这名学生的 ID ，这名学生的评语是&nbsp;<code>report[i]</code>&nbsp;。每名学生的 ID <strong>互不相同</strong>。</p>

<p>给你一个整数&nbsp;<code>k</code>&nbsp;，请你返回按照得分&nbsp;<strong>从高到低</strong>&nbsp;最顶尖的<em>&nbsp;</em><code>k</code>&nbsp;名学生。如果有多名学生分数相同，ID 越小排名越前。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
<b>输出：</b>[1,2]
<b>解释：</b>
两名学生都有 1 个正面词汇，都得到 3 分，学生 1 的 ID 更小所以排名更前。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious","the student is smart"], student_id = [1,2], k = 2
<b>输出：</b>[2,1]
<b>解释：</b>
- ID 为 1 的学生有 1 个正面词汇和 1 个负面词汇，所以得分为 3-1=2 分。
- ID 为 2 的学生有 1 个正面词汇，得分为 3 分。
学生 2 分数更高，所以返回 [2,1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= positive_feedback.length, negative_feedback.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= positive_feedback[i].length, negative_feedback[j].length &lt;= 100</code></li>
	<li><code>positive_feedback[i]</code> 和&nbsp;<code>negative_feedback[j]</code>&nbsp;都只包含小写英文字母。</li>
	<li><code>positive_feedback</code> 和&nbsp;<code>negative_feedback</code>&nbsp;中不会有相同单词。</li>
	<li><code>n == report.length == student_id.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>report[i]</code>&nbsp;只包含小写英文字母和空格&nbsp;<code>' '</code>&nbsp;。</li>
	<li><code>report[i]</code>&nbsp;中连续单词之间有单个空格隔开。</li>
	<li><code>1 &lt;= report[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= student_id[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>student_id[i]</code>&nbsp;的值 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


    
## 方法一：哈希表设计

对于一句评语，我们可以以空格未依据将其分为不同的单词。

如何快速判断某个单词得多少分呢？只需要预处理一下，将正负单词预先放入哈希表中，这样就能快速判断某个单词是否为“正负性词语”了。

怎么选出得分最高的$k$个$id$呢？题目中说$student_id[i]$的值互不相同，也就是说每个学生最多收到一次评语，因此我们直接将```[负的得分, 学生id]```放入一个数组中，最后排个序选前$k$个的$id$即可。

+ 时间复杂度$O((len(positive\_feedback) + len(negative\_feedback))\times L + len(student\_id)\log len(student\_id))$，其中$L$为一个单词的平均长度
+ 空间复杂度$O((len(positive\_feedback) + len(negative\_feedback))\times L + len(student\_id))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> postive, negative;
        for (string& s : positive_feedback) {
            postive.insert(s);
        }
        for (string& s : negative_feedback) {
            negative.insert(s);
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < report.size(); i++) {
            int lastSpace = -1;
            int thisScore = 0;
            for (int j = 0; j <= report[i].size(); j++) {
                if (j == report[i].size() || report[i][j] == ' ') {  // (lastSpace, j)
                    string thisWord = report[i].substr(lastSpace + 1, j - lastSpace - 1);
                    lastSpace = j;
                    if (postive.count(thisWord)) {
                        thisScore += 3;
                    }
                    else if (negative.count(thisWord)) {
                        thisScore -= 1;
                    }
                }
            }
            v.push_back({-thisScore, student_id[i]});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        mp = {}
        for s in positive_feedback:
            mp[s] = -3
        for s in negative_feedback:
            mp[s] = 1
        v = []
        for i in range(len(report)):
            v.append([sum(mp.get(word, 0) for word in report[i].split()), student_id[i]])
        v.sort()
        return [t[1] for t in v[:k]]
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/10/11/LeetCode%202512.%E5%A5%96%E5%8A%B1%E6%9C%80%E9%A1%B6%E5%B0%96%E7%9A%84K%E5%90%8D%E5%AD%A6%E7%94%9F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133762019](https://letmefly.blog.csdn.net/article/details/133762019)
