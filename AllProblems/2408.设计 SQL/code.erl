-spec sql_init_(Names :: [unicode:unicode_binary()], Columns :: [integer()]) -> any().
sql_init_(Names, Columns) ->
  .

-spec sql_ins(Name :: unicode:unicode_binary(), Row :: [unicode:unicode_binary()]) -> boolean().
sql_ins(Name, Row) ->
  .

-spec sql_rmv(Name :: unicode:unicode_binary(), RowId :: integer()) -> any().
sql_rmv(Name, RowId) ->
  .

-spec sql_sel(Name :: unicode:unicode_binary(), RowId :: integer(), ColumnId :: integer()) -> unicode:unicode_binary().
sql_sel(Name, RowId, ColumnId) ->
  .

-spec sql_exp(Name :: unicode:unicode_binary()) -> [unicode:unicode_binary()].
sql_exp(Name) ->
  .


%% Your functions will be called as such:
%% sql_init_(Names, Columns),
%% Param_1 = sql_ins(Name, Row),
%% sql_rmv(Name, RowId),
%% Param_3 = sql_sel(Name, RowId, ColumnId),
%% Param_4 = sql_exp(Name),

%% sql_init_ will be called before every test case, in which you can do some necessary initializations.