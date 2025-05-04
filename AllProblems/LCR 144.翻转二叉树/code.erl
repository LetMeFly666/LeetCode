%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec flip_tree(Root :: #tree_node{} | null) -> #tree_node{} | null.
flip_tree(Root) ->
  .