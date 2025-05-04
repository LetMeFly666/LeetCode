%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec subtree_with_all_deepest(Root :: #tree_node{} | null) -> #tree_node{} | null.
subtree_with_all_deepest(Root) ->
  .