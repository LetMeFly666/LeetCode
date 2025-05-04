%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec delete_node(Root :: #tree_node{} | null, Key :: integer()) -> #tree_node{} | null.
delete_node(Root, Key) ->
  .