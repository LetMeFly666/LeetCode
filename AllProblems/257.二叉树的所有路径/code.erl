%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec binary_tree_paths(Root :: #tree_node{} | null) -> [unicode:unicode_binary()].
binary_tree_paths(Root) ->
  .