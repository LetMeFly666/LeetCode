-spec movie_renting_system_init_(N :: integer(), Entries :: [[integer()]]) -> any().
movie_renting_system_init_(N, Entries) ->
  .

-spec movie_renting_system_search(Movie :: integer()) -> [integer()].
movie_renting_system_search(Movie) ->
  .

-spec movie_renting_system_rent(Shop :: integer(), Movie :: integer()) -> any().
movie_renting_system_rent(Shop, Movie) ->
  .

-spec movie_renting_system_drop(Shop :: integer(), Movie :: integer()) -> any().
movie_renting_system_drop(Shop, Movie) ->
  .

-spec movie_renting_system_report() -> [[integer()]].
movie_renting_system_report() ->
  .


%% Your functions will be called as such:
%% movie_renting_system_init_(N, Entries),
%% Param_1 = movie_renting_system_search(Movie),
%% movie_renting_system_rent(Shop, Movie),
%% movie_renting_system_drop(Shop, Movie),
%% Param_4 = movie_renting_system_report(),

%% movie_renting_system_init_ will be called before every test case, in which you can do some necessary initializations.