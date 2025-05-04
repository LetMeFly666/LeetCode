%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec get_all_elements(Root1 :: #tree_node{} | null, Root2 :: #tree_node{} | null) -> [integer()].
get_all_elements(Root1, Root2) ->
  .