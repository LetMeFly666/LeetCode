%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec is_sub_structure(A :: #tree_node{} | null, B :: #tree_node{} | null) -> boolean().
is_sub_structure(A, B) ->
  .