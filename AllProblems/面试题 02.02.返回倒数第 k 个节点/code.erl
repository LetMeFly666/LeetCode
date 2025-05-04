%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec kth_to_last(Head :: #list_node{} | null, K :: integer()) -> integer().
kth_to_last(Head, K) ->
  .