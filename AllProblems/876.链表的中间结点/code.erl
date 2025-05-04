%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec middle_node(Head :: #list_node{} | null) -> #list_node{} | null.
middle_node(Head) ->
  .