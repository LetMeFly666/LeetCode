%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec find_frequent_tree_sum(Root :: #tree_node{} | null) -> [integer()].
find_frequent_tree_sum(Root) ->
  .