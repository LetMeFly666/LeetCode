---
title: 355.设计推特
date: 2022-10-04 09:16:05
tags: [题解, LeetCode, 中等, 设计, 哈希表, 哈希, 链表, 堆（优先队列）, 类, 设计]
---

# 【LetMeFly】355.设计推特

力扣题目链接：[https://leetcode.cn/problems/design-twitter/](https://leetcode.cn/problems/design-twitter/)

<p>设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近 <code>10</code> 条推文。</p>

<p>实现 <code>Twitter</code> 类：</p>

<ul>
	<li><code>Twitter()</code> 初始化简易版推特对象</li>
	<li><code>void postTweet(int userId, int tweetId)</code> 根据给定的 <code>tweetId</code> 和 <code>userId</code> 创建一条新推文。每次调用此函数都会使用一个不同的 <code>tweetId</code> 。</li>
	<li><code>List&lt;Integer&gt; getNewsFeed(int userId)</code> 检索当前用户新闻推送中最近&nbsp; <code>10</code> 条推文的 ID 。新闻推送中的每一项都必须是由用户关注的人或者是用户自己发布的推文。推文必须 <strong>按照时间顺序由最近到最远排序</strong> 。</li>
	<li><code>void follow(int followerId, int followeeId)</code> ID 为 <code>followerId</code> 的用户开始关注 ID 为 <code>followeeId</code> 的用户。</li>
	<li><code>void unfollow(int followerId, int followeeId)</code> ID 为 <code>followerId</code> 的用户不再关注 ID 为 <code>followeeId</code> 的用户。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
<strong>输出</strong>
[null, null, [5], null, null, [6, 5], null, [5]]

<strong>解释</strong>
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
twitter.follow(1, 2);    // 用户 1 关注了用户 2
twitter.postTweet(2, 6); // 用户 2 发送了一个新推文 (推文 id = 6)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -&gt; [6, 5] 。推文 id 6 应当在推文 id 5 之前，因为它是在 5 之后发送的
twitter.unfollow(1, 2);  // 用户 1 取消关注了用户 2
twitter.getNewsFeed(1);  // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。因为用户 1 已经不再关注用户 2</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= userId, followerId, followeeId &lt;= 500</code></li>
	<li><code>0 &lt;= tweetId &lt;= 10<sup>4</sup></code></li>
	<li>所有推特的 ID 都互不相同</li>
	<li><code>postTweet</code>、<code>getNewsFeed</code>、<code>follow</code> 和 <code>unfollow</code> 方法最多调用 <code>3 * 10<sup>4</sup></code> 次</li>
</ul>


    
## 方法一：哈希表

我们使用一下三种数据来记录题目所需各种信息：

+ 用```unordered_map<int, unordered_set<int>> followList```来记录关注信息。如果```followList[1] = {2, 5, 7}```，就说明用户```1```关注了用户```2```、```5```、```7```
+ 用```unordered_map<int, vector<pair<int, int>>> posts```来记录发文信息。如果```posts[1] = {{1, 2}, {5, 3}, {6, 7}}```，就说明用户```1```发了三篇文，文章id分别是```1```、```5```、```3```，这三篇文章的发文时间分别是```2```、```3```、```7```。
+ 用```int th```来记录每次发文的“时间”。

那么，对于题目要求的4中操作：

+ 用户a发的文章tweetId：```posts[a].push_back({tweedId, th++})```
+ 用户a关注用户b：```followList[a].insert(b)```
+ 用户a取关用户b：```followList[a].erase(b)```
+ 调取用户a关注列表中的最近10篇文章：
   这个相比起来稍微复杂一些。
   + 首先这道题没有“用户注册”这一操作，也就是说对于一个用户你无法直到他是否是第一次出现（可能没有出现过上来就直接调用了）。因此，在获取用户a关注列表中最近10篇文章时，需首先判断a是否以及添加到了自己的“关注列表”里面。如果还没有，那么把a加入自己的关注列表。（如果题目有“用户注册”这一操作，就可以在用户注册的时候将自己添加到自己的关注列表中）
   + 其次，因为这道题只需要调取10篇推文，所以其实**不需要排序**，每次调取一篇，进行10次操作即可。推文要调取“发布时间尽可能大”的，因此操作时，记录“上次调取的推文的时间”，然后遍历关注列表中每一位用户的所有推文，记录“时间上 小于上一篇推文 的 最大推文”，即为这次操作要获取的推文。

总体码量不大。

+ 时间复杂度：单次发文、关注、取关：$O(1)$；单次获取10篇关注列表的推文：$O(C\times F\times N)$，其中$C$是常数$10$，$F$是这位用户关注了多少人，$N$是这位用户关注的人中平均每人的发文量。
+ 空间复杂度$O(S+U)$，其中$S$是总发文量，$U$是总关注量

获取10篇推文时，可以优化的是：

1. 最多获取10篇推文，因此发布过早的推文可以直接删除
2. 对于某位用户，其推文是有序的。因此不需要遍历所有用户的全部推文10次，而是可以在关注列表中，每次选取“最后一篇推文”中，发布最晚的那一篇。这个方法类似于“[合并升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)”

### AC代码

#### C++

```cpp
typedef pair<int, int> pii;  // <twitterId, th>

class Twitter {
private:
    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, vector<pii>> posts;
    int th;
public:
    Twitter() {
        th = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({tweetId, th++});
    }
    
    vector<int> getNewsFeed(int userId) {
        if (!followList[userId].count(userId))
            followList[userId].insert(userId);
        vector<int> ans;
        int lastTh = INT_MAX;
        for (int i = 0; i < 10; i++) {
            int maxTh = -1;
            int idOfTheMaxTh;
            for (int followeeId : followList[userId]) {
                for (auto[twitterId, twitterTh] : posts[followeeId]) {
                    if (twitterTh >= lastTh)
                        continue;
                    if (twitterTh > maxTh) {
                        maxTh = twitterTh;
                        idOfTheMaxTh = twitterId;
                    }
                }
            }
            if (maxTh == -1)
                break;
            lastTh = maxTh;
            ans.push_back(idOfTheMaxTh);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/04/LeetCode%200355.%E8%AE%BE%E8%AE%A1%E6%8E%A8%E7%89%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127159464](https://letmefly.blog.csdn.net/article/details/127159464)
