%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec remove_duplicate_nodes(Head :: #list_node{} | null) -> #list_node{} | null.
remove_duplicate_nodes(Head) ->
  .