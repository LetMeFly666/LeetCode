-spec spreadsheet_init_(Rows :: integer()) -> any().
spreadsheet_init_(Rows) ->
  .

-spec spreadsheet_set_cell(Cell :: unicode:unicode_binary(), Value :: integer()) -> any().
spreadsheet_set_cell(Cell, Value) ->
  .

-spec spreadsheet_reset_cell(Cell :: unicode:unicode_binary()) -> any().
spreadsheet_reset_cell(Cell) ->
  .

-spec spreadsheet_get_value(Formula :: unicode:unicode_binary()) -> integer().
spreadsheet_get_value(Formula) ->
  .


%% Your functions will be called as such:
%% spreadsheet_init_(Rows),
%% spreadsheet_set_cell(Cell, Value),
%% spreadsheet_reset_cell(Cell),
%% Param_3 = spreadsheet_get_value(Formula),

%% spreadsheet_init_ will be called before every test case, in which you can do some necessary initializations.