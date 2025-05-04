%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec get_directions(Root :: #tree_node{} | null, StartValue :: integer(), DestValue :: integer()) -> unicode:unicode_binary().
get_directions(Root, StartValue, DestValue) ->
  .