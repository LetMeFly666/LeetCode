%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec is_subtree(Root :: #tree_node{} | null, SubRoot :: #tree_node{} | null) -> boolean().
is_subtree(Root, SubRoot) ->
  .