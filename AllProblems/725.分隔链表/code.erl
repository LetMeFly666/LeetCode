%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec split_list_to_parts(Head :: #list_node{} | null, K :: integer()) -> [#list_node{} | null].
split_list_to_parts(Head, K) ->
  .