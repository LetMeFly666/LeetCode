-spec event_manager_init_(Events :: [[integer()]]) -> any().
event_manager_init_(Events) ->
  .

-spec event_manager_update_priority(EventId :: integer(), NewPriority :: integer()) -> any().
event_manager_update_priority(EventId, NewPriority) ->
  .

-spec event_manager_poll_highest() -> integer().
event_manager_poll_highest() ->
  .


%% Your functions will be called as such:
%% event_manager_init_(Events),
%% event_manager_update_priority(EventId, NewPriority),
%% Param_2 = event_manager_poll_highest(),

%% event_manager_init_ will be called before every test case, in which you can do some necessary initializations.