%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec remove_leaf_nodes(Root :: #tree_node{} | null, Target :: integer()) -> #tree_node{} | null.
remove_leaf_nodes(Root, Target) ->
  .