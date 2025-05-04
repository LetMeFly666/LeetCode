%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec all_possible_fbt(N :: integer()) -> [#tree_node{} | null].
all_possible_fbt(N) ->
  .