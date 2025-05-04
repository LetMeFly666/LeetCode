%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec min_diff_in_bst(Root :: #tree_node{} | null) -> integer().
min_diff_in_bst(Root) ->
  .