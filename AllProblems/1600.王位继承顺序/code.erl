-spec throne_inheritance_init_(KingName :: unicode:unicode_binary()) -> any().
throne_inheritance_init_(KingName) ->
  .

-spec throne_inheritance_birth(ParentName :: unicode:unicode_binary(), ChildName :: unicode:unicode_binary()) -> any().
throne_inheritance_birth(ParentName, ChildName) ->
  .

-spec throne_inheritance_death(Name :: unicode:unicode_binary()) -> any().
throne_inheritance_death(Name) ->
  .

-spec throne_inheritance_get_inheritance_order() -> [unicode:unicode_binary()].
throne_inheritance_get_inheritance_order() ->
  .


%% Your functions will be called as such:
%% throne_inheritance_init_(KingName),
%% throne_inheritance_birth(ParentName, ChildName),
%% throne_inheritance_death(Name),
%% Param_3 = throne_inheritance_get_inheritance_order(),

%% throne_inheritance_init_ will be called before every test case, in which you can do some necessary initializations.