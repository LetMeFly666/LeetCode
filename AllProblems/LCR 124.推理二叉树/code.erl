%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec deduce_tree(Preorder :: [integer()], Inorder :: [integer()]) -> #tree_node{} | null.
deduce_tree(Preorder, Inorder) ->
  .