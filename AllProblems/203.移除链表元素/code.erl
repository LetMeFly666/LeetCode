%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec remove_elements(Head :: #list_node{} | null, Val :: integer()) -> #list_node{} | null.
remove_elements(Head, Val) ->
  .