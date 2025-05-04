%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec zigzag_level_order(Root :: #tree_node{} | null) -> [[integer()]].
zigzag_level_order(Root) ->
  .