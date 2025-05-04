%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec reverse_book_list(Head :: #list_node{} | null) -> [integer()].
reverse_book_list(Head) ->
  .