%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec swap_pairs(Head :: #list_node{} | null) -> #list_node{} | null.
swap_pairs(Head) ->
  .