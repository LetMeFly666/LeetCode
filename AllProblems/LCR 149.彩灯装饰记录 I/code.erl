%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec decorate_record(Root :: #tree_node{} | null) -> [integer()].
decorate_record(Root) ->
  .