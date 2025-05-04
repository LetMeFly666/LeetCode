%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec right_side_view(Root :: #tree_node{} | null) -> [integer()].
right_side_view(Root) ->
  .