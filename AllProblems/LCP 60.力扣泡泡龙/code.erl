%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec get_max_layer_sum(Root :: #tree_node{} | null) -> integer().
get_max_layer_sum(Root) ->
  .