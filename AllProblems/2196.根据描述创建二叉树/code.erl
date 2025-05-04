%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec create_binary_tree(Descriptions :: [[integer()]]) -> #tree_node{} | null.
create_binary_tree(Descriptions) ->
  .