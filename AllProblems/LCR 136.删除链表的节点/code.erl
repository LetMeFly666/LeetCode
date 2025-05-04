%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec delete_node(Head :: #list_node{} | null, Val :: integer()) -> #list_node{} | null.
delete_node(Head, Val) ->
  .