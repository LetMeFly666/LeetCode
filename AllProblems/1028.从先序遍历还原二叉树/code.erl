%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec recover_from_preorder(Traversal :: unicode:unicode_binary()) -> #tree_node{} | null.
recover_from_preorder(Traversal) ->
  .