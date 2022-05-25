---
title: 49.字母异位词分组
date: 2022-05-25 19:29:07
tags: [题解, LeetCode, 中等, 哈希]
---

# 【LetMeFly】49.字母异位词分组

力扣题目链接：[https://leetcode.cn/problems/group-anagrams/](https://leetcode.cn/problems/group-anagrams/)

给你一个字符串数组，请你将**字母异位词**组合在一起。可以按任意顺序返回结果列表。

**字母异位词**是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

**示例 1:**

```
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**示例 2:**

```
输入: strs = [""]
输出: [[""]]
```

**示例 3:**

```
输入: strs = ["a"]
输出: [["a"]]
```

**提示:**

+ $1\leq strs.length\leq 10^4$
+ $0\leq strs[i].length\leq100$
+ $strs[i]$ 仅包含小写字母

# 题目大意

“字母异位词”是至每种字母出现次数都相同的单词。

> 例如“aba”和“aab”是“字母异位词”因为它们中“a”都出现了2次且“b”都出现了1次。

给你一些串，让你把这些串中同属于“字母异位词”的分为一组。

# 思路

对于每个单词，我们只需要计算出其中每个字母出现的次数，然后用哈希表对应到一个分组中即可。

## 方法一：哈希表

假如用C++实现，那么可以用```map<vector<int>, vector<string>>```来充当哈希表。

对于每一个字符串，我们为其建立一个```size```为26的```vector```，以此来记录每个字母出现的次数。

还可以用```vector<string>```来存放同组的字符串。

然后用这个计算出来的```vector```作为键值，映射到不同的每一组中去。

+ 时间复杂度$O(|n|)$，其中$|n|$是所有字符串的长度之和。
+ 空间复杂度$O(|n|)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> ma;
        for (string& s : strs) {
            vector<int> appendTime(26, 0);
            for (char& c : s) {
                appendTime[c - 'a']++;
            }
            ma[appendTime].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& [a, vs] : ma) {
            ans.push_back(vs);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/05/25/LeetCode%200049.%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D%E5%88%86%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/124972260](https://letmefly.blog.csdn.net/article/details/124972260)
