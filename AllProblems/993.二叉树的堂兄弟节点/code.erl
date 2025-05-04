%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec is_cousins(Root :: #tree_node{} | null, X :: integer(), Y :: integer()) -> boolean().
is_cousins(Root, X, Y) ->
  .