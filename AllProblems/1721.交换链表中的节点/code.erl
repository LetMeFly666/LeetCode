%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec swap_nodes(Head :: #list_node{} | null, K :: integer()) -> #list_node{} | null.
swap_nodes(Head, K) ->
  .