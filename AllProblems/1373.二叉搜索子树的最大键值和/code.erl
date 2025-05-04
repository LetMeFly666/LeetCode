%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec max_sum_bst(Root :: #tree_node{} | null) -> integer().
max_sum_bst(Root) ->
  .