%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec insert_into_max_tree(Root :: #tree_node{} | null, Val :: integer()) -> #tree_node{} | null.
insert_into_max_tree(Root, Val) ->
  .