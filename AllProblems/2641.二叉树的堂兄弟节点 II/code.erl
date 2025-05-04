%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec replace_value_in_tree(Root :: #tree_node{} | null) -> #tree_node{} | null.
replace_value_in_tree(Root) ->
  .