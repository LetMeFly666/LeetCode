%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec build_tree(Inorder :: [integer()], Postorder :: [integer()]) -> #tree_node{} | null.
build_tree(Inorder, Postorder) ->
  .