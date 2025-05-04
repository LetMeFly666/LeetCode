%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec vertical_traversal(Root :: #tree_node{} | null) -> [[integer()]].
vertical_traversal(Root) ->
  .