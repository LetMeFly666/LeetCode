%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec find_target_node(Root :: #tree_node{} | null, Cnt :: integer()) -> integer().
find_target_node(Root, Cnt) ->
  .