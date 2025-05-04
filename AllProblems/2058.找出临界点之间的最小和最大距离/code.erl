%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec nodes_between_critical_points(Head :: #list_node{} | null) -> [integer()].
nodes_between_critical_points(Head) ->
  .