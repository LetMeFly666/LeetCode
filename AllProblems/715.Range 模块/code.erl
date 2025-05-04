-spec range_module_init_() -> any().
range_module_init_() ->
  .

-spec range_module_add_range(Left :: integer(), Right :: integer()) -> any().
range_module_add_range(Left, Right) ->
  .

-spec range_module_query_range(Left :: integer(), Right :: integer()) -> boolean().
range_module_query_range(Left, Right) ->
  .

-spec range_module_remove_range(Left :: integer(), Right :: integer()) -> any().
range_module_remove_range(Left, Right) ->
  .


%% Your functions will be called as such:
%% range_module_init_(),
%% range_module_add_range(Left, Right),
%% Param_2 = range_module_query_range(Left, Right),
%% range_module_remove_range(Left, Right),

%% range_module_init_ will be called before every test case, in which you can do some necessary initializations.