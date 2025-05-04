%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec increasing_bst(Root :: #tree_node{} | null) -> #tree_node{} | null.
increasing_bst(Root) ->
  .