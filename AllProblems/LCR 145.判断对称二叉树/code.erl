%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec check_symmetric_tree(Root :: #tree_node{} | null) -> boolean().
check_symmetric_tree(Root) ->
  .