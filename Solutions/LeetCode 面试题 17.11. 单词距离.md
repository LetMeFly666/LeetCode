---
title: 面试题17.11.单词距离
date: 2022-05-27 09:54:36
tags: [题解, LeetCode, 中等, 哈希, 双指针, 字符串]
---

# 【LetMeFly】面试题17.11.单词距离 - 可直接应用到题目进阶

力扣题目链接：[https://leetcode.cn/problems/find-closest-lcci/](https://leetcode.cn/problems/find-closest-lcci/)

有个内含单词的超大文本文件，给定任意两个不同的单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

**示例 1:**

```
输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
输出：1
```

**提示:**

+ $words.length \leq 100000$

# 思路

我们只需要使用哈希表，然后把单词出现的位置都记录下来，遍历两个单词出现的位置，找到间隔最小的即为答案。

## 方法一：哈希表

假如用C++实现，那么可以用```map<string, vector<int>>```来充当哈希表。

假如单词```LetMeFly```出现位置分别为：```0```、```5```、```7```，那么```ma["LetMeFly"]```就是```{0, 5, 7}```

只需要遍历一遍```words```，就能记录下来每个单词出现的位置。接下来问题就转化为：给定两个单词出现过的所有下标，让你找到这两个单词的最近下标是多少。

如果枚举两个单词出现过的下标，极端情况时间复杂度可能会达到$O(n^2)$（$n$是单词的数量）。因此我们可以使用双指针：

使用两个指针locloc1和locloc2，初始值分别为0，在locloc1和locloc2都在下标数组的范围内时，比较两个指针对应的值哪个大，然后就把对应值小的指针往后移。每次比较都更新答案的最小值即可。

+ 时间复杂度$O(n)$，其中$n$是单词个数。
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> ma;
        // 全部用哈希表记录
        for (int i = 0; i < words.size(); i++) {
            ma[words[i]].push_back(i);
        }
        vector<int>& loc1s = ma[word1];  // 第1个单词的所有下标
        vector<int>& loc2s = ma[word2];  // 第2个单词的所有下标
        if (loc1s.empty() || loc2s.empty()) {  // 如果单词1或单词2从来都没有出现过
            return -1;  // 题目好像没说不存在的情况
        }
        int ans = words.size();
        int locloc1 = 0, locloc2 = 0;  // 双指针
        while (locloc1 < loc1s.size() && locloc2 < loc2s.size()) {  // 两个指针都在数据范围内时
            ans = min(ans, abs(loc1s[locloc1] - loc2s[locloc2]));  // 更新答案最小值
            if (loc1s[locloc1] < loc2s[locloc2]) {
                locloc1++;  // 对应下标小的指针往后移
            }
            else {
                locloc2++;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/05/27/LeetCode%20%E9%9D%A2%E8%AF%95%E9%A2%98%2017.11.%20%E5%8D%95%E8%AF%8D%E8%B7%9D%E7%A6%BB/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/124998677](https://letmefly.blog.csdn.net/article/details/124998677)
