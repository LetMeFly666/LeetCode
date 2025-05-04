%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec trainning_plan(L1 :: #list_node{} | null, L2 :: #list_node{} | null) -> #list_node{} | null.
trainning_plan(L1, L2) ->
  .