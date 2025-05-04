defmodule FoodRatings do
  @spec init_(foods :: [String.t], cuisines :: [String.t], ratings :: [integer]) :: any
  def init_(foods, cuisines, ratings) do
    
  end

  @spec change_rating(food :: String.t, new_rating :: integer) :: any
  def change_rating(food, new_rating) do
    
  end

  @spec highest_rated(cuisine :: String.t) :: String.t
  def highest_rated(cuisine) do
    
  end
end

# Your functions will be called as such:
# FoodRatings.init_(foods, cuisines, ratings)
# FoodRatings.change_rating(food, new_rating)
# param_2 = FoodRatings.highest_rated(cuisine)

# FoodRatings.init_ will be called before every test case, in which you can do some necessary initializations.