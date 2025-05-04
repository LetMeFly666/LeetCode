-spec text_editor_init_() -> any().
text_editor_init_() ->
  .

-spec text_editor_add_text(Text :: unicode:unicode_binary()) -> any().
text_editor_add_text(Text) ->
  .

-spec text_editor_delete_text(K :: integer()) -> integer().
text_editor_delete_text(K) ->
  .

-spec text_editor_cursor_left(K :: integer()) -> unicode:unicode_binary().
text_editor_cursor_left(K) ->
  .

-spec text_editor_cursor_right(K :: integer()) -> unicode:unicode_binary().
text_editor_cursor_right(K) ->
  .


%% Your functions will be called as such:
%% text_editor_init_(),
%% text_editor_add_text(Text),
%% Param_2 = text_editor_delete_text(K),
%% Param_3 = text_editor_cursor_left(K),
%% Param_4 = text_editor_cursor_right(K),

%% text_editor_init_ will be called before every test case, in which you can do some necessary initializations.