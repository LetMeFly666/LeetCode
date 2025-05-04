%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec longest_zig_zag(Root :: #tree_node{} | null) -> integer().
longest_zig_zag(Root) ->
  .