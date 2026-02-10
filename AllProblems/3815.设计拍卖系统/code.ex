defmodule AuctionSystem do
  @spec init_() :: any
  def init_() do
    
  end

  @spec add_bid(user_id :: integer, item_id :: integer, bid_amount :: integer) :: any
  def add_bid(user_id, item_id, bid_amount) do
    
  end

  @spec update_bid(user_id :: integer, item_id :: integer, new_amount :: integer) :: any
  def update_bid(user_id, item_id, new_amount) do
    
  end

  @spec remove_bid(user_id :: integer, item_id :: integer) :: any
  def remove_bid(user_id, item_id) do
    
  end

  @spec get_highest_bidder(item_id :: integer) :: integer
  def get_highest_bidder(item_id) do
    
  end
end

# Your functions will be called as such:
# AuctionSystem.init_()
# AuctionSystem.add_bid(user_id, item_id, bid_amount)
# AuctionSystem.update_bid(user_id, item_id, new_amount)
# AuctionSystem.remove_bid(user_id, item_id)
# param_4 = AuctionSystem.get_highest_bidder(item_id)

# AuctionSystem.init_ will be called before every test case, in which you can do some necessary initializations.