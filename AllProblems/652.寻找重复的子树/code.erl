%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec find_duplicate_subtrees(Root :: #tree_node{} | null) -> [#tree_node{} | null].
find_duplicate_subtrees(Root) ->
  .