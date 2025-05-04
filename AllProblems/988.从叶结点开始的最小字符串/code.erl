%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec smallest_from_leaf(Root :: #tree_node{} | null) -> unicode:unicode_binary().
smallest_from_leaf(Root) ->
  .