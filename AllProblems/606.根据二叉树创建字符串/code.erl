%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec tree2str(Root :: #tree_node{} | null) -> unicode:unicode_binary().
tree2str(Root) ->
  .