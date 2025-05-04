%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec find_second_minimum_value(Root :: #tree_node{} | null) -> integer().
find_second_minimum_value(Root) ->
  .