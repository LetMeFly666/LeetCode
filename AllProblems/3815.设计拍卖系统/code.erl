-spec auction_system_init_() -> any().
auction_system_init_() ->
  .

-spec auction_system_add_bid(UserId :: integer(), ItemId :: integer(), BidAmount :: integer()) -> any().
auction_system_add_bid(UserId, ItemId, BidAmount) ->
  .

-spec auction_system_update_bid(UserId :: integer(), ItemId :: integer(), NewAmount :: integer()) -> any().
auction_system_update_bid(UserId, ItemId, NewAmount) ->
  .

-spec auction_system_remove_bid(UserId :: integer(), ItemId :: integer()) -> any().
auction_system_remove_bid(UserId, ItemId) ->
  .

-spec auction_system_get_highest_bidder(ItemId :: integer()) -> integer().
auction_system_get_highest_bidder(ItemId) ->
  .


%% Your functions will be called as such:
%% auction_system_init_(),
%% auction_system_add_bid(UserId, ItemId, BidAmount),
%% auction_system_update_bid(UserId, ItemId, NewAmount),
%% auction_system_remove_bid(UserId, ItemId),
%% Param_4 = auction_system_get_highest_bidder(ItemId),

%% auction_system_init_ will be called before every test case, in which you can do some necessary initializations.