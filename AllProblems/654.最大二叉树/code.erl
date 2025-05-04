%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec construct_maximum_binary_tree(Nums :: [integer()]) -> #tree_node{} | null.
construct_maximum_binary_tree(Nums) ->
  .