---
title: 1773.统计匹配检索规则的物品数量
date: 2022-10-29 09:04:28
tags: [题解, LeetCode, 简单, 数组, 字符串]
---

# 【LetMeFly】1773.统计匹配检索规则的物品数量(5行核心代码)

力扣题目链接：[https://leetcode.cn/problems/count-items-matching-a-rule/](https://leetcode.cn/problems/count-items-matching-a-rule/)

<p>给你一个数组 <code>items</code> ，其中 <code>items[i] = [type<sub>i</sub>, color<sub>i</sub>, name<sub>i</sub>]</code> ，描述第 <code>i</code> 件物品的类型、颜色以及名称。</p>

<p>另给你一条由两个字符串 <code>ruleKey</code> 和 <code>ruleValue</code> 表示的检索规则。</p>

<p>如果第 <code>i</code> 件物品能满足下述条件之一，则认为该物品与给定的检索规则 <strong>匹配</strong> ：</p>

<ul>
	<li><code>ruleKey == "type"</code> 且 <code>ruleValue == type<sub>i</sub></code> 。</li>
	<li><code>ruleKey == "color"</code> 且 <code>ruleValue == color<sub>i</sub></code> 。</li>
	<li><code>ruleKey == "name"</code> 且 <code>ruleValue == name<sub>i</sub></code> 。</li>
</ul>

<p>统计并返回 <strong>匹配检索规则的物品数量</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
<strong>输出：</strong>1
<strong>解释：</strong>只有一件物品匹配检索规则，这件物品是 ["computer","silver","lenovo"] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
<strong>输出：</strong>2
<strong>解释：</strong>只有两件物品匹配检索规则，这两件物品分别是 ["phone","blue","pixel"] 和 ["phone","gold","iphone"] 。注意，["computer","silver","phone"] 未匹配检索规则。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= items.length <= 10<sup>4</sup></code></li>
	<li><code>1 <= type<sub>i</sub>.length, color<sub>i</sub>.length, name<sub>i</sub>.length, ruleValue.length <= 10</code></li>
	<li><code>ruleKey</code> 等于 <code>"type"</code>、<code>"color"</code> 或 <code>"name"</code></li>
	<li>所有字符串仅由小写字母组成</li>
</ul>


    
## 方法一：遍历

由参数“ruleKey”可以得到我们关注的是数组中的第几个元素：

+ 若为“type”则我们只关注下标0
+ 若为“color”则我们只关注下标1
+ 若为“name”则我们只关注下标2

这是因为“item”的存放顺序为“[type, color, name]”

知道了我们关注的是第几个元素之后，我们只需要遍历一遍“items”数组，将每个“item”的对应元素与“ruleValue”比对，若相同则答案数量加一。

最终只需要返回答案即可。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string& ruleKey, string& ruleValue) {
        int ans = 0;
        int th = (ruleKey == "type") ? 0 : (ruleKey == "color" ? 1 : 2);
        for (auto& item : items) {
            ans += item[th] == ruleValue;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/29/LeetCode%201773.%E7%BB%9F%E8%AE%A1%E5%8C%B9%E9%85%8D%E6%A3%80%E7%B4%A2%E8%A7%84%E5%88%99%E7%9A%84%E7%89%A9%E5%93%81%E6%95%B0%E9%87%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127582940](https://letmefly.blog.csdn.net/article/details/127582940)
