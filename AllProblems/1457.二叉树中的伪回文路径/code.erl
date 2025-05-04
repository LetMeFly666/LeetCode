%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec pseudo_palindromic_paths (Root :: #tree_node{} | null) -> integer().
pseudo_palindromic_paths (Root) ->
  .