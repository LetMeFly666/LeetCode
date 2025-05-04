%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec merge_nodes(Head :: #list_node{} | null) -> #list_node{} | null.
merge_nodes(Head) ->
  .