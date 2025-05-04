%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec kth_largest_perfect_subtree(Root :: #tree_node{} | null, K :: integer()) -> integer().
kth_largest_perfect_subtree(Root, K) ->
  .