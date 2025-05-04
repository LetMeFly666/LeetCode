%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec kth_smallest(Root :: #tree_node{} | null, K :: integer()) -> integer().
kth_smallest(Root, K) ->
  .