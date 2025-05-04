%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec modified_list(Nums :: [integer()], Head :: #list_node{} | null) -> #list_node{} | null.
modified_list(Nums, Head) ->
  .