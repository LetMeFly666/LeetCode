%% % This is the interface that allows for creating nested lists.
%% % You should not implement it, or speculate about its implementation
%%
%% % Create an empty nested list.
%% nested_integer:new() -> nested_integer().
%%
%% % Create a single integer.
%% nested_integer:new(Val :: integer()) -> nested_integer().
%%
%% % Return true if argument NestedInteger holds a single integer, rather than a nested list.
%% nested_integer:is_integer(NestedInteger :: nested_integer()) -> boolean().
%%
%% % Return the single integer that NestedInteger holds, if it holds a single integer.
%% % The result is undefined if it holds a nested list.
%% nested_integer:get_integer(NestedInteger :: nested_integer()) -> integer().
%%
%% % Return a copy of argument NestedInteger with it set to hold a single integer Val.
%% nested_integer:set_integer(NestedInteger :: nested_integer(), Val :: integer()) -> nested_integer().
%%
%% % Return a copy of argument NestedInteger with it set to hold a nested list and adds a nested_integer Elem to it.
%% nested_integer:add(NestedInteger :: nested_integer(), Elem :: nested_integer()) -> nested_integer().
%%
%% % Return the nested list that NestedInteger holds, if it holds a nested list.
%% % The result is undefined if it holds a single integer.
%% nested_integer:get_list(NestedInteger :: nested_integer()) -> array:array(nested_integer()).

-spec deserialize(S :: unicode:unicode_binary()) -> nested_integer:nested_integer().
deserialize(S) ->
  .