%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec bst_iterator_init_(Root :: #tree_node{} | null) -> any().
bst_iterator_init_(Root) ->
  .

-spec bst_iterator_next() -> integer().
bst_iterator_next() ->
  .

-spec bst_iterator_has_next() -> boolean().
bst_iterator_has_next() ->
  .


%% Your functions will be called as such:
%% bst_iterator_init_(Root),
%% Param_1 = bst_iterator_next(),
%% Param_2 = bst_iterator_has_next(),

%% bst_iterator_init_ will be called before every test case, in which you can do some necessary initializations.