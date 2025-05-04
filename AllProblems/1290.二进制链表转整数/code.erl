%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec get_decimal_value(Head :: #list_node{} | null) -> integer().
get_decimal_value(Head) ->
  .