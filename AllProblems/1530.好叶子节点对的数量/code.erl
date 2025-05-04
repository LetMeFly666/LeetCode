%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec count_pairs(Root :: #tree_node{} | null, Distance :: integer()) -> integer().
count_pairs(Root, Distance) ->
  .