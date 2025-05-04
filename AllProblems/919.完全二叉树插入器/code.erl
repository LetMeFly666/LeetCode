%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec cbt_inserter_init_(Root :: #tree_node{} | null) -> any().
cbt_inserter_init_(Root) ->
  .

-spec cbt_inserter_insert(Val :: integer()) -> integer().
cbt_inserter_insert(Val) ->
  .

-spec cbt_inserter_get_root() -> #tree_node{} | null.
cbt_inserter_get_root() ->
  .


%% Your functions will be called as such:
%% cbt_inserter_init_(Root),
%% Param_1 = cbt_inserter_insert(Val),
%% Param_2 = cbt_inserter_get_root(),

%% cbt_inserter_init_ will be called before every test case, in which you can do some necessary initializations.