%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec build_tree(Preorder :: [integer()], Inorder :: [integer()]) -> #tree_node{} | null.
build_tree(Preorder, Inorder) ->
  .