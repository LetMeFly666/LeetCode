%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec amount_of_time(Root :: #tree_node{} | null, Start :: integer()) -> integer().
amount_of_time(Root, Start) ->
  .