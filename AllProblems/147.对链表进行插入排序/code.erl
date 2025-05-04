%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec insertion_sort_list(Head :: #list_node{} | null) -> #list_node{} | null.
insertion_sort_list(Head) ->
  .