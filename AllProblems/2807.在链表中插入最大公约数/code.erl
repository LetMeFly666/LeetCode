%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec insert_greatest_common_divisors(Head :: #list_node{} | null) -> #list_node{} | null.
insert_greatest_common_divisors(Head) ->
  .