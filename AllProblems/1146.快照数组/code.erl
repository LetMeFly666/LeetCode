-spec snapshot_array_init_(Length :: integer()) -> any().
snapshot_array_init_(Length) ->
  .

-spec snapshot_array_set(Index :: integer(), Val :: integer()) -> any().
snapshot_array_set(Index, Val) ->
  .

-spec snapshot_array_snap() -> integer().
snapshot_array_snap() ->
  .

-spec snapshot_array_get(Index :: integer(), Snap_id :: integer()) -> integer().
snapshot_array_get(Index, Snap_id) ->
  .


%% Your functions will be called as such:
%% snapshot_array_init_(Length),
%% snapshot_array_set(Index, Val),
%% Param_2 = snapshot_array_snap(),
%% Param_3 = snapshot_array_get(Index, Snap_id),

%% snapshot_array_init_ will be called before every test case, in which you can do some necessary initializations.