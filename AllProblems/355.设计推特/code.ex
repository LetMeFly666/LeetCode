defmodule Twitter do
  @spec init_() :: any
  def init_() do
    
  end

  @spec post_tweet(user_id :: integer, tweet_id :: integer) :: any
  def post_tweet(user_id, tweet_id) do
    
  end

  @spec get_news_feed(user_id :: integer) :: [integer]
  def get_news_feed(user_id) do
    
  end

  @spec follow(follower_id :: integer, followee_id :: integer) :: any
  def follow(follower_id, followee_id) do
    
  end

  @spec unfollow(follower_id :: integer, followee_id :: integer) :: any
  def unfollow(follower_id, followee_id) do
    
  end
end

# Your functions will be called as such:
# Twitter.init_()
# Twitter.post_tweet(user_id, tweet_id)
# param_2 = Twitter.get_news_feed(user_id)
# Twitter.follow(follower_id, followee_id)
# Twitter.unfollow(follower_id, followee_id)

# Twitter.init_ will be called before every test case, in which you can do some necessary initializations.