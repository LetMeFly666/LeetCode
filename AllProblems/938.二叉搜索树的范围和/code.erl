%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec range_sum_bst(Root :: #tree_node{} | null, Low :: integer(), High :: integer()) -> integer().
range_sum_bst(Root, Low, High) ->
  .