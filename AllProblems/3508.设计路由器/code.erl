-spec router_init_(MemoryLimit :: integer()) -> any().
router_init_(MemoryLimit) ->
  .

-spec router_add_packet(Source :: integer(), Destination :: integer(), Timestamp :: integer()) -> boolean().
router_add_packet(Source, Destination, Timestamp) ->
  .

-spec router_forward_packet() -> [integer()].
router_forward_packet() ->
  .

-spec router_get_count(Destination :: integer(), StartTime :: integer(), EndTime :: integer()) -> integer().
router_get_count(Destination, StartTime, EndTime) ->
  .


%% Your functions will be called as such:
%% router_init_(MemoryLimit),
%% Param_1 = router_add_packet(Source, Destination, Timestamp),
%% Param_2 = router_forward_packet(),
%% Param_3 = router_get_count(Destination, StartTime, EndTime),

%% router_init_ will be called before every test case, in which you can do some necessary initializations.