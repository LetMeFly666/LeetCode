%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec delete_middle(Head :: #list_node{} | null) -> #list_node{} | null.
delete_middle(Head) ->
  .