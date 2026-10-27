%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec construct_from_pre_post(Preorder :: [integer()], Postorder :: [integer()]) -> #tree_node{} | null.
construct_from_pre_post(Preorder, Postorder) ->
  .