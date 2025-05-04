%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec sum_root_to_leaf(Root :: #tree_node{} | null) -> integer().
sum_root_to_leaf(Root) ->
  .