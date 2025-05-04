-spec twitter_init_() -> any().
twitter_init_() ->
  .

-spec twitter_post_tweet(UserId :: integer(), TweetId :: integer()) -> any().
twitter_post_tweet(UserId, TweetId) ->
  .

-spec twitter_get_news_feed(UserId :: integer()) -> [integer()].
twitter_get_news_feed(UserId) ->
  .

-spec twitter_follow(FollowerId :: integer(), FolloweeId :: integer()) -> any().
twitter_follow(FollowerId, FolloweeId) ->
  .

-spec twitter_unfollow(FollowerId :: integer(), FolloweeId :: integer()) -> any().
twitter_unfollow(FollowerId, FolloweeId) ->
  .


%% Your functions will be called as such:
%% twitter_init_(),
%% twitter_post_tweet(UserId, TweetId),
%% Param_2 = twitter_get_news_feed(UserId),
%% twitter_follow(FollowerId, FolloweeId),
%% twitter_unfollow(FollowerId, FolloweeId),

%% twitter_init_ will be called before every test case, in which you can do some necessary initializations.