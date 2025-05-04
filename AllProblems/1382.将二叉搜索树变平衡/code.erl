%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec balance_bst(Root :: #tree_node{} | null) -> #tree_node{} | null.
balance_bst(Root) ->
  .