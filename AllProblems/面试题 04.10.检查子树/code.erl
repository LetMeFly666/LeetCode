%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec check_sub_tree(T1 :: #tree_node{} | null, T2 :: #tree_node{} | null) -> boolean().
check_sub_tree(T1, T2) ->
  .