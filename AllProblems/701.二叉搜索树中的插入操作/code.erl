%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec insert_into_bst(Root :: #tree_node{} | null, Val :: integer()) -> #tree_node{} | null.
insert_into_bst(Root, Val) ->
  .