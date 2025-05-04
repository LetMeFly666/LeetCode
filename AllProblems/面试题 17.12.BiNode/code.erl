%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec convert_bi_node(Root :: #tree_node{} | null) -> #tree_node{} | null.
convert_bi_node(Root) ->
  .