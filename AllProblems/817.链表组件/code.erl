%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec num_components(Head :: #list_node{} | null, Nums :: [integer()]) -> integer().
num_components(Head, Nums) ->
  .