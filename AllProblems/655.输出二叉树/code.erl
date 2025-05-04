%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec print_tree(Root :: #tree_node{} | null) -> [[unicode:unicode_binary()]].
print_tree(Root) ->
  .