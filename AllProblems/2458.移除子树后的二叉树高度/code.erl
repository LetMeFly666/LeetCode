%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec tree_queries(Root :: #tree_node{} | null, Queries :: [integer()]) -> [integer()].
tree_queries(Root, Queries) ->
  .