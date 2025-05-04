%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec training_plan(Head :: #list_node{} | null, Cnt :: integer()) -> #list_node{} | null.
training_plan(Head, Cnt) ->
  .