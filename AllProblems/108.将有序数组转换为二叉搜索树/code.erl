%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec sorted_array_to_bst(Nums :: [integer()]) -> #tree_node{} | null.
sorted_array_to_bst(Nums) ->
  .