%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec sufficient_subset(Root :: #tree_node{} | null, Limit :: integer()) -> #tree_node{} | null.
sufficient_subset(Root, Limit) ->
  .