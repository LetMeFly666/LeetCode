%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec closest_nodes(Root :: #tree_node{} | null, Queries :: [integer()]) -> [[integer()]].
closest_nodes(Root, Queries) ->
  .