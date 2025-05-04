struct Twitter {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Twitter {

    fn new() -> Self {
        
    }
    
    fn post_tweet(&self, user_id: i32, tweet_id: i32) {
        
    }
    
    fn get_news_feed(&self, user_id: i32) -> Vec<i32> {
        
    }
    
    fn follow(&self, follower_id: i32, followee_id: i32) {
        
    }
    
    fn unfollow(&self, follower_id: i32, followee_id: i32) {
        
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * let obj = Twitter::new();
 * obj.post_tweet(userId, tweetId);
 * let ret_2: Vec<i32> = obj.get_news_feed(userId);
 * obj.follow(followerId, followeeId);
 * obj.unfollow(followerId, followeeId);
 */