%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec search_bst(Root :: #tree_node{} | null, Val :: integer()) -> #tree_node{} | null.
search_bst(Root, Val) ->
  .