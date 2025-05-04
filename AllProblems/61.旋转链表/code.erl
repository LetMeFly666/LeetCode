%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec rotate_right(Head :: #list_node{} | null, K :: integer()) -> #list_node{} | null.
rotate_right(Head, K) ->
  .