-spec book_my_show_init_(N :: integer(), M :: integer()) -> any().
book_my_show_init_(N, M) ->
  .

-spec book_my_show_gather(K :: integer(), MaxRow :: integer()) -> [integer()].
book_my_show_gather(K, MaxRow) ->
  .

-spec book_my_show_scatter(K :: integer(), MaxRow :: integer()) -> boolean().
book_my_show_scatter(K, MaxRow) ->
  .


%% Your functions will be called as such:
%% book_my_show_init_(N, M),
%% Param_1 = book_my_show_gather(K, MaxRow),
%% Param_2 = book_my_show_scatter(K, MaxRow),

%% book_my_show_init_ will be called before every test case, in which you can do some necessary initializations.