%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec trim_bst(Root :: #tree_node{} | null, Low :: integer(), High :: integer()) -> #tree_node{} | null.
trim_bst(Root, Low, High) ->
  .