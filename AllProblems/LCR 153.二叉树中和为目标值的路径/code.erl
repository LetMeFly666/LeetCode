%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec path_target(Root :: #tree_node{} | null, Target :: integer()) -> [[integer()]].
path_target(Root, Target) ->
  .