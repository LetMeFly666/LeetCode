-spec time_map_init_() -> any().
time_map_init_() ->
  .

-spec time_map_set(Key :: unicode:unicode_binary(), Value :: unicode:unicode_binary(), Timestamp :: integer()) -> any().
time_map_set(Key, Value, Timestamp) ->
  .

-spec time_map_get(Key :: unicode:unicode_binary(), Timestamp :: integer()) -> unicode:unicode_binary().
time_map_get(Key, Timestamp) ->
  .


%% Your functions will be called as such:
%% time_map_init_(),
%% time_map_set(Key, Value, Timestamp),
%% Param_2 = time_map_get(Key, Timestamp),

%% time_map_init_ will be called before every test case, in which you can do some necessary initializations.