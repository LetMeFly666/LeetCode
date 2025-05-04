%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec find_elements_init_(Root :: #tree_node{} | null) -> any().
find_elements_init_(Root) ->
  .

-spec find_elements_find(Target :: integer()) -> boolean().
find_elements_find(Target) ->
  .


%% Your functions will be called as such:
%% find_elements_init_(Root),
%% Param_1 = find_elements_find(Target),

%% find_elements_init_ will be called before every test case, in which you can do some necessary initializations.