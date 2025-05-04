%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec width_of_binary_tree(Root :: #tree_node{} | null) -> integer().
width_of_binary_tree(Root) ->
  .