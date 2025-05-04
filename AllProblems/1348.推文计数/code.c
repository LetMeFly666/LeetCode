


typedef struct {
    
} TweetCounts;


TweetCounts* tweetCountsCreate() {
    
}

void tweetCountsRecordTweet(TweetCounts* obj, char* tweetName, int time) {
    
}

int* tweetCountsGetTweetCountsPerFrequency(TweetCounts* obj, char* freq, char* tweetName, int startTime, int endTime, int* retSize) {
    
}

void tweetCountsFree(TweetCounts* obj) {
    
}

/**
 * Your TweetCounts struct will be instantiated and called as such:
 * TweetCounts* obj = tweetCountsCreate();
 * tweetCountsRecordTweet(obj, tweetName, time);
 
 * int* param_2 = tweetCountsGetTweetCountsPerFrequency(obj, freq, tweetName, startTime, endTime, retSize);
 
 * tweetCountsFree(obj);
*/