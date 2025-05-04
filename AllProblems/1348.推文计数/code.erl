-spec tweet_counts_init_() -> any().
tweet_counts_init_() ->
  .

-spec tweet_counts_record_tweet(TweetName :: unicode:unicode_binary(), Time :: integer()) -> any().
tweet_counts_record_tweet(TweetName, Time) ->
  .

-spec tweet_counts_get_tweet_counts_per_frequency(Freq :: unicode:unicode_binary(), TweetName :: unicode:unicode_binary(), StartTime :: integer(), EndTime :: integer()) -> [integer()].
tweet_counts_get_tweet_counts_per_frequency(Freq, TweetName, StartTime, EndTime) ->
  .


%% Your functions will be called as such:
%% tweet_counts_init_(),
%% tweet_counts_record_tweet(TweetName, Time),
%% Param_2 = tweet_counts_get_tweet_counts_per_frequency(Freq, TweetName, StartTime, EndTime),

%% tweet_counts_init_ will be called before every test case, in which you can do some necessary initializations.