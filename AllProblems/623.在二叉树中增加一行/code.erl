%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec add_one_row(Root :: #tree_node{} | null, Val :: integer(), Depth :: integer()) -> #tree_node{} | null.
add_one_row(Root, Val, Depth) ->
  .