%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec average_of_levels(Root :: #tree_node{} | null) -> [float()].
average_of_levels(Root) ->
  .