%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec flip_match_voyage(Root :: #tree_node{} | null, Voyage :: [integer()]) -> [integer()].
flip_match_voyage(Root, Voyage) ->
  .