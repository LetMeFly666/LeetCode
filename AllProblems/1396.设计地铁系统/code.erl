-spec underground_system_init_() -> any().
underground_system_init_() ->
  .

-spec underground_system_check_in(Id :: integer(), StationName :: unicode:unicode_binary(), T :: integer()) -> any().
underground_system_check_in(Id, StationName, T) ->
  .

-spec underground_system_check_out(Id :: integer(), StationName :: unicode:unicode_binary(), T :: integer()) -> any().
underground_system_check_out(Id, StationName, T) ->
  .

-spec underground_system_get_average_time(StartStation :: unicode:unicode_binary(), EndStation :: unicode:unicode_binary()) -> float().
underground_system_get_average_time(StartStation, EndStation) ->
  .


%% Your functions will be called as such:
%% underground_system_init_(),
%% underground_system_check_in(Id, StationName, T),
%% underground_system_check_out(Id, StationName, T),
%% Param_3 = underground_system_get_average_time(StartStation, EndStation),

%% underground_system_init_ will be called before every test case, in which you can do some necessary initializations.