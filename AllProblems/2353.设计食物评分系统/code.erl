-spec food_ratings_init_(Foods :: [unicode:unicode_binary()], Cuisines :: [unicode:unicode_binary()], Ratings :: [integer()]) -> any().
food_ratings_init_(Foods, Cuisines, Ratings) ->
  .

-spec food_ratings_change_rating(Food :: unicode:unicode_binary(), NewRating :: integer()) -> any().
food_ratings_change_rating(Food, NewRating) ->
  .

-spec food_ratings_highest_rated(Cuisine :: unicode:unicode_binary()) -> unicode:unicode_binary().
food_ratings_highest_rated(Cuisine) ->
  .


%% Your functions will be called as such:
%% food_ratings_init_(Foods, Cuisines, Ratings),
%% food_ratings_change_rating(Food, NewRating),
%% Param_2 = food_ratings_highest_rated(Cuisine),

%% food_ratings_init_ will be called before every test case, in which you can do some necessary initializations.