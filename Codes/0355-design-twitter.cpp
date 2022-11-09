/*
 * @Author: LetMeFly
 * @Date: 2022-10-04 09:03:42
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-10-04 09:15:26
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

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

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */