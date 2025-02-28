/*
 * @Author: LetMeFly
 * @Date: 2025-02-28 11:12:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-28 11:29:56
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/* UnUsed
changeRating: food->cuisine->rating
highestRated: cuisine->rating->food

Hash:
  + food->cuisine
  + cuisine: rating->food
  + cuisine: food->rating
*/

class FoodRatings {
private:
    unordered_map<string, pair<string, int>> food2cuisineScore;        // food->(cuisine, score)
    unordered_map<string, set<pair<int, string>>> cuisine2rscoreFood;  // cuisine->[(-score, food), ...]
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            food2cuisineScore[foods[i]] = {cuisines[i], ratings[i]};
            cuisine2rscoreFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, score] = food2cuisineScore[food];
        food2cuisineScore[food] = {cuisine, newRating};
        cuisine2rscoreFood[cuisine].erase({-score, food});
        cuisine2rscoreFood[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*cuisine2rscoreFood[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */