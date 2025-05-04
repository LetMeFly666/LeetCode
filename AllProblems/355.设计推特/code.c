


typedef struct {
    
} Twitter;


Twitter* twitterCreate() {
    
}

void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    
}

int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
    
}

void twitterFollow(Twitter* obj, int followerId, int followeeId) {
    
}

void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
    
}

void twitterFree(Twitter* obj) {
    
}

/**
 * Your Twitter struct will be instantiated and called as such:
 * Twitter* obj = twitterCreate();
 * twitterPostTweet(obj, userId, tweetId);
 
 * int* param_2 = twitterGetNewsFeed(obj, userId, retSize);
 
 * twitterFollow(obj, followerId, followeeId);
 
 * twitterUnfollow(obj, followerId, followeeId);
 
 * twitterFree(obj);
*/