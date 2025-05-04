-spec browser_history_init_(Homepage :: unicode:unicode_binary()) -> any().
browser_history_init_(Homepage) ->
  .

-spec browser_history_visit(Url :: unicode:unicode_binary()) -> any().
browser_history_visit(Url) ->
  .

-spec browser_history_back(Steps :: integer()) -> unicode:unicode_binary().
browser_history_back(Steps) ->
  .

-spec browser_history_forward(Steps :: integer()) -> unicode:unicode_binary().
browser_history_forward(Steps) ->
  .


%% Your functions will be called as such:
%% browser_history_init_(Homepage),
%% browser_history_visit(Url),
%% Param_2 = browser_history_back(Steps),
%% Param_3 = browser_history_forward(Steps),

%% browser_history_init_ will be called before every test case, in which you can do some necessary initializations.