-spec locking_tree_init_(Parent :: [integer()]) -> any().
locking_tree_init_(Parent) ->
  .

-spec locking_tree_lock(Num :: integer(), User :: integer()) -> boolean().
locking_tree_lock(Num, User) ->
  .

-spec locking_tree_unlock(Num :: integer(), User :: integer()) -> boolean().
locking_tree_unlock(Num, User) ->
  .

-spec locking_tree_upgrade(Num :: integer(), User :: integer()) -> boolean().
locking_tree_upgrade(Num, User) ->
  .


%% Your functions will be called as such:
%% locking_tree_init_(Parent),
%% Param_1 = locking_tree_lock(Num, User),
%% Param_2 = locking_tree_unlock(Num, User),
%% Param_3 = locking_tree_upgrade(Num, User),

%% locking_tree_init_ will be called before every test case, in which you can do some necessary initializations.