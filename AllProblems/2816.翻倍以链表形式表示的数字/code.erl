%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec double_it(Head :: #list_node{} | null) -> #list_node{} | null.
double_it(Head) ->
  .