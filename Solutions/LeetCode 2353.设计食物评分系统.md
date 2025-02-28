---
title: 2353.设计食物评分系统：哈希表 + 有序集合
date: 2025-02-28 13:33:16
tags: [题解, LeetCode, 中等, 设计, 哈希表, map, set, 有序集合, 堆（优先队列）]
---

# 【LetMeFly】2353.设计食物评分系统：哈希表 + 有序集合

力扣题目链接：[https://leetcode.cn/problems/design-a-food-rating-system/](https://leetcode.cn/problems/design-a-food-rating-system/)

<p>设计一个支持下述操作的食物评分系统：</p>

<ul>
	<li><strong>修改</strong> 系统中列出的某种食物的评分。</li>
	<li>返回系统中某一类烹饪方式下评分最高的食物。</li>
</ul>

<p>实现 <code>FoodRatings</code> 类：</p>

<ul>
	<li><code>FoodRatings(String[] foods, String[] cuisines, int[] ratings)</code> 初始化系统。食物由 <code>foods</code>、<code>cuisines</code> 和 <code>ratings</code> 描述，长度均为 <code>n</code> 。

	<ul>
		<li><code>foods[i]</code> 是第 <code>i</code> 种食物的名字。</li>
		<li><code>cuisines[i]</code> 是第 <code>i</code> 种食物的烹饪方式。</li>
		<li><code>ratings[i]</code> 是第 <code>i</code> 种食物的最初评分。</li>
	</ul>
	</li>
	<li><code>void changeRating(String food, int newRating)</code> 修改名字为 <code>food</code> 的食物的评分。</li>
	<li><code>String highestRated(String cuisine)</code> 返回指定烹饪方式 <code>cuisine</code> 下评分最高的食物的名字。如果存在并列，返回 <strong>字典序较小</strong> 的名字。</li>
</ul>

<p>注意，字符串 <code>x</code> 的字典序比字符串 <code>y</code> 更小的前提是：<code>x</code> 在字典中出现的位置在 <code>y</code> 之前，也就是说，要么 <code>x</code> 是 <code>y</code> 的前缀，或者在满足&nbsp;<code>x[i] != y[i]</code> 的第一个位置 <code>i</code> 处，<code>x[i]</code> 在字母表中出现的位置在 <code>y[i]</code> 之前。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入</strong>
["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
<strong>输出</strong>
[null, "kimchi", "ramen", null, "sushi", null, "ramen"]

<strong>解释</strong>
FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
foodRatings.highestRated("korean"); // 返回 "kimchi"
                                    // "kimchi" 是分数最高的韩式料理，评分为 9 。
foodRatings.highestRated("japanese"); // 返回 "ramen"
                                      // "ramen" 是分数最高的日式料理，评分为 14 。
foodRatings.changeRating("sushi", 16); // "sushi" 现在评分变更为 16 。
foodRatings.highestRated("japanese"); // 返回 "sushi"
                                      // "sushi" 是分数最高的日式料理，评分为 16 。
foodRatings.changeRating("ramen", 16); // "ramen" 现在评分变更为 16 。
foodRatings.highestRated("japanese"); // 返回 "ramen"
                                      // "sushi" 和 "ramen" 的评分都是 16 。
                                      // 但是，"ramen" 的字典序比 "sushi" 更小。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>n == foods.length == cuisines.length == ratings.length</code></li>
	<li><code>1 &lt;= foods[i].length, cuisines[i].length &lt;= 10</code></li>
	<li><code>foods[i]</code>、<code>cuisines[i]</code> 由小写英文字母组成</li>
	<li><code>1 &lt;= ratings[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>foods</code> 中的所有字符串 <strong>互不相同</strong></li>
	<li>在对&nbsp;<code>changeRating</code> 的所有调用中，<code>food</code> 是系统中食物的名字。</li>
	<li>在对&nbsp;<code>highestRated</code> 的所有调用中，<code>cuisine</code> 是系统中 <strong>至少一种</strong> 食物的烹饪方式。</li>
	<li>最多调用 <code>changeRating</code> 和 <code>highestRated</code> <strong>总计</strong> <code>2 * 10<sup>4</sup></code> 次</li>
</ul>


    
## 解题方法：设计

哈希表可以通过一个值快速找到拎一个值，有序集合可以快速插入删除一些值并保持集合中元素的有序性。

+ 创建一个哈希表，由food查询cuisine和rating；
+ 创建一个哈希表，由cuisine查询所有使用这个cuisine的`(food, rating)`集合，集合的排序方式是rating大优先然后字典序小优先。

修改评分时，先由food查询出cuisine和rating，再由cuisine查询出使用这个cuisine的`(food, rating)`集合，删除旧的`(food, rating)`对，插入新的`(food, rating)`对。

查询时，由cuisine查询出使用这个cuisine的`(food, rating)`集合，因为是有序的，所以集合中的第一个元素对就是我们所求。

+ 时间复杂度：初始化$O(n\log n)$，单次操作$O(\log n)$，其中$n$是食物数量
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-28 11:12:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-28 11:29:56
 */
class FoodRatings {
private:
    unordered_map<string, pair<string, int>> food2cuisineScore;        // food->(cuisine, score)
    unordered_map<string, set<pair<int, string>>> cuisine2rscoreFood;  // cuisine->[(-score, food), ...]
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            food2cuisineScore[foods[i]] = {cuisines[i], ratings[i]};
            cuisine2rscoreFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, score] = food2cuisineScore[food];
        food2cuisineScore[food] = {cuisine, newRating};
        cuisine2rscoreFood[cuisine].erase({-score, food});
        cuisine2rscoreFood[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*cuisine2rscoreFood[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-28 11:30:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-28 12:28:00
'''
from typing import List
from sortedcontainers import SortedList
from collections import defaultdict


class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.f2cs = dict()
        self.c2rf = defaultdict(SortedList)
        for i in range(len(foods)):
            self.f2cs[foods[i]] = (cuisines[i], ratings[i])
            self.c2rf[cuisines[i]].add((-ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine, rating = self.f2cs[food]
        self.f2cs[food] = (cuisine, newRating)
        self.c2rf[cuisine].discard((-rating, food))
        self.c2rf[cuisine].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        return self.c2rf[cuisine][0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-28 12:31:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-28 12:58:08
 * @Say: Java是真复杂
 */
import java.util.HashMap;
import java.util.Map;
import java.util.TreeSet;


final class Pair<K extends Comparable<K>, V extends Comparable<V>> implements Comparable<Pair<K, V>> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K first() {
        return key;
    }

    public V second() {
        return value;
    }

    @Override
    public int compareTo(Pair<K, V> other) {
        int keyCompare = this.key.compareTo(other.key);
        if (keyCompare != 0) {
            return keyCompare;
        }
        return this.value.compareTo(other.value);
    }

    @Override
    public String toString() {
        return "Pair{" + "key=" + key + ", value=" + value + '}';
    }
}


class FoodRatings {
    private Map<String, Pair<String, Integer>> f2cr = new HashMap<>();
    private Map<String, TreeSet<Pair<Integer, String>>> c2rf = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; i++) {
            f2cr.put(foods[i], new Pair<>(cuisines[i], ratings[i]));
            c2rf.computeIfAbsent(cuisines[i], k -> new TreeSet<>());
            c2rf.get(cuisines[i]).add(new Pair<>(-ratings[i], foods[i]));
        }
    }
    
    public void changeRating(String food, int newRating) {
        Pair<String, Integer> temp = f2cr.get(food);
        String cuisine = temp.first();
        int rating = temp.second();
        f2cr.put(food, new Pair<>(cuisine, newRating));

        TreeSet<Pair<Integer, String>> list = c2rf.get(cuisine);
        list.remove(new Pair<>(-rating, food));
        list.add(new Pair<>(-newRating, food));
    }
    
    public String highestRated(String cuisine) {
        return c2rf.get(cuisine).first().second();
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145926792)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/28/LeetCode%202353.%E8%AE%BE%E8%AE%A1%E9%A3%9F%E7%89%A9%E8%AF%84%E5%88%86%E7%B3%BB%E7%BB%9F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
