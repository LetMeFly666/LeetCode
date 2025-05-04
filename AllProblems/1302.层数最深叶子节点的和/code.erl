%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec deepest_leaves_sum(Root :: #tree_node{} | null) -> integer().
deepest_leaves_sum(Root) ->
  .