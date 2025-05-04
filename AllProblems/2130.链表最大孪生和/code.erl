%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec pair_sum(Head :: #list_node{} | null) -> integer().
pair_sum(Head) ->
  .