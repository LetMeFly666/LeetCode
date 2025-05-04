%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec average_of_subtree(Root :: #tree_node{} | null) -> integer().
average_of_subtree(Root) ->
  .