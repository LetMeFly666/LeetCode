%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec spiral_matrix(M :: integer(), N :: integer(), Head :: #list_node{} | null) -> [[integer()]].
spiral_matrix(M, N, Head) ->
  .