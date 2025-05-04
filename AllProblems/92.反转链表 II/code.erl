%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec reverse_between(Head :: #list_node{} | null, Left :: integer(), Right :: integer()) -> #list_node{} | null.
reverse_between(Head, Left, Right) ->
  .