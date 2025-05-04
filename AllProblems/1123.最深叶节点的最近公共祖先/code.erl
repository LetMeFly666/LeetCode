%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec lca_deepest_leaves(Root :: #tree_node{} | null) -> #tree_node{} | null.
lca_deepest_leaves(Root) ->
  .