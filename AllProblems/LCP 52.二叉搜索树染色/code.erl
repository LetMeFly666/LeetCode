%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec get_number(Root :: #tree_node{} | null, Ops :: [[integer()]]) -> integer().
get_number(Root, Ops) ->
  .